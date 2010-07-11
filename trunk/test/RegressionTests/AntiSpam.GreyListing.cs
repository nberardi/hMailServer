// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;

namespace UnitTest.AntiSpam
{
   [TestFixture]
   public class GreyListing : TestFixtureBase
   {
      hMailServer.AntiSpam _antiSpam;

      [SetUp]
      public new void SetUp()
      {
         _antiSpam = _settings.AntiSpam;
      }

      [Test]
      public void TestGreyListing()
      {
         _antiSpam.GreyListingEnabled = false;

         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "grey@test.com", "test");

         SMTPSimulator smtp = new SMTPSimulator();
         List<string> recipients = new List<string>();
         recipients.Add(oAccount1.Address);
         bool result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsTrue(result);
         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         _antiSpam.GreyListingEnabled = true;

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsFalse(result);

         _antiSpam.GreyListingEnabled = false;

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsTrue(result);
         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

      }

      [Test]
      [Description("Test that grey listing can be enabled if message arrives from A or MX record.")]
      public void ItShouldBePossibleToBypassGreylistingOnMessagesArrivingFromMXorA()
      {
         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "grey@test.com", "test");

         _antiSpam.GreyListingEnabled = true;

         Assert.IsFalse(SMTPSimulator.StaticSend("test@localhost.hmailserver.com", oAccount1.Address, "Test", "Body"));

         _antiSpam.BypassGreylistingOnMailFromMX = true;

         Assert.IsTrue(SMTPSimulator.StaticSend("test@localhost.hmailserver.com", oAccount1.Address, "Test", "Body"));

         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
      }

      [Test]
      public void TestGreyListingWithDomainAliases()
      {
         _antiSpam.GreyListingEnabled = false;

         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "grey@test.com", "test");

         SMTPSimulator smtp = new SMTPSimulator();
         List<string> recipients = new List<string>();
         recipients.Add(oAccount1.Address);
         bool result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsTrue(result);
         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         _antiSpam.GreyListingEnabled = true;

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsFalse(result);

         _domain.AntiSpamEnableGreylisting = false;
         _domain.Save();

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsTrue(result);
         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         hMailServer.DomainAlias da = _domain.DomainAliases.Add();
         da.AliasName = "test2.com";
         da.Save();

         recipients = new List<string>();
         recipients.Add("grey@test2.com");

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsTrue(result);
         POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         _domain.AntiSpamEnableGreylisting = true;
         _domain.Save();

         result = smtp.Send("test@test.com", recipients, "Test", "Body");
         Assert.IsFalse(result);
      }

      [Test]
      public void TestGreyListingWhiteListWildcard()
      {
         _antiSpam.GreyListingEnabled = true;

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "grey@test.com", "test");

         hMailServer.GreyListingWhiteAddresses whiteAddresses = _antiSpam.GreyListingWhiteAddresses;
         hMailServer.GreyListingWhiteAddress whiteAddress = whiteAddresses.Add();
         whiteAddress.IPAddress = "127.0.0.5";
         whiteAddress.Save();

         Assert.IsFalse(SMTPSimulator.StaticSend("external@example.com", account.Address, "Test", "Test"));

         whiteAddress.IPAddress = "*";
         whiteAddress.Save();

         Assert.IsTrue(SMTPSimulator.StaticSend("external@example.com", account.Address, "Test", "Test"));

         POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
      }

   }
}
