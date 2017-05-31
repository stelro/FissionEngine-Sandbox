#include "App.hpp"

#include "MainMenuState.hpp"
#include "GamePlayState.hpp"
#include "StateIndecies.hpp"

#include <Engine/Allocators/FreeListAllocator.hpp>
#include <Engine/Allocators/PoolAllocator.hpp>
#include <Engine/Resources/Texture.hpp>
#include <Engine/Resources/TexturesManager.hpp>

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
    delete m_MainMenuState;
    delete m_GamePlayState;

}
