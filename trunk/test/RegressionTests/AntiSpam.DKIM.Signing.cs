// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;
using System.IO;

namespace UnitTest.AntiSpam.DKIM
{
    [TestFixture]
    public class Signing : TestFixtureBase
    {
        hMailServer.AntiSpam _antiSpam;

        [SetUp]
        public new void SetUp()
        {
            _antiSpam = _application.Settings.AntiSpam;

            _antiSpam.SpamDeleteThreshold = 5;
        }

        [Test]
        [Description("Test that a message sent through a new domain is not tagged.")]
        public void TestSigningDisabled()
        {
            string result = SendMessage();
            Assert.IsFalse(result.ToLower().Contains("dkim-signature"), result);
        }

        [Test]
        [Description("Test that no dkim-sigature is added if the private key is not specified.")]
        public void TestSigningEnabledNoPrivateKey()
        {
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsFalse(result.ToLower().Contains("dkim-signature"), result);

            Utilities.AssertReportedError();
        }

        [Test]
        [Description("Test that no dkim-sigature is added if the selector is not specified.")]
        public void TestSigningEnabledNoSelector()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsFalse(result.ToLower().Contains("dkim-signature"), result);

            Utilities.AssertReportedError();
        }

        [Test]
        [Description("Test that a dkim-sigature is added if both the selector and private key is specified.")]
        public void TestSigningEnabled()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("dkim-signature"), result);
        }


        [Test]
        [Description("Test that the selector specified in the domain is specified in the header.")]
        public void TestSelectorInHeader()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "MySelector";
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("dkim-signature"), result);
            Assert.IsTrue(result.Contains("s=MySelector"), result);
        }

        [Test]
        [Description("Test that senders domain is specified in the d=tag.")]
        public void TestDomainInHeader()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("dkim-signature"), result);
            Assert.IsTrue(result.ToLower().Contains("d=" + _domain.Name.ToLower()), result);
        }

        [Test]
        [Description("Test that the default canonicalization method is relaxed/relaxed.")]
        public void TestDefaultAlgorithm()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("a=rsa-sha256"), result);
        }

        [Test]
        [Description("Test usage of algorithm RSA-SHA1.")]
        public void TestAlgorithmSHA1()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSigningAlgorithm = hMailServer.eDKIMAlgorithm.eSHA1;
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("a=rsa-sha1"), result);
        }

        [Test]
        [Description("Test usage of algorithm RSA-SHA256.")]
        public void TestAlgorithmSHA256()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSigningAlgorithm = hMailServer.eDKIMAlgorithm.eSHA256;
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();

            if (result.ToLower().Contains("a=rsa-sha256") == false)
            {
                Assert.Fail(result);
            }
        }

        [Test]
        [Description("Test that the default canonicalization method is relaxed/relaxed.")]
        public void TestDefaultCanonicalizationMethod()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("relaxed/relaxed"), result);
        }

        [Test]
        [Description("Test that the default canonicalization method is relaxed/relaxed.")]
        public void TestCanonicalizationMethodSimpleSimple()
        {
            _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
            _domain.DKIMSelector = "TestSelector";
            _domain.DKIMBodyCanonicalizationMethod = hMailServer.eDKIMCanonicalizationMethod.eCanonicalizationSimple;
            _domain.DKIMHeaderCanonicalizationMethod = hMailServer.eDKIMCanonicalizationMethod.eCanonicalizationSimple;
            _domain.DKIMSignEnabled = true;
            _domain.Save();

            string result = SendMessage();
            Assert.IsTrue(result.ToLower().Contains("simple/simple"), result);
        }

        private string GetPrivateKeyFile()
        {
            string originalPath = Environment.CurrentDirectory;
            Environment.CurrentDirectory = Environment.CurrentDirectory + "\\..\\..\\..\\SSL examples";
            string sslPath = Environment.CurrentDirectory;
            Environment.CurrentDirectory = originalPath;

            return Path.Combine(sslPath, "example.key");
        }

        private string SendMessage()
        {
           return SendMessage("Test message");
        }

        private string SendMessage(string body)
        {
           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["test@example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           // Add a route so we can connect to localhost.
           AddRoutePointingAtLocalhost(5, 250);

           // Send message to this route.
           SMTPClientSimulator smtp = new SMTPClientSimulator();
           List<string> recipients = new List<string>();
           recipients.Add("test@example.com");
           Assert.IsTrue(smtp.Send("test@test.com", recipients, "Test", body));

           // Wait for the client to disconnect.
           server.WaitForCompletion();
           string messageData = server.MessageData;

           Utilities.AssertRecipientsInDeliveryQueue(0);

           return messageData;
        }

        internal static hMailServer.Route AddRoutePointingAtLocalhost(int numberOfTries, int port)
        {
            // Add a route pointing at localhost
            hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;

            hMailServer.Route route = oSettings.Routes.Add();
            route.DomainName = "example.com";
            route.TargetSMTPHost = "localhost";
            route.TargetSMTPPort = port;
            route.NumberOfTries = numberOfTries;
            route.MinutesBetweenTry = 5;
            route.Save();

            return route;
        }
		
		[Test]
        [Description("Test to DKIM sign an empty body.")]
        public void TestSignSingleWordBody()
        {
           _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
           _domain.DKIMSelector = "TestSelector";
           _domain.DKIMSignEnabled = true;
           _domain.Save();

           string result = SendMessage("Test");
           Assert.IsTrue(result.Contains("bh=fdkeB/A0FkbVP2k4J4pNPoeWH6vqBm9+b0C3OY87Cw8=;"), result);
        }


        [Test]
        [Description("Test to DKIM sign an empty body.")]
        public void TestSignSingleEmptyBody()
        {
           _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
           _domain.DKIMSelector = "TestSelector";
           _domain.DKIMSignEnabled = true;
           _domain.Save();

           string result = SendMessage("");
           Assert.IsTrue(result.Contains("bh=47DEQpj8HBSa+/TImW+5JCeuQeRkm5NMpJWZG3hSuFU=;"), result);
        }

        [Test]
        [Description("Test to DKIM sign an empty body.")]
        public void TestSignSingleFewWordBody()
        {
           _domain.DKIMPrivateKeyFile = GetPrivateKeyFile();
           _domain.DKIMSelector = "TestSelector";
           _domain.DKIMSignEnabled = true;
           _domain.Save();

           string result = SendMessage("Whati\r\nwhati\r\n\r\nwhati\r\n\r\n");
           Assert.IsTrue(result.Contains("bh=HfVBKUbHPvnfdY6y9RCu4IDyM+v+0HkekU0RPi3bgCk=;"), result);
        }
    }
}
