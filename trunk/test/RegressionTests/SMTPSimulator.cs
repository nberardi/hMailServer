// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Threading;
using System.Collections.Generic;
using System.Net;

namespace UnitTest
{
   /// <summary>
   /// Summary description for SMTPSimulator.
   /// </summary>
   public class SMTPSimulator
   {
      TCPSocket m_oSocket;
      private IPAddress _ipaddress = null;
      private int _port = 25;

      public SMTPSimulator() :
          this(false, 25)
      {
         
      }

      public SMTPSimulator(bool useSSL, int port) :
         this(useSSL, port, null)
      {

      }

      public SMTPSimulator(bool useSSL, int port, IPAddress ipaddress)
      {
         m_oSocket = new TCPSocket(useSSL);
         _port = port;
         _ipaddress = ipaddress;
      }

      public bool TestConnect(int iPort)
      {
         bool bRetVal = m_oSocket.Connect(_ipaddress, iPort);
         m_oSocket.Disconnect();
         return bRetVal;
      }

      public void Connect(int iPort)
      {
         m_oSocket.Connect(iPort);
      }

      public bool IsConnected
      {
          get {
              return m_oSocket.Connected;
          }
      }

      public bool ConnectAndLogon(int port, string base64Username, string base64Password, out string errorMessage)
      {
         Connect(port);

         errorMessage = Receive();
         if (!errorMessage.StartsWith("220"))
            return false;

         Send("EHLO test\r\n");
         errorMessage = Receive();
         if (!errorMessage.StartsWith("250"))
            return false;

         Send("AUTH LOGIN\r\n");
         errorMessage = Receive();
         if (!errorMessage.StartsWith("334"))
            return false;

         Send(base64Username + "\r\n");
         errorMessage = Receive();
         if (!errorMessage.StartsWith("334"))
            return false;

         Send(base64Password + "\r\n");
         errorMessage = Receive();
         if (!errorMessage.StartsWith("235"))
            return false;

         return true;
      }

      public void Disconnect()
      {
         m_oSocket.Disconnect();
      }

      public void Send(string sData)
      {
         m_oSocket.Send(sData);
      }

      public string Receive()
      {
         return m_oSocket.Receive();
      }

      public string GetWelcomeMessage()
      {
         m_oSocket.Connect(_port);
         string sData = m_oSocket.Receive();

         m_oSocket.Disconnect();
         return sData;
      }

