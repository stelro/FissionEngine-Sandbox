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
#ifndef PROJECT_FPSLIMITER_HPP
#define PROJECT_FPSLIMITER_HPP

namespace Fiene {

    class FpsLimiter {

    public:

        FpsLimiter();
        void init(const float maxFps);
        void setMaxFps(const float maxFps);
        void begin();
        void end();
        float getCurrentFps() const;

    private:

        void                calucalteFPS();

        float               m_Fps;
        float               m_MaxFps;
        float               m_FrameTime;
        unsigned int        m_StartTicks;
    };

}


#endif //PROJECT_FPSLIMITER_HPP
