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

#include <iostream>
#include "lua_script_system.hpp"
#include "lua_script_manager.hpp"


namespace Fiene {

    Lua_script_system* Lua_script_system::m_Instance;

    Lua_script_system::Lua_script_system()
        : m_CacheManager(new Lua_script_manager())
    {
        m_luaState.open_libraries(sol::lib::base, sol::lib::package);
    }

    Lua_script_system::~Lua_script_system()
    {
        delete m_CacheManager;
    }

    void Lua_script_system::addScript(const std::string &scriptName,const std::string &filePath)
    {
        m_CacheManager->store(scriptName, filePath, &m_luaState);
    }

    void Lua_script_system::removeScript(const std::string &scriptName)
    {
        m_CacheManager->remove(scriptName);
    }


    void Lua_script_system::exec(const std::string& scriptName) const
    {
        m_CacheManager->lookup(scriptName)->exec();
    }

    size_t Lua_script_system::size() const
    {
        return m_CacheManager->size();
    }

    Lua_script_system *Lua_script_system::Instance() {

        if (!m_Instance)
            m_Instance = new Lua_script_system();
        return m_Instance;

    }

    void Lua_script_system::Destroy() {

        if (m_Instance) {
            delete m_Instance;
            m_Instance = nullptr;
        }
        else {
            return;
        }
    }

}



