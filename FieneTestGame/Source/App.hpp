#pragma once

#include <Engine/Game/AppBehaviour.hpp>

class App : public Fiene::AppBehaviour {
public:
    App();
    ~App();

    void init();
    void addStates();
    void exit();
private:
};