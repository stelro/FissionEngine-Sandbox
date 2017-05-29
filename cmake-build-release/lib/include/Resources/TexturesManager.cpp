//
// Created by stel on 3/4/2017.
//

#include "TexturesManager.hpp"
#include "Texture.hpp"

namespace Fiene {

    TexturesManager::TexturesManager(BaseAllocator& allocator)
        : ResourceManager(allocator)
    {

    }

    TexturesManager::~TexturesManager()
    {
        //Empty
    }

    bool TexturesManager::load(const std::string &filePath)
    {
        F_ASSERT(!(filePath.empty()), "FilePath shouldn't be empty!");
        //todo: trim and lower the filepath string

        auto it = bm_CacheContainer.find(filePath);
        if (it != bm_CacheContainer.end()) {
            return true;
        }

        Texture* resource = allocateNew(bm_Allocator, Texture(filePath)); //new T(filePath);
        resource->ref();
        cacheStore(filePath, resource);

        return true;
    }

    bool TexturesManager::unload(const std::string &filePath)
    {
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

    Texture *TexturesManager::getTexture(const std::string &filePath)
    {
        return static_cast<Texture*>(cacheLookup(filePath));
    }

    GLuint TexturesManager::getTextureID(const std::string &filePath)
    {
        auto it = bm_CacheContainer.find(filePath);
        if (it != bm_CacheContainer.end()) {
            return static_cast<const Texture*>(it->second)->id();
        }

        return 0;
    }

}


