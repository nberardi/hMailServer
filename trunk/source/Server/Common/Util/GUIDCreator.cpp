// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "GUIDCreator.h"

namespace HM
{
   GUIDCreator::GUIDCreator()
   {

   }

   GUIDCreator::~GUIDCreator()
   {

   }

   String
   GUIDCreator::GetGUID()
   {
      GUID uuid;
      CoCreateGuid(&uuid);

      wchar_t szGUID[39];
      StringFromGUID2 (uuid, szGUID, 39);

      return szGUID;
   }
}
