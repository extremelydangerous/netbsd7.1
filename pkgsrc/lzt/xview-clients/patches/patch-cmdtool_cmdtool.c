$NetBSD$

--- cmdtool/cmdtool.c.orig	1993-06-29 05:12:08.000000000 +0000
+++ cmdtool/cmdtool.c
@@ -123,7 +123,6 @@ main(argc,argv)
 	int     cmdline_count = 0;
 	char	cmdline2[50];
 	Server_image  cmd_pixmap, cmd_mask_pixmap;
-
 	
 #ifdef GPROF
 	if (argc > 1 && strcmp(argv[argc-1], "-gprof") == 0) {
@@ -141,6 +140,8 @@ main(argc,argv)
 #endif	
 	
 	/* This is required to initialize correctly */	
+
+
 	xv_init(XV_INIT_ARGC_PTR_ARGV, &argc, argv, 
 		XV_USE_LOCALE, TRUE, 0);
 
@@ -287,6 +288,7 @@ main(argc,argv)
 		argv[0]	= cmdline2;
 	}
 
+
 	/* If FRAME_LABEL wasn't set by cmdline argument, set it */
 	if ((tmp_label1 = (char *)xv_get(base_frame, FRAME_LABEL)) == NULL) {
 		(void)strncpy(frame_label,
