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

#include "Engine.hpp"
#include "Allocators/BaseAllocator.hpp"
#include "Allocators/PointerMath.hpp"
#include "Allocators/StackAllocator.hpp"
#include "Allocators/FreeListAllocator.hpp"
#include "Allocators/ProxyAllocator.hpp"
#include "Allocators/LinearAllocator.hpp"
#include "Allocators/PoolAllocator.hpp"

//C++ Includes
#include <iostream>
#include <ctime>
#include <vector>

#define LINEAR_ALLOC 1
#define STACK_ALLOC 1
#define FREELIST_ALLOC 1
#define POOL_ALLOC 1

#define MAX_NUM_ALLOCS 100000

#define NUM_16B_ALLOCS 10000
#define NUM_256B_ALLOCS 1000
#define NUM_2MB_ALLOCS 50

#define MB2INBYTES  2097152 //2mb

#define MEM_SIZE 1048576000 //1GB

using namespace Fiene;
using std::cin;

int main()
{
    void* memory = malloc(MEM_SIZE);
    FreeListAllocator* freeListAllocator = new FreeListAllocator(MEM_SIZE, memory);
    ProxyAllocator* proxyAllocator = new ProxyAllocator(*freeListAllocator);

    LinearAllocator* linearAllocator = newLinearAllocator(MB2INBYTES, *freeListAllocator);
    StackAllocator* stackAllocator = newStackAllocator(MB2INBYTES, *freeListAllocator);


    int *a = (int*)linearAllocator->allocate(4,4);
    int *b = (int*)linearAllocator->allocate(4,4);

    int *c = (int*)stackAllocator->allocate(4,4);

    *c = 11;


    *a = 10;
    *b = 20;

    std::cout << "a: " << a << " - " << *a << std::endl;
    std::cout << "b: " << b << " - " << *b << std::endl;
    std::cout << "c: " << c << " - " << *c << std::endl;

    std::cout << linearAllocator->getSize() << std::endl;
    std::cout << linearAllocator->getSize() << std::endl;
    std::cout << freeListAllocator->getAllocations() << std::endl;

    return 0;
}