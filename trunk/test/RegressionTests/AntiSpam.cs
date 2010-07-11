// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;
using System.Diagnostics;

namespace UnitTest.AntiSpam
{
    [TestFixture]
    public class Basics : TestFixtureBase
    {
        hMailServer.AntiSpam _antiSpam;

        [SetUp]
        public new void SetUp()
        {
           _antiSpam = _settings.AntiSpam;
        }

        [Test]
        public void TestIncorrectLineEndings()
        {
            // Create a test account
            // Fetch the default domain
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "SpamProtectionLineEndings@test.com", "test");

            // Disallow incorrect line endings.
            SingletonProvider<Utilities>.Instance.GetApp().Settings.AllowIncorrectLineEndings = false;

            // Send a messages to this account.

            SMTPSimulator oSMTP = new SMTPSimulator();
            if (!oSMTP.Send("SpamProtectionLineEndings@test.com", "SpamProtectionLineEndings@test.com", "INBOX", "This is a test message\r\n consisting of correct lines"))
                throw new Exception("ERROR - Was not able to send correct email.");


            if (oSMTP.Send("SpamProtectionLineEndings@test.com", "SpamProtectionLineEndings@test.com", "INBOX", "This is a test message\r consisting of incorrect lines"))
                throw new Exception("ERROR - Was able to send incorrect email.");


            if (oSMTP.Send("SpamProtectionLineEndings@test.com", "SpamProtectionLineEndings@test.com", "INBOX", "This is a test message\n consisting of incorrect lines"))
                throw new Exception("ERROR - Was able to send incorrect email.");


            if (oSMTP.Send("SpamProtectionLineEndings@test.com", "SpamProtectionLineEndings@test.com", "INBOX", "This is a test message\n\r consisting of incorrect lines"))
                throw new Exception("ERROR - Was able to send incorrect email.");

            POP3Simulator.AssertMessageCount(oAccount1.Address, "test", 1);
        }

