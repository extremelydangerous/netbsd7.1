$NetBSD$

--- ppp/ipcp.c.orig	2000-11-07 05:45:44.000000000 +0000
+++ ppp/ipcp.c
@@ -1194,8 +1194,7 @@ IpcpDecodeConfig(struct fsm *fp, u_char 
 	    break;
 	  case 6:		/* RFC1332 */
 	    if (ntohs(pcomp->proto) == PROTO_VJCOMP) {
-              if (pcomp->slots <= MAX_VJ_STATES
-                  && pcomp->slots >= MIN_VJ_STATES) {
+              if (pcomp->slots >= MIN_VJ_STATES) {
                 /* Ok, we can do that */
 	        ipcp->peer_compproto = compproto;
 	        ipcp->heis1172 = 0;
@@ -1230,9 +1229,7 @@ IpcpDecodeConfig(struct fsm *fp, u_char 
 
       case MODE_NAK:
 	if (ntohs(pcomp->proto) == PROTO_VJCOMP) {
-          if (pcomp->slots > MAX_VJ_STATES)
-            pcomp->slots = MAX_VJ_STATES;
-          else if (pcomp->slots < MIN_VJ_STATES)
+          if (pcomp->slots < MIN_VJ_STATES)
             pcomp->slots = MIN_VJ_STATES;
           compproto = (ntohs(pcomp->proto) << 16) + (pcomp->slots << 8) +
                       pcomp->compcid;
