// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace hMailServer.Shared
{
   public class Authenticator
   {
      public static bool AuthenticateUser(hMailServer.Application application)
      {
         // First try to authenticate using an empty password.
         hMailServer.Account account = null;
         
         account = application.Authenticate("Administrator", "");

         if (account != null)
            return true;

         // Try to authenticate using password on command line...
         string [] args = Environment.GetCommandLineArgs();
         foreach (string password in args)
         {
            account = application.Authenticate("Administrator", password);

            if (account != null)
               return true;
         }

         while (true)
         {
            formEnterPassword passwordDlg = new formEnterPassword();

            if (passwordDlg.ShowDialog() != System.Windows.Forms.DialogResult.OK)
               return false;

            string password = passwordDlg.Password;

            account = application.Authenticate("Administrator", password);

            if (account != null)
               return true;

            MessageBox.Show("Invalid user name or password.", "hMailServer");
         }
      }
   }
}
