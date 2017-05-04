#include "App.hpp"

#include "MainMenuState.hpp"
#include "GamePlayState.hpp"
#include "StateIndecies.hpp"

App::App()
{

}

App::~App()
{

}

void App::init()
{
    m_MainMenuState = new MainMenuState(&window);
    m_GamePlayState = new GamePlayState(&window);
}

void App::addStates()
{

    stateManager.addState(MAINMENU_STATE, m_MainMenuState);
    stateManager.addState(GAMEPLAY_STATE, m_GamePlayState);

}

void App::exit()
{
    //todo: delete states
}
