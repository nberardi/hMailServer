using System;
using System.Threading;
using NUnit.Framework;
using System.Collections.Generic;
using System.Net;
using System.Text;

namespace UnitTest
{
   /// <summary>
   /// Summary description for POP3Simulator.
   /// </summary>
   public class POP3Simulator
   {
      TCPSocket m_oSocket;
      int _port = 110;
      private IPAddress _ipaddress = null;

      public POP3Simulator()
      {
         m_oSocket = new TCPSocket();
      }

      public POP3Simulator(IPAddress ipaddress, bool useSSL, int port)
      {
         m_oSocket = new TCPSocket(useSSL);
         _port = port;
         _ipaddress = ipaddress;

      }

      public POP3Simulator(bool useSSL, int port) :
         this(null, useSSL, port)
      {

      }

      public bool Connect(int iPort)
      {
         return m_oSocket.Connect(_ipaddress, iPort);
      }

      public void Disconnect()
      {
         m_oSocket.Disconnect();
      }

      public bool TestConnect(int iPort)
      {
         bool bRetVal = m_oSocket.Connect(_ipaddress, iPort);
         m_oSocket.Disconnect();
         return bRetVal;
      }

      public string GetWelcomeMessage()
      {
         m_oSocket.Connect(_ipaddress, _port);
         string sData = m_oSocket.Receive();

         m_oSocket.Disconnect();
         return sData;
      }

      public bool ConnectAndLogon(string username, string password, out string errorMessage)
      {
         errorMessage = "";
         if (!m_oSocket.Connect(_ipaddress, _port))
            return false;

         // Receive welcome message.
         errorMessage = m_oSocket.ReadUntil("+OK");
         if (!errorMessage.StartsWith("+OK"))
            return false;

         m_oSocket.Send("USER " + username + "\r\n");

         errorMessage = m_oSocket.ReadUntil("+OK Send your password");
         if (!errorMessage.StartsWith("+OK"))
            return false;

         m_oSocket.Send("PASS " + password + "\r\n");
         errorMessage = m_oSocket.ReadUntil(new List<string>() { "+OK", "-ERR" });

         return errorMessage.StartsWith("+OK");
      }

      public bool ConnectAndLogon(string username, string password)
      {
         string errorMessage;

         return ConnectAndLogon(username, password, out errorMessage);
      }

      public string RETR(int index)
      {
         m_oSocket.Send("RETR " + index.ToString() + "\r\n");

         StringBuilder result = new StringBuilder();

         string eofCheck = "";

         while (eofCheck.IndexOf("\r\n.\r\n") < 0)
         {
            if (eofCheck.IndexOf("-ERR no such message") >= 0)
            {
               m_oSocket.Disconnect();
               return "";
            }

            string data = m_oSocket.Receive();

            eofCheck += data;

            if (eofCheck.Length > 25)
            {
               // Only save the end of the string.
               eofCheck = eofCheck.Substring(eofCheck.Length - 25);
            }

            result.Append(data);
         }

         return result.ToString();
      }

      public string LIST()
      {
         string sRetVal = "";

         m_oSocket.Send("LIST\r\n");

         while (sRetVal.IndexOf("\r\n.\r\n") < 0)
         {
            if (sRetVal.IndexOf("-ERR No such message") >= 0)
            {
               m_oSocket.Disconnect();
               return "";
            }

            sRetVal += m_oSocket.Receive();
         }

         return sRetVal;
      }


      public string LIST(int index)
      {
         string sRetVal;

         m_oSocket.Send("LIST " + index.ToString() + "\r\n");

         sRetVal = m_oSocket.Receive();

         return sRetVal;
      }

      public string UIDL()
      {
         string sRetVal = "";

         m_oSocket.Send("UIDL\r\n");

         while (sRetVal.IndexOf("\r\n.\r\n") < 0)
         {
            if (sRetVal.IndexOf("-ERR No such message") >= 0)
            {
               m_oSocket.Disconnect();
               return "";
            }

            sRetVal += m_oSocket.Receive();
         }

         return sRetVal;
      }

