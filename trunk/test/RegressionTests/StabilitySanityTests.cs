// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.IO;
using System.Diagnostics;

namespace UnitTest.Stability
{
   [TestFixture]
   public class SanityTests : TestFixtureBase
   {
      [Test]
      public void TestRetrievalOfDeletedMessage()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         string deletedMessageText = _settings.ServerMessages.get_ItemByName("MESSAGE_FILE_MISSING").Text;

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody");

         hMailServer.IMAPFolder inbox = account.IMAPFolders.get_ItemByName("Inbox"); ;

         Utilities.AssertMessageExistsInFolder(inbox, 1);

         hMailServer.Message message = inbox.Messages[0];

         System.IO.File.Delete(message.Filename);

         string text = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
         Assert.IsTrue(text.Contains(deletedMessageText.Replace("%MACRO_FILE%", message.Filename)));

         Utilities.AssertReportedError();
      }

      [Test]
      public void TestRetrievalOfMessageInDeletedFolder()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         string deletedMessageText = _settings.ServerMessages.get_ItemByName("MESSAGE_FILE_MISSING").Text;

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody");

         hMailServer.IMAPFolder inbox = account.IMAPFolders.get_ItemByName("Inbox"); ;

         Utilities.AssertMessageExistsInFolder(inbox, 1);

         hMailServer.Message message = inbox.Messages[0];

         DirectoryInfo dir = new DirectoryInfo(Path.GetFullPath(message.Filename));
         DirectoryInfo parent = dir.Parent.Parent.Parent;
         parent.Delete(true);

         string text = POP3Simulator.AssertGetFirstMessageText(account.Address, "test");
         Assert.IsTrue(text.Contains(deletedMessageText.Replace("%MACRO_FILE%", message.Filename)));
         Utilities.AssertReportedError();
      }


      [Test]
      public void TestRetrievalOfMessageInDeletedFolderUsingIMAP()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         string deletedMessageText = _settings.ServerMessages.get_ItemByName("MESSAGE_FILE_MISSING").Text;

         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         SMTPClientSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody");

         hMailServer.IMAPFolder inbox = account.IMAPFolders.get_ItemByName("Inbox"); ;

         Utilities.AssertMessageExistsInFolder(inbox, 1);

         hMailServer.Message message = inbox.Messages[0];

         DirectoryInfo dir = new DirectoryInfo(Path.GetFullPath(message.Filename));
         DirectoryInfo parent = dir.Parent.Parent.Parent;
         parent.Delete(true);

         IMAPSimulator sim = new IMAPSimulator();
         sim.ConnectAndLogon(account.Address, "test");
         sim.SelectFolder("INBOX");
         string result = sim.Fetch("1 BODY[1]");

         Assert.IsTrue(result.Contains(deletedMessageText.Replace("%MACRO_FILE%", message.Filename)));
         Utilities.AssertReportedError();
      }

      [Test]
      public void TestDeletionOfMessageInDeletedFolder()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
          string deletedMessageText = _settings.ServerMessages.get_ItemByName("MESSAGE_FILE_MISSING").Text;
          hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");
          SMTPClientSimulator.StaticSend(account.Address, account.Address, "Test", "SampleBody");
          hMailServer.IMAPFolder inbox = account.IMAPFolders.get_ItemByName("Inbox"); ;
          Utilities.AssertMessageExistsInFolder(inbox, 1);

          hMailServer.Messages messages = inbox.Messages;

          hMailServer.Message message = messages[0];
          DirectoryInfo dir = new DirectoryInfo(Path.GetFullPath(message.Filename));
          DirectoryInfo parent = dir.Parent.Parent.Parent;
          parent.Delete(true);

          DateTime timeBeforeDelete = DateTime.Now;
          messages.DeleteByDBID(message.ID);

          TimeSpan executionTime = DateTime.Now - timeBeforeDelete;

          Assert.Greater(1500, executionTime.TotalMilliseconds);
      }

      [Test]
      public void TestInsertionOfTooLongString()
      {
         Stopwatch watch = new Stopwatch();

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.Account account = SingletonProvider<Utilities>.Instance.AddAccount(_domain, "test@test.com", "test");

         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < 1000; i++)
            sb.Append("abcdefgh");

         account.PersonFirstName = sb.ToString();
         try
         {
            watch.Start();
            account.Save();
         }
         catch (Exception)
         {

         }

         watch.Stop();
         Assert.Greater(1500, watch.ElapsedMilliseconds);

         // an error log file may have been created. if we're using MySQL,
         // the value may have been silently truncated.
         Utilities.AssertDeleteFile(Utilities.GetErrorLogFileName());
      }

      [Test]
      [Description("Confirms that hMailServer behaves properly if a specific port is in use.")]
      public void TestPortInUse()
      {
          hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
          application.Stop();

          var serverSocket = new ServerSocket(1, 25);
          serverSocket.StartListen();

          application.Start();
          TCPSocket sock = new TCPSocket();
          // make sure it's possible to connect to the non blocked port.

          sock.CanConnect(110);
          sock.CanConnect(143);
          
          //let this our temp server die.
          sock.CanConnect(25);

          // make sure that hMailServer reported an error during start up because the ports were blocked.
          Utilities.AssertReportedError();

          // restart hMailServer again. everything is now back to normal.
          application.Stop();
          application.Start();
          sock.CanConnect(25);
      }

   }
}
