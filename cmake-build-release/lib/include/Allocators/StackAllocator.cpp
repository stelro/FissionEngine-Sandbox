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

#include <cstdlib>
#include "StackAllocator.hpp"

namespace Fiene {

    StackAllocator::StackAllocator(size_t size, void* address)
        : BaseAllocator(size,address)
        , m_CurrentPtr(address)
    {

    }

    StackAllocator::~StackAllocator()
    {
        m_CurrentPtr = nullptr;
    }

    void *StackAllocator::allocate(size_t size, u8 alignment) noexcept
    {
        ASSERT(size != 0);
        ASSERT(alignment >= 1);
        ASSERT(alignment <= 128);
        ASSERT((alignment & (alignment - 1)) == 0); // Make sure that alignment is power of 2

        u8 adjustment = Ptr_Math::alignForwardAdjustmentWithHeader(m_CurrentPtr, alignment, sizeof(AlignmentHeader));

        F_ASSERT(((ba_UsedMemory + adjustment + size) < ba_Size), "StackAllocator : Not enough space");

        void *aligned_address = Ptr_Math::add(m_CurrentPtr,adjustment);

        //Keep track of adjustment made for this node
        //Needed for deallocation
        AlignmentHeader* header = (AlignmentHeader*)(Ptr_Math::subtract(aligned_address, sizeof(AlignmentHeader)));
        header->adjustment = adjustment;

        m_CurrentPtr = Ptr_Math::add(aligned_address, size);
        ba_UsedMemory += size + adjustment;
        ba_AllocationsCount++;

        return aligned_address;


    }

    void StackAllocator::deallocate(void *pMem) noexcept
    {
        ASSERT(pMem);

        //Get the header
        AlignmentHeader* header = (AlignmentHeader*)(Ptr_Math::subtract(pMem, sizeof(AlignmentHeader)));
        ba_UsedMemory -= (uptr)m_CurrentPtr - (uptr)pMem + header->adjustment;
        m_CurrentPtr = Ptr_Math::subtract(pMem, header->adjustment);

        ba_AllocationsCount--;
    }

}



