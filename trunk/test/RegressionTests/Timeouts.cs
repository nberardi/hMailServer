// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.Stability
{
   [TestFixture]
   public class Timeouts : TestFixtureBase
   {
      [Test]
      public void TestImproperDisconnect()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Account oAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "TimeoutTest@test.com", "test");
         int iCount = application.Status.get_SessionCount(hMailServer.eSessionType.eSTPOP3);

         POP3Simulator oPOP3 = new POP3Simulator();
         oPOP3.Connect(110);
         AssertSessionCount(hMailServer.eSessionType.eSTPOP3, iCount+1);
         oPOP3.Disconnect(); // Disconnect without sending quit

         AssertSessionCount(hMailServer.eSessionType.eSTPOP3, iCount);
      }

      private void AssertSessionCount(hMailServer.eSessionType sessionType, int expectedCount)
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         int timeout = 150;
         while (timeout > 0)
         {
            int count = application.Status.get_SessionCount(hMailServer.eSessionType.eSTPOP3);
            
            if (count == expectedCount)
               return;
            
            timeout--;
            Thread.Sleep(100);
         }

         Assert.Fail("Session count incorrect");
      }
   }
}
