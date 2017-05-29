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

#ifndef PROJECT_STACKALLOCATOR_HPP
#define PROJECT_STACKALLOCATOR_HPP

//Engine Internal
#include "BaseAllocator.hpp"
#include "PointerMath.hpp"

namespace Fiene {

    struct AlignmentHeader;

    class StackAllocator : public BaseAllocator {
    public:
                            StackAllocator(size_t size, void* address);
                            ~StackAllocator();


        void*               allocate(size_t size, u8 alignment) noexcept override ;
        void                deallocate(void* pMem) noexcept override ;


    private:
        struct AlignmentHeader {
            u8 adjustment;
        };

        F_DISABLE_COPY(StackAllocator);
        F_DISABLE_MOVE(StackAllocator);

        void*               m_CurrentPtr;
    };

    FIENE_FORCE_INLINE
    StackAllocator* newStackAllocator(size_t size, BaseAllocator& allocator)
    {
        void* p = allocator.allocate(size+sizeof(StackAllocator), __alignof(StackAllocator));
        return new (p) StackAllocator(size, Ptr_Math::add(p, sizeof(StackAllocator)));
    }

    FIENE_FORCE_INLINE
    void deleteStackAllocator(StackAllocator& stackAllocator, BaseAllocator& allocator)
    {
        stackAllocator.~StackAllocator();
        allocator.deallocate(&stackAllocator);
    }

}


#endif //PROJECT_STACKALLOCATOR_HPP
