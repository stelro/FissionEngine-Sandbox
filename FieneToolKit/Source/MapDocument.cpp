//
// Created by stel on 26/5/2017.
//

#include "MapDocument.hpp"

namespace Editor {

    MapDocument::MapDocument()
    {

    }

    MapDocument::~MapDocument()
    {

    }

    bool MapDocument::create(Fiene::Map* map)
    {
        m_Map = map;
    }

    void MapDocument::destroy()
    {

    }

}


