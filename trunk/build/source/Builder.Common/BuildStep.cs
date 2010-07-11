// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace Builder.Common
{
    abstract public class BuildStep
    {
        protected Builder m_oBuilder;

        public abstract void Run();
        
        public abstract string Name
        {
            get;
        }

        protected string ExpandMacros(string sInput)
        {
           return m_oBuilder.ExpandMacros(sInput);
        }


    }
}
