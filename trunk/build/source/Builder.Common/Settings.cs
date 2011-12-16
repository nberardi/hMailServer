// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Configuration;

namespace Builder.Common
{
	public class Settings
	{
		public string MSBuildPath { get; set; }

		public string VSPath { get; set; }

		public string InnoSetupPath { get; set; }

		public string SourcePath { get; set; }

		public string SubversionPath { get; set; }

		public string BuildInstructions { get; set; }

		public int BuildNumber { get; set; }

		public string Version { get; set; }

		public void LoadSettings()
		{
			Configuration c = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

			SourcePath = c.AppSettings.Settings["SourcePath"].Value;
			VSPath = c.AppSettings.Settings["VSPath"].Value;
			BuildNumber = Convert.ToInt32(c.AppSettings.Settings["BuildNumber"].Value);
			InnoSetupPath = c.AppSettings.Settings["InnoSetupPath"].Value;
			Version = c.AppSettings.Settings["Version"].Value;
			SubversionPath = c.AppSettings.Settings["SubversionPath"].Value;
			MSBuildPath = c.AppSettings.Settings["MSBuildPath"].Value;

			BuildInstructions = c.GetSection("build").SectionInformation.GetRawXml();
		}

		public void SaveSettings()
		{
			Configuration c = ConfigurationManager.OpenExeConfiguration("hMailServer builder.exe");

			c.AppSettings.Settings["SourcePath"].Value = SourcePath;
			c.AppSettings.Settings["BuildNumber"].Value = BuildNumber.ToString();
			c.AppSettings.Settings["Version"].Value = Version;
			c.AppSettings.Settings["VSPath"].Value = VSPath;
			c.AppSettings.Settings["InnoSetupPath"].Value = InnoSetupPath;
			c.AppSettings.Settings["SubversionPath"].Value = SubversionPath;
			c.AppSettings.Settings["MSBuildPath"].Value = MSBuildPath;

			c.Save(ConfigurationSaveMode.Modified);
		}

		public bool ValidateSettings(Builder builder, out string result)
		{
			if (!File.Exists(builder.ExpandMacros(VSPath)))
			{
				result = "The Visual Studio executable does not exist in the specified path\r\n";
				return false;
			}

			if (!File.Exists(builder.ExpandMacros(InnoSetupPath)))
			{
				result = "The InnoSetup executable does not exist in the specified path\r\n";
				return false;
			}

			if (!Directory.Exists(builder.ExpandMacros(SourcePath)))
			{
				result = "The hMailserver source code does not exist in the specified path\r\n";
				return false;
			}

			result = "";
			return true;
		}
	}
}