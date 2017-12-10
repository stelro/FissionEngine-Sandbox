//
// Created by stel on 25/5/2017.
//

//ToolKit Internal
#include "MapEditor.hpp"
#include "MapDocument.hpp"

//Engine Includes
#include <Engine/Math/Vector.hpp>
#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/Utils/FDebug.hpp>
#include <Engine/Map/Map.hpp>

//ImGui Includes
#include <Engine/External/imgui/imgui.h>

//C++ Includes
#include <algorithm>


using Fiene::iVec2;
using Fiene::iVec4;
using Fiene::infoLog;

namespace Editor {

    MapEditor::MapEditor()
        : m_WindowIsOpen(true)
        , m_DebugPopUpIsOpen(true)
        , m_TexturesManager(nullptr)
        , m_DocumentName("")
    {

    }

    MapEditor::~MapEditor()
    {

    }

    void MapEditor::create(MapDocument* mapDocument)
    {
        m_MapDocument = mapDocument;
        m_TexturesManager = m_MapDocument->getMap()->getTexturesManager();
        m_DocumentName = m_MapDocument->getMap()->getName();

        if (m_DocumentName == "") {
            m_DocumentName = "Untitled";
        }

        m_TexturesManager->load("Assets/Stones.png");

        m_ShaderProgram.startUp();
        m_ShaderProgram.compileVertexShader("Shaders/vertex.glsl");
        m_ShaderProgram.compileFragmentShader("Shaders/fragment.glsl");
        m_ShaderProgram.linkShaders();

        m_SpriteBatch.startUp();
        m_Camera.startUp((int)ImGui::GetWindowSize().x, (int)ImGui::GetWindowSize().y);

    }

    void MapEditor::destroy()
    {

    }

    void MapEditor::render()
    {

        ImGui::SetNextWindowSize(Fiene::iVec2(400,400), ImGuiSetCond_FirstUseEver);
        if(!ImGui::Begin(m_DocumentName.c_str(), &m_WindowIsOpen))
        {
            ImGui::End();
            return;
        }

        placeTiles();
        drawTiles();
        drawGrid();


        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(40,40));
        if (!ImGui::Begin("Fiene Debug", &m_DebugPopUpIsOpen, ImVec2(0,0), 0.5f,
                                  ImGuiWindowFlags_NoTitleBar |
                                  ImGuiWindowFlags_NoResize   |
                                  ImGuiWindowFlags_NoSavedSettings ))
        {
            ImGui::End();
            return;
        }


        ImGui::Text("Fiene Debug");
        ImGui::Separator();
        ImGui::Text("Map Width: %d", m_MapDocument->getMap()->getMapWidth());
        ImGui::Text("Map Height: %d", m_MapDocument->getMap()->getMapHeight());
        ImGui::Text("Tile Width: %d", m_MapDocument->getMap()->getTileWidth());
        ImGui::Text("Tile Height: %d", m_MapDocument->getMap()->getTileHeight());
        ImGui::Text("Textures Cashed: %d", m_TexturesManager->size());
        ImGui::Text("Mouse Position: (%.1f,%.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
        ImGui::End();
    }

    void MapEditor::createContext()
    {

    }

    void MapEditor::drawGrid()
    {
        ImDrawList *draw_list = ImGui::GetWindowDrawList();


        const ImVec2 p = ImGui::GetCursorScreenPos();
        const ImU32 col32 = ImColor(224,224,224,100);
        float x = p.x, y = p.y;

        const int tile_width = m_MapDocument->getMap()->getTileWidth();
        const int tile_height = m_MapDocument->getMap()->getTileHeight();

        const int map_width = m_MapDocument->getMap()->getMapWidth();
        const int map_height = m_MapDocument->getMap()->getMapHeight();


        ImVec2 win_size = ImGui::GetWindowSize();
        int a = static_cast<int>((win_size.x / 2) -((tile_width * map_width) / 2 ) );
        int b = static_cast<int>((win_size.y / 2) - ((tile_height * map_height) / 2) );


        for ( auto i = 0; i < map_width; i++) {

            for (auto j = 0; j < map_height; j++) {

                draw_list->AddRect(ImVec2(a+x+i * tile_width, b+y+j * tile_height),
                                   ImVec2(a+x+tile_width + i * tile_width, b+y+tile_height + j * tile_height),
                                   col32,
                                   0.0f,
                                   ~0,
                                   0.1f
                );
            }
        }


    }

    void MapEditor::drawXYAxis()
    {

    }

    void MapEditor::drawTiles()
    {
        ImDrawList *draw_list = ImGui::GetWindowDrawList();

        const ImVec2 p = ImGui::GetCursorScreenPos();
        float x = p.x, y = p.y;

        for ( auto &i : m_Tiles) {
            iVec2 a = iVec2((int)((i->topLeft.x)), (int)( ( i->topLeft.y )));
            iVec2 b = iVec2((int)((i->bottomRight.x)), (int)((i->bottomRight.y)));
            draw_list->AddImage((GLuint*)i->texture, a, b);
        }


    }

    void MapEditor::placeTiles()
    {
        ImDrawList *draw_list = ImGui::GetWindowDrawList();

        GLuint texture = m_TexturesManager->getTextureID("Assets/Stones.png");


        const ImVec2 p = ImGui::GetCursorScreenPos();
        float x = p.x, y = p.y;

        const int tile_width = m_MapDocument->getMap()->getTileWidth();
        const int tile_height = m_MapDocument->getMap()->getTileHeight();

        const int map_width = m_MapDocument->getMap()->getMapWidth();
        const int map_height = m_MapDocument->getMap()->getMapHeight();


        ImVec2 win_size = ImGui::GetWindowSize();
        int half_sz_x = static_cast<int>((win_size.x / 2) -((tile_width * map_width) / 2 ) );
        int half_sz_y = static_cast<int>((win_size.y / 2) - ((tile_height * map_height) / 2) );

        int mouseX = (int)ImGui::GetIO().MousePos.x;
        int mouseY = (int)ImGui::GetIO().MousePos.y;


        if(ImGui::IsMouseClicked(0)) {

            if (  ((mouseX >= x + half_sz_x) && (mouseX <= x + half_sz_x + (tile_width * map_width))) &&
                    ((mouseY >= y + half_sz_y) && (mouseY <= y + half_sz_y + (tile_height * map_height)))) {

                Cell *cell = new Cell();
                cell->texture = texture;
                int a = 0;
                int b = 0;

                a = 32 - (mouseX % 32);
                b = 32 - (mouseY % 32);

                ImGui::SetCursorPos(ImVec2(a + mouseX, b + mouseY));

                cell->topLeft = iVec2((int) (a + mouseX), (int) (b + mouseY));
                cell->bottomRight = iVec2((int) (a + mouseX + tile_width), (int) (b + mouseY + tile_height));


                m_Tiles.push_back(cell);
            }
        }

    }

}


