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

class Npc : public Fiene::Component<Npc> {
public:
    explicit Npc(int a, int b)  {
        std::cout << "pike ston const " << a << b << std::endl;
        this->x = a;
        this->y = b;

        std::cout << '--->' << this->x << std::endl;

    }

    void print() {
        std::cout << " result " << x  << std::endl;
    }

    int valueget() {
        return x + y;
    }

    int x = 0, y = 0;
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
        ecs.update_components<Transform>(dt);

    }

    void render( Fiene::FieneEcs& ecs, float dt) {


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



    auto ecs = engine->getScene()->getFieneEcs();
    auto system = ecs->register_system < RenderingSystem >();
    auto car = ecs->create_entity("car");
    car->add_component<Transform>();
    car->get_component<Transform>()->helloWorld();


}

void App::addStates()
{

}

void App::exit()
{

}




