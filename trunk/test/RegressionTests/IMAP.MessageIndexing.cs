// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class MessageIndexing : TestFixtureBase
	{
      hMailServer.MessageIndexing _indexing;

      [SetUp]
      public new void SetUp()
      {
         _application.Settings.IMAPSortEnabled = true;
         _indexing = _application.Settings.MessageIndexing;
      }

      [Test]
      [Description("Test message metadata subject")]
      public void TestMetaDataSortSubjectAnsi()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test 1", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         SendMessage("Test 2", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(SUBJECT) UTF-8 ALL");
         
         Assert.IsTrue(result.StartsWith("1 2"));

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }


      [Test]
      [Description("Test message metadata subject")]
      public void TestMetaDataSortSubjectSwedish()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test Ä", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         SendMessage("Test Ö", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

         SendMessage("Test Å", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual("3 1 2", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      [Test]
      [Description("Test message metadata subject")]
      public void TestMetaDataSortSubjectGreek()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test Σ", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);
         // pos: 18

         SendMessage("Test Α", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);
         // pos: 1

         SendMessage("Test Δ", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);
         // pos: 4

         SendMessage("Test β", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 4);
         // pos: 2

         SendMessage("Test κ", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 5);
         // pos: 10

         SendMessage("Test Ψ", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 6);
         // pos: 23

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual("2 4 3 5 1 6", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      [Test]
      [Description("Test message metadata subject")]
      public void TestMetaDataSortSubjectTurkish()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test Ç", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);
         // pos: 4

         SendMessage("Test C", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);
         // pos: 3

         SendMessage("Test B", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);
         // pos: 2

         SendMessage("Test Ğ", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 4);
         // pos: 9

         SendMessage("Test G", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 5);
         // pos: 8

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual("3 2 1 5 4", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      [Test]
      [Description("Test message metadata date")]
      public void TestMetaDataSortDate()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test A", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         SendMessage("Test B", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

         SendMessage("Test C", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);

         SendMessage("Test D", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 4);

         SendMessage("Test E", "Body", "", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 5);

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(DATE) UTF-8 ALL");

         Assert.AreEqual("1 2 3 4 5", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(SUBJECT) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      [Test]
      [Description("Test message metadata date")]
      public void TestMetaDataSortTo()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test A", "Body", "ÅÅÅ", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         SendMessage("Test B", "Body", "ÖÖÖ", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

         SendMessage("Test C", "Body", "ÄÄÄ", "");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(TO) UTF-8 ALL");

         Assert.AreEqual("1 3 2", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(TO) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      [Test]
      [Description("Test message metadata date")]
      public void TestMetaDataSortCC()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "meta'data@test.com", "test");

         // disable...
         SendMessage("Test C", "Body", "", "ÄÄÄ");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         SendMessage("Test B", "Body", "", "ÖÖÖ");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

         SendMessage("Test A", "Body", "", "ÅÅÅ");
         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);

         AssertAllMessagesIndexed();

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");

         string result = sim.Sort("(CC) UTF-8 ALL");

         Assert.AreEqual("3 1 2", result);

         // Disable the indexing functionality
         _indexing.Enabled = false;
         _indexing.Clear();

         // Make sure the sort order is the same.
         string resultAfter = sim.Sort("(CC) UTF-8 ALL");

         Assert.AreEqual(result, resultAfter);
      }

      private void AssertAllMessagesIndexed()
      {
         if (_indexing.Enabled == false)
            _indexing.Enabled = true;

         _indexing.Index();

         for (int i = 0; i < 1000; i++)
         {
            if (_indexing.TotalIndexedCount == _indexing.TotalMessageCount)
               return;

            Thread.Sleep(20);
         }

         Assert.Fail("Messages not indexed...");
      }

      private void SendMessage(string subject, string body, string to, string cc)
      {
         hMailServer.Message message = new hMailServer.Message();

         message.Charset = "UTF-8";
         message.AddRecipient("test", "meta'data@test.com");
         message.From = "Test";
         message.FromAddress = "meta'data@test.com";
         message.Subject = subject;
         message.set_HeaderValue("To", to);
         message.set_HeaderValue("cc", cc);
         message.Body = body;
         message.Save();
      }
	}
}
