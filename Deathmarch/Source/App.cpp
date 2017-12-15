#include "App.hpp"
#include <Engine/ScriptSystem/ScriptManager.hpp>
#include <Engine/ScriptSystem/ScriptSystem.hpp>
#include <Engine/Scene/Scene.hpp>

#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include <functional>

#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/NpcComponent.hpp>
#include <Engine/Scene/GraphicsComponent.hpp>

App::App()
{

}

App::~App()
{

}

void App::init()
{

    engine->setWindowTitle("Ultra Space v0.1");
    engine->setWindowSize(1200,800);
    engine->initializeSystems();


    auto scriptManager = Fiene::ScriptManager::getInstance();
    auto scriptSystem = Fiene::ScriptSystem::getInstance();

    scriptManager->load("Scripts/ghost.lua");

    scriptSystem->executeAndRun(scriptManager->getScriptSrc("Scripts/ghost.lua"));
    auto table = scriptSystem->getTable("ghost");

    auto func = scriptSystem->getProtectedFunction<void>("hello");

//    if (func == nullptr) {
//        std::cout << "is nullptr" << std::endl;
//    } else {
//        func();
//    }


    Fiene::Scene* scene = engine->getScene();
    auto e = scene->loadEntity("Scripts/ghost.lua", "ghost");

    auto npcc = e->getComponent<Fiene::GraphicsComponent>();
    std::cout << e->getType() << " says: " << npcc->getFilename() << std::endl;

    scene->reload();




}

void App::addStates()
{

}

void App::exit()
{

}




