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

#ifndef PROJECT_MATRIXTRANSFORMATIONS_HPP
#define PROJECT_MATRIXTRANSFORMATIONS_HPP

//Engine Internal
#include "Math/Matrix.hpp"

namespace Fiene {

    namespace Math {

        Matrix4 ortho(const float left, const float right,
                      const float bottom, const float top);

        Matrix4 ortho(const float left, const float right, const float bottom,
                      const float top, const float zNear, const float zFar);

        Matrix4 scale(const Matrix4& lhs, const Vec3& rhs);

        Matrix4 translate(const Matrix4& lhs, const Vec3& rhs);

        Matrix4 rotate(const Matrix4& lhs, const Vec3& rhs,const float angle);
    }
}


#endif //PROJECT_MATRIXTRANSFORMATIONS_HPP
