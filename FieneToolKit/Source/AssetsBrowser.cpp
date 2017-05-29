//
// Created by stel on 28/5/2017.
//



#include "AssetsBrowser.hpp"

#include "../imgui/imgui.h"

#include <Engine/Resources/TexturesManager.hpp>
#include <Engine/Utils/FDebug.hpp>

#include <vector>
#include <algorithm>

namespace Editor {

    AssetsBrowser::AssetsBrowser()
        : m_TexturesManager(nullptr)
        , m_WindowIsOpen(true)
        , m_TexturesAssetsSizeCounter(0)
    {

    }

    AssetsBrowser::~AssetsBrowser()
    {

    }

    void AssetsBrowser::create(Fiene::TexturesManager* texturesManager)
    {
        m_TexturesManager = texturesManager;


    }

    void AssetsBrowser::destroy()
    {

    }

    void AssetsBrowser::render()
    {
        ImGui::SetNextWindowSize(Fiene::iVec2(400,400), ImGuiSetCond_FirstUseEver);
        if(!ImGui::Begin("Assets Browser", &m_WindowIsOpen))
        {
            ImGui::End();
            return;
        }

        ImGui::End();
    }

    void AssetsBrowser::refreshTexturesArray()
    {
        std::vector<std::string> tmp{m_TexturesManager->getCacheNames()};



    }

}


