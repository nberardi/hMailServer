// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace UnitTest
{
    class SMTPServer : ServerSocket
    {
        private List<Dictionary<string, int>> _recipientResults;
        private Dictionary<string, int> _currentRecipientResult;
        private int _quitResult = 221;
        private int _mailFromresult = 250;
        private bool _hasMailFrom = false;
        private string _messageData = "";

        private bool _transmittingData = false;
        private bool _expectingUsername = false;
        private bool _expectingPassword = false;
        private bool _disconnectAfterDataDeliveryStarted = false;
        private bool _disconnectWithoutReplyOnQuit = false;
        private bool _disconnectAfterMessageAccept = false;
        private bool _forceAuthFailure = false;

        public SMTPServer(int maxNumberOfConnections, int port) :
            base(maxNumberOfConnections, port)
        {
            _recipientResults = new List<Dictionary<string, int>>();
        }

        public void AddRecipientResult(Dictionary<string, int> result)
        {
            _recipientResults.Add(result);

        }

        public int QuitResult
        {
            set
            {
                _quitResult = value;
            }
        }

        public bool DisconnectWithoutReplyOnQuit
        {
            set
            {
                _disconnectWithoutReplyOnQuit = true;
            }

        }

        public bool DisconnectAfterMessageAccept
        {
            set
            {
                _disconnectAfterMessageAccept = true;
            }

        }

        public bool DisconnectAfterDataDeliveryStarted
        {
           set
           {
              _disconnectAfterDataDeliveryStarted = true;
           }

        }

       public bool ForceAuthenticationFailure
       {
          set
          {
             _forceAuthFailure = true;
          }
       }

        public int MailFromResult
        {
            set
            {
                _mailFromresult = value;
            }
        }

        public string MessageData
        {
            get
            {
                return _messageData;
            }
        }

        protected override void OnConnect()
        {
            _currentRecipientResult = _recipientResults[0];
            _recipientResults.Remove(_currentRecipientResult);

            base.OnConnect();

            Run();
        }

        public void Run()
        {
            Send("220 ESMTP Test Server\r\n");

            while (true)
            {
                string text = ReadUntil("\r\n");

                if (string.IsNullOrEmpty(text))
                    break;

                bool quit = ProcessCommand(text);

                if (quit)
                    break;
            }
        }

        

        private bool ProcessCommand(string command)
        {
            if (command.ToUpper().StartsWith("HELO") || command.ToUpper().StartsWith("EHLO"))
            {
                Send("250 Test Server - Helo\r\n");
                return false;
            }

            if (command.ToUpper().StartsWith("AUTH LOGIN"))
            {
                Send("334 VXNlcm5hbWU6\r\n");
                _expectingUsername = true;
                return false;
            }

            if (command.ToUpper().StartsWith("AUTH LOGIN"))
            {
                Send("334 VXNlcm5hbWU6\r\n");
                return false;
            }

            if (command.ToUpper().StartsWith("MAIL"))
            {
                Send(_mailFromresult.ToString() + "\r\n");

                if (_mailFromresult == 250)
                    _hasMailFrom = true;

                return false;
            }

            if (command.ToUpper().StartsWith("RCPT"))
            {
                if (!_hasMailFrom)
                {
                    Send("503 must have sender first.\r\n");
                    return false;
                }
                int StartPos = command.IndexOf("<") + 1;
                int EndPos = command.LastIndexOf(">");
                int length = EndPos - StartPos;

                string address = command.Substring(StartPos, length);

                if (!_currentRecipientResult.ContainsKey(address))
                    throw new Exception("Unexpected address");

                string result = _currentRecipientResult[address].ToString();

                Send(result + " " + address + "\r\n");

                return false;
            }

            if (command.ToUpper().StartsWith("DATA"))
            {
                Send("354 Test Server - Give it to me...\r\n");
                _transmittingData = true;
                _messageData = "";
                return false;
            }

            if (command.ToUpper().StartsWith("QUIT"))
            {
                if (!_disconnectWithoutReplyOnQuit)
                {
                    Send(_quitResult.ToString() + " Test Server - Goodbye\r\n");
                }
               
                Disconnect();

                return true;
            }

            if (_transmittingData)
            {
               if (_disconnectAfterDataDeliveryStarted)
               {
                  // We've received some message data. Disconenct!
                  Disconnect();
                  return true;
               }


                _messageData += command;
            }

            if (command.IndexOf(".\r\n") > 0)
            {
                // remove the ending...
                _messageData = _messageData.Replace("\r\n.\r\n", "\r\n");

                Send("250 Test Server - Queued for delivery\r\n");

                if (_disconnectAfterMessageAccept)
                {
                    Disconnect();
                    return true;
                }

                _transmittingData = false;
                return false;
            }

            if (_expectingUsername)
            {
                _expectingUsername = false;
                Send("334 UGFzc3dvcmQ6\r\n");
                _expectingPassword = true;
                return false;
            }

            if (_expectingPassword)
            {
               if (_forceAuthFailure)
                  Send("535 Authentication failed. Restarting authentication process.\r\n");
               else
                  Send("235 authenticated.\r\n");

               _expectingPassword = false;

               return false;
            }

            return false;
        }
    }
}
