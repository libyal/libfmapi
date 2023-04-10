AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCDATA_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFGUID_CPPFLAGS@ \
	@LIBFWNT_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBFMAPI_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_manpage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fmapi_test_checksum \
	fmapi_test_entry_identifier \
	fmapi_test_error \
	fmapi_test_lzfu \
	fmapi_test_one_off_entry_identifier \
	fmapi_test_property_type \
	fmapi_test_support \
	fmapi_test_value_type

fmapi_test_checksum_SOURCES = \
	fmapi_test_checksum.c \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_unused.h

fmapi_test_checksum_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

fmapi_test_entry_identifier_SOURCES = \
	fmapi_test_entry_identifier.c \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_memory.c fmapi_test_memory.h \
	fmapi_test_unused.h

fmapi_test_entry_identifier_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

fmapi_test_error_SOURCES = \
	fmapi_test_error.c \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_unused.h

fmapi_test_error_LDADD = \
	../libfmapi/libfmapi.la

fmapi_test_lzfu_SOURCES = \
	fmapi_test_lzfu.c \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_memory.c fmapi_test_memory.h \
	fmapi_test_unused.h

fmapi_test_lzfu_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

fmapi_test_one_off_entry_identifier_SOURCES = \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_libuna.h \
	fmapi_test_macros.h \
	fmapi_test_memory.c fmapi_test_memory.h \
	fmapi_test_one_off_entry_identifier.c \
	fmapi_test_unused.h

fmapi_test_one_off_entry_identifier_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

fmapi_test_property_type_SOURCES = \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_memory.c fmapi_test_memory.h \
	fmapi_test_property_type.c \
	fmapi_test_unused.h

fmapi_test_property_type_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

fmapi_test_support_SOURCES = \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_support.c \
	fmapi_test_unused.h

fmapi_test_support_LDADD = \
	../libfmapi/libfmapi.la

fmapi_test_value_type_SOURCES = \
	fmapi_test_libcerror.h \
	fmapi_test_libfmapi.h \
	fmapi_test_macros.h \
	fmapi_test_memory.c fmapi_test_memory.h \
	fmapi_test_unused.h \
	fmapi_test_value_type.c

fmapi_test_value_type_LDADD = \
	../libfmapi/libfmapi.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

