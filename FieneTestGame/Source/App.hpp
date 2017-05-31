#pragma once

#include <memory>

#include <Engine/Game/AppBehaviour.hpp>
#include <Engine/Core/InputManager.hpp>

class GamePlayState;
class MainMenuState;

namespace Fiene {

    class FreeListAllocator;
    class PoolAllocator;
    class TexturesManager;

}

class App : public Fiene::AppBehaviour {
public:
    App();
    ~App();

    void init();
    void addStates();
    void exit();
private:
    GamePlayState* m_GamePlayState;
    MainMenuState* m_MainMenuState;

};