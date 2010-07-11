// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
    [TestFixture]
    public class HierarchyDelimiter : TestFixtureBase
    {
        [Test]
        [Description("Test that the hierchary delimiter has effect on the Create command.")]
        public void TestHierarchyDelimiterCreate()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "/";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test.Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            string listResponse = oSimulator.List();
            Assert.IsTrue(listResponse.Contains("\"" + folderName + "\""));
            Assert.IsTrue(!listResponse.Contains("\"Test\""));
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the Rename command.")]
        public void TestHierarchyDelimiterRename()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "/";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test/Test";
            string newFolderName = "Apa/Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            string listResponse = oSimulator.List();
            Assert.IsTrue(listResponse.Contains("\"" + folderName + "\""));
            Assert.IsTrue(listResponse.Contains("\"Test\""));
            Assert.IsTrue(oSimulator.RenameFolder("Test", "Apa"));
            listResponse = oSimulator.List();
            Assert.IsTrue(listResponse.Contains("\"" + newFolderName + "\""));
            Assert.IsTrue(listResponse.Contains("\"Apa\""));
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the Delete command.")]
        public void TestHierarchyDelimiterDelete()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "\\";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test\\Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            string listResponse = oSimulator.List();
            Assert.IsTrue(listResponse.Contains("\"Test\\Test\""));
            Assert.IsTrue(listResponse.Contains("\"Test\""));
            Assert.IsTrue(oSimulator.DeleteFolder("Test\\Test"));
            listResponse = oSimulator.List();
            Assert.IsFalse(listResponse.Contains("Test\\Test"));
            Assert.IsTrue(listResponse.Contains("Test"));
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the Namespace response.")]
        public void TestHierarchyDelimiterNamespaceResponse()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "\\";
            string publicFolderName = _settings.IMAPPublicFolderName;

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            IMAPSimulator oSimulator = new IMAPSimulator();
            oSimulator.ConnectAndLogon(account.Address, "test");
            string result = oSimulator.Send("A01 NAMESPACE");
            string correctNamespaceSetting = "* NAMESPACE ((\"\" \"\\\\\")) NIL ((\"" + publicFolderName + "\" \"\\\\\"))";
            Assert.IsTrue(result.Contains(correctNamespaceSetting), result);
            oSimulator.Disconnect();

            settings.IMAPHierarchyDelimiter = ".";

            oSimulator = new IMAPSimulator();
            oSimulator.ConnectAndLogon(account.Address, "test");
            
            result = oSimulator.Send("A01 NAMESPACE");
            correctNamespaceSetting = "* NAMESPACE ((\"\" \".\")) NIL ((\"" + publicFolderName + "\" \".\"))";
            Assert.IsTrue(result.Contains(correctNamespaceSetting), result);
            oSimulator.Disconnect();

            settings.IMAPHierarchyDelimiter = "/";

            oSimulator = new IMAPSimulator();
            oSimulator.ConnectAndLogon(account.Address, "test");

            result = oSimulator.Send("A01 NAMESPACE");
            correctNamespaceSetting = "* NAMESPACE ((\"\" \"/\")) NIL ((\"" + publicFolderName + "\" \"/\"))";
            Assert.IsTrue(result.Contains(correctNamespaceSetting), result);
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the List response.")]
        public void TestHierarchyDelimiterListResponse()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "\\";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test\\Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            string listResponse = oSimulator.List();
            Assert.IsTrue(listResponse.Contains("\"Test\\Test\""));
            Assert.IsTrue(listResponse.Contains("\"Test\""));
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the LSUB response.")]
        public void TestHierarchyDelimiterLsubResponse()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "/";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test/Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            Assert.IsTrue(oSimulator.Subscribe("Test"));
            Assert.IsTrue(oSimulator.Subscribe("Test/Test"));
            string lsubResponse = oSimulator.LSUB();
            Assert.IsTrue(lsubResponse.Contains("\"Test/Test\""));
            Assert.IsTrue(lsubResponse.Contains("\"Test\""));
            oSimulator.Disconnect();
        }

        [Test]
        [Description("Test that the hierchary delimiter has effect on the LSUB response.")]
        public void TestHierarchyDelimiterSlash()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.Settings settings = _settings;
            settings.IMAPHierarchyDelimiter = "\\";

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "quote@test.com", "test");

            string folderName = "Test\\Test";

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            Assert.IsTrue(oSimulator.CreateFolder(folderName));
            Assert.IsTrue(oSimulator.Subscribe("Test"));
            Assert.IsTrue(oSimulator.Subscribe("Test\\Test"));
            string lsubResponse = oSimulator.LSUB();
            Assert.IsTrue(lsubResponse.Contains("\"Test\\Test\""));
            Assert.IsTrue(lsubResponse.Contains("\"Test\""));
            oSimulator.Disconnect();
        }
    }
}
