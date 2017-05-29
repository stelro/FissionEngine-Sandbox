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

#ifndef FISSIONENGINE_CAMERA2D_HPP
#define FISSIONENGINE_CAMERA2D_HPP


//Engine Internal
#include "Math/Matrix.hpp"
#include "Math/Vector.hpp"

namespace Fiene {

    class Camera2D {
    public:
                            Camera2D();
                            ~Camera2D();

        void                startUp(const int screenWidth = 1024, const int screenHeight = 768);
        void                update();

        void                setPosition(const Vec2& newPos);
        void                setPosition(const float t_x, const float t_y);
        void                setCamOffset(const float x, const float y);
        void                setScaleOffset(const float scale);
        void                setScale(const float scale);

        Vec2                getPosition() const;
        float               getScale() const;
        Matrix4             getCameraMatrix() const;
        Vec2                convertCameraToWorld(Vec2 screenCords);
        bool                isBoxInView(const Vec2& position, const Vec2& dimensions);
        bool                isBoxInView(const float x, const float y, const float width, const float height);
        void                terminate();

    private:

        Matrix4             m_CameraMatrix;
        Matrix4             m_OrthoMatrix;
        Vec2                m_Position;
        float               m_Scale;
        int                 m_ScreenWidth;
        int                 m_ScreenHeight;
        bool                m_NeedMatrixUpdate;
    };


}


#endif //FISSIONENGINE_CAMERA2D_HPP
