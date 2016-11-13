/*
 * Library entry_identifier type testing program
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fmapi_test_libcerror.h"
#include "fmapi_test_libfmapi.h"
#include "fmapi_test_macros.h"
#include "fmapi_test_memory.h"
#include "fmapi_test_unused.h"

/* Tests the libfmapi_entry_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_entry_identifier_initialize(
     void )
{
	libcerror_error_t *error                      = NULL;
	libfmapi_entry_identifier_t *entry_identifier = NULL;
	int result                                    = 0;

#if defined( HAVE_FMAPI_TEST_MEMORY )
	int number_of_malloc_fail_tests               = 1;
	int number_of_memset_fail_tests               = 1;
	int test_number                               = 0;
#endif

	/* Test regular cases
	 */
	result = libfmapi_entry_identifier_initialize(
	          &entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FMAPI_TEST_ASSERT_IS_NOT_NULL(
         "entry_identifier",
         entry_identifier );

        FMAPI_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libfmapi_entry_identifier_free(
	          &entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        FMAPI_TEST_ASSERT_IS_NULL(
         "entry_identifier",
         entry_identifier );

        FMAPI_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libfmapi_entry_identifier_initialize(
	          NULL,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FMAPI_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	entry_identifier = (libfmapi_entry_identifier_t *) 0x12345678UL;

	result = libfmapi_entry_identifier_initialize(
	          &entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FMAPI_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	entry_identifier = NULL;

#if defined( HAVE_FMAPI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfmapi_entry_identifier_initialize with malloc failing
		 */
		fmapi_test_malloc_attempts_before_fail = test_number;

		result = libfmapi_entry_identifier_initialize(
		          &entry_identifier,
		          &error );

		if( fmapi_test_malloc_attempts_before_fail != -1 )
		{
			fmapi_test_malloc_attempts_before_fail = -1;

			if( entry_identifier != NULL )
			{
				libfmapi_entry_identifier_free(
				 &entry_identifier,
				 NULL );
			}
		}
		else
		{
			FMAPI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FMAPI_TEST_ASSERT_IS_NULL(
			 "entry_identifier",
			 entry_identifier );

			FMAPI_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfmapi_entry_identifier_initialize with memset failing
		 */
		fmapi_test_memset_attempts_before_fail = test_number;

		result = libfmapi_entry_identifier_initialize(
		          &entry_identifier,
		          &error );

		if( fmapi_test_memset_attempts_before_fail != -1 )
		{
			fmapi_test_memset_attempts_before_fail = -1;

			if( entry_identifier != NULL )
			{
				libfmapi_entry_identifier_free(
				 &entry_identifier,
				 NULL );
			}
		}
		else
		{
			FMAPI_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FMAPI_TEST_ASSERT_IS_NULL(
			 "entry_identifier",
			 entry_identifier );

			FMAPI_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FMAPI_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( entry_identifier != NULL )
	{
		libfmapi_entry_identifier_free(
		 &entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_entry_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_entry_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfmapi_entry_identifier_free(
	          NULL,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        FMAPI_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FMAPI_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FMAPI_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FMAPI_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FMAPI_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FMAPI_TEST_UNREFERENCED_PARAMETER( argc )
	FMAPI_TEST_UNREFERENCED_PARAMETER( argv )

	FMAPI_TEST_RUN(
	 "libfmapi_entry_identifier_initialize",
	 fmapi_test_entry_identifier_initialize );

	FMAPI_TEST_RUN(
	 "libfmapi_entry_identifier_free",
	 fmapi_test_entry_identifier_free );

	/* TODO: add tests for libfmapi_entry_identifier_copy_from_byte_stream */

	/* TODO: add tests for libfmapi_entry_identifier_get_service_provider_identifier */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
