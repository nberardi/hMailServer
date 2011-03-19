// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Collections;
using System.Threading;
using System.IO;
using System.Net;
using System.Net.Mail;
using UnitTest.API;

namespace UnitTest.Protocols.SMTP
{
   [TestFixture]
   public class General : TestFixtureBase
   {
      [Test]
      public void TestDistributionLists()
      {
         // Fetch default domain



         // Add distribution list
         List<string> oRecipients = new List<string>();
         oRecipients.Add("recipient1@test.com");
         oRecipients.Add("recipient2@test.com");
         oRecipients.Add("recipient3@test.com");

         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list1@test.com", oRecipients);

         hMailServer.Account oAccount;
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient1@test.com", "test");
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient2@test.com", "test");
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient3@test.com", "test");

         // Add alias pointing at the distribution list.
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "listalias@test.com", "list1@test.com");

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();

         Assert.IsTrue(oSMTP.Send("test@test.com", "list1@test.com", "Mail 1", "Mail 1"));
         Assert.IsTrue(oSMTP.Send("test@test.com", "listalias@test.com", "Mail 2", "Mail 2"));
         Assert.IsTrue(oSMTP.Send("test@test.com", "listalias@test.com", "Mail 3", "Mail 3"));

         IMAPSimulator.AssertMessageCount("recipient1@test.com", "test", "Inbox", 3);
         IMAPSimulator.AssertMessageCount("recipient2@test.com", "test", "Inbox", 3);
         IMAPSimulator.AssertMessageCount("recipient3@test.com", "test", "Inbox", 3);

         oRecipients.Add("recipient4@test.com");
         oRecipients.Add("recipient5@test.com");
         oRecipients.Add("recipient6@test.com");
         oRecipients.Add("recipient7@test.com");
         oRecipients.Add("recipient8@test.com");

         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list2@test.com", oRecipients);
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient7@test.com", "test");
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient8@test.com", "test");
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         Assert.IsTrue(oSMTP.Send("test@test.com", "list2@test.com", "Mail 1", "Mail 1"));

         IMAPSimulator.AssertMessageCount("recipient7@test.com", "test", "Inbox", 1);

         // Wait for the message to be completely delivered. The above assertion isn't enough to confirm that.
         Thread.Sleep(1000); 

         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "announcer@test.com", "test");
         hMailServer.DistributionList oList = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list3-security@test.com", oRecipients);
         oList.Mode = hMailServer.eDistributionListMode.eLMAnnouncement;
         oList.RequireSenderAddress = oAccount.Address;
         oList.RequireSMTPAuth = false;
         oList.Save();

         Assert.IsFalse(oSMTP.Send("test@test.com", "list3-security@test.com", "Mail 1", "Mail 1"));
         Assert.IsTrue(oSMTP.Send(oAccount.Address, "list3-security@test.com", "Mail 1", "Mail 1"));
         IMAPSimulator.AssertMessageCount("recipient7@test.com", "test", "Inbox", 2);

         oList.Mode = hMailServer.eDistributionListMode.eLMMembership;
         oList.Save();

         Assert.IsFalse(oSMTP.Send(oAccount.Address, "list3-security@test.com", "Mail 1", "Mail 1"));

