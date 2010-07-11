// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#include "StdAfx.h"

#include "PersistentWhiteListAddress.h"
#include "..\BO\WhiteListAddress.h"
#include "..\SQL\SQLStatement.h"
#include "../SQL/IPAddressSQLHelper.h"

namespace HM
{
   PersistentWhiteListAddress::PersistentWhiteListAddress(void)
   {
   }

   PersistentWhiteListAddress::~PersistentWhiteListAddress(void)
   {
   }

   bool
   PersistentWhiteListAddress::DeleteObject(shared_ptr<WhiteListAddress> pObject)
   {
      SQLCommand command("delete from hm_whitelist where whiteid = @WHITEID");
      command.AddParameter("@WHITEID", pObject->GetID());

      return Application::Instance()->GetDBManager()->Execute(command);
   }

   bool 
   PersistentWhiteListAddress::ReadObject(shared_ptr<WhiteListAddress> pObject, shared_ptr<DALRecordset> pRS)
   {
      IPAddressSQLHelper helper;

      pObject->SetID (pRS->GetLongValue("whiteid"));
      pObject->SetLowerIPAddress(helper.Construct(pRS, "whiteloweripaddress1", "whiteloweripaddress2"));
      pObject->SetUpperIPAddress(helper.Construct(pRS, "whiteupperipaddress1", "whiteupperipaddress2"));
      pObject->SetEMailAddress(pRS->GetStringValue("whiteemailaddress"));
      pObject->SetDescription(pRS->GetStringValue("whitedescription"));
      
      return true;
   }

   bool 
   PersistentWhiteListAddress::SaveObject(shared_ptr<WhiteListAddress> pObject, String &errorMessage)
   {
      return SaveObject(pObject);
   }

   bool 
   PersistentWhiteListAddress::SaveObject(shared_ptr<WhiteListAddress> pObject)
   {
      SQLStatement oStatement;
      oStatement.SetTable("hm_whitelist");
      
      if (pObject->GetID() == 0)
      {
         oStatement.SetStatementType(SQLStatement::STInsert);
         oStatement.SetIdentityColumn("whiteid");
      }
      else
      {
         oStatement.SetStatementType(SQLStatement::STUpdate);
         String sWhere;
         sWhere.Format(_T("whiteid = %I64d"), pObject->GetID());
         oStatement.SetWhereClause(sWhere);
         
      }

      IPAddressSQLHelper helper;
      helper.AppendStatement(oStatement, pObject->GetLowerIPAddress(), "whiteloweripaddress1", "whiteloweripaddress2");
      helper.AppendStatement(oStatement, pObject->GetUpperIPAddress(), "whiteupperipaddress1", "whiteupperipaddress2");

      oStatement.AddColumn("whiteemailaddress", pObject->GetEmailAddress());
      oStatement.AddColumn("whitedescription", pObject->GetDescription());

      bool bNewObject = pObject->GetID() == 0;

      // Save and fetch ID
      __int64 iDBID = 0;
      bool bRetVal = Application::Instance()->GetDBManager()->Execute(oStatement, bNewObject ? &iDBID : 0);
      if (bRetVal && bNewObject)
         pObject->SetID((int) iDBID);

      return true;
   }

   /// Checks if a specific sender on a specific IP address is white listed.
   bool 
   PersistentWhiteListAddress::IsSenderWhitelisted(const IPAddress &ipaddress, const String &fromAddress)
   {
      IPAddressSQLHelper helper;     

      SQLCommand command;

      String addressWhereClause;

      if (ipaddress.GetType() == IPAddress::IPV4)
      {
         addressWhereClause = "@ADDRESS1A >= whiteloweripaddress1 and @ADDRESS1B <= whiteupperipaddress1 and whiteloweripaddress2 IS NULL and whiteupperipaddress2 IS NULL";

         String address1 = helper.GetAddress1String(ipaddress);
         command.AddParameter("@ADDRESS1A", address1);
         command.AddParameter("@ADDRESS1B", address1);
      }
      else
      {
         addressWhereClause = 
               "(@ADDRESS1A = whiteloweripaddress1 && @ADDRESS1B >= whiteloweripaddress2 "
               "@ADDRESS1C > whiteloweripaddress1 && whiteloweripaddress2 is not null) AND "
               "(@ADDRESS1D} = whiteupperipaddress1 && @ADDRESS1E <= whiteupperipaddress2 "
               "@ADDRESS1F < whiteupperipaddress1 && whiteupperipaddress2 is not null)";

         String address1 = helper.GetAddress1String(ipaddress);
         command.AddParameter("@ADDRESS1A", address1);
         command.AddParameter("@ADDRESS1B", address1);
         command.AddParameter("@ADDRESS1C", address1);

         String address2 = helper.GetAddress2String(ipaddress);

         command.AddParameter("@ADDRESS1D", address2);
         command.AddParameter("@ADDRESS1E", address2);
         command.AddParameter("@ADDRESS1F", address2);
      }

      String whereClause = addressWhereClause + " AND (whiteemailaddress = '' OR @FROMADDRESS LIKE whiteemailaddress ESCAPE '/')";
      String queryString = "SELECT COUNT(*) as c FROM hm_whitelist WHERE " + whereClause;

      command.AddParameter("@FROMADDRESS", fromAddress);

      command.SetQueryString(queryString);

      shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      long count = pRS->GetLongValue("c");

      if (count > 0)
         return true;
      else 
         return false;

   }
}