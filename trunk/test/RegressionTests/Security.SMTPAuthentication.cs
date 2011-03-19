// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest.Protocols.SMTP;

namespace UnitTest.Security
{
    [TestFixture]
    public class SMTPAuthentication : TestFixtureBase
    {
        [SetUp]
        public new void SetUp()
        {
           _settings.ClearLogonFailureList();
        }


        [Test]
        [Description("Local to local")]
        public void TestSMTPAuthLocalToLocal()
        {
            hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
            range.RequireSMTPAuthLocalToLocal = true;
            range.Save();

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            string result;
            Assert.IsFalse(oSMTP.Send(account1.Address, account1.Address, "Mail 1", "Mail 1", out result));
            Assert.IsTrue(result.Contains("SMTP authentication is required."));

            range.RequireSMTPAuthLocalToLocal = false;
            range.Save();

            Assert.IsTrue(oSMTP.Send(account1.Address, account1.Address, "Mail 1", "Mail 1", out result));
            Utilities.AssertRecipientsInDeliveryQueue(0);
        }

        [Test]
        [Description("Test require SMTP auth when sending from local address to external address.")]
        public void TestSMTPAuthLocalToExternal()
        {
            hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
            range.RequireSMTPAuthLocalToExternal = true;
            range.Save();

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            string result;
            Assert.IsFalse(oSMTP.Send(account1.Address, "someexternaladdress@example.com", "Mail 1", "Mail 1", out result));
            Assert.IsTrue(result.Contains("SMTP authentication is required"));
        }

        [Test]
        [Description("External to local")]
        public void TestSMTPAuthExternalToLocal()
        {
            hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
            range.RequireSMTPAuthExternalToLocal = true;
            range.Save();

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            Assert.IsFalse(oSMTP.Send("someexternaladdress@example.com", account1.Address, "Mail 1", "Mail 1"));

            range.RequireSMTPAuthExternalToLocal = false;
            range.Save();

            Assert.IsTrue(oSMTP.Send("someexternaladdress@example.com", account1.Address, "Mail 1", "Mail 1"));
            Utilities.AssertRecipientsInDeliveryQueue(0);
        }


        [Test]
        [Description("Test require SMTP auth is not happening if we're trying to deliver from external to external.")]
        public void TestSMTPAuthExternalToExternal()
        {
            hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
            range.RequireSMTPAuthExternalToExternal = true;
            range.Save();

            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            string result;
            Assert.IsFalse(oSMTP.Send("externaladdress@example.com", "someexternaladdress@example.com", "Mail 1", "Mail 1", out result));
            Assert.IsTrue(result.Contains("SMTP authentication is required."));

            range.RequireSMTPAuthExternalToExternal = false;
            range.AllowDeliveryFromRemoteToRemote = false;
            range.Save();

            Assert.IsFalse(oSMTP.Send("externaladdress@example.com", "someexternaladdress@example.com", "Mail 1", "Mail 1", out result));
            Assert.IsTrue(result.Contains("550 Delivery is not allowed to this address."));

        }

        [Test]
        [Description("Local to local")]
        public void TestBlockingDeliveries()
        {
            hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
            range.RequireSMTPAuthLocalToLocal = false;
            range.RequireSMTPAuthLocalToExternal = false;
            range.RequireSMTPAuthExternalToLocal = false;
            range.RequireSMTPAuthExternalToExternal = false;

            range.AllowDeliveryFromLocalToLocal = false;
            range.AllowDeliveryFromLocalToRemote = false;
            range.AllowDeliveryFromRemoteToLocal = false;
            range.AllowDeliveryFromRemoteToRemote = false;

            range.Save();

            hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

            SMTPClientSimulator oSMTP = new SMTPClientSimulator();
            
            string result1, result2, result3, result4;

            Assert.IsFalse(oSMTP.Send(account1.Address, account1.Address, "Mail 1", "Mail 1", out result1));
            Assert.IsFalse(oSMTP.Send(account1.Address, "externaladdress@gmail.com", "Mail 1", "Mail 1", out result2));
            Assert.IsFalse(oSMTP.Send("externaladdress@gmail.com", account1.Address, "Mail 1", "Mail 1", out result3));
            Assert.IsFalse(oSMTP.Send("externaladdress@gmail.com", "externaladdress@gmail.com", "Mail 1", "Mail 1", out result4));
            
            Assert.IsTrue(result1.Contains("550 Delivery is not allowed to this address."));
            Assert.IsTrue(result2.Contains("550 Delivery is not allowed to this address."));
            Assert.IsTrue(result3.Contains("550 Delivery is not allowed to this address."));
            Assert.IsTrue(result4.Contains("550 Delivery is not allowed to this address."));

        }

