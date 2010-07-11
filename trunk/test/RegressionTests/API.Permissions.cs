using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;

namespace UnitTest.API
{
   public class Permissions : TestFixtureBase
   {
      [Test]
      [Description("Issue 303, Domain administrators should not have permission to add new domains.")]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException),MatchType=MessageMatch.Contains, ExpectedMessage = "You do not have access to this property / method.")]
      public void DomainAdminShouldNotBeAbleToAddDomain()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();
         
         // Create an account with normal privileges.
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");
         account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
         account.Save();

         hMailServer.Application newApp = new hMailServer.Application();
         hMailServer.Account authenticated = newApp.Authenticate(account.Address, "test");
         Assert.IsNotNull(authenticated);

         // This should throw an exception.
         hMailServer.Domain newDomain = newApp.Domains.Add();
      }

      [Test]
      [Description("Issue 303, Normal users should not have permission to add new domains.")]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException), MatchType = MessageMatch.Contains, ExpectedMessage = "You do not have access to this property / method.")]
      public void NormalUserShouldNotBeAbleToAddDomain()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();

         // Create an account with normal privileges.
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");

         hMailServer.Application newApp = new hMailServer.Application();
         hMailServer.Account authenticated = newApp.Authenticate(account.Address, "test");
         Assert.IsNotNull(authenticated);

         // This should throw an exception.
         hMailServer.Domain newDomain = newApp.Domains.Add();
      }

      [Test]
      [Description("Issue 303, Server admin should be allowed to add domain.")]
      public void ServerAdminShouldBeAbleToAddDomain()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();

         // Create an account with normal privileges.
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");
         account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelServerAdmin;
         account.Save();

         hMailServer.Application newApp = new hMailServer.Application();
         hMailServer.Account authenticated = newApp.Authenticate(account.Address, "test");
         Assert.IsNotNull(authenticated);

         // This should throw an exception.
         hMailServer.Domain newDomain = newApp.Domains.Add();
      }

      [Test]
      public void DomainAdminShouldBeAbleToSaveDomain()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();

         // Create an account with normal privileges.
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");
         account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
         account.Save();

         hMailServer.Application newApp = new hMailServer.Application();
         hMailServer.Account authenticated = newApp.Authenticate(account.Address, "test");
         Assert.IsNotNull(authenticated);

         Assert.AreEqual(1, newApp.Domains.Count);

         // Retrieve our domain.
         hMailServer.Domain newDomain = newApp.Domains[0];
         newDomain.Save();
      }

      [Test]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException), MatchType = MessageMatch.Contains, ExpectedMessage = "You do not have access to this property / method.")]
      public void UserShouldNotBeAbleToSaveDomain()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();

         // Create an account with normal privileges.
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");
         account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
         account.Save();

         hMailServer.Application newApp = new hMailServer.Application();
         hMailServer.Account authenticated = newApp.Authenticate(account.Address, "test");
         Assert.IsNotNull(authenticated);

         Assert.AreEqual(1, newApp.Domains.Count);

         // Retrieve our domain.
         hMailServer.Domain newDomain = newApp.Domains[0];
         newDomain.Save();
      }


     
   }
}
