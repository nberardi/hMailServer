// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include "GreyListingWhiteAddress.h"

namespace HM
{
   GreyListingWhiteAddress::GreyListingWhiteAddress(void) 
   {
      
   }

   GreyListingWhiteAddress::~GreyListingWhiteAddress(void)
   {
   }

   
   String
   GreyListingWhiteAddress::GetName() const
   {  
      return m_sWhiteIPAddress;
   }

   bool 
   GreyListingWhiteAddress::XMLStore(XNode *pParentNode, int iOptions)
   {
      XNode *pNode = pParentNode->AppendChild(_T("WhiteAddress"));

      pNode->AppendAttr(_T("Name"), GetName());
      pNode->AppendAttr(_T("WhiteIPDescription"), m_sWhiteIPDescription);

      return true;
   }

   bool 
   GreyListingWhiteAddress::XMLLoad(XNode *pNode, int iOptions)
   {
      m_sWhiteIPAddress = pNode->GetAttrValue(_T("Name"));
      m_sWhiteIPDescription = pNode->GetAttrValue(_T("WhiteIPDescription"));

      return true;
   }

   String 
   GreyListingWhiteAddress::GetIPAddress() const
   {
      return m_sWhiteIPAddress;
   }


   void
   GreyListingWhiteAddress::SetIPAddress(const String &sIPAddress)
   {
      m_sWhiteIPAddress = sIPAddress;
   }

   String 
   GreyListingWhiteAddress::GetUserEditableIPAddress() const
   {
      return SQLStatement::ConvertLikeToWildcard(m_sWhiteIPAddress);
   }


   void
   GreyListingWhiteAddress::SetUserEditableIPAddress(const String &sIPAddress)
   {
      m_sWhiteIPAddress = SQLStatement::ConvertWildcardToLike(sIPAddress);
   }
}
