
#include "App.hpp"
#include "GamePlayState.hpp"
#include "MainMenuState.hpp"
#include "StateIndecies.hpp"

App::App()
{

}

App::~App()
{

}

void App::startUp()
{

}

void App::addStates()
{
    m_MainMenuState = new MainMenuState(&bm_Window,bm_InputManager);
    m_GamePlayState = new GamePlayState(&bm_Window,bm_InputManager);

    bm_StateManager.addState(MAINMENU_STATE, m_MainMenuState);
    bm_StateManager.addState(GAMEPLAY_STATE, m_GamePlayState);

    bm_StateManager.changeStateRequest(MAINMENU_STATE);
}

void App::destroy()
{

}
