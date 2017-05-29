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
#include "BaseAllocator.hpp"

namespace Fiene {

    BaseAllocator::BaseAllocator(size_t size, void* start)
        : ba_Size(size)
        , ba_StartPtr(start)
        , ba_UsedMemory(0)
        , ba_AllocationsCount(0)
    {

    }

    BaseAllocator::~BaseAllocator()
    {
        if (ba_StartPtr) {
            ba_StartPtr = nullptr;
        }

        ba_Size = 0;
        ba_AllocationsCount = 0;
        ba_UsedMemory = 0;
    }

}


