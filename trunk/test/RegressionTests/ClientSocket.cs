// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;
using System.Threading;
using System.Net.Security;
using System.Collections;
using System.Security.Authentication;
using System.Security.Cryptography.X509Certificates;
using NUnit.Framework;
using System.Collections.Generic;

namespace UnitTest
{
   /// <summary>
   /// Summary description for ClientSocket.
   /// </summary>
   public class TCPSocket
   {
      protected Socket m_oSocket;
      private bool _useSslSocket = false;
      private string _conversation = "";

      public TCPSocket()
      {
 
         //
         // TODO: Add constructor logic here
         //
      }


      public TCPSocket(bool useSSL)
      {
         _useSslSocket = useSSL;
      }

      public bool Connect(int iPort)
      {
         return Connect(null, iPort);
      }

      private IPAddress GetHostAddress(string hostName, bool allowIPv6)
      {
          IPAddress [] addresses = Dns.GetHostEntry(hostName).AddressList;

          foreach (IPAddress address in addresses)
          {
              if (address.AddressFamily == AddressFamily.InterNetworkV6 && allowIPv6)
                  return address;
              else if (address.AddressFamily == AddressFamily.InterNetwork)
                  return address;
          }

          return null;
      }

      public bool Connect(IPAddress ipaddress, int iPort)
      {
         IPEndPoint endPoint = null;

         if (ipaddress != null)
            endPoint = new IPEndPoint(ipaddress, iPort);
         else
            endPoint = new IPEndPoint(GetHostAddress("localhost", false), iPort);

         if (_useSslSocket)
         {
            _tcpClient = new TcpClient(endPoint.Address.ToString(), iPort);

            // Create an SSL stream that will close the client's stream.
            _sslStream = new SslStream(_tcpClient.GetStream(), false,
                new RemoteCertificateValidationCallback(ValidateServerCertificate), null);

            try
            {
               _sslStream.AuthenticateAsClient("localhost");
            }
            catch (AuthenticationException)
            {
               return false;
            }

            _tcpClient.Client.Blocking = true;

            return true;

         }
         else
         {
            Socket tmpS = new Socket(endPoint.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            try
            {
               tmpS.Connect(endPoint);
            }
            catch (SocketException exp)
            {
               int i = exp.ErrorCode;
            }


            if (tmpS.Connected)
            {
               m_oSocket = tmpS;
               m_oSocket.Blocking = true;
               return true;
            }
         }

         return false;
      }

      public string Conversation
      {
         get
         {
            return _conversation;
         }

      }

      public bool CanConnect(int iPort)
      {
         if (!Connect(iPort))
            return false;

         try
         {
            for (int i = 0; i < 40; i++)
            {
               if (m_oSocket.Available > 0)
                  return true;

               Thread.Sleep(25);
            }
         }
         finally
         {
            Disconnect();
         }

         return false;

      }

      public void Disconnect()
      {
         if (_useSslSocket)
         {
            _sslStream.Close();
            _tcpClient.Close();
         }
         else
            m_oSocket.Close();

         
      }

      public void Send(string s)
      {
         _conversation += s;
         if (_useSslSocket)
         {
            Assert.IsTrue(_tcpClient.Connected);

            byte[] message = Encoding.UTF8.GetBytes(s);
            _sslStream.Write(message);
            _sslStream.Flush();
         }
         else
         {
            Assert.IsTrue(m_oSocket.Connected);

            Byte[] buf = Encoding.UTF8.GetBytes(s);
            m_oSocket.Send(buf, buf.Length, 0);
         }
      }

      public bool Connected
      {
         get
         {
            return m_oSocket.Connected;
         }
      }

      public string ReadUntil(string text)
      {
         string result = Receive();

         for (int i = 0; i < 1000; i++)
         {
            if (result.Contains(text))
               return result;

            if (!m_oSocket.Connected)
               return "";

            result += Receive();

            Thread.Sleep(10);
         }

         Assert.Fail("Timeout while waiting for server response: " + text);
         return "";
      }


      public string ReadUntil(List<string> possibleReplies)
      {
         string result = Receive();

         for (int i = 0; i < 1000; i++)
         {
            foreach (string s in possibleReplies)
            {
               if (result.Contains(s))
                  return result;
            }

            Thread.Sleep(10);

            result += Receive();
         }

         Assert.Fail("Timeout while waiting for server response.");
         return "";
      }

      public string Receive()
      {
         StringBuilder messageData = new StringBuilder();
         byte[] buffer = new byte[2048];
         int bytes = -1;

         if (_useSslSocket)
         {
            if (!_tcpClient.Connected)
               return "";
            
            do
            {
               bytes = _sslStream.Read(buffer, 0, buffer.Length);
               Decoder decoder = Encoding.UTF8.GetDecoder();
               char[] chars = new char[decoder.GetCharCount(buffer, 0, bytes)];
               decoder.GetChars(buffer, 0, bytes, chars, 0);
               messageData.Append(chars);

            } while (_tcpClient.Available > 0);

            
         }
         else
         {
            if (!m_oSocket.Connected)
               return "";

            do
            {
               bytes = m_oSocket.Receive(buffer, SocketFlags.None);
               char[] chars = Encoding.ASCII.GetChars(buffer);
               string s = new string(chars, 0, bytes);

               messageData.Append(s);

            } while (m_oSocket.Available > 0);
         }

         _conversation += messageData;

         return messageData.ToString();
      }

      public bool Peek()
      {
         if (_useSslSocket)
         {
            if (_tcpClient.Available > 0)
               return true;
            else
               return false;
         }
         else
         {
            if (m_oSocket.Available > 0)
               return true;
            else
               return false;
         }
      }

      #region SSL_LOGICS

      private static Hashtable certificateErrors = new Hashtable();

      TcpClient _tcpClient = null;
      SslStream _sslStream = null;

      // The following method is invoked by the RemoteCertificateValidationDelegate.
      public static bool ValidateServerCertificate(
            object sender,
            X509Certificate certificate,
            X509Chain chain,
            SslPolicyErrors sslPolicyErrors)
      {
         return true;
      }


      #endregion

   }
}
