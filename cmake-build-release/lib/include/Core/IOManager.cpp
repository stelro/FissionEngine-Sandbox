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
#include "IOManager.hpp"
#include "Utils/FDebug.hpp"
#include "2D/picoPNG.hpp"
#include "Resources/Texture.hpp"

//C++ Includes
#include <fstream>
#include <cstdarg>
#include <ctime>
#include <iostream>


namespace Fiene {

    bool IOManager::readFileToBuffer(const std::string &filePath, std::vector<unsigned char> &t_buffer)
    {
        //Open file in binary format
        std::ifstream file(filePath, std::ios::binary);
        if (file.fail()) {
            errorLog("File: %s faild to load!", filePath);
            perror(filePath.c_str());
        }

        //Seek to the end
        file.seekg(0, std::ios::end);

        //Get the file size
        long long int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        //Reduce the file size by any header bytes that might be present
        fileSize -= file.tellg();

        t_buffer.resize(static_cast<unsigned long>(fileSize));
        file.read((char *)(&(t_buffer[0])), fileSize);
        file.close();

        return true;
    }

    bool IOManager::readFileToBuffer(const std::string &filePath, std::string &t_buffer)
    {
        //Open file in binary format
        std::ifstream file(filePath, std::ios::binary);
        if (file.fail()) {
            errorLog("File: %s faild to load!", filePath);
            perror(filePath.c_str());
        }

        //Seek to the end
        file.seekg(0, std::ios::end);

        //Get the file size
        long long int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        //Reduce the file size by any header bytes that might be present
        fileSize -= file.tellg();

        t_buffer.resize(static_cast<unsigned long>(fileSize));
        file.read((char* )(&(t_buffer[0])), fileSize);
        file.close();

        return true;
    }

    void IOManager::iostreamInit()
    {
        std::ofstream infileLog("engine_log.log");
        if (!infileLog.is_open()) {
            errorLog("While opening engine_log.log file to read/write, %s %s %d\n",
                     __FILE__, __FUNCTION__, __LINE__);
            Exit(1);
        }

        time_t now = time(NULL);
        char *date = ctime(&now);
        infileLog << "Fission Engine Log File @ local time: " << date << "\n";
        infileLog.close();

        std::ofstream infileError("engine_error.log");
        if (!infileError.is_open()) {
            errorLog("While opening engine_error.log file to read/write, %s %s %d\n",
                     __FILE__, __FUNCTION__, __LINE__);
            Exit(1);
        }

        infileError << "Fission Engine Error File @ local time: " << date << "\n";
        infileError.close();
    }

    void IOManager::iostreamLogOutput(const char *message, ...)
    {
        va_list args;

        FILE* infile = fopen("engine_log.log", "a");

        if (!infile) {
            errorLog("While opening engine_log.log file to read/write, %s %s %d\n",
            __FILE__, __FUNCTION__, __LINE__);
            Exit(1);
        }

        va_start(args, message);
        vfprintf(infile, message, args);
        va_end(args);
        fclose(infile);

    }

    void IOManager::iostreamErrorOutput(const char *message, ...)
    {
        va_list args;

        FILE* infile = fopen("engine_error.log", "a");

        if (!infile) {
            errorLog("While opening engine_error.log file to read/write, %s %s %d\n",
                     __FILE__, __FUNCTION__, __LINE__);
            Exit(1);
        }

        va_start(args, message);
        fprintf(infile, "Error occurred in File: '%s' Function: '%s' Line: '%d'\n",__FILE__, __FUNCTION__, __LINE__);
        vfprintf(infile, message, args);
        va_end(args);
        fclose(infile);
    }

    void IOManager::iostreamGlLogParamsOutput()
    {
        GLenum params[] = {
                GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
                GL_MAX_CUBE_MAP_TEXTURE_SIZE,
                GL_MAX_DRAW_BUFFERS,
                GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,
                GL_MAX_TEXTURE_IMAGE_UNITS,
                GL_MAX_TEXTURE_SIZE,
                GL_MAX_VARYING_FLOATS,
                GL_MAX_VERTEX_ATTRIBS,
                GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
                GL_MAX_VERTEX_UNIFORM_COMPONENTS,
                GL_MAX_VIEWPORT_DIMS,
                GL_STEREO,
        };

        const char *names[] = {
                "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS",
                "GL_MAX_CUBE_MAP_TEXTURE_SIZE",
                "GL_MAX_DRAW_BUFFERS",
                "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS",
                "GL_MAX_TEXTURE_IMAGE_UNITS",
                "GL_MAX_TEXTURE_SIZE",
                "GL_MAX_VARYING_FLOATS",
                "GL_MAX_VERTEX_ATTRIBS",
                "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS",
                "GL_MAX_VERTEX_UNIFORM_COMPONENTS",
                "GL_MAX_VIEWPORT_DIMS",
                "GL_STEREO",
        };

        IOManager::iostreamLogOutput("GL Context Params: \n");
        for (int i = 0; i < 10; i++) {
            int v = 0;
            glGetIntegerv(params[i], &v);
            iostreamLogOutput("%s %i\n", names[i], v);
        }

        //others

        int v[2];
        v[0] = v[1] = 0;
        glGetIntegerv(params[10], v);
        IOManager::iostreamLogOutput("%s %i %i\n", names[10], v[0], v[1]);
        unsigned char s = 0;
        glGetBooleanv(params[11], &s);
        IOManager::iostreamLogOutput("%s %u\n", names[11], (unsigned int)s);
        IOManager::iostreamLogOutput("------------------------------------\n");
    }

}



