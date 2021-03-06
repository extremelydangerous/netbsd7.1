$NetBSD$

--- daemon/verify-shadow.c.orig	2007-07-30 20:06:56.000000000 +0000
+++ daemon/verify-shadow.c
@@ -199,7 +199,7 @@ authenticate_again:
 
     if (pwent == NULL) {
 	    gdm_sleep_no_signal (gdm_get_value_int (GDM_KEY_RETRY_DELAY));
-	    gdm_error (_("Couldn't authenticate user \"%s\""), login);
+	    gdm_error ("Couldn't authenticate user");
 
 	    print_cant_auth_errbox ();
 
@@ -213,7 +213,7 @@ authenticate_again:
     if (ppasswd == NULL || (ppasswd[0] != '\0' &&
 			    strcmp (crypt (passwd, ppasswd), ppasswd) != 0)) {
 	    gdm_sleep_no_signal (gdm_get_value_int (GDM_KEY_RETRY_DELAY));
-	    gdm_error (_("Couldn't authenticate user \"%s\""), login);
+	    gdm_error ("Couldn't authenticate user");
 
 	    print_cant_auth_errbox ();
 
@@ -226,7 +226,7 @@ authenticate_again:
     if ( ( ! gdm_get_value_bool (GDM_KEY_ALLOW_ROOT)||
 	  ( ! gdm_get_value_bool (GDM_KEY_ALLOW_REMOTE_ROOT) && ! local) ) &&
 	pwent->pw_uid == 0) {
-	    gdm_error (_("Root login disallowed on display '%s'"), display);
+	    gdm_error ("Root login disallowed on display '%s'", display);
 	    gdm_slave_greeter_ctl_no_ret (GDM_ERRBOX,
 					  _("The system administrator "
 					    "is not allowed to login "
@@ -244,7 +244,7 @@ authenticate_again:
     /* Check with the 'loginrestrictions' function
        if the user has been disallowed */
     if (loginrestrictions (login, 0, NULL, &message) != 0) {
-	    gdm_error (_("User %s not allowed to log in"), login);
+	    gdm_error ("User not allowed to log in");
 	    gdm_slave_greeter_ctl_no_ret (GDM_ERRBOX,
 					  _("\nThe system administrator "
 					    "has disabled your "
@@ -268,7 +268,7 @@ authenticate_again:
 	(strcmp (pwent->pw_shell, "/sbin/nologin") == 0 ||
 	 strcmp (pwent->pw_shell, "/bin/true") == 0 ||
 	 strcmp (pwent->pw_shell, "/bin/false") == 0)) {
-	    gdm_error (_("User %s not allowed to log in"), login);
+	    gdm_error ("User not allowed to log in");
 	    gdm_slave_greeter_ctl_no_ret (GDM_ERRBOX,
 					  _("\nThe system administrator "
 					    "has disabled your "
@@ -293,7 +293,7 @@ authenticate_again:
     }
 
     if ( ! gdm_setup_gids (login, pwent->pw_gid)) {
-	    gdm_error (_("Cannot set user group for %s"), login);
+	    gdm_error ("Cannot set user group");
 	    gdm_slave_greeter_ctl_no_ret (GDM_ERRBOX,
 					  _("\nCannot set your user group; "
 					    "you will not be able to log in. "
@@ -306,7 +306,7 @@ authenticate_again:
 
     switch (passwdexpired (login, &info_msg)) {
     case 1 :
-	    gdm_error (_("Password of %s has expired"), login);
+	    gdm_error ("User password has expired");
 	    gdm_error_box (d, GTK_MESSAGE_ERROR,
 			   _("You are required to change your password.\n"
 			     "Please choose a new one."));
@@ -380,7 +380,7 @@ authenticate_again:
 	    break;
 
     case 2 :
-	    gdm_error (_("Password of %s has expired"), login);
+	    gdm_error ("User password has expired");
 	    gdm_error_box (d, GTK_MESSAGE_ERROR,
 			   _("Your password has expired.\n"
 			     "Only a system administrator can now change it"));
@@ -389,7 +389,7 @@ authenticate_again:
 	    break;    
 
     case -1 :
-	    gdm_error (_("Internal error on passwdexpired"));
+	    gdm_error ("Internal error on passwdexpired");
 	    gdm_error_box (d, GTK_MESSAGE_ERROR,
 			   _("An internal error occurred. You will not be able to log in.\n"
 			     "Please try again later or contact your system administrator."));
@@ -426,12 +426,12 @@ gdm_verify_setup_user (GdmDisplay *d, co
 
 	pwent = getpwnam (login);
 	if (pwent == NULL) {
-		gdm_error (_("Cannot get passwd structure for %s"), login);
+		gdm_error ("Cannot get passwd structure for user");
 		return FALSE;
 	}
 
 	if ( ! gdm_setup_gids (login, pwent->pw_gid)) {
-		gdm_error (_("Cannot set user group for %s"), login);
+		gdm_error ("Cannot set user group");
 		gdm_error_box (d,
 			       GTK_MESSAGE_ERROR,
 			       _("\nCannot set your user group; "
