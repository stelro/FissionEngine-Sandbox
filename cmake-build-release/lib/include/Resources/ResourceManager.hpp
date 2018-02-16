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

#ifndef PROJECT_RESOURCEMANAGER_HPP
#define PROJECT_RESOURCEMANAGER_HPP

//Engine Internal
#include "Core/Core.h"
#include "Allocators/BaseAllocator.hpp"

//C++ Includes
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

namespace Fiene {

    class BaseAllocator;
    class ResourceBase;

    class ResourceManager {
    public:
                                                            ResourceManager(BaseAllocator& Allocator);
        virtual                                             ~ResourceManager();
        virtual bool                                        load(const std::string& filePath) = 0;
        virtual bool                                        unload(const std::string& filePath) = 0;

        size_t                                              size() const;

        std::vector<std::string>                            getCacheNames();

    protected:
        ResourceBase*                                       cacheLookup(const std::string& fileName);
        void                                                cacheStore(const std::string& filePath,ResourceBase* resource);
        void                                                cacheRemove(const std::string& fileName);
        void                                                cacheRemoveAll();
        size_t                                              cacheAllocsCounter() const;

        std::unordered_map<std::string, ResourceBase* >     bm_CacheContainer;
        BaseAllocator&                                      bm_Allocator;
        size_t                                              bm_AllocSize;
    };

}


#endif //PROJECT_RESOURCEMANAGER_HPP
