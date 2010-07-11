// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Builder.Common
{

   class BuildStepCopyFile : BuildStep
   {
      private string m_sFrom;
      private string m_sTo;
      private bool m_bOverwrite;

      public BuildStepCopyFile(Builder oBuilder, string sFrom, string sTo, bool bOverwrite)
      {
         m_oBuilder = oBuilder;

         m_sFrom = sFrom;
         m_sTo = sTo;
         m_bOverwrite = bOverwrite;
      }

      public override string Name
      {
         get
         {
            return "Copy file " + m_sFrom;
         }
      }

      public override void Run()
      {
         m_oBuilder.Log("Copying file " + ExpandMacros(m_sFrom) + "...\r\n", true);
         File.Copy(ExpandMacros(m_sFrom), ExpandMacros(m_sTo), m_bOverwrite);
      }
   }
}
