// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.MIME
{
   [TestFixture]
   public class Parameters : TestFixtureBase
   {
      [Test]
      [Description("Issue 238, If charset parameter contains double quotes, the string isn't parsed properly.")]
      public void TestFetchCharsetInQuotesWithSpaceBefore()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address,
            "From: test@test.com\r\n" +
            "Content-Type: text/plain; charset = \"iso-8859-1\"\r\n" +
            "\r\n" +
            "Test\r\n");

         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");
         string result = sim.Fetch("1 BODYSTRUCTURE");
         sim.Disconnect();

         Assert.IsTrue(result.Contains("(\"CHARSET\" \"iso-8859-1\")"), result);
      }

      [Test]
      [Description("Issue 238, If charset parameter contains double quotes, the string isn't parsed properly.")]
      public void TestFetchCharsetInQuotesWithoutSpace()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address,
            "From: test@test.com\r\n" +
            "Content-Type: text/plain; charset =\"iso-8859-1\"\r\n" +
            "\r\n" +
            "Test\r\n");

         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");
         string result = sim.Fetch("1 BODYSTRUCTURE");
         sim.Disconnect();

         Assert.IsTrue(result.Contains("(\"CHARSET\" \"iso-8859-1\")"), result);
      }

      [Test]
      [Description("Issue 238, If charset parameter contains double quotes, the string isn't parsed properly.")]
      public void TestFetchCharsetInQuotesWithSpaceAfter()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address,
            "From: test@test.com\r\n" +
            "Content-Type: text/plain; charset =\"iso-8859-1\" \r\n" +
            "\r\n" +
            "Test\r\n");

         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");
         string result = sim.Fetch("1 BODYSTRUCTURE");
         sim.Disconnect();

         Assert.IsTrue(result.Contains("(\"CHARSET\" \"iso-8859-1\")"), result);
      }

      [Test]
      [Description("Issue 238, If charset parameter contains double quotes, the string isn't parsed properly.")]
      public void TestFetchCharsetInQuotesWithoutQuotesWithSpace()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address,
            "From: test@test.com\r\n" +
            "Content-Type: text/plain; charset = iso-8859-1 \r\n" +
            "\r\n" +
            "Test\r\n");

         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");
         string result = sim.Fetch("1 BODYSTRUCTURE");
         sim.Disconnect();

         Assert.IsTrue(result.Contains("(\"CHARSET\" \"iso-8859-1\")"), result);
      }

      [Test]
      [Description("Issue 238, If charset parameter contains double quotes, the string isn't parsed properly.")]
      public void TestFetchCharsetInQuotesWithoutQuotesWithoutSpace()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSendRaw(account.Address, account.Address,
            "From: test@test.com\r\n" +
            "Content-Type: text/plain; charset=iso-8859-1 \r\n" +
            "\r\n" +
            "Test\r\n");

         IMAPSimulator.AssertMessageCount(account.Address, "test", "Inbox", 1);

         IMAPSimulator sim = new IMAPSimulator(account.Address, "test", "Inbox");
         string result = sim.Fetch("1 BODYSTRUCTURE");
         sim.Disconnect();

         Assert.IsTrue(result.Contains("(\"CHARSET\" \"iso-8859-1\")"), result);
      }
   }


}
