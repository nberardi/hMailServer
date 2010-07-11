// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Builder.Common
{
    class BuildStepClearDirectory : BuildStep
    {
        private string _directory;

        public BuildStepClearDirectory(Builder builder, string directory)
        {
            if (string.IsNullOrEmpty(directory))
                throw new ArgumentNullException("Directory must be specified.", "directory");

            if (builder == null)
                throw new ArgumentNullException("Builder must be specified.", "builder");

            m_oBuilder = builder;
            _directory = directory;
        }

        public override void Run()
        {
            string directoryName = ExpandMacros(_directory);

            m_oBuilder.Log("Clearing folder " + directoryName, true);

            if (!Directory.Exists(directoryName))
            {
               m_oBuilder.Log("Directory does not exist.", true);
               return;
            }

            string [] subDirs = Directory.GetDirectories(directoryName);
            foreach (string subDir in subDirs)
            {
               m_oBuilder.Log("Deleting directory " + subDir + "...", true);
                Directory.Delete(subDir, true);
            }

            string[] files = Directory.GetFiles(directoryName);

            foreach (string file in files)
            {
               m_oBuilder.Log("Deleting file " + file + "...", true);
                File.Delete(file);
            }
        }

        public override string Name
        {
            get 
            {
                return "Clear directory " + ExpandMacros(_directory); 
            }
        }
    }
}
