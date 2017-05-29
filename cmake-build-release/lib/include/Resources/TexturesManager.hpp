//
// Created by stel on 3/4/2017.
//

#ifndef PROJECT_TEXTURESMANAGER_HPP
#define PROJECT_TEXTURESMANAGER_HPP

//Engine Internal
#include <GL/glew.h>
#include "ResourceManager.hpp"

namespace Fiene {

    class BaseAllocator;
    class Texture;

    class TexturesManager : public ResourceManager {
    public:
                                                TexturesManager(BaseAllocator& allocator);
                                                ~TexturesManager();

                                                F_DISABLE_COPY(TexturesManager);
                                                F_DISABLE_MOVE(TexturesManager);

        bool                                    load(const std::string& filePath) override ;
        bool                                    unload(const std::string& filePath) override ;

        Texture*                                getTexture(const std::string& filePath);
        GLuint                                  getTextureID(const std::string& filePath);

    };

}


#endif //PROJECT_TEXTURESMANAGER_HPP
