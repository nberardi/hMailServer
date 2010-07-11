// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Assert.h"
namespace HM
{
   void
   Assert::IsTrue(bool argument)
   {
      if (!argument)
         throw;
   }

   void
   Assert::IsFalse(bool argument)
   {
      if (argument)
         throw;
   }


   void
   Assert::AreEqual(const String &str1, const String &str2)
   {
      if (str1 != str2)
         throw;

   }


}