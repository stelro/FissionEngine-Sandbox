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

#ifndef FISSIONENGINE_APPBEHAVIOUR_HPP
#define FISSIONENGINE_APPBEHAVIOUR_HPP

//Engine Internal
#include "Engine.hpp"
#include "Core/Window.hpp"
#include "Core/FpsLimiter.hpp"
#include "StateManager.hpp"
#include "StateBehaviour.hpp"

namespace Fiene {

    class InputManager;

    class AppBehaviour {
    public:
        AppBehaviour();
        virtual ~AppBehaviour();

        /**
         * The main entry point of the application, the run() function
         * should be called only once in the main file, after the initialization
         * of the AppBehaviour object
         */
        void run();

        void terminate();

        /**
         * init() method used to perform all the initializations, object creation and allocations
         * of the Application. Prefer init() method over the constructor.
         */
        virtual void init() = 0;

        /**
         * this method used to add states ( or game levels/maps ) to the StateManager.
         * Every new state should be created and DESTROYED from the user, not by the StateManager.
         * The user is responsible for the life time of a state. Good practice is to create all the
         * states you need in the init() method, and then add them to the StateManager inside
         * addState() method.
         */
        virtual void addStates() = 0;

        /**
         * Prefer exit() method over the destructor. If something is created inside the init() method
         * then it should be destroyed inside the exit() method. Otherwise if something is created or
         * initialized inside the constructor, then it should be destructed inside the ~destructor().
         */
        virtual void exit() = 0;

    protected:
        virtual void render();
        virtual void update();
        virtual void initSystems();

        Window                  window;
        FpsLimiter              fps;
        StateManager            stateManager;
        InputManager*           m_InputManager;
        StateBehaviour*         currentState;
        StateModeStatus         currentStateMode;

    private:

        bool m_IsRunning;

    };
}

#endif //FISSIONENGINE_APPBEHAVIOUR_HPP