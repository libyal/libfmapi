if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../libcerror -I$(top_srcdir)/libcerror \
	-I../common -I$(top_srcdir)/common

bin_PROGRAMS = \
	checksum_fuzzer \
	entry_identifier_fuzzer \
	lzfu_fuzzer \
	one_off_entry_identifier_fuzzer

checksum_fuzzer_SOURCES = \
	checksum_fuzzer.cc \
	ossfuzz_libfmapi.h

checksum_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmapi/libfmapi.la

entry_identifier_fuzzer_SOURCES = \
	entry_identifier_fuzzer.cc \
	ossfuzz_libfmapi.h

entry_identifier_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmapi/libfmapi.la

lzfu_fuzzer_SOURCES = \
	lzfu_fuzzer.cc \
	ossfuzz_libfmapi.h

lzfu_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmapi/libfmapi.la

one_off_entry_identifier_fuzzer_SOURCES = \
	one_off_entry_identifier_fuzzer.cc \
	ossfuzz_libfmapi.h

one_off_entry_identifier_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmapi/libfmapi.la
endif

DISTCLEANFILES = \
	Makefile \
	Makefile.in

splint-local:
	@echo "Running splint on checksum_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(checksum_fuzzer_SOURCES)
	@echo "Running splint on entry_identifier_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(entry_identifier_fuzzer_SOURCES)
	@echo "Running splint on lzfu_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzfu_fuzzer_SOURCES)
	@echo "Running splint on one_off_entry_identifier_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(one_off_entry_identifier_fuzzer_SOURCES)

