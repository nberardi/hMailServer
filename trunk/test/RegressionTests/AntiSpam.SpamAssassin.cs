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
    public class SpamAssassin : TestFixtureBase
    {
        hMailServer.Account account;
        hMailServer.Application application;

        [SetUp]
        public new void SetUp()
        {
            Utilities.AssertSpamAssassinIsRunning();

            // Enable spam assassin
            application = SingletonProvider<Utilities>.Instance.GetApp();
            hMailServer.AntiSpam antiSpam = _settings.AntiSpam;
            ;
            account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sa@test.com", "test");

            // Disallow incorrect line endings.
            antiSpam.SpamMarkThreshold = 1;
            antiSpam.SpamDeleteThreshold = 10000;
            antiSpam.AddHeaderReason = true;
            antiSpam.AddHeaderSpam = true;
            antiSpam.PrependSubject = true;
            antiSpam.PrependSubjectText = "ThisIsSpam";

            // Enable SpamAssassin
            antiSpam.SpamAssassinEnabled = true;
            antiSpam.SpamAssassinHost = "localhost";
            antiSpam.SpamAssassinPort = 783;
            antiSpam.SpamAssassinMergeScore = false;
            antiSpam.SpamAssassinScore = 5;
        }



        [Test]
        public void TestBasic()
        {
            // Send a messages to this account.
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();

            Assert.IsTrue(oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message."));
            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
            if (!sMessageContents.Contains("X-Spam-Status"))
            {
                Assert.Fail("SpamAssassin did not run");
            }
        }

        [Test]
        public void TestSANotRunning()
        {
           Process[] processlist = Process.GetProcesses();

           foreach (Process theprocess in processlist)
           {
              if (theprocess.ProcessName == "spamd")
              {
                 theprocess.Kill();
                 break;
              }
           }


           // Send a messages to this account.
           SMTPClientSimulator oSMTP = new SMTPClientSimulator();

           Assert.IsTrue(oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message."));
           string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

           Assert.IsFalse(sMessageContents.Contains("X-Spam-Status"));
        }

        [Test]
        public void TestIncorrectHost()
        {
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();

            _settings.AntiSpam.SpamAssassinEnabled = true;
            _settings.AntiSpam.SpamAssassinHost = "localholst";// <- mispelled
            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message.");
            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
            if (sMessageContents.Contains("X-Spam-Status"))
            {
                _settings.AntiSpam.SpamAssassinEnabled = false;
                throw new Exception("Spam assassin not run");
            }


        }

        [Test]
        public void TestDisabled()
        {
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();

            _settings.AntiSpam.SpamAssassinEnabled = false;
            _settings.AntiSpam.SpamAssassinHost = "localhost";
            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
            if (sMessageContents.Contains("X-Spam-Status"))
            {
                _settings.AntiSpam.SpamAssassinEnabled = false;
                throw new Exception("Spam assassin not run");
            }
        }

        [Test]
        public void TestSpamMessage()
        {
            // Send a messages to this account.
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            
            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message with spam.\r\n XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
            if (!sMessageContents.Contains("X-Spam-Status: Yes"))
                Assert.Fail("Spam message not treated as spam (no X-Spam-Status-header).");

            if (!sMessageContents.Contains("X-hMailServer-Spam"))
                Assert.Fail("Spam message not treated as spam (no X-hMailServer-Spam header).");

            if (!sMessageContents.Contains("X-hMailServer-Reason"))
                Assert.Fail("Spam message not treated as spam (no X-hMailServer-Reason header).");

            if (!sMessageContents.Contains("X-hMailServer-Reason-Score"))
                Assert.Fail("Spam message not treated as spam (no X-hMailServer-Reason-Score header).");
            

        }

        [Test]
        public void TestMessageScore()
        {
            // Send a messages to this account.
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();

            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message with spam.\r\n XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

            int scoreStart = sMessageContents.IndexOf("X-Spam-Status: Yes, score") + "X-Spam-Status: Yes, score".Length + 1;
            int scoreEnd = sMessageContents.IndexOf(".", scoreStart);
            int scoreLength = scoreEnd - scoreStart;

            string score = sMessageContents.Substring(scoreStart, scoreLength);
            double scoreValue = Convert.ToDouble(score);

            Assert.Greater(scoreValue, 500);
        }

        [Test]
        public void TestMessageScoreNotMerged()
        {
            // Send a messages to this account.
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            POP3Simulator oPOP3 = new POP3Simulator();

            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message with spam.\r\n XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

            int scoreStart = sMessageContents.IndexOf("X-hMailServer-Reason-Score");
            Assert.AreNotSame(0, scoreStart);

            scoreStart = sMessageContents.IndexOf(":", scoreStart) +2;
            int scoreEnd = sMessageContents.IndexOf("\r\n", scoreStart);
            int scoreLength = scoreEnd - scoreStart;
            string score = sMessageContents.Substring(scoreStart, scoreLength);

            double scoreValue = Convert.ToDouble(score);
            Assert.Less(scoreValue, 10);
        }

        [Test]
        public void TestScoreMerge()
        {
            _settings.AntiSpam.SpamAssassinMergeScore = true;

            // Send a messages to this account.
            SMTPClientSimulator oSMTP = new SMTPClientSimulator();

            oSMTP.Send(account.Address, account.Address, "SA test", "This is a test message with spam.\r\n XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X.");

            string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

            int scoreStart = sMessageContents.IndexOf("X-hMailServer-Reason-Score");
            Assert.AreNotSame(-1, scoreStart, sMessageContents);

            try
            {
                scoreStart = sMessageContents.IndexOf(":", scoreStart) + 2;
            }
            catch (Exception)
            {
                Assert.Fail(sMessageContents);
            }

            Assert.AreNotSame(-1, scoreStart, sMessageContents);

            int scoreEnd = sMessageContents.IndexOf("\r\n", scoreStart);
            Assert.AreNotSame(-1, scoreEnd, sMessageContents);

            int scoreLength = scoreEnd - scoreStart;
            string score = sMessageContents.Substring(scoreStart, scoreLength);

            double scoreValue = Convert.ToDouble(score);
            Assert.Greater(scoreValue, 100);
        }

       [Test]
       public void TestWhiteList()
       {
          // First white-list the sender address
          hMailServer.WhiteListAddress address = _settings.AntiSpam.WhiteListAddresses.Add();
          address.Description = "TestWhiteList";
          address.EmailAddress = "test-sender@test.com";
          address.LowerIPAddress = "0.0.0.0";
          address.UpperIPAddress = "255.255.255.255";
          address.Save();


          // Send a messages to this account.
          SMTPClientSimulator oSMTP = new SMTPClientSimulator();
          oSMTP.Send("test-sender@test.com", account.Address, "SA test", "This is a test message with spam.\r\n XJS*C4JDBQADN1.NSBN3*2IDNEN*GTUBE-STANDARD-ANTI-UBE-TEST-EMAIL*C.34X.");

          string sMessageContents = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsFalse(sMessageContents.Contains("X-Spam-Status: Yes"));
       }

       [Test]
       public void ItShouldBePossibleToTestSAConnectionUsingAPI()
       {
          hMailServer.AntiSpam antiSpam = _settings.AntiSpam;
          
          string resultText;
          Assert.IsTrue(antiSpam.TestSpamAssassinConnection("localhost", 783, out resultText));
          Assert.IsTrue(resultText.Contains("Content analysis details:"));

          Assert.IsFalse(antiSpam.TestSpamAssassinConnection("localhost", 0, out resultText));
          

       }

    }
}
