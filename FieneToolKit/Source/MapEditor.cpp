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
#include "../imgui/imgui.h"

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

        static float sz = 64.0f;
        static ImVec4 col = ImVec4(1.0f,1.0f,0.4f,1.0f);
        const ImVec2 p = ImGui::GetCursorScreenPos();
        const ImU32 col32 = ImColor(224,224,224,200);
        float x = p.x, y = p.y;
        float thickness = 1.0f;

        const ImVec2 snd = ImGui::GetWindowSize();

        const int tile_width = m_MapDocument->getMap()->getTileWidth();
        const int tile_height = m_MapDocument->getMap()->getTileHeight();

        const int map_width = m_MapDocument->getMap()->getMapWidth();
        const int map_height = m_MapDocument->getMap()->getMapHeight();

        int startX = std::max(0,(int)(p.x / tile_width) * tile_width);
        int startY = std::max(0,(int)(p.y / tile_height) * tile_height);

        int endX = std::min((int)std::ceil(snd.x), (map_width * tile_width + 1));
        int endY = std::min((int)std::ceil(snd.y), (map_height * tile_height + 1));

        for (int i = startX; i < endX; i += tile_width) {
            draw_list->AddLine(ImVec2(i, startY), ImVec2(i, endY - 1), col32);
        }

        for (int j = startY; j < endY; j += tile_height) {
            draw_list->AddLine(ImVec2(startX, j), ImVec2(endX - 1, j), col32);
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
            iVec2 a = iVec2((int)((i->topLeft.x + x) - x), (int)( ( i->topLeft.y + y) - y));
            iVec2 b = iVec2((int)((i->bottomRight.x + x)-x ), (int)((i->bottomRight.y + y) - y));
            draw_list->AddImage((GLuint*)i->texture, a, b);
        }

        if (ImGui::IsMouseClicked(0)) {
            infoLog("x: %f", x);
            infoLog("y: %f", y);
        }
    }

    void MapEditor::placeTiles()
    {
        ImDrawList *draw_list = ImGui::GetWindowDrawList();
        const int tile_width = m_MapDocument->getMap()->getTileWidth();
        const int tile_height = m_MapDocument->getMap()->getTileHeight();
        GLuint texture = m_TexturesManager->getTextureID("Assets/Stones.png");
        const ImVec2 p = ImGui::GetCursorScreenPos();
        float x = p.x, y = p.y;

        int mouseX = (int)ImGui::GetIO().MousePos.x;
        int mouseY = (int)ImGui::GetIO().MousePos.y;


        if(ImGui::IsMouseClicked(0)) {

            Cell* cell = new Cell();
            cell->texture = texture;
            cell->topLeft = iVec2((int)(mouseX), (int)(mouseY));
            cell->bottomRight = iVec2((int)(mouseX + tile_width),(int)(mouseY + tile_height ));



            m_Tiles.push_back(cell);
        }

    }

}


