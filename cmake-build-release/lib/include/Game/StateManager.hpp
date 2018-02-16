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

#ifndef FISSIONENGINE_STATEMANAGER_HPP
#define FISSIONENGINE_STATEMANAGER_HPP

//Engine Internal
#include "Core/Core.h"
#include "Core/Stack.hpp"

//C++ Includes
#include <unordered_map>

namespace Fiene {

    class StateBehaviour;

    class StateManager {
    public:
        StateManager();
        ~StateManager();
        /**
         * Adds new state to the StateManager with unique Index
         * User must take care of the StateBehaviour pointer.
         * @param stateIndex unique StateIndex
         * @param state StateBehaviour pointer
         */
        void                                            addState(u16 stateIndex, StateBehaviour* state);
        StateBehaviour*                                 getCurrentState();
        size_t                                          currentStateSize() const            { return m_StateList.size(); }
        int                                             currentStateIndex() const           { return m_CurrentStateIndex; }

        StateBehaviour*                                 moveNext();
        StateBehaviour*                                 movePrevious();


        bool                                            indexExist(int index) const;

    private:
        std::unordered_map<int, StateBehaviour*>        m_StateList;
        int                                             m_CurrentStateIndex;

    };
}

#endif //FISSIONENGINE_STATEMANAGER_HPP