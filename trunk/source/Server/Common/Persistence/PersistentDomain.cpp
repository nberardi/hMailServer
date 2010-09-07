// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "PersistentDomain.h"
#include "PersistentAccount.h"
#include "PersistentAlias.h"
#include "PersistentDistributionList.h"

#include "../BO/Domain.h"
#include "../BO/DomainAliases.h"
#include "../BO/Accounts.h"
#include "../BO/Groups.h"
#include "../BO/Aliases.h"
#include "../BO/Account.h"
#include "../BO/DistributionLists.h"
#include "../Cache/Cache.h"

#include "PreSaveLimitationsCheck.h"

#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

namespace HM
{
   PersistentDomain::PersistentDomain()
   {

   }

   PersistentDomain::~PersistentDomain()
   {

   }

   bool
   PersistentDomain::DeleteObject(shared_ptr<Domain> pDomain)
   {
      __int64 iDomainID = pDomain->GetID();
      assert(iDomainID);

      if (iDomainID > 0)
      {
         if (!pDomain->GetAccounts()->DeleteAll())
            return false;

         if (!pDomain->GetAliases()->DeleteAll())
            return false;

         if (!pDomain->GetDistributionLists()->DeleteAll())
            return false;

         if (!pDomain->GetDomainAliases()->DeleteAll())
            return false;

         SQLCommand command("delete from hm_domains where domainid = @DOMAINID");
         command.AddParameter("@DOMAINID", iDomainID);
           
         if (!Application::Instance()->GetDBManager()->Execute(command))
            return false;
         
         // Refresh the BO cache
         Cache<Domain, PersistentDomain>::Instance()->RemoveObject(pDomain);

         // Delete folder from data directory
         String sDomainFolder = IniFileSettings::Instance()->GetDataDirectory() + "\\" + pDomain->GetName();
         FileUtilities::DeleteDirectory(sDomainFolder);

         return true;

      }

      return true;
   }

   bool
   PersistentDomain::_RenameDomain(shared_ptr<Domain> pDomain)
   {
      // Update accounts...
      std::vector<shared_ptr<Account> > vecAccounts = pDomain->GetAccounts()->GetVector();
      std::vector<shared_ptr<Account> >::iterator iterAccount = vecAccounts.begin();
      std::vector<shared_ptr<Account> >::iterator iterAccountEnd = vecAccounts.end();

      for (; iterAccount != iterAccountEnd; iterAccount++)
      {
         shared_ptr<Account> pAccount = (*iterAccount);
         
         String sAddress = pAccount->GetAddress();
         _UpdateDomainName(sAddress, pDomain);
         pAccount->SetAddress(sAddress);

         PersistentAccount::SaveObject(pAccount);
      }

      // Update aliases...
      std::vector<shared_ptr<Alias> > vecAliases = pDomain->GetAliases()->GetVector();
      std::vector<shared_ptr<Alias> >::iterator iterAlias = vecAliases.begin();
      std::vector<shared_ptr<Alias> >::iterator iterAliasEnd = vecAliases.end();

      for (; iterAlias != iterAliasEnd; iterAlias++)
      {
         shared_ptr<Alias> pAlias = (*iterAlias);

         String sAddress = pAlias->GetName();
         _UpdateDomainName(sAddress, pDomain);
         pAlias->SetName(sAddress);

         PersistentAlias::SaveObject(pAlias);
      }

      // Update lists...
      std::vector<shared_ptr<DistributionList> > vecLists = pDomain->GetDistributionLists()->GetVector();
      std::vector<shared_ptr<DistributionList> >::iterator iterList = vecLists.begin();
      std::vector<shared_ptr<DistributionList> >::iterator iterListEnd = vecLists.end();

      for (; iterList != iterListEnd; iterList++)
      {
         shared_ptr<DistributionList> pList = (*iterList);

         String sAddress = pList->GetAddress();
         _UpdateDomainName(sAddress, pDomain);
         pList->SetAddress(sAddress);

         PersistentDistributionList::SaveObject(pList);
      }

      return true;
   }

   void 
   PersistentDomain::_UpdateDomainName(String &sAddress, shared_ptr<Domain> pDomain)
   {
      int atPos = sAddress.Find(_T("@"));
      if (atPos < 0)
      {
         // Doesn't seem to contain the domain name.
         return;
      }
      
      // Remove the current domain name.
      sAddress = sAddress.Mid(0, atPos+1);

      // Add the new one.
      sAddress += pDomain->GetName();
   }

   bool
   PersistentDomain::ReadObject(shared_ptr<Domain> pDomain, __int64 ObjectID)
   {
      SQLCommand command("select * from hm_domains where domainid = @DOMAINID");
      command.AddParameter("@DOMAINID", ObjectID);

      bool bResult = ReadObject(pDomain, command);

      return bResult;
   }

