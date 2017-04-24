//
// Created by stel on 7/4/2017.
//

#ifndef PROJECT_GAMEPLAYSTATE_HPP
#define PROJECT_GAMEPLAYSTATE_HPP

#include <Engine/Game/StateBehaviour.hpp>
#include <Engine/Core/Camera2D.hpp>

namespace Fiene {
    class Window;
    class InputManager;
}


class GamePlayState : public Fiene::StateBehaviour {
public:
    GamePlayState(Fiene::Window* window, Fiene::InputManager* inputManager);
    ~GamePlayState();
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


#endif //PROJECT_GAMEPLAYSTATE_HPP