         // THIS MESSAGE SHOULD SUCCED 
         Assert.IsTrue(oSMTP.Send("recipient5@test.com", "list3-security@test.com", "Mail 1", "Mail 1"));
         IMAPSimulator.AssertMessageCount("recipient7@test.com", "test", "Inbox", 3);
      }

      [Test]
      public void TestDistributionListWithEmptyAddress()
      {

          // Add distribution list
          List<string> oRecipients = new List<string>();
          oRecipients.Add("recipient1@test.com");
          oRecipients.Add("recipient2@test.com");
          oRecipients.Add("");
          oRecipients.Add("recipient4@test.com");

          try
          {
              SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list1@test.com", oRecipients);
          }
          catch (Exception ex)
          {
              Assert.IsTrue(ex.Message.Contains("The recipient address is empty"));
              return;
          }

          Assert.Fail("No error reported when creating distribution list recipient with empty address");
      }

      [Test]
      public void TestDistributionListPointingAtItself()
      {

          // Add distribution list
          List<string> oRecipients = new List<string>();
          oRecipients.Add("recipient1@test.com");
          oRecipients.Add("recipient2@test.com");
          oRecipients.Add("recipient4@test.com");
          oRecipients.Add("list1@test.com");

          SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list1@test.com", oRecipients);
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
          SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient1@test.com", "test");
          SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient2@test.com", "test");
          SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient3@test.com", "test");
          SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient4@test.com", "test");

          Assert.IsTrue(SMTPClientSimulator.StaticSend("test@test.com", "list1@test.com", "Mail 1", "Mail 1"));

          IMAPSimulator.AssertMessageCount("recipient1@test.com", "test", "Inbox", 1);
          IMAPSimulator.AssertMessageCount("recipient2@test.com", "test", "Inbox", 1);
          IMAPSimulator.AssertMessageCount("recipient4@test.com", "test", "Inbox", 1);
      }


      [Test]
      public void TestDistributionListsMembershipDomainAliases()
      {
         IMAPSimulator oIMAP = new IMAPSimulator();
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         ;

         hMailServer.DomainAlias oDA = _domain.DomainAliases.Add();
         oDA.AliasName = "dummy-example.com";
         oDA.Save();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");
         oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2@test.com", "test");


         // 
         // TEST LIST SECURITY IN COMBINATION WITH DOMAIN NAME ALIASES
         // 



         List<string> oRecipients = new List<string>();
         oRecipients.Clear();
         oRecipients.Add("vaffe@dummy-example.com");

         hMailServer.DistributionList oList3 = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list@test.com", oRecipients);
         oList3.Mode = hMailServer.eDistributionListMode.eLMMembership;
         oList3.Save();

         // THIS MESSAGE SHOULD FAIL - Membership required, unknown sender domain
         Assert.IsFalse(oSMTP.Send("account1@dummy-example.com", "list@test.com", "Mail 1", "Mail 1"));

         oList3.Delete();

         // THIS MESSAGE SHOULD SUCCED - Membership required, sender domain is now an alias for test.com.

         oRecipients = new List<string>();
         oRecipients.Clear();
         oRecipients.Add("account1@dummy-example.com");
         oRecipients.Add("account2@test.com");

         oList3 = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list@test.com", oRecipients);
         oList3.Mode = hMailServer.eDistributionListMode.eLMMembership;
         oList3.Save();

         Assert.IsTrue(oSMTP.Send("account1@dummy-example.com", "list@test.com", "Mail 1", "Mail 1"));

         IMAPSimulator.AssertMessageCount("account1@test.com", "test", "Inbox", 1);
         IMAPSimulator.AssertMessageCount("account2@test.com", "test", "Inbox", 1);
      }

      [Test]
      [Description("Test send email from internal address to external, using no authentication on an IP range with does not require authentication")]
      public void TestSendExternalToExternalPermitted()
      {
         hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
         range.RequireSMTPAuthExternalToExternal = false;
         
         range.Save();

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         Assert.IsTrue(oSMTP.Send("test@sdag532sdfagdsa12fsdafdsa1.com", "test2@dsatwvbsdagdasfds423sdavsagasddas.com", "Mail 1", "Mail 1"));
      }

      [Test]
      public void TestDistributionListAnnouncementFromDomainAlias()
      {
         IMAPSimulator oIMAP = new IMAPSimulator();
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         ;

         // 
         // TEST LIST SECURITY IN COMBINATION WITH DOMAIN NAME ALIASES
         // 



         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         List<string> oRecipients = new List<string>();
         oRecipients.Add("test@dummy-example.com");

         hMailServer.DistributionList oList3 = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list@test.com", oRecipients);
         oList3.Mode = hMailServer.eDistributionListMode.eLMAnnouncement;
         oList3.RequireSenderAddress = "test@dummy-example.com";
         oList3.Save();

         // THIS MESSAGE SHOULD FAIL
         Assert.IsFalse(oSMTP.Send("test@test.com", "list@test.com", "Mail 1", "Mail 1"));

         hMailServer.DomainAlias oDA = _domain.DomainAliases.Add();
         oDA.AliasName = "dummy-example.com";
         oDA.Save();

         // THIS MESSAGE SHOULD SUCCEED
         Assert.IsTrue(oSMTP.Send("test@dummy-example.com", "list@dummy-example.com", "Mail 1", "Mail 1"));
         IMAPSimulator.AssertMessageCount("test@dummy-example.com", "test", "Inbox", 1);
      }

      [Test]
      public void TestHelo()
      {


         SMTPClientSimulator oSimulator = new SMTPClientSimulator();

         oSimulator.Connect(25);

         string sWelcome = oSimulator.Receive();

         oSimulator.Send("HELO\r\n");
         string sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("501"))
            throw new Exception("Invalid response to HELO");

         oSimulator.Send("HELO   \r\n");
         sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("501"))
            throw new Exception("Invalid response to HELO");

         oSimulator.Send("HELO TEST.COM\r\n");
         sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("250"))
            throw new Exception("Invalid response to HELO");


         oSimulator.Send("HELO   TEST.COM\r\n");
         sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("250"))
            throw new Exception("Invalid response to HELO");

         oSimulator.Send("EHLO TEST.COM\r\n");
         sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("250"))
            throw new Exception("Invalid response to HELO");

         oSimulator.Send("EHLO    TEST.COM\r\n");
         sResponse = oSimulator.Receive();

         if (!sResponse.StartsWith("250"))
            throw new Exception("Invalid response to HELO");

         oSimulator.Disconnect();


      }

      [Test]
      public void TestWelcomeMessage()
      {


         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         _settings.WelcomeSMTP = "HOWDYHO";

         SMTPClientSimulator oSimulator = new SMTPClientSimulator();

         string sWelcomeMessage = oSimulator.GetWelcomeMessage();

         if (sWelcomeMessage != "220 HOWDYHO\r\n")
            throw new Exception("ERROR - Wrong welcome message.");


      }

      [Test]
      public void TestSendToMultipleAccounts()
      {


         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "multi1@test.com", "test");
         hMailServer.Account oAccount2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "multi2@test.com", "test");
         hMailServer.Account oAccount3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "multi3@test.com", "test");

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();

         List<string> lstRecipients = new List<string>();
         lstRecipients.Add("multi1@test.com");
         lstRecipients.Add("multi2@test.com");
         lstRecipients.Add("multi3@test.com");

         string sBody = "Test of sending same email to multiple accounts.";

         oSMTP.Send(oAccount1.Address, lstRecipients, "Multi test", sBody);

         POP3Simulator oPOP3 = new POP3Simulator();

         string sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageData.IndexOf(sBody) < 0)
            throw new Exception("E-mail not found");

         sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount2.Address, "test");
         if (sMessageData.IndexOf(sBody) < 0)
            throw new Exception("E-mail not found");

         sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount3.Address, "test");
         if (sMessageData.IndexOf(sBody) < 0)
            throw new Exception("E-mail not found");
      }

      [Test]
      [Category("SMTP")]
      [Description("Confirm that deliveries are logged in the awstats log.")]
      public void TestAwstatsLog()
      {
         hMailServer.Settings settings = SingletonProvider<Utilities>.Instance.GetApp().Settings;

         hMailServer.Logging logging = settings.Logging;
         logging.AWStatsEnabled = true;
         logging.Enabled = true;

         if (File.Exists(logging.CurrentAwstatsLog))
            File.Delete(logging.CurrentAwstatsLog);

         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         IPAddress localAddress = Utilities.GetLocalIPAddress();
         SMTPClientSimulator oSMTP = new SMTPClientSimulator(false, 25, localAddress);

         // Delivery from external to local.
         Assert.IsTrue(oSMTP.Send("test@external.com", "test@test.com", "Mail 1", "Mail 1"));
         POP3Simulator.AssertMessageCount("test@test.com", "test", 1);
         string contents = Utilities.ReadExistingTextFile(logging.CurrentAwstatsLog);
         Utilities.AssertDeleteFile(logging.CurrentAwstatsLog);
         string expectedString = string.Format("\ttest@external.com\ttest@test.com\t{0}\t127.0.0.1\tSMTP\t?\t250\t", localAddress.ToString());
         Assert.IsTrue(contents.Contains(expectedString), contents);

         // Failed delivery from local to local.
         Assert.IsFalse(oSMTP.Send("test@test.com", "test@test.com", "Mail 1", "Mail 1"));
         contents = Utilities.ReadExistingTextFile(logging.CurrentAwstatsLog);
         Utilities.AssertDeleteFile(logging.CurrentAwstatsLog);
         expectedString = string.Format("\ttest@test.com\ttest@test.com\t{0}\t127.0.0.1\tSMTP\t?\t530\t", localAddress.ToString());
         Assert.IsTrue(contents.Contains(expectedString), contents);
      }

      [Test]
      public void TestMediumVolume()
      {

         // Fetch default domain
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "bigaccount@test.com", "test");

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();


         ArrayList oThreads = new ArrayList();
         for (int i = 0; i < 5; i++)
         {
            Thread oThread = new System.Threading.Thread(new ThreadStart(Send50Messages));
            oThreads.Add(oThread);
            oThread.Start();
         }

         // Join the threads
         for (int i = 0; i < 5; i++)
         {
            Thread oThread = (Thread)oThreads[i];
            oThread.Join();
         }

         IMAPSimulator.AssertMessageCount("bigaccount@test.com", "test", "Inbox", 250);

      }

      // helper
      private static void Send50Messages()
      {
         for (int i = 0; i < 50; i++)
         {
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            oSMTP.Send("test@test.com", "bigaccount@test.com", "Big account email", "Body av email");
         }
      }


      [Test]
      [Category("SMTP")]
      [Description("Confirm that it's OK to add the same recipient multiple times.")]
      public void TestSameRecipientMultipleTimes()
      {
          hMailServer.Logging logging = SingletonProvider<Utilities>.Instance.GetApp().Settings.Logging;
          logging.AWStatsEnabled = true;
          logging.Enabled = true;

          if (File.Exists(logging.CurrentAwstatsLog))
              File.Delete(logging.CurrentAwstatsLog);

          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Connect(25);
          Assert.IsTrue(oSMTP.Receive().StartsWith("220"));
          oSMTP.Send("HELO test\r\n");
          Assert.IsTrue(oSMTP.Receive().StartsWith("250"));
          oSMTP.Send("MAIL FROM: test@test.com\r\n");
          Assert.IsTrue(oSMTP.Receive().StartsWith("250"));
          oSMTP.Send("RCPT TO: knafve@gmail.com\r\n");
          Assert.IsTrue(oSMTP.Receive().StartsWith("250"));
          oSMTP.Send("RCPT TO: knafve@gmail.com\r\n");
          Assert.IsTrue(oSMTP.Receive().StartsWith("250"));

          oSMTP.Disconnect();
      }


      [Test]
      [Category("SMTP")]
      [Description("Confirm that it's OK to send MAIL FROM without the < and >")]
      public void TestMailFromSyntaxValidation()
      {
         var account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Connect(25);
         
         Assert.IsTrue(oSMTP.Receive().StartsWith("220"));
         oSMTP.Send("HELO test\r\n");
         Assert.IsTrue(oSMTP.Receive().StartsWith("250"));

         // A few tests of invalid syntax.
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: <test@test.com\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: test@test.com>\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: <    test@test.com    \r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: <        \r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: >        \r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM: <sdsdfs@sdsdf.csd\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM <sdsdfs@sdsdf.csd>\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("MAIL FROM  sdsdfs@sdsdf.csd\r\n").StartsWith("250"));
         
         // Valid syntax, < and >
         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM: <test@test.com>\r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RSET\r\n").StartsWith("250"));

         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM: test@test.com\r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RSET\r\n").StartsWith("250"));

         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM:    test@test.com   \r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RSET\r\n").StartsWith("250"));

         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM:test@test.com\r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RSET\r\n").StartsWith("250"));

         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM:<test@test.com>\r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RSET\r\n").StartsWith("250"));

         oSMTP.Disconnect();
      }

      [Test]
      [Category("SMTP")]
      [Description("Confirm that it's OK to send MAIL FROM without the < and >")]
      public void TestRcptToSyntax()
      {
         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Connect(25);

         Assert.IsTrue(oSMTP.Receive().StartsWith("220"));
         oSMTP.Send("HELO test\r\n");
         Assert.IsTrue(oSMTP.Receive().StartsWith("250"));

         // A few tests of invalid syntax.
         Assert.IsTrue(oSMTP.SendAndReceive("MAIL FROM: <test@test.com>\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("RCPT TO: test@test.com>\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("RCPT TO: <test@test.com\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("RCPT TO <test@test.com\r\n").StartsWith("250"));
         Assert.IsFalse(oSMTP.SendAndReceive("RCPT TO<test@test.com\r\n").StartsWith("250"));
         
         Assert.IsTrue(oSMTP.SendAndReceive("RCPT TO: <test@test.com>\r\n").StartsWith("250"));
         Assert.IsTrue(oSMTP.SendAndReceive("RCPT TO: test@test.com\r\n").StartsWith("250"));

         oSMTP.Disconnect();
      }


      [Test]
      public void TestEHLOKeywords()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
          hMailServer.Settings settings = _settings;
          settings.HostName = "examplify.com";
          
          TCPSocket socket = new TCPSocket();
          Assert.IsTrue(socket.Connect(25));
          string result = socket.Receive();
          socket.Send("EHLO example.com\r\n");
          result = socket.Receive();
          socket.Disconnect();
          Assert.IsTrue(result.Contains("250-" + settings.HostName));
      }

      [Test]
      public void TestTooManyInvalidCommandsHELO()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
          hMailServer.Settings settings = _settings;
          settings.DisconnectInvalidClients = true;
          settings.MaxNumberOfInvalidCommands = 3;

          SMTPClientSimulator sim = new SMTPClientSimulator();
          sim.Connect(25);

          for (int i = 1; i <= 6; i++)
          {
              sim.Send("HELO\r\n");
              string result = sim.Receive();

              if (result.Contains("Too many invalid commands"))
                  break;

              if (i > 5)
                  Assert.Fail();
          }
      }

      [Test]
      public void TestTooManyInvalidCommandsAUTH()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
          hMailServer.Settings settings = _settings;

          settings.DisconnectInvalidClients = true;
          settings.MaxNumberOfInvalidCommands = 3;

          SMTPClientSimulator sim = new SMTPClientSimulator();
          sim.Connect(25);
          sim.Send("EHLO test.com\r\n");

          for (int i = 1; i <= 6; i++)
          {
              try
              {
                  sim.Send("AUTH LOGIN\r\n");

                  string result = sim.Receive();

                  if (result.Contains("Too many invalid commands"))
                      return;

                  if (i > 5)
                      break;

                  sim.Send("YWNhZGVtaWE=\r\n");
                  sim.Receive();
                  sim.Send("abc\r\n");
                  sim.Receive();
              }
              catch (Exception)
              {
                  if (i < 5)
                  {
                      Assert.Fail("Was disconnected prematurely.");
                  }
                  
                  return;
              }
          }

          Assert.Fail("Wasn't disconnected");

 
      }

      /// <summary>
      /// If an error is rejected with a temp-error (4xx), that should not be counted
      /// as an error which makes the client get disconnected.
      /// </summary>
      [Test]
      [Description("Issue 189, Greylisting rejections (try again) are treated as errors ")]
      public void TestTooManyInvalidCommandsTempError()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         for (int i = 0; i < 10; i++)
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, string.Format("test{0}@test.com", i), "test");

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Settings settings = _settings;

         settings.DisconnectInvalidClients = true;
         settings.MaxNumberOfInvalidCommands = 5;

         settings.AntiSpam.GreyListingEnabled = true;

         SMTPClientSimulator sim = new SMTPClientSimulator();
         sim.Connect(25);
         string res = sim.Receive();
         sim.Send("EHLO test.com\r\n");
         res = sim.Receive();
         sim.Send("MAIL FROM: <test@test.com>\r\n");
         res = sim.Receive();
         for (int i = 1; i < 10; i++)
         {
            string address = string.Format("test{0}@test.com", i);

            sim.Send("RCPT TO: " + address + "\r\n");

            res = sim.Receive();

            Assert.AreEqual("451 Please try again later.\r\n", res);
         }

         sim.Disconnect();
      }

      [Test]
      [Category("SMTP")]
      [Description("Issue 181: Make sure that duplicate Message-ID's aren't added.")]
      public void TestDuplicateMessageIDs()
      {
         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string content = "SomeHeader: Text" +Environment.NewLine+
                          "Message-Id: <200903121212246.SM01264@server03>" + Environment.NewLine+
                          "" + Environment.NewLine +
                          "Test";

         SMTPClientSimulator.StaticSendRaw("test@test.com", "test@test.com", content);

         string test = POP3Simulator.AssertGetFirstMessageText("test@test.com", "test");

         Assert.IsTrue(test.Contains("Message-Id"));
         Assert.IsFalse(test.Contains("Message-ID"));
      }

      [Test]
      [Category("SMTP")]
      [Description("Test account max size limitation.")]
      public void TestMaxSizeLimitationMultipleSmallMessages()
      {
          hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
          hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

          recipientAccount.MaxSize = 1;
          recipientAccount.Save();

          // Make sure we can send several messages.
          Assert.IsTrue(SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "Test", "Test"));
          Assert.IsTrue(SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "Test", "Test"));
          
          POP3Simulator.AssertMessageCount(recipientAccount.Address, "test", 2);
      }

      [Test]
      [Category("SMTP")]
      [Description("Test account max size limitation.")]
      public void TestMaxSizeLimitation()
      {
         hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
         hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

         recipientAccount.MaxSize = 1;
         recipientAccount.Save();

         // Make sure that no bounce is sent.
         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "MySubject", "Test");
         POP3Simulator.AssertGetFirstMessageText(recipientAccount.Address, "test");
         
         // Build a 2MB string.
         StringBuilder builder = new StringBuilder();
         for (int i = 0; i < 11000; i++)
         {
            builder.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");
         }
         string text = builder.ToString();

         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "MySubject", text);

         // Make sure the recipient did not receive it.
         Utilities.AssertRecipientsInDeliveryQueue(0);
         POP3Simulator.AssertMessageCount(recipientAccount.Address, "test", 0);
         SingletonProvider<Utilities>.Instance.AssertFilesInUserDirectory(recipientAccount, 0);

         // Make sure it bounced.
         string content = POP3Simulator.AssertGetFirstMessageText(senderAccount.Address, "test");
         Assert.IsTrue(content.Contains("Inbox is full"));
      }

      [Test]
      [Category("SMTP")]
      [Description("Issue 228. Bounce messages does not contain Subject or Date.")]
      public void BounceMessageShouldContainSubjectAndDate()
      {
         hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
         hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

         recipientAccount.MaxSize = 1;
         recipientAccount.Save();

         // Make sure that no bounce is sent.
         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "MySubject", "Test");
         POP3Simulator.AssertGetFirstMessageText(recipientAccount.Address, "test");

         // Build a 2MB string.
         StringBuilder builder = new StringBuilder();
         for (int i = 0; i < 11000; i++)
         {
            builder.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");
         }
         string text = builder.ToString();

         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "Test subject", text);

         // Make sure the recipient did not receive it.
         Utilities.AssertRecipientsInDeliveryQueue(0);
         POP3Simulator.AssertMessageCount(recipientAccount.Address, "test", 0);
         SingletonProvider<Utilities>.Instance.AssertFilesInUserDirectory(recipientAccount, 0);

         // Make sure it bounced.
         string content = POP3Simulator.AssertGetFirstMessageText(senderAccount.Address, "test");
         Assert.IsTrue(content.Contains("Inbox is full"));
         Assert.IsTrue(content.Contains("Subject: Test subject"));

         // Make sure body contains year.
         int bodyStartPos = content.IndexOf("\r\n\r\n");
         int yearPos = content.IndexOf(DateTime.Now.Year.ToString(), bodyStartPos);
         Assert.IsTrue(yearPos >= 0);
      }

      [Test]
      [Category("SMTP")]
      [Description("Issue 188, SMTP: Permanent error response if disk full ")]
      public void TestTempErrorIfDiskFull()
      {
         hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
         hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

         hMailServer.Directories directories = SingletonProvider<Utilities>.Instance.GetApp().Settings.Directories;

         string origDataDir = directories.DataDirectory;

         try
         {
            directories.DataDirectory = "C:\\FolderWhichDoesNotExist";

            string result = "";

            SMTPClientSimulator sim = new SMTPClientSimulator();
            sim.Send(senderAccount.Address, recipientAccount.Address, "MySubject", "Test", out result);

            Assert.IsTrue(result.StartsWith("4"), "Expected temporary error, but was: " + result);

            Utilities.AssertReportedError();
         }
         finally
         {
            directories.DataDirectory = origDataDir;
         }
         
      }

      [Test]
      [Description("Issue 226. Domain alias rewrites sender address.")]
      public void DomainAliasesShouldNotRewriteRecipientList()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         ;

         hMailServer.DomainAlias oDA = _domain.DomainAliases.Add();
         oDA.AliasName = "dummy-example.com";
         oDA.Save();
        
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "otherguy@test.com", "test");

         // Set up a server listening on port 250 which accepts email for test@otherdomain.com
         Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
         deliveryResults["test@dummy-example.com"] = 250;
         SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
         server.AddRecipientResult(deliveryResults);
         server.StartListen();


         hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, true);

         // Now send a message from test@test.com to test@otherdomain.com.
         // Error scenario:
         // In the recipientlist, otherdomain.com gets rewritten to test.com 
         // since there's a domain alias named otherdomain.co on the domain 
         // test.com.
         //
         // This should not happen. Otherdomain.com is an alias for test.com,
         // but we shouldn't actually modify the recipient address just because
         // of this?
         SMTPClientSimulator smtpClient = new SMTPClientSimulator();
         Assert.IsTrue(smtpClient.Send(account.Address, "test@dummy-example.com", "Test", "Test message"));

         Utilities.AssertRecipientsInDeliveryQueue(0);

         POP3Simulator.AssertMessageCount(account.Address, "test", 0);

         // This should now be processed via the rule -> route -> external server we've set up.
         server.WaitForCompletion();

         Assert.IsTrue(server.MessageData.Contains("Test message"));

      }

      [Test]
      [Description("Issue 284. Sender to Alias to Route not working.")]
      public void SendMessageToAliasForwardToRoute()
      {
          // Set up a server listening on port 250 which accepts email for test@otherdomain.com
          Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
          deliveryResults["user@test.com"] = 250;
          SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
          server.AddRecipientResult(deliveryResults);
          server.StartListen();

          // Add a route pointing at localhost
          hMailServer.Route route = _settings.Routes.Add();
          route.DomainName = "test.com";
          route.TargetSMTPHost = "localhost";
          route.TargetSMTPPort = 250;
          route.NumberOfTries = 1;
          route.MinutesBetweenTry = 5;
          route.TreatRecipientAsLocalDomain = true;
          route.TreatSenderAsLocalDomain = true;
          route.AllAddresses = false;
          route.Save();

          // Make sure only the specific user is valid.
          hMailServer.RouteAddress routeAddress = route.Addresses.Add();
          routeAddress.Address = "user@" + _domain.Name;
          routeAddress.Save();

          SingletonProvider<Utilities>.Instance.AddAlias(_domain, "users@test.com", "user@test.com");

          SMTPClientSimulator smtpClient = new SMTPClientSimulator();
          Assert.IsTrue(smtpClient.Send("example@example.com", "users@test.com", "Test", "Test message"));
          Utilities.AssertRecipientsInDeliveryQueue(0);

          server.WaitForCompletion();

          Assert.IsTrue(server.MessageData.Contains("Test message"));

      }

      [Test]
      public void TestAntiVirusEnabled()
      {
         hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
         range.EnableAntiVirus = true;
         range.Save();
         
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          
         SMTPClientSimulator.StaticSend("user@test.com", "user@test.com", "Test", "Test");
         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         hMailServer.Message message = account.IMAPFolders.get_ItemByName("INBOX").Messages[0];
         Assert.IsTrue(message.get_Flag(hMailServer.eMessageFlag.eMFVirusScan));
      }

      [Test]
      public void TestSendToAddressWithQuote()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "us'er@test.com", "test");
          SMTPClientSimulator.StaticSend("someone@test.com", "us'er@test.com", "Test", "Test");
          POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      [Description("Issue 291, Sloppy non-delivery report generated")]
      public void TestBounceMessageSyntax()
      {
         hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
         hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

         recipientAccount.MaxSize = 1;
         recipientAccount.Save();

         // Build a 2MB string.
         StringBuilder builder = new StringBuilder();
         for (int i = 0; i < 11000; i++)
            builder.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");

         string text = builder.ToString();

         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "", text);

         // Make sure the recipient did not receive it.
         Utilities.AssertRecipientsInDeliveryQueue(0);

         // Check the syntax in the bounce message.
         string content = POP3Simulator.AssertGetFirstMessageText(senderAccount.Address, "test");

         // The bounce message should contain the MIME-version.
         Assert.IsTrue(content.Contains("MIME-Version: 1.0"));
         
         // Lines may not end with space if they are QP-encoded.
         Assert.IsTrue(content.Contains("  Subject:=20"));
         
      }

      [Test]
      [Description("Issue 291, Sloppy non-delivery report generated")]
      public void TestValidEmailAddress()
      {
         hMailServer.Account senderAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");
         hMailServer.Account recipientAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "recipient@test.com", "test");

         recipientAccount.MaxSize = 1;
         recipientAccount.Save();

         // Build a 2MB string.
         StringBuilder builder = new StringBuilder();
         for (int i = 0; i < 11000; i++)
            builder.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");

         string text = builder.ToString();

         SMTPClientSimulator.StaticSend(senderAccount.Address, recipientAccount.Address, "", text);

         // Make sure the recipient did not receive it.
         Utilities.AssertRecipientsInDeliveryQueue(0);

         // Check the syntax in the bounce message.
         string content = POP3Simulator.AssertGetFirstMessageText(senderAccount.Address, "test");

         // The bounce message should contain the MIME-version.
         Assert.IsTrue(content.Contains("MIME-Version: 1.0"));

         // Lines may not end with space if they are QP-encoded.
         Assert.IsTrue(content.Contains("  Subject:=20"));

      }

      [Test]
      public void TestSendToPostmasterAddress()
      {
         _domain.Postmaster = "test@test.com";
         _domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("someone@example.com", "someone@test.com", "Test", "Test"));
         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }


      [Test]
      public void TestSendToPostmasterAddressDomainAlias()
      {
         hMailServer.DomainAlias alias = _domain.DomainAliases.Add();
         alias.AliasName = "alias.com";
         alias.Save();

         _domain.Postmaster = "test@alias.com";
         _domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("someone@example.com", "someone@test.com", "Test", "Test"));

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestPostmasterAddressIsAliasButAliasMissing()
      {
         _domain.Postmaster = "alias@test.com";
         _domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsFalse(SMTPClientSimulator.StaticSend("someone@example.com", "someone@test.com", "Test", "Test"));
      }

      [Test]
      public void TestPostmasterAddressIsAlias()
      {
         _domain.Postmaster = "alias@test.com";
         _domain.Save();

         hMailServer.Alias alias = SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias@test.com", "test@test.com");

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("someone@example.com", "someone@test.com", "Test", "Test"));
         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestPostmasterInternalSender()
      {
         _domain.Postmaster = "test@test.com";
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("sender@test.com", "someone@test.com", "Test", "Test"));

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      [Description("Test that we don't mess up external deliveries with the postmaster address.")]
      public void TestPostmasterRecipientExternal()
      {
         _domain.Postmaster = "test@test.com";
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sender@test.com", "test");

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         Assert.IsFalse(SMTPClientSimulator.StaticSend("sender@example.com", "someone@example.com", "Test", "Test"));
      }

      [Test]
      public void TestPostmasterOnSecondDomain()
      {
         _domain.Postmaster = "test@otherDomain.com";
         _domain.Save();

         hMailServer.Domain otherDomain = SingletonProvider<Utilities>.Instance.AddDomain(SingletonProvider<Utilities>.Instance.GetApp().Domains, "otherDomain.com");

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(otherDomain, "test@otherDomain.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("sender@test.com", "someone@test.com", "Test", "Test"));

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestPostmasterOnSecondDomainWithDomainAlias()
      {
         hMailServer.Domain otherDomain = SingletonProvider<Utilities>.Instance.AddDomain(SingletonProvider<Utilities>.Instance.GetApp().Domains, "otherDomain.com");
         hMailServer.DomainAlias otherDomainAlias = otherDomain.DomainAliases.Add();
         otherDomainAlias.AliasName = "name2.com";
         otherDomainAlias.Save();

         _domain.Postmaster = "test@name2.com";
         _domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(otherDomain, "test@otherDomain.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("sender@test.com", "someone@test.com", "Test", "Test"));

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestPostmasterToPostmasterOnOtherDomain()
      {
         _domain.Postmaster = "nonexistant@otherDomain.com";
         _domain.Save();

         hMailServer.Domain otherDomain = SingletonProvider<Utilities>.Instance.AddDomain(SingletonProvider<Utilities>.Instance.GetApp().Domains, "otherDomain.com");
         otherDomain.Postmaster = "account@otherDomain.com";
         otherDomain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(otherDomain, "account@otherDomain.com", "test");
         Assert.IsTrue(SMTPClientSimulator.StaticSend("sender@test.com", "someone@test.com", "Test", "Test"));

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestMultipleHostsLimitMXHosts()
      {
         _settings.MaxNumberOfMXHosts = 1;

         // No valid recipients...
         Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
         deliveryResults["user1@dummy-example.com"] = 250;

         SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
         server.AddRecipientResult(deliveryResults);
         server.StartListen();

         // Add a route so we can connect to localhost.
         hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhostMultipleHosts(2);

         // Send message to this route.
         SMTPClientSimulator smtp = new SMTPClientSimulator();
         List<string> recipients = new List<string>();

         recipients.Add("user1@dummy-example.com");

         Assert.IsTrue(SMTPClientSimulator.StaticSend("test@test.com", "user1@dummy-example.com", "Test", "Test"));

         // Wait for the client to disconnect.
         server.WaitForCompletion();

         string log = Utilities.ReadCurrentDefaultLog();
         Assert.IsTrue(log.Contains("Truncating MX server list."));
      }

      [Test]
      [Description("Issue 325, Last logon time being updated at wrong point")]
      public void MailFromShouldNotUpdatedLastLogonTime()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "us'er@test.com", "test");
         DateTime lastLogonTimeBefore = Convert.ToDateTime(account.LastLogonTime);

         System.Threading.Thread.Sleep(1000);
         SMTPClientSimulator.StaticSend("someone@test.com", "us'er@test.com", "Test", "Test");

         Utilities.AssertRecipientsInDeliveryQueue(0);
         DateTime lastLogonTimeAfter = Convert.ToDateTime(SingletonProvider<Utilities>.Instance.GetApp().Domains[0].Accounts[0].LastLogonTime);
         Assert.AreEqual(lastLogonTimeBefore, lastLogonTimeAfter);
      }

      [Test]
      [Description("Issue 325, Last logon time being updated at wrong point")]
      public void AuthShouldUpdateLastLogonTime()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
         DateTime lastLogonTimeBefore = Convert.ToDateTime(account.LastLogonTime);

         System.Threading.Thread.Sleep(1000);
         TCPSocket sock = new TCPSocket();
         sock.Connect(25);
         Assert.IsTrue(sock.Receive().StartsWith("220"));
         sock.Send("EHLO test.com\r\n");
         Assert.IsTrue(sock.Receive().StartsWith("250"));

         string base64EncodedUsername = EncodeBase64("test@test.com");
         sock.Send("AUTH LOGIN " + base64EncodedUsername + "\r\n");
         Assert.IsTrue(sock.Receive().StartsWith("334"));

         sock.Send(EncodeBase64("test") + "\r\n");
         Assert.IsTrue(sock.Receive().StartsWith("235"));

         DateTime lastLogonTimeAfter = Convert.ToDateTime(SingletonProvider<Utilities>.Instance.GetApp().Domains[0].Accounts[0].LastLogonTime);
         Assert.AreNotEqual(lastLogonTimeBefore, lastLogonTimeAfter);
      }

      private string EncodeBase64(string s)
      {
         byte[] bytes = System.Text.Encoding.UTF8.GetBytes(s);
         return System.Convert.ToBase64String(bytes);
      }
   }
}
