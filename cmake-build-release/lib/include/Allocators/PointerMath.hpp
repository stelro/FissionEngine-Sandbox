/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  **Pointer Math used for Allocators, Original Author Tiago Costa, 2014
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

#ifndef PROJECT_POINTERMATH_HPP
#define PROJECT_POINTERMATH_HPP

//Engine Internal
#include "Core/Fiene.h"

//C++ Includes
#include <cstddef>

namespace Fiene {
    namespace Ptr_Math {

        void*       alignForward(void* address, u8 alignment);
        const void* alignForward(const void* address, u8 alignment);

        void*       alignBackward(void* address, u8 alignment);
        const void* alignBackward(const void* address, u8 alignment);

        u8          alignForwardAdjustment(const void* address, u8 alignment);
        u8          alignForwardAdjustmentWithHeader(const void* address, u8 alignment, u8 headerSize);

        u8          alignBackwardAdjustment(const void* address, u8 alignment);

        void*       add(void* p, size_t x);
        const void* add(const void* p, size_t x);

        void*       subtract(void* p, size_t x);
        const void* subtract(const void* p, size_t x);

        FIENE_FORCE_INLINE
        void* alignForward(void* address, u8 alignment)
        {
            return (void*)( ( reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment-1) ) & static_cast<uptr>(~(alignment-1)) );
        }

        FIENE_FORCE_INLINE
        const void* alignForward(const void* address, u8 alignment)
        {
            return (void*)( ( reinterpret_cast<uptr>(address) + static_cast<uptr>(alignment-1) ) & static_cast<uptr>(~(alignment-1)) );
        }

        FIENE_FORCE_INLINE
        void* alignBackward(void* address, u8 alignment)
        {
            return (void*)( reinterpret_cast<uptr>(address) & static_cast<uptr>(~(alignment-1)) );
        }

        FIENE_FORCE_INLINE
        const void* alignBackward(const void* address, u8 alignment)
        {
            return (void*)( reinterpret_cast<uptr>(address) & static_cast<uptr>(~(alignment-1)) );
        }

        FIENE_FORCE_INLINE
        u8 alignForwardAdjustment(const void* address, u8 alignment)
        {
            u8 adjustment =  alignment - ( reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment-1) );

            if(adjustment == alignment)
                return 0; //already aligned

            return adjustment;
        }

        FIENE_FORCE_INLINE
        u8 alignForwardAdjustmentWithHeader(const void* address, u8 alignment, u8 headerSize)
        {
            u8 adjustment =  alignForwardAdjustment(address, alignment);

            u8 neededSpace = headerSize;

            if(adjustment < neededSpace)
            {
                neededSpace -= adjustment;

                //Increase adjustment to fit header
                adjustment += alignment * (neededSpace / alignment);

                if(neededSpace % alignment > 0)
                    adjustment += alignment;
            }

            return adjustment;
        }

        FIENE_FORCE_INLINE
        u8 alignBackwardAdjustment(const void* address, u8 alignment)
        {
            u8 adjustment =  reinterpret_cast<uptr>(address) & static_cast<uptr>(alignment-1);

            if(adjustment == alignment)
                return 0; //already aligned

            return adjustment;
        }

        FIENE_FORCE_INLINE
        void* add(void* p, size_t x)
        {
            return (void*)( reinterpret_cast<uptr>(p) + x);
        }

        FIENE_FORCE_INLINE
        const void* add(const void* p, size_t x)
        {
            return (const void*)( reinterpret_cast<uptr>(p) + x);
        }

        FIENE_FORCE_INLINE
        void* subtract(void* p, size_t x)
        {
            return (void*)( reinterpret_cast<uptr>(p) - x);
        }

        FIENE_FORCE_INLINE
        const void* subtract(const void* p, size_t x)
        {
            return (const void*)( reinterpret_cast<uptr>(p) - x);
        }

    }
}

#endif //PROJECT_POINTERMATH_HPP
