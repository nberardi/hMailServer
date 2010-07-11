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
      private string _VSPath;
      private string _innoSetupPath;
      private string _sourcePath;
      private string _subversionPath;
      private string _buildInstructions;
      private int _buildNumber;
      private string _version;

      public string VSPath
      {
         get
         {
            return _VSPath;
         }
         set
         {
            _VSPath = value;
         }
      }

      public string InnoSetupPath
      {
         get
         {
            return _innoSetupPath;
         }
         set
         {
            _innoSetupPath = value;
         }
      }

      public string SourcePath
      {
         get
         {
            return _sourcePath;
         }
         set
         {
            _sourcePath = value;
         }
      }

      public string SubversionPath
      {
         get
         {
            return _subversionPath;
         }
         set
         {
            _subversionPath = value;
         }
      }

      public string BuildInstructions
      {
         get
         {
            return _buildInstructions;
         }
         set
         {
            _buildInstructions = value;
         }
      }

      public int BuildNumber
      {
         get
         {
            return _buildNumber;
         }
         set
         {
            _buildNumber = value;
         }

      }

      public string Version
      {
         get
         {
            return _version;
         }
         set
         {
            _version = value;
         }

      }

      public void LoadSettings()
      {
         Configuration c = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

         SourcePath = c.AppSettings.Settings["SourcePath"].Value;
         VSPath = c.AppSettings.Settings["VS8Path"].Value;
         BuildNumber = Convert.ToInt32(c.AppSettings.Settings["BuildNumber"].Value);
         InnoSetupPath = c.AppSettings.Settings["InnoSetupPath"].Value;
         Version = c.AppSettings.Settings["Version"].Value;
         SubversionPath = c.AppSettings.Settings["SubversionPath"].Value;
         
         _buildInstructions = c.GetSection("build").SectionInformation.GetRawXml();
      }

      public void SaveSettings()
      {
         Configuration c = ConfigurationManager.OpenExeConfiguration("hMailServer builder.exe");

         c.AppSettings.Settings["SourcePath"].Value = SourcePath;
         c.AppSettings.Settings["BuildNumber"].Value = BuildNumber.ToString();
         c.AppSettings.Settings["Version"].Value = Version;
         c.AppSettings.Settings["VS8Path"].Value = VSPath;
         c.AppSettings.Settings["InnoSetupPath"].Value = InnoSetupPath;
         c.AppSettings.Settings["SubversionPath"].Value = SubversionPath;

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
