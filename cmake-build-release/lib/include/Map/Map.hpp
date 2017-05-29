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

#ifndef PROJECT_MAP_HPP
#define PROJECT_MAP_HPP

//Engine Internal
#include "TileSet.hpp"

//C++ Includes
#include <string>
#include <vector>


namespace Fiene {

    class TexturesManager;

    enum class MapOrientation {

        Orientation_None    = 0x0,
        Orthogonal          = 0x2,
        Isometric           = 0x4
    };

    class Map {
    public:
        Map();
        ~Map();

        void create(const std::string& mapName,
                    const int mapWidth,
                    const int mapHeight,
                    const int tileWidth,
                    const int tileHeight,
                    MapOrientation mapOrientation,
                    TexturesManager* texturesManager

        );

        void destory();

        std::string             getName() const                     { return m_mapName; }
        int                     getMapWidth() const                 { return m_MapWidth; }
        int                     getMapHeight() const                { return m_MapHeight; }
        int                     getTileWidth() const                { return m_TileWidth; }
        int                     getTileHeight() const               { return m_TileHeight; }
        MapOrientation          getOrientation() const              { return m_MapOrientation; }
        TexturesManager*        getTexturesManager() const          { return m_TexturesManager; }

    private:

        std::string             m_mapName;
        int                     m_MapWidth;
        int                     m_MapHeight;
        int                     m_TileWidth;
        int                     m_TileHeight;
        MapOrientation          m_MapOrientation;

        TexturesManager*        m_TexturesManager;


    };



}


#endif //PROJECT_MAP_HPP
