if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common

bin_PROGRAMS = \
	lzfu_fuzzer

lzfu_fuzzer_SOURCES = \
	lzfu_fuzzer.cc \
	ossfuzz_libfmapi.h

lzfu_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfmapi/libfmapi.la
endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

splint:
	@echo "Running splint on lzfu_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(lzfu_fuzzer_SOURCES)

