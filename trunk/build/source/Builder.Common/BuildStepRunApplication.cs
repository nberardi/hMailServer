// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;

namespace Builder.Common
{
    class BuildStepRunApplication : BuildStep
    {
        private string m_sExecutable;
        private string m_sArguments;


        public BuildStepRunApplication(Builder oBuilder, string sExecutable, string sArguments)
        {
            m_oBuilder = oBuilder;

            m_sExecutable = sExecutable;
            m_sArguments = sArguments;

        }


        public override string Name
        {
            get
            {
                return "Run application " + m_sExecutable;
            }
        }

        public override void Run()
        {
           m_oBuilder.Log("Running application " + m_sExecutable + "...\r\n", true);

            ProcessLauncher launcher = new ProcessLauncher();
            launcher.Output += new ProcessLauncher.OutputDelegate(launcher_Output);


            string output;
            int exitCode = launcher.LaunchProcess(ExpandMacros(m_sExecutable), ExpandMacros(m_sArguments), out output);

            if (exitCode != 0)
               throw new Exception("Failed");
        }

        void launcher_Output(string output)
        {
           m_oBuilder.Log(output, false);
        }
    }
}
