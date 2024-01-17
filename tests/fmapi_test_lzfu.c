/*
 * Library lzfu functions test program
 *
 * Copyright (C) 2009-2024, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <byte_stream.h>
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

#include "../libfmapi/libfmapi_lzfu.h"

uint8_t fmapi_test_lzfu_compressed_data1[ 164 ] = {
	0xa0, 0x00, 0x00, 0x00, 0xc3, 0x00, 0x00, 0x00, 0x4c, 0x5a, 0x46, 0x75, 0x49, 0x4a, 0x12, 0x91,
	0x03, 0x00, 0x0a, 0x00, 0x72, 0x63, 0x70, 0x67, 0x31, 0x32, 0x35, 0x16, 0x32, 0x00, 0xf8, 0x0b,
	0x60, 0x6e, 0x0e, 0x10, 0x30, 0x34, 0x33, 0x4f, 0x01, 0xf7, 0x02, 0xa4, 0x03, 0xe3, 0x02, 0x00,
	0x63, 0x68, 0x0a, 0xc0, 0x73, 0xb0, 0x65, 0x74, 0x30, 0x20, 0x07, 0x13, 0x02, 0x80, 0x7d, 0x0a,
	0x80, 0x9d, 0x00, 0x00, 0x2a, 0x09, 0xb0, 0x09, 0xf0, 0x04, 0x90, 0x61, 0x74, 0x05, 0xb1, 0x1a,
	0x52, 0x0d, 0xe0, 0x68, 0x09, 0x80, 0x01, 0xd0, 0x20, 0x35, 0x2e, 0xc0, 0x35, 0x30, 0x2e, 0x39,
	0x39, 0x2e, 0x01, 0xd0, 0x13, 0xa0, 0x49, 0x02, 0x80, 0x5c, 0x76, 0x08, 0x90, 0x77, 0x6b, 0x0b,
	0x80, 0x64, 0x7a, 0x34, 0x0c, 0x60, 0x63, 0x00, 0x50, 0x0b, 0x03, 0x0b, 0xb6, 0x0f, 0x04, 0x33,
	0xb0, 0x33, 0x20, 0x44, 0x69, 0x05, 0x40, 0x04, 0x00, 0x20, 0x09, 0xe1, 0xa8, 0x20, 0x6f, 0x70,
	0x07, 0x80, 0x72, 0x14, 0xb1, 0x67, 0x16, 0x15, 0x2f, 0x0f, 0x60, 0x0a, 0xa2, 0x0a, 0x80, 0x11,
	0xe1, 0x00, 0x19, 0x20 };

uint8_t fmapi_test_lzfu_uncompressed_data1[ 197 ] = {
	0x7b, 0x5c, 0x72, 0x74, 0x66, 0x31, 0x5c, 0x61, 0x6e, 0x73, 0x69, 0x5c, 0x61, 0x6e, 0x73, 0x69,
	0x63, 0x70, 0x67, 0x31, 0x32, 0x35, 0x32, 0x5c, 0x64, 0x65, 0x66, 0x66, 0x30, 0x5c, 0x64, 0x65,
	0x66, 0x6c, 0x61, 0x6e, 0x67, 0x31, 0x30, 0x34, 0x33, 0x7b, 0x5c, 0x66, 0x6f, 0x6e, 0x74, 0x74,
	0x62, 0x6c, 0x7b, 0x5c, 0x66, 0x30, 0x5c, 0x66, 0x73, 0x77, 0x69, 0x73, 0x73, 0x5c, 0x66, 0x63,
	0x68, 0x61, 0x72, 0x73, 0x65, 0x74, 0x30, 0x20, 0x41, 0x72, 0x69, 0x61, 0x6c, 0x3b, 0x7d, 0x7d,
	0x0d, 0x0a, 0x7b, 0x5c, 0x2a, 0x5c, 0x67, 0x65, 0x6e, 0x65, 0x72, 0x61, 0x74, 0x6f, 0x72, 0x20,
	0x52, 0x69, 0x63, 0x68, 0x65, 0x64, 0x32, 0x30, 0x20, 0x35, 0x2e, 0x35, 0x30, 0x2e, 0x39, 0x39,
	0x2e, 0x32, 0x30, 0x35, 0x30, 0x3b, 0x7d, 0x5c, 0x76, 0x69, 0x65, 0x77, 0x6b, 0x69, 0x6e, 0x64,
	0x34, 0x5c, 0x75, 0x63, 0x31, 0x5c, 0x70, 0x61, 0x72, 0x64, 0x5c, 0x66, 0x30, 0x5c, 0x66, 0x73,
	0x32, 0x30, 0x5c, 0x6c, 0x61, 0x6e, 0x67, 0x31, 0x30, 0x33, 0x33, 0x20, 0x44, 0x69, 0x74, 0x20,
	0x69, 0x73, 0x20, 0x65, 0x65, 0x6e, 0x20, 0x6f, 0x70, 0x6d, 0x65, 0x72, 0x6b, 0x69, 0x6e, 0x67,
	0x5c, 0x6c, 0x61, 0x6e, 0x67, 0x31, 0x30, 0x34, 0x33, 0x5c, 0x70, 0x61, 0x72, 0x0d, 0x0a, 0x7d,
	0x0d, 0x0a, 0x00, 0x00, 0x00 };

/* Tests the libfmapi_lzfu_get_uncompressed_data_size function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_lzfu_get_uncompressed_data_size(
     void )
{
	libcerror_error_t *error      = NULL;
	size_t uncompressed_data_size = 0;
	int result                    = 0;

	/* Test regular cases
	 */
	result = libfmapi_lzfu_get_uncompressed_data_size(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          &uncompressed_data_size,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_EQUAL_SIZE(
	 "uncompressed_data_size",
	 uncompressed_data_size,
	 (size_t) 197 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfmapi_lzfu_get_uncompressed_data_size(
	          NULL,
	          164,
	          &uncompressed_data_size,
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

	result = libfmapi_lzfu_get_uncompressed_data_size(
	          fmapi_test_lzfu_compressed_data1,
	          (size_t) SSIZE_MAX + 1,
	          &uncompressed_data_size,
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

	result = libfmapi_lzfu_get_uncompressed_data_size(
	          fmapi_test_lzfu_compressed_data1,
	          164,
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

	/* Test with invalid signature
	 */
	byte_stream_copy_from_uint32_little_endian(
	 &( fmapi_test_lzfu_compressed_data1[ 8 ] ),
	 0xffffffffUL );

	result = libfmapi_lzfu_get_uncompressed_data_size(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          &uncompressed_data_size,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 &( fmapi_test_lzfu_compressed_data1[ 8 ] ),
	 0x75465a4cUL );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid compressed data size
	 */
	byte_stream_copy_from_uint32_little_endian(
	 fmapi_test_lzfu_compressed_data1,
	 0xffffffffUL );

	result = libfmapi_lzfu_get_uncompressed_data_size(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          &uncompressed_data_size,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 fmapi_test_lzfu_compressed_data1,
	 0x000000a0UL );

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

/* Tests the libfmapi_lzfu_decompress function
 * Returns 1 if successful or 0 if not
 */
int fmapi_test_lzfu_decompress(
     void )
{
	uint8_t uncompressed_data[ 256 ];

	libcerror_error_t *error      = NULL;
	size_t uncompressed_data_size = 0;
	int result                    = 0;

	/* Test regular cases
	 */
	uncompressed_data_size = 256;

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FMAPI_TEST_ASSERT_EQUAL_SIZE(
	 "uncompressed_data_size",
	 uncompressed_data_size,
	 (size_t) 197 );

	FMAPI_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	uncompressed_data_size = 256;

	result = libfmapi_lzfu_decompress(
	          NULL,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
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

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          (size_t) SSIZE_MAX + 1,
	          uncompressed_data,
	          &uncompressed_data_size,
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

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          NULL,
	          &uncompressed_data_size,
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

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
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

	/* Test with invalid signature
	 */
	byte_stream_copy_from_uint32_little_endian(
	 &( fmapi_test_lzfu_compressed_data1[ 8 ] ),
	 0xffffffffUL );

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 &( fmapi_test_lzfu_compressed_data1[ 8 ] ),
	 0x75465a4cUL );

	FMAPI_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FMAPI_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with invalid compressed data size
	 */
	byte_stream_copy_from_uint32_little_endian(
	 fmapi_test_lzfu_compressed_data1,
	 0xffffffffUL );

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 fmapi_test_lzfu_compressed_data1,
	 0x000000a0UL );

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
#if defined( OPTIMIZATION_DISABLED )

	/* Test libfmapi_lzfu_decompress with memcpy failing
	 */
	fmapi_test_memcpy_attempts_before_fail = 0;

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
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
#endif /* defined( OPTIMIZATION_DISABLED ) */

	/* Test libfmapi_lzfu_decompress with memset failing
	 */
	fmapi_test_memset_attempts_before_fail = 0;

	result = libfmapi_lzfu_decompress(
	          fmapi_test_lzfu_compressed_data1,
	          164,
	          uncompressed_data,
	          &uncompressed_data_size,
	          &error );

	if( fmapi_test_memset_attempts_before_fail != -1 )
	{
		fmapi_test_memset_attempts_before_fail = -1;
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
#endif /* defined( HAVE_FMAPI_TEST_MEMORY ) */

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
	 "libfmapi_lzfu_get_uncompressed_data_size",
	 fmapi_test_lzfu_get_uncompressed_data_size );

	FMAPI_TEST_RUN(
	 "libfmapi_lzfu_decompress",
	 fmapi_test_lzfu_decompress );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

