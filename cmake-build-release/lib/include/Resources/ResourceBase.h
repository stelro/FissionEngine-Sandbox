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
#ifndef PROJECT_RESOURCE_H
#define PROJECT_RESOURCE_H

//C++ Includes
#include <cstddef>
#include <string>

namespace Fiene {

    class ResourceBase {
    public:
                                        ResourceBase(const std::string& fileName);
        virtual                         ~ResourceBase();

        virtual void                    ref() final;
        virtual void                    unref() final;
        virtual size_t                  getCounter() const final;
        std::string                     getName() const ;

    protected:
        size_t                          m_ReferenceCounter;
        std::string                     m_FileName;
    };

}


#endif //PROJECT_RESOURCE_H
