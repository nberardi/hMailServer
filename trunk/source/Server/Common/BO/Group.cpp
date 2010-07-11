// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "Group.h"

#include "GroupMembers.h"
#include "Groups.h"

namespace HM
{
   Group::Group(void)
   {
      
   }

   Group::~Group(void)
   {
   }

   String 
   Group::GetName() const
   {
      return m_sName;
   }

   void 
   Group::SetName(const String &sName)
   {
      m_sName = sName;
   }

   shared_ptr<GroupMembers> 
   Group::GetMembers()
   {
      shared_ptr<GroupMembers> pGroupMembers = shared_ptr<GroupMembers>(new GroupMembers(m_iID));
      pGroupMembers->Refresh();

      return pGroupMembers;
   }

   bool 
   Group::UserIsMember(__int64 iAccountID)
   {
      return GetMembers()->UserIsMember(iAccountID);
   }

   bool 
   Group::XMLStore(XNode *pParentNode, int iOptions)
   {
      XNode *pNode = pParentNode->AppendChild(_T("Group"));

      pNode->AppendAttr(_T("Name"), m_sName);

      GetMembers()->XMLStore(pNode, iOptions);

      return true;
   }

   bool
   Group::XMLLoad(XNode *pNode, int iRestoreOptions)
   {
      m_sName = pNode->GetAttrValue(_T("Name"));

      return true;
   }


   bool
   Group::XMLLoadSubItems(XNode *pNode, int iRestoreOptions)
   {
      shared_ptr<GroupMembers> pGroupMembers = GetMembers();
      return pGroupMembers->XMLLoad(pNode, iRestoreOptions);
   }
}