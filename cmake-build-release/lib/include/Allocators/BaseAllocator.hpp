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

#ifndef PROJECT_BASEALLOCATOR_HPP
#define PROJECT_BASEALLOCATOR_HPP

//C++ Includes
#include <cstddef>
#include <new>

//Engine Internal
#include "Core/Fiene.h"

namespace Fiene {

    class BaseAllocator {
    public:
                                BaseAllocator(size_t size, void* start);
        virtual                 ~BaseAllocator();

        virtual void*           allocate(size_t size, u8 alignment) noexcept = 0;
        virtual void            deallocate(void* pMem) noexcept = 0;

        size_t                  getSize() const         { return ba_Size; }
        size_t                  getUsedMem() const      { return ba_UsedMemory; }
        size_t                  getAllocations() const  { return ba_AllocationsCount; }
        void*                   getStart() const        { return ba_StartPtr; }

    protected:
        void*                   ba_StartPtr;
        size_t                  ba_Size;
        size_t                  ba_UsedMemory;
        size_t                  ba_AllocationsCount;
    };

    template <class T> T* allocateNew(BaseAllocator& allocator)
    {
        return new (allocator.allocate(sizeof(T), __alignof(T))) T;
    }

    template <class T> T* allocateNew(BaseAllocator& allocator, const T& t)
    {
        return new (allocator.allocate(sizeof(T), __alignof(T))) T(t);
    }

    template<class T> void deallocateDelete(BaseAllocator& allocator, T& object)
    {
        object.~T();
        allocator.deallocate(&object);
    }

    template<class T> T* allocateArray(BaseAllocator& allocator, size_t length)
    {
        ASSERT(length != 0);

        u8 headerSize = sizeof(size_t)/sizeof(T);

        if(sizeof(size_t)%sizeof(T) > 0)
            headerSize += 1;

        //Allocate extra space to store array length in the bytes before the array
        T* p = ( (T*) allocator.allocate(sizeof(T)*(length + headerSize), __alignof(T)) ) + headerSize;

        *( ((size_t*)p) - 1 ) = length;

        for(size_t i = 0; i < length; i++)
            new (&p[i]) T;

        return p;
    }

    template<class T> void deallocateArray(BaseAllocator& allocator, T* array)
    {
        ASSERT(array != nullptr);

        size_t length = *( ((size_t*)array) - 1 );

        for(size_t i = 0; i < length; i++)
            array[i].~T();

        //Calculate how much extra memory was allocated to store the length before the array
        u8 headerSize = sizeof(size_t)/sizeof(T);

        if(sizeof(size_t)%sizeof(T) > 0)
            headerSize += 1;

        allocator.deallocate(array - headerSize);
    }

}

#endif //PROJECT_BASEALLOCATOR_HPP
