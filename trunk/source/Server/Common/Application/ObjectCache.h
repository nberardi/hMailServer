// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   class DomainAliases;
   class Rules;

   class ObjectCache : public Singleton<ObjectCache>
   {
   public:
      ObjectCache(void);
      ~ObjectCache(void);

      void SetDomainAliasesNeedsReload();
      boost::shared_ptr<DomainAliases> GetDomainAliases();

      void SetGlobalRulesNeedsReload();
      boost::shared_ptr<Rules> GetGlobalRules();

      void SetAccountRulesNeedsReload(__int64 iAccountID);
      boost::shared_ptr<Rules> GetAccountRules(__int64 iAccountID);

      void ClearRuleCaches();

   private:

      boost::shared_ptr<DomainAliases> m_pDomainAliases;
      bool m_bDomainAliasesNeedsReload;

      boost::shared_ptr<Rules> m_pGlobalRules;
      bool m_bGlobalRulesNeedsReload;

      map<__int64, boost::shared_ptr<Rules> > m_mapAccountRules;
      set<__int64> m_setAccountRulesToRefresh;

      CriticalSection m_oDACritSec;
      CriticalSection m_oGRCritSec;
      CriticalSection m_oARCritSec;


   };
}