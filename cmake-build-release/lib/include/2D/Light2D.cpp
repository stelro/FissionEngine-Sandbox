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

//Internal Engine Includes
#include "Light2D.hpp"
#include "Math/Matrix.hpp"

//C++ Includes
#include <iostream>

namespace Fiene {

    Light2D::Light2D()
        : m_UV(Vec4(-1.0f,-1.0f,2.0f,2.0f))
        , m_Color(255,255,255,255)
        , m_Size(20.0f)
    { }

    Light2D::~Light2D()
    {
        //Empty
    }

    void Light2D::render(SpriteBatch& spriteBatch) {

        Vec4 destRect;
        destRect.x = m_Position.x - m_Size / 2.0f;
        destRect.y = m_Position.y - m_Size / 2.0f;
        destRect.z = m_Size;
        destRect.w = m_Size;
        spriteBatch.append(destRect,m_UV,0,0.0f,m_Color,0.0f);
    }


    void Light2D::setColor(const Color &color)
    {
        m_Color = color;
    }

    void Light2D::setPosition(const Vec2 &position)
    {
        m_Position = position;
    }

    void Light2D::setSize(float size)
    {
        m_Size = size;
    }

    void Light2D::setUV(const Vec4 &uv)
    {
        m_UV = uv;
    }

}