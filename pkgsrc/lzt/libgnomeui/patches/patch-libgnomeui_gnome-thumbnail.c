$NetBSD$

--- libgnomeui/gnome-thumbnail.c.orig	2010-03-29 10:48:34.000000000 +0000
+++ libgnomeui/gnome-thumbnail.c
@@ -863,7 +863,7 @@ gnome_thumbnail_factory_save_thumbnail (
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  original_mtime);
+  g_snprintf (mtime_str, 21, "%lld",  (long long)original_mtime);
   width = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Width");
   height = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Height");
 
@@ -970,7 +970,7 @@ gnome_thumbnail_factory_create_failed_th
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  mtime);
+  g_snprintf (mtime_str, 21, "%lld",  (long long)mtime);
   pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, 1, 1);
   saved_ok  = gdk_pixbuf_save (pixbuf,
 			       tmp_path,
