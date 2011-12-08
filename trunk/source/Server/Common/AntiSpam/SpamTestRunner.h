// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "SpamTest.h"

namespace HM
{
   class SpamTestData;
   class SpamTestResult;

   class SpamTestRunner
   {
   public:
      
      SpamTestRunner();
      virtual ~SpamTestRunner();

      void LoadSpamTests();

      set<boost::shared_ptr<SpamTestResult> > RunSpamTest(boost::shared_ptr<SpamTestData> pInputData, SpamTest::SpamTestType iType, int iMaxScore);

   private:

      std::vector<boost::shared_ptr<SpamTest> > m_setSpamTests;

   };

}