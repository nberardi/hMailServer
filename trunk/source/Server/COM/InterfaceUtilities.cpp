// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceUtilities.h"
#include "../Common/TCPIP/DNSResolver.h"
#include "../Common/util/ServiceManager.h"
#include "../Common/util/Crypt.h"
#include "../Common/util/MailImporter.h"
#include "../Common/util/EmailAllUsers.h"
#include "../Common/util/GUIDcreator.h"
#include "../Common/util/ClassTester.h"
#include "../Common/util/Utilities.h"
#include "../Common/util/PasswordGenerator.h"
#include "../SMTP/RuleApplier.h"
#include "../SMTP/DeliveryQueue.h"
#include "../Common/Persistence/PersistentMessage.h"
#include "../Common/Persistence/Maintenance/Maintenance.h"


#include "COMError.h"

STDMETHODIMP InterfaceUtilities::InterfaceSupportsErrorInfo(REFIID riid)
{
   static const IID* arr[] = 
   {
      &IID_IInterfaceUtilities,
   };

   for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
      if (InlineIsEqualGUID(*arr[i],riid))
         return S_OK;
   }
   return S_FALSE;
}

STDMETHODIMP InterfaceUtilities::GetMailServer(BSTR EMailAddress, BSTR *MailServer)
{
   HM::String sDomainName;
   HM::String sEMail(EMailAddress);

   sDomainName = HM::StringParser::ExtractDomain (EMailAddress);

   std::vector<HM::String> saDomainNames;

   HM::DNSResolver oDNSResolver;
   oDNSResolver.GetEmailServers(sDomainName, saDomainNames);

   HM::String sMailServer = "";
   for (unsigned int i = 0; i < saDomainNames.size(); i++)
   {
      if (!sMailServer.IsEmpty())
         sMailServer += ",";

      sMailServer += saDomainNames[i];
   }

   *MailServer = sMailServer.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::MD5(BSTR Input, BSTR *Output)
{
   HM::String sInput(Input);

   HM::String sOutput = HM::Crypt::Instance()->EnCrypt(sInput, HM::Crypt::ETMD5);

   *Output = sOutput.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::SHA256(BSTR Input, BSTR *Output)
{
   HM::String sInput(Input);

   HM::String sOutput = HM::Crypt::Instance()->EnCrypt(sInput, HM::Crypt::ETSHA256);

   *Output = sOutput.AllocSysString();

   return S_OK;
}


STDMETHODIMP InterfaceUtilities::BlowfishEncrypt(BSTR Input, BSTR *Output)
{
   HM::String sInput(Input);  

   HM::String sOutput = HM::Crypt::Instance()->EnCrypt(sInput, HM::Crypt::ETBlowFish);

   *Output = sOutput.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::BlowfishDecrypt(BSTR Input, BSTR *Output)
{
   HM::String sInput(Input);

   HM::String sOutput = HM::Crypt::Instance()->DeCrypt(sInput, HM::Crypt::ETBlowFish);

   *Output = sOutput.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::GenerateGUID(BSTR *Output)
{
   HM::String sOutput = HM::GUIDCreator::GetGUID();
   *Output = sOutput.AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceUtilities::IsValidEmailAddress(BSTR EMailAddress, VARIANT_BOOL *bIsValid)
{
   bool bValid = HM::StringParser::IsValidEmailAddress(EMailAddress);
   if (bValid)
      *bIsValid = VARIANT_TRUE;
   else
      *bIsValid = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::IsValidIPAddress(BSTR IPAddress, VARIANT_BOOL *bIsValid)
{
   HM::Utilities utilities;
   
   *bIsValid = utilities.IsValidIPAddress(IPAddress) ? VARIANT_TRUE : VARIANT_FALSE;
   
   return S_OK;
}

STDMETHODIMP InterfaceUtilities::IsStrongPassword(BSTR Username, BSTR Password, VARIANT_BOOL *bIsValid)
{
   bool bStrong = HM::PasswordGenerator::IsStrongPassword(Username, Password);

   if (bStrong)
      *bIsValid = VARIANT_TRUE;
   else
      *bIsValid = VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::IsValidDomainName(BSTR sDomainName, VARIANT_BOOL *bIsValid)
{
   bool bValid = HM::StringParser::IsValidDomainName(sDomainName);
   if (bValid)
      *bIsValid = VARIANT_TRUE;
   else
      *bIsValid = VARIANT_FALSE;


   return S_OK;
}

STDMETHODIMP InterfaceUtilities::IsLocalHost(BSTR sHostname, VARIANT_BOOL *bIsValid)
{
   *bIsValid = HM::Utilities::IsLocalHost(sHostname) ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::CriteriaMatch(BSTR MatchValue, eRuleMatchType matchType, BSTR TestValue, VARIANT_BOOL *bMatch)
{
   HM::RuleApplier ruleApplier;

   *bMatch = ruleApplier.TestMatch(MatchValue, (HM::RuleCriteria::MatchType) matchType, TestValue) ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::MakeDependent(BSTR sOtherService)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::ServiceManager oManager; 
   oManager.MakeDependentOn(sOtherService);
   return S_OK;
}

STDMETHODIMP InterfaceUtilities::ImportMessageFromFile(BSTR sFilename, long iAccountID, VARIANT_BOOL *bIsSuccessful)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   *bIsSuccessful = HM::MailImporter::Import(sFilename, iAccountID, "") ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::RetrieveMessageID(BSTR sFilename, hyper *messageID)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   __int64 id = 0;
   bool partialFileName;
   bool result = HM::PersistentMessage::GetMessageID(sFilename, id, partialFileName);

   *messageID = id;
   
   if (result == false)
      return COMError::GenerateError("Retrieval of message-ID failed. Please check hMailServer error log.");

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::ImportMessageFromFileToIMAPFolder(BSTR sFilename, long iAccountID, BSTR sIMAPFolder, VARIANT_BOOL *bIsSuccessful)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   *bIsSuccessful = HM::MailImporter::Import(sFilename, iAccountID, sIMAPFolder) ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP
InterfaceUtilities::EmailAllAccounts(BSTR sRecipientWildcard, BSTR sFromAddress, BSTR sFromName, BSTR sSubject, BSTR sBody, VARIANT_BOOL *bIsSuccessful)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::EmailAllUsers oEmailAllUsers;
   *bIsSuccessful = oEmailAllUsers.Start(sRecipientWildcard, sFromAddress, sFromName, sSubject, sBody) ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::RunTestSuite(BSTR sTestPassword)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::String sCorrectPassword = _T("I know what I am doing.");
   HM::String sPassword = sTestPassword;

   if (sPassword.Compare(sCorrectPassword) != 0)
      return S_FALSE;

   HM::ClassTester oTester;
   oTester.DoTests();

   return S_OK;
}

STDMETHODIMP InterfaceUtilities::PerformMaintenance(eMaintenanceOperation operation)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return m_pAuthentication->GetAccessDenied();

   HM::Maintenance maintenance;

   HM::Maintenance::MaintenanceOperation internalOperation;

   switch (operation)
   {
   case eUpdateIMAPFolderUID:
      internalOperation = HM::Maintenance::RecalculateFolderUID;
      break;
   default:
      return COMError::GenerateError("Unknown maintenance operation.");
   }

   bool result = maintenance.Perform(internalOperation);
   if (result == false)
      return COMError::GenerateError("The maintenance operation failed. Please see hMailServer log for details.");

   return S_OK;
}
