// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace Builder.Common
{
   public class Builder
   {
      System.Collections.ArrayList m_oBuildSteps;
      System.Collections.ArrayList m_oMacros;

      private string m_sParamSourcePath;
      private string m_sParamVS8Path;
      private string m_sParamInnoSetupPath;
      private string m_sParamSubversionPath;

      private int m_iStepStart;
      private int m_iStepEnd;

      public delegate void MessageLogDelegate(bool timestamp, string message);
      public event MessageLogDelegate MessageLog;

      public Builder()
      {
         m_oBuildSteps = new System.Collections.ArrayList();
         m_oMacros = new System.Collections.ArrayList();

         m_iStepStart = -1;
         m_iStepEnd = -1;
      }

      public bool RunAllSteps
      {
         get
         {
            return m_iStepStart == -1;
         }
      }

      public int StepStart
      {
         get { return m_iStepStart; }
         set { m_iStepStart = value; }
      }

      public int StepEnd
      {
         get { return m_iStepEnd; }
         set { m_iStepEnd = value; }
      }


      public string ParameterSourcePath
      {
         get { return m_sParamSourcePath; }
         set { m_sParamSourcePath = value; }
      }

      public string ParameterVS8Path
      {
         get { return m_sParamVS8Path; }
         set { m_sParamVS8Path = value; }
      }

      public string ParameterInnoSetupPath
      {
         get { return m_sParamInnoSetupPath; }
         set { m_sParamInnoSetupPath = value; }
      }

      public string ParameterSubversionPath
      {
         get { return m_sParamSubversionPath; }
         set { m_sParamSubversionPath = value; }
      }



      public void LoadSettings(Settings settings)
      {
         ParameterSourcePath = settings.SourcePath;
         ParameterVS8Path = settings.VSPath;
         ParameterInnoSetupPath = settings.InnoSetupPath;
         ParameterSubversionPath = settings.SubversionPath;
      }

      public void Log(string sMessage, bool timestamp)
      {
         if (MessageLog != null)
            MessageLog(timestamp, sMessage);
         
      }

      public void Add(BuildStep bs)
      {
         m_oBuildSteps.Add(bs);
      }

      private void AddMacro(string sName, string sValue)
      {
         Macro oMacro = new Macro(sName, sValue);
         m_oMacros.Add(oMacro);
      }

      public System.Collections.ArrayList Macros
      {
         get { return m_oMacros; }
      }

      public void LoadMacros(string sourceDir, string version, string build)
      {
         Macros.Clear();
         AddMacro("%BUILD_NUMBER%", build);
         AddMacro("%PATH_SOURCE%", sourceDir);
         AddMacro("%HMAILSERVER_VERSION%", version);
         AddMacro("%PROGRAM_FILES%", BuildLoader.ProgramFilesx86());
      }

      public string ExpandMacros(string input)
      {
         string sExpanded = input;
         bool bFound = true;

         ArrayList oMacros = Macros;

         while (bFound)
         {
            bFound = false;

            for (int i = 0; i < oMacros.Count; i++)
            {
               Macro oMacro = (Macro)oMacros[i];
               if (sExpanded.IndexOf(oMacro.Name) >= 0)
               {
                  bFound = true;
                  sExpanded = sExpanded.Replace(oMacro.Name, oMacro.Value);
               }
            }
         }

         return sExpanded;
      }

      public BuildStep Get(int index)
      {
         return (BuildStep)m_oBuildSteps[index];
      }

      public int Count
      {
         get
         {
            return m_oBuildSteps.Count;
         }
      }


   }


}
