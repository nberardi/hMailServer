// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "distributionlistrecipient.h"

namespace HM
{
   DistributionListRecipient::DistributionListRecipient(void) :
      m_iListID(0)
   {

   }

   DistributionListRecipient::~DistributionListRecipient(void)
   {
   }

   void
   DistributionListRecipient::SetAddress(const String & sAddress)
   {
      m_sAddress = sAddress;
   }

   bool 
   DistributionListRecipient::XMLStore(XNode *pParentNode, int iOptions)
   {
      XNode *pNode = pParentNode->AppendChild(_T("Recipient"));

      pNode->AppendAttr(_T("Name"), m_sAddress);

      return true;
   }

   bool 
   DistributionListRecipient::XMLLoad(XNode *pNode, int iOptions)
   {
      m_sAddress = pNode->GetAttrValue(_T("Name"));

      return true;
   }
}