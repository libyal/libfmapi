/*
 * MAPI definitions
 *
 * Copyright (C) 2009-2018, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( MAPI_DEFINITIONS_H )
#define MAPI_DEFINITIONS_H

/* MAPI property data type definitions
 */
#define PT_UNSPECIFIED						0x0000
#define PT_UNKNOWN						0x0000
#define PT_NULL							0x0001
#define PT_SHORT						0x0002
#define PT_I2							0x0002
#define PT_LONG							0x0003
#define PT_I4							0x0003
#define PT_FLOAT						0x0004
#define PT_R4							0x0004
#define PT_DOUBLE						0x0005
#define PT_R8							0x0005
#define PT_CURRENCY						0x0006
#define PT_APPTIME						0x0007
#define PT_ERROR						0x000a
#define PT_BOOLEAN						0x000b
#define PT_OBJECT						0x000d
#define PT_LONGLONG						0x0014
#define PT_I8							0x0014
#define PT_STRING8						0x001e
#define PT_UNICODE						0x001f
#define PT_SYSTIME						0x0040
#define PT_CLSID						0x0048
#define PT_SVREID						0x00fb
#define PT_SRESTRICT						0x00fd
#define PT_ACTIONS						0x00fe
#define PT_BINARY						0x0102

/* Multi value flag
 */
#define PT_MV_FLAG						0x1000

/* Multi instance flag
 */
#define PT_MI_FLAG						0x2000

/* MAPI multi value property data type definitions
 */
#define PT_MV_SHORT						( PT_MV_FLAG | PT_SHORT )
#define PT_MV_I2						( PT_MV_FLAG | PT_I2 )
#define PT_MV_LONG						( PT_MV_FLAG | PT_LONG )
#define PT_MV_I4						( PT_MV_FLAG | PT_I4 )
#define PT_MV_FLOAT						( PT_MV_FLAG | PT_FLOAT )
#define PT_MV_R4						( PT_MV_FLAG | PT_R4 )
#define PT_MV_DOUBLE						( PT_MV_FLAG | PT_DOUBLE )
#define PT_MV_R8						( PT_MV_FLAG | PT_R8 )
#define PT_MV_CURRENCY						( PT_MV_FLAG | PT_CURRENCY )
#define PT_MV_APPTIME						( PT_MV_FLAG | PT_APPTIME )
#define PT_MV_LONGLONG						( PT_MV_FLAG | PT_LONGLONG )
#define PT_MV_I8						( PT_MV_FLAG | PT_I8 )
#define PT_MV_STRING8						( PT_MV_FLAG | PT_STRING8 )
#define PT_MV_UNICODE						( PT_MV_FLAG | PT_UNICODE )
#define PT_MV_SYSTIME						( PT_MV_FLAG | PT_SYSTIME )
#define PT_MV_CLSID						( PT_MV_FLAG | PT_CLSID )
#define PT_MV_BINARY						( PT_MV_FLAG | PT_BINARY )

#endif

