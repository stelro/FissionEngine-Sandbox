#include "GamePlayState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"

int GamePlayState::changeStateNext()
{
    return 0;
}

int GamePlayState::changeStatePrevious()
{
    return MAINMENU_STATE;
}

void GamePlayState::render()
{
    m_ShaderProgram->useGLSLProgram();

    Fiene::Matrix4 projectionMatrix = m_Camera.getCameraMatrix();
    GLint pUniform = m_ShaderProgram->getUniformLocation("P");
    glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

    m_SpriteBatch->begin();
    char buffer[128] = "";
    sprintf(buffer, "Game Play State");
    m_SpriteFont->draw(*m_SpriteBatch, buffer, glm::vec2(0,0), glm::vec2(0.5), 0.0f, Fiene::Color(85,25585,255));
    m_SpriteBatch->end();
    m_SpriteBatch->render();
}

void GamePlayState::update()
{
    m_Camera.update();
    m_InputManager.update();

    if (m_InputManager.isKeyPressed(SDLK_1)) {
        StateMode = Fiene::CurrentStateMode::STATE_MOVE_PREVIOUS;
    }

    if (m_InputManager.isKeyPressed(SDLK_ESCAPE)) {
        StateMode = Fiene::CurrentStateMode::STATE_EXIT;
    }
}

void GamePlayState::onInit()
{
    m_InputManager.startUp();
    m_Camera.startUp(window->getScreenWidth(), window->getScreenHeight());
    m_Camera.setPosition(window->getScreenWidth() / 2, window->getScreenHeight() / 2);

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
        : StateBehaviour(window) {

}

GamePlayState::~GamePlayState() {

}
