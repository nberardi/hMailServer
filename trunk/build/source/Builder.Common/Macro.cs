// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;

namespace Builder.Common
{
    class Macro
    {
        private string m_sName;
        private string m_sValue;

        public Macro(string sName, string sValue)
        {
            m_sName = sName;
            m_sValue = sValue;
        }

        public string Name
        {
            get { return m_sName; }
        }
        
        public string Value
        {
            get { return m_sValue;  }
        }

    }
}
