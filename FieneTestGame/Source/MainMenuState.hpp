#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <memory>

#include <Engine/Game/StateBehaviour.hpp>
#include <Engine/2D/SpriteFont.hpp>
#include <Engine/2D/Camera2D.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/Resources/TexturesManager.hpp>


namespace Fiene {
    class BaseAllocator;
}

class MainMenuState : public Fiene::StateBehaviour {
public:
    MainMenuState(Fiene::Window* window);
    ~MainMenuState();

    virtual void                            onInit();
    virtual void                            onExit();

    virtual int                             changeStateNext();
    virtual int                             changeStatePrevious();

    virtual void                            render();
    virtual void                            update();


private:
    Fiene::Camera2D                         m_Camera;
    Fiene::InputManager*                    m_InputManager;
    Fiene::ShaderProgram                    m_ShaderProgram;
    Fiene::SpriteBatch                      m_SpriteBatch;
    Fiene::SpriteFont                       m_SpriteFont;

    Fiene::TexturesManager*                 m_TexturesManager;


};

#endif //MAINMENUSTATE_HPP
