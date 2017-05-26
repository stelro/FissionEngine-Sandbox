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
    m_PMemmory = malloc(ONEGIG_SIZE);
    m_FreeListAllocator = new Fiene::FreeListAllocator(ONEGIG_SIZE, m_PMemmory);
    m_PoolAllocator = Fiene::newPoolAllocator(sizeof(Fiene::Texture), __alignof(Fiene::Texture), EIGHTMEG_SIZE, *m_FreeListAllocator);

    m_TexturesManager = new Fiene::TexturesManager(*m_PoolAllocator);

    m_MainMenuState = new MainMenuState(&window, m_TexturesManager);
    m_GamePlayState = new GamePlayState(&window, m_TexturesManager);


}

void App::addStates()
{

    stateManager.addState(MAINMENU_STATE, m_MainMenuState);
    stateManager.addState(GAMEPLAY_STATE, m_GamePlayState);

}

void App::exit()
{
    delete m_TexturesManager;

    Fiene::deletePoolAllocator(*m_PoolAllocator, *m_FreeListAllocator);
    delete m_FreeListAllocator;
    free(m_PMemmory);
    delete m_MainMenuState;
    delete m_GamePlayState;

}
