/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  **Pool Allocator , Original Author Tiago Costa, 2014
 *  **Date Modified : 02/Apr/2017 - Stelmach Rostislav
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

//Engine Internal
#include "PoolAllocator.hpp"


namespace Fiene {

    PoolAllocator::PoolAllocator(size_t objectSize, u8 objectAlignment, size_t size, void* mem)
              : BaseAllocator(size,mem)
              , m_ObjectSize(objectSize)
              , m_ObjectAlignment(objectAlignment)
    {
        ASSERT(objectSize >= sizeof(void*));

        //Calculate adjustment needed to keep object correctly aligned
        u8 adjustment = Ptr_Math::alignForwardAdjustment(mem, objectAlignment);

        m_FreeList = (void**)Ptr_Math::add(mem, adjustment);

        size_t numObjects = (size-adjustment)/objectSize;

        void** p = m_FreeList;

        //Initialize free blocks list
        for(size_t i = 0; i < numObjects-1; i++)
        {
            *p = Ptr_Math::add(p, objectSize );
            p = (void**) *p;
        }

        *p = nullptr;
    }

    PoolAllocator::~PoolAllocator()
    {
        m_FreeList = nullptr;
    }

    void* PoolAllocator::allocate(size_t size, u8 alignment) noexcept
    {
        ASSERT(size == m_ObjectSize && alignment == m_ObjectAlignment);

        if(m_FreeList == nullptr)
            return nullptr;

        void* p = m_FreeList;

        m_FreeList = (void**)(*m_FreeList);

        ba_UsedMemory += size;
        ba_AllocationsCount++;

        return p;
    }

    void PoolAllocator::deallocate(void* p) noexcept
    {
        *((void**)p) = m_FreeList;

        m_FreeList = (void**)p;

        ba_UsedMemory -= m_ObjectSize;
        ba_AllocationsCount--;
    }

}


