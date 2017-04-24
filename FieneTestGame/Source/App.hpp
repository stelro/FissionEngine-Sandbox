
#ifndef PROJECT_APP_HPP
#define PROJECT_APP_HPP

#include <Engine/Game/AppBehaviour.hpp>

class MainMenuState;
class GamePlayState;

class App : public Fiene::AppBehaviour {
public:

    App();
    ~App();

    void startUp() override ;
    void addStates() override ;
    void destroy() override ;

private:
    MainMenuState* m_MainMenuState;
    GamePlayState* m_GamePlayState;
};

#endif