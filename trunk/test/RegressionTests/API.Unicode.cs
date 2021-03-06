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
   public class Unicode : TestFixtureBase
	{
      [Test]
      public void TestJapaneseAttachments()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string attachmentName = "本本本.zip";

         string filename = Path.Combine(Path.GetTempPath(), attachmentName);
         File.WriteAllText(filename, "tjena moss");

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.From = "Test";
         message.FromAddress = account.Address;
         message.Body = "hejsan";
         message.Attachments.Add(filename);
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

         hMailServer.Message downloadedMessage = account.IMAPFolders[0].Messages[0];
         Assert.AreNotEqual(0, downloadedMessage.Attachments.Count);
         hMailServer.Attachment attachment = downloadedMessage.Attachments[0];
         Assert.AreEqual(attachmentName, attachment.Filename);
      }

      [Test]
      public void TestSwedishAndChineseCombination()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string swedishAndChinese = "ÅÄÖ汉语";
         string attachmentName = swedishAndChinese + ".zip";

         string filename = Path.Combine(Path.GetTempPath(), attachmentName);
         File.WriteAllText(filename, swedishAndChinese);

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.From = "Test";
         message.FromAddress = account.Address;
         message.Body = swedishAndChinese;
         message.Attachments.Add(filename);
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

         hMailServer.Message downloadedMessage = account.IMAPFolders[0].Messages[0];
         Assert.AreNotEqual(0, downloadedMessage.Attachments.Count);
         hMailServer.Attachment attachment = downloadedMessage.Attachments[0];
         Assert.AreEqual(attachmentName, attachment.Filename);

         Assert.AreEqual(swedishAndChinese + Environment.NewLine, downloadedMessage.Body);
      }

      [Test]
      public void TestDanishSubject()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string croatianAndDanish = "ʒʥʨPiskefløde";

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.From = "Test";
         message.FromAddress = account.Address;
         message.Subject = croatianAndDanish;
         message.Body = "hej";
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);
         
         hMailServer.Message downloadedMessage = account.IMAPFolders[0].Messages[0];
         Assert.AreEqual(croatianAndDanish, downloadedMessage.Subject);
      }

      [Test]
      public void TestEncodingOfStringIncludingSpace()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.From = "Test";
         message.FromAddress = account.Address;
         message.Subject = "test mit encoding und deutc ü...";
         message.Body = "Test";
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         string [] lines = messageText.Split(Environment.NewLine.ToCharArray());

         foreach (string line in lines)
         {
            if (line.ToLower().StartsWith("subject: "))
            {
               string subject = line.Substring("subject: ".Length + 1);

               // encoded part should not contain space.
               Assert.IsFalse(subject.Contains(" "));

               break;
            }

         }

      }


      [Test]
      public void TestEncodingOfStringIncludingSpaceNET()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         MailMessage mail = new MailMessage();
         mail.From = new System.Net.Mail.MailAddress(account.Address);
         mail.To.Add(account.Address);
         mail.Subject = "test mit encoding und deutc ü...";
         mail.Body = "Test";
         mail.BodyEncoding = System.Text.Encoding.GetEncoding(1252);
         mail.SubjectEncoding = System.Text.Encoding.GetEncoding(1252);
         SmtpClient oClient = new SmtpClient("localhost", 25);
         oClient.Send(mail);

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         string[] lines = messageText.Split(Environment.NewLine.ToCharArray());

         foreach (string line in lines)
         {
            if (line.ToLower().StartsWith("subject: "))
            {
               string subject = line.Substring("subject: ".Length + 1);

               // encoded part should not contain space.
               Assert.IsTrue(subject.Contains(" "));

               break;
            }

         }

      }

      [Test]
      public void TestMultipleLanguages()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string manyLanguages = "中文åäöん文t͡ɬɪŋ";

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.From = manyLanguages;
         message.FromAddress = account.Address;
         message.Subject = manyLanguages;
         message.Body = manyLanguages;
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

         hMailServer.Message downloadedMessage = account.IMAPFolders[0].Messages[0];
         Assert.AreEqual(manyLanguages, downloadedMessage.Subject);
         Assert.AreEqual(manyLanguages, downloadedMessage.From);
         Assert.AreEqual(manyLanguages + Environment.NewLine, downloadedMessage.Body);
      }


      [Test]
      public void TestModifyBodyWithExistingAttachments()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         string swedish = "abc.zip";
         string attachmentName = swedish + ".zip";
         string filename = Path.Combine(Path.GetTempPath(), attachmentName);
         File.WriteAllText(filename, swedish);


         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("test", account.Address);
         message.Attachments.Add(filename);
         message.From = swedish;
         message.FromAddress = account.Address;
         message.Subject = swedish;
         message.Body = "";
         message.Save();

         Utilities.AssertMessageExistsInFolder(account.IMAPFolders[0], 1);

         hMailServer.Message downloadedMessage = account.IMAPFolders[0].Messages[0];

         downloadedMessage.Body = "Test";
         downloadedMessage.Save();
      }

      [Test]
      [Description("Test case for issue 164")]
      public void TestFolderAdd()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

          string folderName = "åäö";
          hMailServer.IMAPFolder folder = account.IMAPFolders.Add(folderName);
          hMailServer.IMAPFolder folder2 = account.IMAPFolders.get_ItemByName(folderName);
          Assert.AreEqual(folderName, folder2.Name);
      }

      [Test]
      [Description("Issue 169 - Unicode subject not decoded properly.")]
      public void TestDecodeSpecificMessage()
      {
          string message = "Return-Path:" +Environment.NewLine +
                           "Received: from host ([1.2.3.4])" +Environment.NewLine +
                           "X-Facebook: from zuckmail" +Environment.NewLine +
                           "by localhost.localdomain with local (ZuckMail);" +Environment.NewLine +
                           "Date: Wed, 3 Dec 2008 06:14:37 -0800" +Environment.NewLine +
                           "To: someone@example.com" +Environment.NewLine +
                           "From: Facebook" +Environment.NewLine +
                           "Reply-to: Facebook" +Environment.NewLine +
                           "Subject: =?UTF-8?Q?V=C3=A4nligen_=C3=A5terst=C3=A4ll_dina_inst=C3=A4llningar_f=C3?=" +Environment.NewLine +
                           "    =?UTF-8?Q?=B6r_meddelanden_via_e-post.?=" +Environment.NewLine +
                           "Message-ID:" +Environment.NewLine +
                           "X-Priority: 3" +Environment.NewLine +
                           "X-Mailer: ZuckMail [version 1.00]" +Environment.NewLine +
                           "Errors-To: root+monkeymonkey@facebookmail.com" +Environment.NewLine +
                           "MIME-Version: 1.0" +Environment.NewLine +
                           "Content-Type: text/plain; charset=\"UTF-8\"" +Environment.NewLine +
                           "Content-Transfer-Encoding: quoted-printable" + Environment.NewLine +
                           "" +Environment.NewLine +
                           "Dina inst=C3=A4llningar f=C3=B6r meddelanden via e-post har tyv=C3=A4rr g=" +Environment.NewLine +
                           "=C3=A5tt f=C3=B6rlorade. Vi beklagar det intr=C3=A4ffade.G=C3=" +Environment.NewLine +
                           "=A5 till http://www.facebook.com/editaccount.php?notifications f=C3=B6r a=" +Environment.NewLine +
                           "tt =C3=A5terst=C3=A4lla dina inst=C3=A4llningar.Tack!Facebook-grupp=" +Environment.NewLine +
                           "en." +Environment.NewLine;

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "decode@test.com", "test");

          SMTPClientSimulator.StaticSendRaw("test@test.com", account.Address, message);

          POP3Simulator.AssertMessageCount(account.Address, "test", 1);

          hMailServer.Message apiMessage = account.Messages[0];

          Assert.AreEqual("Vänligen återställ dina inställningar för meddelanden via e-post.", apiMessage.Subject);
          Assert.IsTrue(apiMessage.Body.StartsWith("Dina inställningar för meddelanden via e-post har tyvärr gått förlorade."));
                              
      }

      [Test]
      [Description("Test of issue 176. Underscore in body disappears")]
      public void TestUnderscoreInBody()
      {
          string body = "underscore_in_body\r\n";

          hMailServer.Message message = new hMailServer.Message();
          message.Body = body;
          Assert.AreEqual(body, message.Body);
      }

      [Test]
      [Description("Test encode word. Test that the word is actually encoded and not just stored as unicode in the file.")]
      public void TestEncodeWord()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode@test.com", "test");
        
          string croatianAndDanish = "ʒʥʨPiskefløde";
          hMailServer.Message message = new hMailServer.Message();
          message.Subject = croatianAndDanish;
          message.AddRecipient("", account.Address);
          message.Save();

          POP3Simulator.AssertMessageCount(account.Address, "test", 1);

          hMailServer.Message apiMessage = account.Messages[0];

          Assert.AreEqual(apiMessage.Subject, croatianAndDanish);
          string fileContents = File.ReadAllText(apiMessage.Filename);
          Assert.IsFalse(fileContents.Contains(croatianAndDanish));

      }

      [Test]
      [Description("Issue 233. Test non-latin characters in recipient name." +
                   "The problem was that spaces weren't encoded. This had the effect that" +
                   "they were removed in the recipients email client.")]
      public void NonLatinCharactersInRecipientNameResultsInNoSpaces()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode@test.com", "test");

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("Tестов Тест Тестостеронович", account.Address);
         message.Subject = "Test";
         message.Charset = "utf-8";
         message.Body = "Test body.";
         message.Save();

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         // Important:
         //   RFC 2047: http://www.faqs.org/rfcs/rfc2047.html
         //   The notation of RFC 822 is used, with the exception that white space
         //   characters MUST NOT appear between components of an 'encoded-word'.
         // 
         //   Also, there should be a space separating the encoded word with the following
         //   non-encoded word.
         Assert.IsTrue(messageText.Contains("To: \"=?utf-8?B?VNC10YHRgtC+0LIg0KLQtdGB0YIg0KLQtdGB0YLQvtGB0YLQtdGA0L7QvdC+?=\r\n =?utf-8?B?0LLQuNGH?=\" <encode@test.com>"));
      }

      [Test]
      [Description("Issue 233. Test non-latin characters in recipient name." +
                   "The problem was that spaces weren't encoded. This had the effect that" +
                   "they were removed in the recipients email client.")]
      public void NonLatinCharactersInRecipientNameResultsInBoxesInThunderbird()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode3@test.com", "test");

         hMailServer.Message message = new hMailServer.Message();
         //message.AddRecipient("Тестов Тест ТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостероновичТестостеронович", account.Address);
         message.AddRecipient("ТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероноТестовТестТестостероно", account.Address);
         message.Subject = "Test";
         message.Charset = "utf-8";
         message.Body = "Test body.";
         message.Save();

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         // Important:
         //   RFC 2047: http://www.faqs.org/rfcs/rfc2047.html
         //   The notation of RFC 822 is used, with the exception that white space
         //   characters MUST NOT appear between components of an 'encoded-word'.
         //
         //   Also, there should be a space separating the encoded word with the following
         //   non-encoded word.


          string match = 
              "To: \"=?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n"+
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\r\n" +
             " =?utf-8?B?0KLQtdGB0YLQvtCy0KLQtdGB0YLQotC10YHRgtC+0YHRgtC10YDQvtC90L4=?=\" <encode3@test.com>";
          

         Assert.IsTrue(messageText.Contains(match));

      }


      [Test]
      public void SingleLatinCharacterRecipient()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode3@test.com", "test");

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("Ö", account.Address);
         message.Charset = "utf-8";
         message.Body = "Test body.";
         message.Save();

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         Assert.IsTrue(messageText.Contains("To: \"=?utf-8?B?w5Y=?=\" <encode3@test.com>"));
      }

      [Test]
      [Description("Issue 233. Test non-latin characters in recipient name." +
                   "The problem was that spaces weren't encoded. This had the effect that" +
                   "they were removed in the recipients email client.")]
      public void TestMostlyLatinCharacters()
      {
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode@test.com", "test");

         hMailServer.Message message = new hMailServer.Message();
         message.AddRecipient("Test Recipient: Тест", account.Address);
         message.Subject = "Test Subject: Тест";
         message.Charset = "utf-8";
         message.Body = "Test body.";
         message.Save();

         string messageText = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         // Important:
         //   RFC 2047: http://www.faqs.org/rfcs/rfc2047.html
         //   The notation of RFC 822 is used, with the exception that white space
         //   characters MUST NOT appear between components of an 'encoded-word'.
         // 
         //   Also, there should be a space separating the encoded word with the following
         //   non-encoded word.
         Assert.IsTrue(messageText.Contains("To: \"=?utf-8?B?VGVzdCBSZWNpcGllbnQ6INCi0LXRgdGC?=\" <encode@test.com>"));
      }



      [Test]
      public void SwedishCharactersInBody()
      {
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "encode3@test.com", "test");

          hMailServer.Message message = new hMailServer.Message();
          message.AddRecipient("Ö", account.Address);
          message.Charset = "utf-8";
          message.Body = "Test ÅÄÖ Test.";

          string body = message.Body;
          Assert.IsTrue(body.Contains("Test ÅÄÖ Test."));
      }
	}
}
