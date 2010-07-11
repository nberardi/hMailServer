// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.SSL
{
    [TestFixture]
    public class CertificateTypes : TestFixtureBase
    {
        [Test]
        [Description("Test that loading a private key with password does not hang")]
        public void SetupSSLCertificateWithPassword()
        {
            string originalPath = Environment.CurrentDirectory;
            Environment.CurrentDirectory = Environment.CurrentDirectory + "\\..\\..\\..\\SSL examples\\WithPassword";
            string sslPath = Environment.CurrentDirectory;
            Environment.CurrentDirectory = originalPath;

            hMailServer.SSLCertificate sslCertificate = _application.Settings.SSLCertificates.Add();
            sslCertificate.Name = "Example";
            sslCertificate.CertificateFile = sslPath + "\\server.crt";
            sslCertificate.PrivateKeyFile = sslPath + "\\server.key";
            sslCertificate.Save();

            hMailServer.TCPIPPort port = _application.Settings.TCPIPPorts.Add();
            port.Address = "0.0.0.0";
            port.PortNumber = 251;
            port.UseSSL = true;
            port.SSLCertificateID = sslCertificate.ID;
            port.Protocol = hMailServer.eSessionType.eSTSMTP;
            port.Save();

            _application.Stop();
            _application.Start();

            Utilities.AssertReportedError();
        }
    }
}
