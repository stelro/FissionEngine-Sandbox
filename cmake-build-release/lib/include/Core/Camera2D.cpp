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
#include "Camera2D.hpp"
#include "Math/MatrixTransformations.hpp"

//#include <glm/gtc/matrix_transform.hpp>

namespace Fiene {

    Camera2D::Camera2D()
        : m_CameraMatrix(1.0f)
        , m_OrthoMatrix(1.0f)
        , m_Position(0.0f, 0.0f)
        , m_Scale(1)
        , m_NeedMatrixUpdate(true)
    {

    }

    Camera2D::~Camera2D()
    {
        //Empty
    }

    void Camera2D::startUp(const int screenWidth, const int screenHeight)
    {
        m_ScreenWidth = screenWidth;
        m_ScreenHeight = screenHeight;
        m_OrthoMatrix = Math::ortho(0.0f, static_cast<float>(m_ScreenWidth), 0.0f, static_cast<float>(screenHeight));
    }


    void Camera2D::update()
    {
        if ( m_NeedMatrixUpdate ) {

            //Camera Translation
            Vec3 _translate(static_cast<float>(-m_Position.x) + static_cast<float>(m_ScreenWidth) / 2.0f,
                            static_cast<float>(-m_Position.y) + static_cast<float>(m_ScreenHeight) / 2.0f, 0.0f);

            m_CameraMatrix = Math::translate(m_OrthoMatrix, _translate);

            //Camera Scale
            Vec3 scale(m_Scale, m_Scale, 0.0f);
            m_CameraMatrix = Math::scale(Matrix4(1.0f), scale) * m_CameraMatrix;
            m_NeedMatrixUpdate = false;

        }
    }

    void Camera2D::setPosition(const Vec2 &newPos)
    {
        m_Position = newPos;
        m_NeedMatrixUpdate = true;
    }


    void Camera2D::setPosition(const float t_x, const float t_y)
    {
        m_Position.x = t_x;
        m_Position.y = t_y;
        m_NeedMatrixUpdate = true;
    }

    void Camera2D::setCamOffset(const float x, const float y)
    {
        m_Position.x += x;
        m_Position.y += y;
        m_NeedMatrixUpdate = true;
    }

    void Camera2D::setScale(const float scale)
    {
        m_Scale = scale;
        m_NeedMatrixUpdate = true;
    }

    void Camera2D::setScaleOffset(const float scale)
    {
        m_Scale += scale;
        m_NeedMatrixUpdate = true;
    }

    Vec2 Camera2D::getPosition() const
    {
        return m_Position;
    }

    float Camera2D::getScale() const
    {
        return m_Scale;
    }

    Matrix4 Camera2D::getCameraMatrix() const
    {
        return m_CameraMatrix;
    }

    Vec2 Camera2D::convertCameraToWorld(Vec2 screenCords)
    {
        //Invert Y direction
        screenCords.y = static_cast<float>(m_ScreenHeight) - static_cast<float>(screenCords.y);
        //make it so that zero is the center
        screenCords -= Vec2(static_cast<float>(m_ScreenWidth) / 2.0f, static_cast<float>(m_ScreenHeight) / 2.0f);
        //scale the coordinates
        screenCords /= m_Scale;
        //translate with the camera position
        screenCords += m_Position;

        return screenCords;
    }

    bool Camera2D::isBoxInView(const Vec2 &position, const Vec2 &dimensions)
    {
        Vec2 scaledScreenDimensions = Vec2(static_cast<float>(m_ScreenWidth), static_cast<float>(m_ScreenHeight)) / (m_Scale);

        //the minumum distance before collision occurs
        const float MIN_DISTANCE_X = dimensions.x / 2.0f + scaledScreenDimensions.x / 2.0f;
        const float MIN_DISTANCE_Y = dimensions.y / 2.0f + scaledScreenDimensions.y / 2.0f;

        //center position of the parameters
        Vec2 pos = position;
        Vec2 dim = dimensions;
        Vec2 centerPos = pos + dim / 2.0f;
        //center position of the camera
        Vec2 centerCameraPos = m_Position;
        //vector from the input to the camera
        Vec2 distVec = centerPos - centerCameraPos;

        //get the depth of the collision
        float xdepth = MIN_DISTANCE_X - static_cast<float>( abs(static_cast<int>(distVec.x)) );
        float ydepth = MIN_DISTANCE_Y - static_cast<float>( abs(static_cast<int>(distVec.y)) );

        if (xdepth > 0 || ydepth > 0) {
            //there was a collision
            return true;
        }

        return false;
    }

    bool Camera2D::isBoxInView(const float x, const float y, const float width, const float height)
    {
        Vec2 scaledScreenDimensions = Vec2(static_cast<float>(m_ScreenWidth), static_cast<float>(m_ScreenHeight)) / (m_Scale );

        //the minumum distance before collision occurs
        const float MIN_DISTANCE_X = width / 2.0f + scaledScreenDimensions.x / 2.0f;
        const float MIN_DISTANCE_Y = height / 2.0f + scaledScreenDimensions.y / 2.0f;

        //center position of the parameters
        Vec2 centerPos;
        centerPos.x = x + width / 2.0f;
        centerPos.y = y + height / 2.0f;
        //center position of the camera
        Vec2 centerCameraPos;
        centerCameraPos.x = x;
        centerCameraPos.y = y;
        //vector from the input to the camera
        Vec2 distVec = centerPos - centerCameraPos;


        //get the depth of the collision
        float xdepth = MIN_DISTANCE_X - static_cast<float>( abs(static_cast<int>(distVec.x)) );
        float ydepth = MIN_DISTANCE_Y - static_cast<float>( abs(static_cast<int>(distVec.y)) );

        if (xdepth > 0 || ydepth > 0) {
            //there was a collision
            return true;
        }

        return false;
    }

    void Camera2D::terminate()
    {

    }

}


