/*
 * Library one_off_entry_identifier type test program
 *
 * Copyright (C) 2009-2019, Joachim Metz <joachim.metz@gmail.com>
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
#include "fmapi_test_libuna.h"
#include "fmapi_test_macros.h"
#include "fmapi_test_memory.h"
#include "fmapi_test_unused.h"

#include "../libfmapi/libfmapi_one_off_entry_identifier.h"

uint8_t fmapi_test_one_off_entry_identifier_data1[ 28 ] = {
	0x00, 0x00, 0x00, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00, 0x55, 0x4e, 0x4b, 0x4e,
	0x4f, 0x57, 0x4e, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00 };

uint8_t fmapi_test_one_off_entry_identifier_data2[ 52 ] = {
	0x00, 0x00, 0x00, 0x80, 0x55, 0x00, 0x6e, 0x00, 0x6b, 0x00, 0x6e, 0x00, 0x6f, 0x00, 0x77, 0x00,
	0x6e, 0x00, 0x00, 0x00, 0x55, 0x00, 0x4e, 0x00, 0x4b, 0x00, 0x4e, 0x00, 0x4f, 0x00, 0x57, 0x00,
	0x4e, 0x00, 0x00, 0x00, 0x55, 0x00, 0x6e, 0x00, 0x6b, 0x00, 0x6e, 0x00, 0x6f, 0x00, 0x77, 0x00,
	0x6e, 0x00, 0x00, 0x00 };

uint8_t fmapi_test_one_off_entry_identifier_data_invalid_format_version1[ 28 ] = {
	0xff, 0xff, 0x00, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00, 0x55, 0x4e, 0x4b, 0x4e,
	0x4f, 0x57, 0x4e, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00 };

uint8_t fmapi_test_one_off_entry_identifier_data_invalid_flags1[ 28 ] = {
	0x00, 0x00, 0xff, 0xff, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00, 0x55, 0x4e, 0x4b, 0x4e,
	0x4f, 0x57, 0x4e, 0x00, 0x55, 0x6e, 0x6b, 0x6e, 0x6f, 0x77, 0x6e, 0x00 };

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

	one_off_entry_identifier = NULL;

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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

/* Tests the libfmapi_one_off_entry_identifier_copy_from_byte_stream function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_copy_from_byte_stream(
     void )
{
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;

#if defined( HAVE_FMAPI_TEST_MEMORY )
	int number_of_malloc_fail_tests                               = 3;
	int test_number                                               = 0;

#if defined( OPTIMIZATION_DISABLED )
	int number_of_memcpy_fail_tests                               = 3;
#endif
#endif /* defined( HAVE_FMAPI_TEST_MEMORY ) */

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
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data1,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data2,
	          52,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          NULL,
	          fmapi_test_one_off_entry_identifier_data1,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          NULL,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data1,
	          (size_t) SSIZE_MAX + 1,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data1,
	          0,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	/* Test with invalid format version
	 */
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data_invalid_format_version1,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	/* Test with invalid flags
	 */
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data_invalid_flags1,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

	/* Test with missing data
	 */
	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data1,
	          4,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
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

#if defined( HAVE_FMAPI_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfmapi_one_off_entry_identifier_copy_from_byte_stream with malloc failing
		 */
		fmapi_test_malloc_attempts_before_fail = test_number;

		result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
		          one_off_entry_identifier,
		          fmapi_test_one_off_entry_identifier_data1,
		          28,
		          LIBUNA_CODEPAGE_WINDOWS_1252,
		          &error );

		if( fmapi_test_malloc_attempts_before_fail != -1 )
		{
			fmapi_test_malloc_attempts_before_fail = -1;
		}
		else
		{
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
	}
#if defined( OPTIMIZATION_DISABLED )
	for( test_number = 0;
	     test_number < number_of_memcpy_fail_tests;
	     test_number++ )
	{
		/* Test libfmapi_one_off_entry_identifier_copy_from_byte_stream with memcpy failing
		 */
		fmapi_test_memcpy_attempts_before_fail = test_number;

		result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
		          one_off_entry_identifier,
		          fmapi_test_one_off_entry_identifier_data1,
		          28,
		          LIBUNA_CODEPAGE_WINDOWS_1252,
		          &error );

		if( fmapi_test_memcpy_attempts_before_fail != -1 )
		{
			fmapi_test_memcpy_attempts_before_fail = -1;
		}
		else
		{
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
	}
#endif /* defined( OPTIMIZATION_DISABLED ) */
#endif /* defined( HAVE_FMAPI_TEST_MEMORY ) */

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

