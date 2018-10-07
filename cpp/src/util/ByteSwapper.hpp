/*
 *  KVStore - A distributed key value store supporting a common set of data
 *  types and arrays over a multicast network.
 *
 *  Copyright (C) 2017 Harlan Murphy
 *  harlan3@hotmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License Version 3 dated 29 June 2007, as published by the
 *  Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library.  If not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef BYTESWAPPER_H_
#define BYTESWAPPER_H_

#include <iostream>
#include <stdint.h>

using namespace std;

class ByteSwapper {
public:

    // Perform byte swap on two bytes
    static void swapTwoBytes(int8_t* data);

    // Perform byte swap on four bytes
    static void swapFourBytes(int8_t* data);

    // Perform byte swap on eight bytes.
    static void swapEightBytes(int8_t* data);

    // Perform byte swap on a two byte array
    static void swapTwoByteArray(int8_t* data, int32_t numberElements);

    // Perform byte swap on a four byte array
    static void swapFourByteArray(int8_t* data, int32_t numberElements);

    // Perform byte swap on a eight byte array
    static void swapEightByteArray(int8_t* data, int32_t numberElements);
};

#endif
