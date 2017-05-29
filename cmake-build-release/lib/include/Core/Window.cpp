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
#include "Window.hpp"
#include "Utils/FDebug.hpp"
#include "IOManager.hpp"

namespace Fiene {

    Window::Window()
        : m_Window(nullptr)
        , m_Title(" ")
        , m_ScreenWidth(0)
        , m_ScreenHeight(0)
        , m_ScreenPosX(SDL_WINDOWPOS_CENTERED)
        , m_ScreenPosY(SDL_WINDOWPOS_CENTERED)
        , m_Vsync(true)
        , m_AlphaBlending(true)
        , m_IsTerminated(false)
        , m_BgcR(0.0f)
        , m_BgcG(0.0f)
        , m_BgcB(0.0f)
        , m_BgcA(1.0f)
    {
        //Empty
    }

    Window::~Window()
    {
        if (!m_IsTerminated) terminate();
    }

    int Window::startUp(const std::string &windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
    {

        Uint32 flags = SDL_WINDOW_OPENGL;

        if ( currentFlags & WINDOW_SHOWN ) {
            flags |= SDL_WINDOW_HIDDEN;
        }
        if ( currentFlags & WINDOW_FULLSCREEN ) {
            flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        if ( currentFlags & WINDOW_BORDERLESS ) {
            flags |= SDL_WINDOW_BORDERLESS;
        }
        if (currentFlags & WINDOW_RESIZABLE ) {
            flags |= SDL_WINDOW_RESIZABLE;
        }
        if (currentFlags & WINDOW_MINIMIZED ) {
            flags |= SDL_WINDOW_MINIMIZED;
        }
        if (currentFlags & WINDOW_MAXIMAZED ) {
            flags |= SDL_WINDOW_MAXIMIZED;
        }
        if (currentFlags & WINDOW_ALLOW_HIGH_DPI ) {
            flags |= SDL_WINDOW_ALLOW_HIGHDPI;
        }


        //Initialize openGL window
        m_Window = SDL_CreateWindow(windowName.c_str(), m_ScreenPosX, m_ScreenPosY, screenWidth, screenHeight, flags);

        if ( m_Window == nullptr ) {
            errorLog("SDL_Window could not be initialized %s\n", SDL_GetError());
            IOManager::iostreamErrorOutput("SDL_Window could not be initialized %s\n", SDL_GetError());
            Exit();
        }

        SDL_GLContext glContext = SDL_GL_CreateContext(m_Window);

        if ( glContext == nullptr ) {
            errorLog("SDL_GLContext could not be created %s\n", SDL_GetError());
            IOManager::iostreamErrorOutput("SDL_GLContext could not be created %s\n", SDL_GetError());
            Exit();
        }

        glewExperimental = GL_TRUE;
        GLenum error = glewInit();
        if ( error != GLEW_OK ) {
            errorLog("Glew could not be initialized : \n");
            IOManager::iostreamErrorOutput("Glew could not be initialized : \n");
            Exit();
        }

        glViewport(m_ScreenPosX, m_ScreenPosY, screenWidth, screenHeight);
        glEnable(GL_DEPTH_TEST);


        //setup the background color
        glClearColor(m_BgcR, m_BgcG, m_BgcB, m_BgcA);

        if ( m_Vsync ) {
            //Enable VSYNC
            SDL_GL_SetSwapInterval(1);
        }

        if ( m_AlphaBlending ) {
            //Enable Alpha Blending
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

        IOManager::iostreamLogOutput("OpenGL Version: %s\n", glGetString(GL_VERSION));
        IOManager::iostreamLogOutput("Project Window Dimensions: [ width: %d ] - [ height: %d ] \n", screenWidth, screenHeight);
        IOManager::iostreamLogOutput("VSYNC: %d\n", m_Vsync);
        IOManager::iostreamLogOutput("Alpha Blending: %d\n\n", m_AlphaBlending);

        return 0;

    }

    void Window::swapBuffer() noexcept
    {
        SDL_GL_SwapWindow(m_Window);
    }

    int Window::getScreenWidth() const
    {
        SDL_DisplayMode currentDisplayMode;
        SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
        return currentDisplayMode.w;
    }

    int Window::getScreenHeight() const
    {
        SDL_DisplayMode currentDisplayMode;
        SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
        return currentDisplayMode.h;
    }

    void Window::terminate()
    {
        if (!m_IsTerminated) {

            if (m_Window) {

                SDL_DestroyWindow(m_Window);
                m_Window = nullptr;
            }

            m_IsTerminated = true;
        }
    }

    void Window::setBackgroundColorRGB(const Color &color)
    {
        m_BgcR = static_cast<float>(color.r/255.0);
        m_BgcG = static_cast<float>(color.g/255.0);
        m_BgcB = static_cast<float>(color.b/255.0);
        m_BgcA = static_cast<float>(color.a/255.0);

        glClearColor(m_BgcR, m_BgcG, m_BgcB, m_BgcA);
    }

    void Window::setBackgroundColorRGB(uint8_t t_r, uint8_t t_g, uint8_t t_b, uint8_t t_a)
    {
        m_BgcR = static_cast<float>(t_r/255.0);
        m_BgcG = static_cast<float>(t_g/255.0);
        m_BgcB = static_cast<float>(t_b/255.0);
        m_BgcA = static_cast<float>(t_a/255.0);

        glClearColor(m_BgcR, m_BgcG, m_BgcB, m_BgcA);
    }

    void Window::setBackgroundColor(float t_r, float t_g, float t_b, float t_a)
    {
        m_BgcR = t_r;
        m_BgcG = t_g;
        m_BgcB = t_b;
        m_BgcA = t_a;

        glClearColor(m_BgcR, m_BgcG, m_BgcB, m_BgcA);
    }

    void Window::blankScreen() noexcept
    {
        //Set the base depth to 1.0
        glClearDepth(1.0);

        //Cleat the color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::windowResize()
    {
        //TODO: Impelement window resize funtion
    }

    SDL_Window *Window::getWindow() const
    {
        return m_Window;
    }

    void Window::setWindowPos(int x, int y)
    {
        m_ScreenPosX = x;
        m_ScreenPosY = y;
    }

    void Window::setWindowPos(const Vec2 &pos)
    {
        m_ScreenPosX = static_cast<int>(pos.x);
        m_ScreenPosY = static_cast<int>(pos.y);
    }

    iVec2 Window::getWindowPos() const
    {
        return iVec2(m_ScreenPosX, m_ScreenPosY);
    }

}



