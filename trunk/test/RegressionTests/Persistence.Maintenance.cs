// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace UnitTest.Persistence
{
   [TestFixture]
	public class Maintenance : TestFixtureBase
	{
      [Test]
      public void TestUpdateIMAPFolderUID()
      {
         // Set up a basic environment which we can work with.
         BackupRestore backupRestore = new BackupRestore();
         backupRestore.SetUp();
         backupRestore.SetupEnvironment();

         _application.Utilities.PerformMaintenance(hMailServer.eMaintenanceOperation.eUpdateIMAPFolderUID);
      }

      [Test]
      [ExpectedException(typeof(System.Runtime.InteropServices.COMException), ExpectedMessage="Unknown maintenance operation.")]
      public void TestUnknownOperation()
      {
         _application.Utilities.PerformMaintenance((hMailServer.eMaintenanceOperation) 234);
      }
	}
}
