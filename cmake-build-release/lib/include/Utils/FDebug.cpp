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
#include "FDebug.hpp"

//SDL2 Includes
#include <SDL2/SDL.h>

//C++ Includes
#include <cstdarg>


namespace Fiene {

    void debugLog(const char* format, ...) {

        va_list args;
        va_start(args,format);
        SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG, format, args);
        va_end(args);

    }//debugLog

    void infoLog(const char* format, ...) {

        va_list args;
        va_start(args,format);
        SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, format, args);
        va_end(args);

    }//infoLog

    void errorLog(const char* format, ...) {

        va_list args;
        va_start(args,format);
        SDL_LogMessageV(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, format, args);
        va_end(args);

    }//errorLog

    void Exit(int t_errorCode /* = 1 */ ) {

        //TODO: Shut down the entier engine first
        SDL_Quit();
        exit(t_errorCode);

    }//Error

    void errorDialog(const char* errorMsg) {

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fission Engine ", errorMsg, nullptr);

    }//errorDialog

}



