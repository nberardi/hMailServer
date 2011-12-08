// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class MimeBody;

   class Attachment  
   {
   public:
	   Attachment(boost::shared_ptr<MimeBody> pMessage, boost::shared_ptr<MimeBody> pAttachment);
	   virtual ~Attachment();

      String GetFileName();
      int GetSize();
      void Delete();
      void SaveAs(const String &sSaveTo) const;
      
   private:
      
      boost::shared_ptr<MimeBody> m_pAttachment;
      boost::shared_ptr<MimeBody> m_pMessage;
   };

}
