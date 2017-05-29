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

#include "FreeListAllocator.hpp"


namespace Fiene {

    FreeListAllocator::FreeListAllocator(size_t size, void* start)
              : BaseAllocator(size, start)
              , m_FreeBlocks((FreeBlock*)start)
    {
        ASSERT(size > sizeof(FreeBlock));

        m_FreeBlocks->size  = size;
        m_FreeBlocks->next = nullptr;
    }

    FreeListAllocator::~FreeListAllocator()
    {
        m_FreeBlocks        = nullptr;
    }

    void* FreeListAllocator::allocate(size_t size, u8 alignment) noexcept
    {

        ASSERT(size != 0);
        ASSERT(alignment >= 1);
        ASSERT(alignment <= 128);
        ASSERT((alignment & (alignment - 1)) == 0); // Make sure that alignment is power of 2

        FreeBlock* prev_free_block  = nullptr;
        FreeBlock* free_block       = m_FreeBlocks;

        while(free_block != nullptr) {
            //Calculate adjustment needed to keep object correctly aligned
            u8 adjustment = Ptr_Math::alignForwardAdjustmentWithHeader(free_block, alignment, sizeof(AllocationHeader));

            size_t total_size = size + adjustment;

            //If allocation doesn't fit in this FreeBlock, try the next
            if(free_block->size < total_size) {
                prev_free_block = free_block;
                free_block = free_block->next;
                continue;
            }

            F_ASSERT(sizeof(AllocationHeader) >= sizeof(FreeBlock), "sizeof(AllocationHeader) < sizeof(FreeBlock)");

            //If allocations in the remaining memory will be impossible
            if(free_block->size - total_size <= sizeof(AllocationHeader)) {
                //Increase allocation size instead of creating a new FreeBlock
                total_size = free_block->size;

                if(prev_free_block != nullptr)
                    prev_free_block->next = free_block->next;
                else
                    m_FreeBlocks = free_block->next;
            }

            else {
                //Else create a new FreeBlock containing remaining memory
                FreeBlock* next_block = (FreeBlock*)( Ptr_Math::add(free_block, total_size) );
                next_block->size = free_block->size - total_size;
                next_block->next = free_block->next;

                if(prev_free_block != nullptr)
                    prev_free_block->next = next_block;
                else
                    m_FreeBlocks = next_block;
            }

            uptr aligned_address = (uptr)free_block + adjustment;

            AllocationHeader* header = (AllocationHeader*)(aligned_address - sizeof(AllocationHeader));
            header->size             = total_size;
            header->adjustment       = adjustment;

            ba_UsedMemory += total_size;
            ba_AllocationsCount++;

            ASSERT(Ptr_Math::alignForwardAdjustment((void*)aligned_address, alignment) == 0);

            return (void*)aligned_address;
        }

        //ASSERT(false && "Couldn't find free block large enough!");

        return nullptr;
    }

    void FreeListAllocator::deallocate(void* p) noexcept
    {
        ASSERT(p != nullptr);

        AllocationHeader* header = (AllocationHeader*)Ptr_Math::subtract(p, sizeof(AllocationHeader));

        uptr   block_start = reinterpret_cast<uptr>(p) - header->adjustment;
        size_t block_size  = header->size;
        uptr   block_end   = block_start + block_size;

        FreeBlock* prev_free_block = nullptr;
        FreeBlock* free_block = m_FreeBlocks;

        while(free_block != nullptr) {
            if( (uptr) free_block >= block_end )
                break;

            prev_free_block = free_block;
            free_block = free_block->next;
        }

        if(prev_free_block == nullptr) {
            prev_free_block = (FreeBlock*) block_start;
            prev_free_block->size = block_size;
            prev_free_block->next = m_FreeBlocks;

            m_FreeBlocks = prev_free_block;
        } else if((uptr) prev_free_block + prev_free_block->size == block_start) {
            prev_free_block->size += block_size;
        } else  {
            FreeBlock* temp = (FreeBlock*) block_start;
            temp->size = block_size;
            temp->next = prev_free_block->next;
            prev_free_block->next = temp;

            prev_free_block = temp;
        }

        if( free_block != nullptr && (uptr) free_block == block_end) {
            prev_free_block->size += free_block->size;
            prev_free_block->next = free_block->next;
        }

        ba_AllocationsCount--;
        ba_UsedMemory -= block_size;
    }
}


