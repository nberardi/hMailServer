// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace Builder.Common
{
   class ProcessLauncher
   {
      public delegate void OutputDelegate(string output);
      public event OutputDelegate Output;

      public string _receivedData;

      public int LaunchProcess(string path, string arguments, out string writtenData)
      {
         _receivedData = "";

         var proc = new Process();
         proc.StartInfo.FileName = path;
         proc.StartInfo.WorkingDirectory = Path.GetDirectoryName(path);
         proc.StartInfo.Arguments = arguments;
         proc.StartInfo.UseShellExecute = false;

         // set up output redirection
         proc.StartInfo.RedirectStandardOutput = true;
         proc.StartInfo.RedirectStandardError = true;
         proc.EnableRaisingEvents = true;
         proc.StartInfo.CreateNoWindow = true;
         // see below for output handler
         proc.ErrorDataReceived += new DataReceivedEventHandler(proc_DataReceived);
         proc.OutputDataReceived += new DataReceivedEventHandler(proc_DataReceived);

         proc.Start();

         proc.BeginErrorReadLine();
         proc.BeginOutputReadLine();

         proc.WaitForExit();

         writtenData = _receivedData;

         return proc.ExitCode;
      }

      void proc_DataReceived(object sender, DataReceivedEventArgs e)
      {
         if (e.Data == null)
            return;

         if (Output != null)
            Output(e.Data);

         _receivedData += e.Data;
      }


   }
}
