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
#include "AppBehaviour.hpp"
#include "Core/InputManager.hpp"

namespace Fiene {

    AppBehaviour::AppBehaviour()
        : m_IsRunning(true)

    {
    }

    AppBehaviour::~AppBehaviour()
    {

    }

    void AppBehaviour::run()
    {
        initSystems();

        while (m_IsRunning) {
            fps.begin();
            window.blankScreen();

            update();
            render();

            window.swapBuffer();
            fps.end();
        }
    }

    void AppBehaviour::terminate()
    {
        m_IsRunning = false;
        exit();
        window.terminate();
        InputManager::deleteInstance();
        EngineCore::terminate();
    }

    void AppBehaviour::render()
    {
        glViewport(0,0, window.getScreenWidth(), window.getScreenHeight());
        if (currentState->getCurrentStateMode() == StateModeStatus::STATE_APP_RUNNING) {
            currentState->render();
        }

    }

    void AppBehaviour::update()
    {
        switch (currentState->getCurrentStateMode()) {

            case StateModeStatus::STATE_APP_RUNNING:
                currentState->update();
                break;
            case StateModeStatus::STATE_MOVE_NEXT:
                currentState->onExit();
                currentState = stateManager.moveNext();
                if (currentState) {
                    currentState->onInit();
                    currentState->run();
                }
                break;
            case StateModeStatus::STATE_MOVE_PREVIOUS:
                currentState->onExit();
                currentState = stateManager.movePrevious();
                if (currentState) {
                    currentState->onInit();
                    currentState->run();
                }
                break;
            case StateModeStatus::STATE_EXIT:
                this->terminate();
                break;
            default:
                break;
        }
    }

    void AppBehaviour::initSystems()
    {
        EngineCore::initialize();
        init();
        addStates();

        window.startUp("Untitiled", 1024, 768, 0);
        fps.setMaxFps(60000.0f);
        m_InputManager = InputManager::instance();
        currentState = stateManager.getCurrentState();
        currentState->onInit();
        currentState->run();

    }
}