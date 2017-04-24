//
// Created by stel on 13/4/2017.
//

#ifndef PROJECT_MAINMENUSTATE_HPP
#define PROJECT_MAINMENUSTATE_HPP

#include <Engine/Game/StateBehaviour.hpp>
#include <Engine/Core/Camera2D.hpp>

namespace Fiene {
    class Window;
    class InputManager;
}

class MainMenuState : public Fiene::StateBehaviour {
public:
    MainMenuState(Fiene::Window* window, Fiene::InputManager* inputManager);
    ~MainMenuState();

    virtual int  changeStateBehaviourIndex() override ;

    virtual void init() override ;
    virtual void destroy() override ;

    virtual void update() override ;
    virtual void render() override ;

    virtual void onEntry() override ;
    virtual void onExit() override ;

private:
    Fiene::Window* m_Window;
    Fiene::InputManager* m_InputManager;
    Fiene::Camera2D      m_Camera;
};


#endif //PROJECT_MAINMENUSTATE_HPP
