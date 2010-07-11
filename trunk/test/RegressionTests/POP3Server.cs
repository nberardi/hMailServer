// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;

namespace UnitTest
{
    class POP3Server : ServerSocket
    {
        List<string> _messages;
        public List<int> DeletedMessages {get; set;}
        public List<int> RetrievedMessages { get; set; }
        private bool _disconnectImmediate;
		public bool SupportsUIDL {get;set;}

        public POP3Server(int maxNumberOfConnections, int port, List<string> messages) :
            base(maxNumberOfConnections, port)
        {
            _messages = messages;
            DeletedMessages = new List<int>();
            _disconnectImmediate = false;
			SupportsUIDL = true;
        }

        public bool DisconnectImmediate
        {
           get
           {
              return _disconnectImmediate;
           }
           set
           {
              _disconnectImmediate = value;
           }
        }

        protected override void OnConnect()
        {
            base.OnConnect();

            Run();
        }

        public void Run()
        {
            Send("+OK\r\n");

            DeletedMessages = new List<int>();
            RetrievedMessages = new List<int>();

            if (_disconnectImmediate)
               return;

            while (ProcessCommand(Receive()))
            {

            }
        }

        public bool ProcessCommand(string command)
        {
           if (command.ToLower().StartsWith("quit"))
           {
              // Remove the messages...
              DeletedMessages.Sort();
              DeletedMessages.Reverse();
              foreach (int deletedMessage in DeletedMessages)
              {
                 _messages.RemoveAt(deletedMessage-1);
              }

              return false;
           }

            if (command.ToLower().StartsWith("user"))
            {
                Send("+OK\r\n");
                return true;
            }

            if (command.ToLower().StartsWith("pass"))
            {
                Send("+OK\r\n");
                return true;
            }

            if (command.ToLower().StartsWith("uidl"))
            {
			    if (!SupportsUIDL)
                {
                   Send("-ERR unhandled command\r\n");
                   return true;
                }
				
                Send("+OK\r\n");

                for (int i = 0; i < _messages.Count; i++)
                {
                    Send(string.Format("{0} UniqueID-{1}\r\n", i+1, _messages[i].GetHashCode()));
                }
                
                Send(".\r\n");
                return true;
            }

            if (command.ToLower().StartsWith("retr"))
            {
                command = command.Substring(5);
                command = command.TrimEnd('\n');
                command = command.TrimEnd('\r');

                
                int messageID = Convert.ToInt32(command);

                RetrievedMessages.Add(messageID);

                string message = _messages[messageID-1];
                Send("+OK\r\n");
                Send(message);
                Send("\r\n.\r\n");

                return true;
            }

            if (command.ToLower().StartsWith("dele"))
            {
                command = command.Substring(5);
                command = command.TrimEnd('\n');
                command = command.TrimEnd('\r');

                int messageID = Convert.ToInt32(command);

                DeletedMessages.Add(messageID);

                Send("+OK\r\n");

                return true;
            }

            return true;
        }


    }
}
