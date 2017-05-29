//
// Created by stel on 25/5/2017.
//

#ifndef PROJECT_MAPEDITOR_HPP
#define PROJECT_MAPEDITOR_HPP

#include <string>
#include <vector>

#include <Engine/Resources/Texture.hpp>
#include <Engine/Math/Vector.hpp>
#include <Engine/GLSL/ShaderProgram.hpp>
#include <Engine/2D/SpriteBatch.hpp>
#include <Engine/2D/Camera2D.hpp>

namespace Fiene {
    class TexturesManager;
}

namespace Editor {

    class MapDocument;

    struct Cell {
        GLuint texture;
        Fiene::iVec2 topLeft;
        Fiene::iVec2 bottomRight;
    };

    class MapEditor {
    public:
        MapEditor();
        ~MapEditor();

        void create(MapDocument* mapDocument);
        void destroy();
        void render();

        void drawGrid();
        void drawXYAxis();

    private:

        void createContext();
        void drawTiles();
        void placeTiles();

    private:
        bool m_WindowIsOpen;
        bool m_DebugPopUpIsOpen;

        Fiene::TexturesManager* m_TexturesManager;
        MapDocument*    m_MapDocument;
        std::string m_DocumentName;

        Fiene::ShaderProgram m_ShaderProgram;
        Fiene::SpriteBatch m_SpriteBatch;
        Fiene::Camera2D m_Camera;


        std::vector<Cell*> m_Tiles;

    };

}

#endif //PROJECT_MAPEDITOR_HPP
