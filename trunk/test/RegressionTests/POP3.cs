// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;
using System.Net.Mail;
using System.Reflection;
using System.IO;
using System.Net.Mime;
using System.Diagnostics;

namespace UnitTest.Protocols.POP3
{
   [TestFixture]
   public class Basics : TestFixtureBase
   {
      [Test]
      public void WelcomeMessage()
      {
         SingletonProvider<Utilities>.Instance.GetApp().Settings.WelcomePOP3 = "HOWDYHO POP3";

         POP3Simulator oSimulator = new POP3Simulator();

         string sWelcomeMessage = oSimulator.GetWelcomeMessage();

         if (sWelcomeMessage != "+OK HOWDYHO POP3\r\n")
            throw new Exception("ERROR - Wrong welcome message.");
      }

      [Test]
      public void TestConnection()
      {


         // Create a test account
         // Fetch the default domain
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "pop3user@test.com", "test");

         // Send 5 messages to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         for (int i = 0; i < 5; i++)
            oSMTP.Send("test@test.com", "pop3user@test.com", "INBOX", "POP3 test message");


         POP3Simulator.AssertMessageCount("pop3user@test.com", "test", 5);
      }

      [Test]
      public void TestRETR()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody1");
          POP3Simulator.AssertMessageCount(account.Address, "test", 1);

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody2");
          POP3Simulator.AssertMessageCount(account.Address, "test", 2);

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody3");
          POP3Simulator.AssertMessageCount(account.Address, "test", 3);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.RETR(1);
          Assert.IsTrue(result.Contains("TestBody1"), result);
          result = sim.RETR(2);
          Assert.IsTrue(result.Contains("TestBody2"), result);
          result = sim.RETR(3);
          Assert.IsTrue(result.Contains("TestBody3"), result);

