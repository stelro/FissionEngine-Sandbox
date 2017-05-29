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
#include "lua_script_manager.hpp"


namespace Fiene {

    typedef std::map<std::string, Lua_script* > m_LuaScriptCacheContainer;
    m_LuaScriptCacheContainer Lua_script_manager::m_Cache;

    Lua_script_manager::Lua_script_manager()
    {

    }

    Lua_script_manager::~Lua_script_manager()
    {

    }


    Lua_script *Lua_script_manager::lookup(const std::string &scriptName)
    {
        auto it = m_Cache.find(scriptName);
        if (it != m_Cache.end()) {
            it->second->ref();
            return it->second;
        }

        return nullptr;
    }

    void Lua_script_manager::store(const std::string& scriptName,const std::string& pathName, sol::state* state)
    {
        auto it = m_Cache.find(scriptName);
        if ( it != m_Cache.end()) {
            return;
        }

        Lua_script* tmp = new Lua_script(scriptName, pathName);
        tmp->script = state->load_file(pathName);
        m_Cache[scriptName] = tmp;

    }

    void Lua_script_manager::remove(const std::string &scriptName)
    {
        auto it = m_Cache.find(scriptName);
        if (it != m_Cache.end()) {
            delete it->second;
            m_Cache.erase(it);
        }
    }

    void Lua_script_manager::remove(Lua_script *script)
    {
        auto it = m_Cache.begin();
        while ( it != m_Cache.end() ) {
            if ( it->second == script ) {
                break;
            }

            ++it;
        }

        if ( it != m_Cache.end() ) {
            delete it->second;
            m_Cache.erase(it);
        }
    }

    void Lua_script_manager::removeAll()
    {
        auto it = m_Cache.begin();
        while ( it != m_Cache.end() ) {
            remove(it->second);
            it = m_Cache.begin();
        }
    }

    size_t Lua_script_manager::size()
    {
        return m_Cache.size();
    }


}



