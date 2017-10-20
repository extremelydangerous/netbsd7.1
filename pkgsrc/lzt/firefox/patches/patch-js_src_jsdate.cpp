$NetBSD$

--- js/src/jsdate.cpp.orig	2016-10-31 20:15:36.000000000 +0000
+++ js/src/jsdate.cpp
@@ -2721,8 +2721,8 @@ ToLocaleFormatHelper(JSContext* cx, Hand
         if (strcmp(format, "%x") == 0 && result_len >= 6 &&
             /* Format %x means use OS settings, which may have 2-digit yr, so
                hack end of 3/11/22 or 11.03.22 or 11Mar22 to use 4-digit yr...*/
-            !isdigit(buf[result_len - 3]) &&
-            isdigit(buf[result_len - 2]) && isdigit(buf[result_len - 1]) &&
+            !isdigit(((unsigned char)buf[result_len - 3])) &&
+            isdigit(((unsigned char)buf[result_len - 2])) && isdigit(((unsigned char)buf[result_len - 1])) &&
             /* ...but not if starts with 4-digit year, like 2022/3/11. */
             !(isdigit(buf[0]) && isdigit(buf[1]) &&
               isdigit(buf[2]) && isdigit(buf[3]))) {