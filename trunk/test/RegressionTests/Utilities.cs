// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Threading;
using NUnit.Framework;
using System.Runtime.InteropServices;
using System.Net;
using System.Reflection;
using System.Security.Cryptography;

namespace UnitTest
{
   class Utilities
   {
      private hMailServer.Application application;
      private hMailServer.Settings _settings;

      public Utilities()
      {
         application = new hMailServer.Application();
      }

      public void Authenticate()
      {
         hMailServer.Account account = application.Authenticate("Administrator", "testar");

         if (account == null)
            account = application.Authenticate("Administrator", "");

         if (account == null)
            Assert.Fail("hMailServer API authentication failed");

         _settings = application.Settings;
      }

      public void RemoveAllRoutes()
      {
         hMailServer.Routes routes = _settings.Routes;
         while (routes.Count > 0)
            routes[0].Delete();
      }

      static public string GethMailServerCOMIPaddress()
      {
         IPAddress[] addresses = Dns.GetHostEntry("mail.hmailserver.com").AddressList;

         return addresses[0].ToString();
      }



      public hMailServer.Domain DoBasicSetup()
      {


         if (application.ServerState == hMailServer.eServerState.hStateStopped)
            application.Start();

         hMailServer.Domain domain = SingletonProvider<Utilities>.Instance.AddTestDomain();

         _settings.SecurityRanges.SetDefault();

         DisableSpamProtection();
         DisableVirusProtection();
         RemoveAllRoutes();
         RemoveAllRules();
         RemoveAllSharedFolders();
         RemoveAllGroups();
         ClearGreyListingWhiteAddresses();
         EnableLogging(true);


         _settings.SSLCertificates.Clear();
         _settings.TCPIPPorts.SetDefault();

         if (_settings.AutoBanOnLogonFailure)
            _settings.AutoBanOnLogonFailure = false;

         if (_settings.SMTPNoOfTries != 0)
            _settings.SMTPNoOfTries = 0;

         if (_settings.SMTPMinutesBetweenTry != 60)
            _settings.SMTPMinutesBetweenTry = 60;

         if (_settings.Scripting.Enabled != false)
            _settings.Scripting.Enabled = false;

         if (_settings.MirrorEMailAddress != "")
            _settings.MirrorEMailAddress = "";

         if (_settings.SMTPRelayer != "")
            _settings.SMTPRelayer = "";

         if (_settings.MaxDeliveryThreads != 50)
            _settings.MaxDeliveryThreads = 50;

         if (_settings.Scripting.Language != "VBScript")
            _settings.Scripting.Language = "VBScript";

         if (_settings.IMAPPublicFolderName != "#Public")
            _settings.IMAPPublicFolderName = "#Public";

         if (_settings.MaxNumberOfInvalidCommands != 3)
            _settings.MaxNumberOfInvalidCommands = 3;

         if (_settings.DisconnectInvalidClients != false)
            _settings.DisconnectInvalidClients = false;

         if (_settings.MaxSMTPRecipientsInBatch != 100)
            _settings.MaxSMTPRecipientsInBatch = 100;

         if (_settings.IMAPHierarchyDelimiter != ".")
            _settings.IMAPHierarchyDelimiter = ".";

         if (_settings.IMAPACLEnabled != true)
            _settings.IMAPACLEnabled = true;

         if (_settings.MaxMessageSize != 20480)
            _settings.MaxMessageSize = 20480;

         if (_settings.MaxNumberOfMXHosts != 15)
            _settings.MaxNumberOfMXHosts = 15;

         hMailServer.AntiVirus antiVirus = _settings.AntiVirus;

         if (antiVirus.ClamAVEnabled)
            antiVirus.ClamAVEnabled = false;

         if (antiVirus.ClamAVPort != 3310)
            antiVirus.ClamAVPort = 3310;

         if (antiVirus.ClamAVHost != "localhost")
            antiVirus.ClamAVHost = "localhost";

         EnableLogging(true);

         if (File.Exists(GetErrorLogFileName()))
         {
            string contents = File.ReadAllText(GetErrorLogFileName());
            Assert.Fail(contents);
         }

         if (File.Exists(GetEventLogFileName()))
            File.Delete(GetEventLogFileName());

         Utilities.AssertRecipientsInDeliveryQueue(0);

         return domain;

      }

