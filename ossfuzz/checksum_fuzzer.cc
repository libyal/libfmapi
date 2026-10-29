/*
 * OSS-Fuzz target for libfmapi checksum functions
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

#include "../libfmapi/libfmapi_checksum.h"

int LLVMFuzzerTestOneInput(
     const uint8_t *data,
     size_t size )
{
	uint32_t checksum        = 0;

	uint32_t initial_value   = 0;

	if( size >= 3 )
	{
		initial_value = (uint32_t) data[ 0 ]
		    | ( (uint32_t) data[ 1 ] << 8 )
		    | ( (uint32_t) data[ 2 ] << 16 );
	}
	if( libfmapi_checksum_calculate_crc32(
	     &checksum,
	     data,
	     size,
	     0,
	     NULL ) != 1 )
	{
		return( 0 );
	}
	libfmapi_checksum_calculate_weak_crc32(
	 &checksum,
	 data,
	 size,
	 0,
	 NULL );

	libfmapi_checksum_calculate_weak_crc32(
	 &checksum,
	 data,
	 size,
	 initial_value,
	 NULL );

	return( 0 );
}

} /* extern "C" */
