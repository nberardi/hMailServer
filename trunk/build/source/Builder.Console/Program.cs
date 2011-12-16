// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Builder.Common;
using System.Threading;

namespace Builder.Console
{
   class Program
   {
	  static void Main(string[] args)
	  {
		 if (args.Length != 3)
		 {
			System.Console.WriteLine("Wrong number of parameters passed to Builder.Console");
			Environment.ExitCode = -1;
			return;
		 }

		 Settings settings = new Settings();
		 settings.LoadSettings();

		 BuildLoader loader = new BuildLoader();
		 Builder.Common.Builder builder = loader.Load(settings.BuildInstructions);

		 // Run all steps.
		 builder.StepStart = -1;
		 builder.StepEnd = -1;

		 builder.LoadMacros(args[0], args[1], args[2]);

		 string result;
		 if (!settings.ValidateSettings(builder, out result))
		 {
			System.Console.WriteLine(result);
			Environment.ExitCode = -1;
			return;
		 }

		 builder.LoadSettings(settings);


		 ManualResetEvent eventStopThread= new ManualResetEvent(false);
		 ManualResetEvent eventThreadStopped= new ManualResetEvent(false);

		 BuildRunner runner = new BuildRunner(eventStopThread, eventThreadStopped, builder);
		 runner.StepError+= new BuildRunner.StepErrorDelegate(runner_StepError);
		 builder.MessageLog += new Builder.Common.Builder.MessageLogDelegate(builder_MessageLog);
		 runner.Run();

		 return;
	  }

	  static void builder_MessageLog(bool timestamp, string message)
	  {
		 if (timestamp)
			System.Console.Write(DateTime.Now + " - ");
		 
		 System.Console.WriteLine(message);
	  }

	  static void runner_StepError(int stepindex, string errorMessage)
	  {
		 System.Console.WriteLine(errorMessage);
		 Environment.ExitCode = -1;
	  }
   }
}
