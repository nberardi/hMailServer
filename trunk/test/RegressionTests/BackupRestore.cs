// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.IO;
using System.Threading;

namespace UnitTest
{
    [TestFixture]
    public class BackupRestore : TestFixtureBase
    {
        private string _backupDir;
        
        static private string _folderCreationTime;

        private bool _backupMessages = true;

        [SetUp]
        public new void SetUp()
        {
            InitializeBackupSettings();
        }

        public void InitializeBackupSettings()
        {
            _application = SingletonProvider<Utilities>.Instance.GetApp();
            SetBackupDir(Path.Combine(Path.GetTempPath(), Utilities.RandomString()));

            DirectoryInfo dirInfo = new DirectoryInfo(_backupDir);
            dirInfo.Create();

            File.Delete(_application.Settings.Backup.LogFile);

        }

        public void SetBackupDir(string backupDir)
        {
            _backupDir = backupDir;
        }

        [Test]
        public void TestWithMessages()
        {
           _backupMessages = true;
           Assert.IsTrue(Execute());
        }

        [Test]
        public void TestWithoutMessages()
        {
           _backupMessages = false;
           Assert.IsTrue(Execute());
        }

        internal bool Execute()
        {
           Utilities.AssertDeleteFile(_application.Settings.Backup.LogFile);

           SetupEnvironment();
           if (!BackupEnvironment())
              return false;
           
           DeleteEnvironment();
           RestoreEnvironment();
           ConfirmRestore();

           Directory.Delete(_backupDir, true);

           return true;
        }

        private bool WaitForBackupCompletion()
        {
            Assert.IsNotNull(_application);

            for (int i = 0; i < 40; i++)
            {
                try
                {
                    string logFile = _application.Settings.Backup.LogFile;

                    string contents = Utilities.ReadExistingTextFile(logFile);

                    if (contents.IndexOf("Backup completed successfully") > 0)
                        return true;

                    if (contents.IndexOf("BACKUP ERROR:") > 0)
                    {
                        return false;
                    }

                }
                catch (Exception)
                {
                    // probably a share access violation.
                }

                Thread.Sleep(250);
            }

            return false;

        }

        private void WaitForRestoreCompletion(string lastServerStartTime)
        {
            Assert.IsNotNull(_application);

            for (int i = 0; i < 600; i++)
            {
                try
                {
                    string startTime = _application.Status.StartTime;

                    if (startTime.Length > 0 && startTime != lastServerStartTime)
                        return;
                }
                catch (Exception)
                {
                    // probably a share access violation.
                }

                Thread.Sleep(100);
            }

            throw new Exception("Timeout while waiting for backup or restore completion");

        }

        public void SetupEnvironment()
        {
            // Set up the domain. It's already set-up...
            hMailServer.Domain domain = _application.Domains[0];
            Assert.IsNotNull(domain);
            Assert.AreEqual("test.com", domain.Name);

            SetupDomainObject(domain);
            SetupDomainObjects(domain);
            SetupSettings();
        }

        private void SetupSettings()
        {
            SetupBlockedAttachment();
            SetupGreyListingWhiteList();
            SetupWhiteList();
            SetupRoutes();
            SetupDNSBlackLists();
            SetupSURBLServers();
            SetupSSLCertificates();
            SetupGroupObject();
            SetupPublicFolders();
            SetupIncomingRelay();
        }

        private void SetupSSLCertificates()
        {
            hMailServer.SSLCertificate cert = _application.Settings.SSLCertificates.Add();
            cert.CertificateFile = "file1.txt";
            cert.Name = "name1";
            cert.PrivateKeyFile = "pk1";
            cert.Save();

            cert = _application.Settings.SSLCertificates.Add();
            cert.CertificateFile = "file2.txt";
            cert.Name = "name2";
            cert.PrivateKeyFile = "pk2";
            cert.Save();
        }

        private void SetupBlockedAttachment()
        {
            hMailServer.BlockedAttachment ba = _application.Settings.AntiVirus.BlockedAttachments.Add();
            ba.Description = "My description";
            ba.Wildcard = "*.my";
            ba.Save();
        }

