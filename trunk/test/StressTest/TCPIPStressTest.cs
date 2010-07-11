// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;
using UnitTest;
using System.Threading;

namespace StressTest
{
   [TestFixture]
   public class TCPIPStressTest : TestFixtureBase
   {
      [Test]
      public void TestManyTCPIPConnections()
      {
         Utilities.DeleteCurrentDefaultLog();

         const int count = 1000;

         List<TCPSocket> sockets = new List<TCPSocket>();
         for (int i = 0; i < count; i++)
         {
            TCPSocket socket = new TCPSocket();
            Assert.IsTrue(socket.Connect(25));

            sockets.Add(socket);
         }

         foreach (TCPSocket socket in sockets)
         {
            socket.Disconnect();
         }

         string log = Utilities.ReadCurrentDefaultLog();
      }
   }
}
