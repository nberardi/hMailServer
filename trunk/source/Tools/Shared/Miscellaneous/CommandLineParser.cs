// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;

namespace hMailServer.Shared
{
   public class CommandLineParser
   {
      private static List<string> _arguments = null;
      private static Dictionary<string, string> _parsedArguments = null;

      public static void Parse()
      {
         _arguments = new List<string>();
         _parsedArguments = new Dictionary<string, string>();
         
         string[] arguments = Environment.GetCommandLineArgs();

         bool first = true;

         foreach (string argument in arguments)
         {
             // The first argument is the executable name. We're never interested in this.
             if (first)
             {
                 first = false;
                 continue;
             }

            _arguments.Add(argument);

            if (argument.IndexOf(":") > 0)
            {
               string name = argument.Substring(0, argument.IndexOf(":"));
               string value = argument.Substring(argument.IndexOf(":")+1);

               _parsedArguments[name] = value;
            }
         }
      }

      public static bool ContainsArgument(string argument)
      {
         if (_arguments == null)
            return false;

         foreach (string arg in _arguments)
         {
            if (arg.ToLower() == argument.ToLower())
               return true;
         }

         return false;
      }

      public static bool IsSilent()
      {
         if (_arguments == null)
            return false;

         foreach (string arg in _arguments)
         {
            if (arg.ToLower() == "/silent")
               return true;
         }

         return false;
      }

      public static Dictionary<string, string> GetParsedArguments()
      {
         return _parsedArguments;
      }

   }
}
