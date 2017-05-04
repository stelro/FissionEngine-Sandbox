#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include <Engine/Game/StateBehaviour.hpp>
#include <Engine/2D/SpriteFont.hpp>
#include <Engine/Core/Camera2D.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/Allocators/FreeListAllocator.hpp>
#include <Engine/Allocators/PoolAllocator.hpp>
#include <Engine/Resources/TexturesManager.hpp>

class MainMenuState : public Fiene::StateBehaviour {
public:
    MainMenuState(Fiene::Window* window);
    ~MainMenuState();

    virtual int                             changeStateNext();
    virtual int                             changeStatePrevious();

    virtual void                            render();
    virtual void                            update();

    virtual void                            onInit();
    virtual void                            onExit();
private:
    Fiene::Camera2D                         m_Camera;
    Fiene::InputManager*                    m_InputManager;
    Fiene::ShaderProgram*                   m_ShaderProgram; //fixme
    Fiene::SpriteBatch*                     m_SpriteBatch; //fixme
    Fiene::SpriteFont *                     m_SpriteFont; //fixme

    void *m_PMemmory;
    Fiene::FreeListAllocator* m_FreeListAllocator;
    Fiene::PoolAllocator* m_PoolAllocator;

    Fiene::TexturesManager* m_TexturesManager; //fixme
};

#endif //MAINMENUSTATE_HPP
