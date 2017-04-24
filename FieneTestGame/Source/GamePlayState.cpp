//
// Created by stel on 7/4/2017.
//

#include "GamePlayState.hpp"
#include "StateIndecies.hpp"

#include <Engine/Core/Window.hpp>
#include <Engine/Core/InputManager.hpp>
#include <iostream>

GamePlayState::GamePlayState(Fiene::Window* window, Fiene::InputManager* inputManager)
    : m_Window(window)
    , m_InputManager(inputManager)
{

}

GamePlayState::~GamePlayState()
{

}

void GamePlayState::init()
{
    m_Camera.startUp(m_Window->getScreenWidth(), m_Window->getScreenHeight());
    m_Window->setBackgroundColorRGB(255,255,66,255);
}

void GamePlayState::destroy()
{
    m_Camera.terminate();
}

void GamePlayState::update()
{
    m_Camera.update();
    if (m_InputManager->isKeyPressed(SDLK_r)) {
        std::cout << "GMAEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << std::endl;

    }
}

void GamePlayState::render()
{

}

void GamePlayState::onEntry()
{

}

void GamePlayState::onExit()
{

}

int GamePlayState::changeStateBehaviourIndex()
{

}