   bool
   PersistentDomain::ReadObject(shared_ptr<Domain> pDomain, const String & sDomainName)
   {
      SQLStatement statement;

      statement.SetStatementType(SQLStatement::STSelect);
      statement.SetTable("hm_domains");
      statement.AddWhereClauseColumn("domainname", sDomainName);

      bool bResult = ReadObject(pDomain, statement.GetCommand());

      return bResult;
   }


   bool
   PersistentDomain::ReadObject(shared_ptr<Domain> pDomain, const SQLCommand &command)
   {
      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      bool bRetVal = false;
      if (!pRS->IsEOF())
         bRetVal = ReadObject(pDomain, pRS);

      return bRetVal;
   }



   bool
   PersistentDomain::ReadObject(shared_ptr<Domain> pDomain, shared_ptr<DALRecordset> pRS)
   {
      pDomain->SetID(pRS->GetLongValue("domainid"));
      pDomain->SetName(pRS->GetStringValue("domainname"));
      pDomain->SetIsActive(pRS->GetLongValue("domainactive") == 1);
      pDomain->SetPostmaster(pRS->GetStringValue("domainpostmaster"));
      pDomain->SetADDomainName(pRS->GetStringValue("domainaddomain"));
      pDomain->SetMaxMessageSize(pRS->GetLongValue("domainmaxmessagesize"));
      pDomain->SetMaxAccountSize(pRS->GetLongValue("domainmaxaccountsize"));

      pDomain->SetUsePlusAddressing(pRS->GetLongValue("domainuseplusaddressing") ? true : false);
      pDomain->SetPlusAddressingChar(pRS->GetStringValue("domainplusaddressingchar"));
      pDomain->SetAntiSpamOptions(pRS->GetLongValue("domainantispamoptions"));
      pDomain->SetMaxSizeMB(pRS->GetLongValue("domainmaxsize"));

      pDomain->SetEnableSignature(pRS->GetLongValue("domainenablesignature") ? true : false);
      pDomain->SetSignatureMethod((Domain::DomainSignatureMethod) pRS->GetLongValue("domainsignaturemethod"));
      pDomain->SetSignaturePlainText(pRS->GetStringValue("domainsignatureplaintext"));
      pDomain->SetSignatureHTML(pRS->GetStringValue("domainsignaturehtml"));

      pDomain->SetAddSignaturesToReplies(pRS->GetLongValue("domainaddsignaturestoreplies") ? true : false);
      pDomain->SetAddSignaturesToLocalMail(pRS->GetLongValue("domainaddsignaturestolocalemail") ? true : false);

      pDomain->SetMaxNoOfAccounts(pRS->GetLongValue("domainmaxnoofaccounts"));
      pDomain->SetMaxNoOfAliases(pRS->GetLongValue("domainmaxnoofaliases"));
      pDomain->SetMaxNoOfDistributionLists(pRS->GetLongValue("domainmaxnoofdistributionlists"));
      
      pDomain->SetLimitationsEnabled(pRS->GetLongValue("domainlimitationsenabled"));

      pDomain->SetDKIMSelector(pRS->GetStringValue("domaindkimselector"));
      pDomain->SetDKIMPrivateKeyFile(pRS->GetStringValue("domaindkimprivatekeyfile"));

      return true;
   }

   bool
   PersistentDomain::SaveObject(shared_ptr<Domain> pDomain)
   {
      String sErrorMessage;
      return SaveObject(pDomain, sErrorMessage);
   }