        [Test]
        [Description("External to route configured to be treated as local")]
        public void TestSMTPAuthExternalToRouteConfiguredAsLocal()
        {
           // First, make sure hMailServer requires auth.
           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthExternalToExternal = true;
           range.RequireSMTPAuthLocalToExternal = true;
           range.Save();


           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = true;
           route.TreatSenderAsLocalDomain = true;
           route.Save();

           // Set up the simulating server to listen.
           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["dummy@dummy-example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           // Make sure we can't send to this route without using smtp auth.
           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           Assert.IsTrue(oSMTP.Send("someexternaladdress@example.com", "dummy@dummy-example.com", "Mail 1", "Mail 1"));

           server.WaitForCompletion();

           Assert.IsTrue(server.MessageData.Contains("Mail 1"), server.MessageData);
        }


        [Test]
        [Description("Use case 1: Delivery from internal users to a route configured as local. SMTP-auth should not be required.")]
        public void TestUseCaseDeliveryToLocalRoute()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = true;
           route.TreatSenderAsLocalDomain = false;
           route.Save();

           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["test@dummy-example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", "test@dummy-example.com", "Mail 1", "Mail 1", out result));

           server.WaitForCompletion();

           server.MessageData.Contains("Mail 1");
        }

        [Test]
        [Description("Use case 2: Delivery from primary MX to backup server. For example someone@customer to someone@hoster.")]
        public void TestUseCaseDeliveryFromPrimaryMXToBackupMX()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = true;
           route.TreatSenderAsLocalDomain = false;
           route.Save();

           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sales@test.com", "test");

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", account1.Address, "Mail 1", "Mail 1", out result));

