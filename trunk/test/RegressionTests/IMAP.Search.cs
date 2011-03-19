// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Protocols.IMAP
{
   [TestFixture]
   public class Search : TestFixtureBase
   {
      [Test]
      public void TestSearch()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "se'arch@test.com", "test");

         // Send a message to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Send(oAccount.Address, oAccount.Address, "Search test", "This is a test of IMAP Search");

         IMAPSimulator.AssertMessageCount(oAccount.Address, "test", "INBOX", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon(oAccount.Address, "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         oSimulator.SetFlagOnFirstMessage(true, "\\ANSWERED");
         if (oSimulator.Search("ANSWERED") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\ANSWERED");
         if (oSimulator.Search("ANSWERED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\DELETED");
         if (oSimulator.Search("DELETED") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\DELETED");
         if (oSimulator.Search("DELETED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\DRAFT");
         if (oSimulator.Search("DRAFT") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\DRAFT");
         if (oSimulator.Search("DRAFT") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\FLAGGED");
         if (oSimulator.Search("FLAGGED  ") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\FLAGGED");
         if (oSimulator.Search("FLAGGED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\SEEN");
         if (oSimulator.Search("SEEN") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\SEEN");
         if (oSimulator.Search("SEEN") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\ANSWERED");
         if (oSimulator.Search("UNANSWERED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\ANSWERED");
         if (oSimulator.Search("UNANSWERED") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\DELETED");
         if (oSimulator.Search("UNDELETED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\DELETED");
         if (oSimulator.Search("UNDELETED") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\DRAFT");
         if (oSimulator.Search("UNDRAFT") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\DRAFT");
         if (oSimulator.Search("UNDRAFT") != "1")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(true, "\\FLAGGED");
         if (oSimulator.Search("UNFLAGGED") != "")
            throw new Exception("ERROR - Search or flag failed");

         oSimulator.SetFlagOnFirstMessage(false, "\\FLAGGED");
         if (oSimulator.Search("UNFLAGGED") != "1")
            throw new Exception("ERROR - Search or flag failed");

         // SEARCH using LARGER & SMALLER
         if (oSimulator.Search("SMALLER 10") != "")
            throw new Exception("ERROR - Search or flag failed");

         if (oSimulator.Search("SMALLER 10000") != "1")
            throw new Exception("ERROR - Search or flag failed");

         if (oSimulator.Search("LARGER 10") != "1")
            throw new Exception("ERROR - Search or flag failed");

         if (oSimulator.Search("LARGER 10000") != "")
            throw new Exception("ERROR - Search or flag failed");


      }

      [Test]
      public void TestSearchON()
      {

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string formattedTomorrow = (DateTime.Now + new TimeSpan(1,0,0,0)).ToString("dd-MMM-yyyy", System.Globalization.CultureInfo.InvariantCulture).ToUpper();
         string formattedToday = DateTime.Now.ToString("dd-MMM-yyyy", System.Globalization.CultureInfo.InvariantCulture).ToUpper();

         if (oSimulator.Search("ON " + formattedTomorrow) != "")
         {
            throw new Exception("ERROR - Search or flag failed");
         }

         if (oSimulator.Search("ON " + formattedToday) != "1")
         {
            throw new Exception("ERROR - Search or flag failed");
         }
      }


      [Test]
      public void TestSearchOR()
      {

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");
         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();

         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         if (oSimulator.Search("OR SINCE 28-May-2001 ON 28-May-2001 ALL") != "1")
         {
            throw new Exception("ERROR - Search or flag failed");
         }

         if (oSimulator.Search("OR SINCE 28-May-2012 ON 28-May-2012 ALL") != "")
         {
            throw new Exception("ERROR - Search or flag failed");
         }

         string formattedToday = DateTime.Now.ToString("dd-MMM-yyyy", System.Globalization.CultureInfo.InvariantCulture).ToUpper();
         if (oSimulator.Search("OR SINCE 28-May-2017 ON " + formattedToday + " ALL") != "1")
         {
            throw new Exception("ERROR - Search or flag failed");
         }

         string formatted2001 = new DateTime(2001,01,01).ToString("dd-MMM-yyyy").ToUpper();
         if (oSimulator.Search("OR SINCE 28-May-2008 ON " + formatted2001 + " ALL") != "1")
         {
            throw new Exception("ERROR - Search or flag failed");
         }
      }

      [Test]
      public void TestSearchORWithParenthesis()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          if (oSimulator.Search("OR (SINCE 28-May-2001) (ON 28-May-2001) ALL") != "1 2")
          {
              throw new Exception("ERROR - Search or flag failed");
          }
      }


      [Test]
      public void TestNestedOr()
      {

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");

         IMAPSimulator.AssertMessageCount(oAccount.Address, "test", "Inbox",1);

         IMAPSimulator oSimulator = new IMAPSimulator();
         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         oSimulator.SelectFolder("INBOX");


         string result = oSimulator.SendSingleCommand("A4 SEARCH OR OR OR OR OR OR SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 ALL");
         Assert.IsTrue(result.StartsWith("* SEARCH"), result);

         result = oSimulator.SendSingleCommand("A4 SEARCH OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR OR SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008 ALL");
         Assert.IsTrue(result.StartsWith("A4 NO"), result);
      }

      [Test]
      public void TestSearchORWithParenthesisSubject()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          if (oSimulator.Search("OR (SUBJECT \"Test1\") (ON 28-May-2001) ALL") != "1")
          {
              throw new Exception("ERROR - Search or flag failed");
          }

          if (oSimulator.Search("OR (SUBJECT \"Test2\") (ON 28-May-2001) ALL") != "2")
          {
              throw new Exception("ERROR - Search or flag failed");
          }
      }

      [Test]
      public void TestSearchWithLiterals()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          
          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          string result = oSimulator.SendSingleCommandWithLiteral("A01 SEARCH HEADER SUBJECT {5}", "Test1");
          Assert.IsTrue(result.StartsWith("* SEARCH 1\r\n"));

          result = oSimulator.SendSingleCommandWithLiteral("A01 SEARCH HEADER SUBJECT {5}", "Test2");
          Assert.IsTrue(result.StartsWith("* SEARCH 2\r\n"));
      }

      [Test]
      public void TestSearchORWithLiterals()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");

          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          string result = oSimulator.Send("A01 SEARCH ALL OR (HEADER SUBJECT {5}" );
          result = oSimulator.Send("Test1) (HEADER SUBJECT {5}");
          result = oSimulator.Send("Test2)");
          Assert.IsTrue(result.StartsWith("* SEARCH 1 2"));
      }

      [Test]
      public void TestSearchORWithLiterals2()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");

          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          string result = oSimulator.Send("A01 SEARCH ALL OR (HEADER SUBJECT {5}");
          result = oSimulator.Send("Test1) (HEADER SUBJECT {5}");
          result = oSimulator.Send("Test5)");
          Assert.IsTrue(result.StartsWith("* SEARCH 1"));
      }

      [Test]
      public void TestSearchORWithLiterals3()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");

          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          string result = oSimulator.Send("A01 SEARCH ALL OR (HEADER SUBJECT {5}");
          result = oSimulator.Send("Test5) (HEADER SUBJECT {5}");
          result = oSimulator.Send("Test2)");
          Assert.IsTrue(result.StartsWith("* SEARCH 2"));
      }

      [Test]
      public void TestSearchORWithParenthesisSubjectNested()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 1);
          oSMTP.Send("search@test.com", "search@test.com", "Test2", "This is a test of IMAP Search");
          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 2);

          IMAPSimulator oSimulator = new IMAPSimulator();

          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          if (oSimulator.Search("ALL (OR (HEADER SUBJECT \"Test1\") (HEADER SUBJECT \"Test2\"))") != "1 2")
          {
              throw new Exception("ERROR - Search or flag failed");
          }
      }

      [Test]
      public void TestNestedOrSearch()
      {

          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("search@test.com", "search@test.com", "Search test", "This is a test of IMAP Search");

          IMAPSimulator.AssertMessageCount(oAccount.Address, "test", "Inbox", 1);

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          oSimulator.SelectFolder("INBOX");

          string result = oSimulator.SendSingleCommand("A4 SEARCH ALL OR OR SINCE 28-May-2008 SINCE 28-May-2008 SINCE 28-May-2008");
          Assert.IsTrue(result.StartsWith("* SEARCH 1"), result);

          result = oSimulator.SendSingleCommand("A4 SEARCH ALL OR SMALLER 1 LARGER 10000");
          Assert.IsTrue(result.StartsWith("* SEARCH\r\n"), result);

          result = oSimulator.SendSingleCommand("A4 SEARCH ALL OR OR SMALLER 1 LARGER 10000 SMALLER 10000");
          Assert.IsTrue(result.StartsWith("* SEARCH 1\r\n"), result);      
      }

      [Test]
      [Description("Issue 167 - IMAP: Search for message in range fails.")]
      public void TestSearchRange()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

          ;
          hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

          // Send a message to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          for (int i = 0; i <5 ; i++)
            oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");

          IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 5);

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon("search@test.com", "test");
          Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

          string result = oSimulator.SendSingleCommand("a01 search 2:4");
          Assert.IsTrue(result.StartsWith("* SEARCH 2 3 4"));

          result = oSimulator.SendSingleCommand("a01 search 3,2");
          Assert.IsTrue(result.StartsWith("* SEARCH 2 3"));

          result = oSimulator.SendSingleCommand("a01 search 3:*");
          Assert.IsTrue(result.StartsWith("* SEARCH 3 4 5"));

          result = oSimulator.SendSingleCommand("a01 search 3,1,3");
          Assert.IsTrue(result.StartsWith("* SEARCH 1 3"));

          result = oSimulator.SendSingleCommand("a01 search 1:*");
          Assert.IsTrue(result.StartsWith("* SEARCH 1 2 3 4 5"));
      }

      [Test]
      [Description("Test that searching for message UID's works.")]
      public void TestSearchUID()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         ;
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         // Send a message to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();
         for (int i = 0; i < 3; i++)
            oSMTP.Send("search@test.com", "search@test.com", "Test1", "This is a test of IMAP Search");

         IMAPSimulator.AssertMessageCount("search@test.com", "test", "INBOX", 3);

         // There should be 3 UID's, 1,2,3 or similar. No skips in the middle fo them.
         IMAPSimulator oSimulator = new IMAPSimulator();
         string sWelcomeMessage = oSimulator.Connect();
         oSimulator.Logon("search@test.com", "test");
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.SendSingleCommand("* UID SEARCH UID 1:*");

         // Potentially, the response is multiline. (UID RESPONSE and an OK line). We only want the first line...
         result = result.Substring(0, result.IndexOf("\r\n"));

         string [] tokens = Microsoft.VisualBasic.Strings.Split(result, " ", -1, Microsoft.VisualBasic.CompareMethod.Text);

         List<int> uids = new List<int>();
         foreach (string token in tokens)
         {
            int temp;
            if (Int32.TryParse(token, out temp))
            {
               uids.Add(temp);
            }
         }

         Assert.AreEqual(3, uids.Count, result);

         Assert.AreEqual(1, uids[0]);
         Assert.AreEqual(2, uids[1]);
         Assert.AreEqual(3, uids[2]);
      }

      [Test]
      public void TestSearchUTF8()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         string body = Utilities.GetResource("Messages.MessageContainingGreekAndJapanese.txt");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address, body);

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();
         Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.Search("CHARSET UTF-8 ALL TEXT GRΣΣK");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT ÅÄÖ");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT 標準語標準語");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT ßEßEß");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT ÅÅÅ");
         Assert.AreEqual("", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT GREEK");
         Assert.AreEqual("", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT ßEEEß");
         Assert.AreEqual("", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT 標準語標語語");
         Assert.AreEqual("", result);
      }

      [Test]
      [Description("Tests the ALL TEXT search command. TEXT should match both header and body")]
      public void TestSearchUTF8TEXT()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");
         string body = Utilities.GetResource("Messages.MessageContainingGreekSubject.txt");
         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address, body);

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();
         Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.Search("CHARSET UTF-8 ALL TEXT GRΣΣK");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT 標準語");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT GRΣΣK標準語");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET UTF-8 ALL TEXT GRΣΣKWHAT標準語");
         Assert.AreEqual("", result);

      }

      [Test]
      public void TestSearchUSASCII()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         SMTPClientSimulator.StaticSend(account.Address, account.Address, "MySubject", "MyBody");

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();
         Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.Search("CHARSET US-ASCII ALL SUBJECT MySubject");
         Assert.AreEqual("1", result);

         result = oSimulator.Search("CHARSET US-ASCII ALL SUBJECT MySubjact");
         Assert.AreEqual("", result);
      }

      [Test]
      public void TestSearchInvalidCharset()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");

         SMTPClientSimulator.StaticSend(account.Address, account.Address, "MySubject", "MyBody");

         POP3Simulator.AssertMessageCount(account.Address, "test", 1);

         IMAPSimulator oSimulator = new IMAPSimulator();
         Assert.IsTrue(oSimulator.ConnectAndLogon(account.Address, "test"));
         Assert.IsTrue(oSimulator.SelectFolder("INBOX"));

         string result = oSimulator.SendSingleCommand("A01 SEARCH CHARSET NONEXISTANT ALL SUBJECT MySubject");
         Assert.AreEqual("A01 NO [BADCHARSET]\r\n", result);
      }

   }
}
