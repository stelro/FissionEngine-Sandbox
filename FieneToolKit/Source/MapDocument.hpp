//
// Created by stel on 26/5/2017.
//

#ifndef PROJECT_MAPDOCUMENT_HPP
#define PROJECT_MAPDOCUMENT_HPP

#include <Engine/Map/Map.hpp>

namespace Editor {

    class MapDocument {
    public:
        MapDocument();
        ~MapDocument();

        bool create();
        void destroy();

    private:

        Fiene::Map m_Map;

    };

}


#endif //PROJECT_MAPDOCUMENT_HPP
