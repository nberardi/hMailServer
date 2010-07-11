// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace Builder.Common
{
    class BuildStepInnoSetup : BuildStep
    {
        private string m_sProject;

        public BuildStepInnoSetup(Builder oBuilder, string sProject)
        {
            m_oBuilder = oBuilder;
            m_sProject = sProject;
        }


        public override string Name
        {
            get
            {
                return "Create installation " + m_sProject;
            }
        }

        public override void Run()
        {
           m_oBuilder.Log("Running InnoSetup on " + ExpandMacros(m_sProject) + "...\r\n", true);

            string sArguments = "\"" + ExpandMacros(m_sProject) + "\"";

            Process processCompile = new Process();

            processCompile.StartInfo.UseShellExecute = false;
            processCompile.StartInfo.RedirectStandardOutput = true;
            processCompile.StartInfo.CreateNoWindow = true;

            processCompile.StartInfo.FileName = ExpandMacros(m_oBuilder.ParameterInnoSetupPath);
            processCompile.StartInfo.Arguments = sArguments;

            processCompile.Start();

            // Capture the result
            string output = processCompile.StandardOutput.ReadToEnd();

            processCompile.WaitForExit();


            m_oBuilder.Log(output + "\r\n", true);

            if (output.IndexOf("0 succeeded") >= 0)
                throw new Exception("Failed");
        }

    }
}
