// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class DatabaseSettings;

   class DALConnectionFactory  
   {
   public:
	   DALConnectionFactory();
	   virtual ~DALConnectionFactory();


      static boost::shared_ptr<DALConnection> CreateConnection(boost::shared_ptr<DatabaseSettings> pSettings);

   };
}
