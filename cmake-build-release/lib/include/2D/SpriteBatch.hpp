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

#ifndef PROJECT_SPRITEBATCH_HPP
#define PROJECT_SPRITEBATCH_HPP

//Engine Internal
#include "Utils/Utils.hpp"
#include "Math/Vector.hpp"

//OpenGL Includes
#include <GL/glew.h>
#include <glm/glm.hpp>

//C++ Includes
#include <vector>
#include <algorithm>


namespace Fiene {

    class Tile;
    class Cell;

    enum class GlyphSortType {
        NONE,
        FRONT_TO_BACK,
        BACK_TO_FRONT,
        TEXTURE_SORT
    };

    class Glyph {

    public:

        Glyph() { }

        Glyph(const Vec4& destRect, const Vec4& uvRect, GLuint t_texture,
              const float t_depth, const Color& color);

        Glyph(const Vec4& destRect, const Vec4& uvRect, GLuint t_texture,
              const float t_depth, const Color& color, const float angle);

        GLuint              texture;
        float               depth;

        Vertex              topLeft;
        Vertex              bottomLeft;
        Vertex              topRight;
        Vertex              bottomRight;

    private:

        Vec2 rotatePoint(Vec2, const float angle);
    };

    class Batch {
    public:

        Batch(const GLuint t_offset, const GLuint t_numVerticies, const GLuint t_texture)
            : offset(t_offset)
            , numVerticies(t_numVerticies)
            , texture(t_texture) { }

        GLuint              offset;
        GLuint              numVerticies;
        GLuint              texture;
    };

    class SpriteBatch {

    public:

                                    SpriteBatch();
                                    ~SpriteBatch();

        void                        startUp();
        void                        begin(const GlyphSortType sortType = GlyphSortType::TEXTURE_SORT);
        void                        end();

        void                        append(const Vec4& destRect, const GLuint texture);

        void                        append(const Vec4& destRect, const GLuint texture, const float angle);

        void                        append(const Vec4& destRect, const Vec4& uvRect, const GLuint texture,
                                        const float depth, const Color& color);

        void                        append(const Vec4& destRect, const Vec4& uvRect,
                                        const GLuint texture, const float depth, const Color& color, const float angle);

        void                        append(const Vec4& destRect, const Vec4& uvRect,
                                        const GLuint texture, const float depth, const Color& color,const Vec2& dir);

        void                        append(const Cell& cell);


        void                        render();

        void                        terminate();

    private:

        void                        createRenderBatches();
        void                        createVertexArray();
        void                        sortGlyphs();

        //This is the actual glyphs
        std::vector<Glyph >         m_Glyphs;
        //Glyph pointers is for sorting
        std::vector<Glyph* >        m_GlyphPointers;
        std::vector<Batch>          m_Batches;
        //Vertex Buffer Object
        GLuint                      m_Vbo;
        //Vertex Array Object
        GLuint                      m_Vao;
        GlyphSortType               m_SortType;

    };

}


#endif //PROJECT_SPRITEBATCH_HPP
