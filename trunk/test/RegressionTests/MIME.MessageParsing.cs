using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.MIME
{
    [TestFixture]
    public class MessageParsing : TestFixtureBase
    {
        [Test]
        [Description("Test to parse a multi-part message with no text in the main body directly after the header.")]
        public void TestParseMultipartNoBody()
        {
            hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "search@test.com", "test");
            string body = Utilities.GetResource("Messages.MultipartMessageWithNoMainBodyText.txt");
            SMTPClientSimulator.StaticSendRaw(account.Address, account.Address, body);

            POP3Simulator.AssertMessageCount(account.Address, "test", 1);

            var imapSim = new IMAPSimulator("search@test.com", "test", "INBOX");
            var result = imapSim.Fetch("1 (BODY.PEEK[HEADER] BODY.PEEK[TEXT])");

            imapSim.Logout();
        }
    }
}
