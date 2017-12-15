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

//using Fiene::infoLog;
//using Fiene::errorLog;
//
//bool printtiles = true;



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

    glm::vec4 aha;


    Fiene::Window           mainWindow;
    Fiene::Camera2D         camera;

    void* pMem = malloc(Fiene::mb_to_byte(512));
    Fiene::FreeListAllocator* freeListAllocator = new Fiene::FreeListAllocator(Fiene::mb_to_byte(512), pMem);

    Fiene::ProxyAllocator* proxyAllocator = new Fiene::ProxyAllocator(*freeListAllocator);

    Fiene::LinearAllocator* linearAllocator = Fiene::newLinearAllocator(Fiene::mb_to_byte(256), *proxyAllocator);


    Fiene::TexturesManager *texturesManager = Fiene::TexturesManager::create(*linearAllocator,*proxyAllocator, Fiene::mb_to_byte(128));

    Fiene::InputManager *inputManager = Fiene::InputManager::create(*linearAllocator);

    Fiene::Color color(255,255,255,255);





    mainWindow.startUp("Sample Engine", 1024, 768, 0);
    mainWindow.setBackgroundColorRGB(100,100,100,255);
    camera.startUp(1024, 768);
    camera.setPosition(1024/2, 768/2);

    glViewport(0,0, 1024, 768);


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
    fpsLimiter.setMaxFps(60000.0f);


    Fiene::ShaderProgram shaderProgram;
    shaderProgram.startUp();
    shaderProgram.compileVertexShader("Shaders/test.vert");
    shaderProgram.compileFragmentShader("Shaders/test.frag");
    shaderProgram.addAttribute("vertexPosition");
    shaderProgram.addAttribute("vertexColor");
    shaderProgram.addAttribute("vertexUV");
    shaderProgram.linkShaders();

    Fiene::ShaderProgram2 shader;
    shader.loadShaders("Shaders/test2_vert.glsl", "Shaders/test2_frag.glsl");

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

    std::array<GLfloat, 9> vertices1 {
        -0.5f,  0.5f,  0.0f,
        0.5f,  0.5f,  0.0f,
        0.5f, -0.5f,  0.5f,
    };

    GLuint vbo1, vao1;

    glGenVertexArrays(1, &vao1);
    glBindVertexArray(vao1);

    glGenBuffers(1, &vbo1);
    glBindBuffer(GL_ARRAY_BUFFER, vbo1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    shader.useShaderProgram2();
    glBindVertexArray(0);


    const float cam_offset = 20.0f;
//
//    Fiene::SpriteFont* spriteFont = new Fiene::SpriteFont();
//    spriteFont->startUp("Textures/Monaco-Stel.ttf",32);

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

        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

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
        light.setPosition(camera.convertCameraToWorld(inputManager->getMouseCoords()));
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