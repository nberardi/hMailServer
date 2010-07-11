// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"
#include ".\domainalias.h"

namespace HM
{
   DomainAlias::DomainAlias(void) :
      m_iDomainID(0)
   {

   }

   DomainAlias::~DomainAlias(void)
   {

   }

   bool 
   DomainAlias::XMLStore(XNode *pParentNode, int iOptions)
   {
      XNode *pNode = pParentNode->AppendChild(_T("DomainAlias"));
      pNode->AppendAttr(_T("Name"), m_sAlias);

      return true;

   }

   bool 
   DomainAlias::XMLLoad(XNode *pAliasNode, int iOptions)
   {
      m_sAlias = pAliasNode->GetAttrValue(_T("Name"));

      return true;
   }

}