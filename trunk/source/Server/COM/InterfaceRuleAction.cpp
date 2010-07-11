// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "stdafx.h"
#include "InterfaceRuleAction.h"

#include "../Common/BO/RuleAction.h"
#include "../Common/BO/RuleActions.h"
#include "../Common/Persistence/PersistentRuleAction.h"
#include "../Common/Util/Encoding/ModifiedUTF7.h"

#include "COMError.h"

STDMETHODIMP InterfaceRuleAction::get_ID(long *pVal)
{
   *pVal = (long) m_pObject->GetID();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::Save()
{
   // Set the sort order of the rule.
   if (m_pObject->GetID() == 0 && m_pObject->GetSortOrder() == 0)
   {
      std::vector<shared_ptr<HM::RuleAction> > vecExistingRuleActions = m_pParentCollection->GetVector();

      // Determine the highest SortOrder.
      if (vecExistingRuleActions.size() == 0)
         m_pObject->SetSortOrder(1);
      else
      {
         shared_ptr<HM::RuleAction> pLastRuleAction = vecExistingRuleActions[vecExistingRuleActions.size() -1];
         m_pObject->SetSortOrder(pLastRuleAction->GetSortOrder() +1);
      }
   }

   if (m_pParentCollection->GetRuleID() > 0)
   {
      if (!HM::PersistentRuleAction::SaveObject(m_pObject))
      {
         // Saving failed.
         return COMError::GenerateError("Failed to save object. See hMailServer error log.");
      }
   }

   AddToParentCollection();   

   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::MoveUp()
{
   m_pParentCollection->MoveUp(m_pObject);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::MoveDown()
{
   m_pParentCollection->MoveDown(m_pObject);
   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::get_RuleID(long *pVal)
{
   *pVal = (long) m_pObject->GetRuleID();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_RuleID(long newVal)
{
   m_pObject->SetRuleID(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_Type(eRuleActionType *pVal)
{
   *pVal = (eRuleActionType) m_pObject->GetType();

   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_Type(eRuleActionType newVal)
{
   m_pObject->SetType((HM::RuleAction::Type) newVal);

   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_RouteID(long *pVal)
{
   *pVal = (long) m_pObject->GetRouteID();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_RouteID(long newVal)
{
   m_pObject->SetRouteID(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::get_Subject(BSTR *pVal)
{
   *pVal = m_pObject->GetSubject().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_Subject(BSTR newVal)
{
   m_pObject->SetSubject(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_Body(BSTR *pVal)
{
   *pVal = m_pObject->GetBody().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_Body(BSTR newVal)
{
   m_pObject->SetBody(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_FromName(BSTR *pVal)
{
   *pVal = m_pObject->GetFromName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_FromName(BSTR newVal)
{
   m_pObject->SetFromName(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_FromAddress(BSTR *pVal)
{
   *pVal = m_pObject->GetFromAddress().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_FromAddress(BSTR newVal)
{
   m_pObject->SetFromAddress(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_Filename(BSTR *pVal)
{
   *pVal = m_pObject->GetFilename().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_Filename(BSTR newVal)
{
   m_pObject->SetFilename(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_To(BSTR *pVal)
{
   *pVal = m_pObject->GetTo().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_To(BSTR newVal)
{
   m_pObject->SetTo(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::get_ScriptFunction(BSTR *pVal)
{
   *pVal = m_pObject->GetScriptFunction().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_ScriptFunction(BSTR newVal)
{
   m_pObject->SetScriptFunction(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::get_IMAPFolder(BSTR *pVal)
{
   USES_CONVERSION;

   // Convert the modified UTF7 string into unicode.
   // Since hMailServer core don't know unicode, we
   // have to do it out here in the interface.
   
   HM::String sValue = m_pObject->GetIMAPFolder();
   HM::String sResult = HM::ModifiedUTF7::Decode(T2A(sValue.GetBuffer()));

   *pVal = sResult.AllocSysString();

   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_IMAPFolder(BSTR newVal)
{
   HM::String sUnicode (newVal);

   // Convert the unciode string to a modified UTF7.
   // Since hMailServer core don't know unicode, we
   // have to do it out here in the interface.
   HM::AnsiString sRetVal = HM::ModifiedUTF7::Encode(sUnicode);
   m_pObject->SetIMAPFolder(sRetVal);

   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::get_HeaderName(BSTR *pVal)
{
   *pVal = m_pObject->GetHeaderName().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_HeaderName(BSTR newVal)
{
   m_pObject->SetHeaderName(newVal);
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::get_Value(BSTR *pVal)
{
   *pVal = m_pObject->GetValue().AllocSysString();
   return S_OK;
}

STDMETHODIMP InterfaceRuleAction::put_Value(BSTR newVal)
{
   m_pObject->SetValue(newVal);
   return S_OK;
}


STDMETHODIMP InterfaceRuleAction::Delete()
{
   if (!m_pParentCollection)
      return HM::PersistentRuleAction::DeleteObject(m_pObject) ? S_OK : S_FALSE;

   m_pParentCollection->DeleteItemByDBID(m_pObject->GetID());

   return S_OK;
}