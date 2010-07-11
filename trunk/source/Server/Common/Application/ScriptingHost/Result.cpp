// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\result.h"


namespace HM
{
   Result::Result(void) :
      _parameter(0),
      m_lValue(0)
   {
      
   }

   Result::~Result(void)
   {
   }

   long
   Result::GetValue() const 
   {
      return m_lValue;
   }

   int
   Result::GetParameter() const 
   {
      return _parameter;
   }

   String
   Result::GetMessage() const
   {
      return m_sMessage;
   }
}