          Assert.IsFalse(result.Contains(".\r\n."));
      }




      [Test]
      public void TestLIST()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody1");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody2");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody3");

          POP3Simulator.AssertMessageCount(account.Address, "test", 3);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.LIST();

          Assert.IsTrue(result.Contains("3 messages"));
          Assert.IsTrue(result.Contains("\r\n1"));
          Assert.IsTrue(result.Contains("\r\n2"));
          Assert.IsTrue(result.Contains("\r\n3"));
          Assert.IsTrue(result.Contains("\r\n."));
      }

      [Test]
      public void TestLISTWithDeleted()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          sim.DELE(2);
          sim.DELE(4);
          string result = sim.LIST();
          
          Assert.IsTrue(result.Contains("8 messages"));
          Assert.IsTrue(result.Contains("\r\n1"));
          Assert.IsTrue(result.Contains("\r\n3"));
          Assert.IsTrue(result.Contains("\r\n5"));
          Assert.IsTrue(result.Contains("\r\n."));
      }

      [Test]
      public void TestUIDLWithDeleted()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          sim.DELE(2);
          sim.DELE(4);
          string result = sim.UIDL();

          Assert.IsTrue(result.Contains("8 messages"));
          Assert.IsTrue(result.Contains("\r\n1"));
          Assert.IsTrue(result.Contains("\r\n3"));
          Assert.IsTrue(result.Contains("\r\n5"));
          Assert.IsTrue(result.Contains("\r\n."));
      }

      [Test]
      public void TestLISTInvalid()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.LIST(0);
          Assert.IsTrue(result.Contains("No such message"));
          result = sim.LIST(-1);
          Assert.IsTrue(result.Contains("No such message"));
          result = sim.LIST(100);
          Assert.IsTrue(result.Contains("No such message"));
      }

      [Test]
      public void TestUIDLInvalid()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.UIDL(0);
          Assert.IsTrue(result.Contains("No such message"));
          result = sim.UIDL(-1);
          Assert.IsTrue(result.Contains("No such message"));
          result = sim.UIDL(100);
          Assert.IsTrue(result.Contains("No such message"));
      }

      [Test]
      public void TestDELEInvalid()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          Assert.IsFalse(sim.DELE(0));
          Assert.IsFalse(sim.DELE(-1));
          Assert.IsFalse(sim.DELE(1000));
          Assert.IsTrue(sim.DELE(5));
      }

      [Test]
      public void TestLISTSpecific()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody1");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody2");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody3");

          POP3Simulator.AssertMessageCount(account.Address, "test", 3);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.LIST(2);

          Assert.IsTrue(result.Contains("OK 2"));

          result = sim.LIST(3);
          Assert.IsTrue(result.Contains("OK 3"));

      }

      [Test]
      public void TestUIDLSpecific()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody1");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody2");
          SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody3");

          POP3Simulator.AssertMessageCount(account.Address, "test", 3);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.UIDL(2);

          Assert.IsTrue(result.Contains("OK 2"));

          result = sim.UIDL(3);
          Assert.IsTrue(result.Contains("OK 3"));

      }


      [Test]
      public void TestTOPInvalid()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          Assert.IsTrue(sim.TOP(-1,0).Contains("No such message"));
          Assert.IsTrue(sim.TOP(0,0).Contains("No such message"));
          Assert.IsTrue(sim.TOP(100,0).Contains("No such message"));
      }

      [Test]
      public void TestTOPSpecificEntire()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody" + i.ToString());

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.TOP(1,0);

          Assert.IsTrue(result.Contains("Received"));
          Assert.IsTrue(result.Contains("Subject"));
      }

      [Test]
      public void TestTOPSpecificPartial()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          for (int i = 1; i <= 10; i++)
              SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "Line1\r\nLine2\r\nLine3\r\nLine4\r\nLine\r\n");

          POP3Simulator.AssertMessageCount(account.Address, "test", 10);

          POP3Simulator sim = new POP3Simulator();
          sim.ConnectAndLogon(account.Address, "test");
          string result = sim.TOP(4, 2);

          Assert.IsTrue(result.Contains("Received"));
          Assert.IsTrue(result.Contains("Line1"));
          Assert.IsTrue(result.Contains("Line2"));
          Assert.IsFalse(result.Contains("Line3"));
          Assert.IsFalse(result.Contains("Line4"));

      }


      [Test]
      [Description("Test to log on a mailbox containing a message which has been marked as deleted using IMAP")]
      public void TestLogonMailboxWithDeletedMessage()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         for (int i = 1; i <= 3; i++)
            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "Line1\r\nLine2\r\nLine3\r\nLine4\r\nLine\r\n");

         // Mark the second message as deleted using IMAP.
         POP3Simulator.AssertMessageCount(account.Address, "test", 3);

         IMAPSimulator sim = new IMAPSimulator();
         sim.ConnectAndLogon(account.Address, "test");
         sim.SelectFolder("INBOX");
         sim.SetDeletedFlag(2);
         sim.Disconnect();

         // Now list messages and confirm that all are listed.

         POP3Simulator pop3Client = new POP3Simulator();
         pop3Client.ConnectAndLogon(account.Address, "test");
         string listResponse = pop3Client.LIST();
         string uidlResponse = pop3Client.UIDL();

         Assert.IsTrue(listResponse.Contains("\r\n1"));
         Assert.IsTrue(listResponse.Contains("\r\n2"));
         Assert.IsTrue(listResponse.Contains("\r\n3"));
         Assert.IsTrue(listResponse.Contains("\r\n.\r\n"));
         Assert.IsTrue(listResponse.Contains("3 messages"));

         Assert.IsTrue(uidlResponse.Contains("\r\n1"));
         Assert.IsTrue(uidlResponse.Contains("\r\n2"));
         Assert.IsTrue(uidlResponse.Contains("\r\n3"));
         Assert.IsTrue(uidlResponse.Contains("\r\n.\r\n"));
         Assert.IsTrue(uidlResponse.Contains("3 messages"));

      }

      [Test]
      public void TestPOP3TransactionSafety()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         Assert.IsTrue(SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody"));
         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         POP3Simulator sim = new POP3Simulator();
         sim.ConnectAndLogon(account.Address, "test");
         
         // Now delete the message using an IMAP client.
         IMAPSimulator imapSimulator = new IMAPSimulator();
         Assert.IsTrue(imapSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(imapSimulator.SelectFolder("INBOX"));
         Assert.IsTrue(imapSimulator.SetDeletedFlag(1));
         Assert.IsTrue(imapSimulator.Expunge());
         Assert.AreEqual(0, imapSimulator.GetMessageCount("Inbox"));

         Assert.IsTrue(SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody"));
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);
         
         // This deletion should not have any effect, since the POP3 connection is referencing an old message.
         sim.DELE(1);
         sim.QUIT();

         Assert.AreEqual(1, imapSimulator.GetMessageCount("Inbox"));
      }
	  
	  private string[] GetTestFiles()
      {
         List<string> files = new List<string>();
         Assembly a = Assembly.GetExecutingAssembly();
         files.Add(a.Location);

         // create a file with a lot of dots.
         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < 10000; i++ )
         {
            sb.Append("....................");
         }

         string tempFile = Path.GetTempFileName() + ".txt";
         File.WriteAllText(tempFile, sb.ToString());
         files.Add(tempFile);

         return files.ToArray();
      }

      [Test]
      [Description("Test to send a number of attachments...")]
      public void TestAttachmentEncoding()
      {
         var testFiles = GetTestFiles();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         foreach (string testFile in testFiles)
         {
            Trace.WriteLine(testFile);
            

            string fileHash = Utilities.GetFileHash(testFile);

            MailMessage mail = new MailMessage();
            mail.From = new System.Net.Mail.MailAddress("test@test.com");
            mail.To.Add("test@test.com");
            mail.Subject = "Test";
            mail.Attachments.Add(new Attachment(testFile));
            
            SmtpClient client = new SmtpClient("localhost", 25);
            client.Send(mail);

            POP3Simulator.AssertMessageCount("test@test.com", "test", 1);

            POP3Simulator sim = new POP3Simulator();
            sim.ConnectAndLogon("test@test.com", "test");
            string fileContent = sim.RETR(1);
            sim.DELE(1);
            sim.QUIT();


            hMailServer.Message message = new hMailServer.Message();

            try
            {
               
               File.WriteAllText(message.Filename, fileContent);
               message.RefreshContent();

               message.Attachments[0].SaveAs(message.Filename);
               string fileHashAfter = Utilities.GetFileHash(message.Filename);

               Assert.AreEqual(fileHash, fileHashAfter);
            }
            finally
            {
               File.Delete(message.Filename);

            }
         }
      }
   }
}
