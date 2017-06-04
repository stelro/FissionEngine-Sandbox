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
#ifndef PROJECT_LIGHT2D_HPP
#define PROJECT_LIGHT2D_HPP

//Internal Engine Includes
#include "Math/Vector.hpp"
#include "Utils/Utils.hpp"
#include "SpriteBatch.hpp"

namespace Fiene {

    class Light2D {
    public:
        Light2D();
        ~Light2D();
        void render(SpriteBatch& spriteBatch);
        void setColor(const Color& color);
        void setPosition(const Vec2& position);
        void setSize(float size);
        void setUV(const Vec4& uv);

    private:

        Vec4        m_UV;
        Vec2        m_Position;
        Color       m_Color;
        float       m_Size;
    };

}

#endif //PROJECT_LIGHT2D_HPP