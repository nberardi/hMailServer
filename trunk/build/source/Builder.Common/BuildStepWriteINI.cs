using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace Builder.Common
{
    class BuildStepWriteINI : BuildStep
    {
        [DllImport("kernel32")]
        private static extern long WritePrivateProfileString(string section,
            string key,string val,string filePath);

        private string m_sFilename;
        private string m_sSection;
        private string m_sKey;
        private string m_sValue;

        public BuildStepWriteINI(Builder oBuilder, string sFileName, string sSection, string sKey, string sValue)
        {
            m_oBuilder = oBuilder;

            m_sFilename = sFileName;
            m_sSection = sSection;
            m_sKey = sKey;
            m_sValue = sValue;
        }


        public override string Name
        {
            get
            {
                return "Write to inifile " + m_sFilename;
            }
        }

        public override void Run()
        {
            m_oBuilder.Log("Writing to inifile " + m_sFilename + "...\r\n", true);

            WritePrivateProfileString(m_sSection, m_sKey, ExpandMacros(m_sValue), ExpandMacros(m_sFilename));
        }
    }
}
    