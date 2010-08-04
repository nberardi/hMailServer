using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.AntiVirus
{
    [TestFixture]
    public class ClamAV : TestFixtureBase
    {
        hMailServer.AntiVirus _antiVirus;

        [SetUp]
        public new void SetUp()
        {
            Utilities.AssertClamDRunning();

            _antiVirus = _application.Settings.AntiVirus;
        }

        [Test]
        public void TestNotEnabled()
        {
            Utilities.DeleteCurrentDefaultLog();
            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            Assert.IsTrue(SMTPSimulator.StaticSend(account1.Address, account1.Address, "Mail 1", "Mail 1"));
            POP3Simulator.AssertMessageCount(account1.Address, "test", 1);
            string defaultLog = Utilities.ReadCurrentDefaultLog();
            Assert.IsFalse(defaultLog.Contains("Connecting to ClamAV"));
        }

        [Test]
        public void TestNoVirus()
        {
            _antiVirus.ClamAVEnabled = true;

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            Assert.IsTrue(SMTPSimulator.StaticSend(account1.Address, account1.Address, "Mail 1", "Mail 1"));
            POP3Simulator.AssertMessageCount(account1.Address, "test", 1);
        }

        [Test]
        public void TestWithVirus()
        {
            _antiVirus.ClamAVEnabled = true;
            Utilities.DeleteCurrentDefaultLog();

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            string firstPart = @"X5O!P%@AP[4\PZX54(P^)7CC)7}";
            string secondPart = @"$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";
            Assert.IsTrue(SMTPSimulator.StaticSend(account1.Address, account1.Address, "Mail 1", firstPart + secondPart));

            Utilities.AssertRecipientsInDeliveryQueue(0);
            POP3Simulator.AssertMessageCount(account1.Address, "test", 0);

            string defaultLog = Utilities.ReadCurrentDefaultLog();
            Assert.IsTrue(defaultLog.Contains("Connecting to ClamAV"));
            Assert.IsTrue(defaultLog.Contains("Message deleted (contained virus Eicar-Test-Signature)"));
        }

        [Test]
        public void TestIncorrectPort()
        {
            _antiVirus.ClamAVEnabled = true;
            _antiVirus.ClamAVPort = 110;

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            Assert.IsTrue(SMTPSimulator.StaticSend(account1.Address, account1.Address, "Mail 1", "DummyBody"));
            POP3Simulator.AssertMessageCount(account1.Address, "test", 1);
            Utilities.AssertReportedError("Protocol error. Unexpected response: +OK");
        }

        [Test]
        public void TestUnusedPort()
        {
            _antiVirus.ClamAVEnabled = true;
            _antiVirus.ClamAVPort = 54391;

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
            Assert.IsTrue(SMTPSimulator.StaticSend(account1.Address, account1.Address, "Mail 1", "DummyBody"));
            POP3Simulator.AssertMessageCount(account1.Address, "test", 1);
            Utilities.AssertReportedError("Unable to connect to ClamAV server at localhost:54391.");
        }
    }

}
