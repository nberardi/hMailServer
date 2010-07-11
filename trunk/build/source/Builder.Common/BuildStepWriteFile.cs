// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Builder.Common
{
    class BuildStepWriteFile : BuildStep
    {
        private string m_sFilename;
        private string m_sContents;

        public BuildStepWriteFile(Builder oBuilder, string sFileName, string sContents)
        {
            m_oBuilder = oBuilder;

            m_sFilename = sFileName;
            m_sContents = sContents;
        }


        public override string Name
        {
            get
            {
                return "Write to file " + m_sFilename;
            }
        }

        public override void Run()
        {
            m_oBuilder.Log("Writing to file " + ExpandMacros(m_sFilename) + "...\r\n", true);
            File.WriteAllText(ExpandMacros(m_sFilename), ExpandMacros(m_sContents));
        }
    }
}
