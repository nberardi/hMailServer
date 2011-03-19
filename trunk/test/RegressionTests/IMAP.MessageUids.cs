// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;
using System.IO;
using System.Diagnostics;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class MessageUids : TestFixtureBase
   {
      [Test]
      [Description("Confirm that new messages receive new UIDs")]
      public void TestBasicIncrements()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);

         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];

         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 2);

         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[1].UID);

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 3);

         Assert.AreEqual(3, inboxFolder.CurrentUID);
         Assert.AreEqual(3, inboxFolder.Messages[2].UID);

         
      }

      [Test]
      [Description("Confirm that deletion of messages does not effect UID sequence")]
      public void TestBasicIncrementsWithDeletion()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);

         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];

         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);
         POP3Simulator.AssertGetFirstMessageText(testAccount.Address, "test");

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);

         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[0].UID);
         POP3Simulator.AssertGetFirstMessageText(testAccount.Address, "test");
         

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);

         Assert.AreEqual(3, inboxFolder.CurrentUID);
         Assert.AreEqual(3, inboxFolder.Messages[0].UID);
         


      }

      [Test]
      [Description("Confirm that moving a message to a new folder generates an UID specific to that folder.")]
      public void TestMoveMessageWithAccountLevelRule()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         // First deliver two messages to the inbox.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);
         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];
         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 2);
         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[1].UID);

         CreateMoveRule(testAccount.Rules, "TestFolder");

         // This message will be moved into the test folder.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         
         // Wait for the message to arrive.
         Utilities.AssertFolderExists(testAccount.IMAPFolders, "TestFolder");

         hMailServer.IMAPFolder testFolder = testAccount.IMAPFolders.get_ItemByName("TestFolder");

         // Since the message is placed in a new folder, it should receive a unique UID.
         Utilities.AssertMessageExistsInFolder(testFolder, 1);
         Assert.AreEqual(1, testFolder.CurrentUID);
         Assert.AreEqual(1, testFolder.Messages[0].UID);
     }

      [Test]
      [Description("Confirm that moving a message to a new folder generates an UID specific to that folder.")]
      public void TestMoveMessageWithGlobalRule()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         // First deliver two messages to the inbox.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);
         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];
         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 2);
         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[1].UID);

         CreateMoveRule(_application.Rules, "TestFolder");

         // This message will be moved into the test folder.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");

         // Wait for the message to arrive.
         Utilities.AssertFolderExists(testAccount.IMAPFolders, "TestFolder");

         hMailServer.IMAPFolder testFolder = testAccount.IMAPFolders.get_ItemByName("TestFolder");
         Utilities.AssertMessageExistsInFolder(testFolder, 1);

         // Since the message is placed in a new folder, it should receive a unique UID.
         Assert.AreEqual(1, testFolder.Messages.Count);
         Assert.AreEqual(1, testFolder.CurrentUID);
         Assert.AreEqual(1, testFolder.Messages[0].UID);
      }

      [Test]
      [Description("Issue 267, Invalid message UID generated. " +
                   " Confirm that moving a message to a new folder generates an UID specific to that folder, even if the message is saved using an account rule.")]
      public void TestSaveMessageWithScriptAndMoveMessageWithAccountRule()
      {
         _settings.Scripting.Enabled = true;
         _settings.Scripting.Reload();

         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         IMAPSimulator sim = new IMAPSimulator();
         Assert.IsTrue(sim.ConnectAndLogon(testAccount.Address, "test"));

         // First deliver two messages to the inbox.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);
         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];
         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 2"));

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 2);
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 3"));
         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[1].UID);

         CreateMessageModificationRule(testAccount.Rules);
         CreateMoveRule(testAccount.Rules, "TestFolder");

         // This message will be moved into the test folder.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");

         // Wait for the message to arrive.
         Utilities.AssertFolderExists(testAccount.IMAPFolders, "TestFolder");
         
         hMailServer.IMAPFolder testFolder = testAccount.IMAPFolders.get_ItemByName("TestFolder");
         Utilities.AssertMessageExistsInFolder(testFolder, 1);

         // The UID for the inbox should be the same as before.
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 3"));

         // Since the message is placed in a new folder, it should receive a unique UID.
         Assert.IsTrue(sim.Status("TestFolder", "UIDNEXT").Contains("UIDNEXT 2"));
         Assert.AreEqual(1, testFolder.Messages.Count);
         Assert.AreEqual(1, testFolder.CurrentUID);
         Assert.AreEqual(1, testFolder.Messages[0].UID);
      }

      [Test]
      [Description("Issue 267, Invalid message UID generated. " +
                   " Confirm that moving a message to a new folder generates an UID specific to that folder, even if the message is saved using an account rule.")]
      public void TestSaveMessageWithScriptAndMoveMessageWithGlobalRule()
      {
         _settings.Scripting.Enabled = true;

         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "Test'Account@test.com", "test");

         IMAPSimulator sim = new IMAPSimulator();
         Assert.IsTrue(sim.ConnectAndLogon(testAccount.Address, "test"));

         // First deliver two messages to the inbox.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 1);
         hMailServer.IMAPFolder inboxFolder = testAccount.IMAPFolders[0];
         Assert.AreEqual(1, inboxFolder.CurrentUID);
         Assert.AreEqual(1, inboxFolder.Messages[0].UID);
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 2"));

         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");
         POP3Simulator.AssertMessageCount(testAccount.Address, "test", 2);
         Assert.AreEqual(2, inboxFolder.CurrentUID);
         Assert.AreEqual(2, inboxFolder.Messages[1].UID);
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 3"));

         CreateMessageModificationRule(_application.Rules);
         CreateMoveRule(_application.Rules, "TestFolder");


         // This message will be moved into the test folder.
         SMTPClientSimulator.StaticSend(testAccount.Address, testAccount.Address, "Test", "Test");

         // Wait for the message to arrive.
         Utilities.AssertFolderExists(testAccount.IMAPFolders, "TestFolder");

         // Inbox UID should not have changed since nothing has been added to the inbox.
         Assert.IsTrue(sim.Status("INBOX", "UIDNEXT").Contains("UIDNEXT 3"));

         hMailServer.IMAPFolder testFolder = testAccount.IMAPFolders.get_ItemByName("TestFolder");

         // Since the message is placed in a new folder, it should receive a unique UID.
         Assert.IsTrue(sim.Status("TestFolder", "UIDNEXT").Contains("UIDNEXT 2"));
         Assert.AreEqual(1, testFolder.Messages.Count);
         Assert.AreEqual(1, testFolder.CurrentUID);
         Assert.AreEqual(1, testFolder.Messages[0].UID);
      }

      private void CreateMessageModificationRule(hMailServer.Rules ruleContainer)
      {
         hMailServer.Rule oRule = ruleContainer.Add();
         oRule.Name = "Criteria test";
         oRule.Active = true;

         hMailServer.RuleCriteria oRuleCriteria = oRule.Criterias.Add();
         oRuleCriteria.UsePredefined = true;
         oRuleCriteria.PredefinedField = hMailServer.eRulePredefinedField.eFTMessageSize;
         oRuleCriteria.MatchType = hMailServer.eRuleMatchType.eMTGreaterThan;
         oRuleCriteria.MatchValue = "0";
         oRuleCriteria.Save();

         hMailServer.RuleAction oRuleAction = oRule.Actions.Add();
         oRuleAction.Type = hMailServer.eRuleActionType.eRARunScriptFunction;
         oRuleAction.ScriptFunction = "ModifyMessage";
         oRuleAction.Save();
         
         oRule.Save();

         File.WriteAllText(_settings.Scripting.CurrentScriptFile, "Sub ModifyMessage(oMessage)" + Environment.NewLine +
                                                                     "oMessage.Subject = \"[Spam] \" + CStr(oMessage.Subject)" + Environment.NewLine +
                                                                     "oMessage.Save" + Environment.NewLine +
                                                                  "End Sub");

         _settings.Scripting.Reload();
      }

      private void CreateMoveRule(hMailServer.Rules ruleContainer, string foldername)
      {
         hMailServer.Rule oRule = ruleContainer.Add();
         oRule.Name = "Criteria test";
         oRule.Active = true;

         hMailServer.RuleCriteria oRuleCriteria = oRule.Criterias.Add();
         oRuleCriteria.UsePredefined = true;
         oRuleCriteria.PredefinedField = hMailServer.eRulePredefinedField.eFTMessageSize;
         oRuleCriteria.MatchType = hMailServer.eRuleMatchType.eMTGreaterThan;
         oRuleCriteria.MatchValue = "0";
         oRuleCriteria.Save();

         hMailServer.RuleAction oRuleAction = oRule.Actions.Add();
         oRuleAction.Type = hMailServer.eRuleActionType.eRAMoveToImapFolder;
         oRuleAction.IMAPFolder = foldername;
         oRuleAction.Save();

         oRule.Save();
      }

   }
}
