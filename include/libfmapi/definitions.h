/*
 * Definitions for libfmapi
 *
 * Copyright (c) 2009-2014, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFMAPI_DEFINITIONS_H )
#define _LIBFMAPI_DEFINITIONS_H

#include <libfmapi/types.h>

#define LIBFMAPI_VERSION					20140920

/* The version string
 */
#define LIBFMAPI_VERSION_STRING					"20140920"

/* The byte order definitions
 */
enum LIBFMAPI_ENDIAN
{
	LIBFMAPI_ENDIAN_BIG					= (int) 'b',
	LIBFMAPI_ENDIAN_LITTLE					= (int) 'l'
};

/* The GUID identifier version definitions
 */
enum LIBFMAPI_IDENTIFIER_VERSIONS
{
	LIBFMAPI_IDENTIFIER_VERSION_TIME_BASED			= 1,
	LIBFMAPI_IDENTIFIER_VERSION_DCE				= 2,
	LIBFMAPI_IDENTIFIER_VERSION_NAME_BASED			= 3,
	LIBFMAPI_IDENTIFIER_VERSION_RANDOM_BASED		= 4
};

/* The string format definition flags
 */
enum LIBFMAPI_STRING_FORMAT_FLAGS
{
	/* Format the using lower case
	 */
	LIBFMAPI_STRING_FORMAT_FLAG_USE_LOWER_CASE		= 0x00000001UL,

	/* Format the using upper case
	 */
	LIBFMAPI_STRING_FORMAT_FLAG_USE_UPPER_CASE		= 0x00000002UL,

	/* Format the using mixed case
	 */
	LIBFMAPI_STRING_FORMAT_FLAG_USE_MIXED_CASE		= 0x00000003UL,

	/* Format the using surrounding braces { GUID }
	 */
	LIBFMAPI_STRING_FORMAT_FLAG_USE_SURROUNDING_BRACES	= 0x00000004UL
};

#endif

