#ifndef PROJECT_APP_HPP
#define PROJECT_APP_HPP

#include <Engine/Game/AppBehaviour.hpp>

class App : public Fiene::AppBehaviour {
public:
    App();
    ~App();

    virtual void init() override ;
    virtual void addStates() override ;
    virtual void exit() override ;


private:

};


#endif //PROJECT_APP_HPP