        [Test]
        public void TestMissingMXRecord()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "missingmxrecords@test.com", "test");

            // Disallow incorrect line endings.

            _antiSpam.SpamDeleteThreshold = 1;
            _antiSpam.UseMXChecks = true;
            _antiSpam.UseMXChecksScore = 2;

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            if (!oSMTP.Send("test@microsoft.com", "missingmxrecords@test.com", "INBOX", "This is a test message."))
                throw new Exception("ERROR - Was not able to send correct email.");

            if (oSMTP.Send("test@domain_without_mx_records421dfsam430sasd.com", oAccount1.Address, "INBOX", "This is a test message."))
                throw new Exception("ERROR - Was not able to send incorrect email.");

            _antiSpam.UseMXChecks = false;

            POP3Simulator.AssertMessageCount(oAccount1.Address, "test", 1);
        }

        [Test]
        public void TestSURBL()
        {


            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SURBL.
            hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
            oSURBLServer.Active = true;
            oSURBLServer.Score = 5;
            oSURBLServer.Save();

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();


            oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-No-Match", "This is a test message without a SURBL url.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (sMessageContents.Length == 0 ||
                sMessageContents.Contains("X-hMailServer-Spam") ||
                sMessageContents.Contains("X-hMailServer-Reason") ||
                sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Non-Spam message detected as spam");


            oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-");

            sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (!sMessageContents.Contains("X-hMailServer-Spam") ||
                !sMessageContents.Contains("X-hMailServer-Reason") ||
                !sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Spam message not detected as spam");

            oSURBLServer.Active = false;
            oSURBLServer.Save();
        }

        [Test]
        public void TestSURBLCorrectNegative()
        {
           hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

           // Disallow incorrect line endings.
           _antiSpam.SpamMarkThreshold = 1;
           _antiSpam.SpamDeleteThreshold = 100;
           _antiSpam.AddHeaderReason = true;
           _antiSpam.AddHeaderSpam = true;
           _antiSpam.PrependSubject = true;
           _antiSpam.PrependSubjectText = "ThisIsSpam";

           // Enable SURBL.
           hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
           oSURBLServer.Active = true;
           oSURBLServer.Score = 5;
           oSURBLServer.Save();

           // Send a messages to this account.
           Assert.IsTrue(SMTPSimulator.StaticSend("surbltest@test.com", "surbltest@test.com", "SURBL-Match", "This is a test message without a SURBL url: -> http://www.youtube.com/ <-"));

           string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
           if (sMessageContents.Contains("X-hMailServer-Spam"))
              throw new Exception("Non-spam message detected as spam");

           oSURBLServer.Active = false;
           oSURBLServer.Save();
        }

        [Test]
        public void TestSURBLCombinedWithSignature()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            _domain.SignatureEnabled = true;
            _domain.SignaturePlainText = "MyDomainSignature";
            _domain.AddSignaturesToLocalMail = true;
            _domain.Save();

            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SURBL.
            hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
            oSURBLServer.Active = true;
            oSURBLServer.Score = 5;
            oSURBLServer.Save();

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-No-Match", "This is a test message without a SURBL url.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (sMessageContents.Length == 0 ||
                sMessageContents.Contains("X-hMailServer-Spam") ||
                sMessageContents.Contains("X-hMailServer-Reason") ||
                sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Non-Spam message detected as spam");

            Assert.IsTrue(sMessageContents.Contains(_domain.SignaturePlainText));

            oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-No-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-");

            sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (!sMessageContents.Contains("X-hMailServer-Spam") ||
                !sMessageContents.Contains("X-hMailServer-Reason") ||
                !sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Spam message not detected as spam");

            Assert.IsTrue(sMessageContents.Contains(_domain.SignaturePlainText));

        }

        [Test]
        public void TestSPF()
        {


            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "spftest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SPF
            _antiSpam.UseSPF = true;
            _antiSpam.UseSPFScore = 5;

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            oSMTP.Send("spftest@openspf.org", oAccount1.Address, "SPF test", "This is a test message.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (!sMessageContents.Contains("X-hMailServer-Spam"))
                throw new Exception("Spam message not detected as spam");

            _antiSpam.UseSPF = false;

            oSMTP.Send("spftest@openspf.org", oAccount1.Address, "SPF test", "This is a test message.");

            sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (sMessageContents.Contains("X-hMailServer-Spam"))
                throw new Exception("Non-spam message detected as spam");
        }


        [Test]
        public void TestMaxSizeLimit()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";
            _antiSpam.MaximumMessageSize = 40;

            // Enable SURBL.
            hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
            oSURBLServer.Active = true;
            oSURBLServer.Score = 5;
            oSURBLServer.Save();

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            StringBuilder sb = new StringBuilder();
            int iterations = ((40 * 1024) / 100) + 1;
            for (int i = 0; i < iterations; i++)
            {
                sb.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");
            }

            Assert.IsTrue(oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-No-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-\r\n" + sb.ToString()));

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (sMessageContents.Contains("X-hMailServer-Spam") ||
                sMessageContents.Contains("X-hMailServer-Reason") ||
                sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Spam message etected as spam even though it's larger than max spam size.");

            oSURBLServer.Active = false;
            oSURBLServer.Save();
        }

        [Test]
        public void TestMaxSizeNoLimit()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";
            _antiSpam.MaximumMessageSize = 0;

            // Enable SURBL.
            hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
            oSURBLServer.Active = true;
            oSURBLServer.Score = 5;
            oSURBLServer.Save();

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            StringBuilder sb = new StringBuilder();
            int iterations = ((40 * 1024) / 100) + 1;
            for (int i = 0; i < iterations; i++)
            {
                sb.Append("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\r\n");
            }

            Assert.IsTrue(oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-No-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-\r\n" + sb.ToString()));

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (!sMessageContents.Contains("X-hMailServer-Spam") ||
                !sMessageContents.Contains("X-hMailServer-Reason") ||
                !sMessageContents.Contains("ThisIsSpam"))
                throw new Exception("Spam message not detected as spam.");

            oSURBLServer.Active = false;
            oSURBLServer.Save();
        }

        [Test]
        public void TestSURBLWithWrappedURL()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "surbltest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SURBL.
            hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
            oSURBLServer.Active = true;
            oSURBLServer.Score = 5;
            oSURBLServer.Save();

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            oSMTP.Send("surbltest@test.com", "surbltest@test.com", "SURBL-Match",
               "Wrapped URL - <a href=3D\"http://surbl-org-perma=\r\nnent-test-point.com\">Test</a>");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            Assert.IsTrue(sMessageContents.Contains("X-hMailServer-Spam"), "Spam message not detected as spam");

            oSURBLServer.Active = false;
            oSURBLServer.Save();
        }

        [Test]
        public void TestSPFWithDebugLogging()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

            string debugLog = _settings.Logging.CurrentDefaultLog;
            Utilities.AssertDeleteFile(debugLog);

            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "spftest@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SPF
            _antiSpam.UseSPF = true;
            _antiSpam.UseSPFScore = 12;

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            oSMTP.Send("spftest@openspf.org", oAccount1.Address, "SPF test", "This is a test message.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            if (!sMessageContents.Contains("X-hMailServer-Spam"))
                throw new Exception("Spam message not detected as spam");

            // Check that it has been logged.
            string contents = Utilities.ReadExistingTextFile(debugLog);
            Assert.IsTrue(contents.Contains("Total spam score: 12"));
            Assert.IsTrue(contents.Contains("Spam test: SpamTestSPF, Score: 12"));

            Utilities.AssertDeleteFile(debugLog);
        }

        [Test]
        public void TestHeloSpamTest()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            // Disallow incorrect line endings.
            _antiSpam.SpamDeleteThreshold = 100;

            _antiSpam.CheckHostInHelo = true;
            _antiSpam.CheckHostInHeloScore = 125;

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            Assert.IsFalse(oSMTP.Send("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "Test"));
        }

        [Test]
        public void TestSPFViaIncomingRelay()
        {
            hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
            // Create a test account
            // Fetch the default domain
            ;
            hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "spftest@test.com", "test");

            _antiSpam.SpamMarkThreshold = 1;
            _antiSpam.SpamDeleteThreshold = 100;
            _antiSpam.AddHeaderReason = true;
            _antiSpam.AddHeaderSpam = true;
            _antiSpam.PrependSubject = true;
            _antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SPF
            _antiSpam.UseSPF = true;
            _antiSpam.UseSPFScore = 5;

            string message = @"Received: from openspf.org ([76.79.20.184]) by Someone ; Mon, 29 Dec 2008 13:42:55 +0100\r\n" +
                "Message-ID: <5F90152F-DAC5-43CF-B553-FCF9302F6E0C@WORK>\r\n" +
                "From: spftest@openspf.org\r\n" +
                "To: spftest@test.com\r\n" +
                "\r\n" +
                "This is a test message.\r\n";
    

            // Send a messages to this account.
            SMTPSimulator oSMTP = new SMTPSimulator();

            oSMTP.SendRaw("spftest@openspf.org", oAccount1.Address, message);
            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            Assert.IsTrue(sMessageContents.Contains("X-hMailServer-Spam"), sMessageContents);

            // Add a forwarding relay pointing at localhost, so that the message will appear to be
            // properly forwarded.
            hMailServer.IncomingRelays incomingRelays = _settings.IncomingRelays;
            Assert.AreEqual(0, incomingRelays.Count);

            hMailServer.IncomingRelay incomingRelay = incomingRelays.Add();
            incomingRelay.Name = "Localhost";
            incomingRelay.LowerIP = "127.0.0.1";
            incomingRelay.UpperIP = "127.0.0.1";
            incomingRelay.Save();

            oSMTP.SendRaw("spftest@openspf.org", oAccount1.Address, message);
            sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            Assert.IsFalse(sMessageContents.Contains("X-hMailServer-Spam"), sMessageContents);

            // change so that the forwarding relay no longer covers the IP.
            incomingRelay.LowerIP = "1.1.1.1";
            incomingRelay.UpperIP = "1.1.1.1";
            incomingRelay.Save();

            oSMTP.SendRaw("spftest@openspf.org", oAccount1.Address, message);
            sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
            Assert.IsTrue(sMessageContents.Contains("X-hMailServer-Spam"), sMessageContents);

        }

        [Test]
        public void TestDNSBlackList()
        {
           hMailServer.DNSBlackLists dnsBlackLists = SingletonProvider<Utilities>.Instance.GetApp().Settings.AntiSpam.DNSBlackLists;

           hMailServer.DNSBlackList dnsBlackList = dnsBlackLists.Add();
           dnsBlackList.DNSHost = "zen.spamhaus.org";
           dnsBlackList.RejectMessage = "srv1";
           dnsBlackList.Score = 5;
           dnsBlackList.Active = true;
           dnsBlackList.Save();

           dnsBlackList = dnsBlackLists.Add();
           dnsBlackList.DNSHost = "bl.spamcop.net";
           dnsBlackList.RejectMessage = "srv2";
           dnsBlackList.Score = 5;
           dnsBlackList.Active = false;
           dnsBlackList.Save();

           dnsBlackList = dnsBlackLists.Add();
           dnsBlackList.DNSHost = "dnsbl.njabl.org";
           dnsBlackList.RejectMessage = "srv3";
           dnsBlackList.Score = 5;
           dnsBlackList.Active = true;
           dnsBlackList.Save();

           hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
           _antiSpam.SpamMarkThreshold = 1;
           _antiSpam.SpamDeleteThreshold = 100;

           hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "dnsbltest@test.com", "test");

           Utilities.DeleteCurrentDefaultLog();

           SMTPSimulator.StaticSend(account.Address, account.Address, "Test", "TestBody");
           POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

           string result = Utilities.ReadCurrentDefaultLog();

           Assert.IsTrue(result.Contains(".zen.spamhaus.org, 0 addresses found: (none), Match: False"), result);
           Assert.IsTrue(result.Contains(".dnsbl.njabl.org, 0 addresses found: (none), Match: False"), result);
           Assert.IsFalse(result.Contains(".bl.spamcop.net, 0 addresses found:"), result);
        }
    }

}
