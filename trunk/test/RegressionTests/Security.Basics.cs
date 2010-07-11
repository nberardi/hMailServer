// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;

namespace UnitTest.Security
{
   [TestFixture]
   public class Basics : TestFixtureBase
   {
      [Test]
      public void TestEmptyPassword()
      {
         hMailServer.Account account1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "");

         string message;
         POP3Simulator sim = new POP3Simulator();
         Assert.IsFalse(sim.ConnectAndLogon(account1.Address, "", out message));
         

         IMAPSimulator simIMAP = new IMAPSimulator();
         Assert.IsFalse(simIMAP.ConnectAndLogon(account1.Address, "", out message));
         Assert.AreEqual("A01 NO Invalid user name or password.\r\n", message);
         
         SMTPSimulator simSMTP = new SMTPSimulator();
         Assert.IsFalse(simSMTP.ConnectAndLogon(25, "dGVzdEB0ZXN0LmNvbQ==", "", out message));
         Assert.AreEqual("535 Authentication failed. Restarting authentication process.\r\n", message);
         
      }
   }
}
