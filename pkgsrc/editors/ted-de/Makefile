# $NetBSD: Makefile,v 1.17 2015/07/04 16:18:29 joerg Exp $

DISTNAME=	Ted_de_DE
PKGNAME=	ted-de-2.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	German spelling dictionary for the Ted word processor

DEPENDS+=	ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}

DIST_SUBDIR=	Ted-2.16
NO_BUILD=	YES

INSTALLATION_DIRS=	share/Ted/ind

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/German.ind \
		${DESTDIR}${PREFIX}/share/Ted/ind

.include "../../mk/bsd.pkg.mk"
