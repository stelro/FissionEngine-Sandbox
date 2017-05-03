#ifndef GAMEPLAYSTATE_HPP
#define GAMEPLAYSTATE_HPP

#include <Engine/Game/StateBehaviour.hpp>
#include <Engine/2D/SpriteFont.hpp>
#include <Engine/Core/Camera2D.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>


class Fiene::Window;

class GamePlayState : public Fiene::StateBehaviour {
public:
    GamePlayState(Fiene::Window* window);
    ~GamePlayState();
    virtual int                             changeStateNext();
    virtual int                             changeStatePrevious();

    virtual void                            render();
    virtual void                            update();

    virtual void                            onInit();
    virtual void                            onExit();
private:
    Fiene::Camera2D m_Camera;
    Fiene::InputManager m_InputManager;
    Fiene::ShaderProgram* m_ShaderProgram; //fixme
    Fiene::SpriteBatch* m_SpriteBatch; //fixme
    Fiene::SpriteFont *m_SpriteFont; //fixme
};

#endif //GAMEPLAYSTATE_HPP
