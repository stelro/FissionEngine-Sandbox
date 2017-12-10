#include "../imgui/imgui.h"


#include "AssetsBrowser.h"


AssetsBrowser::AssetsBrowser() {

}

AssetsBrowser::~AssetsBrowser() {

}

void AssetsBrowser::render()
{
    bool m_is_opened = true;
    bool m_activate = true;

    if (!ImGui::BeginDock("Asset Browser", &m_is_opened))
    {
        if (m_activate) ImGui::SetDockActive();
        m_activate = false;
        ImGui::EndDock();
        return;
    }
}



