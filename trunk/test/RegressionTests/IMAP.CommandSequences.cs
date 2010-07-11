// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest
{
    [TestFixture]
    public class CommandSequences : TestFixtureBase
    {
        [Test]
        public void TestBatchOfCommands()
        {
           hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "batch@test.com", "test");

           IMAPSimulator oSimulator = new IMAPSimulator();
           string sWelcomeMessage = oSimulator.Connect();
           oSimulator.Logon(account.Address, "test");

           string commandSequence = "";
           for (int i = 0; i < 200; i++)
           {
              commandSequence += "A" + i.ToString() + " SELECT INBOX\r\n";
           }
           commandSequence = commandSequence.TrimEnd("\r\n".ToCharArray());

           string result = oSimulator.Send(commandSequence);
           Assert.IsFalse(result.StartsWith("* BYE"));

           oSimulator.Disconnect();

           sWelcomeMessage = oSimulator.Connect();
           oSimulator.Logon(account.Address, "test");
           commandSequence = "";
           for (int i = 0; i < 500; i++)
           {
              commandSequence += "A" + i.ToString() + " SELECT INBOX\r\n";
           }
           commandSequence = commandSequence.TrimEnd("\r\n".ToCharArray());

           result = oSimulator.Send(commandSequence);
           Assert.IsFalse(result.StartsWith("* BYE Excessive number of buffered commands"));
           oSimulator.Disconnect();
        }

       [Test]
       public void TestLongCommand()
       {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "batch@test.com", "test");

          IMAPSimulator oSimulator = new IMAPSimulator();
          string sWelcomeMessage = oSimulator.Connect();
          oSimulator.Logon(account.Address, "test");

          StringBuilder sb = new StringBuilder();
          
          for (int i = 0; i < 240000; i++)
          {
             sb.Append("A");
          }

          string result = oSimulator.Send("A01 " + sb.ToString());
          Assert.IsTrue(result.Length == 0 || result.StartsWith("A01"));
       }
     }


}
