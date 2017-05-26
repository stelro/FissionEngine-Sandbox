//
// Created by stel on 25/5/2017.
//

#include "MapEditor.hpp"
#include "../imgui/imgui.h"
#include <Engine/Math/Vector.hpp>
#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/Utils/FDebug.hpp>

using Fiene::iVec2;
using Fiene::iVec4;
using Fiene::infoLog;

namespace Editor {

    MapEditor::MapEditor()
        : m_WindowIsOpen(true)
    {

    }

    MapEditor::~MapEditor()
    {

    }

    void MapEditor::create(Fiene::TexturesManager* texturesManager)
    {
        m_TexturesManager = texturesManager;

        m_TexturesManager->load("Assets/mhouse.png");


    }

    void MapEditor::destroy()
    {

    }

    void MapEditor::render()
    {

        ImGui::SetNextWindowSize(Fiene::iVec2(400,400), ImGuiSetCond_FirstUseEver);
        ImGui::Begin("Map Editor", &m_WindowIsOpen);
        {
            //ImGui::Image((GLuint *)m_TexturesManager->getTextureID("Assets/mhouse.png"), iVec2(400,400));
            drawGrid();

            ImDrawList *draw_list = ImGui::GetWindowDrawList();

            static float sz = 36.0f;
            static ImVec4 col = ImVec4(1.0f,1.0f,0.4f,1.0f);
            const ImVec2 p = ImGui::GetCursorScreenPos();
            const ImU32 col32 = ImColor(col);
            float x = p.x + 4.0f, y = p.y + 4.0f, spacing = 8.0f;
            float thickness = 4.0f;


            draw_list->AddLine(ImVec2(20, 20), ImVec2(x+sz, y+sz), col32, thickness);
        }

        ImGui::End();
    }

    void MapEditor::createContext()
    {

    }

    void MapEditor::drawGrid()
    {

    }

    void MapEditor::drawXYAxis()
    {

    }

}


