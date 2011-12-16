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
			proc.StartInfo.CreateNoWindow = true;

			// setup output redirection
			proc.StartInfo.UseShellExecute = false;
			proc.StartInfo.RedirectStandardOutput = true;
			proc.StartInfo.RedirectStandardError = true;

			proc.OutputDataReceived += new DataReceivedEventHandler((o, e) => DataReceived(e.Data));
			proc.ErrorDataReceived += new DataReceivedEventHandler((o, e) => DataReceived(e.Data));

			proc.Start();

			proc.BeginOutputReadLine();
			proc.BeginErrorReadLine();

			proc.WaitForExit();

			writtenData = _receivedData;

			return proc.ExitCode;
		}

		private void DataReceived(string data)
		{
			if (data == null)
				return;

			if (Output != null)
				Output(data);

			_receivedData += data;
		}
	}
}