        private void SetupDNSBlackLists()
        {
            hMailServer.DNSBlackList black = _application.Settings.AntiSpam.DNSBlackLists.Add();
            black.Active = true;
            black.DNSHost = "127.0.0.1";
            black.ExpectedResult = "127.5.2.1";
            black.RejectMessage = "Test";
            black.Score = 4;
            black.Save();

            black = _application.Settings.AntiSpam.DNSBlackLists.Add();
            black.Active = true;
            black.DNSHost = "127.0.0.2";
            black.ExpectedResult = "127.5.2.2";
            black.RejectMessage = "Test2";
            black.Score = 5;
            black.Save();
        }

        private void SetupIncomingRelay()
        {
            hMailServer.IncomingRelay relay = _application.Settings.IncomingRelays.Add();
            relay.Name = "Test";
            relay.LowerIP = "1.2.3.4";
            relay.UpperIP = "4.3.2.1";
            relay.Save();
        }


        private void SetupSURBLServers()
        {
            hMailServer.SURBLServer black = _application.Settings.AntiSpam.SURBLServers.Add();
            black.Active = true;
            black.DNSHost = "127.0.0.1";
            black.RejectMessage = "Test";
            black.Score = 4;
            black.Save();

            black = _application.Settings.AntiSpam.SURBLServers.Add();
            black.Active = true;
            black.DNSHost = "127.0.0.2";
            black.RejectMessage = "Test2";
            black.Score = 5;
            black.Save();
        }

        private void SetupGreyListingWhiteList()
        {
            hMailServer.GreyListingWhiteAddresses addresses = _application.Settings.AntiSpam.GreyListingWhiteAddresses;

            hMailServer.GreyListingWhiteAddress address = addresses.Add();
            address.Description = "helo1";
            address.IPAddress = "1.1.1.1";
            address.Save();

            address = addresses.Add();
            address.Description = "helo2";
            address.IPAddress = "2.2.2.2";
            address.Save();
        }


        private void SetupWhiteList()
        {
            hMailServer.WhiteListAddresses addresses = _application.Settings.AntiSpam.WhiteListAddresses;

            hMailServer.WhiteListAddress address = addresses.Add();
            address.Description = "Desc1";
            address.EmailAddress = "Email1";
            address.LowerIPAddress = "1.1.1.1";
            address.UpperIPAddress = "2.2.2.2";
            address.Save();

            address = addresses.Add();
            address.Description = "Desc2";
            address.EmailAddress = "Email2";
            address.LowerIPAddress = "2.2.2.2";
            address.UpperIPAddress = "21.21.21.21";
            address.Save();
        }


        private void SetupRoutes()
        {
            hMailServer.Routes routes = _application.Settings.Routes;

            hMailServer.Route route = routes.Add();
            route.DomainName = "test1.com";
            route.Description = "description";
            route.UseSSL = true;
            route.TreatSenderAsLocalDomain = true; 
            route.TreatRecipientAsLocalDomain = false;
            route.Save();

            route = routes.Add();
            route.DomainName = "test2.com";
            route.Description = "description2";
            route.UseSSL = false;
            route.TreatSenderAsLocalDomain = false;
            route.TreatRecipientAsLocalDomain = true;
            route.Save();

            hMailServer.RouteAddresses addresses = route.Addresses;
            
            hMailServer.RouteAddress address1 = addresses.Add();
            address1.Address = "address1@test2.com";
            address1.Save();

            hMailServer.RouteAddress address2 = addresses.Add();
            address2.Address = "address2@test2.com";
            address2.Save();

            
        }

        private void SetupDomainObject(hMailServer.Domain domain)
        {
            domain.Postmaster = "someone@test.com";
            domain.SignatureEnabled = true;
            domain.AddSignaturesToLocalMail = true;
            domain.AddSignaturesToReplies = true;

            domain.SignaturePlainText = "PLS";
            domain.SignatureHTML = "HTML";
            domain.Save();

            hMailServer.DomainAlias da = domain.DomainAliases.Add();
            da.AliasName = "test1.com";
            da.Save();

            hMailServer.DomainAlias da2 = domain.DomainAliases.Add();
            da2.AliasName = "test2.com";
            da2.Save();
        }

