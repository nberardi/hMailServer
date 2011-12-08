// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

#include "IMAPCommand.h"
#include "IMAPSearchParser.h"


namespace HM
{
   class IMAPSearchParser;
   class IMAPConnection;
   class MessageData;
   class MimeHeader;

   class IMAPCommandSEARCH : public IMAPCommand
   {
   public:
	   IMAPCommandSEARCH(bool bIsSort);
	   virtual ~IMAPCommandSEARCH();

      void SetIsUID() { m_bIsUID = true; }

      IMAPResult ExecuteCommand(boost::shared_ptr<IMAPConnection> pConnection, boost::shared_ptr<IMAPCommandArgument> pArgument);

   private:

      bool _MatchesHeaderCriteria(const String &fileName,boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesUIDCriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSequenceSetCriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria, int index);
      bool _MatchesTEXTCriteria(const String &fileName, boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesBODYCriteria(const String &fileName, boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesONCriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSENTONCriteria(const String &fileName, boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSENTBEFORECriteria(const String &fileName, boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSENTSINCECriteria(const String &fileName, boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSINCECriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      
      bool _MatchesBEFORECriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesLARGERCriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);
      bool _MatchesSMALLERCriteria(boost::shared_ptr<Message> pMessage, boost::shared_ptr<IMAPSearchCriteria> pCriteria);

      String _GetHeaderValue(const String &fileName, boost::shared_ptr<Message> pMessage, const String &sHeaderField);
      
      
      bool _DoesMessageMatch(boost::shared_ptr<IMAPSearchCriteria> pParentCriteria, const String &fileName, boost::shared_ptr<Message> pMessage, int index);

      boost::shared_ptr<MessageData> m_pMessageData;
      boost::shared_ptr<MimeHeader> m_pMimeHeader;

      bool m_bIsSort;
      bool m_bIsUID;
   };
}
