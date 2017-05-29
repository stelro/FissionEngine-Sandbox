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

#ifndef PROJECT_LUA_SCRIPT_MANAGER_HPP
#define PROJECT_LUA_SCRIPT_MANAGER_HPP

//C++ Includes
#include <string>
#include <map>

//Engine External
#include "External/sol.hpp"

namespace Fiene {

    class Lua_script {
    public:
        Lua_script(const std::string& scriptName, const std::string& scriptPath)
            : m_ScriptName(scriptName)
            , m_ScriptPath(scriptPath)
            , m_Counter(1)
        {

        }

        ~Lua_script()
        {
            script = nullptr;
        }

        void                        exec()              { script(); }
        void                        ref()               { ++m_Counter; }
        void                        unref()             { --m_Counter; if (m_Counter == 0) { delete this; }  }

        size_t getCounter() const                       { return m_Counter; }

        sol::load_result                                script;
    private:

        std::string                 m_ScriptName;
        std::string                 m_ScriptPath;
        size_t                      m_Counter;

    };

    class Lua_script_manager {
    public:

        Lua_script_manager();
        ~Lua_script_manager();

        static Lua_script* lookup(const std::string& scriptName);
        static void store(const std::string& scriptName,const std::string& pathName, sol::state* state);
        static void remove(const std::string& scriptName);
        static void remove(Lua_script *script);
        static void removeAll();
        static size_t size();

    private:

        typedef std::map<std::string, Lua_script* >            m_LuaScriptCacheContainer;
        static m_LuaScriptCacheContainer                       m_Cache;
    };


}


#endif //PROJECT_LUA_SCRIPT_MANAGER_HPP
