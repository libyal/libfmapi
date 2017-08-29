/*
 * Library one_off_entry_identifier type test program
 *
 * Copyright (C) 2009-2017, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libfmapi/libfmapi_one_off_entry_identifier.h"

/* Tests the libfmapi_one_off_entry_identifier_initialize function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_initialize(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;

#if defined( HAVE_FMAPI_TEST_MEMORY )
	int number_of_malloc_fail_tests                               = 1;
	int number_of_memset_fail_tests                               = 1;
	int test_number                                               = 0;
#endif

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
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

	one_off_entry_identifier = (libfmapi_one_off_entry_identifier_t *) 0x12345678UL;

	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
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

	one_off_entry_identifier = NULL;

#if defined( HAVE_FMAPI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfmapi_one_off_entry_identifier_initialize with malloc failing
		 */
		fmapi_test_malloc_attempts_before_fail = test_number;

		result = libfmapi_one_off_entry_identifier_initialize(
		          &one_off_entry_identifier,
		          &error );

		if( fmapi_test_malloc_attempts_before_fail != -1 )
		{
			fmapi_test_malloc_attempts_before_fail = -1;

			if( one_off_entry_identifier != NULL )
			{
				libfmapi_one_off_entry_identifier_free(
				 &one_off_entry_identifier,
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
			 "one_off_entry_identifier",
			 one_off_entry_identifier );

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
		/* Test libfmapi_one_off_entry_identifier_initialize with memset failing
		 */
		fmapi_test_memset_attempts_before_fail = test_number;

		result = libfmapi_one_off_entry_identifier_initialize(
		          &one_off_entry_identifier,
		          &error );

		if( fmapi_test_memset_attempts_before_fail != -1 )
		{
			fmapi_test_memset_attempts_before_fail = -1;

			if( one_off_entry_identifier != NULL )
			{
				libfmapi_one_off_entry_identifier_free(
				 &one_off_entry_identifier,
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
			 "one_off_entry_identifier",
			 one_off_entry_identifier );

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
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_free function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_free(
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

/* Tests the libfmapi_one_off_entry_identifier_get_version function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_version(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	uint16_t version                                              = 0;
	int result                                                    = 0;
	int version_is_set                                            = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_version(
	          one_off_entry_identifier,
	          &version,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	version_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_version(
	          NULL,
	          &version,
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

	if( version_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_version(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_flags function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_flags(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	uint16_t flags                                                = 0;
	int flags_is_set                                              = 0;
	int result                                                    = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_flags(
	          one_off_entry_identifier,
	          &flags,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	flags_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_flags(
	          NULL,
	          &flags,
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

	if( flags_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_flags(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_display_name_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_display_name_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf8_display_name_size                                 = 0;
	int result                                                    = 0;
	int utf8_display_name_size_is_set                             = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
	          one_off_entry_identifier,
	          &utf8_display_name_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_display_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
	          NULL,
	          &utf8_display_name_size,
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

	if( utf8_display_name_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_display_name function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_display_name(
     void )
{
	uint8_t utf8_display_name[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf8_display_name_is_set                                  = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
	          one_off_entry_identifier,
	          utf8_display_name,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_display_name_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
	          NULL,
	          utf8_display_name,
	          512,
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

	if( utf8_display_name_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
		          one_off_entry_identifier,
		          utf8_display_name,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
		          one_off_entry_identifier,
		          utf8_display_name,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_display_name_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_display_name_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf16_display_name_size                                = 0;
	int result                                                    = 0;
	int utf16_display_name_size_is_set                            = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
	          one_off_entry_identifier,
	          &utf16_display_name_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_display_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
	          NULL,
	          &utf16_display_name_size,
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

	if( utf16_display_name_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_display_name function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_display_name(
     void )
{
	uint16_t utf16_display_name[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf16_display_name_is_set                                 = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
	          one_off_entry_identifier,
	          utf16_display_name,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_display_name_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
	          NULL,
	          utf16_display_name,
	          512,
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

	if( utf16_display_name_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
		          one_off_entry_identifier,
		          utf16_display_name,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
		          one_off_entry_identifier,
		          utf16_display_name,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_address_type_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_address_type_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf8_address_type_size                                 = 0;
	int result                                                    = 0;
	int utf8_address_type_size_is_set                             = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
	          one_off_entry_identifier,
	          &utf8_address_type_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_address_type_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
	          NULL,
	          &utf8_address_type_size,
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

	if( utf8_address_type_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_address_type function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_address_type(
     void )
{
	uint8_t utf8_address_type[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf8_address_type_is_set                                  = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
	          one_off_entry_identifier,
	          utf8_address_type,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_address_type_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
	          NULL,
	          utf8_address_type,
	          512,
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

	if( utf8_address_type_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
		          one_off_entry_identifier,
		          utf8_address_type,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
		          one_off_entry_identifier,
		          utf8_address_type,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_address_type_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_address_type_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf16_address_type_size                                = 0;
	int result                                                    = 0;
	int utf16_address_type_size_is_set                            = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
	          one_off_entry_identifier,
	          &utf16_address_type_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_address_type_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
	          NULL,
	          &utf16_address_type_size,
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

	if( utf16_address_type_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_address_type function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_address_type(
     void )
{
	uint16_t utf16_address_type[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf16_address_type_is_set                                 = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
	          one_off_entry_identifier,
	          utf16_address_type,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_address_type_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
	          NULL,
	          utf16_address_type,
	          512,
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

	if( utf16_address_type_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
		          one_off_entry_identifier,
		          utf16_address_type,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
		          one_off_entry_identifier,
		          utf16_address_type,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_email_address_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_email_address_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf8_email_address_size                                = 0;
	int result                                                    = 0;
	int utf8_email_address_size_is_set                            = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
	          one_off_entry_identifier,
	          &utf8_email_address_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_email_address_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
	          NULL,
	          &utf8_email_address_size,
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

	if( utf8_email_address_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_email_address function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_email_address(
     void )
{
	uint8_t utf8_email_address[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf8_email_address_is_set                                 = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
	          one_off_entry_identifier,
	          utf8_email_address,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_email_address_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
	          NULL,
	          utf8_email_address,
	          512,
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

	if( utf8_email_address_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
		          one_off_entry_identifier,
		          utf8_email_address,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
		          one_off_entry_identifier,
		          utf8_email_address,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_email_address_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_email_address_size(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	size_t utf16_email_address_size                               = 0;
	int result                                                    = 0;
	int utf16_email_address_size_is_set                           = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
	          one_off_entry_identifier,
	          &utf16_email_address_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_email_address_size_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
	          NULL,
	          &utf16_email_address_size,
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

	if( utf16_email_address_size_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
		          one_off_entry_identifier,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_email_address function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_email_address(
     void )
{
	uint16_t utf16_email_address[ 512 ];

	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;
	int utf16_email_address_is_set                                = 0;

	/* Initialize test
	 */
	result = libfmapi_one_off_entry_identifier_initialize(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
	          one_off_entry_identifier,
	          utf16_email_address,
	          512,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_email_address_is_set = result;

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
	          NULL,
	          utf16_email_address,
	          512,
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

	if( utf16_email_address_is_set != 0 )
	{
		result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
		          one_off_entry_identifier,
		          NULL,
		          512,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
		          one_off_entry_identifier,
		          utf16_email_address,
		          0,
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

		result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
		          one_off_entry_identifier,
		          utf16_email_address,
		          (size_t) SSIZE_MAX + 1,
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
	}
	/* Clean up
	 */
	result = libfmapi_one_off_entry_identifier_free(
	          &one_off_entry_identifier,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "one_off_entry_identifier",
	 one_off_entry_identifier );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( one_off_entry_identifier != NULL )
	{
		libfmapi_one_off_entry_identifier_free(
		 &one_off_entry_identifier,
		 NULL );
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
	 "libfmapi_one_off_entry_identifier_initialize",
	 fmapi_test_one_off_entry_identifier_initialize );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_free",
	 fmapi_test_one_off_entry_identifier_free );

#if defined( TODO )

	/* TODO: add tests for libfmapi_one_off_entry_identifier_copy_from_byte_stream */

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_version",
	 fmapi_test_one_off_entry_identifier_get_version );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_flags",
	 fmapi_test_one_off_entry_identifier_get_flags );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address_size );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address );

#endif /* defined( TODO ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