   bool
   PersistentDomain::SaveObject(shared_ptr<Domain> pDomain, String &sErrorMessage)
   {
      if (!PreSaveLimitationsCheck::CheckLimitations(pDomain, sErrorMessage))
         return false;

      __int64 iID = pDomain->GetID();
      if (iID > 0)
      {
         // First read the domain to see if we've changed its name.
         shared_ptr<Domain> pTempDomain = shared_ptr<Domain>(new Domain());
         if (!PersistentDomain::ReadObject(pTempDomain, iID))
            return false;

         if (pTempDomain->GetName().CompareNoCase(pDomain->GetName()) != 0)
         {
            // Name has been changed. Rename all sub objects first.
            _RenameDomain(pDomain);
         }
      }

      SQLStatement oStatement;
      oStatement.AddColumn("domainname", pDomain->GetName());
      oStatement.AddColumn("domainactive", pDomain->GetIsActive());
      oStatement.AddColumn("domainpostmaster", pDomain->GetPostmaster());
      oStatement.AddColumn("domainmaxsize", pDomain->GetMaxSizeMB());
      oStatement.AddColumn("domainaddomain", pDomain->GetADDomainName());
      oStatement.AddColumn("domainmaxmessagesize", pDomain->GetMaxMessageSize());
      oStatement.AddColumn("domainmaxaccountsize", pDomain->GetMaxAccountSize());

      oStatement.AddColumn("domainuseplusaddressing", pDomain->GetUsePlusAddressing());
      oStatement.AddColumn("domainplusaddressingchar", pDomain->GetPlusAddressingChar());
      oStatement.AddColumn("domainantispamoptions", pDomain->GetAntiSpamOptions());

      oStatement.AddColumn("domainenablesignature", pDomain->GetEnableSignature());
      oStatement.AddColumn("domainsignaturemethod", pDomain->GetSignatureMethod());
      oStatement.AddColumn("domainsignatureplaintext", pDomain->GetSignaturePlainText());
      oStatement.AddColumn("domainsignaturehtml", pDomain->GetSignatureHTML());
      oStatement.AddColumn("domainaddsignaturestoreplies", pDomain->GetAddSignaturesToReplies());
      oStatement.AddColumn("domainaddsignaturestolocalemail", pDomain->GetAddSignaturesToLocalMail());

      oStatement.AddColumn("domainmaxnoofaccounts", pDomain->GetMaxNoOfAccounts());
      oStatement.AddColumn("domainmaxnoofaliases", pDomain->GetMaxNoOfAliases());
      oStatement.AddColumn("domainmaxnoofdistributionlists", pDomain->GetMaxNoOfDistributionLists());
      oStatement.AddColumn("domainlimitationsenabled", pDomain->GetLimitationsEnabled());

      oStatement.AddColumn("domaindkimselector", pDomain->GetDKIMSelector());
      oStatement.AddColumn("domaindkimprivatekeyfile", pDomain->GetDKIMPrivateKeyFile());

      oStatement.SetTable("hm_domains");
      
      if (pDomain->GetID() == 0)
      {
         oStatement.SetStatementType(SQLStatement::STInsert);
         oStatement.SetIdentityColumn("domainid");
      }
      else
      {
         oStatement.SetStatementType(SQLStatement::STUpdate);

         String sWhere;
         sWhere.Format(_T("domainid = %I64d"), pDomain->GetID());

         oStatement.SetWhereClause(sWhere);

      }

      bool bNewObject = pDomain->GetID() == 0;

      // Save and fetch ID
      __int64 iDBID = 0;
      bool bRetVal = Application::Instance()->GetDBManager()->Execute(oStatement, bNewObject ? &iDBID : 0);
      if (bRetVal && bNewObject)
         pDomain->SetID((int) iDBID);

      // Refresh the BO cache
      Cache<Domain, PersistentDomain>::Instance()->RemoveObject(pDomain);

      return bRetVal;
   }

   bool
   PersistentDomain::DomainExists(const String &DomainName, bool &bIsActive)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns true if an active account with the address accountaddress exists.
   //---------------------------------------------------------------------------()
   {
      shared_ptr<const Domain> pDomain = Cache<Domain, PersistentDomain>::Instance()->GetObject(DomainName);

      if (pDomain)
      {
         bIsActive = pDomain->GetIsActive();
         return true;
      }

      return false;
   }

   int 
   PersistentDomain::GetSize(shared_ptr<Domain> pDomain)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns the current size of this domain, measured in mega bytes.
   //---------------------------------------------------------------------------()
   {
      
      HM::DatabaseSettings::SQLDBType DBType = IniFileSettings::Instance()->GetDatabaseType();

      String sSQL;
      if (DBType == DatabaseSettings::TypeMSSQLServer || DBType == DatabaseSettings::TypePGServer)
      {
         sSQL = "select sum(messagesize) as size from hm_messages "
                "where messageaccountid in "
                "(select accountdomainid from hm_accounts where accountdomainid = @DOMAINID) ";
      }
      else if (DBType == DatabaseSettings::TypeMYSQLServer)
      {
         sSQL = "select sum(messagesize) as size from hm_messages "
                "inner join hm_accounts on "
                "(hm_messages.messageaccountid = hm_accounts.accountid and hm_accounts.accountdomainid = @DOMAINID)";

      }

      SQLCommand command (sSQL);
      command.AddParameter("@DOMAINID", pDomain->GetID());

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS || pRS->IsEOF())
         return 0;

      __int64 iSize = pRS->GetInt64Value("size");
   
      // Convert from bytes to megabytes. We'll lose
      // some precision here, but that's OK.
      int iMB = (int) (iSize / 1024 / 1024);

      return iMB;

   }

   int 
   PersistentDomain::GetAllocatedSize(shared_ptr<Domain> pDomain)
   //---------------------------------------------------------------------------()
   // DESCRIPTION:
   // Returns the current allocated size of the domain in MB. This means the
   // total max size of all accounts in the domain.
   //---------------------------------------------------------------------------()
   {
      HM::DatabaseSettings::SQLDBType DBType = IniFileSettings::Instance()->GetDatabaseType();

      SQLCommand command ("select sum(accountmaxsize) as size from hm_accounts where accountdomainid = @DOMAINID");
      command.AddParameter("@DOMAINID", pDomain->GetID());

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS || pRS->IsEOF())
         return 0;

      // The account size is stored in MB so we don't have to do any conversion.
      int iSize = pRS->GetLongValue("size");

      return iSize;
   }
}
