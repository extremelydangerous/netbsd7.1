# $NetBSD$

BUILDLINK_TREE+=	netcat

.if !defined(NETCAT_BUILDLINK3_MK)
NETCAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcat+=	netcat>=1.10nb3
BUILDLINK_PKGSRCDIR.netcat?=	../../net/netcat
.endif	# NETCAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcat
