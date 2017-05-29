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
#include "SpriteBatch.hpp"
#include "Map/Layer.hpp"
#include "Map/Tile.hpp"

//C++ Includes
#include <algorithm>


namespace Fiene {

    SpriteBatch::SpriteBatch()
    {
        //Empty
    }

    SpriteBatch::~SpriteBatch()
    {
        //Empty
    }

    void SpriteBatch::startUp()
    {
        m_Vbo = 0;
        m_Vao = 0;
        createVertexArray();
    }

    void SpriteBatch::begin(GlyphSortType sortType)
    {
        m_SortType = sortType;
        m_Batches.clear();
        m_Glyphs.clear();
    }

    void SpriteBatch::end()
    {
        // Set up all pointers for fast sorting
        m_GlyphPointers.resize(m_Glyphs.size());

        for (size_t i = 0; i < m_Glyphs.size(); i++) {
            m_GlyphPointers[i] = &m_Glyphs[i];
        }

        sortGlyphs();
        createRenderBatches();
    }

    void SpriteBatch::append(const Vec4 &destRect, const GLuint texture)
    {
        Vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
        Color color(255,255,255,255);
        float depth = 0.0f;
        m_Glyphs.emplace_back(destRect, uvRect, texture,depth,color);
    }

    void SpriteBatch::append(const Vec4 &destRect, const GLuint texture, const float angle)
    {
        Vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
        Color color(255,255,255,255);
        float depth = 0.0f;
        m_Glyphs.emplace_back(destRect, uvRect, texture,depth,color, angle);
    }

    void SpriteBatch::append(const Vec4 &destRect, const Vec4 &uvRect, const GLuint texture, const float depth,
                           const Color &color)
    {
        m_Glyphs.emplace_back(destRect, uvRect, texture, depth, color);
    }

    void SpriteBatch::append(const Vec4 &destRect, const Vec4 &uvRect, const GLuint texture, const float depth,
                           const Color &color, const float angle)
    {
        m_Glyphs.emplace_back(destRect, uvRect, texture, depth, color, angle);
    }

    void SpriteBatch::append(const Vec4 &destRect, const Vec4 &uvRect, const GLuint texture, const float depth,
                           const Color &color,const Vec2 &dir)
    {
        const Vec2 right(1.0f, 0.0f);
        float angle = static_cast<float>(acos(dotProduct(right, dir)));
        if (dir.y < 0)
            angle = -angle;

        m_Glyphs.emplace_back(destRect, uvRect, texture, depth, color, angle);
    }

    void SpriteBatch::append(const Cell &cell)
    {

        // meant to be used with tiles
       // m_Glyphs.emplace_back(cell.pos, cell.tile->uv, cell.tile->textureID, 0.0f, cell.color);
    }


    void SpriteBatch::render()
    {
        glBindVertexArray(m_Vao);

        for (size_t i = 0; i < m_Batches.size(); ++i) {
            glBindTexture(GL_TEXTURE_2D, m_Batches[i].texture);
            glDrawArrays(GL_TRIANGLES, m_Batches[i].offset, m_Batches[i].numVerticies);
        }

        glBindVertexArray(0);
    }

    void SpriteBatch::createRenderBatches()
    {
        if (m_GlyphPointers.empty()) {
            return;
        }


        //Store all verticies that need to be uploaded
        std::vector<Vertex> verticies;

        verticies.resize(m_GlyphPointers.size() * 6);

        int vertex_offset = 0; //Current offset
        int current_vertex = 0; //Current Vertex

        //Add the first batch
        m_Batches.emplace_back(vertex_offset, 6, m_GlyphPointers[0]->texture);
        verticies[current_vertex++] = m_GlyphPointers[0]->topLeft;
        verticies[current_vertex++] = m_GlyphPointers[0]->bottomLeft;
        verticies[current_vertex++] = m_GlyphPointers[0]->bottomRight;
        verticies[current_vertex++] = m_GlyphPointers[0]->bottomRight;
        verticies[current_vertex++] = m_GlyphPointers[0]->topRight;
        verticies[current_vertex++] = m_GlyphPointers[0]->topLeft;
        vertex_offset += 6;

        //Add all the rest of the glyphs
        for ( auto index = 1; index < m_GlyphPointers.size(); index++ ) {

            //Check if the glyph can be part of the current batch
            if ( m_GlyphPointers[index]->texture != m_GlyphPointers[index - 1]->texture) {
                // Make a new Batch
                m_Batches.emplace_back(vertex_offset, 6, m_GlyphPointers[index]->texture);
            } else {
                // If it's part of the current batch, just increase numVerticies
                m_Batches.back().numVerticies += 6;
            }

            verticies[current_vertex++] = m_GlyphPointers[index]->topLeft;
            verticies[current_vertex++] = m_GlyphPointers[index]->bottomLeft;
            verticies[current_vertex++] = m_GlyphPointers[index]->bottomRight;
            verticies[current_vertex++] = m_GlyphPointers[index]->bottomRight;
            verticies[current_vertex++] = m_GlyphPointers[index]->topRight;
            verticies[current_vertex++] = m_GlyphPointers[index]->topLeft;
            vertex_offset += 6;
        }


        //Bind our vbo
        glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
        //Orphan the bufer ( for speed )
        glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof( Vertex ), nullptr, GL_DYNAMIC_DRAW);
        //Upload the data
        glBufferSubData(GL_ARRAY_BUFFER, 0, verticies.size() * sizeof( Vertex ), verticies.data());
        //Unbind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    void SpriteBatch::createVertexArray()
    {
        //Generate new Vertex Array Object is there is not any
        if ( m_Vao == 0) {
            glGenVertexArrays(1, &m_Vao);
        }

        glBindVertexArray(m_Vao);

        //Generate new Vertex Buffer Object if there is not any
        if ( m_Vbo == 0) {
            glGenBuffers(1, &m_Vbo);
        }

        glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);

        /* We are sending one vertex attrib array, which is the
         * only array with the position
         * the zero attribute means the zero index in our vertex shader
         * We have 3 attributes, one for Position one for Color and the last for UV
         */

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        //Position Attribute Pointer
        /* The last argument ( offsetof ) calculates the offset memory in our Vertex struct */
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void* ) offsetof(Vertex, position));
        //Color Attribute Pointer
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof( Vertex ), (void *) offsetof(Vertex, color));
        //UV Attribute Pointer
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void* ) offsetof(Vertex, uv));

        glBindVertexArray(0);
    }

    void SpriteBatch::sortGlyphs()
    {
        switch (m_SortType) {
            case GlyphSortType::BACK_TO_FRONT:
                std::stable_sort(m_GlyphPointers.begin(), m_GlyphPointers.end(), [&](const Glyph* const a, const Glyph* const b) {
                    return ((a->depth) > (b->depth));
                });
                break;
            case GlyphSortType::FRONT_TO_BACK:
                std::stable_sort(m_GlyphPointers.begin(), m_GlyphPointers.end(), [&](const Glyph* const a, const Glyph* const b) {
                    return ((a->depth) < (b->depth));
                });
                break;
            case GlyphSortType::TEXTURE_SORT:
                std::stable_sort(m_GlyphPointers.begin(), m_GlyphPointers.end(), [&](const Glyph* const a, const Glyph* const b) {
                    return ((a->texture) < (b->texture));
                });
                break;
            default:
                break;
        }
    }


    void SpriteBatch::terminate()
    {
        if (m_Vao != 0) {
            glDeleteVertexArrays(1, &m_Vao);
            m_Vao = 0;
        }

        if (m_Vbo != 0) {
            glDeleteBuffers(1, &m_Vbo);
            m_Vbo = 0;
        }
    }

    Glyph::Glyph(const Vec4 &destRect, const Vec4 &uvRect, const GLuint t_texture,
                 const float t_depth, const Color &color)
        : texture(t_texture)
        , depth(t_depth)
    {
        topLeft.color = color;
        topLeft.setPosition(destRect.x, destRect.y + destRect.w);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x, destRect.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

        topRight.color = color;
        topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
    }

    Glyph::Glyph(const Vec4 &destRect, const Vec4 &uvRect, const GLuint t_texture,
                 const float t_depth, const Color &color, const float angle)
        : texture(t_texture)
        , depth(t_depth)
    {
        Vec2 halfDims(destRect.z / 2.0f, destRect.w / 2.0f);

        // Get points centered at origin
        Vec2 tl(-halfDims.x, halfDims.y);
        Vec2 bl(-halfDims.x, -halfDims.y);
        Vec2 br(halfDims.x, -halfDims.y);
        Vec2 tr(halfDims.x, halfDims.y);

        // Rotate the points
        tl = rotatePoint(tl, angle) + halfDims;
        bl = rotatePoint(bl, angle) + halfDims;
        br = rotatePoint(br, angle) + halfDims;
        tr = rotatePoint(tr, angle) + halfDims;

        topLeft.color = color;
        topLeft.setPosition(destRect.x + tl.x, destRect.y + tl.y);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x + bl.x, destRect.y + bl.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + br.x, destRect.y + br.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

        topRight.color = color;
        topRight.setPosition(destRect.x + tr.x, destRect.y + tr.y);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
    }

    Vec2 Glyph::rotatePoint(Vec2 pos, const float angle)
    {
        Vec2 newv;
        newv.x = static_cast<float>(pos.x * cos(angle) - pos.y * sin(angle));
        newv.y = static_cast<float>(pos.x * sin(angle) + pos.y * cos(angle));
        return newv;
    }
}



