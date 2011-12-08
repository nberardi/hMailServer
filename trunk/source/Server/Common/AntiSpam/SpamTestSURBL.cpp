// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "SpamTestSURBL.h"

#include "SpamTestData.h"
#include "SpamTestResult.h"

#include "SURBL.h"

#include "../BO/SURBLServers.h"

#include "../../SMTP/SPF/SPF.h"
#include "../../SMTP/BLCheck.h"
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   String 
   SpamTestSURBL::GetName() const
   {
      return "SpamTestSURBL";
   }

   bool 
   SpamTestSURBL::GetIsEnabled()
   {
      boost::shared_ptr<SURBLServers> pSURBLServers = Configuration::Instance()->GetAntiSpamConfiguration().GetSURBLServers();

      vector<boost::shared_ptr<SURBLServer> > vec = pSURBLServers->GetVector();
      vector<boost::shared_ptr<SURBLServer> >::iterator iter = vec.begin();
      vector<boost::shared_ptr<SURBLServer> >::iterator iterEnd = vec.end();

      for (; iter != iterEnd; iter++)
      {
         boost::shared_ptr<SURBLServer> pSURBLServer = (*iter);

         if (pSURBLServer->GetIsActive()) 
         {
            return true;
         }
      }

      return false;
   }

   set<boost::shared_ptr<SpamTestResult> >
   SpamTestSURBL::RunTest(boost::shared_ptr<SpamTestData> pTestData)
   {
      set<boost::shared_ptr<SpamTestResult> > setSpamTestResults;

      boost::shared_ptr<MessageData> pMessageData = pTestData->GetMessageData();
      boost::shared_ptr<SURBLServers> pSURBLServers = Configuration::Instance()->GetAntiSpamConfiguration().GetSURBLServers();

      SURBL surblTester;

      boost_foreach(boost::shared_ptr<SURBLServer> pSURBLServer, pSURBLServers->GetVector())
      {
         if (pSURBLServer->GetIsActive()) 
         {
            if (!surblTester.Run(pSURBLServer, pMessageData))
            {
               // Blocked
               int iSomeScore = pSURBLServer->GetScore();
               boost::shared_ptr<SpamTestResult> pResult = boost::shared_ptr<SpamTestResult>(new SpamTestResult(GetName(), SpamTestResult::Fail, iSomeScore, pSURBLServer->GetRejectMessage()));

               setSpamTestResults.insert(pResult);
            }
         }

      }      


      return setSpamTestResults;
   }

}