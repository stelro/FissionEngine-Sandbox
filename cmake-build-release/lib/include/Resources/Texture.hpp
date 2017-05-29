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

#ifndef PROJECT_TEXTURE_HPP
#define PROJECT_TEXTURE_HPP

//Engine Internal
#include "Math/Vector.hpp"
#include "ResourceBase.h"
#include "Core/IOManager.hpp"
#include "Core/fglobals.h"
#include "2D/picoPNG.hpp"

//OpenGL Includes
#include <GL/glew.h>


namespace Fiene {

    class Texture : public ResourceBase {
    public:
        Texture(const std::string& filePath) :
               ResourceBase(filePath)
        {

            //Texture texture = {};
            std::vector<unsigned char> in;
            //Pixel Data
            std::vector<unsigned char> out;
            unsigned long width, height;
            GLuint id;

            if (!IOManager::readFileToBuffer(filePath, in)) {
                Fiene::errorLog("Faild to load PNG file to buffer\n");
                Exit(1);
            }

            int errorCode = decodePNG(out, width, height, &(in[0]), in.size());

            if ( errorCode != 0) {
                Fiene::errorLog("Decode PNG faild with error: %d", errorCode);
            }

            glGenTextures(1, &id);
            glBindTexture(GL_TEXTURE_2D, id);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(width),
                         static_cast<GLsizei>(height), 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);

            m_ID = id;
            m_Width = static_cast<int>(width);
            m_Height = static_cast<int>(height);
        }

        GLuint      id()    const   { return m_ID; }
        int         width() const   { return m_Width; }
        int         height() const  { return m_Height; }
        iVec2       size() const    { return iVec2(m_Width, m_Height); }

    private:
        GLuint      m_ID;
        int         m_Width;
        int         m_Height;

    };

}

#endif //PROJECT_TEXTURE_HPP
