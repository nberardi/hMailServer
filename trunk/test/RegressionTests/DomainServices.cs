// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.Services
{
   [TestFixture]
   public class DomainServices : TestFixtureBase
   {
      [Test]
      public void TestDomainAliases()
      {


         // Create a test account
         // Fetch the default domain
         hMailServer.DomainAlias oDomainAlias = _domain.DomainAliases.Add();
         oDomainAlias.AliasName = "alias.com";
         oDomainAlias.Save();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "domain-alias-test@test.com", "test");

         // Send 5 messages to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         for (int i = 0; i < 5; i++)
            oSMTP.Send("domain-alias-test@alias.com", "domain-alias-test@alias.com", "INBOX", "Alias test message");

         POP3Simulator.AssertMessageCount("domain-alias-test@alias.com", "test", 5);

         {
            oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "domain-alias-test-account@test.com", "test");

            // Set up an alias pointing at the domain alias.
            SingletonProvider<Utilities>.Instance.AddAlias(_domain, "datestalias@test.com", "domain-alias-test-account@alias.com");

            // Send to the alias
            for (int i = 0; i < 5; i++)
               oSMTP.Send(oAccount.Address, "datestalias@test.com", "INBOX", "Plus addressing message");
            // Wait for completion

            POP3Simulator.AssertMessageCount(oAccount.Address, "test", 5);
         }

      }

      [Test]
      [Description("Test of virtual domains - test sending to four accounts on two different domains.")]
      public void TestMultipleDomains()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test.com", "test");

         hMailServer.Domain domain2 = SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");

         hMailServer.Account account3 = SingletonProvider<Utilities>.Instance.AddAccount(domain2, "test1@test2.com", "test");
         hMailServer.Account account4 = SingletonProvider<Utilities>.Instance.AddAccount(domain2, "test2@test2.com", "test");

         SMTPClientSimulator smtpSimulator = new SMTPClientSimulator();
         smtpSimulator.Send("test@alias.com", account1.Address, "Test", "test1@test.com");
         smtpSimulator.Send("test@alias.com", account2.Address, "Test", "test2@test.com");
         smtpSimulator.Send("test@alias.com", account3.Address, "Test", "test1@test1.com");
         smtpSimulator.Send("test@alias.com", account4.Address, "Test", "test2@test1.com");

         Assert.IsTrue(POP3Simulator.AssertGetFirstMessageText(account1.Address, "test").Contains(account1.Address));
         Assert.IsTrue(POP3Simulator.AssertGetFirstMessageText(account2.Address, "test").Contains(account2.Address));
         Assert.IsTrue(POP3Simulator.AssertGetFirstMessageText(account3.Address, "test").Contains(account3.Address));
         Assert.IsTrue(POP3Simulator.AssertGetFirstMessageText(account4.Address, "test").Contains(account4.Address));
      }

      [Test]
      public void TestPlusAddressing()
      {


         // Create a test account
         // Fetch the default domain
         // Enable plus adressing
         _domain.PlusAddressingEnabled = true;
         _domain.PlusAddressingCharacter = "+";

         // Save the change
         _domain.Save();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "plustest@test.com", "test");
         hMailServer.Account oAccount2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "plustest2@test.com", "test");

         // Send 5 messages to this account, without using plus addressing.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         for (int i = 0; i < 5; i++)
            oSMTP.Send("plustest@test.com", "plustest2@test.com", "INBOX", "Plus addressing message");
         // Wait for completion

         // Check using POP3 that 5 messages exists.
         POP3Simulator.AssertMessageCount("plustest2@test.com", "test", 5);

         // Send using plus addressing
         for (int i = 0; i < 5; i++)
            oSMTP.Send("plustest@test.com", "plustest2+hejsan@test.com", "INBOX", "Plus addressing message");
         // Wait for completion

         POP3Simulator.AssertMessageCount("plustest2@test.com", "test", 10);

         {
            hMailServer.Account oAccount3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "plustest3@test.com", "test");

            SingletonProvider<Utilities>.Instance.AddAlias(_domain, "plusalias@test.com", "plustest3+hejsan@test.com");

            // Send to the alias
            for (int i = 0; i < 5; i++)
               oSMTP.Send("plustest@test.com", "plusalias@test.com", "INBOX", "Plus addressing message");
            // Wait for completion

            POP3Simulator.AssertMessageCount("plustest3@test.com", "test", 5);
         }

         _domain.PlusAddressingEnabled = false;

      }


   }
}
