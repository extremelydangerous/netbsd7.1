# $NetBSD: Makefile,v 1.5 2017/09/06 16:49:38 wiz Exp $

DISTNAME=	hyphen-spanish
PKGNAME=	tex-${DISTNAME}-4.5.2016
TEXLIVE_REV=	40340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Spanish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	spanish loadhyph-es.tex
TEX_HYPHEN_DAT+=	= espanol
TEX_HYPHEN_DEF+=	\\addlanguage{spanish}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_DEF+=	\\addlanguage{espanol}{loadhyph-es.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['spanish'] = { \
			  loader = 'loadhyph-es.tex', \
			  lefthyphenmin = 2, \
			  righthyphenmin = 2, \
			  synonyms = { 'espanol' }, \
			  patterns = 'hyph-es.pat.txt', \
			  hyphenation = '', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
