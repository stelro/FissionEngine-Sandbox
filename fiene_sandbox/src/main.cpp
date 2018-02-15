#include <iostream>
#include <Engine/Core/Window.hpp>
#include <Engine/Engine.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/2D/Sprite.hpp>
#include <Engine/2D/SpriteFont.hpp>
#include <Engine/Core/FpsLimiter.hpp>
#include <Engine/Core/Fiene.h>
#include <Engine/2D/Light2D.hpp>
#include <Engine/2D/Camera2D.hpp>
#include <Engine/Lua/lua_script_system.hpp>
#include <Engine/Core/IOManager.hpp>
#include <Engine/Allocators/PoolAllocator.hpp>
#include <Engine/Allocators/StackAllocator.hpp>
#include <Engine/Allocators/FreeListAllocator.hpp>
#include <Engine/Allocators/ProxyAllocator.hpp>
#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/2D/SpriteFont.hpp>
#include <Engine/Allocators/LinearAllocator.hpp>
#include <Engine/GLSL/ShaderProgram2.h>


#include <array>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;


int main()
{

    SDL_Init(SDL_INIT_EVERYTHING);

    //Initialize double buffer windowing
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );


    Fiene::Window           mainWindow;
    Fiene::Camera2D         camera;

    void* pMem = malloc(Fiene::mb_to_byte(512));
    auto* freeListAllocator = new Fiene::FreeListAllocator(Fiene::mb_to_byte(512), pMem);
    auto* proxyAllocator = new Fiene::ProxyAllocator(*freeListAllocator);
    auto* linearAllocator = Fiene::newLinearAllocator(Fiene::mb_to_byte(256), *proxyAllocator);
    auto *texturesManager = Fiene::TexturesManager::create(*linearAllocator,*proxyAllocator, Fiene::mb_to_byte(128));
    auto *inputManager = Fiene::InputManager::create(*linearAllocator);



    mainWindow.startUp("Sandbox", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    mainWindow.setBackgroundColorRGB(20,20,20,255);
    camera.startUp(SCREEN_WIDTH, SCREEN_HEIGHT);
    camera.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT /2 );

    //glViewport(0,0, SCREEN_WIDTH, SCREEN_HEIGHT);


    if (!texturesManager->load("Textures/castle.png")) {
        std::cout << "couldn't load castle.png" << std::endl;
    }

    if (!texturesManager->load("Textures/mhouse.png")) {
        std::cout << "couldn't load mhouse.png" << std::endl;
    }


    GLuint castleTexture = texturesManager->getTextureID("Textures/castle.png");
    GLuint houseTexture = texturesManager->getTextureID("Textures/mhouse.png");

    Fiene::SpriteBatch batch;
    batch.startUp();

    Fiene::SpriteBatch batchFont;
    batch.startUp();


    Fiene::FpsLimiter fpsLimiter;
    fpsLimiter.init(60000.0f);


    Fiene::ShaderProgram shaderProgram;
    shaderProgram.startUp();
    shaderProgram.compileVertexShader("Shaders/test.vert");
    shaderProgram.compileFragmentShader("Shaders/test.frag");
    shaderProgram.addAttribute("vertexPosition");
    shaderProgram.addAttribute("vertexColor");
    shaderProgram.addAttribute("vertexUV");
    shaderProgram.linkShaders();


    Fiene::ShaderProgram lightShader;
    lightShader.startUp();
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


        SDL_GL_SwapWindow(mainWindow.getWindow());

        lightShader.use();

        pUniform = lightShader.getUniformLocation("P");
        glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

        batch.begin();
        Fiene::Light2D light;
        light.setColor(Fiene::Color(0,255,130,180));
        light.setPosition(Fiene::Vec2(SCREEN_WIDTH - 40, SCREEN_HEIGHT - 40));
        light.setSize(249.0f);
        light.render(batch);
        batch.end();
        batch.render();

        lightShader.unuse();

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


        mainWindow.swapBuffer();

        fpsLimiter.end();

    }


    delete proxyAllocator;
    delete freeListAllocator;

    free(pMem);

    camera.terminate();
    mainWindow.terminate();



    return 0;
}