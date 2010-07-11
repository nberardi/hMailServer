// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;
using UnitTest.Protocols.SMTP;
using System.IO;

namespace UnitTest.Protocols.POP3
{
   [TestFixture]
   public class ExternalAccounts : TestFixtureBase
   {
      [Test]
      public void TestBasicExternalAccount()
      {
          List<string> messages = new List<string>();

          string message = "Received: from example.com (example.com [1.2.3.4]) by mail.host.edu\r\n"+
                           "From: Martin@example.com\r\n" +
                           "To: Martin@example.com\r\n"+
                           "Subject: Test\r\n"+
                           "\r\n"+
                           "Hello!";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          string downloadedMessage = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsTrue(downloadedMessage.Contains(message));
      }

	  [Test]
      [Description("Issue 313, External fetch thread hangs on -ERR response")]
      public void TestServerNotSupportingUIDL()
      {
         List<string> messages = new List<string>();

         string message = "Received: from example.com (example.com [1.2.3.4]) by mail.host.edu\r\n" +
                          "From: Martin@example.com\r\n" +
                          "To: Martin@example.com\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.SupportsUIDL = false;
         pop3Server.StartListen();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.FetchAccount fa = account.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = false;
         fa.Save();
         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         string error = Utilities.ReadAndDeleteErrorLog();

         Assert.IsTrue(error.Contains("-ERR unhandled command"));
      }
	  
      [Test]
      public void TestDelete()
      {
          List<string> messages = new List<string>();

          string message = "From: Martin@example.com\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Hello!";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = -1;
          fa.Save();
          

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          string downloadedMessage = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsTrue(downloadedMessage.Contains(message));
          Assert.AreEqual(1, pop3Server.DeletedMessages.Count);
      }


      [Test]
      public void TestDeleteMutliple()
      {
          List<string> messages = new List<string>();

          string message = "From: Martin@example.com\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Hello!";

          messages.Add(message);
          messages.Add(message);
          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = -1;
          fa.Save();


          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 3);

          Assert.AreEqual(3, pop3Server.DeletedMessages.Count);
      }

      [Test]
      public void TestSpamProtectionPostTransmission()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";


          hMailServer.SURBLServer oSURBLServer = _application.Settings.AntiSpam.SURBLServers[0];
          oSURBLServer.Active = true;
          oSURBLServer.Score = 5;
          oSURBLServer.Save();

          List<string> messages = new List<string>();

          string message = "Received: from example.com (example.com [1.2.3.4]) by mail.host.edu\r\n"+ 
                           "From: Martin@example.com\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "http://surbl-org-permanent-test-point.com/";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = -1;
          fa.UseAntiSpam = true;

