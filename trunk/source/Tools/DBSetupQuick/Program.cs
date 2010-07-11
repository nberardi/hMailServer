// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Diagnostics;
using hMailServer.Shared;

namespace DBSetupQuick
{
   static class Program
   {
      private static hMailServer.Application _application;

      [STAThread]
      static void Main()
      {
         CommandLineParser.Parse();

         _application = new hMailServer.Application();

         if (_application.Database.DatabaseExists)
            UpgradeDatabase();
         else if (!CommandLineParser.IsSilent())
         {
             // Can't run the database setup in silent mode.
             StartDatabaseSetup();
         }
      }

      private static void UpgradeDatabase()
      {
         try
         {
            // Database upgrader
            System.Diagnostics.ProcessStartInfo upgradeProcess = new System.Diagnostics.ProcessStartInfo();
            upgradeProcess.FileName = "DBUpdater.exe";

            // Means that it should automatically exit if already up to date. This is always
            // the case when we launch it via 'quick'.
            string arguments = "/SilentIfOk";

            // If the /silent param has been supplied to this process, we should forward it to the updater
            if (CommandLineParser.IsSilent())
            {
               arguments += " /silent";
            }

            upgradeProcess.Arguments = arguments;

            // Launch upgrader and wait for it to complete.
            Process p = Process.Start(upgradeProcess);
            p.WaitForExit();
         }
         catch (Exception ex)
         {
            MessageBox.Show("Failed to start DBUpdater.exe" + Environment.NewLine + ex.Message, "hMailServer");
         }
      }

      private static void StartDatabaseSetup()
      {
          try
          {
              // Launch the databsase set up so that the user can create a database.
              ProcessStartInfo pi = new ProcessStartInfo("DBSetup.exe");
              Dictionary<string, string> arguments = CommandLineParser.GetParsedArguments();

              if (arguments.ContainsKey("password"))
                  pi.Arguments = arguments["password"];

              Process process = Process.Start(pi);

              process.WaitForExit();
          }
          catch (Exception ex)
          {
              MessageBox.Show("Failed to start DBSetup.exe" + Environment.NewLine + ex.Message, "hMailServer");
          }
      }

   }
}