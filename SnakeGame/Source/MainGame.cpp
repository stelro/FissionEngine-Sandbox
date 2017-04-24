//
//#include "MainGame.hpp"
//
//#include <Engine/ResourceManager.hpp>
//#include <Engine/FDebug.hpp>
//#include "Snake.hpp"
//
//
//MainGame::MainGame()
//    : mCurrentState(GameStates::PLAYGAME)
//{
//
//}
//
//MainGame::~MainGame()
//{
//    delete mShaderProgram;
//}
//
//void MainGame::run()
//{
//    initSystems();
//    initShaders();
//
//    mSnake.init(&mInputMngr);
//    gameLoop();
//}
//
//
//void MainGame::initSystems()
//{
//    fiene::init();
//    mWindow.startUp("Snake Game", 600, 600, 0);
//    mWindow.setBackgroundColorRGB(32,32,32,255);
//    mCamera.startUp(600,600);
//    mInputMngr.startUp();
//    mFpsLimiter.setMaxFps(60000.0f);
//    mSpriteBatch.init();
//
//}
//
//void MainGame::initShaders()
//{
//    mShaderProgram = new fiene::ShaderProgram();
//    mShaderProgram->compileVertexShader("Shaders/basicShader.vert");
//    mShaderProgram->compileFragmentShader("Shaders/basicShader.frag");
//    mShaderProgram->addAttribute("vertexPosition");
//    mShaderProgram->addAttribute("vertexColor");
//    mShaderProgram->addAttribute("vertexUV");
//    mShaderProgram->linkShaders();
//}
//
//void MainGame::gameLoop()
//{
//
//    //Main game loop
//    while ( mCurrentState != GameStates::TERMINATE)
//    {
//        mFpsLimiter.begin();
//        processInput();
//
//
//        drawGame();
//        mFpsLimiter.end();
//    }
//
//}
//
//void MainGame::processInput()
//{
//    mInputMngr.update();
//
//    if ( mInputMngr.isKeyPressed(SDLK_ESCAPE))
//        mCurrentState = GameStates::TERMINATE;
//    if ( mInputMngr.getEventHandler()->type == SDL_QUIT)
//        mCurrentState = GameStates::TERMINATE;
//}
//
//void MainGame::drawGame()
//{
//    mWindow.blankScreen();
//    mShaderProgram->useGLSLProgram();
//    glActiveTexture(GL_TEXTURE0);
//    mCamera.update();
//
//    GLint textureUniform = mShaderProgram->getUniformLocation("mySampler");
//    glUniform1i(textureUniform, 0);
//
//    //Grab the camera matrix
//    glm::mat4 projectionMatrix = mCamera.getCameraMatrix();
//    GLint pUniform = mShaderProgram->getUniformLocation("P");
//    glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);
//
//    mSpriteBatch.begin();
//    mSnake.render(mSpriteBatch);
//    mSpriteBatch.end();
//    mSpriteBatch.render();
//
//    //mSnake.update();
//    mShaderProgram->unuseGLSLProgram();
//    mWindow.swapBuffer();
//}
//
//
//
