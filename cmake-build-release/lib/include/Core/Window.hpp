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

#ifndef FISSIONENGINE_WINDOW_HPP
#define FISSIONENGINE_WINDOW_HPP

//Engine Internal
#include "Utils/Utils.hpp"
#include "Math/Vector.hpp"
#include "fglobals.h"

//SDL Includes
#include <SDL2/SDL.h>

//C++ Includes
#include <string>

namespace Fiene {

    enum WindowFlags {

        WINDOW_SHOWN            = 0x1,
        WINDOW_FULLSCREEN       = 0x2,
        WINDOW_BORDERLESS       = 0x4,
        WINDOW_RESIZABLE        = 0x8,
        WINDOW_MINIMIZED        = 0x16,
        WINDOW_MAXIMAZED        = 0x32,
        WINDOW_ALLOW_HIGH_DPI   = 0x64

    };

    class Window {
    public:

        Window();
        ~Window();

        F_DISABLE_COPY(Window);
        F_DISABLE_MOVE(Window);

        int startUp(const std::string& windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
        void setBackgroundColorRGB(const Color& color);
        void setBackgroundColorRGB(uint8_t t_r, uint8_t t_g, uint8_t t_b, uint8_t t_a);
        void setBackgroundColor(float t_r, float t_g, float t_b, float t_a);
        void swapBuffer() noexcept;
        void blankScreen() noexcept;
        void windowResize();
        int getScreenWidth() const;
        int getScreenHeight() const;
        SDL_Window* getWindow() const;
        iVec2 getWindowPos() const;
        //Should be called before startup method
        void setWindowPos(int x, int y);
        void setWindowPos(const Vec2& pos);
        void terminate();

    private:

        SDL_Window*     m_Window;
        std::string     m_Title;
        int             m_ScreenWidth;
        int             m_ScreenHeight;
        int             m_ScreenPosX;
        int             m_ScreenPosY;
        bool            m_Vsync;
        bool            m_AlphaBlending;
        bool            m_IsTerminated;

        float           m_BgcR;
        float           m_BgcG;
        float           m_BgcB;
        float           m_BgcA;

    };

}


#endif //FISSIONENGINE_WINDOW_HPP
