//
// Created by stel on 26/5/2017.
//

#ifndef PROJECT_MAPDOCUMENT_HPP
#define PROJECT_MAPDOCUMENT_HPP

namespace Fiene {
    class Map;
}

namespace Editor {

    class MapDocument {
    public:
        MapDocument();
        ~MapDocument();

        bool create(Fiene::Map* map);
        void destroy();

        Fiene::Map* getMap() const { return m_Map; }

    private:

        Fiene::Map* m_Map;

    };

}


#endif //PROJECT_MAPDOCUMENT_HPP
