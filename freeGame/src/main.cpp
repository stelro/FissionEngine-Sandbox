#include <iostream>
#include <Engine/Core/Window.hpp>
#include <Engine/Engine.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/2D/Sprite.hpp>
#include <Engine/Core/FpsLimiter.hpp>
#include <Engine/2D/Light2D.hpp>
#include <Engine/Map/TileSet.hpp>
#include <Engine/Map/Tile.hpp>
#include <Engine/Map/Map.hpp>
#include <Engine/Core/Camera2D.hpp>
#include <Engine/Map/TilesetLayer.hpp>
#include <Engine/Lua/lua_script_system.hpp>
#include <Engine/Map/MapRenderer.hpp>
#include <Engine/Map/OrthogonalRenderer.hpp>
#include <Engine/Core/IOManager.hpp>
#include <Engine/Allocators/PoolAllocator.hpp>
#include <Engine/Allocators/StackAllocator.hpp>
#include <Engine/Allocators/FreeListAllocator.hpp>
#include <Engine/Allocators/ProxyAllocator.hpp>
#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/2D/SpriteFont.hpp>

using Fiene::infoLog;
using Fiene::errorLog;

bool printtiles = true;



int main()
{


    glm::vec4 aha;

    Fiene::EngineCore::initialize();

    Fiene::Window           mainWindow;
    Fiene::InputManager*     inputManager;
    Fiene::Camera2D         camera;

    void* pMem = malloc(ONEGIG_SIZE);
    Fiene::FreeListAllocator* freeListAllocator = new Fiene::FreeListAllocator(ONEGIG_SIZE, pMem);
    Fiene::PoolAllocator* poolAllocator = Fiene::newPoolAllocator(sizeof(Fiene::Texture),
                                                                  __alignof(Fiene::Texture), EIGHTMEG_SIZE, *freeListAllocator);
    Fiene::ProxyAllocator* proxyAllocator = new Fiene::ProxyAllocator(*poolAllocator);


    Fiene::TexturesManager texturesManager(*proxyAllocator);


    Fiene::Color color(255,255,255,255);

    mainWindow.setBackgroundColorRGB(100,100,100,255);


    mainWindow.startUp("Sample Engine", 1024, 768, 0);
    inputManager = Fiene::InputManager::instance();
    camera.startUp(1024, 768);
    camera.setPosition(1024/2, 768/2);


    texturesManager.load("Textures/castle.png");
    texturesManager.load("Textures/mhouse.png");


    GLuint castleTexture = texturesManager.getTextureID("Textures/castle.png");
    GLuint houseTexture = texturesManager.getTextureID("Textures/mhouse.png");

    Fiene::SpriteBatch batch;
    batch.init();

    Fiene::SpriteBatch batchFont;
    batchFont.init();


    Fiene::FpsLimiter fpsLimiter;
    fpsLimiter.setMaxFps(60000.0f);

    Fiene::ShaderProgram shaderProgram;
    shaderProgram.compileVertexShader("Shaders/test.vert");
    shaderProgram.compileFragmentShader("Shaders/test.frag");
    shaderProgram.addAttribute("vertexPosition");
    shaderProgram.addAttribute("vertexColor");
    shaderProgram.addAttribute("vertexUV");
    shaderProgram.linkShaders();

    Fiene::ShaderProgram lightShader;
    lightShader.compileVertexShader("Shaders/lightShader.vert");
    lightShader.compileFragmentShader("Shaders/lightShader.frag");
    lightShader.addAttribute("vertexPosition");
    lightShader.addAttribute("vertexColor");
    lightShader.addAttribute("vertexUV");
    lightShader.linkShaders();

    Fiene::Vec4 castel_destRect(100,0,300,300);
    Fiene::Vec4 castel_uvRect(0.0f, 0.0f, 1.0f, 1.0f);

    Fiene::Vec4 house_destRect(0,0,100,100);
    Fiene::Vec4 house_uvRect(0.0f, 0.0f, 1.0f, 1.0f);


    const float cam_offset = 20.0f;

    Fiene::SpriteFont* spriteFont = new Fiene::SpriteFont("Textures/Monaco-Stel.ttf",32);

    Fiene::IOManager::iostreamGlLogParamsOutput();

    bool run_state = true;

    while ( run_state ) {

        fpsLimiter.begin();

        mainWindow.blankScreen();

        camera.update();
        //---- shader program use --//
        shaderProgram.use();

        glActiveTexture(GL_TEXTURE0);

        GLint textureUniform = shaderProgram.getUniformLocation("mySampler");
        glUniform1i(textureUniform, 0);


        //Grab the camera matrix
        //glm::mat4 projectionMatrix = camera.getCameraMatrix();
        Fiene::Matrix4 projectionMatrix = camera.getCameraMatrix();
        GLint pUniform = shaderProgram.getUniformLocation("P");
        glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

        batch.begin();
        batch.append(castel_destRect, castel_uvRect,castleTexture, 0.0f, Fiene::Color(255,255,255,200));
        batch.append(house_destRect, house_uvRect, houseTexture, 0.0f, Fiene::Color(255,255,255,255));

        batch.end();
        batch.render();

        //glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        inputManager->update();

        if ( inputManager->getEventHandler()->type == SDL_QUIT )
            run_state = false;

        if ( inputManager->isKeyPressed(SDLK_ESCAPE))
            run_state = false;

        if (inputManager->isKeyHold(SDLK_w)) {
            camera.setCamOffset(0, cam_offset);
        }
        if (inputManager->isKeyHold(SDLK_s)) {
            camera.setCamOffset(0,-cam_offset);
        }
        if (inputManager->isKeyHold(SDLK_d)) {
            camera.setCamOffset(cam_offset, 0);
        }
        if (inputManager->isKeyHold(SDLK_a)) {
            camera.setCamOffset(-cam_offset, 0);
        }
        if (inputManager->isKeyHold(SDLK_r)) {
            camera.setScaleOffset(0.2f);
        }
        if (inputManager->isKeyHold(SDLK_q)) {
            camera.setScaleOffset(-0.2f);
        }




        camera.update();


        shaderProgram.unuse();

//        lightShader.useGLSLProgram();
//
//        pUniform = lightShader.getUniformLocation("P");
//        glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);
//
//        batch.begin();
//        Fiene::Light2D light;
//        light.setColor(Fiene::Color(0,255,130,180));
//        light.setPosition(camera.convertCameraToWorld(inputManager->getMouseCoords()));
//        light.setSize(249.0f);
//        light.render(batch);
//        batch.end();
//        batch.render();
//
//        lightShader.unuseGLSLProgram();
//
        // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



        mainWindow.swapBuffer();


        fpsLimiter.end();


    }


    proxyAllocator->deallocate(poolAllocator);
    delete proxyAllocator;
    delete freeListAllocator;

    free(pMem);

    camera.terminate();
    mainWindow.terminate();


    Fiene::EngineCore::terminate();

    return 0;
}