      public bool Send(string sFrom, List<string> lstRecipients, string sSubject, string sBody)
      {
         if (!m_oSocket.Connect(_ipaddress, _port))
            return false;

         // Receive welcome message.
         string sData = m_oSocket.Receive();

         m_oSocket.Send("HELO 127.0.0.1\r\n");
         sData = m_oSocket.Receive();

         // User
         m_oSocket.Send("MAIL FROM:<" + sFrom + ">\r\n");
         sData = m_oSocket.Receive();

         string sCommaSeparatedRecipients = "";
         foreach (string sRecipient in lstRecipients)
         {
            m_oSocket.Send("RCPT TO:<" + sRecipient + ">\r\n");
            sData = m_oSocket.Receive();

            if (!sData.StartsWith("250"))
               return false;

            if (sCommaSeparatedRecipients.Length > 0)
               sCommaSeparatedRecipients += ", ";

            sCommaSeparatedRecipients += sRecipient;
         }
         
         // Select inbox
         m_oSocket.Send("DATA\r\n");
         sData = m_oSocket.Receive();

         if (sCommaSeparatedRecipients.Length > 5000)
            sCommaSeparatedRecipients = sCommaSeparatedRecipients.Substring(0, 5000);

         m_oSocket.Send("From: " + sFrom + "\r\n");
         m_oSocket.Send("To: " + sCommaSeparatedRecipients + "\r\n");
         m_oSocket.Send("Subject: " + sSubject + "\r\n");
         m_oSocket.Send("Date: " + Utilities.GetCurrentMIMEDateTime() + "\r\n");

         m_oSocket.Send("\r\n");

         // Send body

         m_oSocket.Send(sBody);

         m_oSocket.Send("\r\n");
         m_oSocket.Send(".\r\n");

         // Wait for OK.
         sData = m_oSocket.Receive();
         if (sData.Substring(0, 3) != "250")
            return false;

         // Quit again
         m_oSocket.Send("QUIT\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Disconnect();

         return true;
      }

      public bool Send(string sFrom, string sTo, string sSubject, string sBody)
      {
         string result = "";

         return Send(sFrom, sTo, sSubject, sBody, out result);
      }

      public bool Send(string sFrom, string sTo, string sSubject, string sBody, out string result)
      {
         m_oSocket.Connect(_ipaddress,  _port);

         // Receive welcome message.
         string sData = m_oSocket.Receive();

         m_oSocket.Send("HELO example.com\r\n");
         sData = m_oSocket.Receive();

         // User
         m_oSocket.Send("MAIL FROM:<" + sFrom + ">\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Send("RCPT TO:<" + sTo + ">\r\n");
         sData = m_oSocket.Receive();
         if (sData.StartsWith("2") == false)
         {
            result = sData;
            return false;
         }

         // Select inbox
         m_oSocket.Send("DATA\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Send("From: " + sFrom + "\r\n");
         m_oSocket.Send("To: " + sTo + "\r\n");
         m_oSocket.Send("Subject: " + sSubject + "\r\n");

         m_oSocket.Send("\r\n");

         // Send body

         m_oSocket.Send(sBody);

         m_oSocket.Send("\r\n");
         m_oSocket.Send(".\r\n");

         // Wait for OK.
         sData = m_oSocket.Receive();
         if (sData.Substring(0, 3) != "250")
         {
            result = sData;
            return false;
         }

         // Quit again
         m_oSocket.Send("QUIT\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Disconnect();

         result = "";
         return true;
      }

      public bool SendRaw(string sFrom, string sTo, string text)
      {
          if (!m_oSocket.Connect(_port))
              return false;

         // Receive welcome message.
         string sData = m_oSocket.Receive();

         m_oSocket.Send("HELO 127.0.0.1\r\n");
         sData = m_oSocket.Receive();

         // User
         m_oSocket.Send("MAIL FROM:<" + sFrom + ">\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Send("RCPT TO:<" + sTo + ">\r\n");
         sData = m_oSocket.Receive();
         if (sData.StartsWith("2") == false)
            return false;

         // Send the message.
         m_oSocket.Send("DATA\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Send(text);

         m_oSocket.Send("\r\n");
         m_oSocket.Send(".\r\n");

         // Wait for OK.
         sData = m_oSocket.Receive();

         bool success = sData.Substring(0, 3) == "250";
         if (!success)
            return false;

         // Quit again
         m_oSocket.Send("QUIT\r\n");
         sData = m_oSocket.Receive();

         m_oSocket.Disconnect();

         return success;
      }

      public static bool StaticSend(string sFrom, List<string> lstRecipients, string sSubject, string sBody)
      {
         SMTPSimulator oSimulator = new SMTPSimulator();
         return oSimulator.Send(sFrom, lstRecipients, sSubject, sBody);
      }

      public static bool StaticSendRaw(string sFrom, string recipient, string sBody)
      {
         SMTPSimulator oSimulator = new SMTPSimulator();
         return oSimulator.SendRaw(sFrom, recipient, sBody);
      }

      public static bool StaticSend(string sFrom, string recipient, string sSubject, string sBody)
      {
         List<string> messageRecipients = new List<string>();
         messageRecipients.Add(recipient);

         SMTPSimulator oSimulator = new SMTPSimulator();
         return oSimulator.Send(sFrom, messageRecipients, sSubject, sBody);
      }
   }
}
