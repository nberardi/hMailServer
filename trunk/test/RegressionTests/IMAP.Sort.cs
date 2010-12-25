// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class Sort : TestFixtureBase
   {

      [SetUp]
      public new void SetUp()
      {
         _application.Settings.IMAPSortEnabled = true;
      }

      [Test]
      public void TestSortSubject()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1 2", oSimulator.Sort("(SUBJECT) UTF-8 ALL"));
      }

      [Test]
      public void TestSortSubjectReverse()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("2 1", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL"));
      }


      [Test]
      public void TestSubjectSearch()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL HEADER SUBJECT \"Test1\""));
         Assert.AreEqual("2", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL HEADER SUBJECT \"Test2\""));
         Assert.AreEqual("1", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL (HEADER SUBJECT \"Test1\")"));
         Assert.AreEqual("2", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL (HEADER SUBJECT \"Test2\")"));
      }


      [Test]
      public void TestSubjectSearchMultipleMatches()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "TestA", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 3);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1 3", oSimulator.Sort("(SUBJECT) UTF-8 ALL HEADER SUBJECT \"Test1\""));
         Assert.AreEqual("2", oSimulator.Sort("(SUBJECT) UTF-8 ALL HEADER SUBJECT \"TestA\""));
         Assert.AreEqual("3 1", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL HEADER SUBJECT \"Test1\""));
         Assert.AreEqual("2", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL HEADER SUBJECT \"TestA\""));
         Assert.AreEqual("3 1", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL (HEADER SUBJECT) \"Test1\""));
         Assert.AreEqual("2", oSimulator.Sort("(REVERSE SUBJECT) UTF-8 ALL (HEADER SUBJECT) \"TestA\""));
      }

      [Test]
      public void TestSubjectSearchValueWithParanthesis()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Te(st1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "Te)st2", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1", oSimulator.Sort("(SUBJECT) UTF-8 ALL HEADER SUBJECT \"Te(st1\""));
         Assert.AreEqual("2", oSimulator.Sort("(SUBJECT) UTF-8 ALL HEADER SUBJECT \"Te)st2\""));
      }

      [Test]
      public void TestSortSubjectSearch()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "aa", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "bb", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();
         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1 2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR HEADER SUBJECT aa HEADER SUBJECT bb"));
         Assert.AreEqual("1 2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR (HEADER SUBJECT aa) (HEADER SUBJECT bb)"));
         Assert.AreEqual("1 2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED (OR HEADER SUBJECT aa HEADER SUBJECT bb)"));

         Assert.AreEqual("1", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR HEADER SUBJECT aa HEADER SUBJECT cc"));
         Assert.AreEqual("1", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR (HEADER SUBJECT aa) (HEADER SUBJECT cc)"));
         Assert.AreEqual("1", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED (OR HEADER SUBJECT aa HEADER SUBJECT cc)"));

         Assert.AreEqual("2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR HEADER SUBJECT bb HEADER SUBJECT cc"));
         Assert.AreEqual("2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED OR (HEADER SUBJECT bb) (HEADER SUBJECT cc)"));
         Assert.AreEqual("2", oSimulator.Sort("(DATE) UTF-8 ALL UNANSWERED (OR HEADER SUBJECT bb HEADER SUBJECT cc)"));


      }

      [Test]
      public void TestSortDeletedOrAnswered()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "aa", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
         oSMTP.Send("search@test.com", "search@test.com", "bb", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();
         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("", oSimulator.Sort("(DATE) UTF-8 ALL OR ANSWERED DELETED"));
      }


      [Test]
      [Description("Issue 168 - IMAP: Search for message with specific UID fails. ")]
      public void TestSearchSpecficUID()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         for (int i = 0; i < 5; i++)
            oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");

         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 5);

         hMailServer.Messages messages = oAccount.IMAPFolders.get_ItemByName("Inbox").Messages;

         int second = messages[1].UID;
         int third = messages[2].UID;
         int fourth = messages[3].UID;


         IMAPSimulator oSimulator = new IMAPSimulator();
         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.SendSingleCommand(string.Format("a01 SORT (REVERSE DATE) UTF-8 ALL UID {0},{1}", second, third));
         Assert.IsTrue(result.StartsWith("* SORT 3 2"));

         result = oSimulator.SendSingleCommand(string.Format("a01 SORT (DATE) UTF-8 ALL UID {0},{1}", third, second));
         Assert.IsTrue(result.StartsWith("* SORT 2 3"));

         result = oSimulator.SendSingleCommand(string.Format("a01 SORT (DATE) UTF-8 ALL UID {0}:{1}", second, fourth));
         Assert.IsTrue(result.StartsWith("* SORT 2 3 4"));

         result = oSimulator.SendSingleCommand(string.Format("a01 SORT (DATE) UTF-8 ALL UID {0}:*", second));
         Assert.IsTrue(result.StartsWith("* SORT 2 3 4 5"));
      }

      [Test]
      public void TestSortReverseArrival()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);

         // The two messages needs to be sent a second apart, so we actually need to pause a bit here.

         System.Threading.Thread.Sleep(1000);
         oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("1 2", oSimulator.Sort("(ARRIVAL) UTF-8 ALL"));
         Assert.AreEqual("2 1", oSimulator.Sort("(REVERSE ARRIVAL) UTF-8 ALL"));
      }

      [Test]
      public void TestSortReverseSize()
      {
         hMailServer.Domain oDomain = _application.Domains[0];
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         StringBuilder longBodyString = new StringBuilder();
         longBodyString.Append('A', 10000);

         // Send a message to this account.
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Test1", longBodyString.ToString());
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);

         oSMTP.Send("search@test.com", "search@test.com", "Test2", "Test body");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         Assert.AreEqual("2 1", oSimulator.Sort("(SIZE) UTF-8 ALL"));
         Assert.AreEqual("1 2", oSimulator.Sort("(REVERSE SIZE) UTF-8 ALL"));
      }

      [Test]
      [Description("Issue 340, Incorrect date sorting order")]
      public void TestDateSortOrder()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "imapsort@test.com", "test");
         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral("imapsort@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("Inbox"));

         string response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 22:00:00 +0200\" {37}", "Date: Wed, 15 Dec 2010 13:00:00 +0000");
         Assert.IsTrue(response.Contains("* 1 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 21:00:00 +0200\" {37}", "Date: Wed, 15 Dec 2010 14:00:00 +0000");
         Assert.IsTrue(response.Contains("* 2 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 20:00:00 +0200\" {37}", "Date: Wed, 15 Dec 2010 12:00:00 +0000");
         Assert.IsTrue(response.Contains("* 3 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"23-Feb-2008 01:30:23 +0200\" {37}", "Date: Wed, 15 Dec 2010 11:00:00 +0000");
         Assert.IsTrue(response.Contains("* 4 EXISTS"), response);

         string sortDateResponse = oSimulator.SendSingleCommand("A10 SORT (DATE) US-ASCII ALL");

         Assert.IsTrue(sortDateResponse.Contains(" 4 3 1 2"));
         oSimulator.Disconnect();
      }

      [Test]
      [Description("Issue 340, Incorrect date sorting order")]
      public void TestDateSortOrderNonexistantDate()
      {
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "imapsort@test.com", "test");
         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.LogonWithLiteral("imapsort@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("Inbox"));

         string response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 22:00:00 +0200\" {4}", "ABCD");
         Assert.IsTrue(response.Contains("* 1 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 21:00:00 +0200\" {4}", "ABCD");
         Assert.IsTrue(response.Contains("* 2 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"22-Feb-2008 20:00:00 +0200\" {4}", "ABCD");
         Assert.IsTrue(response.Contains("* 3 EXISTS"), response);

         response = oSimulator.SendSingleCommandWithLiteral("A04 APPEND INBOX \"23-Feb-2008 01:30:23 +0200\" {4}", "ABCD");
         Assert.IsTrue(response.Contains("* 4 EXISTS"), response);

         /*
          * RFC 5256 "2.2. Sent Date" chapter. If the sent date cannot be determined (a Date: header is missing or cannot be parsed), 
          * the INTERNALDATE for that message is used as the sent date.
          */

         string sortDateResponse = oSimulator.SendSingleCommand("A10 SORT (DATE) US-ASCII ALL");
         string sortArivalDateResponse = oSimulator.SendSingleCommand("A10 SORT (ARRIVAL) US-ASCII ALL");

         Assert.IsTrue(sortArivalDateResponse.Contains(" 3 2 1 4"));
         Assert.AreEqual(sortDateResponse, sortArivalDateResponse);
         oSimulator.Disconnect();
      }
   }
}
