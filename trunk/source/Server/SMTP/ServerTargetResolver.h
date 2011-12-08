// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class RuleResult;
   class ServerInfo;
   class MessageRecipient;

   class ServerTargetResolver
   {
   public:
      ServerTargetResolver(boost::shared_ptr<Message> message, const RuleResult &globalRuleResult);
      ~ServerTargetResolver(void);
      
      map<boost::shared_ptr<ServerInfo>, std::vector<boost::shared_ptr<MessageRecipient> > > Resolve();

   private:

      static boost::shared_ptr<ServerInfo> _GetFixedSMTPHostForDomain(const String &sDomain);

      boost::shared_ptr<Message> _message;
      const RuleResult &_globalRuleResult;
   };
}