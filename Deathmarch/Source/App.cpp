#include "App.hpp"
#include <ScriptSystem/ScriptSystem.hpp>

#include <ECS/Ecs.hpp>


struct position
{
    int x;
    int y;
};

struct graphics {
    std::string name;
};

enum class msg
{
    ACTION,
    UPDATE_TIME,
    DESTROY,
};

struct msg_action
{
    static const int message_id = int( msg::ACTION );
    Fiene::Handle entity;
};

struct msg_update_time
{
    static const int message_id = int( msg::UPDATE_TIME );
    float time;
};

struct msg_destroy
{
    static const int message_id = int( msg::DESTROY );
    Fiene::Handle entity;
};

using msg_list = Fiene::mpl::list<
        msg_action,
        msg_update_time,
        msg_destroy
>;

using game_ecs = Fiene::Ecs< msg_list >;

struct position_system
{

    using components = Fiene::mpl::list<position>;

    void update( game_ecs& ecs, position& p, float dt )
    {
        p.x++;
        std::cout << "update" << std::endl;
    }

    void on( const msg_action& a, position& p)
    {
        p.y--;
        std::cout << "has on" << std::endl;
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

    auto scriptsystem = Fiene::ScriptSystem::getInstance();

    scriptsystem->executeAndRun(" print('hello world') ");

    game_ecs e;
    e.register_component< position >();
    e.register_component< graphics >();

    e.register_system< position_system >();


    Fiene::Handle being = e.create();
    Fiene::Handle car = e.create();

    e.add_component< position >( being, 3, 4 );
    e.add_component< graphics >( being, "hello world");

    e.add_component< graphics >(car, "sex");
    e.add_component< position >(car, 12,3);

    auto p = e.get< position >(car);
    auto s = e.get <position>(being);


    e.dispatch< msg_action >( being );

    for ( auto i = 0 ; i < 10; i++) {
        e.update( 1.0f );
        std::cout << p->x << std::endl;
        std::cout << s->x << std::endl;

    }

}

void App::addStates()
{

}

void App::exit()
{

}




