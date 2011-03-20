// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;
using System.Threading;
using NUnit.Framework;

namespace UnitTest
{
   class ServerSocket : TCPSocket
   {
      private int _maxNumberOfConnections = 0;
      private int _port = 0;
      TcpListener _tcpListener;
      Thread _serverThread;

      private AutoResetEvent _exitThreadEvent = new AutoResetEvent(false);
      private AutoResetEvent _isListening = new AutoResetEvent(false);

      private int _numberOfConnections = 0;
      public int SecondsToWaitBeforeTerminate {get;set;}

      public ServerSocket(int maxNumberOfConnections, int port)
      {
         _maxNumberOfConnections = maxNumberOfConnections;
         _port = port;
         SecondsToWaitBeforeTerminate = 15;
      }

      public AutoResetEvent GetIsListeningEvent()
      {
          return _isListening;
      }

      public void StartListen()
      {
         _serverThread = new Thread(new ThreadStart(this.ProcessClients));
         _serverThread.Name = "Search thread";
         _serverThread.Start();

         // Wait for thread to have started listen.
         GetIsListeningEvent().WaitOne();
      }

      private void ProcessClients()
      {
         IPAddress local = IPAddress.Parse("0.0.0.0");
         _tcpListener = new TcpListener(local, _port);
         _tcpListener.ExclusiveAddressUse = false;
         _tcpListener.Start();

         _isListening.Set();

         for (int i = 0; i < _maxNumberOfConnections; i++ )
         {
            try
            {
               m_oSocket = _tcpListener.AcceptSocket();
            }
            catch (Exception)
            {
               return;
            }
                       
			_numberOfConnections++;
			
			OnConnect();

            m_oSocket.Close();
         }

         _tcpListener.Stop();

         _exitThreadEvent.Set();
      }

      protected virtual void OnConnect()
      {
         // to be derived
      }

      public void OnClientConnect(IAsyncResult asyn)
      {
         try
         {
            m_oSocket = _tcpListener.EndAcceptSocket(asyn);


         }
         catch (ObjectDisposedException)
         {
            
         }
         catch (SocketException se)
         {
            throw se;
         }
      }

      public void WaitForCompletion()
      {
         for (int i = 0; i < SecondsToWaitBeforeTerminate; i++)
         {
            if (_exitThreadEvent.WaitOne(1000, true))
            {
               return;
            }
         }

         _tcpListener.Stop();
         _exitThreadEvent.Set();

         if (_numberOfConnections < _maxNumberOfConnections)
            Assert.Fail(string.Format("Client did not connect to simulated server. Expected connection count: {0}, Actual: {1}", _maxNumberOfConnections, _numberOfConnections));
         else
            Assert.Fail(string.Format("Client did not disconnect from simulated server. Expected connection count: {0}, Actual: {1}", _maxNumberOfConnections, _numberOfConnections));
      }


   }
}
