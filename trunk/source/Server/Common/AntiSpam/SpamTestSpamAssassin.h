// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "SpamTest.h"

namespace HM
{
   class SpamTestSpamAssassin : public SpamTest
   {
   public:
      
      virtual SpamTestType GetTestType()
      {
         return SpamTest::PostTransmission;
      }

      virtual String GetName() const;
      virtual bool GetIsEnabled();
      virtual set<boost::shared_ptr<SpamTestResult> > RunTest(boost::shared_ptr<SpamTestData> pTestData);

   private:

      int _ParseSpamAssassinScore(const AnsiString &sHeader);

      

   };

}