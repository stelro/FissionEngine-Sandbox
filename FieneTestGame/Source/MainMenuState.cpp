#include "MainMenuState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"
#include <Engine/Resources/Texture.hpp>
#include <Engine/FileSystem/FileSystem.hpp>
#include <Engine/ScriptSystem/ScriptManager.hpp>
#include <Engine/ScriptSystem/ScriptSystem.hpp>
#include <Engine/2D/Light2D.hpp>
//
#include <Engine/Universe/Universe.hpp>
#include <Engine/Universe/IComponent.hpp>

#include "External/lua-sol/sol.hpp"

sol::state lua;


MainMenuState::MainMenuState(Fiene::Window *window)
        : StateBehaviour(window)
{

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::onInit()
{
    m_InputManager =  Fiene::InputManager::instance();
    m_Camera.startUp(getWindow()->getScreenWidth(), getWindow()->getScreenHeight());
    m_Camera.setPosition(getWindow()->getScreenWidth() / 2, getWindow()->getScreenHeight() / 2);


    m_Universe = new Fiene::Universe();



}

void MainMenuState::onExit()
{

}


int MainMenuState::changeStateNext()
{
    return GAMEPLAY_STATE;
}

int MainMenuState::changeStatePrevious()
{
    return NULL_STATE;
}

void MainMenuState::render()
{

    m_Universe->update();
}

void MainMenuState::update()
{
    m_Camera.update();
    m_InputManager->update();

    if (m_InputManager->isKeyPressed(SDLK_ESCAPE)) {
        setStateMode(Fiene::StateModeStatus::STATE_EXIT);
    }

    if (m_InputManager->isKeyPressed(SDLK_2)) {
       setStateMode(Fiene::StateModeStatus::STATE_MOVE_NEXT);
    }
}


