// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Features
{
   [TestFixture]
   public class Signatures
   {
      hMailServer.Domain domain;

      [SetUp]
      public void SetUp()
      {
         domain = SingletonProvider<Utilities>.Instance.DoBasicSetup();


      }

      [Test]
      public void TestSignature()
      {

         domain.SignatureEnabled = true;
         domain.AddSignaturesToLocalMail = true;

         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(domain, "signature@test.com", "test");

         oAccount1.SignatureEnabled = true;
         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         string sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         if (sMessageData.IndexOf("PlainTextSignature") > 0)
            throw new Exception("Found exception which should not be there");

         oAccount1.SignaturePlainText = "PlainTextSignature";
         oAccount1.Save();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 2", "Test of signature - Body");


         sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         if (sMessageData.IndexOf("PlainTextSignature") < 0)
            throw new Exception("Did not find expected signature");

         // Turn off signature again
         oAccount1.SignatureEnabled = false;
         oAccount1.Save();

         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 2", "Test of signature - Body");
         sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

         if (sMessageData.IndexOf("PlainTextSignature") > 0)
            throw new Exception("Found signature even though there shouldn't be any");
      }

      /// <summary>
      ///  Check that domain signature is added to mail sent from local domain but non-existent account.
      ///  This may be the case if an email is sent for example from an alias address.
      /// </summary>
      [Test]
      public void TestSignatureLocalDomainNonExistantAccount()
      {
         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "MyDomainSignature";
         domain.AddSignaturesToLocalMail = true;
         domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "recipient@test.com", "test");

         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("nonexistant@" + domain.Name, account.Address, "SignatureTest", "SignaturerTestBody");

         string messageData = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         Assert.IsTrue(messageData.Contains(domain.SignaturePlainText));

      }

      /// <summary>
      /// Check that domain signature is not added to message sent from external domain.
      /// </summary>
      [Test]
      public void TestSignatureExternalDomain()
      {
         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "MyDomainSignature";
         domain.AddSignaturesToLocalMail = true;
         domain.Save();

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "recipient@test.com", "test");

         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send("nonexistant@dummy-example.com", account.Address, "SignatureTest", "SignaturerTestBody");

         string messageData = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

         Assert.IsFalse(messageData.Contains(domain.SignaturePlainText));
      }


      /// <summary>
      ///  Test different setups for domain signature.
      /// </summary>
      [Test]
      public void TestDomainSignature()
      {
         POP3Simulator oPOP3 = new POP3Simulator();

         domain.SignatureEnabled = true;
         domain.AddSignaturesToLocalMail = true;

         hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(domain, "domainsignature@test.com", "test");
         oAccount1.SignatureEnabled = true;
         oAccount1.SignaturePlainText = "PlainTextSignature";
         oAccount1.Save();


         SMTPSimulator oSMTP = new SMTPSimulator();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         string sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("PlainTextSignature") <= 0)
            throw new Exception("Did not find signature");


         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "DomainSignature";
         domain.SignatureMethod = hMailServer.eDomainSignatureMethod.eSMAppendToAccountSignature;
         domain.Save();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("PlainTextSignature") <= 0 ||
             sMessageContents.IndexOf("DomainSignature") <= 0)
            throw new Exception("Did not find signature");


         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "DomainSignature";
         domain.SignatureMethod = hMailServer.eDomainSignatureMethod.eSMOverwriteAccountSignature;
         domain.Save();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("PlainTextSignature") >= 0 ||
             sMessageContents.IndexOf("DomainSignature") <= 0)
            throw new Exception("Did not find signature");


         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "DomainSignature";
         domain.SignatureMethod = hMailServer.eDomainSignatureMethod.eSMSetIfNotSpecifiedInAccount;
         domain.Save();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("DomainSignature") >= 0)
            throw new Exception("Found incorrect signature.");


         domain.SignatureEnabled = true;
         domain.SignaturePlainText = "DomainSignature";
         domain.SignatureMethod = hMailServer.eDomainSignatureMethod.eSMSetIfNotSpecifiedInAccount;
         domain.Save();
         oAccount1.SignaturePlainText = "";
         oAccount1.Save();

         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("DomainSignature") <= 0)
            throw new Exception("Found incorrect signature.");


         domain.AddSignaturesToLocalMail = false;
         domain.Save();
         oAccount1.SignaturePlainText = "PlainTextSignature";
         oAccount1.Save();
         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("PlainTextSignature") > 0)
            throw new Exception("Found incorrect signature.");

         domain.AddSignaturesToLocalMail = true;
         domain.Save();

         oSMTP.Send(oAccount1.Address, oAccount1.Address, "Test of signature, 1", "Test of signature - Body");

         sMessageContents = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");
         if (sMessageContents.IndexOf("PlainTextSignature") <= 0)
            throw new Exception("Found incorrect signature.");
      }

      [Test]
      public void TestAccountSignatureMacro()
      {
          domain.SignatureEnabled = true;
          domain.AddSignaturesToLocalMail = true;

          hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(domain, "signature@test.com", "test");
          oAccount1.PersonFirstName = "Martin";
          oAccount1.PersonLastName = "Knafve";
          oAccount1.SignatureEnabled = true;
          oAccount1.SignaturePlainText = "Regards %User.FirstName% %User.Lastname%";
          oAccount1.Save();

          SMTPSimulator.StaticSend(oAccount1.Address, oAccount1.Address, "Test of signature, 2", "Test of signature - Body");

          string sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

          Assert.IsTrue(sMessageData.Contains("Regards Martin Knafve"));

      }

      [Test]
      public void TestDomainSignatureMacro()
      {
          domain.SignatureEnabled = true;
          domain.AddSignaturesToLocalMail = true;
          domain.SignaturePlainText = "Regards %User.Lastname%, %User.FirstName%";
          domain.SignatureMethod = hMailServer.eDomainSignatureMethod.eSMSetIfNotSpecifiedInAccount;
          domain.Save();

          hMailServer.Account oAccount1 = SingletonProvider<Utilities>.Instance.AddAccount(domain, "signature@test.com", "test");
          oAccount1.PersonFirstName = "Martin";
          oAccount1.PersonLastName = "Knafve";
          oAccount1.Save();

          SMTPSimulator.StaticSend(oAccount1.Address, oAccount1.Address, "Test of signature, 2", "Test of signature - Body");

          string sMessageData = POP3Simulator.AssertGetFirstMessageText(oAccount1.Address, "test");

          Assert.IsTrue(sMessageData.Contains("Regards Knafve, Martin"));

      }

      /// <summary>
      ///  Test a combination of external accounts and signature macros. If this test fails,
      ///  something is terrible broken with the signature functionality...
      /// </summary>
      [Test]
      public void TestSignatureMacroLocalDomainNonExistantAccount()
      {
          domain.SignatureEnabled = true;
          domain.SignaturePlainText = "MyDomainSignature %User.FirstName%";
          domain.AddSignaturesToLocalMail = true;
          domain.Save();

          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(domain, "recipient@test.com", "test");
          account.PersonFirstName = "Martin";

          SMTPSimulator oSMTP = new SMTPSimulator();
          oSMTP.Send("nonexistant@" + domain.Name, account.Address, "SignatureTest", "SignaturerTestBody");

          string messageData = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");

          Assert.IsTrue(messageData.Contains("%User.FirstName%"));

      }
   }

}
