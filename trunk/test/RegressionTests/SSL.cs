// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;
using NUnit.Framework;



namespace UnitTest.SSL
{
   [TestFixture]
   public class Basic : TestFixtureBase
   {
      [TestFixtureSetUp]
      public new void TestFixtureSetUp()
      {
         InternalSetupSMTPSSLPort();

         Thread.Sleep(1000);
      }

      private hMailServer.SSLCertificate SetupSSLCertificate()
      {
         string originalPath = Environment.CurrentDirectory;
         Environment.CurrentDirectory = Environment.CurrentDirectory + "\\..\\..\\..\\SSL examples";
         string sslPath = Environment.CurrentDirectory;
         Environment.CurrentDirectory = originalPath;

         hMailServer.SSLCertificate sslCertificate = _application.Settings.SSLCertificates.Add();
         sslCertificate.Name = "Example";
         sslCertificate.CertificateFile = sslPath + "\\example.crt";
         sslCertificate.PrivateKeyFile = sslPath + "\\example.key";
         sslCertificate.Save();

         return sslCertificate;
      }

      [Test]
      [Category("SSL")]
      [Description("Confirm that the TCP/IP log contains information on when a SSL handshake fails")]
      public void SetupSSLPort()
      {
         _application.Settings.Logging.Enabled = true;
         _application.Settings.Logging.LogTCPIP = true;
         _application.Settings.Logging.EnableLiveLogging(true);

         TCPSocket cs = new TCPSocket();
         if (!cs.Connect(250))
            Assert.Fail("Could not connect to SSL server.");

         cs.Disconnect();

         for (int i = 0; i <= 40; i++)
         {
            Assert.IsTrue(i != 40);

            string liveLog = _application.Settings.Logging.LiveLog;
            if (liveLog.Contains("SSL handshake with client failed."))
               break;

            Thread.Sleep(250);
         }

         _application.Settings.Logging.EnableLiveLogging(false);
      }

      private void InternalSetupSMTPSSLPort()
      {
         hMailServer.SSLCertificate sslCeritifcate = SetupSSLCertificate();

         hMailServer.TCPIPPort port = _application.Settings.TCPIPPorts.Add();
         port.Address = "0.0.0.0";
         port.PortNumber = 250;
         port.UseSSL = true;
         port.SSLCertificateID = sslCeritifcate.ID;
         port.Protocol = hMailServer.eSessionType.eSTSMTP;
         port.Save();

         port = _application.Settings.TCPIPPorts.Add();
         port.Address = "0.0.0.0";
         port.PortNumber = 11000;
         port.UseSSL = true;
         port.SSLCertificateID = sslCeritifcate.ID;
         port.Protocol = hMailServer.eSessionType.eSTPOP3;
         port.Save();

         port = _application.Settings.TCPIPPorts.Add();
         port.Address = "0.0.0.0";
         port.PortNumber = 14300;
         port.UseSSL = true;
         port.SSLCertificateID = sslCeritifcate.ID;
         port.Protocol = hMailServer.eSessionType.eSTIMAP;
         port.Save();

         _application.Stop();
         _application.Start();
      }

      [Test]
      public void TestSMTPServer()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "smtp-ssl@test.com", "test");

          int i = 0;
          for (i = 0; i < 10; i++)
          {
              try
              {
                  SMTPSimulator smtpSim = new SMTPSimulator(true, 250);
                  Assert.IsTrue(smtpSim.Send("test@test.com", account.Address, "Test", "MyBody"));

                  break;
              }
              catch (Exception)
              {
                  if (i == 9)
                      throw;
              }

              
          }

         POP3Simulator.AssertMessageCount(account.Address, "test", i+1);
         POP3Simulator pop3Sim = new POP3Simulator(false, 110);
         string text = pop3Sim.GetFirstMessageText(account.Address, "test");
         Assert.IsTrue(text.Contains("MyBody"));
      }

      [Test]
      public void TestPOP3Server()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "pop3-ssl@test.com", "test");

         SMTPSimulator smtpSim = new SMTPSimulator();
         Assert.IsTrue(smtpSim.Send("test@test.com", account.Address, "Test", "MyBody"));

          for (int i = 0; i < 10;i++)
          {
              try
              {
                  POP3Simulator.AssertMessageCount(account.Address, "test", 1);
                  POP3Simulator pop3Sim = new POP3Simulator(true, 11000);
                  string text = pop3Sim.GetFirstMessageText(account.Address, "test");
                  
                  Assert.IsTrue(text.Contains("MyBody"));

                  break;
              }
              catch (AssertionException)
              {
                 throw;
              }
              catch (Exception)
              {
                  if (i == 9)
                    throw;
              }
          }

      }

      [Test]
      public void TestIMAPServer()
      {
          Utilities.DeleteCurrentDefaultLog();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "imap-ssl@test.com", "test");

          for (int i = 0; i < 30; i++)
          {
              try
              {
                  IMAPSimulator imapSim = new IMAPSimulator(true, 14300);
                  imapSim.ConnectAndLogon(account.Address, "test");
                  Assert.IsTrue(imapSim.SelectFolder("Inbox"), "SelectInbox");
                  imapSim.CreateFolder("Test");
                  Assert.IsTrue(imapSim.SelectFolder("Test"), "SelectTest");
                  Assert.IsTrue(imapSim.Logout(), "Logout");

                  imapSim.Disconnect();
                  break;
              }
              catch (Exception)
              {
                  if (i == 29)
                      throw;
              }
          }
      }

   }

}
