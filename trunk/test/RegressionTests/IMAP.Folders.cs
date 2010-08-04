// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class Folders : TestFixtureBase
   {
      [Test]
      public void TestRenameToSubFolder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder1@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         Assert.IsTrue(oSimulator.CreateFolder("1.2.3.4.5"));
         Assert.IsTrue(oSimulator.CreateFolder("A"));
         Assert.IsTrue(oSimulator.RenameFolder("1", "A.1"));
         Assert.IsTrue(oSimulator.SelectFolder("A.1"));
         Assert.IsTrue(oSimulator.SelectFolder("A.1.2.3.4.5"));
         Assert.IsTrue(oSimulator.RenameFolder("A.1", "1"));
         Assert.IsFalse(oSimulator.SelectFolder("A.1"));
         Assert.IsFalse(oSimulator.SelectFolder("A.1.2.3.4.5"));
         Assert.IsTrue(oSimulator.SelectFolder("1"));
         Assert.IsTrue(oSimulator.SelectFolder("1.2.3.4.5"));

         oSimulator.Disconnect();
      }

      [Test]
      [Description("Issue 274, IMAP: Moving folder to sub-folder")]
      public void TestRenameSubFolderToChildSub()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder1@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();
         Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(oSimulator.CreateFolder("A.B"));

         string result;
         Assert.IsFalse(oSimulator.RenameFolder("A.B", "A.B.C", out result));
         Assert.IsTrue(result.Contains("A folder cannot be moved into one of its subfolders."));

         Assert.IsTrue(oSimulator.SelectFolder("A.B"));

         oSimulator.Disconnect();
      }

      [Test]
      [Description("Issue 274, Test side effect of fix for 274")]
      public void TestRenameSubFolderToMatchingName()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder1@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();
          Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
          Assert.IsTrue(oSimulator.CreateFolder("Folder1"));
          Assert.IsTrue(oSimulator.SelectFolder("Folder1"));

          string result = string.Empty;
          Assert.IsFalse(oSimulator.RenameFolder("Folder1", "Folder1.Sub1", out result));
          Assert.IsTrue(result.Contains("A folder cannot be moved into one of its subfolders."));
          Assert.IsTrue(oSimulator.SelectFolder("Folder1"));

          result = string.Empty;
          Assert.IsTrue(oSimulator.RenameFolder("Folder1", "Folder1Test", out result));
          Assert.IsTrue(oSimulator.SelectFolder("Folder1Test"));

          oSimulator.Disconnect();
      }

      [Test]
      public void TestRenameLongFolder()
      {
         

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder2@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         Assert.IsTrue(oSimulator.CreateFolder("1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25"));
         Assert.IsTrue(oSimulator.CreateFolder("A"));
         
         Assert.IsFalse(oSimulator.RenameFolder("1", "A.1"));
         Assert.IsTrue(oSimulator.RenameFolder("1.2.3", "A.1"));
         Assert.IsTrue(oSimulator.SelectFolder("A.1.4"));


         oSimulator.Disconnect();
      }

      [Test]
      public void TestRenameToAndFromINBOX()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder3@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         oSimulator.Send("A01 CREATE A\r\n");
         Assert.IsFalse(oSimulator.RenameFolder("A", "INBOX"));
         Assert.IsFalse(oSimulator.RenameFolder("INBOX", "B"));

         oSimulator.Disconnect();
      }

      [Test]
      public void TestCreateDeepFolder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder4@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         string result = oSimulator.Send("A01 CREATE 1.2.3.4.5.6.7.8.9.10.11.12.13.14.15.16.17.18.19.20.21.22.23.24.25.26");
         Assert.IsTrue(result.Contains("A01 NO"));

         oSimulator.Disconnect();
      }

      [Test]
      public void TestCreateParallelFolder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder5@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         string result = oSimulator.Send("A01 CREATE 1.2.3");
         Assert.IsTrue(result.Contains("A01 OK"));
         result = oSimulator.Send("A01 CREATE 1.2.4");
         Assert.IsTrue(result.Contains("A01 OK"));

         oSimulator.Disconnect();
      }



      [Test]
      public void TestCreateFolderWithHash()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder6@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon(oAccount.Address, "test");
         Assert.IsFalse(oSimulator.CreateFolder("#Test"));
         Assert.IsTrue(oSimulator.CreateFolder("Test.#Testar"));
         oSimulator.Disconnect();
      }



      [Test]
      public void TestCreateUnnamedSubFolder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder7@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         string result = oSimulator.Send("A01 CREATE 1..3");
         Assert.IsTrue(result.Contains("A01 NO"));
         result = oSimulator.Send("A01 CREATE 1....3");
         Assert.IsTrue(result.Contains("A01 NO"));
         result = oSimulator.Send("A01 CREATE 1.......3");
         Assert.IsTrue(result.Contains("A01 NO"));


         oSimulator.Disconnect();
      }

      [Test]
      public void TestRenameIncorrectParameters()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder8@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         string result = oSimulator.Send("A01 CREATE A");
         
         result = oSimulator.Send("A02 RENAME A B C");
         Assert.IsTrue(result.Contains("A02 BAD"));

         oSimulator.Disconnect();
      }

      [Test]
      public void TestCreateLongFolder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder9@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral(oAccount.Address, "test");
         
         string folderName = "";
         for (int i = 0; i < 255; i++)
            folderName = folderName + "A";

         string result = oSimulator.Send("A01 CREATE " + folderName);
         Assert.IsTrue(result.Contains("A01 OK"));
         Assert.IsTrue(oSimulator.SelectFolder(folderName));

         folderName = "";
         for (int i = 0; i < 256; i++)
            folderName = folderName + "A";

         result = oSimulator.Send("A01 CREATE " + folderName);
         Assert.IsTrue(result.Contains("A01 NO"));
         Assert.IsFalse(oSimulator.SelectFolder(folderName));

         oSimulator.Disconnect();
      }


      [Test]
      public void TestCreateFolderWithQuote()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");


          string folderName = "ABC\"123";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsTrue(oSimulator.List().Contains(folderName));
          Assert.IsTrue(oSimulator.SelectFolder(folderName));
          oSimulator.Disconnect();
      }

      [Test]
      public void TestCreateFolderWithSlash()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "ABC\\123";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsTrue(oSimulator.List().Contains(folderName));
          Assert.IsTrue(oSimulator.SelectFolder(folderName));
          oSimulator.Disconnect();
      }

      [Test]
      public void TestFolderCaseInLIST()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "ABC.def.GHI";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsFalse(oSimulator.List("ABC.DEF.*").Contains("ABC.def.GHI"));
          Assert.IsTrue(oSimulator.List("ABC.DEF.*").Contains("ABC.DEF.GHI"));
          Assert.IsFalse(oSimulator.List("ABC.def.*").Contains("ABC.DEF"));
          Assert.IsTrue(oSimulator.List("ABC.def.*").Contains("ABC.def.GHI"));
          Assert.IsTrue(oSimulator.SelectFolder(folderName));
          oSimulator.Disconnect();
      }

      [Test]
      public void TestFolderCaseInLSUB()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "ABC.def.GHI";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsTrue(oSimulator.Subscribe(folderName));
          Assert.IsFalse(oSimulator.LSUB("ABC.DEF.*").Contains("ABC.def.GHI"));
          Assert.IsTrue(oSimulator.LSUB("ABC.DEF.*").Contains("ABC.DEF.GHI"));
          Assert.IsFalse(oSimulator.LSUB("ABC.def.*").Contains("ABC.DEF"));
          Assert.IsTrue(oSimulator.LSUB("ABC.def.*").Contains("ABC.def.GHI"));
          Assert.IsTrue(oSimulator.SelectFolder(folderName));
          oSimulator.Disconnect();
      }

       /// <summary>
       ///  Tests that the LSUB resposne doesn't contain an empty line if a folder is not subscribed to.
       /// </summary>
      [Test]
      public void TestFolderLSUBUnsubscribedFolder()
      {

          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "ABC.def.GHI";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsFalse(oSimulator.LSUB().Contains("\r\n\r\n"));
          oSimulator.Disconnect();
      }

      /// <summary>
      ///  Tests that a folder which is not subscribed to isn't included and vice versa.
      /// </summary>
      [Test]
      public void TestLsubInclusion()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "Folder1";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsFalse(oSimulator.LSUB().Contains(folderName));
          Assert.IsTrue(oSimulator.Subscribe(folderName));
          Assert.IsTrue(oSimulator.LSUB().Contains(folderName));

          oSimulator.Disconnect();
      }


        /// <summary>
        /// Test that folder names in the LSUB response are put in quotes.
        /// This is how gmail acts, and Thunderbird crashes if a folder name
        /// is * without quotes.
        /// </summary>
      [Test]
      public void TestFolderQuote()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          string folderName = "Test*";

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder(folderName));
          Assert.IsTrue(oSimulator.Subscribe(folderName));
          Assert.IsTrue(oSimulator.LSUB().Contains("\"" + folderName + "\""));
          oSimulator.Disconnect();
      }

      [Test]
      [Description("Test renaming sub folder to a new sub folder where the new parent does not exist.")]
      public void TestRenameToParallelFolder()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "folder1@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.LogonWithLiteral(oAccount.Address, "test");
          Assert.IsTrue(oSimulator.CreateFolder("Main.Sub"));
          Assert.IsTrue(oSimulator.RenameFolder("Main.Sub", "Second.Sub"));

          string listResponse = oSimulator.List();
          Assert.IsFalse(listResponse.Contains("Main.Sub"));
          Assert.IsTrue(listResponse.Contains("Second.Sub"));
          

          oSimulator.Disconnect();
      }


      [Test]
      [Description("Test that the namespace is included in an empty list response.")]
      public void TestListSpecial()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          string response = oSimulator.List("");
          Assert.IsTrue(response.StartsWith("* LIST (/Noselect) \".\" \"\""));
          oSimulator.Disconnect();

          _settings.IMAPHierarchyDelimiter = "/";

          oSimulator = new IMAPSimulator();
          sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          response = oSimulator.List("");
          Assert.IsTrue(response.StartsWith("* LIST (/Noselect) \"/\" \"\""));
          oSimulator.Disconnect();

          _settings.IMAPHierarchyDelimiter = "\\";

          oSimulator = new IMAPSimulator();
          sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(oAccount.Address, "test");
          response = oSimulator.List("", false);
          string expectedResponse = "* LIST (/Noselect) \"\\\\\" \"\"";
          Assert.IsTrue(response.StartsWith(expectedResponse));
          oSimulator.Disconnect();

      }

      [Test]
      [Description("Test to include reference in LIST command (issue 163).")]
      public void TestListWithReference()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();
          oSimulator.ConnectAndLogon(oAccount.Address, "test");
          oSimulator.CreateFolder("Main.Sub1.Sub2.Sub3");
          oSimulator.CreateFolder("SomeOtherFolder");

          oSimulator.Subscribe("Main");
          oSimulator.Subscribe("Main.Sub1");
          oSimulator.Subscribe("Main.Sub1.Sub2");
          oSimulator.Subscribe("Main.Sub1.Sub2.Sub3");
          oSimulator.Subscribe("SomeOtherFolder");

          string response = oSimulator.List("Main", "*", true);
          Assert.IsFalse(response.Contains("INBOX"));
          Assert.IsFalse(response.Contains("SomeOtherFolder"));
          Assert.IsTrue(response.Contains("* LIST (\\HasChildren) \".\" \"Main.Sub1\""));
          Assert.IsTrue(response.Contains("* LIST (\\HasChildren) \".\" \"Main.Sub1.Sub2\""));
          Assert.IsTrue(response.Contains("* LIST (\\HasNoChildren) \".\" \"Main.Sub1.Sub2.Sub3\""));

          response = oSimulator.List("Main.Sub1", "*", true);
          Assert.IsFalse(response.Contains("INBOX"));
          Assert.IsFalse(response.Contains("SomeOtherFolder"));
          Assert.IsTrue(response.Contains("* LIST (\\HasChildren) \".\" \"Main.Sub1.Sub2\""));
          Assert.IsTrue(response.Contains("* LIST (\\HasNoChildren) \".\" \"Main.Sub1.Sub2.Sub3\""));

          response = oSimulator.LSUB("Main", "*");
          Assert.IsFalse(response.Contains("INBOX"));
          Assert.IsFalse(response.Contains("SomeOtherFolder"));
          Assert.IsTrue(response.Contains("* LSUB (\\HasChildren) \".\" \"Main.Sub1\""));
          Assert.IsTrue(response.Contains("* LSUB (\\HasChildren) \".\" \"Main.Sub1.Sub2\""));
          Assert.IsTrue(response.Contains("* LSUB (\\HasNoChildren) \".\" \"Main.Sub1.Sub2.Sub3\""));

          response = oSimulator.LSUB("Main.Sub1", "*");
          Assert.IsFalse(response.Contains("INBOX"));
          Assert.IsFalse(response.Contains("SomeOtherFolder"));
          Assert.IsTrue(response.Contains("* LSUB (\\HasChildren) \".\" \"Main.Sub1.Sub2\""));
          Assert.IsTrue(response.Contains("* LSUB (\\HasNoChildren) \".\" \"Main.Sub1.Sub2.Sub3\""));
          
          oSimulator.Disconnect();
      }

      [Test]
      [Description("Test to include reference in LIST command (test case from issue 165).")]
      public void TestListWithReferenceTestCase2()
      {
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();
          oSimulator.ConnectAndLogon(oAccount.Address, "test");
          oSimulator.CreateFolder("INBOX.MyApp.SubFolder1");
          oSimulator.CreateFolder("INBOX.MyApp.SubFolder2");
          oSimulator.CreateFolder("INBOX.SomeOtherFolder");


          string response = oSimulator.List("INBOX.MyApp", "%.%", true);
          Assert.IsFalse(response.Contains("\"INBOX.MyApp\""));
          Assert.IsFalse(response.Contains("\"INBOX.SomeOtherFolder\""));
          Assert.IsTrue(response.Contains("* LIST (\\HasNoChildren) \".\" \"INBOX.MyApp.SubFolder1\""));
          Assert.IsTrue(response.Contains("* LIST (\\HasNoChildren) \".\" \"INBOX.MyApp.SubFolder2\""));

          oSimulator.Disconnect();
      }

      [Test]
      public void TestRenameRootPublicFolder()
      {
         hMailServer.IMAPFolders folders = _application.Settings.PublicFolders;
         hMailServer.IMAPFolder folder = folders.Add("ShareA");
         folder.Save();

         hMailServer.IMAPFolderPermission permission = folder.Permissions.Add();
         permission.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeAnyone;
         permission.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission.Save();

         hMailServer.IMAPFolder folder2 = folders.Add("ShareB");
         folder2.Save();

         hMailServer.IMAPFolderPermission permission2 = folder2.Permissions.Add();
         permission2.PermissionType = hMailServer.eACLPermissionType.ePermissionTypeAnyone;
         permission2.set_Permission(hMailServer.eACLPermission.ePermissionLookup, true);
         permission2.set_Permission(hMailServer.eACLPermission.ePermissionRead, true);
         permission2.set_Permission(hMailServer.eACLPermission.ePermissionDeleteMailbox, true);
         permission2.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "shared@test.com", "test");

         IMAPSimulator simulator1 = new IMAPSimulator();
         simulator1.ConnectAndLogon(account.Address, "test");
         Assert.IsTrue(simulator1.SelectFolder("#Public.ShareA"));
         Assert.IsTrue(simulator1.SelectFolder("#Public.ShareB"));
         Assert.IsTrue(simulator1.RenameFolder("#Public.ShareA", "#Public.ShareB.ShareA"));
         Assert.IsFalse(simulator1.SelectFolder("#Public.ShareA"));
         Assert.IsTrue(simulator1.SelectFolder("#Public.ShareB"));
         Assert.IsTrue(simulator1.SelectFolder("#Public.ShareB.ShareA"));

      }
   }
}
