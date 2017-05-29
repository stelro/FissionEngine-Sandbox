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

#ifndef FISSIONENGINE_IOMANAGER_HPP
#define FISSIONENGINE_IOMANAGER_HPP

//Engine Internal


//C++ Includes
#include <string>
#include <vector>

namespace Fiene {

    class IOManager {

    public:

        static void iostreamInit();
        //Reads chars from string filepath, to passed vector buffer
        static bool readFileToBuffer(const std::string& filePath, std::vector<unsigned char>& t_buffer);
        //Reads chars from string filepath, to passed string buffer
        static bool readFileToBuffer(const std::string& filePath, std::string& t_buffer);
        //Loads PNG Image as binary format for the GPU
       // static Texture* loadPNG(const std::string& filePath);
        static void iostreamLogOutput(const char* message, ...);
        static void iostreamErrorOutput(const char* message, ...);
        static void iostreamGlLogParamsOutput();

    };

}


#endif //FISSIONENGINE_IOMANAGER_HPP
