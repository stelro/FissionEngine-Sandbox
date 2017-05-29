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

/*
 * Some parts are taken from Lumix Engine
 * All credits goes to Lumix Engine
 */

//Quaternion used mostly for complex rotations

#ifndef PROJECT_QUATERNION_HPP
#define PROJECT_QUATERNION_HPP

//Engine Internal
#include "Vector.hpp"

namespace Fiene {

    class Matrix4;

    struct Quaternion {

        struct AxisAngle {
            Vec3 axis;
            float angle;
        };

        Quaternion()
            : x(0.0f)
            , y(0.0f)
            , z(0.0f)
            , w(0.0f) { }

        Quaternion(float a, float b, float c, float d)
            : x(a)
            , y(b)
            , z(c)
            , w(d) { }

        Quaternion(const Vec3& axis, float angle);
        void fromEuler(const Vec3& euler);
        Vec3 toEuler() const;
        AxisAngle getAxisAngle() const;
        void conjugate();
        Quaternion conjugated() const;
        void normilize();
        Matrix4 toMatrix() const;
        Vec3 rotate(const Vec3& vec) const;
        Quaternion operator *(const Quaternion& rhs) const;
        Quaternion operator -() const;
        static Quaternion vec3ToVec3(const Vec3& lhs, const Vec3& rhs);

        void set(float a, float b, float c, float d) {
            x = a;
            y = b;
            z = c;
            w = d;
        }



        float               x;
        float               y;
        float               z;
        float               w;

    };

    void nlerp(const Quaternion& q1, const Quaternion& q2, Quaternion * out, float t);
}


#endif //PROJECT_QUATERNION_HPP
