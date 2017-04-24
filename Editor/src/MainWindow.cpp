//
// Created by stel on 29/12/2016.
//

#include "Engine/Engine.hpp"
#include "MainWindow.hpp"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <Engine/Utils/FDebug.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/Core/Window.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include "imgui_impl_sdl_gl3.h"
#include "../imgui/imgui.h"
#include <Engine/Engine.hpp>
#include <Engine/2D/Light2D.hpp>




namespace fiene {

    static const char* ImGui_ImplSdlGL3_GetClipboardText(void*)
    {
        return SDL_GetClipboardText();
    }

    static void ImGui_ImplSdlGL3_SetClipboardText(void*, const char* text)
    {
        SDL_SetClipboardText(text);
    }


    MainWindow::MainWindow()
        : mTerminate(false)
    {

        Fiene::EngineCore::initialize();


        SDL_DisplayMode currentDisplayMode;
        SDL_GetCurrentDisplayMode(0, &currentDisplayMode);


        mWindow = new Fiene::Window();
        mWindow->startUp("Fiene ToolKit", currentDisplayMode.w, currentDisplayMode.h, Fiene::WINDOW_RESIZABLE);
        mCamera.startUp(currentDisplayMode.w, currentDisplayMode.h);


        ImGui_ImplSdlGL3_Init(mWindow->getWindow());


    }

    MainWindow::~MainWindow()
    {
        delete mWindow;

    }

    void MainWindow::execute()
    {

        mWindow->setBackgroundColorRGB(255,255,255, 255);


        const float cam_offset = 20.0f;
        while (!mTerminate) {

            mWindow->blankScreen();

            mCamera.update();

            glActiveTexture(GL_TEXTURE0);

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                ImGui_ImplSdlGL3_ProcessEvent(&event);
                if (event.type == SDL_QUIT)
                    mTerminate = true;
            }

            ImGui_ImplSdlGL3_NewFrame(mWindow->getWindow());
            ImGui::ShowTestWindow();


            // Rendering
            glViewport(0, 0, (int) ImGui::GetIO().DisplaySize.x, (int) ImGui::GetIO().DisplaySize.y);

            ImGui::Render();

            mCamera.update();

            mWindow->swapBuffer();

        }
    }





}


