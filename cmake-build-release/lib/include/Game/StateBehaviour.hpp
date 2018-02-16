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

#ifndef FISSIONENGINE_STATEBEHAVIOUR_HPP
#define FISSIONENGINE_STATEBEHAVIOUR_HPP

//Engine Internal
#include "Core/Core.h"

namespace Fiene {

    class Window;

    /**
     * StateModeStatus Enumeration
     * Determines the current Mode of the State
     *
     */
    enum class StateModeStatus {
        STATE_NONE = 0, /**< enum STATE_NONE */
        STATE_EXIT,
        STATE_MOVE_NEXT,
        STATE_MOVE_PREVIOUS,
        STATE_PUSH_NEXT,
        STATE_PUSH_PREVIOUS,
        STATE_APP_RUNNING
    };

    class StateBehaviour {
    public:
                                                StateBehaviour(Window* _window);
        virtual                                 ~StateBehaviour();

        /**
         * Determines the Next or Previous State if certain event or action is occurred.
         * Every State should have unique index, and the user should keep the indices of
         * all created states.
         * Example : Every sate may be have Next State(level) or Previous State(level),
         * so it can be visualized as a chain, that is, user can move forward or backwards
         * from the current state.
         * Index with number 0, is considered as NULL STATE
         * @return Returns the index of the change to be changed Next Or Previous.
         */
        virtual int                             changeStateNext() = 0;

        /**
         * Determines the Next or Previous State if certain event or action is occurred.
         * Every State should have unique index, and the user should keep the indices of
         * all created states.
         * Example : Every sate may be have Next State(level) or Previous State(level),
         * so it can be visualized as a chain, that is, user can move forward or backwards
         * from the current state.
         * Index with number 0, is considered as NULL STATE
         * @return Returns the index of the change to be changed Next Or Previous.
         */
        virtual int                             changeStatePrevious() = 0;

        /**
         * All render operations, like spritebatch render, shaders and object draw, should be
         * performed inside the render() function. render() function is called every frame.
         */
        virtual void                            render() = 0;

        /**
         * Anything other than render, goes inside update() function, input updates
         * controls, fps, calculations and game logic. update() function is called every frame.
         */
        virtual void                            update() = 0;

        /**
         * All initializations goes on onInit() function
         */
        virtual void                            onInit() = 0;

        /**
         * All destruction relevant to the specific state, goes on onExit() function.
         */
        virtual void                            onExit() = 0;

        /**
         * Sets the StateModeStatus, more specifically sets the mode to be performed on certain actions
         * if the state should move next, move previous, run, or exit.
         * StateModeStatus is enumeration.
         * @param stateMode sets StateModeStatus from StateModeStatus Enumeration
         * (STATE_NONE,STATE_EXIT, STATE_NEXT, STATE_PREVIOUS,STATE_APP_RUNNING)
         */
        void                                    setStateMode(StateModeStatus stateMode) { m_StateMode = stateMode; }

        /**
         * Returns the current window. Every state can be rendered on the same window, or on different windows.
         * The best practice is to create one window on the main App, and then pass this window to all game states.
         * @return window pointer
         */
        Window*                                 getWindow() const { return m_Window; }

        /**
         * Set the StateModeStatus to STATE_APP_RUNNING, that is, starts the state.
         * This method is usually called from AppBehaviour object, after the state is changed or initialized.
         * User have not to bother with run() method, only in specific cases.
         */
        void                                    run() { m_StateMode = StateModeStatus::STATE_APP_RUNNING; }

        /**
         *
         * @return Returns the currentStateMode of the current State
         */
        StateModeStatus                         getCurrentStateMode() const { return m_StateMode; }

    private:
        StateModeStatus                         m_StateMode;
        Window*                                 m_Window;

    };
}

#endif //FISSIONENGINE_STATEBEHAVIOUR_HPP