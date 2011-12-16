// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace Builder.Common
{
	public class BuildLoader
	{
		public Builder Load(string s)
		{
			Builder oBuilder = new Builder();

			XmlDocument oDoc = new XmlDocument();
			oDoc.LoadXml(s);

			XmlNode oBuildNode = oDoc.ChildNodes[0];

			for (int i = 0; i < oBuildNode.ChildNodes.Count; i++)
			{
				XmlNode oAction = oBuildNode.ChildNodes[i];

				if (oAction.NodeType == XmlNodeType.Comment)
					continue;

				string sType = oAction.Attributes["type"].Value;

				if (sType == "writefile")
					AddActionWritefile(oBuilder, oAction);
				else if (sType == "writeini")
					AddActionWriteIni(oBuilder, oAction);
				else if (sType == "runapplication")
					AddActionRunApplication(oBuilder, oAction);
				else if (sType == "compilevs")
					AddActionCompileVS(oBuilder, oAction);
				else if (sType == "msbuild")
					AddActionMSBuild(oBuilder, oAction);
				else if (sType == "copyfile")
					AddActionCopyFile(oBuilder, oAction);
				else if (sType == "compileinnosetup")
					AddActionCompileInnoSetup(oBuilder, oAction);
				else if (sType == "subversion")
					AddActionSubversion(oBuilder, oAction);
				else if (sType == "cleardirectory")
					AddActionClearDirectory(oBuilder, oAction);
				else
				{
					throw new Exception("Unknown build type " + sType);
				}

			}
			return oBuilder;
		}

		private void AddActionClearDirectory(Builder oBuilder, XmlNode oAction)
		{
			string directory = oAction.Attributes["directory"].Value;

			oBuilder.Add(new BuildStepClearDirectory(oBuilder, directory));
		}

		private void AddActionWritefile(Builder oBuilder, XmlNode oNode)
		{
			string sFile = oNode.Attributes["filename"].Value;
			string sValue = oNode.Attributes["value"].Value;
			sValue = sValue.Replace("\\r\\n", Environment.NewLine);

			oBuilder.Add(new BuildStepWriteFile(oBuilder, sFile, sValue));            
		}

		private void AddActionWriteIni(Builder oBuilder, XmlNode oNode)
		{
			string sFile = oNode.Attributes["filename"].Value;
			string sSection = oNode.Attributes["section"].Value;
			string sKey = oNode.Attributes["key"].Value;
			string sValue = oNode.Attributes["value"].Value;

			oBuilder.Add(new BuildStepWriteINI(oBuilder, sFile, sSection, sKey, sValue));
		}

		 private void AddActionCompileVS(Builder oBuilder, XmlNode oNode)
		 {
			 string sFile = oNode.Attributes["filename"].Value;
			 string sConfiguration = oNode.Attributes["configuration"].Value;

			 oBuilder.Add(new BuildStepCompileVSNet(oBuilder,
						sFile, sConfiguration));
		 }

		 private void AddActionMSBuild(Builder oBuilder, XmlNode oNode)
		 {
			 string sFile = oNode.Attributes["filename"].Value;
			 string sConfiguration = oNode.Attributes["configuration"].Value;

			 oBuilder.Add(new BuildStepMSBuild(oBuilder,
						sFile, sConfiguration));
		 }

		private void AddActionRunApplication(Builder oBuilder, XmlNode oNode)
		{
			string sFile = oNode.Attributes["filename"].Value;
			string sParameters = oNode.Attributes["parameters"].Value;
			oBuilder.Add(new BuildStepRunApplication(oBuilder, sFile, sParameters));
		}


		private void AddActionCopyFile(Builder oBuilder, XmlNode oNode)
		{
			string sFrom = oNode.Attributes["from"].Value;
			string sTo = oNode.Attributes["to"].Value;

			bool bOverwrite = false;
			XmlAttribute oAttr = oNode.Attributes["overwrite"];

			if (oAttr != null)
				bOverwrite = oAttr.Value == "true";

			oBuilder.Add(new BuildStepCopyFile(oBuilder, sFrom, sTo, bOverwrite));
		}

		private void AddActionCompileInnoSetup(Builder oBuilder, XmlNode oNode)
		{
			string sFilename = oNode.Attributes["filename"].Value;

			oBuilder.Add(new BuildStepInnoSetup(oBuilder, sFilename));
		}

		private void AddActionSubversion(Builder oBuilder, XmlNode oNode)
		{
			string sAction = oNode.Attributes["action"].Value;
			string sDirectory = oNode.Attributes["directory"].Value;

			BuildStepSubversion.SVNAction svnaction;

			if (sAction == "revert")
				svnaction = BuildStepSubversion.SVNAction.SVNRevert;
			else if (sAction == "update")
				svnaction = BuildStepSubversion.SVNAction.SVNUpdate;
			else
				throw new Exception("Incorrect SubVersion configuration");

			oBuilder.Add(new BuildStepSubversion(oBuilder,svnaction, sDirectory));
		}

		public static string ProgramFilesx86()
		{
		   if (8 == IntPtr.Size
			   || (!String.IsNullOrEmpty(Environment.GetEnvironmentVariable("PROCESSOR_ARCHITEW6432"))))
		   {
			  return Environment.GetEnvironmentVariable("ProgramFiles(x86)");
		   }

		   return Environment.GetEnvironmentVariable("ProgramFiles");
		}

	}

}
