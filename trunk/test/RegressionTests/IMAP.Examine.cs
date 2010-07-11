using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class Examine : TestFixtureBase
   {
      [Test]
      public void TestExamine()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "examine@test.com", "test");

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon(oAccount.Address, "test");
         Assert.IsTrue(oSimulator.CreateFolder("TestFolder"));
         string result = oSimulator.ExamineFolder("TestFolder");

         Assert.IsTrue(result.Contains("[PERMANENTFLAGS ()]"), result);
         Assert.IsTrue(result.Contains("[READ-ONLY]"), result);
      }

      [Test]
      [Description("Assert that it's not possible to change flags while in READONLY-mode")]
      public void TestChangeFlags()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "examine@test.com", "test");

         Assert.IsTrue(SMTPSimulator.StaticSend("test@test.com", oAccount.Address, "Test", "test"));
         POP3Simulator.AssertMessageCount(oAccount.Address, "test", 1);

         IMAPSimulator simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         simulator.ExamineFolder("Inbox");
         Assert.IsFalse(simulator.SetFlagOnMessage(1, true, @"\Deleted"));
      }

      [Test]
      [Description("Assert that it's not possible to EXPUNGE while in READONLY-mode")]
      public void TestExpunge()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "examine@test.com", "test");

         Assert.IsTrue(SMTPSimulator.StaticSend("test@test.com", oAccount.Address, "Test", "test"));
         POP3Simulator.AssertMessageCount(oAccount.Address, "test", 1);

         IMAPSimulator simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         simulator.SelectFolder("Inbox");
         Assert.IsTrue(simulator.SetFlagOnMessage(1, true, @"\Deleted"));

         IMAPSimulator secondSimulator = new IMAPSimulator();
         secondSimulator.ConnectAndLogon(oAccount.Address, "test");
         string result = secondSimulator.ExamineFolder("INBOX");
         Assert.IsTrue(result.Contains("1 EXISTS"), result);
         Assert.IsFalse(secondSimulator.Expunge());

         simulator.SelectFolder("INBOX");
         Assert.IsTrue(simulator.Expunge());

         simulator.Close();
         secondSimulator.Close();
      }

      [Test]
      [Description("Assert that the \\RECENT flag isn't automatically changed when accessing a folder in READONLY-mode")]
      public void TestChangeRecentFlag()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "examine@test.com", "test");

         Assert.IsTrue(SMTPSimulator.StaticSend("test@test.com", oAccount.Address, "Test", "test"));
         POP3Simulator.AssertMessageCount(oAccount.Address, "test", 1);
         
         IMAPSimulator simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         string result = simulator.ExamineFolder("Inbox");
         Assert.IsTrue(result.Contains("* 1 RECENT"), result);
         simulator.Close();
         simulator.Disconnect();

         simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         Assert.IsTrue(simulator.SelectFolder("Inbox", out result));
         Assert.IsTrue(result.Contains("* 1 RECENT"), result);
         simulator.Close();
         simulator.Disconnect();

         simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         result = simulator.ExamineFolder("Inbox");
         Assert.IsTrue(result.Contains("* 0 RECENT"), result);
         simulator.Close();
         simulator.Disconnect();
      }

      [Test]
      [Description("Assert that the \\SEEN flag isn't automatically changed when accessing a message in READONLY-mode")]
      public void TestChangeSeenFlag()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "examine@test.com", "test");

         Assert.IsTrue(SMTPSimulator.StaticSend("test@test.com", oAccount.Address, "Test", "test"));
         POP3Simulator.AssertMessageCount(oAccount.Address, "test", 1);

         IMAPSimulator simulator = new IMAPSimulator();
         simulator.ConnectAndLogon(oAccount.Address, "test");
         simulator.ExamineFolder("Inbox");
         string flags = simulator.GetFlags(1);
         string body = simulator.Fetch("1 RFC822");
         string flagsAfter = simulator.GetFlags(1);
         simulator.Close();
         simulator.Disconnect();

         Assert.AreEqual(flags, flagsAfter);

         IMAPSimulator secondSimulator = new IMAPSimulator();
         secondSimulator.ConnectAndLogon(oAccount.Address, "test");
         secondSimulator.SelectFolder("Inbox");
         string secondFlags = secondSimulator.GetFlags(1);
         string secondBody = secondSimulator.Fetch("1 RFC822");
         string secondFlagsAfter = secondSimulator.GetFlags(1);
         secondSimulator.Close();
         secondSimulator.Disconnect();

         Assert.AreNotEqual(secondFlags, secondFlagsAfter);
      }

   }
}
