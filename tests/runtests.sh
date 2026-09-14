#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfmapi/.libs/libfmapi.1.dylib" ] && [ -f ./pyfmapi/.libs/pyfmapi.so ]
then
    install_name_tool -change /usr/local/lib/libfmapi.1.dylib "${PWD}/libfmapi/.libs/libfmapi.1.dylib" ./pyfmapi/.libs/pyfmapi.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