        private void SetupDomainObjects(hMailServer.Domain domain)
        {
            SetupAccountObject(domain);
            SetupAliasObject(domain);
            SetupDistributionListObject(domain);


        }

        private void SetupPublicFolders()
        {
            hMailServer.IMAPFolders folders = _application.Settings.PublicFolders;
            hMailServer.IMAPFolder folder = folders.Add("Test1");
            folder.Save();

            folder = folders.Add("Test2");
            folder.Save();

            folder = folders.Add("Test3");
            folder.Save();

            folder = folders.Add("ACL");
            folder.Save();

            hMailServer.Domain domain = _application.Domains[0];
            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(domain, "acltest-1@test.com", "test");

            hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
            permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
            permission.PermissionAccountID = account1.ID;
            permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
            permission.set_Permission(hMailServer.eACLPermission.ePermissionInsert, true);
            permission.Save();

            folder = folder.SubFolders.Add("MySubFolder");
            folder.Save();

            hMailServer.Group group1 = _application.Settings.Groups.Add();
            group1.Name = "ACLTestGroup";
            group1.Save();

            permission = folder.Permissions.Add();
            permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
            permission.PermissionGroupID = group1.ID;
            permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
            permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
            permission.Save();


        }

        private void ConfirmPublicFolders()
        {
           if (_backupMessages)
           {
              hMailServer.Domain domain = _application.Domains[0];

              hMailServer.IMAPFolders publicFolders = _application.Settings.PublicFolders;

              Assert.IsNotNull(publicFolders.get_ItemByName("Test1"));
              Assert.IsNotNull(publicFolders.get_ItemByName("Test2"));
              Assert.IsNotNull(publicFolders.get_ItemByName("Test3"));
              Assert.IsNotNull(publicFolders.get_ItemByName("ACL"));

              hMailServer.IMAPFolderPermissions permissions = publicFolders.get_ItemByName("ACL").Permissions;
              Assert.AreEqual(1, permissions.Count);

              hMailServer.Account account1 = domain.Accounts.get_ItemByAddress("acltest-1@test.com");

              hMailServer.IMAPFolderPermission permission = permissions[0];

              Assert.AreEqual(hMailServer.eACLPermissionType.ePermissionTypeUser, permission.PermissionType);
              Assert.AreEqual(account1.ID, permission.PermissionAccountID);

              Assert.IsTrue(permission.get_Permission(hMailServer.eACLPermission.ePermissionAdminister));
              Assert.IsTrue(permission.get_Permission(hMailServer.eACLPermission.ePermissionInsert));
              Assert.IsFalse(permission.get_Permission(hMailServer.eACLPermission.ePermissionRead));
              Assert.IsFalse(permission.get_Permission(hMailServer.eACLPermission.ePermissionWriteSeen));

              hMailServer.Group group1 = _application.Settings.Groups.get_ItemByName("ACLTestGroup");

              permissions = publicFolders.get_ItemByName("ACL").SubFolders.get_ItemByName("MySubFolder").Permissions;
              permission = permissions[0];

              Assert.AreEqual(hMailServer.eACLPermissionType.ePermissionTypeGroup, permission.PermissionType);
              Assert.AreEqual(group1.ID, permission.PermissionGroupID);

              Assert.IsTrue(permission.get_Permission(hMailServer.eACLPermission.ePermissionLookup));
              Assert.IsTrue(permission.get_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox));
              Assert.IsFalse(permission.get_Permission(hMailServer.eACLPermission.ePermissionRead));
              Assert.IsFalse(permission.get_Permission(hMailServer.eACLPermission.ePermissionWriteSeen));
           }
        }

        private void SetupDistributionListObject(hMailServer.Domain domain)
        {
            List<string> listRecipients = new List<string>();
            listRecipients.Add("member1@test.com");
            listRecipients.Add("member2@test.com");
            listRecipients.Add("member3@test.com");

            hMailServer.DistributionList list = SingletonProvider<Utilities>.Instance.AddDistributionList(domain, "list@test.com", listRecipients);
        }

