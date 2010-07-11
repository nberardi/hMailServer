// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"

#include "InterfaceAntiVirus.h"
#include "InterfaceBlockedAttachments.h"

#include "../SMTP/SMTPConfiguration.h"

#include "../Common/BO/BlockedAttachments.h"

bool 
InterfaceAntiVirus::LoadSettings()
{
   if (!GetIsServerAdmin())
      return false;

   m_pConfig = HM::Configuration::Instance();

   return true;
}


STDMETHODIMP InterfaceAntiVirus::get_ClamWinEnabled(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->ClamWinEnabled() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_ClamWinEnabled(VARIANT_BOOL newVal)
{

   m_pConfig->GetSMTPConfiguration()->ClamWinEnabled (newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_ClamWinExecutable(BSTR *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->ClamWinExecutable().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_ClamWinExecutable(BSTR newVal)
{

   m_pConfig->GetSMTPConfiguration()->ClamWinExecutable(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_ClamWinDBFolder(BSTR *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->ClamWinDatabase().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_ClamWinDBFolder(BSTR newVal)
{

   m_pConfig->GetSMTPConfiguration()->ClamWinDatabase(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_CustomScannerEnabled(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->GetCustomScannerEnabled() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_CustomScannerEnabled(VARIANT_BOOL newVal)
{

   m_pConfig->GetSMTPConfiguration()->SetCustomScannerEnabled (newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_CustomScannerExecutable(BSTR *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->GetCustomScannerExecutable().AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_CustomScannerExecutable(BSTR newVal)
{

   m_pConfig->GetSMTPConfiguration()->SetCustomScannerExecutable(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_CustomScannerReturnValue(long *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->GetCustomScannerReturnValue();

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_CustomScannerReturnValue(long  newVal)
{

   m_pConfig->GetSMTPConfiguration()->SetCustomScannerReturnValue(newVal);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_Action(eAntivirusAction *pVal)
{
   switch (m_pConfig->GetSMTPConfiguration()->AVAction())
   {
   case HM::SMTPConfiguration::ActionDelete:
      *pVal = hDeleteEmail;
      break;
   case HM::SMTPConfiguration::ActionStripAttachments:
      *pVal = hDeleteAttachments;
      break;
   }

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_Action(eAntivirusAction newVal)
{

   HM::SMTPConfiguration::eAVAction iAction;
   switch (newVal)
   {
   case hDeleteEmail:
      iAction = HM::SMTPConfiguration::ActionDelete;
      break;
   case hDeleteAttachments:
      iAction = HM::SMTPConfiguration::ActionStripAttachments;
   }

   m_pConfig->GetSMTPConfiguration()->AVAction (iAction);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_NotifySender(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->AVNotifySender() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_NotifySender(VARIANT_BOOL newVal)
{

   m_pConfig->GetSMTPConfiguration()->AVNotifySender(newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_NotifyReceiver(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->AVNotifyReceiver() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_NotifyReceiver(VARIANT_BOOL newVal)
{

   m_pConfig->GetSMTPConfiguration()->AVNotifyReceiver(newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_MaximumMessageSize(long *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->GetVirusScanMaxSize();
   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_MaximumMessageSize(long  newVal)
{
   m_pConfig->GetSMTPConfiguration()->SetVirusScanMaxSize(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_BlockedAttachments(IInterfaceBlockedAttachments **pVal)
{
   CComObject<InterfaceBlockedAttachments>* pInterface = new CComObject<InterfaceBlockedAttachments>;
   pInterface->SetAuthentication(m_pAuthentication);

   shared_ptr<HM::BlockedAttachments> pBlockedAttachments = HM::Configuration::Instance()->GetBlockedAttachments();

   pInterface->Attach(pBlockedAttachments);
   pInterface->AddRef();

   *pVal = pInterface;

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::put_EnableAttachmentBlocking(VARIANT_BOOL newVal)
{

   m_pConfig->GetSMTPConfiguration()->SetEnableAttachmentBlocking(newVal == VARIANT_TRUE ? true : false);

   return S_OK;
}

STDMETHODIMP InterfaceAntiVirus::get_EnableAttachmentBlocking(VARIANT_BOOL *pVal)
{
   *pVal = m_pConfig->GetSMTPConfiguration()->GetEnableAttachmentBlocking() ? VARIANT_TRUE : VARIANT_FALSE;

   return S_OK;
}
