// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace Builder.Common
{
	class BuildStepMSBuild : BuildStep
	{
		private string m_sProject;
		private string m_sConfiguration;

		public BuildStepMSBuild(Builder oBuilder, string sProject, string sConfiguration)
		{
			m_oBuilder = oBuilder;


			m_sProject = sProject;
			m_sConfiguration = sConfiguration;
		}


		public override string Name
		{
			get
			{
				return "Compile " + m_sProject;
			}
		}

		public override void Run()
		{
			m_oBuilder.Log("Compiling " + ExpandMacros(m_sProject) + "...\r\n", true);

			string arguments =
				"\"" + ExpandMacros(m_sProject) + "\" /t:rebuild /p:Configuration=" + ExpandMacros(m_sConfiguration) + "";

			ProcessLauncher launcher = new ProcessLauncher();
			launcher.Output += new ProcessLauncher.OutputDelegate(launcher_Output);

			string output;
			int exitCode = launcher.LaunchProcess(m_oBuilder.ExpandMacros(m_oBuilder.ParameterMSBuildPath), arguments, out output);

			if (exitCode != 0)
				throw new Exception("Failed");

			if (output.IndexOf("0 succeeded") >= 0)
				throw new Exception("Failed");
		}

		void launcher_Output(string output)
		{
			m_oBuilder.Log(output, false);
		}

	}
}