        private void SetupGroupObject()
        {
            hMailServer.Group group = _application.Settings.Groups.Add();
            group.Name = "TestGroup";
            group.Save();

            hMailServer.Account gm1 = SingletonProvider<Utilities>.Instance.AddAccount(_application.Domains[0], "gm1@test.com", "test");
            hMailServer.Account gm2 = SingletonProvider<Utilities>.Instance.AddAccount(_application.Domains[0], "gm2@test.com", "test");
            hMailServer.Account gm3 = SingletonProvider<Utilities>.Instance.AddAccount(_application.Domains[0], "gm3@test.com", "test");

            hMailServer.GroupMember gm = group.Members.Add();
            gm.AccountID = gm1.ID;
            gm.Save();

            gm = group.Members.Add();
            gm.AccountID = gm2.ID;
            gm.Save();

            gm = group.Members.Add();
            gm.AccountID = gm3.ID;
            gm.Save();
        }

        private void SetupAliasObject(hMailServer.Domain domain)
        {
            hMailServer.Alias alias = SingletonProvider<Utilities>.Instance.AddAlias(domain, "alias@test.com", "someone@test.com");
        }

        private void SetupAccountObject(hMailServer.Domain domain)
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");

            // Make sure the inbox contains two messages which should be backed up.
            Assert.IsTrue(SMTPClientSimulator.StaticSend(account.Address, account.Address, "Message 1 Subject", "Message 1 Body"));
            POP3Simulator.AssertMessageCount(account.Address, "test", 1);
           
            Assert.IsTrue(SMTPClientSimulator.StaticSend(account.Address, account.Address, "Message 2 Subject", "Message 2 Body"));
            POP3Simulator.AssertMessageCount(account.Address, "test", 2);

            Assert.IsTrue(SMTPClientSimulator.StaticSend(account.Address, account.Address, "Message 3 Subject", "Message 3 Body"));
            POP3Simulator.AssertMessageCount(account.Address, "test", 3);

            IMAPSimulator sim = new IMAPSimulator();
            Assert.IsTrue(sim.ConnectAndLogon(account.Address, "test"));
            Assert.IsTrue(sim.SelectFolder("Inbox"));
            Assert.IsTrue(sim.SetDeletedFlag(2));
            Assert.IsTrue(sim.Expunge());
            sim.Disconnect();

            _folderCreationTime = account.IMAPFolders.get_ItemByName("INBOX").CreationTime;

            account.Active = true;
            account.ADDomain = "AD";
            account.AdminLevel = hMailServer.eAdminLevel.hAdminLevelDomainAdmin;
            account.ADUsername = "AU";
            account.ForwardAddress = "FA";
            account.ForwardEnabled = false;
            account.ForwardKeepOriginal = true;
            account.IsAD = false;
            account.MaxSize = 1250;
            account.PersonFirstName = "First";
            account.PersonLastName = "Last";
            account.SignatureEnabled = true;
            account.SignatureHTML = "HTML";
            account.SignaturePlainText = "PLAIN";
            account.VacationMessage = "VAC";
            account.VacationMessageExpires = true;
            account.VacationMessageExpiresDate = "2020-01-01";
            account.VacationMessageIsOn = true;
            account.VacationSubject = "SUBJ";
            account.Password = "test";
            account.Save();

            // Set up fetch account
            hMailServer.FetchAccount fa = account.FetchAccounts.Add();
            fa.DaysToKeepMessages = 5;
            fa.Enabled = true;
            fa.MinutesBetweenFetch = 10;
            fa.Name = "test";
            fa.Port = 1110;
            fa.ProcessMIMEDate = true;
            fa.ProcessMIMERecipients = true;
            fa.ServerAddress = "127.0.0.1";
            fa.Username = "test";
            fa.UseSSL = false;
            fa.UseAntiSpam = true;
            fa.UseAntiVirus = true;
            fa.Save();

            DownloadFromExternalAccount(account, fa);

            hMailServer.Rule rule = account.Rules.Add();
            rule.Name = "MyRule";
            hMailServer.RuleCriteria criteria = rule.Criterias.Add();
            criteria.MatchType = hMailServer.eRuleMatchType.eMTGreaterThan;
            criteria.PredefinedField = hMailServer.eRulePredefinedField.eFTMessageSize;
            criteria.MatchValue = "0";
            criteria.Save();

