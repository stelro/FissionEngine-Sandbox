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

#ifndef PROJECT_POOLALLOCATOR_HPP
#define PROJECT_POOLALLOCATOR_HPP

//Engine Internal
#include "BaseAllocator.hpp"
#include "PointerMath.hpp"

namespace Fiene {


    class PoolAllocator : public BaseAllocator {
    public:
                            PoolAllocator(size_t objectSize, u8 objectAlignment, size_t size, void* mem);
                            ~PoolAllocator();

        void*               allocate(size_t size, u8 alignment) noexcept override;
        void                deallocate(void* p) noexcept override;

    private:
                            F_DISABLE_COPY(PoolAllocator);
                            F_DISABLE_MOVE(PoolAllocator);

        size_t              m_ObjectSize;
        u8                  m_ObjectAlignment;

        void**              m_FreeList;
    };

    FIENE_FORCE_INLINE
    PoolAllocator* newPoolAllocator(size_t objectSize, u8 objectAlignment, size_t size, BaseAllocator& allocator)
    {
        void* p = allocator.allocate(size+sizeof(PoolAllocator), __alignof(PoolAllocator));
        return new (p) PoolAllocator(objectSize, objectAlignment, size, Ptr_Math::add(p, sizeof(PoolAllocator)));
    }

    FIENE_FORCE_INLINE
    void deletePoolAllocator(PoolAllocator& poolAllocator, BaseAllocator& allocator)
    {
        poolAllocator.~PoolAllocator();

        allocator.deallocate(&poolAllocator);
    }

}


#endif //PROJECT_POOLALLOCATOR_HPP