      public string UIDL(int index)
      {
         string sRetVal;

         m_oSocket.Send("UIDL " + index.ToString() + "\r\n");

         sRetVal = m_oSocket.Receive();

         return sRetVal;
      }

      public bool DELE(int index)
      {
         m_oSocket.Send("DELE " + index.ToString() + "\r\n");
         string data = m_oSocket.ReadUntil(new List<string>() { "+OK msg deleted", "-ERR No such message" });
         return data.StartsWith("+OK msg deleted");
      }

      public string TOP(int index, int rows)
      {
         if (rows > 0)
            m_oSocket.Send("TOP " + index.ToString() + " " + rows.ToString() + "\r\n");
         else
            m_oSocket.Send("TOP " + index.ToString() + "\r\n");

         string sRetVal = m_oSocket.Receive();
         while (sRetVal.IndexOf("\r\n.\r\n") < 0)
         {
            if (sRetVal.IndexOf("-ERR No such message") >= 0)
            {
               return sRetVal;
            }

            sRetVal += m_oSocket.Receive();
         }

         return sRetVal;
      }


      public void QUIT()
      {
         m_oSocket.Send("QUIT\r\n");
         m_oSocket.ReadUntil("+OK");
      }

      public string GetFirstMessageText(string sUsername, string sPassword)
      {
         ConnectAndLogon(sUsername, sPassword);

         string sRetVal = RETR(1);
         DELE(1);
         QUIT();

         m_oSocket.Disconnect();

         return sRetVal;
      }

      public int GetMessageCount(string sUsername, string sPassword)
      {
         m_oSocket.Connect(_port);

         // Receive welcome message.
         string sData = m_oSocket.Receive();

         m_oSocket.Send("USER " + sUsername + "\r\n");
         sData = m_oSocket.ReadUntil("+OK Send your password");

         m_oSocket.Send("PASS " + sPassword + "\r\n");
         sData = m_oSocket.ReadUntil(new List<string>() {"+OK Mailbox locked and ready", "-ERR Invalid user name or password."});
         Assert.IsTrue(sData.Contains("+OK Mailbox locked and ready"), sData);

         m_oSocket.Send("LIST\r\n");
         sData = m_oSocket.ReadUntil("+OK");

         // Check EXISTS header.
         int iStartPos = 4;
         int iEndPos = sData.IndexOf(" ", iStartPos);
         int iLength = iEndPos - iStartPos;
         string sValue = sData.Substring(iStartPos, iLength);

         m_oSocket.Send("QUIT\r\n");
         sData = m_oSocket.ReadUntil("+OK POP3 server saying goodbye...");

         m_oSocket.Disconnect();

         return Convert.ToInt32(sValue);
      }


      public static void AssertMessageCount(string accountName, string accountPassword, int expectedCount)
      {
         if (expectedCount == 0)
         {
            // just in case.
            Utilities.AssertRecipientsInDeliveryQueue(0);
         }

         int timeout = 100;
         int actualCount = 0;
         while (timeout > 0)
         {

            POP3Simulator oPOP3 = new POP3Simulator();

            actualCount = oPOP3.GetMessageCount(accountName, accountPassword);
            if (actualCount == expectedCount)
               return;

            if (actualCount > expectedCount)
               Assert.Fail(string.Format("Actual count exceeds expected count. Account name: {2}, Actual: {0}, Expected: {1}.", actualCount, expectedCount, accountName));

            timeout--;
            Thread.Sleep(50);
         }

         Assert.Fail(string.Format("Wrong number of messages in inbox for {0}. Actual: {1}, Expected: {2}",
            accountName, actualCount, expectedCount));

      }

      public static string AssertGetFirstMessageText(string accountName, string accountPassword)
      {
         // Wait for the message to appear.
         POP3Simulator pop3 = new POP3Simulator();
         for (int i = 0; i < 5000; i++)
         {
            if (pop3.GetMessageCount(accountName, accountPassword) > 0)
               break;

            Thread.Sleep(20);
         }

         // Download it.
         string text = pop3.GetFirstMessageText(accountName, accountPassword);

         if (text.Length == 0)
            Assert.Fail("Message was found but contents could not be received");

         return text;
      }

   }
}
