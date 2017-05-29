/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  **Linear Allocator , Original Author Tiago Costa, 2014
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

#include "LinearAllocator.hpp"


namespace Fiene {

    LinearAllocator::LinearAllocator(size_t size, void* start)
            : BaseAllocator(size,start)
            , m_CurrentPos(start)
    {
        ASSERT(size > 0);
    }

    LinearAllocator::~LinearAllocator()
    {
        m_CurrentPos   = nullptr;
    }

    void* LinearAllocator::allocate(size_t size, u8 alignment) noexcept
    {
        ASSERT(size != 0);

        u8 adjustment =  Ptr_Math::alignForwardAdjustment(m_CurrentPos, alignment);

        if(ba_UsedMemory + adjustment + size > ba_Size) {
            return nullptr;
        }

        uptr aligned_address = (uptr)m_CurrentPos + adjustment;

        m_CurrentPos = (void*)(aligned_address + size);

        ba_UsedMemory += size + adjustment;
        ba_AllocationsCount++;

        return (void*)aligned_address;
    }

    void LinearAllocator::deallocate(void* p) noexcept
    {
        F_ASSERT( false, "Use clear() instead" );
    }

    void LinearAllocator::clear() noexcept
    {
        ba_AllocationsCount     = 0;
        ba_UsedMemory           = 0;

        m_CurrentPos            = ba_StartPtr;
    }

}


