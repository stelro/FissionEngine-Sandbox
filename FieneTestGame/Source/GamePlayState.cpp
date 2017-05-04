#include "GamePlayState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"

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
    m_ShaderProgram->use();

    Fiene::Matrix4 projectionMatrix = m_Camera.getCameraMatrix();
    GLint pUniform = m_ShaderProgram->getUniformLocation("P");
    glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

    m_SpriteBatch->begin();
    m_SpriteFont->draw(*m_SpriteBatch, "Geme Play State", glm::vec2(0,0), glm::vec2(0.5), 0.0f, Fiene::Color(85,255,85,255));
    m_SpriteBatch->end();
    m_SpriteBatch->render();

    m_ShaderProgram->unuse();
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

    m_ShaderProgram = new Fiene::ShaderProgram();
    m_ShaderProgram->compileVertexShader("Shaders/vertex.glsl");
    m_ShaderProgram->compileFragmentShader("Shaders/fragment.glsl");
    m_ShaderProgram->addAttribute("vertexPosition");
    m_ShaderProgram->addAttribute("vertexColor");
    m_ShaderProgram->addAttribute("vertexUV");
    m_ShaderProgram->linkShaders();

    m_SpriteBatch = new Fiene::SpriteBatch;
    m_SpriteBatch->init();
    m_SpriteFont = new Fiene::SpriteFont("Textures/Monaco-Stel.ttf", 32);
}

void GamePlayState::onExit()
{

}

GamePlayState::GamePlayState(Fiene::Window *window)
        : StateBehaviour(window)
{

}

GamePlayState::~GamePlayState()
{

}
