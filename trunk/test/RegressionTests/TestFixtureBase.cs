// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using UnitTest;

namespace UnitTest
{
   public class TestFixtureBase
   {
      protected hMailServer.Domain _domain;
      protected hMailServer.Application _application;
      protected hMailServer.Settings _settings;

      [TestFixtureSetUp]
      public void TestFixtureSetUp()
      {
         SingletonProvider<Utilities>.Instance.Authenticate();

         _application = SingletonProvider<Utilities>.Instance.GetApp();
         _settings = _application.Settings;

         
      }

      [SetUp]
      public void SetUp()
      {
         _domain = SingletonProvider<Utilities>.Instance.DoBasicSetup();
      }
   }
}
