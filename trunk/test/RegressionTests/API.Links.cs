// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.IO;
using System.Threading;
using System.Net.Mail;

namespace UnitTest.API
{
    [TestFixture]
   public class Links : TestFixtureBase
    {
        hMailServer.Links _links;

        [SetUp]
        public new void SetUp()
        {
            _links = _application.Links;
        }

        [Test]
        public void TestDomainLink()
        {
            Assert.AreEqual(_domain.Name, _links.get_Domain(_domain.ID).Name);
        }

        [Test]
        public void TestAccountLink()
        {
            hMailServer.Account account = 
                SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test", "test");

            Assert.AreEqual(account.Address, _links.get_Account(account.ID).Address);
        }

        [Test]
        public void TestAliasLink()
        {
            hMailServer.Alias alias =
                SingletonProvider<Utilities>.Instance.AddAlias(_domain, "mytest", "test2");

            Assert.AreEqual(alias.Value, _links.get_Alias(alias.ID).Value);
        }

        [Test]
        public void TestDistributionListLink()
        {
            List<string> recipients = new List<string>();
            recipients.Add("Vaffe");
            recipients.Add("Baffe");
            recipients.Add("Laffe");

            hMailServer.DistributionList list =
                SingletonProvider<Utilities>.Instance.AddDistributionList(_domain, "mytest",  recipients);

            Assert.AreEqual(recipients.Count, _links.get_DistributionList(list.ID).Recipients.Count);
        }
    }
}
