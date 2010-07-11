// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "SSLCertificate.h"

namespace HM
{
   SSLCertificate::SSLCertificate(void)
   {
      
   }

   SSLCertificate::~SSLCertificate(void)
   {
   }

   bool 
   SSLCertificate::XMLStore(XNode *pParentNode, int iOptions)
   {
      XNode *pNode = pParentNode->AppendChild(_T("SSLCertificate"));

      pNode->AppendAttr(_T("Name"), m_sName);
      pNode->AppendAttr(_T("CertificateFile"), m_sCertificateFile);
      pNode->AppendAttr(_T("PrivateKeyFile"), m_sPrivateKeyFile);

      return true;
   }

   bool 
   SSLCertificate::XMLLoad(XNode *pNode, int iOptions)
   {
      m_sName = pNode->GetAttrValue(_T("Name"));
      m_sCertificateFile = pNode->GetAttrValue(_T("CertificateFile"));
      m_sPrivateKeyFile = pNode->GetAttrValue(_T("PrivateKeyFile"));

      return true;
   }
}