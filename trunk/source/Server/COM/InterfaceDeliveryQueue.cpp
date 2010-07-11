// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceDeliveryQueue.h"
#include "../SMTP/DeliveryQueue.h"
#include "COMError.h"
void
InterfaceDeliveryQueue::SetAuthentication(shared_ptr<HM::COMAuthentication> pAuthentication)
{
   m_pAuthentication = pAuthentication;
}

STDMETHODIMP 
InterfaceDeliveryQueue::Clear()
{
   if (!m_pAuthentication->GetIsServerAdmin())
   {
      return COMError::GenerateError("Server admin privileges are required to clear queue.");
   }

   HM::DeliveryQueue::Clear();
   return S_OK;
}

STDMETHODIMP 
InterfaceDeliveryQueue::ResetDeliveryTime(hyper iMessageID)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return S_FALSE;

   HM::DeliveryQueue::ResetDeliveryTime(iMessageID);
   return S_OK;
}

STDMETHODIMP 
InterfaceDeliveryQueue::Remove(hyper iMessageID)
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return S_FALSE;

   HM::DeliveryQueue::Remove(iMessageID);
   return S_OK;
}

STDMETHODIMP 
InterfaceDeliveryQueue::StartDelivery()
{
   if (!m_pAuthentication->GetIsServerAdmin())
      return S_FALSE;

   HM::DeliveryQueue::StartDelivery();
   return S_OK;
}