            hMailServer.RuleAction action = rule.Actions.Add();
            action.Type = hMailServer.eRuleActionType.eRAForwardEmail;
            action.To = "someone@test.com";
            action.Body = "Test";
            action.Filename = "File";
            action.FromAddress = "T";
            action.FromName = "N";
            action.HeaderName = "H";
            action.IMAPFolder = "Folder";
            action.ScriptFunction = "Script";
            action.Subject = "Subj";
            action.Value = "Value";
            action.Save();

            rule.Save();

            
        }

        private void DownloadFromExternalAccount(hMailServer.Account account, hMailServer.FetchAccount fa)
        {
            if (!_backupMessages)
                return;

            // Download messages from the external account.
            List<string> messages = new List<string>();

            messages.Add("Subject: Message 1\r\n");
            messages.Add("Subject: Message 2\r\n");
            messages.Add("Subject: Message 3\r\n");

            int port = 1110;
            POP3Server pop3Server = new POP3Server(1, port, messages);
            pop3Server.StartListen();
            fa.DownloadNow();
            pop3Server.WaitForCompletion();

            Utilities.AssertRecipientsInDeliveryQueue(0);
            POP3Simulator.AssertMessageCount(account.Address, "test", 5);
        }

        private bool BackupEnvironment()
        {
            hMailServer.BackupSettings oBackupSettings = _application.Settings.Backup;
            oBackupSettings.BackupDomains = true;
            oBackupSettings.BackupMessages = _backupMessages;
            oBackupSettings.BackupSettings = true;
            oBackupSettings.Destination = _backupDir;

            _application.BackupManager.StartBackup();

            return WaitForBackupCompletion();
        }

        private void DeleteEnvironment()
        {
            while (_application.Domains.Count > 0)
                _application.Domains[0].Delete();

            hMailServer.WhiteListAddresses addresses = _application.Settings.AntiSpam.WhiteListAddresses;
            while (addresses.Count > 0)
                addresses[0].Delete();

            hMailServer.Routes routes = _application.Settings.Routes;
            while (routes.Count > 0)
                routes[0].Delete();

            hMailServer.BlockedAttachments attachments = _application.Settings.AntiVirus.BlockedAttachments;
            while (attachments.Count > 0)
                attachments[0].Delete();

            hMailServer.DNSBlackLists blackLists = _application.Settings.AntiSpam.DNSBlackLists;
            while (blackLists.Count > 0)
                blackLists[0].Delete();

            hMailServer.SURBLServers surblServers = _application.Settings.AntiSpam.SURBLServers;
            while (surblServers.Count > 0)
                surblServers[0].Delete();

            hMailServer.SSLCertificates sslCertificates = _application.Settings.SSLCertificates;
            while (sslCertificates.Count > 0)
                sslCertificates[0].Delete();

            hMailServer.IncomingRelays incomingRelays = _application.Settings.IncomingRelays;
            while (incomingRelays.Count > 0)
                incomingRelays[0].Delete();
        }

        private void RestoreEnvironment()
        {
            string startTime = _application.Status.StartTime;

            // locate backup file
            DirectoryInfo dirInfo = new DirectoryInfo(_backupDir);
            FileInfo[] files = dirInfo.GetFiles();

            string backupFile = files[0].FullName;

            hMailServer.Backup backup = _application.BackupManager.LoadBackup(backupFile);

            backup.RestoreDomains = true;
            backup.RestoreMessages = _backupMessages;
            backup.RestoreSettings = true;
            backup.StartRestore();

            WaitForRestoreCompletion(startTime);
        }

        private void ConfirmRestore()
        {
            ConfirmSettings();
            ConfirmDomainObject(_application.Domains[0]);
            ConfirmDomainObjects();
        }

        private void ConfirmSettings()
        {
            ConfirmGroupObject();
            ConfirmBlockedAttachments();
            ConfirmRoutes();
            ConfirmGreyListingWhiteList();
            ConfirmWhiteList();
            ConfirmDNSBlackLists();
            ConfirmSURBLServers();
            ConfirmSSLCertificates();
            ConfirmPublicFolders();
            ConfirmIncomingRelay();
        }

        private void ConfirmSSLCertificates()
        {
            hMailServer.SSLCertificate cert = _application.Settings.SSLCertificates[0];
            Assert.AreEqual("file1.txt", cert.CertificateFile);
            Assert.AreEqual("name1", cert.Name);
            Assert.AreEqual("pk1", cert.PrivateKeyFile);

            cert = _application.Settings.SSLCertificates[1];
            Assert.AreEqual("file2.txt", cert.CertificateFile);
            Assert.AreEqual("name2", cert.Name);
            Assert.AreEqual("pk2", cert.PrivateKeyFile);
        }

        private void ConfirmDNSBlackLists()
        {
            hMailServer.DNSBlackList black = _application.Settings.AntiSpam.DNSBlackLists.get_ItemByDNSHost("127.0.0.1");
            Assert.IsTrue(black.Active);
            Assert.AreEqual("127.5.2.1", black.ExpectedResult);
            Assert.AreEqual("Test", black.RejectMessage);
            Assert.AreEqual(4, black.Score);

            black = _application.Settings.AntiSpam.DNSBlackLists.get_ItemByDNSHost("127.0.0.2");
            Assert.IsTrue(black.Active);
            Assert.AreEqual("127.5.2.2", black.ExpectedResult);
            Assert.AreEqual("Test2", black.RejectMessage);
            Assert.AreEqual(5, black.Score);
        }

        private void ConfirmIncomingRelay()
        {
            hMailServer.IncomingRelays relays = _application.Settings.IncomingRelays;
            Assert.AreEqual(1, relays.Count);

            hMailServer.IncomingRelay relay = relays[0];
            Assert.AreEqual("Test", relay.Name);
            Assert.AreEqual("1.2.3.4", relay.LowerIP);
            Assert.AreEqual("4.3.2.1", relay.UpperIP);

        }

        private void ConfirmSURBLServers()
        {
            hMailServer.SURBLServer black = _application.Settings.AntiSpam.SURBLServers.get_ItemByDNSHost("127.0.0.1");
            Assert.IsTrue(black.Active);
            Assert.AreEqual("Test", black.RejectMessage);
            Assert.AreEqual(4, black.Score);

            black = _application.Settings.AntiSpam.SURBLServers.get_ItemByDNSHost("127.0.0.2");
            Assert.IsTrue(black.Active);
            Assert.AreEqual("Test2", black.RejectMessage);
            Assert.AreEqual(5, black.Score);
        }

        private void ConfirmBlockedAttachments()
        {
            hMailServer.BlockedAttachments attachments = _application.Settings.AntiVirus.BlockedAttachments;
            Assert.Greater(attachments.Count, 0);

            for (int i = 0; i < attachments.Count; i++)
            {
                hMailServer.BlockedAttachment ba = attachments[i];

                if (ba.Description == "My description" && ba.Wildcard == "*.my")
                    return;
            }

            Assert.Fail("Blocked attachment not found");
        }

        private void ConfirmRoutes()
        {
            hMailServer.Routes routes = _application.Settings.Routes;

            Assert.AreEqual(2, routes.Count);

            hMailServer.Route route = routes[0];
            Assert.AreEqual("test1.com", route.DomainName);
            Assert.AreEqual("description", route.Description);
            Assert.AreEqual(true, route.UseSSL);
            Assert.AreEqual(true, route.TreatSenderAsLocalDomain);
            Assert.AreEqual(false, route.TreatRecipientAsLocalDomain);
            Assert.AreEqual(false, route.TreatSecurityAsLocalDomain);

            route = routes[1];
            Assert.AreEqual("test2.com", route.DomainName);
            Assert.AreEqual("description2", route.Description);
            Assert.AreEqual(false, route.UseSSL);
            Assert.AreEqual(false, route.TreatSenderAsLocalDomain);
            Assert.AreEqual(true, route.TreatRecipientAsLocalDomain);
            Assert.AreEqual(true, route.TreatSecurityAsLocalDomain);

            Assert.AreEqual(2, route.Addresses.Count);

            List<string> addresses = new List<string>();
            addresses.Add(route.Addresses[0].Address);
            addresses.Add(route.Addresses[1].Address);

            Assert.IsTrue(addresses.Contains("address1@test2.com"));
            Assert.IsTrue(addresses.Contains("address2@test2.com"));
        }

        private void ConfirmGreyListingWhiteList()
        {
            hMailServer.GreyListingWhiteAddresses addresses = _application.Settings.AntiSpam.GreyListingWhiteAddresses;

            Assert.AreEqual(2, addresses.Count);

            hMailServer.GreyListingWhiteAddress address = addresses[0];
            Assert.AreEqual("helo1", address.Description);
            Assert.AreEqual("1.1.1.1", address.IPAddress);

            address = addresses[1];
            Assert.AreEqual("helo2", address.Description);
            Assert.AreEqual("2.2.2.2", address.IPAddress);

        }

        private void ConfirmWhiteList()
        {
            hMailServer.WhiteListAddresses addresses = _application.Settings.AntiSpam.WhiteListAddresses;

            Assert.AreEqual(2, addresses.Count);

            hMailServer.WhiteListAddress address = addresses[0];
            Assert.AreEqual("Desc1", address.Description);
            Assert.AreEqual("Email1", address.EmailAddress);
            Assert.AreEqual("1.1.1.1", address.LowerIPAddress);
            Assert.AreEqual("2.2.2.2", address.UpperIPAddress);

            address = addresses[1];
            Assert.AreEqual("Desc2", address.Description);
            Assert.AreEqual("Email2", address.EmailAddress);
            Assert.AreEqual("2.2.2.2", address.LowerIPAddress);
            Assert.AreEqual("21.21.21.21", address.UpperIPAddress);

        }

        private void ConfirmDomainObject(hMailServer.Domain domain)
        {
            Assert.AreEqual("someone@test.com", domain.Postmaster);
            Assert.IsTrue(domain.SignatureEnabled);
            Assert.IsTrue(domain.AddSignaturesToLocalMail);
            Assert.IsTrue(domain.AddSignaturesToReplies);
            Assert.AreEqual("PLS", domain.SignaturePlainText);
            Assert.AreEqual("HTML", domain.SignatureHTML);

            Assert.AreEqual("test.com", _application.Domains[0].Name);
            Assert.AreEqual(2, _application.Domains[0].DomainAliases.Count);
            Assert.AreEqual("test1.com", _application.Domains[0].DomainAliases[0].AliasName);
            Assert.AreEqual("test2.com", _application.Domains[0].DomainAliases[1].AliasName);
        }

        private void ConfirmDomainObjects()
        {
            ConfirmAccountObject();
            ConfirmAliasObject();
            ConfirmDistributionListObject();

        }

        private void ConfirmDistributionListObject()
        {
            hMailServer.DistributionList list = _application.Domains[0].DistributionLists[0];
            Assert.AreEqual("list@test.com", list.Address);
            Assert.AreEqual(3, list.Recipients.Count);
            Assert.AreEqual("member1@test.com", list.Recipients[0].RecipientAddress);
            Assert.AreEqual("member2@test.com", list.Recipients[1].RecipientAddress);
            Assert.AreEqual("member3@test.com", list.Recipients[2].RecipientAddress);
        }

        private void ConfirmAliasObject()
        {
            hMailServer.Alias alias = _application.Domains[0].Aliases[0];
            Assert.AreEqual("alias@test.com", alias.Name);
            Assert.AreEqual("someone@test.com", alias.Value);
        }

        private void ConfirmAccountObject()
        {
            hMailServer.Account account = _application.Domains[0].Accounts.get_ItemByAddress("test@test.com");


            Assert.IsTrue(account.Active);
            Assert.AreEqual("AD", account.ADDomain);
            Assert.AreEqual(hMailServer.eAdminLevel.hAdminLevelDomainAdmin, account.AdminLevel);
            Assert.AreEqual("AU", account.ADUsername);
            Assert.AreEqual("FA", account.ForwardAddress);
            Assert.IsFalse(account.ForwardEnabled);
            Assert.IsTrue(account.ForwardKeepOriginal);
            Assert.IsFalse(account.IsAD);
            Assert.AreEqual(1250, account.MaxSize);
            Assert.AreEqual("First", account.PersonFirstName);
            Assert.AreEqual("Last", account.PersonLastName);
            Assert.IsTrue(account.SignatureEnabled);
            Assert.AreEqual("HTML", account.SignatureHTML);
            Assert.AreEqual("PLAIN", account.SignaturePlainText);
            Assert.AreEqual("VAC", account.VacationMessage);
            Assert.IsTrue(account.VacationMessageExpires);
            Assert.AreEqual("2020-01-01", account.VacationMessageExpiresDate.Substring(0, 10));
            Assert.IsTrue(account.VacationMessageIsOn);
            Assert.AreEqual("SUBJ", account.VacationSubject);

            // Confirm fetch account
            hMailServer.FetchAccount fa = account.FetchAccounts.get_Item(0);
            Assert.AreEqual(5, fa.DaysToKeepMessages);
            Assert.IsTrue(fa.Enabled);
            Assert.AreEqual(10, fa.MinutesBetweenFetch);
            Assert.AreEqual("test", fa.Name);
            Assert.AreEqual(1110, fa.Port);
            Assert.AreEqual(true, fa.ProcessMIMEDate);
            Assert.IsTrue(fa.ProcessMIMERecipients);
            Assert.AreEqual("test", fa.Username);
            Assert.IsFalse(fa.UseSSL);
            Assert.AreEqual("127.0.0.1", fa.ServerAddress);
            Assert.IsTrue(fa.UseAntiSpam);
            Assert.IsTrue(fa.UseAntiVirus);

            // Make sur no additional mail is downloaded. We have already downloaded it.
            DownloadFromExternalAccount(account, fa);

            hMailServer.Rule rule = account.Rules[0];
            Assert.AreEqual("MyRule", rule.Name);

            hMailServer.RuleCriteria criteria = rule.Criterias[0];
            Assert.AreEqual(hMailServer.eRuleMatchType.eMTGreaterThan, criteria.MatchType);
            Assert.AreEqual(hMailServer.eRulePredefinedField.eFTMessageSize, criteria.PredefinedField);
            Assert.AreEqual("0", criteria.MatchValue);

            hMailServer.RuleAction action = rule.Actions[0];
            Assert.AreEqual(hMailServer.eRuleActionType.eRAForwardEmail, action.Type);
            Assert.AreEqual("someone@test.com", action.To);
            Assert.AreEqual("Test", action.Body);
            Assert.AreEqual("File", action.Filename);
            Assert.AreEqual("T", action.FromAddress);
            Assert.AreEqual("N", action.FromName);
            Assert.AreEqual("H", action.HeaderName);
            Assert.AreEqual("Folder", action.IMAPFolder);
            Assert.AreEqual("Script", action.ScriptFunction);
            Assert.AreEqual("Subj", action.Subject);
            Assert.AreEqual("Value", action.Value);

            hMailServer.IMAPFolder inbox = account.IMAPFolders.get_ItemByName("INBOX");
            
            hMailServer.Messages messages = inbox.Messages;

            if (_backupMessages)
            {
               Assert.AreEqual(6, inbox.CurrentUID);
               Assert.AreEqual(_folderCreationTime, inbox.CreationTime);

               Assert.AreEqual(5, messages.Count);
               Assert.AreEqual("Message 1 Subject", messages[0].Subject);
               Assert.IsTrue(messages[1].Body.Contains("Message 3 Body"));

               Assert.AreEqual(1, messages[0].UID);
               Assert.AreEqual(3, messages[1].UID);
            }
            else
            {
               Assert.AreEqual(0, messages.Count);
            }
        }

        private void ConfirmGroupObject()
        {
            hMailServer.Group group = _application.Settings.Groups.get_ItemByName("TestGroup");

            Assert.AreEqual("TestGroup", group.Name);
            Assert.AreEqual(3, group.Members.Count);

            Assert.AreEqual("gm1@test.com", group.Members[0].Account.Address);
            Assert.AreEqual("gm2@test.com", group.Members[1].Account.Address);
            Assert.AreEqual("gm3@test.com", group.Members[2].Account.Address);
        }
    }
}
