include_HEADERS = \
	libfmapi.h

pkginclude_HEADERS = \
	libfmapi/definitions.h \
	libfmapi/error.h \
	libfmapi/extern.h \
	libfmapi/features.h \
	libfmapi/types.h

EXTRA_DIST = \
	libfmapi.h.in \
	libfmapi/definitions.h.in \
	libfmapi/features.h.in \
	libfmapi/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libfmapi.h
	/bin/rm -f libfmapi/definitions.h
	/bin/rm -f libfmapi/features.h
	/bin/rm -f libfmapi/types.h
	/bin/rm -f Makefile

