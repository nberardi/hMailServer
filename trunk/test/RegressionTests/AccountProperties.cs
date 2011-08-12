// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.BusinessObjects
{
   [TestFixture]
   public class Account : TestFixtureBase
   {

      [Test]
      [Category("Accounts")]
      [Description("Ensure that empty account size is reported properly")]
      public void SizeBeforeSend()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");

         if (account.Size != 0)
            throw new Exception("Account is not empty");
      }

      [Test]
      [Category("Accounts")]
      [Description("Ensure that non-empty account size is reported properly")]
      public void SizeAfterSend()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");

         // Send a message
         for (int i = 0; i < 30; i++)
            SMTPClientSimulator.StaticSend("test@test.com", "test@test.com", "Test message", "123456789012345678901234567890123456789012345678901234567890");

         IMAPSimulator.AssertMessageCount("test@test.com", "test", "Inbox", 30);

         var size = account.Size;
         if (size == 0)
            throw new Exception("Account is empty");
      }

      [Test]
      [Category("Accounts")]
      [Description("Ensure that account size is increased when a message is received.")]
      public void SizeIncreasedWhenMessageReceived()
      {
         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "test@test.com", "test");

         string body = Utilities.CreateLargeDummyMailBody();

         // Send a message
         SMTPClientSimulator.StaticSend("test@test.com", "test@test.com", "Test message", body);
         IMAPSimulator.AssertMessageCount("test@test.com", "test", "Inbox", 1);

         float sizeBefore = account.Size;

         SMTPClientSimulator.StaticSend("test@test.com", "test@test.com", "Test message", body);
         IMAPSimulator.AssertMessageCount("test@test.com", "test", "Inbox", 2);

         float sizeAfter = account.Size;

         Assert.Greater(sizeAfter, sizeBefore);
      }
   }
}
