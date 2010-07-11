// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace Builder.Common
{
    class BuildStepSubversion : BuildStep
    {
        private string m_sDirectory;
        private SVNAction m_eAction;

        public enum SVNAction
        {
            SVNRevert = 1,
            SVNUpdate = 2
        }


        public BuildStepSubversion(Builder oBuilder, SVNAction a, string sDirectory)
        {
            m_oBuilder = oBuilder;

            m_eAction = a;
            m_sDirectory = sDirectory;
        }


        public override string Name
        {
            get
            {
                switch (m_eAction)
                {
                    case SVNAction.SVNRevert:
                        return "SVN - Revert " + m_sDirectory;
                    case SVNAction.SVNUpdate:
                        return "SVN - Update " + m_sDirectory;
                }

                return "<Unknown>";
            }
        }

        public override void Run()
        {
            string sDirectory = ExpandMacros(m_sDirectory);

            string sCommand = "";
            switch (m_eAction)
            {
                case SVNAction.SVNRevert:
                  m_oBuilder.Log("Reverting " + sDirectory + "...\r\n", true);
                    sCommand = "revert -R " + sDirectory;
                    break;
                case SVNAction.SVNUpdate:
                    m_oBuilder.Log("Updating " + sDirectory + "...\r\n", true);
                    sCommand = "update "+ sDirectory;
                    break;
                default:
                    throw new Exception("Failed. Unknown action.");
            }

            ProcessLauncher launcher = new ProcessLauncher();
            launcher.Output += new ProcessLauncher.OutputDelegate(launcher_Output);
            string output;
            launcher.LaunchProcess(ExpandMacros(m_oBuilder.ParameterSubversionPath), ExpandMacros(sCommand), out output);

            if (output.IndexOf("svn help cleanup") > 0)
                throw new Exception("Failed");
        }

        void launcher_Output(string output)
        {
           m_oBuilder.Log(output, true);
        }

    }
}
