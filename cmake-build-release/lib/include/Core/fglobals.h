/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROJECT_FGLOBALS_H
#define PROJECT_FGLOBALS_H

//Engine Internal
#include "Utils/FDebug.hpp"

//C++ Includes

#include <cstdint>

#define FIENE_VERSION_MAJOR 0
#define FIENE_VERSION_MINOR 1
#define FIENE_VERSION_PATCH 1

#if !_DEBUG
#define NDEBUG
#endif

namespace Fiene {

    typedef unsigned int    uint;

    typedef uint8_t         u8;
    typedef uint16_t        u16;
    typedef uint32_t        u32;
    typedef uint64_t        u64;
    typedef uintptr_t       uptr;

    #define F_ASSERT(condition, msg) do \
    { if (!(condition)) { errorLog("File: %s\nFunction: %s\nLine:%d\nMessage: %s\n--ERROR END--\n", __FILE__, __func__, __LINE__, msg); Exit(1); } \
    } while(0);

    #define ASSERT(condition) do \
    { if (!(condition)) { errorLog("Assertion Fails: File: %s\nFunction: %s\nLine:%d\n %s\n--END--\n", __FILE__, __func__, __LINE__); Exit(1); } \
    } while(0);


    #define F_DISABLE_COPY(Class) \
        Class(const Class &) = delete; \
        Class &operator =(const Class &) = delete;

    #define F_DISABLE_MOVE(Class) \
        Class(const Class &&) = delete; \
        Class &operator =(const Class &&) = delete;

    #ifdef _WIN32
        #define FIENE_FINAL final
        #define FIENE_LIBRARY_EXPORT __declspec(dllexport)
        #define FIENE_LIBRARY_IMPORT __declspec(dllimport)
        #define FIENE_FORCE_INLINE __forceinline
        #define FIENE_RESTRICT __restrict
        #define FIENE_ATTRIBUTE_USED
    #else
        #define FIENE_FINAL final
        #define FIENE_LIBRARY_EXPORT __attribute__((visibility("default")))
        #define FIENE_LIBRARY_IMPORT
        #define FIENE_FORCE_INLINE __attribute__((always_inline)) inline
        #define FIENE_RESTRICT __restrict__
        #define FIENE_ATTRIBUTE_USED __attribute__((used))
    #endif


    #define ONEMEG_SIZE 1048576
    #define TWOMEG_SIZE 2097152
    #define FOURMEG_SIZE 4194304
    #define EIGHTMEG_SIZE 8388608
    #define ONEGIG_SIZE 1048576000
    #define TWOGIG_SIZE 2147483648
    #define FOURGIG_SIZE 4294967296

}

#endif //PROJECT_FGLOBALS_H
