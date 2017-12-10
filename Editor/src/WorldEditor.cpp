//
// Created by stel on 30/12/2016.
//

#include "WorldEditor.hpp"
#include "../imgui/imgui.h"
#include <Engine/ShaderProgram.hpp>
#include <Engine/SpriteBatch.hpp>
#include <Engine/Camera2D.hpp>
#include <Engine/ResourceManager.hpp>
#include <Engine/FDebug.hpp>
#include <Engine/InputManager.hpp>

namespace fiene {

    WorldEditor::WorldEditor()
    {
        mShaderProgram = new fiene::ShaderProgram();
        mShaderProgram->compileVertexShader("Shaders/ObjectShader.vert");
        mShaderProgram->compileFragmentShader("Shaders/ObjectShader.frag");
        mShaderProgram->addAttribute("vertexPosition");
        mShaderProgram->addAttribute("vertexColor");
        mShaderProgram->addAttribute("vertexUV");
        mShaderProgram->linkShaders();

        mSpriteBatch = new SpriteBatch();
        mSpriteBatch->init();

        mCamera = new Camera2D();
        mCamera->startUp(350,560);

        mInputHandler = new InputManager();
        mInputHandler->startUp();

    }

    WorldEditor::~WorldEditor()
    {

    }

    void WorldEditor::show()
    {

        GLuint aha = fiene::ResourceManager::getTextureId("Textures/castle.png");
        GLuint *textureId = &aha;

        fiene::Vec4 destRect(0,0,300,300);
        fiene::Vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

        mCamera->update();
        mShaderProgram->useGLSLProgram();

        GLint textureUniform = mShaderProgram->getUniformLocation("mySampler");
        glUniform1i(textureUniform, 0);

        //Grab the camera matrix
        glm::mat4 projectionMatrix = mCamera->getCameraMatrix();
        //fiene::Matrix4 projectionMatrix = fiene::camera.getCameraMatrix();
        GLint pUniform = mShaderProgram->getUniformLocation("P");
        glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);



        const float cam_offset = 20.0f;

        static bool ui = true;
        if (ImGui::Begin("Test!", &ui, ImVec2(200, 200)))
        {
            ImGui::Text("Hello, world!");

//            mSpriteBatch->begin();
//            mSpriteBatch->append(destRect, uvRect,textureId, 0.0f, fiene::Color(255,255,255,255));
//            mSpriteBatch->end();
//            mSpriteBatch->render();
            ImGui::Image(textureId,ImVec2(300,300), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImColor(255,255,255,255));
        }
        ImGui::End();



        mInputHandler->update();

        if (mInputHandler->isKeyHold(SDLK_w)) {
            mCamera->setCamOffset(0, cam_offset);
        }
        if (mInputHandler->isKeyHold(SDLK_s)) {
            mCamera->setCamOffset(0,-cam_offset);
        }
        if (mInputHandler->isKeyHold(SDLK_d)) {
            mCamera->setCamOffset(cam_offset, 0);
        }
        if (mInputHandler->isKeyHold(SDLK_a)) {
            mCamera->setCamOffset(-cam_offset, 0);
        }
        if (mInputHandler->isKeyHold(SDLK_r)) {
            mCamera->setScaleOffset(0.2f);
        }
        if (mInputHandler->isKeyHold(SDLK_q)) {
            mCamera->setScaleOffset(-0.2f);
        }

        ImGui::SetNextWindowSize(ImVec2(350,560), ImGuiSetCond_FirstUseEver);
        if (!ImGui::Begin("World Editor", nullptr))
        {
            ImGui::End();
            return;
        }



        mCamera->update();
        mShaderProgram->unuseGLSLProgram();

        ImGui::End();

    }

    void WorldEditor::generateOrthoMap()
    {

    }

}



