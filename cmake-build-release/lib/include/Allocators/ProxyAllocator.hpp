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
#ifndef PROJECT_PROXYALLOCATOR_HPP
#define PROJECT_PROXYALLOCATOR_HPP

//Engine Internal
#include "BaseAllocator.hpp"
#include "PointerMath.hpp"

namespace Fiene {

    class ProxyAllocator : public BaseAllocator {
    public:
                                            ProxyAllocator(BaseAllocator& allocator);
                                            ~ProxyAllocator();

        void*                               allocate(size_t size, u8 alignment) noexcept override;
        void                                deallocate(void* p) noexcept override;

    private:
                                            F_DISABLE_COPY(ProxyAllocator);
                                            F_DISABLE_MOVE(ProxyAllocator);
        BaseAllocator&                      m_Allocator;
    };

    FIENE_FORCE_INLINE
    ProxyAllocator* newProxyAllocator(BaseAllocator& allocator)
    {
        void* p = allocator.allocate(sizeof(ProxyAllocator), __alignof(ProxyAllocator));
        return new (p) ProxyAllocator(allocator);
    }

    FIENE_FORCE_INLINE
    void deleteProxyAllocator(ProxyAllocator& proxyAllocator, BaseAllocator& allocator)
    {
        proxyAllocator.~ProxyAllocator();

        allocator.deallocate(&proxyAllocator);
    }

}


#endif //PROJECT_PROXYALLOCATOR_HPP
