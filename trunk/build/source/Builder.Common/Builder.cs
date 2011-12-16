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

      public delegate void MessageLogDelegate(bool timestamp, string message);
      public event MessageLogDelegate MessageLog;

      public Builder()
      {
         m_oBuildSteps = new System.Collections.ArrayList();
         m_oMacros = new System.Collections.ArrayList();

         StepStart = -1;
         StepEnd = -1;
      }

      public bool RunAllSteps
      {
         get
         {
            return StepStart == -1;
         }
      }

      public int StepStart
      {
		  get;
		  set;
      }

      public int StepEnd
      {
		  get;
		  set;
      }


      public string ParameterSourcePath
      {
		  get;
		  set;
      }

      public string ParameterVSPath
      {
		  get;
		  set;
      }

      public string ParameterInnoSetupPath
      {
		  get;
		  set;
      }

      public string ParameterSubversionPath
      {
		  get;
		  set;
      }

	  public string ParameterMSBuildPath
	  {
		  get;
		  set;
	  }

      public void LoadSettings(Settings settings)
      {
         ParameterSourcePath = settings.SourcePath;
         ParameterVSPath = settings.VSPath;
         ParameterInnoSetupPath = settings.InnoSetupPath;
         ParameterSubversionPath = settings.SubversionPath;
		 ParameterMSBuildPath = settings.MSBuildPath;
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
