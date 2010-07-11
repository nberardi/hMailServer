// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Persistence
{
   [TestFixture]
   public class Basics : TestFixtureBase
   {
      [Test]
      public void TestDomain()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
         _domain = SingletonProvider<Utilities>.Instance.AddDomain(domains, "t'est2.com");
         if (_domain.ID == 0)
            throw new Exception("Domain not properly saved");

         _domain.Delete();
      }

      [Test]
      public void TestGroup()
      {
         hMailServer.Groups groups = _application.Settings.Groups;
         hMailServer.Group group = groups.Add();
         group.Name = "MyGroup";
         group.Save();

         if (group.ID == 0)
            throw new Exception("Group not properly saved");

         _application.Settings.Groups.DeleteByDBID(group.ID);

         if (groups.Count != 0)
            throw new Exception("Group not properly deleted");
      }

      [Test]
      public void TestGroupMember()
      {
         hMailServer.Groups groups = _application.Settings.Groups;

         hMailServer.Group group = groups.Add();
         group.Name = "MyGroup";
         group.Save();

         if (group.ID == 0)
            throw new Exception("Group not properly saved");

         hMailServer.GroupMember member = group.Members.Add();
         member.AccountID = 1;
         member.Save();

         if (member.ID == 0)
            throw new Exception("Group member not properly saved");
      }


      [Test]
      public void TestBlockedAttachment()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.BlockedAttachment attachment = oSettings.AntiVirus.BlockedAttachments.Add();

         attachment.Description = "Some description";
         attachment.Wildcard = "*.some";
         attachment.Save();

         if (attachment.ID == 0)
            throw new Exception("Blocked attachment not properly saved");

         oSettings.AntiVirus.BlockedAttachments.DeleteByDBID(attachment.ID);
      }



      [Test]
      public void TestRoute()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.Route route = oSettings.Routes.Add();

         route.DomainName = "myroute.com";
         route.TargetSMTPHost = "somehost.com";
         route.TargetSMTPPort = 25;

         route.Save();

         if (route.ID == 0)
            throw new Exception("Route not saved properly");

         oSettings.Routes.DeleteByDBID(route.ID);
      }



      [Test]
      public void TestSSLCertificate()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.SSLCertificate sslcert = oSettings.SSLCertificates.Add();

         sslcert.CertificateFile = "somefile.dat";
         sslcert.PrivateKeyFile = "someprivatefile.dat";
         sslcert.Save();

         if (sslcert.ID == 0)
            throw new Exception("SSL certificate not saved properly");

         oSettings.SSLCertificates.DeleteByDBID(sslcert.ID);
      }

      [Test]
      public void TestSURBLServer()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.SURBLServer surblServer = oSettings.AntiSpam.SURBLServers.Add();

         surblServer.DNSHost = "somehost.com";
         surblServer.RejectMessage = "somerejectmessage";
         surblServer.Score = 5;

         surblServer.Save();

         if (surblServer.ID == 0)
            throw new Exception("SURBL server not saved properly");

         oSettings.AntiSpam.SURBLServers.DeleteByDBID(surblServer.ID);
      }

      [Test]
      public void TestDNSBlackList()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.DNSBlackList dnsBlackList = oSettings.AntiSpam.DNSBlackLists.Add();

         dnsBlackList.DNSHost = "somehost.com";
         dnsBlackList.RejectMessage = "somerejectmessage";
         dnsBlackList.Score = 5;

         dnsBlackList.Save();

         if (dnsBlackList.ID == 0)
            throw new Exception("DNS blacklist not saved properly");

         oSettings.AntiSpam.DNSBlackLists.DeleteByDBID(dnsBlackList.ID);
      }

      [Test]
      public void TestWhiteListAddress()
      {
         hMailServer.Settings oSettings = SingletonProvider<Utilities>.Instance.GetApp().Settings;
         hMailServer.WhiteListAddress whiteAddress = oSettings.AntiSpam.WhiteListAddresses.Add();

         whiteAddress.Description = "My description of this entry";
         whiteAddress.EmailAddress = "myaddress@dummy-example.com";
         whiteAddress.Save();

         if (whiteAddress.ID == 0)
            throw new Exception("White list address not saved properly");

         oSettings.AntiSpam.WhiteListAddresses.DeleteByDBID(whiteAddress.ID);
      }


      [Test]
      public void TestAccount()
      {
         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "perste'ster@test.com", "test");
         if (oAccount1.ID == 0)
            throw new Exception("Account not properly saved");

         _domain.Accounts.DeleteByDBID(oAccount1.ID);
      }

      [Test]
      public void TestAlias()
      {
         hMailServer.Alias oAlias = SingletonProvider<Utilities>.Instance.AddAlias(_domain, "fr'om@test.com", "to@t'st.com");
         if (oAlias.ID == 0)
            throw new Exception("Account not properly saved");

         _domain.Aliases.DeleteByDBID(oAlias.ID);
      }


      [Test]
      public void TestDistributionList()
      {
         hMailServer.DistributionList oList = _domain.DistributionLists.Add();
         oList.Address = "persis'tent-test-list@test.com";
         oList.Active = true;
         oList.Save();

         hMailServer.DistributionListRecipient oRecipient = oList.Recipients.Add();
         oRecipient.RecipientAddress = "test@te'st.com";
         oRecipient.Save();

         oRecipient.RecipientAddress = "tes't2@test.com";
         oRecipient.Save();
         oList.Delete();

      }

      [Test]
      public void TestFetchAccount()
      {


         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "fatester@test.com", "test");

         hMailServer.FetchAccount oFA = oAccount1.FetchAccounts.Add();
         oFA.Name = "test";
         oFA.Save();

         if (oFA.ID == 0)
            throw new Exception("Fetch account could not be saved");

         oAccount1.FetchAccounts.Delete(0);
      }

      [Test]
      public void TestDomainRenaming()
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
         _domain = SingletonProvider<Utilities>.Instance.AddDomain(domains, "test2.com");

         // Add a few accounts
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test1@test2.com", "t1");
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2@test2.com", "t1");
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test3@test2.com", "t1");
         SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test2.com@test2.com", "t1");
         
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias1@test2.com", "t1");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias2@test2.com", "t1");
         SingletonProvider<Utilities>.Instance.AddAlias(_domain, "alias3@test2.com", "t1");

         List<string> list = new List<string>();
         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list1@test2.com", list);
         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list2@test2.com", list);
         SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "list3@test2.com", list);

         _domain.Name = "test3.com";
         _domain.Save();

         Assert.IsNotNull(_domain.Accounts.get_ItemByAddress("test1@test3.com"));
         Assert.IsNotNull(_domain.Accounts.get_ItemByAddress("test2@test3.com"));
         Assert.IsNotNull(_domain.Accounts.get_ItemByAddress("test3@test3.com"));
         Assert.IsNotNull(_domain.Accounts.get_ItemByAddress("test2.com@test3.com"));

         Assert.IsNotNull(_domain.Aliases.get_ItemByName("alias1@test3.com"));
         Assert.IsNotNull(_domain.Aliases.get_ItemByName("alias2@test3.com"));
         Assert.IsNotNull(_domain.Aliases.get_ItemByName("alias3@test3.com"));

         Assert.IsNotNull(_domain.DistributionLists.get_ItemByAddress("list1@test3.com"));
         Assert.IsNotNull(_domain.DistributionLists.get_ItemByAddress("list2@test3.com"));
         Assert.IsNotNull(_domain.DistributionLists.get_ItemByAddress("list3@test3.com"));
      }

      [Test]
      public void TestCaseInsensitivtyAccount()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "lowercase@test.com", "test");

         SMTPSimulator oSMTP = new SMTPSimulator();
         string upperCase = testAccount.Address.ToUpper();
         Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", upperCase, "test mail", "test body"));

         POP3Simulator.AssertMessageCount("lowercase@test.com", "test", 1);
      }

      [Test]
      public void TestCaseInsensitivtyAlias()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "lowercase@test.com", "test");
         hMailServer.Alias testAlias = SingletonProvider<Utilities>.Instance.AddAlias(_domain, "sometext@test.com", "LowerCase@test.com");

         SMTPSimulator oSMTP = new SMTPSimulator();
         string upperCase = testAlias.Name.ToUpper();
         Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", upperCase, "test mail", "test body"));

         POP3Simulator.AssertMessageCount("lowercase@test.com", "test", 1);
      }

      [Test]
      public void TestCaseInsensitivtyList()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "lowercase@test.com", "test");
         
         List<string> recipients = new List<string>();
         recipients.Add(testAccount.Address);

         hMailServer.DistributionList list = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "myList@test.com", recipients);

         SMTPSimulator oSMTP = new SMTPSimulator();
         string upperCase = list.Address.ToUpper();
         Assert.IsTrue(oSMTP.Send("someone@dummy-example.com", upperCase, "test mail", "test body"));

         POP3Simulator.AssertMessageCount("lowercase@test.com", "test", 1);
      }

      [Test]
      public void TestCaseInsensitivtyListRecipient()
      {
         hMailServer.Account testAccount = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "lowercase@test.com", "test");

         List<string> recipients = new List<string>();
         recipients.Add(testAccount.Address);

         hMailServer.DistributionList list = SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "myList@test.com", recipients);

         hMailServer.DistributionListRecipient recipient = list.Recipients[0];
         recipient.RecipientAddress = testAccount.Address.ToUpper();

         recipient.Delete();
      }


      [Test]
      public void TestIncomingRelays()
      {
          hMailServer.IncomingRelays incomingRelays = _application.Settings.IncomingRelays;
          Assert.AreEqual(0, incomingRelays.Count);

          hMailServer.IncomingRelay incomingRelay = incomingRelays.Add();
          incomingRelay.Name = "TestRelay";
          incomingRelay.LowerIP = "1.2.1.1";
          incomingRelay.UpperIP = "2.1.2.1";
          incomingRelay.Save();

          // Check that it was saved.
          Assert.AreNotEqual(0, incomingRelay.ID);

          // Confirm that settings were saved properly.
          incomingRelays.Refresh();
          hMailServer.IncomingRelay incomingRelay2 = incomingRelays.get_ItemByDBID(incomingRelay.ID);
          Assert.AreEqual(incomingRelay.ID, incomingRelay2.ID);
          Assert.AreEqual(incomingRelay.Name, incomingRelay2.Name);
          Assert.AreEqual(incomingRelay.LowerIP, incomingRelay2.LowerIP);
          Assert.AreEqual(incomingRelay.UpperIP, incomingRelay2.UpperIP);
         
          // Delete it again.
          incomingRelays.Delete(0);

          Assert.AreEqual(0, incomingRelays.Count);
      }
   }
}
