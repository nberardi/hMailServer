// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Attachment;
   class MimeBody;
   class MessageData;

   class Attachments 
   {
   public:
	   Attachments(boost::shared_ptr<MimeBody> pMimeBody, MessageData *pMsgData);
	   virtual ~Attachments();

      bool Add(const String &sFilename);
      bool Add(boost::shared_ptr<Attachment> pAttachment);
      
      boost::shared_ptr<Attachment> GetItem(unsigned int index) const;

      size_t GetCount() const;
      void Clear();
      
      void Load();

   private:
      std::vector<boost::shared_ptr<Attachment> > vecObjects;

      boost::shared_ptr<MimeBody> m_pMimeBody;
      MessageData *m_pMsgData;
   };
}