           string text = POP3Simulator.AssertGetFirstMessageText(account1.Address, "test");
           Assert.IsTrue(text.Contains("Mail 1"));
        }

        [Test]
        [Description("Use case 3: Delivery from external user to route (backup MX case).")]
        public void TestUseCase3DeliveryFromExternalUserToPrimaryViaBackup()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = true;
           route.TreatSenderAsLocalDomain = false;
           route.Save();

           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["test@dummy-example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@example.com", "test@dummy-example.com", "Mail 1", "Mail 1", out result));

           server.WaitForCompletion();

           server.MessageData.Contains("Mail 1");
        }


        [Test]
        [Description("Test option TreatRecipientAsLocalDomain. Attempt to send message from external account to route configured as exernal. Should fail.")]
        public void TreatRecipientAsExternalDomain()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = false;
           route.Save();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsFalse(oSMTP.Send("someone@example.com", "test@dummy-example.com", "Mail 1", "Mail 1", out result));
           Assert.IsTrue(result.Contains("530 SMTP authentication is required."));
        }


        [Test]
        [Description("Test option TreatRecipientAsLocalDomain. Attempt to send message from external account to route configured as exernal. Should succeed, since it's permitted by IP range.")]
        public void TreatRecipientAsExternalDomainPermitted()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = false;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.AllowDeliveryFromRemoteToRemote = true;
           range.RequireSMTPAuthExternalToExternal = false;
           range.Save();

           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["test@dummy-example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@example.com", "test@dummy-example.com", "Mail 1", "Mail 1", out result));

           server.WaitForCompletion();

           server.MessageData.Contains("Mail 1");
        }

        [Test]
        [Description("Test option TreatRecipientAsLocalDomain. Attempt to send message from external account to route configured as local. Should succeed.")]
        public void TreatRecipientAsLocalDomain()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatRecipientAsLocalDomain = true;
           route.Save();

           Dictionary<string, int> deliveryResults = new Dictionary<string, int>();
           deliveryResults["test@dummy-example.com"] = 250;

           SMTPServerSimulator server = new SMTPServerSimulator(1, 250);
           server.AddRecipientResult(deliveryResults);
           server.StartListen();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@example.com", "test@dummy-example.com", "Mail 1", "Mail 1", out result));

           server.WaitForCompletion();

           server.MessageData.Contains("Mail 1");
        }


        [Test]
        [Description("Test option TestSenderAsLocalDomain. Attempt to send a message from a route configured as local domain to an external account. Should fail, since SMTP auth is required.")]
        public void TestSenderAsLocalDomainSendToExternal()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatSenderAsLocalDomain = true;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthLocalToExternal = true;
           range.Save();

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsFalse(oSMTP.Send("someone@dummy-example.com", "test@example.com", "Mail 1", "Mail 1", out result));
           Assert.IsTrue(result.Contains("530 SMTP authentication is required."));
        }

        [Test]
        [Description("Test option TestSenderAsLocalDomain. Attempt to send a message from a route configured as local domain to a local account account. Should fail, since SMTP auth is required.")]
        public void TestSenderAsLocalDomainSendToLocalAccount()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatSenderAsLocalDomain = true;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthLocalToLocal = true;
           range.Save();

           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sales@test.com", "test");

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsFalse(oSMTP.Send("someone@dummy-example.com", account1.Address, "Mail 1", "Mail 1", out result));
           Assert.IsTrue(result.Contains("530 SMTP authentication is required."));
        }

        [Test]
        [Description("Test option TestSenderAsLocalDomain. Attempt to send a message from a route configured as local domain to a local account account. Should succeed.")]
        public void TestSenderAsLocalDomainSendToLocalAccountPass()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatSenderAsLocalDomain = true;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthLocalToLocal = false;
           range.Save();

           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sales@test.com", "test");

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", account1.Address, "Mail 1", "Mail 1", out result));

           string text = POP3Simulator.AssertGetFirstMessageText(account1.Address, "test");
           Assert.IsTrue(text.Contains("Mail 1"));
        }

        [Test]
        [Description("Test option TestSenderAsLocalDomain. Attempt to send a message from a route configured as external domain to a local account account. Should succeed.")]
        public void TestSenderAsExternalDomainSendToLocalAccountPass()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatSenderAsLocalDomain = false;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthLocalToLocal = true;
           range.Save();

           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sales@test.com", "test");

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", account1.Address, "Mail 1", "Mail 1", out result));

           string text = POP3Simulator.AssertGetFirstMessageText(account1.Address, "test");
           Assert.IsTrue(text.Contains("Mail 1"));
        }

        [Test]
        [Description("Test option TestSenderAsLocalDomain. Attempt to send a message from a route configured as external domain to a local account account. Should fail, since SMTP auth is required.")]
        public void TestSenderAsExternalDomainSendToLocalAccountFail()
        {
           hMailServer.Route route = SMTPClientTests.AddRoutePointingAtLocalhost(1, 250, false);
           route.TreatSenderAsLocalDomain = false;
           route.Save();

           hMailServer.SecurityRange range = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges.get_ItemByName("My computer");
           range.RequireSMTPAuthExternalToLocal = true;
           range.Save();

           hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "sales@test.com", "test");

           SMTPClientSimulator oSMTP = new SMTPClientSimulator();
           string result;
           Assert.IsFalse(oSMTP.Send("someone@dummy-example.com", account1.Address, "Mail 1", "Mail 1", out result));
        }
    }

}
