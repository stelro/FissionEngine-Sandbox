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

#ifndef PROJECT_DEF_VECTOR_HPP
#define PROJECT_DEF_VECTOR_HPP

namespace Fiene {

    //We adopt glm's union style inside vectors to represent
    //the same value with deferant names. e.x xyzw for space cordinates
    //rgba for color and stpq for texture cordinates

    template <typename T>
    struct tVec2 {

        tVec2<T>();
        tVec2<T>(T a, T b);
        tVec2<T>(const tVec2<T>& rhs);
        tVec2<T>(T scalar);

        T& operator [](unsigned int index);
        const T& operator [](unsigned int index) const;

        void set(T a, T b);

        /* Unary arithmetic operators */

        template <typename U>
        tVec2<T>& operator=(const tVec2<U>& rhs);
        template <typename U>
        tVec2<T>& operator+=(U scalar);
        template <typename U>
        tVec2<T>& operator+=(const tVec2<U>& rhs);
        template <typename U>
        tVec2<T>& operator-=(U scalar);
        template <typename U>
        tVec2<T>& operator-=(const tVec2<U>& rhs);
        template <typename U>
        tVec2<T>& operator*=(U scalar);
        template <typename U>
        tVec2<T>& operator*=(const tVec2<U>& rhs);
        template <typename U>
        tVec2<T>& operator/=(U scalar);
        template <typename U>
        tVec2<T>& operator/=(const tVec2<U>& rhs);

        tVec2<T>& operator ++();
        tVec2<T>& operator --();
        const tVec2<T> operator ++(int);
        const tVec2<T> operator --(int);

        T               length() const;
        T               squareLength() const;

        union { T x, r, s; };
        union { T y, g, t; };
    };

    /* tVec2 Binary operators */

    template <typename T>
    tVec2<T> operator+(const tVec2<T>& lhs, T scalar);