      public void DeleteEventLog()
      {
         AssertDeleteFile(GetEventLogFileName());
      }

      public static void AssertDeleteFile(string file)
      {
         for (int i = 0; i <= 400; i++)
         {
            if (!File.Exists(file))
               return;

            try
            {
               File.Delete(file);
               return;
            }
            catch (Exception e)
            {
               if (i == 400)
                  throw e;
            }
            Thread.Sleep(25);
         }
      }

      private void EnableLogging(bool enable)
      {
         hMailServer.Logging logging = _settings.Logging;

         if (logging.AWStatsEnabled != enable)
            logging.AWStatsEnabled = enable;

         if (logging.Enabled != enable)
            logging.Enabled = enable;

         if (logging.LogApplication != enable)
            logging.LogApplication = enable;

         if (logging.LogDebug != enable)
            logging.LogDebug = enable;

         if (logging.LogIMAP != enable)
            logging.LogIMAP = enable;

         if (logging.LogPOP3 != enable)
            logging.LogPOP3 = enable;

         if (logging.LogSMTP != enable)
            logging.LogSMTP = enable;

         if (logging.LogTCPIP != enable)
            logging.LogTCPIP = enable;

         logging.KeepFilesOpen = false;
      }

      private void DisableVirusProtection()
      {
         _settings.AntiVirus.EnableAttachmentBlocking = false;
      }

      private void RemoveAllSharedFolders()
      {
         hMailServer.IMAPFolders folders = _settings.PublicFolders;
         while (folders.Count > 0)
            folders.DeleteByDBID(folders[0].ID);

         string publicFolderPath = Path.Combine(_settings.Directories.DataDirectory, "#Public");
         if (Directory.Exists(publicFolderPath))
            Directory.Delete(publicFolderPath, true);
      }

      private void RemoveAllGroups()
      {
         hMailServer.Groups groups = _settings.Groups;
         while (groups.Count > 0)
            groups.DeleteByDBID(groups[0].ID);
      }


      private void ClearGreyListingWhiteAddresses()
      {
         hMailServer.GreyListingWhiteAddresses addresses = _settings.AntiSpam.GreyListingWhiteAddresses;
         while (addresses.Count > 0)
            addresses.DeleteByDBID(addresses[0].ID);


      }


      public static void SendMessagesInQueue()
      {

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.DeliveryQueue queue = application.GlobalObjects.DeliveryQueue;
         hMailServer.Status status = application.Status;

         string[] messages = status.UndeliveredMessages.Split('\n');
         foreach (string message in messages)
         {
            if (message.Length < 10)
               continue;

            string[] info = message.Split('\t');
            Int64 id = Convert.ToInt64(info[0]);

            queue.ResetDeliveryTime(id);

         }

         application.SubmitEMail();
      }


      private static void DeleteMessagesInQueue()
      {

         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         hMailServer.DeliveryQueue queue = application.GlobalObjects.DeliveryQueue;
         hMailServer.Status status = application.Status;

         string[] messages = status.UndeliveredMessages.Split('\n');
         foreach (string message in messages)
         {
            if (message.Length < 10)
               continue;

            string[] info = message.Split('\t');
            int id = Convert.ToInt32(info[0]);

            queue.Remove(id);

         }

         application.SubmitEMail();
      }

      private static int GetNumberOfMessagesInDeliveryQueue()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.DeliveryQueue queue = application.GlobalObjects.DeliveryQueue;
         hMailServer.Status status = application.Status;

         string messages = status.UndeliveredMessages;

         if (messages.Length < 4)
            return 0;

         string[] messageList = status.UndeliveredMessages.Split('\n');

         int count = 0;
         foreach (string message in messageList)
         {
            if (message.Length < 4)
               continue;

            string recipients = message.Split('\t')[3];

            string[] recipientList = recipients.Split(',');

            count += recipientList.Length;
         }

         return count;
      }

      public static void AssertRecipientsInDeliveryQueue(int count)
      {
         AssertRecipientsInDeliveryQueue(count, true);
      }

