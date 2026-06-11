AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
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

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: package.m4 test_library.at test_macros.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

