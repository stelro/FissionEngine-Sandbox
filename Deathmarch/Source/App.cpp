#include "App.hpp"
#include <ScriptSystem/ScriptSystem.hpp>


App::App()
{

}

App::~App()
{

}

void App::init()
{

    engine->setWindowTitle("DeathMarch v0.1");
    engine->setWindowSize(1200,800);
    engine->initializeSystems();

    auto scriptsystem = Fiene::ScriptSystem::getInstance();

    scriptsystem->executeAndRun(" print('hello world') ");

}

void App::addStates()
{

}

void App::exit()
{

}




