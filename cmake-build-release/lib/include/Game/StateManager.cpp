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
#include "StateManager.hpp"
#include "StateBehaviour.hpp"

namespace Fiene {

    StateManager::StateManager()
            : m_CurrentStateIndex(0)
    {

    }

    StateManager::~StateManager()
    {
//        for (auto &it : m_StateList) {
//            if (it.second != nullptr) {
//                delete it.second;
//                infoLog("it %d has deleted", it.first);
//            }
//        }

        m_StateList.clear();
    }

    void StateManager::addState(u16 stateIndex, StateBehaviour *state)
    {
        if (m_StateList.empty()) {
            m_CurrentStateIndex = stateIndex;
        }

        m_StateList[stateIndex] = state;

    }

    StateBehaviour *StateManager::moveNext()
    {
        StateBehaviour* currentState = getCurrentState();

        if (indexExist(currentState->changeStateNext()) && currentState->changeStateNext() != 0) {
            m_CurrentStateIndex = currentState->changeStateNext();

        }

        return getCurrentState();
    }

    StateBehaviour *StateManager::movePrevious()
    {
        StateBehaviour* currentState = getCurrentState();

        if (indexExist(currentState->changeStatePrevious()) && currentState->changeStatePrevious() != 0) {
            m_CurrentStateIndex = currentState->changeStatePrevious();
        }

        return getCurrentState();
    }

    StateBehaviour *StateManager::getCurrentState()
    {
        return m_StateList[m_CurrentStateIndex];
    }

    bool StateManager::indexExist(int index) const
    {
        auto it = m_StateList.find(index);
        if (it != m_StateList.end()) {
            return true;
        }

        return false;
    }
}