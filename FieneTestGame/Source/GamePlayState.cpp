#include "GamePlayState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"

GamePlayState::GamePlayState(Fiene::Window *window)
        : StateBehaviour(window)
{

}

GamePlayState::~GamePlayState()
{

}

int GamePlayState::changeStateNext()
{
    return NULL_STATE;
}

int GamePlayState::changeStatePrevious()
{
    return MAINMENU_STATE;
}

void GamePlayState::render()
{
    m_ShaderProgram.use();

    Fiene::Matrix4 projectionMatrix = m_Camera.getCameraMatrix();
    m_ShaderProgram.setMat4("P", projectionMatrix);

    m_SpriteBatch.begin();
    m_SpriteFont.draw(m_SpriteBatch, "Geme Play State", glm::vec2(0,0), glm::vec2(0.5), 0.0f, Fiene::Color(85,255,85,255));
    m_SpriteBatch.end();
    m_SpriteBatch.render();

    m_ShaderProgram.unuse();
}

void GamePlayState::update()
{
    m_Camera.update();
    m_InputManager->update();

    if (m_InputManager->isKeyPressed(SDLK_1)) {
        setStateMode(Fiene::StateModeStatus::STATE_MOVE_PREVIOUS);
    }

    if (m_InputManager->isKeyPressed(SDLK_ESCAPE)) {
        setStateMode(Fiene::StateModeStatus::STATE_EXIT);
    }

}

void GamePlayState::onInit()
{
    m_InputManager = Fiene::InputManager::instance();
    m_Camera.startUp(getWindow()->getScreenWidth(), getWindow()->getScreenHeight());
    m_Camera.setPosition(getWindow()->getScreenWidth() / 2, getWindow()->getScreenHeight() / 2);

    m_ShaderProgram.startUp();
    m_ShaderProgram.compileVertexShader("Shaders/vertex.glsl");
    m_ShaderProgram.compileFragmentShader("Shaders/fragment.glsl");
    m_ShaderProgram.linkShaders();

    m_SpriteBatch.startUp();
    m_SpriteFont.startUp("Textures/Monaco-Stel.ttf", 32);
}

void GamePlayState::onExit()
{
}

