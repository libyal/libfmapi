#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfmapi/.libs/libfmapi.1.dylib && test -f ./pyfmapi/.libs/pyfmapi.so
then
	install_name_tool -change /usr/local/lib/libfmapi.1.dylib ${PWD}/libfmapi/.libs/libfmapi.1.dylib ./pyfmapi/.libs/pyfmapi.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