      public static void AssertRecipientsInDeliveryQueue(int count, bool forceSend)
      {
         if (forceSend)
            SendMessagesInQueue();

         for (int i = 1; i <= 60; i++)
         {
            if (GetNumberOfMessagesInDeliveryQueue() == count)
               return;

            if (i % 10 == 0 && forceSend)
               SendMessagesInQueue();

            Thread.Sleep(100);
         }

         int currentCount = GetNumberOfMessagesInDeliveryQueue();
         if (currentCount == count)
            return;

         DeleteMessagesInQueue();

         string message = string.Format(
            "Message queue does not contain correct number of messages. Actual: {0}, Expected: {1}",
            currentCount, count);
         Assert.Fail(message);
      }

      private void RemoveAllRules()
      {
         while (application.Rules.Count > 0)
            application.Rules[0].Delete();
      }

      public hMailServer.Application GetApp()
      {
         return application;
      }

      public void ClearDomains()
      {
         hMailServer.Domains domains = application.Domains;

         while (domains.Count > 0)
         {
            hMailServer.Domain domain = domains[0];
            domain.Delete();
         }
      }

      public void DisableSpamProtection()
      {
         hMailServer.AntiSpam antiSpam = _settings.AntiSpam;

         if (antiSpam.SpamMarkThreshold != 10000)
            antiSpam.SpamMarkThreshold = 10000;

         if (antiSpam.SpamDeleteThreshold != 10000)
            antiSpam.SpamDeleteThreshold = 10000;

         if (antiSpam.CheckHostInHelo != false)
            antiSpam.CheckHostInHelo = false;

         if (antiSpam.GreyListingEnabled != false)
            antiSpam.GreyListingEnabled = false;

         if (antiSpam.BypassGreylistingOnMailFromMX != false)
            antiSpam.BypassGreylistingOnMailFromMX = false;

         if (antiSpam.SpamAssassinEnabled != false)
            antiSpam.SpamAssassinEnabled = false;

         if (antiSpam.TarpitCount != 0)
            antiSpam.TarpitCount = 0;

         if (antiSpam.TarpitDelay != 0)
            antiSpam.TarpitDelay = 0;

         if (antiSpam.UseMXChecks != false)
            antiSpam.UseMXChecks = false;

         if (antiSpam.UseSPF != false)
            antiSpam.UseSPF = false;

         if (antiSpam.MaximumMessageSize != 1024)
            antiSpam.MaximumMessageSize = 1024;

         if (antiSpam.DKIMVerificationEnabled != false)
            antiSpam.DKIMVerificationEnabled = false;

         antiSpam.WhiteListAddresses.Clear();

         for (int i = 0; i < antiSpam.DNSBlackLists.Count; i++)
         {
            hMailServer.DNSBlackList list = antiSpam.DNSBlackLists[i];
            if (list.Active)
            {
               list.Active = false;
               list.Save();
            }
         }

         hMailServer.DNSBlackLists dnsBlackLists = antiSpam.DNSBlackLists;
         while (dnsBlackLists.Count > 0)
            dnsBlackLists.DeleteByDBID(dnsBlackLists[0].ID);

         hMailServer.SURBLServers surblServers = antiSpam.SURBLServers;

         for (int i = surblServers.Count - 1; i >= 0; i--)
         {
            if (surblServers[i].DNSHost != "multi.surbl.org")
               surblServers.DeleteByDBID(surblServers[i].ID);
            else
               surblServers[i].Active = false;
         }

         if (surblServers.Count == 0)
         {
            hMailServer.SURBLServer surblServer = surblServers.Add();
            surblServer.Active = false;
            surblServer.DNSHost = "multi.surbl.org";
            surblServer.RejectMessage = "Nope";
            surblServer.Score = 5;
            surblServer.Save();

         }

         hMailServer.IncomingRelays incomingRelays = _settings.IncomingRelays;
         while (incomingRelays.Count > 0)
            incomingRelays.DeleteByDBID(incomingRelays[0].ID);

         antiSpam.ClearGreyListingTriplets();
      }

      public hMailServer.Domain AddTestDomain()
      {
         ClearDomains();

         hMailServer.Domain domain = AddDomain(application.Domains, "test.com");
         return domain;
      }

      public hMailServer.Alias AddAlias(hMailServer.Domain domain, string sName, string sValue)
      {
         hMailServer.Alias oAlias = domain.Aliases.Add();
         oAlias.Name = sName;
         oAlias.Value = sValue;
         oAlias.Active = true;
         oAlias.Save();

         return oAlias;
      }

      public hMailServer.Group AddGroup(string sName)
      {
         hMailServer.Group group = GetApp().Settings.Groups.Add();
         group.Name = sName;
         group.Save();
         return group;
      }

