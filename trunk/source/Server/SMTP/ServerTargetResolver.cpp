// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "ServerTargetResolver.h"

#include "SMTPConfiguration.h"

#include "../Common/BO/Message.h"
#include "../Common/BO/Route.h"
#include "../Common/BO/Routes.h"
#include "../Common/BO/MessageRecipient.h"
#include "../Common/BO/MessageRecipients.h"
#include "../Common/BO/Rule.h"
#include "../Common/Util/ServerInfo.h"

#include "RuleResult.h"

namespace HM
{
   ServerTargetResolver::ServerTargetResolver(shared_ptr<Message> message, const RuleResult& globalRuleResult) :
      _globalRuleResult(globalRuleResult),
      _message(message)
   {
      
   }

   ServerTargetResolver::~ServerTargetResolver(void)
   {
   }

   map<shared_ptr<ServerInfo>, std::vector<shared_ptr<MessageRecipient> > >
   ServerTargetResolver::Resolve() 
   {  
      map<shared_ptr<ServerInfo>, vector<shared_ptr<MessageRecipient> > > result;

      // first check if all recipients should be delivered via a specific
      // route. if this is the case there's no point in doing any further
      // resolving.
      __int64 iFixedRouteID = _globalRuleResult.GetSendUsingRoute();
      if (iFixedRouteID > 0)
      {
         shared_ptr<Route> pRoute = HM::Configuration::Instance()->GetSMTPConfiguration()->GetRoutes()->GetItemByDBID(iFixedRouteID);
         if (pRoute)
         {
            String domainName = pRoute->DomainName();
            shared_ptr<ServerInfo> serverInfo = _GetFixedSMTPHostForDomain(domainName);

            if (serverInfo)
            {
               // all recipients should go into the same domain.
               std::vector<shared_ptr<MessageRecipient> > recipients;
               boost_foreach(shared_ptr<MessageRecipient> recipient, _message->GetRecipients()->GetVector())
               {
                  recipients.push_back(recipient);
               }

               result.insert(std::make_pair(serverInfo, recipients));
               return result;
            }
          }
      }

      // sort all recipients per domain, domain in lower case. this is done
      // so that we only need to look for routes for every domain once.
      map<String, vector<shared_ptr<MessageRecipient> > > sortedRecipients;
      boost_foreach(shared_ptr<MessageRecipient> recipient, _message->GetRecipients()->GetVector())
      {
         String domainName = StringParser::ExtractDomain(recipient->GetAddress()).ToLower();

         if (sortedRecipients.find(domainName) == sortedRecipients.end())
         {
            vector<shared_ptr<MessageRecipient> > recipientsOnDomain;
            recipientsOnDomain.push_back(recipient);

            sortedRecipients[domainName] = recipientsOnDomain;
         }
         else
         {
            sortedRecipients[domainName].push_back(recipient);
         }
      }      

      // check whether the recipient hosts are fixed or if we need
      // to do a mx resolve later on.
      map<String, vector<shared_ptr<MessageRecipient> > >::iterator iter = sortedRecipients.begin();
      map<String, vector<shared_ptr<MessageRecipient> > >::iterator iterEnd = sortedRecipients.end();

      for (; iter != iterEnd; iter++)
      {
         String domainName = (*iter).first;
         vector<shared_ptr<MessageRecipient> > vecRecipients = (*iter).second;

         shared_ptr<ServerInfo> serverInfo = _GetFixedSMTPHostForDomain(domainName);
         if (!serverInfo)
            serverInfo = shared_ptr<ServerInfo>(new ServerInfo(false, domainName, 0, "", "", false));

         result.insert(std::make_pair(serverInfo, vecRecipients));
      }

      return result;
   }

   shared_ptr<ServerInfo>
   ServerTargetResolver::_GetFixedSMTPHostForDomain(const String &sDomain)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Check if there exists a fixed SMTP host for the domain given, and in that
   // case it returns it. May be used for example for routes or when a SMTP
   // relayer is used.
   //---------------------------------------------------------------------------()
   {
      String sSMTPHost;
      long lPort = 0;
      String sUsername;
      String sPassword;
      bool bUseSSL = false;

      shared_ptr<SMTPConfiguration> pSMTPConfig = Configuration::Instance()->GetSMTPConfiguration();

      // Check if we have any route for this domain.
      shared_ptr<Route> pRoute = pSMTPConfig->GetRoutes()->GetItemByName(sDomain);

      if (pRoute)
      {
         sSMTPHost = pRoute->TargetSMTPHost();
         lPort = pRoute->TargetSMTPPort();
         bUseSSL = pRoute->GetUseSSL();

         if (pRoute->GetRelayerRequiresAuth())
         {
            sUsername = pRoute->GetRelayerAuthUsername();
            sPassword = pRoute->GetRelayerAuthPassword();
         }
      }
      else
      {
         // Do we have a fixed SMTP relayer?
         String sRelayer = pSMTPConfig->GetSMTPRelayer();

         if (!sRelayer.IsEmpty())
         {
            sSMTPHost = sRelayer;
            lPort = pSMTPConfig->GetSMTPRelayerPort();
            if (lPort == 0)
               lPort = 25;

            if (pSMTPConfig->GetSMTPRelayerRequiresAuthentication())
            {
               sUsername = pSMTPConfig->GetSMTPRelayerUsername();
               sPassword = pSMTPConfig->GetSMTPRelayerPassword();
            }

            bUseSSL = pSMTPConfig->GetSMTPRelayerUseSSL();
         }
      }

      if (sSMTPHost.IsEmpty())
      {
         return shared_ptr<ServerInfo>();
      }

      shared_ptr<ServerInfo> serverInfo(new ServerInfo(true, sSMTPHost, lPort, sUsername, sPassword, bUseSSL));
      return serverInfo;

   }

}