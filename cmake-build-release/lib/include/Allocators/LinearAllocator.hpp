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

#ifndef PROJECT_LINEARALLOCATOR_HPP
#define PROJECT_LINEARALLOCATOR_HPP

//Engine Internal
#include "BaseAllocator.hpp"
#include "PointerMath.hpp"

namespace Fiene {

    class LinearAllocator : public BaseAllocator {
    public:
                                    LinearAllocator(size_t size, void* start);
                                    ~LinearAllocator();

        void*                       allocate(size_t size, u8 alignment) noexcept override;
        void                        deallocate(void* p) noexcept override;

        void                        clear() noexcept ;

    private:
                                    F_DISABLE_COPY(LinearAllocator);
                                    F_DISABLE_MOVE(LinearAllocator);

        void*                       m_CurrentPos;
    };

    FIENE_FORCE_INLINE
    LinearAllocator* newLinearAllocator(size_t size, BaseAllocator& allocator)
    {
        void* p = allocator.allocate(size+sizeof(LinearAllocator), __alignof(LinearAllocator));
        return new (p) LinearAllocator(size, Ptr_Math::add(p, sizeof(LinearAllocator)));
    }

    FIENE_FORCE_INLINE
    void deleteLinearAllocator(LinearAllocator& linearAllocator, BaseAllocator& allocator)
    {
        linearAllocator.~LinearAllocator();

        allocator.deallocate(&linearAllocator);
    }

}


#endif //PROJECT_LINEARALLOCATOR_HPP
