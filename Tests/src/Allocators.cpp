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

    EngineCore::initialize();

    void* pMem = malloc(MEM_SIZE);

    clock_t Start, Stop;
    double Seconds;

    void* allocs[MAX_NUM_ALLOCS];


#if LINEAR_ALLOC
    /////////////////////////////////////////////////////////////////
    //Linear
    /////////////////////////////////////////////////////////////////

    LinearAllocator* pLinearAlloc = new LinearAllocator(MEM_SIZE, pMem);

    printf("----------------\n");
    printf("Malloc vs Linear\n");
    printf("----------------\n");

    Start = clock();

    int k = 0;

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[k+i] = malloc(16);

    k += NUM_16B_ALLOCS;

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[k+i] = malloc(256);

    k += NUM_256B_ALLOCS;

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[k+i] = malloc(MB2INBYTES);

    k += NUM_2MB_ALLOCS;

    for(int i = 0; i < k; i++)
        free(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Malloc: " << Seconds << " sec." << std::endl;

    Start = clock();

    k = 0;

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[k+i] = pLinearAlloc->allocate(16, 8);

    k += NUM_16B_ALLOCS;

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[k+i] = pLinearAlloc->allocate(256, 8);

    k += NUM_256B_ALLOCS;

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[k+i] = pLinearAlloc->allocate(MB2INBYTES, 8);

    k += NUM_2MB_ALLOCS;

    pLinearAlloc->clear();

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Linear: " << Seconds << " sec." << std::endl;

    pLinearAlloc->clear();

    delete pLinearAlloc;

#endif

#if STACK_ALLOC

    /////////////////////////////////////////////////////////////////
    //Stack
    /////////////////////////////////////////////////////////////////

    StackAllocator* pStackAlloc   = new StackAllocator(MEM_SIZE, pMem);

    printf("----------------\n");
    printf("Malloc vs Stack\n");
    printf("----------------\n");

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = malloc(16);

    for(int i = NUM_16B_ALLOCS-1; i >= 0; i--)
        free(allocs[i]);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[i] = malloc(256);

    for(int i = NUM_256B_ALLOCS-1; i >= 0; i--)
        free(allocs[i]);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[i] = malloc(MB2INBYTES);

    for(int i = NUM_2MB_ALLOCS-1; i >= 0; i--)
        free(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Malloc: " << Seconds << " sec." << std::endl;

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = pStackAlloc->allocate(16, 8);

    for(int i = NUM_16B_ALLOCS-1; i >= 0; i--)
        pStackAlloc->deallocate(allocs[i]);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[i] = pStackAlloc->allocate(256, 8);

    for(int i = NUM_256B_ALLOCS-1; i >= 0; i--)
        pStackAlloc->deallocate(allocs[i]);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[i] = pStackAlloc->allocate(MB2INBYTES, 8);

    for(int i = NUM_2MB_ALLOCS-1; i >= 0; i--)
        pStackAlloc->deallocate(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Stack: " << Seconds << " sec." << std::endl;

    delete pStackAlloc;

#endif

#if FREELIST_ALLOC

    /////////////////////////////////////////////////////////////////
    //FreeList
    /////////////////////////////////////////////////////////////////

    FreeListAllocator* pFreeListAlloc = new FreeListAllocator(MEM_SIZE, pMem);

    printf("------------------\n");
    printf("Malloc vs FreeList\n");
    printf("------------------\n");

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = malloc(16);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        free(allocs[i]);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[i] = malloc(256);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        free(allocs[i]);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[i] = malloc(MB2INBYTES);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        free(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Malloc: " << Seconds << " sec." << std::endl;

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = pFreeListAlloc->allocate(16, 8);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        pFreeListAlloc->deallocate(allocs[i]);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        allocs[i] = pFreeListAlloc->allocate(256, 8);

    for(int i = 0; i < NUM_256B_ALLOCS; i++)
        pFreeListAlloc->deallocate(allocs[i]);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        allocs[i] = pFreeListAlloc->allocate(MB2INBYTES, 8);

    for(int i = 0; i < NUM_2MB_ALLOCS; i++)
        pFreeListAlloc->deallocate(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Free List: " << Seconds << " sec." << std::endl;

    delete pFreeListAlloc;

#endif

#if POOL_ALLOC

    /////////////////////////////////////////////////////////////////
    //Pool
    /////////////////////////////////////////////////////////////////

    PoolAllocator* pPoolAlloc = new PoolAllocator(16, 8, MEM_SIZE, pMem);

    printf("------------------\n");
    printf("Malloc vs Pool\n");
    printf("------------------\n");

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = malloc(16);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        free(allocs[i]);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = malloc(16);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        free(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Malloc: " << Seconds << " sec." << std::endl;

    Start = clock();

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = pPoolAlloc->allocate(16, 8);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        pPoolAlloc->deallocate(allocs[i]);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        allocs[i] = pPoolAlloc->allocate(16, 8);

    for(int i = 0; i < NUM_16B_ALLOCS; i++)
        pPoolAlloc->deallocate(allocs[i]);

    Stop = clock();

    Seconds = ( (double) ( Stop - Start ) / CLOCKS_PER_SEC );

    std::cout << "Pool: " << Seconds << " sec." << std::endl;

    delete pPoolAlloc;

#endif

    free(pMem);

    ///////////////////////////////////
    // TEST FREE LIST ALLOCATOR
    ///////////////////////////////////

    char* bigbuf = (char*)malloc(10000);

    // remember our allocs
    std::vector<void*> _allocs;

    FreeListAllocator allocator(10000, bigbuf);

    // lots of iterations
    for(int i = 0; i < 1000; i++)
    {
        // allocate blocks till the allocator is full
        for(;;)
        {
            size_t allocSize = rand()%500+1;
            u8 alignment = rand()%2 == 0 ? 4 : 2;

            //printf("%d %d\n", (int) allocSize, alignment);

            void* alloc = allocator.allocate(allocSize, alignment);

            if (!alloc)
                break;

            _allocs.push_back(alloc);
        }

        if(i%2 == 0)
        {
            // randomly deallocate ~50% of blocks (forward)
            for(size_t j = 0; j < _allocs.size(); j++)
            {
                if ((rand() % 2) == 0 && _allocs[j] != nullptr)
                {
                    allocator.deallocate(_allocs[j]);
                    _allocs[j] = nullptr;
                }
            }
        } else
        {
            // randomly deallocate ~50% of blocks (backwards)
            for(int j = _allocs.size()-1; j >= 0; j--)
            {
                if ((rand() % 2) == 0 && _allocs[j] != nullptr)
                {
                    allocator.deallocate(_allocs[j]);
                    _allocs[j] = nullptr;
                }
            }
        }
    }

    for(size_t i = 0; i < _allocs.size(); i++)
    {
        if(_allocs[i] != nullptr)
        {
            allocator.deallocate(_allocs[i]);
            _allocs[i] = nullptr;
        }
    }

    printf("%d == %d\n", 0, (int) allocator.getUsedMem());


    return 0;
}