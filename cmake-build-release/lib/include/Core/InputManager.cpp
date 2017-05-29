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
#include "InputManager.hpp"
#include "Utils/FDebug.hpp"

namespace Fiene {

    InputManager* InputManager::m_Instance = nullptr;

    InputManager::InputManager()
        : m_Event(new SDL_Event())
        , m_MouseCoords(0.0f, 0.0f)
    {
        //Empty
    }

    InputManager::~InputManager()
    {
        delete m_Event;
    }

    void InputManager::update()
    {

        /* Loop through key map and copy over it previous */
        for ( auto& it : m_KeyMap ) {
            m_PreviousKeyMap[it.first] = it.second;
        }

        while (SDL_PollEvent(m_Event)) {

            switch (m_Event->type) {

                case SDL_MOUSEMOTION:
                    this->setMouseCoords(static_cast<float>(m_Event->motion.x), static_cast<float>(m_Event->motion.y));
                    break;
                case SDL_KEYDOWN:
                    this->pressKey(m_Event->key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    this->releaseKey(m_Event->key.keysym.sym);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    this->pressKey(m_Event->button.button);
                    break;
                case SDL_MOUSEBUTTONUP:
                    this->releaseKey(m_Event->button.button);
                    break;
                case SDL_QUIT:
                    Exit(1);
                    break;
                default:
                    break;
            }
        }

    }

    void InputManager::pressKey(const unsigned int KeyID)
    {
        m_KeyMap[KeyID] = true;
    }

    void InputManager::releaseKey(const unsigned int KeyID)
    {
        m_KeyMap[KeyID] = false;
    }

    bool InputManager::isKeyHold(const unsigned int KeyID)
    {
        /* we don't want to use associative array aproach here
         * because we don't want to create a key if it doesent exist
         * so we do it manualy
         */

        auto it = m_KeyMap.find(KeyID);
        if (it != m_KeyMap.end()) {
            return it->second;
        } else {
            return false;
        }
    }

    bool InputManager::isKeyPressed(const unsigned int KeyId)
    {

        /* check if it is pressed this frame, and wasn't pressed last frame */
        if ( isKeyHold(KeyId) && !wasKeyDown(KeyId) ) {
            return true;
        }

        return false;
    }

    void InputManager::setMouseCoords(const float x, const float y)
    {
        m_MouseCoords.x = x;
        m_MouseCoords.y = y;
    }

    void InputManager::setMouseCoords(const Vec2 &t_point)
    {
        m_MouseCoords = t_point;
    }

    Vec2 InputManager::getMouseCoords() const
    {
        return m_MouseCoords;
    }

    bool InputManager::wasKeyDown(const unsigned int KeyID)
    {
        /* we don't want to use associative array aproach here
         * because we don't want to create a key if it doesent exist
         * so we do it manualy
         */

        auto it = m_PreviousKeyMap.find(KeyID);
        if (it != m_PreviousKeyMap.end()) {
            return it->second;
        } else {
            return false;
        }
    }

    SDL_Event *InputManager::getEventHandler() const
    {
        return m_Event;
    }

    InputManager *InputManager::instance()
    {
        if (m_Instance) {
            return m_Instance;
        } else {
            m_Instance = new InputManager();
            return m_Instance;
        }
    }

    void InputManager::deleteInstance()
    {
        if (m_Instance) {
            delete m_Instance;
            m_Instance = nullptr;
        } else {
            return;
        }
    }

}



