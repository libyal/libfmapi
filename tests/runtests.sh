#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfmapi/.libs/libfmapi.1.dylib && test -f ./pyfmapi/.libs/pyfmapi.so;
then
	install_name_tool -change /usr/local/lib/libfmapi.1.dylib ${PWD}/libfmapi/.libs/libfmapi.1.dylib ./pyfmapi/.libs/pyfmapi.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

