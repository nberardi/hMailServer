// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "IMAPConfiguration.h"

#include "../Common/Application/Configuration.h"
#include "../common/Application/ObjectCache.h"
#include "../Common/BO/IMAPFolders.h"
#include "../Common/BO/Groups.h"

#include "../Common/Persistence/PersistentIMAPFolder.h"
#include "../Common/Persistence/PersistentRuleAction.h"

namespace HM
{

   IMAPConfiguration::IMAPConfiguration()
   {

   }

   IMAPConfiguration::~IMAPConfiguration()
   {

   }

   bool
   IMAPConfiguration::Load()
   {
      // Shared public have their AccountID set to zero.
      m_pPublicFolders = shared_ptr<IMAPFolders>(new IMAPFolders(0, -1));
      m_pPublicFolders->Refresh();

      // Shared public have their AccountID set to zero.
      m_pGroups = shared_ptr<Groups>(new Groups());
      m_pGroups->Refresh();

      return true;
   }

   shared_ptr<PropertySet>
   IMAPConfiguration::_GetSettings() const
   {
      return Configuration::Instance()->GetSettings();
   }

   String 
   IMAPConfiguration::GetWelcomeMessage() const
   {
      return _GetSettings()->GetString(PROPERTY_WELCOMEIMAP);
   }
   
   void 
   IMAPConfiguration::SetWelcomeMessage(const String &sMessage)
   {
      _GetSettings()->SetString(PROPERTY_WELCOMEIMAP, sMessage);
   }

   bool
   IMAPConfiguration::GetUseIMAPQuota() const
   {
      return _GetSettings()->GetBool(PROPERTY_ENABLEIMAPQUOTA);
   }

   void 
   IMAPConfiguration::SetUseIMAPQuota(bool bValue)
   {
      _GetSettings()->SetBool(PROPERTY_ENABLEIMAPQUOTA, bValue);
   }

   bool 
   IMAPConfiguration::GetUseIMAPIdle() const
   {
      return _GetSettings()->GetBool(PROPERTY_ENABLEIMAPIDLE);
   }

   void 
   IMAPConfiguration::SetUseIMAPIdle(bool bValue)
   {
      _GetSettings()->SetBool(PROPERTY_ENABLEIMAPIDLE, bValue);
   }

   bool 
   IMAPConfiguration::GetUseIMAPACL() const
   {
      return _GetSettings()->GetBool(PROPERTY_ENABLEIMAPACL);
   }

   void 
   IMAPConfiguration::SetUseIMAPACL(bool bValue)
   {
      _GetSettings()->SetBool(PROPERTY_ENABLEIMAPACL, bValue);
   }

   bool 
   IMAPConfiguration::GetUseIMAPSort() const
   {
      return _GetSettings()->GetBool(PROPERTY_ENABLEIMAPSORT);
   }

   void 
   IMAPConfiguration::SetUseIMAPSort(bool bValue)
   {
      _GetSettings()->SetBool(PROPERTY_ENABLEIMAPSORT, bValue);
   }

   void
   IMAPConfiguration::SetMaxIMAPConnections(int newVal)
   {
      _GetSettings()->SetLong(PROPERTY_MAXIMAPCONNECTIONS, newVal);
   }

   long
   IMAPConfiguration::GetMaxIMAPConnections() const
   {
      return _GetSettings()->GetLong(PROPERTY_MAXIMAPCONNECTIONS);
   }

   void
   IMAPConfiguration::SetIMAPPublicFolderName(const String& newVal)
   {
      _GetSettings()->SetString(PROPERTY_IMAPPUBLICFOLDERNAME, newVal);
   }

   String
   IMAPConfiguration::GetIMAPPublicFolderName() const
   {
      return _GetSettings()->GetString(PROPERTY_IMAPPUBLICFOLDERNAME);
   }

   bool
   IMAPConfiguration::SetHierarchyDelimiter(const String& newVal)
   {
      if (GetHierarchyDelimiter() == newVal)
         return true;

      // Check that no IMAP folder contains this character.
      if (PersistentIMAPFolder::GetExistsFolderContainingCharacter(newVal))
         return false;

      // Check that no rule action exists containing this character.
      if (PersistentRuleAction::GetExistsFolderReferenceContainingCharacter(newVal))
         return false;

      // We need to replace the hierarchy delimiter in all rule actions.
      if (!PersistentRuleAction::UpdateHierarchyDelimiter(GetHierarchyDelimiter(), newVal))
         return false;

      _GetSettings()->SetString(PROPERTY_IMAP_HIERARCHY_DELIMITER, newVal);

      ObjectCache::Instance()->ClearRuleCaches();

      return true;
   }

   String
   IMAPConfiguration::GetHierarchyDelimiter()
   {
      return _GetSettings()->GetString(PROPERTY_IMAP_HIERARCHY_DELIMITER);
   }

   String 
   IMAPConfiguration::GetPublicFolderDiskName()
   {
      return "#Public";
   }

   shared_ptr<IMAPFolders> 
   IMAPConfiguration::GetPublicFolders()
   {
      return m_pPublicFolders;
   }


   shared_ptr<Groups> 
   IMAPConfiguration::GetGroups()
   {
      return m_pGroups;
   }

   bool 
   IMAPConfiguration::XMLStore(XNode *pBackupNode, int iOptions)
   {
      // Public folders
      shared_ptr<IMAPFolders> pIMAPFolders = GetPublicFolders();
      pIMAPFolders->XMLStore(pBackupNode, iOptions);

      if (!GetGroups()->XMLStore(pBackupNode, iOptions))
         return false;

      return true;
   }

   bool
   IMAPConfiguration::XMLLoad(XNode *pBackupNode, int iRestoreOptions)
   {
      GetGroups()->XMLLoad(pBackupNode, iRestoreOptions);

      // Should we restore messages as well?
      if (iRestoreOptions & Backup::BOMessages)
      {
         GetPublicFolders()->XMLLoad(pBackupNode, iRestoreOptions);
      }

      return true;
   }


}