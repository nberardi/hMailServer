// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.IO;

namespace UnitTest.Protocols.IMAP
{
    [TestFixture]
    public class Fetch : TestFixtureBase
    {
        [Test]
        public void TestFetch()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody1");
            IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody2");
            IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 2);

            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody3");
            IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);


            IMAPSimulator sim = new IMAPSimulator();
            sim.ConnectAndLogon(account.Address, "test");
            sim.SelectFolder("INBOX");
            string result = sim.Fetch("1 BODY[1]");
            Assert.IsTrue(result.Contains("SampleBody1"), result);
            result = sim.Fetch("2 BODY[1]");
            Assert.IsTrue(result.Contains("SampleBody2"), result);
            result = sim.Fetch("3 BODY[1]");
            Assert.IsTrue(result.Contains("SampleBody3"), result);
        }

        [Test]
        public void TestFetchInvalid()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody1");
            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody2");
            SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody3");

            IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 3);

            IMAPSimulator sim = new IMAPSimulator();
            sim.ConnectAndLogon(account.Address, "test");
            sim.SelectFolder("INBOX");
            string result = sim.Fetch("0 BODY[1]");
            Assert.IsTrue(result.StartsWith("A01 OK FETCH completed"));
            result = sim.Fetch("-1 BODY[1]");
            Assert.IsTrue(result.StartsWith("A01 BAD"));
            result = sim.Fetch("-100 BODY[1]");
            Assert.IsTrue(result.StartsWith("A01 BAD"));
        }

        [Test]
        [Description("Issue 209, Date containing \" doesn't show up in OE")]
        public void TestFetchEnvelopeWithDateContainingQuote()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mimetest@test.com", "test");

            string message = "From: Someone <someone@example.com>" + Environment.NewLine +
                             "To: Someoen <someone@example.com>" + Environment.NewLine +
                             "Date: Wed, 22 Apr 2009 11:05:09 \"GMT\"" + Environment.NewLine +
                             "Subject: Something" + Environment.NewLine +
                             Environment.NewLine +
                             "Hello" + Environment.NewLine;

            SMTPSimulator smtpSimulator = new SMTPSimulator();
            smtpSimulator.SendRaw(account.Address, account.Address, message);

            POP3Simulator.AssertMessageCount(account.Address, "test", 1);

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            oSimulator.SelectFolder("INBOX");
            string result = oSimulator.Fetch("1 ENVELOPE");
            oSimulator.Disconnect();

            Assert.IsTrue(result.Contains("Wed, 22 Apr 2009 11:05:09 GMT"));

        }

        [Test]
        [Description("Issue 218, IMAP: Problem with file name containing non-latin chars")]
        public void TestBodyStructureWithNonLatinCharacter()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            string attachmentName = "本本本.zip";

            string filename = Path.Combine(Path.GetTempPath(), attachmentName);
            File.WriteAllText(filename, "tjena moss");

            hMailServer.Message message = new hMailServer.Message();
            message.Charset = "utf-8";
            message.AddRecipient("test", account.Address);
            message.From = "Test";
            message.FromAddress = account.Address;
            message.Body = "hejsan";
            message.Attachments.Add(filename);
            message.Save();

            Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

            IMAPSimulator oSimulator = new IMAPSimulator();
            oSimulator.ConnectAndLogon(account.Address, "test");
            oSimulator.SelectFolder("INBOX");
            string result = oSimulator.Fetch("1 BODYSTRUCTURE");
            oSimulator.Disconnect();

            // utf-8 representation of 本本本.zip:
            Assert.IsTrue(result.Contains("=?utf-8?B?5pys5pys5pys?=.zip"));
        }

        [Test]
        [Description("Issue 282, hMailServer not working with Symbian N60 ")]
        public void TestFetchHeaderFields()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mimetest@test.com", "test");

            string message = "From: Someone <someone@example.com>" + Environment.NewLine +
                             "To: Someoen <someone@example.com>" + Environment.NewLine +
                             "Date: Wed, 22 Apr 2009 11:05:09 \"GMT\"" + Environment.NewLine +
                             "Subject: Something" + Environment.NewLine +
                             Environment.NewLine +
                             "Hello" + Environment.NewLine;

            SMTPSimulator smtpSimulator = new SMTPSimulator();
            Assert.IsTrue(smtpSimulator.SendRaw(account.Address, account.Address, message));

            POP3Simulator.AssertMessageCount(account.Address, "test", 1);

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            oSimulator.SelectFolder("INBOX");
            string result = oSimulator.Fetch("1 BODY.PEEK[HEADER.FIELDS (Subject From)]");
            oSimulator.Disconnect();


            Assert.IsTrue(result.Contains("Subject: Something"));
            Assert.IsTrue(result.Contains("From: Someone <someone@example.com>"));
            // The feedback should end with an empty header line.
            Assert.IsTrue(result.Contains("\r\n\r\n)"));
            Assert.IsFalse(result.Contains("Received:"));

        }

        [Test]
        [Description("Issue 282, hMailServer not working with Symbian N60 ")]
        public void TestFetchHeaderFieldsNot()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "mimetest@test.com", "test");

            string message = "From: Someone <someone@example.com>" + Environment.NewLine +
                             "To: Someoen <someone@example.com>" + Environment.NewLine +
                             "Date: Wed, 22 Apr 2009 11:05:09 \"GMT\"" + Environment.NewLine +
                             "Subject: Something" + Environment.NewLine +
                             Environment.NewLine +
                             "Hello" + Environment.NewLine;

            SMTPSimulator smtpSimulator = new SMTPSimulator();
            Assert.IsTrue(smtpSimulator.SendRaw(account.Address, account.Address, message));

            POP3Simulator.AssertMessageCount(account.Address, "test", 1);

            IMAPSimulator oSimulator = new IMAPSimulator();
            string sWelcomeMessage = oSimulator.Connect();
            oSimulator.Logon(account.Address, "test");
            oSimulator.SelectFolder("INBOX");
            string result = oSimulator.Fetch("1 BODY.PEEK[HEADER.FIELDS.NOT (Subject From)]");
            oSimulator.Disconnect();


            Assert.IsTrue(result.Contains("Received:"), result);
            Assert.IsFalse(result.Contains("Subject:"), result);
            Assert.IsFalse(result.Contains("From:"), result);
            // The feedback should end with an empty header line.
            Assert.IsTrue(result.Contains("\r\n\r\n)"), result);
            

        }

    }
}