      public hMailServer.GroupMember AddGroupMember(hMailServer.Group group, hMailServer.Account account)
      {
         hMailServer.GroupMember member = group.Members.Add();
         member.AccountID = account.ID;
         member.Save();

         return member;
      }


      public hMailServer.Account AddAccount(hMailServer.Domain oDomain, string sAddress, string sPassword)
      {
         return AddAccount(oDomain.Accounts, sAddress, sPassword);
      }

      public hMailServer.Account AddAccount(hMailServer.Accounts accounts, string sAddress, string sPassword)
      {
         hMailServer.Account oAccount = accounts.Add();
         oAccount.Address = sAddress;
         oAccount.Password = sPassword;
         oAccount.Active = true;
         oAccount.Save();

         return oAccount;
      }

      public hMailServer.Account AddAccount(hMailServer.Domain oDomain, string sAddress, string sPassword, int maxSize)
      {
         hMailServer.Account oAccount = oDomain.Accounts.Add();
         oAccount.Address = sAddress;
         oAccount.Password = sPassword;
         oAccount.Active = true;
         oAccount.MaxSize = maxSize;
         oAccount.Save();


         return oAccount;
      }

      public hMailServer.Domain AddDomain(string name)
      {
         hMailServer.Domains domains = SingletonProvider<Utilities>.Instance.GetApp().Domains;
         return AddDomain(domains, name);
      }

      public hMailServer.Domain AddDomain(hMailServer.Domains oDomains, string sName)
      {
         hMailServer.Domain oDomain = oDomains.Add();
         oDomain.Name = sName;
         oDomain.Active = true;
         oDomain.Save();

         return oDomain;
      }

      public hMailServer.DistributionList AddDistributionList(hMailServer.Domain oDomain, string sAddress, List<string> recipients)
      {
         hMailServer.DistributionList oList = oDomain.DistributionLists.Add();
         oList.Active = true;
         oList.Address = sAddress;
         oList.Save();

         // Add recipients
         foreach (string recipient in recipients)
         {
            hMailServer.DistributionListRecipient oRecipient = oList.Recipients.Add();
            oRecipient.RecipientAddress = recipient;
            oRecipient.Save();

            Marshal.ReleaseComObject(oRecipient);
         }

         return oList;
      }

      public void AddSpamRule(hMailServer.Account oAccount)
      {
         hMailServer.Rule oRule = oAccount.Rules.Add();
         oRule.Name = "TestRule 1";
         oRule.Active = true;

         hMailServer.RuleCriteria oRuleCriteria = oRule.Criterias.Add();
         oRuleCriteria.UsePredefined = false;
         oRuleCriteria.HeaderField = "Subject";
         oRuleCriteria.MatchType = hMailServer.eRuleMatchType.eMTContains;
         oRuleCriteria.MatchValue = "**SPAM**";
         oRuleCriteria.Save();

         // Add action
         hMailServer.RuleAction oRuleAction = oRule.Actions.Add();
         oRuleAction.Type = hMailServer.eRuleActionType.eRAMoveToImapFolder;
         oRuleAction.IMAPFolder = "INBOX.Spam";
         oRuleAction.Save();

         // Save the rule in the database
         oRule.Save();


      }

      public void AddCorporateRule(hMailServer.Account oAccount)
      {
         hMailServer.Rule oRule = oAccount.Rules.Add();
         oRule.Name = "TestRule 2";
         oRule.Active = true;

         hMailServer.RuleCriteria oRuleCriteria = oRule.Criterias.Add();
         oRuleCriteria.UsePredefined = false;
         oRuleCriteria.HeaderField = "Subject";
         oRuleCriteria.MatchType = hMailServer.eRuleMatchType.eMTContains;
         oRuleCriteria.MatchValue = "**CORPORATE**";
         oRuleCriteria.Save();

         // Add action
         hMailServer.RuleAction oRuleAction = oRule.Actions.Add();
         oRuleAction.Type = hMailServer.eRuleActionType.eRAMoveToImapFolder;
         oRuleAction.IMAPFolder = "INBOX.Corporate";
         oRuleAction.Save();

         // Save the rule in the database
         oRule.Save();
      }

