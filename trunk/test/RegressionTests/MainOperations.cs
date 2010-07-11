// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using System.Threading;

namespace UnitTest.Operations
{
   [TestFixture]
   public class MainOperations : TestFixtureBase
   {
      [SetUp]
      public void Setup()
      {
         SingletonProvider<Utilities>.Instance.DoBasicSetup();
      }

      [Test]
      public void RestartServer()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         for (int i = 0; i < 3; i++)
         {
            
            application.Stop();
                        
            application.Start();
         }
      }

      [Test]
      public void TestInternals()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();
         
         application.Utilities.RunTestSuite("I know what I am doing.");
         
      }

      [Test]
      public void TestLanguages()
      {
         hMailServer.Application application = SingletonProvider<Utilities>.Instance.GetApp();

         hMailServer.Language oLanguageSwedish = application.GlobalObjects.Languages.get_ItemByName("swedish");
         hMailServer.Language oLanguageEnglish = application.GlobalObjects.Languages.get_ItemByName("english");

         string sSWE = oLanguageSwedish.get_String("File");
         string sENG = oLanguageEnglish.get_String("File");

         Assert.AreEqual(sENG, "File");
         Assert.AreNotEqual(sSWE, sENG);
         Assert.AreNotEqual(sSWE, "");
         
      }
   }
}
