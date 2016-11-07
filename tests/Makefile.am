AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFMAPI_DLL_IMPORT@

TESTS = \
	test_api_functions.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fmapi_test_support

fmapi_test_support_SOURCES = \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_support.c \
	fmapi_test_unused.h

fmapi_test_support_LDADD = \
	../libfmapi/libfmapi.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

