// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{

   class DatabaseSettings;

   class SQLScriptParser  
   {
   public:
      SQLScriptParser(boost::shared_ptr<DatabaseSettings> pSettings, const String &sFile);
      virtual ~SQLScriptParser();

      bool Parse(String &sErrorMessage);

      int GetNoOfCommands() {return (int)m_vecCommands.size(); }
      String GetCommand(int index) {return m_vecCommands[index]; }

   private:

      bool _PreprocessLine(String &sLine);

      boost::shared_ptr<DatabaseSettings> m_pSettings;
      String m_sFile;
      vector<String> m_vecCommands;

   };

}
