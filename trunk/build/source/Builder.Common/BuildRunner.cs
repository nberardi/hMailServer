// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Builder.Common
{
    public class BuildRunner
    {
        ManualResetEvent m_EventStop;
        ManualResetEvent m_EventStopped;

        Builder m_oBuilder;

        public delegate void StepStartedDelegate(int stepIndex);
        public event StepStartedDelegate StepStarted;

        public delegate void StepErrorDelegate(int stepindex, string errorMessage);
        public event StepErrorDelegate StepError;

        public delegate void StepCompletedDelegate(int stepIndex);
        public event StepCompletedDelegate StepCompleted;

        public delegate void ThreadFinishedDelegate();
        public event ThreadFinishedDelegate ThreadFinished;

        public BuildRunner(
            ManualResetEvent eventStop, 
			   ManualResetEvent eventStopped,
            Builder oBuilder)
        {
            m_EventStop = eventStop;
            m_EventStopped = eventStopped;

            m_oBuilder = oBuilder;

        }

        

        public void Run()
        {

            for (int i = 0; i < m_oBuilder.Count; i++)
            {
                if (m_oBuilder.RunAllSteps ||
                    (i >= m_oBuilder.StepStart && i <= m_oBuilder.StepEnd)) 
                {
                    BuildStep oStep = (BuildStep)m_oBuilder.Get(i);

                    if (StepStarted != null)
                       StepStarted(i);

                    try
                    {
                        oStep.Run();
                    }
                    catch (Exception e)
                    {
                       if (StepError != null)
                          StepError(i, e.Message);
                        
                        break;
                    }

                    if (StepCompleted != null)
                       StepCompleted(i);
                }

                if (m_EventStop.WaitOne(1))
                    break;
            }

            // Make synchronous call to main form
            // to inform it that thread finished
            if (ThreadFinished != null)
               ThreadFinished();


            // Reset the event
            m_EventStopped.Set();

        }
    }
}
