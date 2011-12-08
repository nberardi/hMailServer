// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "SpamTest.h"

namespace HM
{
   class SpamTestDNSBlackLists : public SpamTest
   {
   public:
      
      virtual SpamTestType GetTestType()
      {
         return SpamTest::PreTransmission;
      }

      virtual String GetName() const;
      virtual bool GetIsEnabled();

      virtual set<boost::shared_ptr<SpamTestResult> > RunTest(boost::shared_ptr<SpamTestData> pTestData);

   private:

   };

}