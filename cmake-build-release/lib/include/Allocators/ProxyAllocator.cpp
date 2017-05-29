/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  **Proxy Allocator , Original Author Tiago Costa, 2014
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

#include <cstdlib>
#include "ProxyAllocator.hpp"

namespace Fiene {

    ProxyAllocator::ProxyAllocator(BaseAllocator& allocator)
                : BaseAllocator(allocator.getSize(), allocator.getStart())
                , m_Allocator(allocator)
    {

    }

    ProxyAllocator::~ProxyAllocator()
    {

    }

    void* ProxyAllocator::allocate(size_t size, u8 alignment) noexcept
    {
        ASSERT(size != 0);
        ba_AllocationsCount++;

        size_t mem = m_Allocator.getUsedMem();

        void* p = m_Allocator.allocate(size, alignment);

        ba_UsedMemory += m_Allocator.getUsedMem() - mem;

        return p;
    }

    void ProxyAllocator::deallocate(void* p) noexcept
    {
        ba_AllocationsCount--;

        size_t mem = m_Allocator.getUsedMem();

        m_Allocator.deallocate(p);

        ba_UsedMemory -= mem - m_Allocator.getUsedMem();
    }

}


