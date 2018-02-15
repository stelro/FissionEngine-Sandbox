#include "App.hpp"
#include <Engine/ScriptSystem/ScriptManager.hpp>
#include <Engine/ScriptSystem/ScriptSystem.hpp>
#include <Engine/Scene/Scene.hpp>

#include <Engine/Core/SharedPtr.hpp>

#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/EntityManager.hpp>
#include <Engine/Scene/TestComponent.hpp>
#include <Engine/Scene/AbstractSystem.hpp>
#include <Engine/Scene/FieneEcs.hpp>

struct Transform : public Fiene::Component<Transform> {
    void helloWorld() {
        std::cout << "Hello from component " << std::endl;
    }
};

struct GrapnicsComponent {
    std::string id;
};

class RenderingSystem : public Fiene::AbstractSystem {
public:
    void sayHello() {
        std::cout << "Hello from renderingSystem" << std::endl;
    }

    void update( Fiene::FieneEcs& ecs, float dt) {

    }
};

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


    auto scriptManager = Fiene::ScriptManager::getInstance();
    auto scriptSystem = Fiene::ScriptSystem::getInstance();

    scriptManager->load("Scripts/ghost.lua");

    scriptSystem->executeAndRun(scriptManager->getScriptSrc("Scripts/ghost.lua"));
    auto table = scriptSystem->getTable("ghost");



    auto entityManager = Fiene::EntityManager::getInstance();

//    auto car = entityManager->create_entity("car");
//    car->add_component<Transform>();
//    //car->get_component<Transform>()->helloWorld();
//
//    auto car2 = entityManager->get_entity("car");
//    car2->get_component<Transform>()->helloWorld();
//
//    std::cout << car->get_id() << std::endl;
//    std::cout << car2->get_id() << std::endl;
//
//    car2->add_component<Fiene::TestComponent>();

    auto ecs = engine->getScene()->getFieneEcs();
    auto system = ecs->register_system < RenderingSystem >();






}

void App::addStates()
{

}

void App::exit()
{

}




