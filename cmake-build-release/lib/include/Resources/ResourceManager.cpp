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


//Engine Internal
#include "ResourceManager.hpp"
#include "ResourceBase.h"

namespace Fiene {

    ResourceManager::ResourceManager(BaseAllocator& Allocator)
            : bm_Allocator(Allocator)
    {

    }


    ResourceManager::~ResourceManager()
    {
        cacheRemoveAll();
    }

    ResourceBase* ResourceManager::cacheLookup(const std::string &fileName) {

        auto iterator = bm_CacheContainer.find(fileName);
        if (iterator != bm_CacheContainer.end()) {
            iterator->second->ref();
            return iterator->second;
        }

        return nullptr;
    }


    void ResourceManager::cacheStore(const std::string &filePath, ResourceBase* resource) {
        bm_CacheContainer.insert( std::pair<std::string, ResourceBase*>(filePath, resource));
    }


    void ResourceManager::cacheRemove(const std::string& fileName)
    {
        auto iterator = bm_CacheContainer.find(fileName);
        if (iterator != bm_CacheContainer.end()) {
            bm_Allocator.deallocate(iterator->second);
            bm_CacheContainer.erase(iterator);
        }
    }


    void ResourceManager::cacheRemoveAll()
    {
        auto iterator = bm_CacheContainer.begin();
        while (iterator != bm_CacheContainer.end()) {
            cacheRemove(iterator->first);
            iterator = bm_CacheContainer.begin();
        }
    }


    size_t ResourceManager::cacheAllocsCounter() const
    {
        return bm_CacheContainer.size();
    }


    bool ResourceManager::unload(const std::string &filePath) {

        F_ASSERT(!(filePath.empty()), "FilePath Shouldn't be emtpy!");

        auto it = bm_CacheContainer.find(filePath);

        if (it != bm_CacheContainer.end()) {

            it->second->unref();
            if (it->second->getCounter() == 0) {
                bm_Allocator.deallocate(it->second);
                bm_CacheContainer.erase(it);
            }

            return true;

        }

        return false;

    }

    size_t ResourceManager::size() const
    {
        return cacheAllocsCounter();
    }

    std::vector<std::string> ResourceManager::getCacheNames()
    {
        std::vector<std::string> tmp;
        for (auto const &i : bm_CacheContainer) {
            tmp.push_back(i.first);
        }

        return tmp;
    }


}