      public void AddExactMatchRule(hMailServer.Account oAccount)
      {
         hMailServer.Rule oRule = oAccount.Rules.Add();
         oRule.Name = "TestRule 3";
         oRule.Active = true;

         hMailServer.RuleCriteria oRuleCriteria = oRule.Criterias.Add();
         oRuleCriteria.UsePredefined = false;
         oRuleCriteria.HeaderField = "Subject";
         oRuleCriteria.MatchType = hMailServer.eRuleMatchType.eMTEquals;
         oRuleCriteria.MatchValue = "CORPORATE EXACT MATCH";
         oRuleCriteria.Save();

         // Add action
         hMailServer.RuleAction oRuleAction = oRule.Actions.Add();
         oRuleAction.Type = hMailServer.eRuleActionType.eRAMoveToImapFolder;
         oRuleAction.IMAPFolder = "INBOX.Corporate";
         oRuleAction.Save();

         // Save the rule in the database
         oRule.Save();
      }

      public static string RandomString()
      {
         string s = System.Guid.NewGuid().ToString();
         s = s.Replace("{", "");
         s = s.Replace("}", "");
         s = s.Replace("-", "");

         return s;
      }

      public static void WriteFile(string file, string contents)
      {
         StreamWriter streamWriter;

         streamWriter = File.CreateText(file);
         streamWriter.Write(contents);
         streamWriter.Close();
      }

      public void AssertBounceMessageExistsInQueue(string bounceTo)
      {
         hMailServer.Status status = application.Status;
         for (int i = 0; i < 100; i++)
         {
            if (status.UndeliveredMessages.Length == 0 || status.UndeliveredMessages.Contains("\t" + bounceTo))
               return;

            Thread.Sleep(100);
         }

         Assert.Fail("Delivery queue not empty");
      }

      public string AssertLiveLogContents()
      {
         hMailServer.Logging logging = _settings.Logging;
         for (int i = 0; i < 40; i++)
         {
            string contents = logging.LiveLog;
            if (contents.Length > 0)
               return contents;

            Thread.Sleep(100);
         }

         return "";
      }

      public static void AssertSpamAssassinIsRunning()
      {
         Process[] processlist = Process.GetProcesses();

         foreach (Process theprocess in processlist)
         {
            if (theprocess.ProcessName == "spamd")
               return;
         }

         // Check if we can launch it...
         string spamdExecutable = @"C:\Program Files (x86)\SpamAssasssin\spamd.exe";

         try
         {
            System.Diagnostics.Process.Start(spamdExecutable);
         }
         catch (Exception)
         {
            Assert.Ignore("Unable to start SpamAssassin process. Is SpamAssassin installed?");
         }
      }

      public static void AssertClamDRunning()
      {
         Process[] processlist = Process.GetProcesses();

         foreach (Process theprocess in processlist)
         {
            if (theprocess.ProcessName == "clamd")
               return;
         }

         // Check if we can launch it...
         ProcessStartInfo startInfo = new ProcessStartInfo();
         startInfo.FileName = @"C:\clamav\clamd.exe";
         startInfo.WorkingDirectory = @"C:\Clamav";
         startInfo.Arguments = "--daemon";

         try
         {

            System.Diagnostics.Process.Start(startInfo);

            // Wait for clamav to start up.
            for (int i = 0; i < 10; i++)
            {
               TCPSocket sock = new TCPSocket();
               if (sock.Connect(3310))
                  return;
               System.Threading.Thread.Sleep(1000);
            }

            Assert.Fail("ClamD process not starting up.");
         }
         catch (Exception)
         {
            Assert.Ignore("Unable to start ClamD process. Is ClamAV installed?");
         }
      }

      public static void AssertMessageExistsInFolder(hMailServer.IMAPFolder folder, int expectedCount)
      {
         if (expectedCount == 0)
         {
            // just in case.
            Utilities.AssertRecipientsInDeliveryQueue(0);
         }

         int currentCount = 0;
         int timeout = 100;
         while (timeout > 0)
         {
            currentCount = folder.Messages.Count;

            if (currentCount == expectedCount)
               return;

            timeout--;
            Thread.Sleep(100);
         }

         string error = "Wrong number of messages in mailbox " + folder.Name;
         Assert.Fail(error);
      }

