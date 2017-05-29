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

#ifndef PROJECT_LUA_SCRIPT_SYSTEM_HPP
#define PROJECT_LUA_SCRIPT_SYSTEM_HPP

//C++ Includes
#include <string>

//Engine External
#include "External/sol.hpp"

namespace Fiene {

    typedef sol::table luaTable;

    class Lua_script_manager;

    class Lua_script_system {

    public:

        static Lua_script_system* Instance();
        static void Destroy();

        template<class T>
        decltype(auto) operator[](const T& t) const {
            return m_luaState[t];
        }

        void                    addScript(const std::string &scriptName, const std::string &filePath);
        void                    removeScript(const std::string& scriptName);
        void                    exec(const std::string& scriptName) const;
        size_t                  size() const;
        const sol::state&       state() const                   { return m_luaState; }

        template<class T> T get(const std::string& name) {
            return m_luaState.get<T>(name);
        }

    private:
        static Lua_script_system*                       m_Instance;
        Lua_script_system();
        ~Lua_script_system();
        Lua_script_manager*                             m_CacheManager;
        sol::state                                      m_luaState;


    };

}


#endif //PROJECT_LUA_SCRIPT_SYSTEM_HPP
