// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using NUnit.Framework;

namespace UnitTest
{
   [TestFixture]
   public class TCPIP : TestFixtureBase
   {
      [Test]
      [Category("TCP/IP implementation")]
      [Description("Ensure that basic resolution of existing domain names work.")]
      public void TestMXQueryExistingDomain()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         
         string sQuery = application.Utilities.GetMailServer("martin@hmailserver.com");
         if (sQuery != Utilities.GethMailServerCOMIPaddress())
            throw new Exception("ERROR - DNX query failed: " + sQuery);
      }

      [Test]
      [Category("TCP/IP implementation")]
      [Description("Ensure that basic resolution of non-existing domain names work.")]
      public void TestMXQueryNonExistentDomain()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         string query = application.Utilities.GetMailServer("martin@23sdfakm52lvcxbmvxcbmdtapvxcpaasdf.com");
         Assert.IsTrue(query.Length == 0);
      }

      [Test]
      [Category("TCP/IP implementation")]
      [Description("Ensure that it's possible to re-configure which ports hMailServer should listen on")]
      public void TestPortOpening()
      {
         hMailServer.Application oApp = SingletonProvider<Utilities>.Instance.GetApp();

         oApp.Settings.TCPIPPorts.SetDefault();

         SMTPSimulator pSMTPSimulator = new SMTPSimulator();
         POP3Simulator pPOP3Simulator = new POP3Simulator();
         IMAPSimulator pIMAPSimulator = new IMAPSimulator();

         oApp.Stop();

         hMailServer.TCPIPPorts oPorts = oApp.Settings.TCPIPPorts;
         for (int i = 0; i < oPorts.Count; i++)
         {
            hMailServer.TCPIPPort oTestPort = oPorts[i];
            if (oTestPort.Protocol == hMailServer.eSessionType.eSTIMAP)
               oTestPort.PortNumber = 14300;
            else if (oTestPort.Protocol == hMailServer.eSessionType.eSTSMTP)
               oTestPort.PortNumber = 11000;
            else if (oTestPort.Protocol == hMailServer.eSessionType.eSTPOP3)
               oTestPort.PortNumber = 2500;

            oTestPort.Save();
         }
 
         oApp.Start();

         Assert.IsTrue(pSMTPSimulator.TestConnect(2500));
         Assert.IsTrue(pSMTPSimulator.TestConnect(11000));
         Assert.IsTrue(pSMTPSimulator.TestConnect(14300));

         oApp.Stop();

         hMailServer.TCPIPPort oPort = oApp.Settings.TCPIPPorts.Add();
         oPort.Protocol = hMailServer.eSessionType.eSTSMTP;
         oPort.PortNumber = 25000;
         oPort.Save();

         oApp.Start();

         // Try to connect to the new port
         Assert.IsTrue(pSMTPSimulator.TestConnect(25000));

         oApp.Stop();

          // Delete the port again
         oApp.Settings.TCPIPPorts.DeleteByDBID(oPort.ID);

         // Change back the ports
         for (int i = 0; i < oPorts.Count; i++)
         {
            hMailServer.TCPIPPort oTestPort = oPorts[i];
            if (oTestPort.Protocol == hMailServer.eSessionType.eSTIMAP)
               oTestPort.PortNumber = 143;
            else if (oTestPort.Protocol == hMailServer.eSessionType.eSTSMTP)
               oTestPort.PortNumber = 25;
            else if (oTestPort.Protocol == hMailServer.eSessionType.eSTPOP3)
               oTestPort.PortNumber = 110;

            oTestPort.Save();
         }
   
         oApp.Start();

         Assert.IsTrue(pSMTPSimulator.TestConnect(25));
         Assert.IsTrue(pPOP3Simulator.TestConnect(110));
         Assert.IsTrue(pPOP3Simulator.TestConnect(143));
      }
   }
}
