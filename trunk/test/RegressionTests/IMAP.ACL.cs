// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class ACL : TestFixtureBase
	{
      [Test]
      public void TestSetACLOnAccountFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2@test.com", "test");

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         Assert.IsTrue(oSimulator1.CreateFolder("SharedFolder"));
         Assert.IsFalse(oSimulator1.SetACL("SharedFolder", account2.Address, "lrswipkxtea"));
         oSimulator1.Disconnect();
      }

      [Test]
      public void TestSetAclOnPublicFolderNormalUser()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account3@test.com", "test");

         hMailServer.IMAPFolders publicFolders  = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();
         
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         Assert.IsFalse(oSimulator1.CreateFolder("#Public.Share1.MySub1"));
         oSimulator1.Disconnect();
      }

      [Test]
      public void TestSetAclOnPublicFolderNormalUserWithPrivilegies()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account4@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         Assert.IsTrue(oSimulator1.CreateFolder("#Public.Share1.MySub1"));
         oSimulator1.Disconnect();
      }

       /// <summary>
       /// Test that a public folder is included in the LIST response.
       /// </summary>
      [Test]
      public void TestListPublicFolder()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account4@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.LogonWithLiteral(account1.Address, "test");

          string result = oSimulator1.List();

          Assert.IsTrue(result.Contains(folder.Name));

          oSimulator1.Disconnect();
      }
      
       /// <summary>
       /// Test that if you create a folder named #public.Share1, both #public and #public.Share1
       /// are listed in the LIST response.
       /// </summary>
      [Test]
      public void TestLISTPublicFolderParent()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account5@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.Save();

         string folderName = "#Public.Share1";
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.List().Contains(folderName));

         // Add permissions to select and lookup
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         Assert.IsTrue(oSimulator1.List().Contains("#Public\"\r\n"));
         Assert.IsTrue(oSimulator1.List().Contains(folderName));

         oSimulator1.Disconnect();
      }

      /// <summary>
      /// Test that if you create a folder named #public.Share1, both #public and #public.Share1
      /// are listed in the LIST response.
      /// </summary>
      [Test]
      public void TestLSUBPublicFolderParent()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account5@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
          permission.Save();

          string folderName = "#Public.Share1";
          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");
          Assert.IsFalse(oSimulator1.LSUB().Contains(folderName));

          // Add permissions to select and lookup
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          Assert.IsTrue(oSimulator1.LSUB().Contains("#Public\"\r\n"));
          Assert.IsTrue(oSimulator1.LSUB().Contains(folderName));

          oSimulator1.Disconnect();
      }

      [Test]
      public void TestListPublicFolderGroupPermission()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2@test.com", "test");
         hMailServer.Account account3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account3@test.com", "test");

         hMailServer.Group group = SingletonProvider<Utilities>.Instance.AddGroup("TestGroup");
         SingletonProvider<Utilities>.Instance.AddGroupMember(group, account2);


         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionGroupID = group.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         string folderName = "#Public.Share1";

         // account 1 should not have permission since he's not in the group
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

         // account 2 should have permission since he is in the group
         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account2.Address, "test");
         Assert.IsTrue(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

         // account 3 should not have permission since he's not in the group
         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account3.Address, "test");
         Assert.IsFalse(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

         // add account 1 to the group to give him permission.
         hMailServer.GroupMember member = SingletonProvider<Utilities>.Instance.AddGroupMember(group, account1);
         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsTrue(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

         // delete account 1 from the group again to remove permissios.
         group.Members.DeleteByDBID(member.ID);
         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

      }

      [Test]
      public void TestListPublicFolderAnyonePermission()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2@test.com", "test");
         hMailServer.Account account3 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account3@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         string folderName = "#Public.Share1";

         // account 1 should not have permission since they aren't added yet.
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeAnyone;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         

         // account 1 should not have permission since he's not in the group
         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsTrue(oSimulator1.List().Contains(folderName));
         oSimulator1.Disconnect();


      }

      [Test]
      public void TestSelectPublicFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

                  hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account6@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.Save();
         
         string folderName = "#Public.Share1.MySub1";
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         Assert.IsTrue(oSimulator1.CreateFolder(folderName));
         
         Assert.IsFalse(oSimulator1.SelectFolderWithoutLiteral(folderName));

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestAppendToPublicFolder()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "append-public@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionInsert, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionPost, true);
          permission.Save();

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.LogonWithLiteral(account.Address, "test");
          oSimulator.SendSingleCommandWithLiteral("A01 APPEND #Public.Share1 {4}", "ABCD");
          Assert.AreEqual(1, oSimulator.GetMessageCount("#Public.Share1"));
          oSimulator.Disconnect();
      }

      [Test]
      public void TestCopyMessageToPublicFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account7@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.Save();

         string folderName = "#Public.Share1";

         SMTPClientSimulator.StaticSend("test@test.com", account1.Address, "TestMessage", "Body");

         Utilities.AssertMessageExistsInFolder(account1.IMAPFolders.get_ItemByName("INBOX"), 1);
         Utilities.AssertMessageExistsInFolder(folder, 0);

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         oSimulator1.SelectFolder("INBOX");
         
         // This should fails since we don't have ACL Insert permission.
         Assert.IsFalse(oSimulator1.Copy(1, folderName));

         // Give permission...
         permission.set_Permission(hMailServer.eACLPermission.ePermissionInsert, true);
         permission.Save();
         Assert.IsTrue(oSimulator1.Copy(1, folderName));

         oSimulator1.Disconnect();

         Utilities.AssertMessageExistsInFolder(folder, 1);
      }

      [Test]
      public void TestSetDeletedFlag()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account8@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionInsert, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         string folderName = "#Public.Share1";
         SMTPClientSimulator.StaticSend("test@test.com", account1.Address, "TestMessage", "Body");
         Utilities.AssertMessageExistsInFolder(account1.IMAPFolders.get_ItemByName("INBOX"), 1);
         Utilities.AssertMessageExistsInFolder(folder, 0);

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         oSimulator1.SelectFolder("INBOX");
         Assert.IsTrue(oSimulator1.Copy(1, folderName));

         Utilities.AssertMessageExistsInFolder(folder, 1);
         oSimulator1.SelectFolder(folderName);
         Assert.IsFalse(oSimulator1.SetDeletedFlag(1));

         permission.set_Permission(hMailServer.eACLPermission.ePermissionWriteDeleted, true);
         permission.Save();
         Assert.IsTrue(oSimulator1.SetDeletedFlag(1));

         oSimulator1.Disconnect();

         
      }

      [Test]
      public void TestExpunge()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionInsert, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionWriteDeleted, true);
         permission.Save();

         string folderName = "#Public.Share1";
         SMTPClientSimulator.StaticSend("test@test.com", account1.Address, "TestMessage", "Body");
         Utilities.AssertMessageExistsInFolder(account1.IMAPFolders.get_ItemByName("INBOX"), 1);
         Utilities.AssertMessageExistsInFolder(folder, 0);

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         oSimulator1.SelectFolder("INBOX");
         Assert.IsTrue(oSimulator1.Copy(1, folderName));
         Assert.IsTrue(oSimulator1.SelectFolder(folderName));
         Assert.IsTrue(oSimulator1.SetDeletedFlag(1));
         
         
         Assert.IsFalse(oSimulator1.Expunge());

         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.Save();
         Assert.IsTrue(oSimulator1.Expunge());

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestRenamePublicFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         string oldFolderName = "#Public.Share1.MySub1";
         string newFolderName = "#Public.Share1.MySub2";
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsTrue(oSimulator1.CreateFolder(oldFolderName));

         Assert.IsFalse(oSimulator1.RenameFolder(oldFolderName, newFolderName));

         // Add permissions to delete the mailbox.
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.Save();

         Assert.IsTrue(oSimulator1.RenameFolder(oldFolderName, newFolderName));

         Assert.IsFalse(oSimulator1.List().Contains(oldFolderName));
         Assert.IsTrue(oSimulator1.List().Contains(newFolderName));

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestCreateFolderWithSameNameAsPublic()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         string origPublicFolderName = _settings.IMAPPublicFolderName;

         _settings.IMAPPublicFolderName = "MyPublic";

         try
         {
            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account10@test.com", "test");

            IMAPSimulator oSimulator1 = new IMAPSimulator();
            oSimulator1.Connect();
            oSimulator1.Logon(account1.Address, "test");
            Assert.IsFalse(oSimulator1.CreateFolder("MyPublic"));
            oSimulator1.Disconnect();

         }
         finally
         {
            _settings.IMAPPublicFolderName = origPublicFolderName;
         }
      }

      [Test]
      public void TestRenameFolderToAndFromPublic()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account11@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         string oldFolderName = "#Public.Share1";
         string newFolderName = "AccountLevelFolder";
         
         // Test renaming from local folder name to shared folder.
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.RenameFolder(oldFolderName, newFolderName));
         oSimulator1.Disconnect();


         // Test renaming from local folder name to shared folder.
         oldFolderName = "LocalFolder";
         newFolderName = "#Public.Share1";

         oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         oSimulator1.CreateFolder(oldFolderName);
         Assert.IsFalse(oSimulator1.RenameFolder(oldFolderName, newFolderName));
         oSimulator1.Disconnect();
      }

      [Test]
      public void TestGetACL()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account12@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
         permission.Save();

         string folderName = "#Public.Share1";
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         string result = oSimulator1.GetACL(folderName);
         Assert.IsTrue(result.StartsWith("* ACL \"" + folderName + "\" " + account1.Address + " ka"));
         

         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.Save();
         result = oSimulator1.GetACL(folderName);
         Assert.IsTrue(result.StartsWith("* ACL \"" + folderName + "\" " + account1.Address + " kxa"));

         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();
         result = oSimulator1.GetACL(folderName);
         Assert.IsTrue(result.StartsWith("* ACL \"" + folderName + "\" " + account1.Address + " rkxa"));

         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.Save();
         result = oSimulator1.GetACL(folderName);
         Assert.IsTrue(result.StartsWith("* ACL \"" + folderName + "\" " + account1.Address + " rkxea"));

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestMyRights()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account13@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         string folderName = "#Public.Share1";
         string result = oSimulator1.GetMyRights(folderName);
         Assert.IsTrue(result.StartsWith("* MYRIGHTS \"" + folderName + "\" rkxea"));

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestListRights()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1b@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2b@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         string folderName = "#Public.Share1";

         string rights = oSimulator1.ListRights(folderName, account1.Address);
         Assert.IsTrue(rights.StartsWith("* LISTRIGHTS #Public.Share1 account1b@test.com l r s w i k x t e a"));
         oSimulator1.Disconnect();

      }


      [Test]
      public void TestCreateRootSharedFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1c@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2c@test.com", "test");

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsFalse(oSimulator1.CreateFolder("#Public.SharedFolder"));
         oSimulator1.Disconnect();
      }


      [Test]
      public void TestRenamePublicFolderToRootPublicFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1d@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.Save();

         string oldFolderName = "#Public.Share1.MySub1";
         string newFolderName = "#Public.Share2";
         
         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         Assert.IsTrue(oSimulator1.CreateFolder(oldFolderName));
         Assert.IsFalse(oSimulator1.RenameFolder(oldFolderName, newFolderName));

         Assert.IsTrue(oSimulator1.List().Contains(oldFolderName));
         Assert.IsFalse(oSimulator1.List().Contains(newFolderName));

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestPublicFolderSubscriptionAPI()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1e@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();
         
         Assert.IsTrue(folder.Subscribed);
      }

      [Test]
      public void TestPublicFolderSubscriptionCreate()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1f@test.com", "test");
         hMailServer.Account account2 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account2f@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         string folderName = "#Public.Share1.MySub";
         oSimulator1.CreateFolder(folderName);

         hMailServer.IMAPFolder theNewFolder = folder.SubFolders[0];
         Assert.IsTrue(theNewFolder.Name.Equals("MySub"));
         Assert.IsTrue(theNewFolder.Subscribed);

         oSimulator1.Disconnect();
      }

      [Test]
      public void TestPublicFolderCreateDeep()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         string folderName = "#Public.Share1.MySub1.MySub2.MySub3.MySub4";
         Assert.IsTrue(oSimulator1.CreateFolder(folderName));

         oSimulator1.Disconnect();
      }


      [Test]
      public void TestPublicFolderUnsubscribe()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1g@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionAdminister, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionExpunge, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.Logon(account1.Address, "test");
         string folderName = "#Public.Share1";
         Assert.IsFalse(oSimulator1.Unsubscribe(folderName));


         oSimulator1.Disconnect();
      }

      [Test]
      public void TestPublicFolderNoSelectAttribute()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1-p@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");
          
          Assert.IsTrue(oSimulator1.List("#Public").Contains("Noselect"));
          Assert.IsTrue(oSimulator1.List("#Public.Share1").Contains("#Public.Share1"));
          Assert.IsFalse(oSimulator1.List("#Public.Share1").Contains("Noselect"));

          oSimulator1.Disconnect();
      }


      [Test]
      public void TestListPublicFolderOnly()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1-p@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");

          Assert.IsTrue(oSimulator1.List("#Public").Contains("#Public"));

          oSimulator1.Disconnect();
      }

      [Test]
      public void TestListPublicFolderSubFolderOnly()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1-p@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");

          Assert.IsFalse(oSimulator1.List("#Public.Share1").Contains("#Public\r\n"));

          oSimulator1.Disconnect();
      }

      [Test]
      public void TestDelete()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.ConnectAndLogon("account9@test.com", "test");
          Assert.IsTrue(oSimulator1.SelectFolder("#public.Share1"));
          Assert.IsFalse(oSimulator1.DeleteFolder("#public.Share1"));

          permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
          permission.Save();

          Assert.IsTrue(oSimulator1.DeleteFolder("#public.Share1"));
          Assert.IsFalse(oSimulator1.SelectFolder("#public.Share1"));

          oSimulator1.Disconnect();
      }


      [Test]
      public void TestDeleteCheckAPI()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;

          Assert.AreEqual(0, publicFolders.Count);

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          Assert.AreEqual(1, publicFolders.Count);

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.ConnectAndLogon("account9@test.com", "test");
          Assert.IsTrue(oSimulator1.SelectFolder("#public.Share1"));
          Assert.IsFalse(oSimulator1.DeleteFolder("#public.Share1"));

          Assert.AreEqual(1, publicFolders.Count);

          permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
          permission.Save();

          Assert.IsTrue(oSimulator1.DeleteFolder("#public.Share1"));
          Assert.IsFalse(oSimulator1.SelectFolder("#public.Share1"));

          Assert.AreEqual(0, publicFolders.Count);

          oSimulator1.Disconnect();
      }

      [Test]
      public void TestDeleteSubFolderCheckAPI()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;

          Assert.AreEqual(0, publicFolders.Count);

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          Assert.AreEqual(1, publicFolders.Count);

          hMailServer.IMAPFolders mySubFolders = folder.SubFolders;
          Assert.AreEqual(0, mySubFolders.Count);

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionCreate, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.ConnectAndLogon("account9@test.com", "test");
          Assert.IsTrue(oSimulator1.CreateFolder("#public.Share1.MySub"));
          Assert.AreEqual(1, mySubFolders.Count);

          permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
          permission.Save();

          Assert.IsTrue(oSimulator1.DeleteFolder("#public.Share1.MySub"));
          Assert.IsFalse(oSimulator1.SelectFolder("#public.Share1.MySub"));

          Assert.AreEqual(0, mySubFolders.Count);
          Assert.AreEqual(1, publicFolders.Count);

          oSimulator1.Disconnect();
      }

      [Test]
      [Description("Test that when deleting an account, the corresponding permissions is removed as well.")]
      public void TestDeleteAccountHoldingGrant()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;

          Assert.AreEqual(0, publicFolders.Count);

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account9@test.com", "test");

          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          Assert.AreEqual(1, publicFolders.Count);

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionAccountID = account1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
          permission.Save();

          account1.Delete();

          Assert.AreEqual(0, folder.Permissions.Count);
      }

      [Test]
      [Description("Test that when deleting an group, the corresponding permissions is removed as well.")]
      public void TestDeleteGroupHoldingGrant()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");

          hMailServer.Group group = SingletonProvider<Utilities>.Instance.AddGroup("TestGroup");
          SingletonProvider<Utilities>.Instance.AddGroupMember(group, account1);


          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
          permission.PermissionGroupID = group.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
          permission.Save();

          group.Delete();

          Assert.AreEqual(0, folder.Permissions.Count);

      }

      [Test]
      [Description("Test to create two groups with the same user account. The permissions for the FIRST group should be used.")]
      public void TestDuplicateConflictingGroupPermission()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "account1@test.com", "test");

          hMailServer.Group group1 = SingletonProvider<Utilities>.Instance.AddGroup("TestGroup1");
          SingletonProvider<Utilities>.Instance.AddGroupMember(group1, account1);

          hMailServer.Group group2 = SingletonProvider<Utilities>.Instance.AddGroup("TestGroup2");
          SingletonProvider<Utilities>.Instance.AddGroupMember(group2, account1);

          hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
          hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
          folder.Save();

          hMailServer.IMAPFolderPermissions permissions = folder.Permissions;

          hMailServer.IMAPFolderPermission permission = permissions.Add();
          permission.PermissionGroupID = group1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
          permission.Save();

          hMailServer.IMAPFolderPermission permission2 = permissions.Add();
          permission2.PermissionGroupID = group2.ID;
          permission2.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
          permission2.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission2.Save();

          string folderName = "#Public.Share1";

          // The account should not have permission since the first permission doesn't give him this.
          IMAPSimulator oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");
          Assert.IsFalse(oSimulator1.List().Contains(folderName));
          oSimulator1.Disconnect();

          // Now delete the permissions and in the first permission give the group the rights.
          while (permissions.Count > 0)
              permissions.Delete(0);

          permission = permissions.Add();
          permission.PermissionGroupID = group1.ID;
          permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
          permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
          permission.Save();

          permission2 = permissions.Add();
          permission2.PermissionGroupID = group2.ID;
          permission2.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeGroup;
          permission2.Save();

          // The account should not have permission since the first permission does give him this.
          oSimulator1 = new IMAPSimulator();
          oSimulator1.Connect();
          oSimulator1.Logon(account1.Address, "test");
          Assert.IsTrue(oSimulator1.List().Contains(folderName));
          oSimulator1.Disconnect();


      }

      [Test]
      public void FolderMarkedAsReadOnlyWhenUserHasReadOnlyRights()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "reader@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.Save();

         string selectResult = string.Empty;

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         oSimulator1.SelectFolder("#Public.Share1", out selectResult);
         oSimulator1.Disconnect();

         Assert.IsTrue(selectResult.Contains("[READ-ONLY]"), selectResult);
         Assert.IsFalse(selectResult.Contains("[READ-WRITE]"), selectResult);

      }

      [Test]
      public void FolderMarkedAsReadWriteWhenUserHasChangeRights()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "reader@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionWriteOthers, true);
         permission.Save();

         string selectResult = string.Empty;

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         oSimulator1.SelectFolder("#Public.Share1", out selectResult);
         oSimulator1.Disconnect();

         Assert.IsTrue(selectResult.Contains("[READ-WRITE]"), selectResult);
         Assert.IsFalse(selectResult.Contains("[READ-ONLY]"), selectResult);
      }

      [Test]
      public void ExamineFolderRequiresReadPermission()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "reader@test.com", "test");

         hMailServer.IMAPFolders publicFolders = _settings.PublicFolders;
         hMailServer.IMAPFolder folder = publicFolders.Add("Share1");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionAccountID = account1.ID;
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeUser;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.Save();

         string selectResult = string.Empty;

         IMAPSimulator oSimulator1 = new IMAPSimulator();
         oSimulator1.Connect();
         oSimulator1.LogonWithLiteral(account1.Address, "test");
         string examineResult = oSimulator1.ExamineFolder("#Public.Share1");
         oSimulator1.Disconnect();

         Assert.IsTrue(examineResult.Contains("ACL: Read permission denied (Required for EXAMINE command)."), examineResult);
      }
	}
}
