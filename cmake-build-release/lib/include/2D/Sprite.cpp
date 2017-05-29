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

#include <cstddef>

#include "Resources/Texture.hpp"
#include "Sprite.hpp"
#include "Utils/Utils.hpp"

namespace Fiene {

    Sprite::Sprite()
        : m_Texture(nullptr)
        , m_VboID(0)
    {

    }

    Sprite::~Sprite()
    {
        if (m_VboID != 0) {
            glDeleteBuffers(1, &m_VboID);
        }
    }

    void Sprite::render()
    {
        glBindTexture(GL_TEXTURE_2D, m_Texture->id());

        //bind the buffer object
        glBindBuffer(GL_ARRAY_BUFFER, m_VboID);

        //Tell opengl what attribute arrays we need
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        //This is the position attribute pointer
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        //This is the color attribute pointer
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        //This is the UV attribute pointer
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

        //Draw the 6 vertices to the screen
        glDrawArrays(GL_TRIANGLES, 0, 6);

        //Disable the vertex attrib arrays. This is not optional.
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        //Unbind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Sprite::create(const float x, const float y, const float width,
                        const float height,Texture *texture)
    {
        //Set up our private vars
        m_X = x;
        m_Y = y;
        m_Width = width;
        m_Height = height;

        m_Texture = texture;


        //Generate the buffer if it hasn't already been generated
        if (m_VboID == 0) {
            glGenBuffers(1, &m_VboID);
        }

        //This array will hold our vertex data.
        //We need 6 vertices, and each vertex has 2
        //floats for X and Y
        Vertex vertexData[6];

        //First Triangle
        vertexData[0].setPosition(x + width, y + height);
        vertexData[0].setUV(1.0f, 1.0f);

        vertexData[1].setPosition(x, y + height);
        vertexData[1].setUV(0.0f, 1.0f);

        vertexData[2].setPosition(x, y);
        vertexData[2].setUV(0.0f, 0.0f);

        //Second Triangle
        vertexData[3].setPosition(x, y);
        vertexData[3].setUV(0.0f, 0.0f);

        vertexData[4].setPosition(x + width, y);
        vertexData[4].setUV(1.0f, 0.0f);

        vertexData[5].setPosition(x + width, y + height);
        vertexData[5].setUV(1.0f, 1.0f);

        //Set all vertex colors to magenta
        for (int i = 0; i < 6; i++) {
            vertexData[i].setColor(255, 255, 255, 255);
        }


        //Tell opengl to bind our vertex buffer object
        glBindBuffer(GL_ARRAY_BUFFER, m_VboID);
        //Upload the data to the GPU
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

        //Unbind the buffer (optional)
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}



