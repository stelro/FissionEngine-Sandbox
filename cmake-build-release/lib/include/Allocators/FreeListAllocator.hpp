/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  **FreeList Allocator , Original Author Tiago Costa, 2014
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

#ifndef PROJECT_FREELISTALLOCATOR_HPP
#define PROJECT_FREELISTALLOCATOR_HPP

//Engine Internal
#include "BaseAllocator.hpp"
#include "PointerMath.hpp"

namespace Fiene {

    class FreeListAllocator : public BaseAllocator {
    public:
                            FreeListAllocator(size_t size, void* start);
                            ~FreeListAllocator();

        void*               allocate(size_t size, u8 alignment) noexcept override;
        void                deallocate(void* p) noexcept override;

    private:

        struct AllocationHeader {
            size_t size;
            u8     adjustment;
        };

        struct FreeBlock {
            size_t     size;
            FreeBlock* next;
        };

        F_DISABLE_COPY(FreeListAllocator);
        F_DISABLE_MOVE(FreeListAllocator);

        FreeBlock*          m_FreeBlocks;
    };

    FIENE_FORCE_INLINE
    FreeListAllocator* newFreeListAllocator(size_t size, BaseAllocator& allocator)
    {
        void* p = allocator.allocate(size+sizeof(FreeListAllocator), __alignof(FreeListAllocator));
        return new (p) FreeListAllocator(size, Ptr_Math::add(p, sizeof(FreeListAllocator)));
    }

    FIENE_FORCE_INLINE
    void deleteFreeListAllocator(FreeListAllocator& freeListAllocator, BaseAllocator& allocator)
    {
        freeListAllocator.~FreeListAllocator();

        allocator.deallocate(&freeListAllocator);
    }

}


#endif //PROJECT_FREELISTALLOCATOR_HPP
