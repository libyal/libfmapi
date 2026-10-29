/*
 * OSS-Fuzz target for libfmapi entry_identifier type
 *
 * Copyright (C) 2011-2026, Joachim Metz <joachim.metz@gmail.com>
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

#include <stddef.h>
#include <stdint.h>

/* Note that some of the OSS-Fuzz engines use C++
 */
extern "C" {

#include "ossfuzz_libfmapi.h"

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	char error_string[ 4096 ]          = { 0 };

	libfmapi_error_t *error            = NULL;

	libfmapi_entry_identifier_t *entry_identifier = NULL;

	uint8_t guid_data[ 16 ]            = { 0 };

	if( libfmapi_entry_identifier_initialize(
	     &entry_identifier,
	     &error ) == 1
	 && libfmapi_entry_identifier_copy_from_byte_stream(
	     entry_identifier,
	     data,
	     size,
	     &error ) == 1 )
	{
		libfmapi_entry_identifier_get_service_provider_identifier(
		 entry_identifier,
		 guid_data,
		 16,
		 &error );
	}
	libfmapi_entry_identifier_free(
	 &entry_identifier,
	 &error );

	if( error != NULL )
	{
		libfmapi_error_sprint(
		 error,
		 error_string,
		 sizeof( error_string ) );

		libfmapi_error_backtrace_sprint(
		 error,
		 error_string,
		 sizeof( error_string ) );
	}
	libfmapi_error_free(
	 &error );

	return( 0 );
}

} /* extern "C" */
