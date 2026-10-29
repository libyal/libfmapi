/*
 * OSS-Fuzz target for libfmapi one_off_entry_identifier type
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
#include <stdlib.h>

/* Note that some of the OSS-Fuzz engines use C++
 */
extern "C" {

#include "ossfuzz_libfmapi.h"

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	char error_string[ 4096 ]                       = { 0 };

	libfmapi_error_t *error                         = NULL;

	libfmapi_one_off_entry_identifier_t *one_off_entry_identifier = NULL;

	uint16_t format_version                         = 0;
	uint16_t flags                                  = 0;

	size_t utf16_string_size                        = 0;
	size_t utf8_string_size                         = 0;

	if( libfmapi_one_off_entry_identifier_initialize(
	     &one_off_entry_identifier,
	     &error ) == 1
	/* TODO replace 1252 by codepage definition */
	 && libfmapi_one_off_entry_identifier_copy_from_byte_stream(
	     one_off_entry_identifier,
	     data,
	     size,
	     1252,
	     &error ) == 1 )
	{
		libfmapi_one_off_entry_identifier_get_version(
		 one_off_entry_identifier,
		 &format_version,
		 &error );

		libfmapi_one_off_entry_identifier_get_flags(
		 one_off_entry_identifier,
		 &flags,
		 &error );

		/* Retrieves the display name as UTF-16 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf16_display_name_size(
		    one_off_entry_identifier,
		    &utf16_string_size,
		    &error ) == 1
		 && ( utf16_string_size > 1 )
		 && ( utf16_string_size <= 16384 ) )
		{
			uint16_t *utf16_string = (uint16_t *) malloc( sizeof( uint16_t ) * utf16_string_size );

			if( utf16_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf16_display_name(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf16_display_name(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size,
				 &error );

				free(
				 utf16_string );
			}
		}
		/* Retrieves the display name as UTF-8 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf8_display_name_size(
		    one_off_entry_identifier,
		    &utf8_string_size,
		    &error ) == 1
		 && ( utf8_string_size > 1 )
		 && ( utf8_string_size <= 16384 ) )
		{
			uint8_t *utf8_string        = (uint8_t *) malloc( utf8_string_size );

			if( utf8_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf8_display_name(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf8_display_name(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size,
				 &error );

				free(
				 utf8_string );
			}
		}
		/* Retrieves the address type as UTF-16 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf16_address_type_size(
		    one_off_entry_identifier,
		    &utf16_string_size,
		    &error ) == 1
		 && ( utf16_string_size > 1 )
		 && ( utf16_string_size <= 16384 ) )
		{
			uint16_t *utf16_string = (uint16_t *) malloc( sizeof( uint16_t ) * utf16_string_size );

			if( utf16_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf16_address_type(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf16_address_type(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size,
				 &error );

				free(
				 utf16_string );
			}
		}
		/* Retrieves the address type as UTF-8 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf8_address_type_size(
		    one_off_entry_identifier,
		    &utf8_string_size,
		    &error ) == 1
		 && ( utf8_string_size > 1 )
		 && ( utf8_string_size <= 16384 ) )
		{
			uint8_t *utf8_string        = (uint8_t *) malloc( utf8_string_size );

			if( utf8_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf8_address_type(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf8_address_type(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size,
				 &error );

				free(
				 utf8_string );
			}
		}
		/* Retrieves the email address as UTF-16 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf16_email_address_size(
		    one_off_entry_identifier,
		    &utf16_string_size,
		    &error ) == 1
		 && ( utf16_string_size > 1 )
		 && ( utf16_string_size <= 16384 ) )
		{
			uint16_t *utf16_string = (uint16_t *) malloc( sizeof( uint16_t ) * utf16_string_size );

			if( utf16_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf16_email_address(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf16_email_address(
				 one_off_entry_identifier,
				 utf16_string,
				 utf16_string_size,
				 &error );

				free(
				 utf16_string );
			}
		}
		/* Retrieves the email address as UTF-8 string
		 */
		if( libfmapi_one_off_entry_identifier_get_utf8_email_address_size(
		    one_off_entry_identifier,
		    &utf8_string_size,
		    &error ) == 1
		 && ( utf8_string_size > 1 )
		 && ( utf8_string_size <= 16384 ) )
		{
			uint8_t *utf8_string        = (uint8_t *) malloc( utf8_string_size );

			if( utf8_string != NULL )
			{
				libfmapi_one_off_entry_identifier_get_utf8_email_address(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size - 1,
				 &error );

				libfmapi_one_off_entry_identifier_get_utf8_email_address(
				 one_off_entry_identifier,
				 utf8_string,
				 utf8_string_size,
				 &error );

				free(
				 utf8_string );
			}
		}
	}
	libfmapi_one_off_entry_identifier_free(
	 &one_off_entry_identifier,
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
