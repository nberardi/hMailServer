// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using UnitTest.Protocols.SMTP;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.Security
{
    [TestFixture]
    public class PasswordMasking : TestFixtureBase
    {
        hMailServer.Status _status;

        private const string _username = "NonSecretUser@test.com";
        private const string _password = "SecretPassword";

        [SetUp]
        public new void SetUp()
        {
            _status = SingletonProvider<Utilities>.Instance.GetApp().Status;
            string logFile = _settings.Logging.CurrentDefaultLog;
            if (File.Exists(logFile))
                File.Delete(logFile);

        }

        [Test]
        public void TestPOP3Server()
        {
            POP3Simulator sim = new POP3Simulator();
            sim.ConnectAndLogon(GetUsername(), GetPassword());
            EnsureNoPassword();
        }

        [Test]
        public void TestIMAPServerNormal()
        {
            IMAPSimulator sim = new IMAPSimulator();
            sim.ConnectAndLogon(GetUsername(), GetPassword());
            EnsureNoPassword();
        }

        [Test]
        public void TestIMAPServerLiteral()
        {
            IMAPSimulator sim = new IMAPSimulator();
            sim.Connect();
            Assert.IsTrue(sim.Send("a01 login " + GetUsername() + " {4}").StartsWith("+"));
            sim.Send(GetPassword());
            EnsureNoPassword();
        }

        [Test]
        public void TestIMAPServerLiteral2()
        {
            IMAPSimulator sim = new IMAPSimulator();
            sim.Connect();
            Assert.IsTrue(sim.Send("a01 login {" + GetUsername().Length.ToString() + "} {4}").StartsWith("+"));
            Assert.IsTrue(sim.Send(GetUsername() + " {" + GetPassword().Length.ToString() + "}").StartsWith("+"));
            sim.Send(GetPassword());
            EnsureNoPassword();
        }

        [Test]
        public void TestSMTPServerAuthLogin()
        {

            SMTPSimulator sim = new SMTPSimulator();
            string errorMsg;
            sim.ConnectAndLogon(25, GetUsername(), GetPassword(), out errorMsg);
            EnsureNoPassword();

        }

        [Test]
        public void TestSMTPServerAuthPlain()
        {
            _settings.AllowSMTPAuthPlain = true;

            TCPSocket sock = new TCPSocket();
            sock.Connect(25);
            Assert.IsTrue(sock.Receive().StartsWith("220"));
            sock.Send("EHLO test.com\r\n");
            Assert.IsTrue(sock.Receive().StartsWith("250"));
            sock.Send("AUTH PLAIN\r\n");
            Assert.IsTrue(sock.Receive().StartsWith("334"));
            
            string str = "\t" + GetUsername() + "\t" + GetPassword();

            sock.Send(EncodeBase64(str) + "\r\n");
            Assert.IsTrue(sock.Receive().StartsWith("535"));
            EnsureNoPassword();
        }

        [Test]
        public void TestSMTPServerAuthLoginUsernameAsThirdParameter()
        {
           _settings.AllowSMTPAuthPlain = true;

           TCPSocket sock = new TCPSocket();
           sock.Connect(25);
           Assert.IsTrue(sock.Receive().StartsWith("220"));
           sock.Send("EHLO test.com\r\n");
           Assert.IsTrue(sock.Receive().StartsWith("250"));

           string base64EncodedUsername = EncodeBase64(GetUsername());
           sock.Send("AUTH LOGIN " + base64EncodedUsername + "\r\n");
           Assert.IsTrue(sock.Receive().StartsWith("334"));

           sock.Send(EncodeBase64(GetPassword()) + "\r\n");
           Assert.IsTrue(sock.Receive().StartsWith("535"));
           EnsureNoPassword();
        }

 
        [Test]
        public void TestSMTPClient()
        {
            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            Assert.AreEqual(0, _status.UndeliveredMessages.Length);

            // No valid recipients...
            Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
            deliveryResults["test@dummy-example.com"] = 550;

            SMTPServer server = new SMTPServer(1, 250);
            server.AddRecipientResult(deliveryResults);
            server.StartListen();

            // Add a route so we can connect to localhost.
            AddRoutePointingAtLocalhostWithAuth(0, 250);

            // Send message to this route.
            SMTPSimulator smtp = new SMTPSimulator();
            Assert.IsTrue(smtp.Send("test@test.com", "test@dummy-example.com", "Test", "Test message"));

            Utilities.AssertRecipientsInDeliveryQueue(0);

            string undeliveredMessages = _status.UndeliveredMessages;

            // Wait for the client to disconnect.
            server.WaitForCompletion();

            Utilities.AssertRecipientsInDeliveryQueue(0);

            EnsureNoPassword();
        }

        [Test]
        public void TestPOP3Client()
        {
            List<string> messages = new List<string>();

            string message = "From: Martin@example.com\r\n" +
                             "To: Martin@example.com\r\n" +
                             "Subject: Test\r\n" +
                             "\r\n" +
                             "Hello!";

            messages.Add(message);

            int port = 1110;
            POP3Server pop3Server = new POP3Server(1, port, messages);
            pop3Server.StartListen();

            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "user@test.com", "test");
            hMailServer.FetchAccount fa = account.FetchAccounts.Add();

            fa.Enabled = true;
            fa.MinutesBetweenFetch = 10;
            fa.Name = "Test";
            fa.Username = GetUsername();
            fa.Password = GetPassword();
            fa.UseSSL = false;
            fa.ServerAddress = "localhost";
            fa.Port = port;
            fa.ProcessMIMERecipients = false;
            fa.Save();

            fa.DownloadNow();

            pop3Server.WaitForCompletion();

            fa.Delete();

            string downloadedMessage = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
            Assert.IsTrue(downloadedMessage.Contains(message));

            EnsureNoPassword();
        }

        private string EncodeBase64(string s)
        {
            byte [] bytes = System.Text.Encoding.UTF8.GetBytes(s);
            return System.Convert.ToBase64String(bytes);
        }

        private string GetUsername()
        {
            return _username;
        }

        private string GetPassword()
        {
            return _password;
        }

        private void EnsureNoPassword()
        {
            string log = _settings.Logging.CurrentDefaultLog;
            string text = File.ReadAllText(log);

            Assert.IsTrue(text.Contains(_username) || text.Contains(EncodeBase64(_username)), text);
            Assert.IsFalse(text.Contains(_password) || text.Contains(EncodeBase64(_password)), text);
            Assert.IsTrue(text.Contains("***"), text);
        }

        internal hMailServer.Route AddRoutePointingAtLocalhostWithAuth(int numberOfTries, int port)
        {
            // Add a route pointing at localhost
            hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;

            hMailServer.Route route = oSettings.Routes.Add();
            route.DomainName = "dummy-example.com";
            route.TargetSMTPHost = "localhost";
            route.TargetSMTPPort = port;
            route.NumberOfTries = numberOfTries;
            route.RelayerRequiresAuth = true;
            route.RelayerAuthUsername = GetUsername();
            route.SetRelayerAuthPassword(GetPassword());
            route.MinutesBetweenTry = 5;
            route.Save();

            return route;
        }
        

    }
}
