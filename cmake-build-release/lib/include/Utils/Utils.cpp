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
#include "Utils.hpp"


namespace Fiene {

    Color::Color() : r(0), g(0), b(0), a(0) { }
    Color::Color(GLubyte t_r, GLubyte t_g, GLubyte t_b) : r(t_r), g(t_g), b(t_b), a(255) { }
    Color::Color(GLubyte t_r, GLubyte t_g, GLubyte t_b, GLubyte t_a) : r(t_r), g(t_g), b(t_b), a(t_a) { }
    Color::Color(const Color& rhs) {
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        a = rhs.a;
    }

    Color Color::operator =(const Color& rhs) {

        if ( *this != rhs ) {
            r = rhs.r;
            g = rhs.g;
            b = rhs.b;
            a = rhs.a;
        }

        return *this;
    }

    bool Color::operator ==(const Color& rhs) {
        return r == rhs.r &&
               g == rhs.g &&
               b == rhs.b &&
               a == rhs.a;
    }

    bool Color::operator !=(const Color& rhs) {
        return !((*this) == rhs);
    }

}