/* Tests the libfmapi_one_off_entry_identifier_get_version function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_version(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	uint16_t version         = 0;
	int result               = 0;

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_flags function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_flags(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	uint16_t flags           = 0;
	int result               = 0;

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_display_name_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_display_name_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
	          one_off_entry_identifier,
	          &utf8_string_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
	          NULL,
	          &utf8_string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_display_name function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_display_name(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
	          one_off_entry_identifier,
	          utf8_string,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_display_name(
	          NULL,
	          utf8_string,
	          32,
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
	          NULL,
	          32,
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
	          utf8_string,
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
	          utf8_string,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_display_name_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_display_name_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
	          one_off_entry_identifier,
	          &utf16_string_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
	          NULL,
	          &utf16_string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_display_name function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_display_name(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
	          one_off_entry_identifier,
	          utf16_string,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_display_name(
	          NULL,
	          utf16_string,
	          32,
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
	          NULL,
	          32,
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
	          utf16_string,
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
	          utf16_string,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_address_type_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_address_type_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf8_string_size  = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
	          one_off_entry_identifier,
	          &utf8_string_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
	          NULL,
	          &utf8_string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_address_type function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_address_type(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint8_t utf8_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
	          one_off_entry_identifier,
	          utf8_string,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_address_type(
	          NULL,
	          utf8_string,
	          32,
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
	          NULL,
	          32,
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
	          utf8_string,
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
	          utf8_string,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_address_type_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_address_type_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
	          one_off_entry_identifier,
	          &utf16_string_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
	          NULL,
	          &utf16_string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_address_type function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_address_type(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
	          one_off_entry_identifier,
	          utf16_string,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_address_type(
	          NULL,
	          utf16_string,
	          32,
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
	          NULL,
	          32,
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
	          utf16_string,
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
	          utf16_string,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_email_address_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_email_address_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf8_sting_size   = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
	          one_off_entry_identifier,
	          &utf8_sting_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
	          NULL,
	          &utf8_sting_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf8_email_address function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf8_email_address(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint8_t utf8_sting[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
	          one_off_entry_identifier,
	          utf8_sting,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf8_email_address(
	          NULL,
	          utf8_sting,
	          32,
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
	          NULL,
	          32,
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
	          utf8_sting,
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
	          utf8_sting,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_email_address_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_email_address_size(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	libcerror_error_t *error = NULL;
	size_t utf16_string_size = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
	          one_off_entry_identifier,
	          &utf16_string_size,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
	          NULL,
	          &utf16_string_size,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfmapi_one_off_entry_identifier_get_utf16_email_address function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_one_off_entry_identifier_get_utf16_email_address(
     libfmapi_one_off_entry_identifier_t *one_off_entry_identifier )
{
	uint16_t utf16_string[ 32 ];

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
	          one_off_entry_identifier,
	          utf16_string,
	          32,
	          &error );

	FMAPI_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_one_off_entry_identifier_get_utf16_email_address(
	          NULL,
	          utf16_string,
	          32,
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
	          NULL,
	          32,
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
	          utf16_string,
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
	          utf16_string,
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
	libcerror_error_t *error                                      = NULL;
	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;
	int result                                                    = 0;

	FMAPI_TEST_UNREFERENCED_PARAMETER( argc )
	FMAPI_TEST_UNREFERENCED_PARAMETER( argv )

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_initialize",
	 fmapi_test_one_off_entry_identifier_initialize );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_free",
	 fmapi_test_one_off_entry_identifier_free );

	FMAPI_TEST_RUN(
	 "libfmapi_one_off_entry_identifier_copy_from_byte_stream",
	 fmapi_test_one_off_entry_identifier_copy_from_byte_stream );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize one_off_entry_identifier for tests
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

	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data1,
	          28,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_version",
	 fmapi_test_one_off_entry_identifier_get_version,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_flags",
	 fmapi_test_one_off_entry_identifier_get_flags,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address,
	 one_off_entry_identifier );

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

	/* Initialize one_off_entry_identifier for tests
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

	result = libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	          one_off_entry_identifier,
	          fmapi_test_one_off_entry_identifier_data2,
	          52,
	          LIBUNA_CODEPAGE_WINDOWS_1252,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_version",
	 fmapi_test_one_off_entry_identifier_get_version,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_flags",
	 fmapi_test_one_off_entry_identifier_get_flags,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf8_display_name,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_display_name",
	 fmapi_test_one_off_entry_identifier_get_utf16_display_name,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf8_address_type,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_address_type",
	 fmapi_test_one_off_entry_identifier_get_utf16_address_type,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf8_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf8_email_address,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address_size",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address_size,
	 one_off_entry_identifier );

	FMAPI_TEST_RUN_WITH_ARGS(
	 "libfmapi_one_off_entry_identifier_get_utf16_email_address",
	 fmapi_test_one_off_entry_identifier_get_utf16_email_address,
	 one_off_entry_identifier );

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

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

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
	return( EXIT_FAILURE );
}

