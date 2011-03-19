// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Persistence
{
   [TestFixture]
   public class Limitations : TestFixtureBase
   {
      [Test]
      public void TestNameDuplicateAlias()
      {
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "secret1");

         try
         {
            SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test@test.com", "secret2");
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Alias with same name as account was permitted.");
      }


      [Test]
      public void TestNameDuplicateAccount()
      {
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "secret1");

         try
         {
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "secret2");
         }
         catch (Exception)
         {
            return;

         }
         Assert.Fail("Duplicate account was permitted");
      }


      [Test]
      public void TestNameDuplicateDistributionList()
      {
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test@test.com", "test2@test.com");

         List<string> recipients = new List<string>();

         try
         {
            SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "test@test.com", recipients);
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Distribution list with same name as alias was permitted.");
      }

      [Test]
      public void TestNameDuplicateGroup()
      {
         SingletonProvider<Utilities>.Instance.AddGroup("test@test.com");

         try
         {
            SingletonProvider<Utilities>.Instance.AddGroup("test@test.com");
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Two groups with same name was permitted.");
      }

      [Test]
      public void TestDomainLimitNumberOfAccounts()
      {
         _domain.MaxNumberOfAccountsEnabled = true;
         _domain.MaxNumberOfAccounts = 3;
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1");
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test.com", "secret1");
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test3@test.com", "secret1");

         try
         {
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test4@test.com", "secret1");
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Number of accounts exceeded max no of accounts");
      }

      [Test]
      public void TestDomainLimitNumberOfAliases()
      {
         _domain.MaxNumberOfAliasesEnabled = true;
         _domain.MaxNumberOfAliases = 4;
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test1@test.com", "test@test.com");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test2@test.com", "test@test.com");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test3@test.com", "test@test.com");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test4@test.com", "test@test.com");

         try
         {
            SingletonProvider<Utilities>.Instance.AddAlias(_domain, "test5@test.com", "test@test.com");   
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Number of aliases exceeded max no of accounts");
      }

      [Test]
      public void TestDomainLimitNumberOfDistributionLists()
      {
         _domain.MaxNumberOfDistributionListsEnabled = true;
         _domain.MaxNumberOfDistributionLists = 2;
         _domain.Save();

         List<string> recipients = new List<string>();
         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "test1@test.com", recipients);
         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "test2@test.com", recipients);

         try
         {
            SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "test3@test.com", recipients);
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Number of aliases exceeded max no of accounts");
      }

      [Test]
      public void TestDomainLimitAccountMaxSizeTest1()
      {
         _domain.MaxAccountSize = 25;
         _domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1", 1);
         account.Save();
      }

      [Test]
      public void TestDomainLimitAccountMaxSizeTest2()
      {
         _domain.MaxAccountSize = 25;
         _domain.Save();

         try
         {
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1", 32);
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Max account size limit exceeded.");
      }

      [Test]
      public void TestDomainLimitAccountMaxSizeTest3()
      {
         _domain.MaxAccountSize = 25;
         _domain.Save();

         try
         {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1", 0);
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Max account size limit exceeded (max size = 0)");
      }


      [Test]
      public void TestDomainMaxSizeLimit()
      {
         _domain.MaxSize = 30;
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1", 10);
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test.com", "secret1", 10);
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test3@test.com", "secret1", 10);


         try
         {
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test4@test.com", "secret1", 10);
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Max domain size limit exceeded.");
      }

      [Test]
      public void TestDomainMaxSizeLimitZeroSizeAccount()
      {
         _domain.MaxSize = 30;
         _domain.Save();

         try
         {
            SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test.com", "secret1", 0);
         }
         catch (Exception)
         {
            return;
         }

         Assert.Fail("Max domain size limit exceeded.");
      }

      [Test]
      public void TestDomainMaxMessageSizeLimit()
      {
         _domain.MaxMessageSize = 0;
         _domain.Save();

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "secret1", 0);
         StringBuilder message = new StringBuilder();

         for (int i = 0; i < 10000; i++ )
         {
            message.Append("ABCDEFGH");
         }

         Assert.IsTrue(SMTPClientSimulator.StaticSend("test@test.com", "test@test.com", "TestSubject", message.ToString()));
         POP3Simulator.AssertMessageCount("test@test.com", "secret1", 1);
         _domain.MaxMessageSize = 50;
         _domain.Save();

         Assert.IsFalse(SMTPClientSimulator.StaticSend("test@test.com", "test@test.com", "TestSubject", message.ToString()));

      }

      [Test]
      public void TestDomainNameDuplicate()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
         SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");
         
         try
         {
            SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Duplicate domain name was permitted.");
      }

      [Test]
      public void TestDomainWithSameNameAsDomainAlias()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;

         hMailServer.DomainAlias da = _domain.DomainAliases.Add();
         da.AliasName = "test2.com";
         da.Save();

         try
         {
            SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Domain with same name as domain alias was permitted.");
      }

      [Test]
      public void TestDomainAliasWithSameNameAsDomain()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;

         hMailServer.DomainAlias da = _domain.DomainAliases.Add();
         da.AliasName = "test.com";

         try
         {
            da.Save();
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Domain alias with same name as domain was permitted.");
      }


      [Test]
      public void TestDomainAliasRenameToSameNameAsDomain()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;

         hMailServer.DomainAlias da = _domain.DomainAliases.Add();
         da.AliasName = "test2.com";
         da.Save();

         try
         {
            da.AliasName = "test.com";
            da.Save();

         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Domain alias with same name as domain was permitted.");
      }


      [Test]
      public void TestDomainNameDuplicateDomainRename()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");

         domain.Name = "test.com";
         
         try
         {
            domain.Save();
         }
         catch (Exception)
         {
            return;
         }
         Assert.Fail("Duplicate domain name was permitted.");
      }

      [Test]
      public void TestAccountContainingForwardSlash()
      {
          try
          {
              SingletonProvider<Utilities>.Instance.AddAccount(_domain, "\\@test.com", "secret2");
          }
          catch (Exception)
          {
              return;
          }
          Assert.Fail("Account containing forward slash was permitted");
      }

      [Test]
      public void TestAccountContainingBackwardSlash()
      {
          try
          {
              SingletonProvider<Utilities>.Instance.AddAccount(_domain, "\\@test.com", "secret2");
          }
          catch (Exception)
          {
              return;
          }
          Assert.Fail("Account containing forward slash was permitted");
      }

      [Test]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException), ExpectedMessage = "The lower IP address must be lower or the same as the upper IP address.")]
      public void TestSaveInvalidIPRange()
      {
         hMailServer.Application app = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.SecurityRange range = app.Settings.SecurityRanges.Add();

         range.Name = "Test";
         range.LowerIP = "1.1.1.1";
         range.UpperIP = "0.0.0.0";
         range.Save();
      }


      [Test]
      public void TestSaveValidIPRange()
      {
         hMailServer.Application app = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.SecurityRange range = app.Settings.SecurityRanges.Add();

         range.Name = "Test";
         range.LowerIP = "0.0.0.0";
         range.UpperIP = "0.0.0.1";
         range.Save();
      }

      [Test]
      [Description("Issue 195, Creating two SMTP routes allowed for same domain.")]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException), ExpectedMessage = "Another route with this name already exists.")]
      public void TestDuplicateRoutes()
      {
         hMailServer.Application app = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Routes routes = app.Settings.Routes;

         hMailServer.Route route = routes.Add();
         route.DomainName = "test.com";
         route.Save();

         hMailServer.Route route2 = routes.Add();
         route2.DomainName = "test.com";

         route2.Save();
      }
   }
}
