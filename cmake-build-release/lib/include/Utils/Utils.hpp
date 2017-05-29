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

#ifndef PROJECT_UTILS_HPP
#define PROJECT_UTILS_HPP

//SDL2 Includes
#include <SDL2/SDL.h>

//OpenGL Includes
#include <GL/glew.h>

namespace Fiene {

    class Color {
    public:

        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;

        Color();
        Color(GLubyte t_r, GLubyte t_g, GLubyte t_b);
        Color(GLubyte t_r, GLubyte t_g, GLubyte t_b, GLubyte t_a);
        Color(const Color& rhs);
        Color operator =(const Color& rhs);
        bool operator ==(const Color& rhs);
        bool operator !=(const Color& rhs);
    };

    struct Point {
        float x;
        float y;
        Point() : x(0.0f), y(0.0f) { }
        Point(float t_x, float t_y) : x(t_x), y(t_y) { }
    };

    struct Pointi {
        int x;
        int y;
        Pointi() : x(0), y(0) { }
        Pointi(int t_x, int t_y) : x(t_x), y(t_y) { }
    };

    struct UVPoint {
        float u;
        float v;
        UVPoint() : u(0.0f), v(0.0f) { }
        UVPoint(float t_u, float t_v) : u(t_u), v(t_v) { }
    };

    struct Vertex {

        UVPoint         uv;
        Color           color;
        Point           position;


        void setPosition(float x, float y) {
            position.x = x;
            position.y = y;
        }

        void setUV(float u, float v) {
            uv.u = u;
            uv.v = v;
        }

        void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
            color.r = r;
            color.g = g;
            color.b = b;
            color.a = a;
        }
    };

    struct Rect {
        Rect() : x(0.0f), y(0.0f), width(0.0f), height(0.0f) { }
        Rect(float t_x, float t_y, float t_w, float t_h)
            : x(t_x), y(t_y), width(t_w), height(t_h) { }
        float x;
        float y;
        float width;
        float height;
    };
}


#endif //PROJECT_UTILS_HPP
