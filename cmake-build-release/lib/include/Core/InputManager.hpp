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

#ifndef FISSIONENGINE_INPUTMANAGER_HPP
#define FISSIONENGINE_INPUTMANAGER_HPP

//Engine Internal
#include "Utils/Utils.hpp"
#include "Math/Vector.hpp"
#include "Core/fglobals.h"

//C++ Includes
#include <unordered_map>

namespace Fiene {

    class InputManager {
    public:
        static InputManager*                        instance();
        static void                                 deleteInstance();
                                                    F_DISABLE_COPY(InputManager);
                                                    F_DISABLE_MOVE(InputManager);

        void                                        update();
        bool                                        isKeyHold(const unsigned int KeyID);
        bool                                        isKeyPressed(const unsigned int KeyId);
        void                                        setMouseCoords(const float x,const float y);
        void                                        setMouseCoords(const Vec2& t_point);
        Vec2                                        getMouseCoords() const;
        SDL_Event*                                  getEventHandler() const;

    private:
                                                    InputManager();
                                                    ~InputManager();

        static InputManager*                        m_Instance;

        //Check if it was pressed the last frame
        bool                                        wasKeyDown(unsigned int KeyID);
        void                                        pressKey(unsigned int KeyID);
        void                                        releaseKey(unsigned int KeyID);

        std::unordered_map<unsigned int, bool>      m_KeyMap;
        std::unordered_map<unsigned int, bool>      m_PreviousKeyMap;
        SDL_Event*                                  m_Event;
        Vec2                                        m_MouseCoords;
    };

}


#endif //FISSIONENGINE_INPUTMANAGER_HPP