    template <typename T>
    tVec2<T> operator+(T scalar, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator+(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator-(const tVec2<T>& rhs, T scalar);

    template <typename T>
    tVec2<T> operator-(T scalar, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator-(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator*(const tVec2<T>& lhs, T scalar);

    template <typename T>
    tVec2<T> operator*(T scalar, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator*(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator/(const tVec2<T>& lhs, T scalar);

    template <typename T>
    tVec2<T> operator/(T scalar, const tVec2<T>& rhs);

    template <typename T>
    tVec2<T> operator/(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    bool operator==(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    bool operator!=(const tVec2<T>& lhs, const tVec2<T>& rhs);


    template <typename T>
    T dotProduct(const tVec2<T>& lhs, const tVec2<T>& rhs);

    template <typename T>
    struct tVec3 {

        union { T x, r, s; };
        union { T y, g, t; };
        union { T z, b, p; };

        tVec3<T>();
        tVec3<T>(T a,T b,T c);
        tVec3<T>(const tVec2<T>& lhs, T c);
        tVec3<T>(const tVec3<T>& rhs);
        tVec3<T>(T scalar);

        void set(T a, T b, T c);
        void set(const tVec2<T>& lhs, T c);
        tVec2<T> xy() const;

        T &operator [](unsigned int index);
        const T &operator [](unsigned int index) const;


        /* Unary arithmetic operators */

        template <typename U>
        tVec3<T>& operator=(const tVec3<U>& rhs);
        template <typename U>
        tVec3<T>& operator+=(U scalar);
        template <typename U>
        tVec3<T>& operator+=(const tVec3<U>& rhs);
        template <typename U>
        tVec3<T>& operator-=(U scalar);
        template <typename U>
        tVec3<T>& operator-=(const tVec3<U>& rhs);
        template <typename U>
        tVec3<T>& operator*=(U scalar);
        template <typename U>
        tVec3<T>& operator*=(const tVec3<U>& rhs);
        template <typename U>
        tVec3<T>& operator/=(U scalar);
        template <typename U>
        tVec3<T>& operator/=(const tVec3<U>& rhs);

        /* Increment and decrement operators */

        tVec3<T>& operator++();
        tVec3<T>& operator--();
        const tVec3<T> operator++(int);
        const tVec3<T> operator--(int);


        void normalize();
        tVec3<T> normalized() const;
        T length() const;
        T squaredLength() const;

    };

    template <typename T>
    tVec3<T> operator+(const tVec3<T>& lhs, T scalar);

    template <typename T>
    tVec3<T> operator+(T scalar, const tVec3<T>& lhs);

    template <typename T>
    tVec3<T> operator+(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator-(const tVec3<T>& lhs, T scalar);

    template <typename T>
    tVec3<T> operator-(T scalar, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator-(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator*(const tVec3<T>& lhs, T scalar);

    template <typename T>
    tVec3<T> operator*(T scalar, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator*(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator/(const tVec3<T>& lhs, T scalar);

    template <typename T>
    tVec3<T> operator/(T scalar, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> operator/(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    bool operator==(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    bool operator!=(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    T dotProduct(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    tVec3<T> crossProduct(const tVec3<T>& lhs, const tVec3<T>& rhs);

    template <typename T>
    void lerp(const tVec3<T>& lhs, const tVec3<T>& rhs, tVec3<T>* out, T val);

    template <typename T>
    struct tVec4 {

        //The idea with union come up from
        //Glew library, so credits goes to Glew library
        union { T x, r, s; };
        union { T y, g, t; };
        union { T z, b, p; };
        union { T w, a, q; };

        tVec4<T>();
        tVec4<T>(T a, T b, T c, T d);
        tVec4<T>(const tVec3<T>& vec, T d);
        tVec4<T>(const tVec4<T>& rhs);
        tVec4<T>(T scalar);

        tVec3<T> xyz();
        void set(T a, T b, T c, T d);
        operator tVec3<T>();

        float& operator [](unsigned int index);
        const float& operator [](unsigned int index) const;

        /* Unary arithmetic operators */

        template <typename U>
        tVec4<T>& operator=(const tVec4<U>& rhs);
        template <typename U>
        tVec4<T>& operator+=(U scalar);
        template <typename U>
        tVec4<T>& operator+=(const tVec4<U>& rhs);
        template <typename U>
        tVec4<T>& operator-=(U scalar);
        template <typename U>
        tVec4<T>& operator-=(const tVec4<U>& rhs);
        template <typename U>
        tVec4<T>& operator*=(U scalar);
        template <typename U>
        tVec4<T>& operator*=(const tVec4<U>& rhs);
        template <typename U>
        tVec4<T>& operator/=(U scalar);
        template <typename U>
        tVec4<T>& operator/=(const tVec4<U>& rhs);

        /* Increment and decrement operators */

        tVec4<T>& operator++();
        tVec4<T>& operator--();
        const tVec4<T> operator++(int);
        const tVec4<T> operator--(int);

        T length() const;
        T sqaredLength() const;
        void normilize();

    };

    /* tVec4 arithmetic binary operators */

    template <typename T>
    tVec4<T> operator+(const tVec4<T>& lhs, T scalar);

    template <typename T>
    tVec4<T> operator+(T scalar, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator+(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator-(const tVec4<T>& lhs, T scalar);

    template <typename T>
    tVec4<T> operator-(T scalar, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator-(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator*(const tVec4<T>& lhs, T scalar);

    template <typename T>
    tVec4<T> operator*(T scalar, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator*(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator/(const tVec4<T>& lhs, T scalar);

    template <typename T>
    tVec4<T> operator/(T scalar, const tVec4<T>& rhs);

    template <typename T>
    tVec4<T> operator/(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    bool operator==(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    bool operator!=(const tVec4<T>& lhs, const tVec4<T>& rhs);


    template <typename T>
    T dotProduct(const tVec4<T>& lhs, const tVec4<T>& rhs);

    template <typename T>
    void lerp(const tVec4<T>& lhs, const tVec4<T>& rhs, tVec4<T>* out, T t);
}

#include "def_vector.inl"
#endif //PROJECT_DEF_VECTOR_HPP
