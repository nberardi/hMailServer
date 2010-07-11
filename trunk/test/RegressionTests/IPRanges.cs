// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
namespace UnitTest.Security
{
   [TestFixture]
   public class IPRanges : TestFixtureBase
   {
      hMailServer.SecurityRanges _ipRanges;

      [SetUp]
      public new void SetUp()
      {
         _ipRanges = SingletonProvider<Utilities>.Instance.GetApp().Settings.SecurityRanges;
      }

      [Test]
      public void TestConnections()
      {
         

         TCPSocket oSocket = new TCPSocket();

         // Make sure an IP range exists.
         RemoveIPRanges();
         if (_ipRanges.Count == 0)
            AddIPRange();

         if (!oSocket.CanConnect(25))
            throw new Exception("ERROR: Cannot connect to port 25");
         if (!oSocket.CanConnect(110))
            throw new Exception("ERROR: Cannot connect to port 110");
         if (!oSocket.CanConnect(143))
            throw new Exception("ERROR: Cannot connect to port 143");

         RemoveIPRanges();

         // Now it shouldn't be possible to connect.

         if (oSocket.CanConnect(25))
            throw new Exception("ERROR: Cannot connect to port 25");
         if (oSocket.CanConnect(110))
            throw new Exception("ERROR: Cannot connect to port 110");
         if (oSocket.CanConnect(143))
            throw new Exception("ERROR: Cannot connect to port 143");

         AddIPRange();
         // Now it should be possible to connect again.
         if (!oSocket.CanConnect(25))
            throw new Exception("ERROR: Cannot connect to port 25");
         if (!oSocket.CanConnect(110))
            throw new Exception("ERROR: Cannot connect to port 110");
         if (!oSocket.CanConnect(143))
            throw new Exception("ERROR: Cannot connect to port 143");

         

      }

      private void AddIPRange()
      {
         hMailServer.SecurityRange oRange = _ipRanges.Add();
         oRange.LowerIP = "127.0.0.1";
         oRange.UpperIP = "127.0.0.1";
         oRange.Name = "My computer";
         oRange.AllowDeliveryFromLocalToLocal = true;
         oRange.AllowDeliveryFromLocalToRemote = true;
         oRange.AllowDeliveryFromRemoteToLocal = true;
         oRange.AllowIMAPConnections = true;
         oRange.AllowPOP3Connections = true;
         oRange.AllowSMTPConnections = true;
         

         oRange.EnableSpamProtection = true;

         oRange.Save();
      }

      public void RemoveIPRanges()
      {
         while (_ipRanges.Count > 0)
            _ipRanges.Delete(0);
      }
   }
}
