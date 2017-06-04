#include "MainMenuState.hpp"
#include <Engine/Core/Window.hpp>
#include "StateIndecies.hpp"
#include <Engine/Resources/Texture.hpp>
#include <Engine/FileSystem/FileSystem.hpp>
#include <Engine/ScriptSystem/ScriptManager.hpp>
#include <Engine/ScriptSystem/ScriptSystem.hpp>

MainMenuState::MainMenuState(Fiene::Window *window)
        : StateBehaviour(window)
{

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::onInit()
{
    m_InputManager =  Fiene::InputManager::instance();
    m_Camera.startUp(getWindow()->getScreenWidth(), getWindow()->getScreenHeight());
    m_Camera.setPosition(getWindow()->getScreenWidth() / 2, getWindow()->getScreenHeight() / 2);

    m_ShaderProgram.startUp();
    m_ShaderProgram.compileVertexShader("Shaders/vertex.glsl");
    m_ShaderProgram.compileFragmentShader("Shaders/fragment.glsl");
    m_ShaderProgram.linkShaders();

    m_SpriteBatch.startUp();
    m_SpriteFont.startUp("Textures/Monaco-Stel.ttf", 32);

    m_TexturesManager = Fiene::TexturesManager::getInstance();
    m_TexturesManager->load("Textures/castle.png");
    Fiene::infoLog("txt mng size: %d", m_TexturesManager->size());


    Fiene::ScriptManager *scriptManager = Fiene::ScriptManager::getInstance();
    scriptManager->load("maps/hello.lua");

    Fiene::ScriptSystem scriptSystem;
    scriptSystem.executeAndRun(scriptManager->getScriptSrc("maps/hello.lua"));


    auto func = scriptSystem.getFunction<int,int,int>("add");
    std::cout << func(4,5) << std::endl;




}

void MainMenuState::onExit()
{
   // m_TexturesManager->unload("Textures/castle.png");
}


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
    m_ShaderProgram.use();

    GLuint castleTexture = m_TexturesManager->getTextureID("Textures/castle.png");

    Fiene::Vec4 castel_destRect(100,0,300,300);
    Fiene::Vec4 castel_uvRect(0.0f, 0.0f, 1.0f, 1.0f);

    Fiene::Matrix4 projectionMatrix = m_Camera.getCameraMatrix();
    m_ShaderProgram.setMat4("P", projectionMatrix);


    m_SpriteBatch.begin();
    m_SpriteFont.draw(m_SpriteBatch, "Main Menu State", glm::vec2(1.0f,1.0f), glm::vec2(0.5), 0.0f, Fiene::Color(85,255,85,255));
    m_SpriteBatch.append(castel_destRect, castel_uvRect, castleTexture, 0.0f, Fiene::Color(255,255,255,255));
    m_SpriteBatch.end();
    m_SpriteBatch.render();

    m_ShaderProgram.unuse();
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


