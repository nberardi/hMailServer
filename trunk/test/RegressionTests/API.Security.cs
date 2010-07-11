// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;
using System.Runtime.InteropServices;

namespace UnitTest.API
{
    [TestFixture]
    public class Security : TestFixtureBase
    {
        [Test]
        [ExpectedException(ExpectedMessage="You do not have access to this property / method.", MatchType=MessageMatch.Contains)]
        public void TestNormalUserAccessSettings()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.Settings settings = newApplication.Settings;
        }

        [Test]
        [ExpectedException(ExpectedMessage = "You do not have access to this property / method.", MatchType = MessageMatch.Contains)]
        public void TestDomainAdminAccessSettings()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.Settings settings = newApplication.Settings;
        }

        [Test]
        [ExpectedException(ExpectedMessage = "You do not have access to this property / method.", MatchType = MessageMatch.Contains)]
        public void TestNormalUserAccessBackupManager()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.BackupManager backupManager = newApplication.BackupManager;
        }

        [Test]
        [ExpectedException(ExpectedMessage = "You do not have access to this property / method.", MatchType = MessageMatch.Contains)]
        public void TestDomainAdminAccessBackupManager()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.BackupManager backupManager = newApplication.BackupManager;
        }

        [Test]
        [ExpectedException(ExpectedMessage = "You do not have access to this property / method.", MatchType = MessageMatch.Contains)]
        public void TestNormalUserAccessDatabase()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.Database database = newApplication.Database;
            database.ExecuteSQL("select");
        }

        [Test]
        [ExpectedException(ExpectedMessage = "You do not have access to this property / method.", MatchType = MessageMatch.Contains)]
        public void TestDomainAdminAccessDatabase()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
            account.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            hMailServer.Database database = newApplication.Database;
            database.ExecuteSQL("select");
        }

        [Test]
        public void TestNormalUserAccessOtherDomain()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            account.Save();

            SingletonProvider<Utilities>.Instance.AddDomain("example.com");

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            Assert.AreEqual(1, newApplication.Domains.Count);

            hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
            Assert.AreEqual(2, domains.Count);

            try
            {
                hMailServer.Domain secondDomain = newApplication.Domains.get_ItemByName("example.com");
                Assert.Fail();
            }
            catch (COMException ex)
            {
                Assert.IsTrue(ex.Message.Contains("Invalid index."));
            }
        }

        [Test]
        public void TestDomainAdminAccessOtherDomain()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
            account.Save();

            SingletonProvider<Utilities>.Instance.AddDomain("example.com");

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            Assert.AreEqual(1, newApplication.Domains.Count);

            hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
            Assert.AreEqual(2, domains.Count);

            try
            {
                hMailServer.Domain secondDomain = newApplication.Domains.get_ItemByName("example.com");
                Assert.Fail();
            }
            catch (COMException ex)
            {
                Assert.IsTrue(ex.Message.Contains("Invalid index."));
            }
        }

        [Test]
        public void TestNormalUserAccessOtherAccount()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            account.Save();

            hMailServer.Account secondAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "second@test.com", "test");
            secondAccount.AdminLevel = hMailServer.eAdminLevel.hAdminLevelNormal;
            secondAccount.Save();

            hMailServer.Application newApplication = new hMailServer.Application();
            newApplication.Authenticate("user@test.com", "test");
            Assert.AreEqual(1, newApplication.Domains.Count);
            Assert.AreEqual(1, newApplication.Domains[0].Accounts.Count);

            hMailServer.Account myAccount = newApplication.Domains[0].Accounts.get_ItemByAddress("user@test.com");

            try
            {
                hMailServer.Account otherAccount = newApplication.Domains[0].Accounts.get_ItemByAddress("second@test.com");
                
                Assert.Fail();
            }
            catch (COMException ex)
            {
                Assert.IsTrue(ex.Message.Contains("Invalid index."));
            }

            hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
            Assert.AreEqual(2, domains[0].Accounts.Count);

        }

        
    }
}