          fa.Save();
          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          string downloadedMessage = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsTrue(downloadedMessage.Contains("X-hMailServer-Spam: YES"));
          
      }

      [Test]
      [Description("Issue 249: POP3 download may fail on spam message")]
      public void TestSpamProtectionNoTagging()
      {
         Utilities.AssertSpamAssassinIsRunning();

         _application.Settings.AntiSpam.SpamMarkThreshold = 5;
         _application.Settings.AntiSpam.SpamDeleteThreshold = 9999;
         _application.Settings.AntiSpam.MaximumMessageSize = 1024 * 1024;
         _application.Settings.AntiSpam.AddHeaderReason = false;
         _application.Settings.AntiSpam.AddHeaderSpam = false;
         _application.Settings.AntiSpam.PrependSubject = false;
         _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

         // Enable SpamAssassin
         _application.Settings.AntiSpam.SpamAssassinEnabled = true;
         _application.Settings.AntiSpam.SpamAssassinHost = "localhost";
         _application.Settings.AntiSpam.SpamAssassinPort = 783;
         _application.Settings.AntiSpam.SpamAssassinMergeScore = true;
         _application.Settings.AntiSpam.SpamAssassinScore = 5;

         List<string> messages = new List<string>();

         string  message = "From: Martin@example.com\r\n" +
                      "To: Martin@example.com\r\n" +
                      "Subject: Test\r\n" +
                      "\r\n" +
                      "XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.FetchAccount fa = account.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = false;
         fa.DaysToKeepMessages = -1;
         fa.UseAntiSpam = true;

         fa.Save();
         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

      }

      
      [Test]
      public void TestSpamProtectionPreTransmissionSPFDelete()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          _application.Settings.AntiSpam.UseSPF = true;
          _application.Settings.AntiSpam.UseSPFScore = 105;

          List<string> messages = new List<string>();

          string message = "Received: from openspf.org (openspf.org [1.2.3.4]) by mail.host.edu\r\n" +
                           "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should be blocked by SPF.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = 0;
          fa.UseAntiSpam = true;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 0);
      }

      [Test]
      public void TestSpamProtectionPreTransmissionSPFPass()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          _application.Settings.AntiSpam.UseSPF = true;
          _application.Settings.AntiSpam.UseSPFScore = 105;

          List<string> messages = new List<string>();

          string message = "Received: from openspf.org (openspf.org [72.81.252.18]) by mail.host.edu\r\n" +
                           "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should be blocked by SPF.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = 0;
          fa.UseAntiSpam = true;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestSpamProtectionPreTransmissionHELODelete()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          _application.Settings.AntiSpam.CheckHostInHelo = true;
          _application.Settings.AntiSpam.CheckHostInHeloScore = 105;

          List<string> messages = new List<string>();

          string message = "Received: from openspf.org (openspf.org [1.2.1.1]) by mail.host.edu\r\n" +
                           "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should be blocked by SPF.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = 0;
          fa.UseAntiSpam = true;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 0);
      }

      [Test]
      public void TestSpamProtectionPreTransmissionHELOPass()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          _application.Settings.AntiSpam.CheckHostInHelo = true;
          _application.Settings.AntiSpam.CheckHostInHeloScore = 105;

          List<string> messages = new List<string>();
          
          string message = "Received: from mail.hmailserver.com (mail.hmailserver.com [" + Utilities.GethMailServerCOMIPaddress() + "]) by mail.host.edu\r\n" +
                           "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should not be blocked.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = 0;
          fa.UseAntiSpam = true;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      [Description("Test that the spam test skips hosts which are listed as incoming relays.")]
      public void TestSpamProtectionPreTransmissionHELOPassFirst()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          _application.Settings.AntiSpam.CheckHostInHelo = true;
          _application.Settings.AntiSpam.CheckHostInHeloScore = 105;

          hMailServer.IncomingRelay incomingRelay = _application.Settings.IncomingRelays.Add();
          incomingRelay.LowerIP = "1.2.1.2";
          incomingRelay.UpperIP = "1.2.1.3";
          incomingRelay.Name = "Test";
          incomingRelay.Save();

          List<string> messages = new List<string>();

          string message = "Received: from example.com (example.com [1.2.1.2]) by mail.host.edu\r\n" +
                           "Received: from mail.hmailserver.com (mail.hmailserver.com [" + Utilities.GethMailServerCOMIPaddress() + "]) by mail.host.edu\r\n" +
                           "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should be blocked by SPF.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = 0;
          fa.UseAntiSpam = true;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          POP3Simulator.AssertMessageCount(account.Address, "test", 1);
      }

      [Test]
      public void TestSpamProtectionDisabled()
      {
          _application.Settings.AntiSpam.SpamMarkThreshold = 1;
          _application.Settings.AntiSpam.SpamDeleteThreshold = 100;
          _application.Settings.AntiSpam.AddHeaderReason = true;
          _application.Settings.AntiSpam.AddHeaderSpam = true;
          _application.Settings.AntiSpam.PrependSubject = true;
          _application.Settings.AntiSpam.PrependSubjectText = "ThisIsSpam";

          
          _application.Settings.AntiSpam.UseSPF = true;
          _application.Settings.AntiSpam.UseSPFScore = 5;

          List<string> messages = new List<string>();

          string message = "From: spftest@openspf.org\r\n" +
                           "To: Martin@example.com\r\n" +
                           "Subject: Test\r\n" +
                           "\r\n" +
                           "Should be blocked by SPF.";

          messages.Add(message);

          int port = 1110;
          POP3Server pop3Server = new POP3Server(1, port, messages);
          pop3Server.StartListen();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
          hMailServer.FetchAccount fa = account.FetchAccounts.Add();

          fa.Enabled = true;
          fa.MinutesBetweenFetch = 10;
          fa.Name = "Test";
          fa.Username = "test@example.com";
          fa.Password = "test";
          fa.UseSSL = false;
          fa.ServerAddress = "localhost";
          fa.Port = port;
          fa.ProcessMIMERecipients = false;
          fa.DaysToKeepMessages = -1;
          fa.UseAntiSpam = false;
          fa.Save();

          fa.DownloadNow();

          pop3Server.WaitForCompletion();

          fa.Delete();

          string downloadedMessage = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsFalse(downloadedMessage.Contains("X-hMailServer-Spam: YES"));
      }

      [Test]
      [Description("Tests to connect to a normal non-SSL POP3 server using SSL. An error should be reported and hMailServer should disconnect correctly.")]
      public void TestBasicExternalAccountSSLEvenThoughNotSupported()
      {
         List<string> messages = new List<string>();

         string message = "From: Martin@example.com\r\n" +
                          "To: Martin@example.com\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1111;
         POP3Server pop3Server = new POP3Server(2, port, messages);
         pop3Server.DisconnectImmediate = true;
         pop3Server.StartListen();

         Utilities.DeleteCurrentDefaultLog();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.FetchAccount fa = account.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = true;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = false;
         fa.Save();

         fa.DownloadNow();
         string contentSoFar = "";
         for (int i = 0; i <= 10; i++)
         {
            if (i == 5)
               Assert.Fail("No connection: " + contentSoFar);

            contentSoFar = Utilities.ReadCurrentDefaultLog();
            if (contentSoFar.Contains("SSL handshake with client failed."))
               break;

            Thread.Sleep(1000);
         }

         Utilities.DeleteCurrentDefaultLog();

         // try again.
         fa.DownloadNow();

         contentSoFar = "";

         for (int i = 0; i <= 10; i++)
         {
            if (i == 5)
               Assert.Fail("No connection: " +contentSoFar);

            contentSoFar = Utilities.ReadCurrentDefaultLog();
            if (contentSoFar.Contains("SSL handshake with client failed."))
               break;

            Thread.Sleep(1000);
         }

         pop3Server.WaitForCompletion();

         fa.Delete();
      }

      [Test]
      public void TestDeliverToMIMERecipients()
      {
         List<string> messages = new List<string>();

         string message = "From: Martin@example.com\r\n" +
                          "To: \"Test\" <test1@test.com>, \"Test 2\" <test2@test.com>\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "test");
         hMailServer.Account account3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test.com", "test");
         hMailServer.Account catchallAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "catchall@test.com", "test");

         _domain.Postmaster = catchallAccount.Address;
         _domain.Save();
         
         
         hMailServer.FetchAccount fa = account1.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = true;
         fa.Save();

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         string downloadedMessage1 = POP3Simulator.AssertGetFirstMessageText(account2.Address, "test");
         string downloadedMessage2 = POP3Simulator.AssertGetFirstMessageText(account3.Address, "test");
         POP3Simulator.AssertMessageCount(account1.Address, "test", 0);
         POP3Simulator.AssertMessageCount(catchallAccount.Address, "test", 0);

         Assert.IsTrue(downloadedMessage1.Contains(message), downloadedMessage1);
         Assert.IsTrue(downloadedMessage2.Contains(message), downloadedMessage2);
      }

      [Test]
      [Description("Issue 215, Mail not delivered to MIME recipients (if external). Test option disabled.")]
      public void TestDeliverToExternalMimeRecipientsDisabled()
      {
         List<string> messages = new List<string>();

         string message = "From: Martin@example.com\r\n" +
                          "To: \"Test\" <test1@test.com>, \"ExternalGuy\" <external@dummy-example.com>\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
         deliveryResults["external@dummy-example.com"] = 250;

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "test");
         hMailServer.Account catchallAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "catchall@test.com", "test");

         _domain.Postmaster = catchallAccount.Address;
         _domain.Save();

         hMailServer.FetchAccount fa = account1.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = true;
         fa.Save();

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         string downloadedMessage1 = POP3Simulator.AssertGetFirstMessageText(account2.Address, "test");
         POP3Simulator.AssertMessageCount(account1.Address, "test", 0);
         Assert.IsTrue(downloadedMessage1.Contains(message), downloadedMessage1);

         POP3Simulator.AssertMessageCount(account2.Address, "test", 0);
         POP3Simulator.AssertMessageCount(catchallAccount.Address, "test", 0);
      }

      [Test]
      [Description("Issue 215, Mail not delivered to MIME recipients (if external)")]
      public void TestDeliverToExternalMimeRecipientsEnabled()
      {
         List<string> messages = new List<string>();

         string message = "From: Martin@example.com\r\n" +
                          "To: \"Test\" <test1@test.com>, \"ExternalGuy\" <external@dummy-example.com>\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
         deliveryResults["external@dummy-example.com"] = 250;

         SMTPServer smtpServer = new SMTPServer(1, 250);
         smtpServer.AddRecipientResult(deliveryResults);
         smtpServer.StartListen();

         // Add a route so we can connect to localhost.
         hMailServer.Route route = SMTPClient.AddRoutePointingAtLocalhost(1, 250, false);
         route.TreatSecurityAsLocalDomain = true;
         route.Save();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "test");
         hMailServer.Account catchallAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "catchall@test.com", "test");

         _domain.Postmaster = catchallAccount.Address;
         _domain.Save();

         hMailServer.FetchAccount fa = account1.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = true;
         fa.EnableRouteRecipients = true;
         fa.Save();

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         string downloadedMessage1 = POP3Simulator.AssertGetFirstMessageText(account2.Address, "test");
         POP3Simulator.AssertMessageCount(account1.Address, "test", 0);
         POP3Simulator.AssertMessageCount(catchallAccount.Address, "test", 0);
         Assert.IsTrue(downloadedMessage1.Contains(message), downloadedMessage1);

         // Make sure the exernal recipient has received his copy.
         smtpServer.WaitForCompletion();
         string messageData = smtpServer.MessageData;
         Assert.IsTrue(messageData.Contains(messageData), messageData);

         Utilities.AssertRecipientsInDeliveryQueue(0, false);
      }

      [Test]
      [Description("Issue 215, Mail not delivered to MIME recipients (if external). Test to deliver when the route is external.")]
      public void TestDeliverToExternalMimeRecipientsEnabledRouteAsExternal()
      {
         List<string> messages = new List<string>();

         string message = "From: Martin@example.com\r\n" +
                          "To: \"Test\" <test1@test.com>, \"ExternalGuy\" <external@dummy-example.com>\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Hello!";

         messages.Add(message);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         // Add a route so we can connect to localhost.
         hMailServer.Route route = SMTPClient.AddRoutePointingAtLocalhost(5, 250, false);
         route.TreatSecurityAsLocalDomain = false;
         route.Save();

         hMailServer.Account userAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.Account recipientAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "test");
         hMailServer.Account catchallAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "catchall@test.com", "test");

         _domain.Postmaster = catchallAccount.Address;
         _domain.Save();

         hMailServer.FetchAccount fa = userAccount.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = true;
         fa.EnableRouteRecipients = true;
         fa.Save();

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         string downloadedMessage1 = POP3Simulator.AssertGetFirstMessageText(recipientAccount1.Address, "test");
         Assert.IsTrue(downloadedMessage1.Contains(message), downloadedMessage1);

         Utilities.AssertRecipientsInDeliveryQueue(0, false);
      }


      [Test]
      public void TestAntiVirusEnabled()
      {
         List<string> messages = new List<string>();

         string messageText = "From: spftest@openspf.org\r\n" +
                          "To: Martin@example.com\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Should be blocked by SPF.";

         messages.Add(messageText);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.FetchAccount fa = CreateFetchAccount(account, port, false, true);

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         hMailServer.Message message = account.IMAPFolders.get_ItemByName("INBOX").Messages[0];
         Assert.IsTrue(message.get_Flag(hMailServer.eMessageFlag.eMFVirusScan));
      }


      [Test]
      public void TestAntiVirusDisabled()
      {
         List<string> messages = new List<string>();

         string messageText = "From: spftest@openspf.org\r\n" +
                          "To: Martin@example.com\r\n" +
                          "Subject: Test\r\n" +
                          "\r\n" +
                          "Should be blocked by SPF.";

         messages.Add(messageText);

         int port = 1110;
         POP3Server pop3Server = new POP3Server(1, port, messages);
         pop3Server.StartListen();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
         hMailServer.FetchAccount fa = CreateFetchAccount(account, port, false, false);

         fa.DownloadNow();

         pop3Server.WaitForCompletion();

         fa.Delete();

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         hMailServer.Message message = account.IMAPFolders.get_ItemByName("INBOX").Messages[0];
         Assert.IsFalse(message.get_Flag(hMailServer.eMessageFlag.eMFVirusScan));
      }

      
      private static hMailServer.FetchAccount CreateFetchAccount(hMailServer.Account account, int port, bool antiSpam, bool antiVirus)
      {
         hMailServer.FetchAccount fa = account.FetchAccounts.Add();

         fa.Enabled = true;
         fa.MinutesBetweenFetch = 10;
         fa.Name = "Test";
         fa.Username = "test@example.com";
         fa.Password = "test";
         fa.UseSSL = false;
         fa.ServerAddress = "localhost";
         fa.Port = port;
         fa.ProcessMIMERecipients = false;
         fa.DaysToKeepMessages = -1;
         fa.UseAntiSpam = antiSpam;
         fa.UseAntiVirus = antiVirus;
         fa.Save();
         return fa;
      }

    }
}