      public static hMailServer.Message AssertRetrieveFirstMessage(hMailServer.IMAPFolder folder)
      {
         int timeout = 100;
         while (timeout > 0)
         {
            if (folder.Messages.Count > 0)
            {
               return folder.Messages[0];
            }

            timeout--;
            Thread.Sleep(100);
         }

         string error = "Could not retrieve message from folder";
         Assert.Fail(error);

         return null;
      }

      public static hMailServer.IMAPFolder AssertFolderExists(hMailServer.IMAPFolders folders, string folderName)
      {
         int timeout = 100;
         while (timeout > 0)
         {
            try
            {
               return folders.get_ItemByName(folderName);
            }
            catch (Exception)
            {

            }

            timeout--;
            Thread.Sleep(100);
         }

         string error = "Folder could not be found " + folderName;
         Assert.Fail(error);
         return null;
      }

      public static string GetErrorLogFileName()
      {
         return SingletonProvider<Utilities>.Instance.GetApp().Settings.Logging.CurrentErrorLog;
      }

      public static string GetDefaultLogFileName()
      {
         return SingletonProvider<Utilities>.Instance.GetApp().Settings.Logging.CurrentDefaultLog;
      }

      public static void DeleteCurrentDefaultLog()
      {
         for (int i = 0; i < 50; i++)
         {
            try
            {
               string filename = GetDefaultLogFileName();
               if (File.Exists(filename))
                  File.Delete(filename);

               return;
            }
            catch (Exception)
            {
               Thread.Sleep(100);
            }
         }

         Assert.Fail("Failed to delete default log file during test");
      }

      public static string ReadCurrentDefaultLog()
      {
         string filename = GetDefaultLogFileName();
         string content = string.Empty;
         if (File.Exists(filename))
            return ReadExistingTextFile(filename);

         return content;
      }

      public static bool DefaultLogContains(string data)
      {
         string filename = GetDefaultLogFileName();

         for (int i = 0; i < 40; i++)
         {
            if (File.Exists(filename))
            {
               string content = ReadExistingTextFile(filename);
               if (content.Contains(data))
                  return true;
            }

            Thread.Sleep(250);
         }

         return false;
      }

      public static string GetEventLogFileName()
      {
         return SingletonProvider<Utilities>.Instance.GetApp().Settings.Logging.CurrentEventLog;
      }

      public static string ReadExistingTextFile(string fileName)
      {
         AssertFileExists(fileName, false);

         for (int i = 1; i <= 100; i++)
         {
            try
            {
               FileStream stream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
               StreamReader reader = new StreamReader(stream);
               string contents = reader.ReadToEnd();
               reader.Close();
               stream.Close();

               // Check that some data has actually been read.
               if (!string.IsNullOrEmpty(contents))
               {
                  return contents;
               }
            }
            catch (Exception ex)
            {
               if (i == 100)
                  throw ex;
            }

            Thread.Sleep(100);
         }

         return "";

      }

      public static void AssertFileExists(string file, bool delete)
      {
         int timeout = 100;
         while (timeout > 0)
         {
            try
            {
               if (File.Exists(file))
               {
                  if (delete)
                     File.Delete(file);

                  return;
               }


            }
            catch (Exception)
            {

            }

            timeout--;
            Thread.Sleep(100);
         }

         Assert.Fail("Expected file does not exist:" + file);
      }

      public static void AssertReportedError()
      {
         string file = GetErrorLogFileName();
         AssertFileExists(file, true);
      }

      public static void AssertReportedError(string content)
      {
         string errorLog = ReadAndDeleteErrorLog();
         Assert.IsTrue(errorLog.Contains(content), errorLog);
      }


      public static string ReadAndDeleteErrorLog()
      {
         string file = GetErrorLogFileName();
         AssertFileExists(file, false);

         string contents = File.ReadAllText(file);

         File.Delete(file);

         return contents;
      }

      public void AssertFilesInUserDirectory(hMailServer.Account account, int expectedFileCount)
      {
         string domain = account.Address.Substring(account.Address.IndexOf("@") + 1);
         string mailbox = account.Address.Substring(0, account.Address.IndexOf("@"));

         string domainDir = Path.Combine(_settings.Directories.DataDirectory, domain);
         string userDir = Path.Combine(domainDir, mailbox);

         AssertFilesInDirectory(userDir, expectedFileCount);

      }

