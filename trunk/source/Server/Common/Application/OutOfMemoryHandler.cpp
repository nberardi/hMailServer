// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "OutOfMemoryHandler.h"

namespace HM
{
   _PNH OutOfMemoryHandler::pOriginalNewHandler = 0;
   CriticalSection m_gcCritSecFree;
   
   OutOfMemoryHandler::OutOfMemoryHandler(void)
   {
   }

   OutOfMemoryHandler::~OutOfMemoryHandler(void)
   {
   }

   int OnOutOfMemory( size_t )
   {
		exit(255);
      return 0;
   }

   void 
   OutOfMemoryHandler::Initialize()
   {     
      pOriginalNewHandler = _set_new_handler( OnOutOfMemory );
      _set_new_mode(1);
   }

   void 
   OutOfMemoryHandler::Terminate()
   {
      _set_new_handler(pOriginalNewHandler);
   }
}