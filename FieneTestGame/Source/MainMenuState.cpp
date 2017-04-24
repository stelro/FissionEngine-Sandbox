//
// Created by stel on 13/4/2017.
//

#include <Engine/Core/Window.hpp>
#include <Engine/Core/InputManager.hpp>
#include <iostream>

#include "MainMenuState.hpp"
#include "StateIndecies.hpp"


MainMenuState::MainMenuState(Fiene::Window* window, Fiene::InputManager* inputManager)
    : m_Window(window)
    , m_InputManager(inputManager)
{

}

MainMenuState::~MainMenuState()
{

}

int MainMenuState::changeStateBehaviourIndex()
{
    return GAMEPLAY_STATE;
}

void MainMenuState::init()
{
    m_Camera.startUp(m_Window->getScreenWidth(), m_Window->getScreenHeight());

}

void MainMenuState::destroy()
{
    m_Camera.terminate();
}

void MainMenuState::update()
{
    m_Camera.update();

    if (m_InputManager->isKeyPressed(SDLK_r)) {
        std::cout << "Pressed" << std::endl;
        bm_CurrentStateMode = Fiene::StateMode ::NEXT_STATE;
    }
}

void MainMenuState::render()
{

}

void MainMenuState::onEntry()
{

}

void MainMenuState::onExit()
{

}