      public void AssertFilesInDirectory(string directory, int expectedFileCount)
      {
          int count = 0;

          if (Directory.Exists(directory))
          {
              string[] dirs = Directory.GetDirectories(directory);
              
              foreach (string dir in dirs)
              {
                  string[] files = Directory.GetFiles(dir);
                  count += files.Length;
              }
          }

          Assert.AreEqual(expectedFileCount, count);
      }

      public static string GetCurrentMIMEDateTime()
      {
         DateTime now = DateTime.Now;

         string dayOfWeek = "";
         switch (now.DayOfWeek)
         {
            case DayOfWeek.Monday:
               dayOfWeek = "Mon";
               break;
            case DayOfWeek.Tuesday:
               dayOfWeek = "Tue";
               break;
            case DayOfWeek.Wednesday:
               dayOfWeek = "Wed";
               break;
            case DayOfWeek.Thursday:
               dayOfWeek = "Thu";
               break;
            case DayOfWeek.Friday:
               dayOfWeek = "Fri";
               break;
            case DayOfWeek.Saturday:
               dayOfWeek = "Sat";
               break;
            case DayOfWeek.Sunday:
               dayOfWeek = "Sun";
               break;
         }

         string monthName = "";
         switch (now.Month)
         {
            case 1:
               monthName = "Jan";
               break;
            case 2:
               monthName = "Feb";
               break;
            case 3:
               monthName = "Mar";
               break;
            case 4:
               monthName = "Apr";
               break;
            case 5:
               monthName = "May";
               break;
            case 6:
               monthName = "Jun";
               break;
            case 7:
               monthName = "Jul";
               break;
            case 8:
               monthName = "Aug";
               break;
            case 9:
               monthName = "Sep";
               break;
            case 10:
               monthName = "Oct";
               break;
            case 11:
               monthName = "Nov";
               break;
            case 12:
               monthName = "Dec";
               break;

         }

         string timeString = now.ToString("HH':'mm':'ss");
         string dateString = string.Format("{0}, {1} {2} {3} {4} +0100", dayOfWeek, now.Day, monthName, now.Year, timeString);

         return dateString;
      }

      static internal IPAddress GetLocalIPAddress()
      {
         // Connect to another local address.
         IPHostEntry iphostentry = Dns.GetHostEntry(Dns.GetHostName());

         foreach (IPAddress ipaddress in iphostentry.AddressList)
         {
            if (ipaddress.ToString().Contains(".") && !ipaddress.ToString().Contains("127.0.0"))
            {
               return ipaddress;
            }
         }

         Assert.Fail("No local internet address found.");
         return null;
      }

      public static string GetResource(string resourceName)
      {
         Assembly assembly = Assembly.GetExecutingAssembly();
         TextReader textReader = new StreamReader(assembly.GetManifestResourceStream("RegressionTests." + resourceName));
         string result = textReader.ReadToEnd();
         textReader.Close();
         return result;
      }

      public static string GetFileHash(string fileName)
      {
         byte[] bytes = File.ReadAllBytes(fileName);
         SHA1 sha = new SHA1CryptoServiceProvider();
         StringBuilder hash = new StringBuilder();

         byte[] hashedData = sha.ComputeHash(bytes);

         foreach (byte b in hashedData)
         {
            hash.Append(string.Format("{0,2:X2}", b));
         }

         //return the hashed value
         return hash.ToString();
      }


      static public string Escape(string input)
      {
         string escapedValue = input;

         switch (SingletonProvider<Utilities>.Instance.GetApp().Database.DatabaseType)
         {
            case hMailServer.eDBtype.hDBTypeMSSQL:
            case hMailServer.eDBtype.hDBTypeMSSQLCE:
               break;
            case hMailServer.eDBtype.hDBTypeMySQL:
            case hMailServer.eDBtype.hDBTypePostgreSQL:
               escapedValue = escapedValue.Replace("\\", "\\\\");
               break;
            default:
               throw new Exception("Unknown database type");

         }

         return escapedValue;
      }

      public string GetPublicDirectory()
      {
          string dataDir = _settings.Directories.DataDirectory;
          string publicDir = Path.Combine(dataDir, _settings.PublicFolderDiskName);
          return publicDir;
      }

      public static string CreateLargeDummyMailBody()
      {
         var sb = new StringBuilder();
         for (int i = 0; i < 10000; i++)
            sb.AppendLine("0123456789012345678901234567890123456789012345678901234567890123456789");

         return sb.ToString();
      }
   }
}
