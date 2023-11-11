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
	-rm -f libfmapi.h
	-rm -f libfmapi/definitions.h
	-rm -f libfmapi/features.h
	-rm -f libfmapi/types.h
	-rm -f Makefile

