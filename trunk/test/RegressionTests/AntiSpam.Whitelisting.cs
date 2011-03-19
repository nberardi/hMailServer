// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.AntiSpam
{
   [TestFixture]
   class WhiteListing : TestFixtureBase
   {
      hMailServer.AntiSpam _antiSpam;
      
      [SetUp]
      public new void SetUp()
      {
         _antiSpam = _settings.AntiSpam;
         
         // We should always mark messages as spam.
         _antiSpam.SpamDeleteThreshold = 5;
         _antiSpam.SpamMarkThreshold = 2;

         _antiSpam.AddHeaderReason = true;
         _antiSpam.AddHeaderSpam = true;
         _antiSpam.PrependSubject = true;
         _antiSpam.PrependSubjectText = "ThisIsSpam";

         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "whitelist@test.com", "test");
      }

      [Test]
      public void TestEnabled()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;
         hMailServer.WhiteListAddress obAddress = obAddresses.Add();

         obAddress.EmailAddress = "whitelist@microsoft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         obAddresses.DeleteByDBID(obAddress.ID);

         // Check that it's detected as spam again.
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 1);
      }

      [Test]
      public void TestHelo()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;
         hMailServer.WhiteListAddress obAddress = obAddresses.Add();

         obAddress.EmailAddress = "whitelist@microsoft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Test that we can send spam now.
         // Create a test account
         // Fetch the default domain
         ;
         _antiSpam.CheckHostInHelo = true;
         _antiSpam.CheckHostInHeloScore = 125;

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         SMTPClientSimulator oSMTP = new SMTPClientSimulator();

         Assert.IsTrue(oSMTP.Send("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         obAddresses.DeleteByDBID(obAddress.ID);

         // Check that it's deteceted as spam again.
         Assert.IsFalse(oSMTP.Send("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         
         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 1);
      }

      [Test]
      public void TestWildcardStar()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         obAddress.EmailAddress = "white*@microsoft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("blacklist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsTrue(SMTPClientSimulator.StaticSend("whitesomething@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("blacksomething@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 2);
      }

      [Test]
      public void TestWildcardQuestionMark()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         obAddress.EmailAddress = "whitelist@?icrosoft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whitelist@icrosoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsTrue(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whitelist@icrosoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 2);
      }

      [Test]
      public void TestWildcardEscapedCharacters()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         obAddress.EmailAddress = "white%list@micro_soft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("white%list@micro_soft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whiteAlist@micro_soft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whiteAlist@microEsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 1);
      }


      [Test]
      public void TestWildcardSingleQuote()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         obAddress.EmailAddress = "white'list@micro_soft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("white'list@micro_soft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whitelist@micro_soft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 1);
      }

      [Test]
      public void TestWildcardEscapeChar()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         obAddress.EmailAddress = "white/list@microsoft.com";
         obAddress.LowerIPAddress = "0.0.0.0";
         obAddress.UpperIPAddress = "255.255.255.255";
         obAddress.Description = "Test";
         obAddress.Save();

         // Enable SURBL.
         hMailServer.SURBLServer oSURBLServer = _antiSpam.SURBLServers[0];
         oSURBLServer.Active = true;
         oSURBLServer.Score = 5;
         oSURBLServer.Save();

         // Send a messages to this account.
         Assert.IsTrue(SMTPClientSimulator.StaticSend("white/list@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));
         Assert.IsFalse(SMTPClientSimulator.StaticSend("whitelist@microsoft.com", "whitelist@test.com", "SURBL-Match", "This is a test message with a SURBL url: -> http://surbl-org-permanent-test-point.com/ <-"));

         POP3Simulator.AssertMessageCount("whitelist@test.com", "test", 1);
      }

      [Test]
      public void TestFormatVariations()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.WhiteListAddresses obAddresses = _antiSpam.WhiteListAddresses;

         hMailServer.WhiteListAddress obAddress = obAddresses.Add();
         
         string address = @"A%B/C\D_@microsoft.com";
         obAddress.EmailAddress = address;
         Assert.AreEqual(address, obAddress.EmailAddress);

         address = @"\%%%__\_@microsoft.com";
         obAddress.EmailAddress = address;
         Assert.AreEqual(address, obAddress.EmailAddress);
         
      }
   }
}
