/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//Engine Internal
#include "Map.hpp"
#include "TilesetLayer.hpp"
#include "CollisionLayer.hpp"
#include "ObjectLayer.hpp"
#include "Core/Core.h"
#include "TileSet.hpp"
#include "Lua/lua_script_system.hpp"
#include "Resources/Texture.hpp"

//C++ Includes
#include <iostream>
#include <fstream>

namespace Fiene {

    Map::Map()
        : m_mapName("")
        , m_MapWidth(0)
        , m_MapHeight(0)
        , m_TileWidth(0)
        , m_TileHeight(0)
        , m_MapOrientation(MapOrientation::Orientation_None)
        , m_TexturesManager(nullptr)
    {

    }

    Map::~Map()
    {
        //Empty
    }


    void Map::create(const std::string &mapName,
                     const int mapWidth,
                     const int mapHeight,
                     const int tileWidth,
                     const int tileHeight,
                     MapOrientation mapOrientation,
                     TexturesManager* texturesManager) {

        m_mapName = mapName;
        m_MapWidth = mapWidth;
        m_MapHeight = mapHeight;
        m_TileWidth = tileWidth;
        m_TileHeight = tileHeight;
        m_MapOrientation = mapOrientation;
        m_TexturesManager = texturesManager;


    }

    void Map::destory()
    {

    }

}



