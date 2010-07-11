// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Cacheable.h"

namespace HM
{
   Cacheable::Cacheable(void)
   {
      m_iCreationTime = GetTickCount();
   }

   Cacheable::~Cacheable(void)
   {
   }

   int 
   Cacheable::Seconds()
   {
      int iCurrentTime = GetTickCount();

      // Convert from milliseconds to seconds.
      int iAge = (iCurrentTime - m_iCreationTime) / 1000;

      if (iAge < 0)
         iAge = 60*60*24;

      return iAge;
   }
}