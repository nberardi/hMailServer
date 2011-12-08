// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class Message;
   class MimeBody;
   class CMimeMessage;
   
   
   class MessageAttachmentStripper  
   {
   public:
	   MessageAttachmentStripper();
	   virtual ~MessageAttachmentStripper();

      static void Strip(boost::shared_ptr<Message> pMessage);
   private:
      
      static void _WriteToDisk(boost::shared_ptr<Message> pMessage, MimeBody &oMainMessage, boost::shared_ptr<MimeBody> pBody);
      static bool _IsGoodTextPart(boost::shared_ptr<MimeBody> pBody);
   };

}