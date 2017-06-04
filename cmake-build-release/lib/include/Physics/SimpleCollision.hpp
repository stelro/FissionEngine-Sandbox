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

#ifndef PROJECT_SIMPLECOLLISION_HPP
#define PROJECT_SIMPLECOLLISION_HPP

//Engine Internal
#include "Utils/Utils.hpp"

namespace Fiene {

    class SimpleCollision {
    public:
        SimpleCollision();
        ~SimpleCollision();
        bool AABBCollision(const Rect& a, const Rect& b);
    private:

    };

}


#endif //PROJECT_SIMPLECOLLISION_HPP