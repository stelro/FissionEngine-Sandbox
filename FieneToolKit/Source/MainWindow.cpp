
//ToolKit Internal
#include "MainWindow.hpp"
#include "MapEditor.hpp"
#include "MapDocument.hpp"
#include "AssetsBrowser.hpp"

//Fiene Engine
#include <Engine/Engine.hpp>
#include <Engine/Utils/FDebug.hpp>
#include <Engine/Core/InputManager.hpp>
#include <Engine/Core/Window.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/Allocators/FreeListAllocator.hpp>
#include <Engine/Allocators/PoolAllocator.hpp>
#include <Engine/Resources/Texture.hpp>
#include <Engine/Map/Map.hpp>
#include <Engine/Allocators/ProxyAllocator.hpp>

//SDL2 Inlcudes
#include <SDL2/SDL.h>

//OpenGL Includes
#include <GL/glew.h>

//ImGui Includes
#include <Engine/External/imgui/imgui.h>
#include <Engine/External/imgui/imgui_impl_sdl_gl3.hpp>


namespace Editor {

    static const char* ImGui_ImplSdlGL3_GetClipboardText(void*)             { return SDL_GetClipboardText(); }
    static void ImGui_ImplSdlGL3_SetClipboardText(void*, const char* text)  { SDL_SetClipboardText(text); }

    MainWindow::MainWindow()
        : m_CreateNewLevel_Signal(false)
        , m_ShowLevelEditor_Signal(false)
        , m_ShowAssetsBrowser_Signal(true)
    {
        //Empty
    }

    MainWindow::~MainWindow()
    {
        //Empty
    }

    void MainWindow::run()
    {
        init();


        //Main Loop
        while (m_IsRunning) {

            m_Window->blankScreen();


            glActiveTexture(GL_TEXTURE0);

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                ImGui_ImplSdlGL3_ProcessEvent(&event);
                if (event.type == SDL_QUIT)
                    m_IsRunning = false;
            }

            ImGui_ImplSdlGL3_NewFrame(m_Window->getWindow());
            ImGui::ShowTestWindow();

            //Show Main Menu Bar
            showMenuBar();

            if (m_CreateNewLevel_Signal)
                createNewLevel();
            if (m_ShowLevelEditor_Signal) {
                m_MapEditorWindow->render();
            }

            if (m_ShowAssetsBrowser_Signal) {
                m_AssetsBrowser->render();
            }


            // Rendering
            glViewport(0, 0, (int) ImGui::GetIO().DisplaySize.x, (int) ImGui::GetIO().DisplaySize.y);

            ImGui::Render();



            m_Window->swapBuffer();

        }

        destroy();
    }

    void MainWindow::init()
    {
        m_IsRunning = true;

        Fiene::EngineCore::initialize();

        SDL_DisplayMode currentDisplayMode;
        SDL_GetCurrentDisplayMode(0, &currentDisplayMode);


        m_Window = new Fiene::Window();
        m_Window->startUp("Fiene ToolKit", currentDisplayMode.w, currentDisplayMode.h, Fiene::WINDOW_RESIZABLE);
        //mCamera.startUp(currentDisplayMode.w, currentDisplayMode.h);
        m_Window->setBackgroundColorRGB(255,255,255, 255);

        ImGui_ImplSdlGL3_Init(m_Window->getWindow());

        /* Memory Configuration */

        m_PMemory = malloc(ONEGIG_SIZE);
        m_FreeListAllocator = new Fiene::FreeListAllocator(ONEGIG_SIZE, m_PMemory);
        m_ProxyAllocator = Fiene::newProxyAllocator(*m_FreeListAllocator);

        m_TexturesManager = Fiene::TexturesManager::create(*m_ProxyAllocator);

        m_AssetsBrowser = new AssetsBrowser();
        m_AssetsBrowser->create(m_TexturesManager);

    }

    void MainWindow::destroy()
    {
        // Cleanup
        ImGui_ImplSdlGL3_Shutdown();
        m_MapEditorWindow->destroy();
        delete m_Window;
        Fiene::EngineCore::terminate();
    }

    void MainWindow::showMenuBar()
    {

        if (ImGui::BeginMainMenuBar()) {

            if (ImGui::BeginMenu("File")) {
                ImGui::MenuItem("New", nullptr, &m_CreateNewLevel_Signal);
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Edit")) {
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Options")) {
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help")) {
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

    }

    void MainWindow::createNewLevel()
    {

        ImGui::OpenPopup("New Level");

        if (ImGui::BeginPopupModal("New Level", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {

            static char strName[128] = "Untitled";
            static int map_width_tiles = 3;
            static int map_height_tiles = 3;
            static int tile_width = 32;
            static int tile_height = 32;
            static int orientation = 0;
            static Fiene::MapOrientation orientation_enum =
                    Fiene::MapOrientation::Orientation_None;

            ImGui::Text("Map Settings:");
            ImGui::InputText("Map Name", strName, sizeof(strName));
            ImGui::Text("Tiles:");
            ImGui::SameLine();
            ImGui::InputInt("Width", &map_width_tiles);
            ImGui::Text("Tiles:");
            ImGui::SameLine();
            ImGui::InputInt("Height", &map_height_tiles);
            ImGui::Separator();
            ImGui::Text("Tiles Settings:");
            ImGui::InputInt("Tile Width", &tile_width);
            ImGui::InputInt("Tile Height", &tile_height);
            ImGui::Combo("Orientation", &orientation, "Orthogonal\0Isometric\0\0");
            ImGui::Separator();

            int map_width = map_width_tiles * tile_width;
            int map_height = map_height_tiles * tile_height;

            ImGui::Text("(%d x %d)", map_width, map_height);

            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0,0));
            ImGui::PopStyleVar();

            if (ImGui::Button("Craete", ImVec2(120,0))) {

                /* Creating the Map Document */

                if (orientation == 0){
                    orientation_enum = Fiene::MapOrientation::Orthogonal;
                } else {
                    orientation_enum = Fiene::MapOrientation::Isometric;
                }

                Fiene::Map* map = new Fiene::Map();

                map->create(strName,
                            map_width_tiles,
                            map_height_tiles,
                            tile_width,
                            tile_height,
                            orientation_enum,
                            m_TexturesManager );

                MapDocument* mapDocument = new MapDocument();
                mapDocument->create(map);
                m_MapEditorWindow = new MapEditor();
                m_MapEditorWindow->create(mapDocument);
                m_ShowLevelEditor_Signal = true;


                ImGui::CloseCurrentPopup();
                m_CreateNewLevel_Signal = false;

            }

            ImGui::SameLine();
            if (ImGui::Button("Cancel", ImVec2(120,0))) {
                ImGui::CloseCurrentPopup();
                m_CreateNewLevel_Signal = false;
            }

            ImGui::EndPopup();
        }
    }

}
