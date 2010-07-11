// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using NUnit.Framework;

namespace UnitTest.Delivery
{
   [TestFixture]
   public class BasicTests : TestFixtureBase
   {
      [SetUp]
      public new void SetUp()
      {
         SingletonProvider<Utilities>.Instance.DisableSpamProtection();
      }

      [Test]
      public void TestMirror()
      {
         // Create a test account
         // Fetch the default domain
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror@test.com", "test");
         hMailServer.Account oAccount2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror-test@test.com", "test");

         _settings.MirrorEMailAddress = "mirror-test@test.com";
         _settings.AddDeliveredToHeader = true;

         // Send 5 messages to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         for (int i = 0; i < 5; i++)
            oSMTP.Send("test@test.com", "mirror@test.com", "INBOX", "Mirror test message");

         // Check using POP3 that 5 messages exists.
         POP3Simulator.AssertMessageCount("mirror-test@test.com", "test", 5);

         string message = POP3Simulator.AssertGetFirstMessageText(oAccount2.Address, "test");

         Assert.IsTrue(message.Contains("Delivered-To: mirror@test.com"));
      }

      [Test]
      [Description("Issue 248, Delivered-To header invalid for mirror messages")]
      public void TestMirrorMultipleRecipients()
      {
         // Create a test account
         // Fetch the default domain
         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror1@test.com", "test");
         hMailServer.Account oAccount2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror2@test.com", "test");
         hMailServer.Account oAccount3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror3@test.com", "test");

         hMailServer.Account mirrorAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror-test@test.com", "test");

         _settings.MirrorEMailAddress = "mirror-test@test.com";
         _settings.AddDeliveredToHeader = true;

         // Send 5 messages to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("test@test.com", new List<string>() {oAccount1.Address, oAccount2.Address, oAccount3.Address}, "INBOX", "Mirror test message");

         POP3Simulator.AssertMessageCount(mirrorAccount.Address, "test", 1);

         string message = POP3Simulator.AssertGetFirstMessageText(mirrorAccount.Address, "test");

         Assert.IsTrue(message.Contains("Delivered-To: mirror1@test.com,mirror2@test.com,mirror3@test.com"));

         Utilities.AssertRecipientsInDeliveryQueue(0);
      }

      [Test]
      [Description("Issue 248, Delivered-To header invalid for mirror messages")]
      public void TestMirrorMultipleRecipientsOver255Chars()
      {
         // Create a test account
         // Fetch the default domain
         List<string> recipients = new List<string>();
         for (int i = 0; i < 20; i++)
         {
            string address = string.Format("mirror{0}@test.com", i);
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, address, "test");
            recipients.Add(address);
         }
         
         hMailServer.Account mirrorAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mirror-test@test.com", "test");

         _settings.MirrorEMailAddress = "mirror-test@test.com";
         _settings.AddDeliveredToHeader = true;

         // Send 5 messages to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("test@test.com", recipients, "INBOX", "Mirror test message");

         POP3Simulator.AssertMessageCount(mirrorAccount.Address, "test", 1);

         string message = POP3Simulator.AssertGetFirstMessageText(mirrorAccount.Address, "test");

         Assert.IsTrue(message.Contains("Delivered-To: mirror0@test.com,mirror1@test.com,mirror2@test.com,mirror3@test.com,mirror4@test.com,mirror5@test.com,mirror6@test.com,mirror7@test.com,mirror8@test.com,mirror9@test.com,mirror10@test.com,mirror11@test.com,mirror12@test.com,mirror13@test.com,mirror14@test\r\n"));

         Utilities.AssertRecipientsInDeliveryQueue(0);
      }

      [Test]
      public void TestAliases()
      {
         // Fetch default domain

         // Create another account
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test.com", "test");

         // Add aliases
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias1@test.com", "test2@test.com");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias2@test.com", "test2@test.com");
         SMTPSimulator oSMTP = new SMTPSimulator();

         // Spam folder
         oSMTP.Send("test@test.com", "test2@test.com", "Mail 1", "Mail 1");
         oSMTP.Send("test@test.com", "alias1@test.com", "Mail 2", "Mail 2");
         oSMTP.Send("test@test.com", "alias2@test.com", "Mail 3", "Mail 3");

         IMAPSimulator.AssertMessageCount("test2@test.com", "test", "Inbox", 3);
      }

   }
}
