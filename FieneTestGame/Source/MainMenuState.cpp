#include "MainMenuState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"
#include <Engine/Resources/Texture.hpp>

int MainMenuState::changeStateNext()
{
    return GAMEPLAY_STATE;
}

int MainMenuState::changeStatePrevious()
{
    return NULL_STATE;
}

void MainMenuState::render()
{
    m_ShaderProgram->use();

    GLuint castleTexture = m_TexturesManager->getTextureID("Textures/castle.png");
    Fiene::Vec4 castel_destRect(100,0,300,300);
    Fiene::Vec4 castel_uvRect(0.0f, 0.0f, 1.0f, 1.0f);



    Fiene::Matrix4 projectionMatrix = m_Camera.getCameraMatrix();
    GLint pUniform = m_ShaderProgram->getUniformLocation("P");
    glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

    m_SpriteBatch->begin();
    char buffer[128] = "";
    sprintf(buffer, "Main Menu State");
    m_SpriteFont->draw(*m_SpriteBatch, buffer, glm::vec2(0,0), glm::vec2(0.5), 0.0f, Fiene::Color(85,255,85,255));
    m_SpriteBatch->append(castel_destRect, castel_uvRect, castleTexture, 0.0f, Fiene::Color(255,255,255,255));
    m_SpriteBatch->end();
    m_SpriteBatch->render();



    m_ShaderProgram->unuse();
}

void MainMenuState::update()
{
    m_Camera.update();
    m_InputManager->update();

    if (m_InputManager->isKeyPressed(SDLK_ESCAPE)) {
        setStateMode(Fiene::StateModeStatus::STATE_EXIT);
    }

    if (m_InputManager->isKeyPressed(SDLK_2)) {
       setStateMode(Fiene::StateModeStatus::STATE_MOVE_NEXT);
    }
}

void MainMenuState::onInit()
{
    m_InputManager =  Fiene::InputManager::instance();
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

    m_PMemmory = malloc(ONEGIG_SIZE);
    m_FreeListAllocator = new Fiene::FreeListAllocator(ONEGIG_SIZE, m_PMemmory);
    m_PoolAllocator = Fiene::newPoolAllocator(sizeof(Fiene::Texture), __alignof(Fiene::Texture), EIGHTMEG_SIZE, *m_FreeListAllocator);

    m_TexturesManager = new Fiene::TexturesManager(*m_PoolAllocator);

    m_TexturesManager->load("Textures/castle.png");

}

void MainMenuState::onExit()
{

}

MainMenuState::MainMenuState(Fiene::Window *window)
        : StateBehaviour(window) {

}

MainMenuState::~MainMenuState() {

}
