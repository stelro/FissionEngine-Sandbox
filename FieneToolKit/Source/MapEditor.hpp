//
// Created by stel on 25/5/2017.
//

#ifndef PROJECT_MAPEDITOR_HPP
#define PROJECT_MAPEDITOR_HPP

namespace Fiene {
    class TexturesManager;
}

namespace Editor {

    class MapDocument;

    class MapEditor {
    public:
        MapEditor();
        ~MapEditor();

        void create(Fiene::TexturesManager* texturesManager);
        void destroy();
        void render();

        void drawGrid();
        void drawXYAxis();

    private:

        void createContext();

    private:
        bool m_WindowIsOpen;

        Fiene::TexturesManager* m_TexturesManager;
        MapDocument*    m_MapDocument;

    };

}

#endif //PROJECT_MAPEDITOR_HPP
