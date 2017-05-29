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
#include "FpsLimiter.hpp"

//SDL2 Includes
#include <SDL2/SDL.h>

namespace Fiene {

    FpsLimiter::FpsLimiter()
        : m_Fps(0.0f)
        , m_MaxFps(0.0f)
        , m_FrameTime(0.0f)
        , m_StartTicks(0)
    { }

    void FpsLimiter::init(const float maxFps)
    {
        setMaxFps(maxFps);
    }

    void FpsLimiter::setMaxFps(const float maxFps)
    {
        m_MaxFps = maxFps;
    }

    void FpsLimiter::begin()
    {
        m_StartTicks = SDL_GetTicks();
    }

    void FpsLimiter::end()
    {
        calucalteFPS();

        float frameTicks = static_cast<float>(SDL_GetTicks() - m_StartTicks);

        //Limit the FPS to the max FPS
        if (1000.0f / m_MaxFps > frameTicks) {
            SDL_Delay(static_cast<Uint32> (1000.0f / m_MaxFps - frameTicks));
        }
    }

    float FpsLimiter::getCurrentFps() const
    {
        return m_Fps;
    }

    void FpsLimiter::calucalteFPS()
    {

        //The number of frames to average
        static const int NUM_SAMPLES = 10;
        //Stores all the frametimes for each frame that we will average
        static float frameTimes[NUM_SAMPLES];
        //The current frame we are on
        static int currentFrame = 0;
        //The ticks of the previous frame
        static Uint32 prevTicks = SDL_GetTicks();

        //ticks for the current frame
        Uint32 currentTicks = SDL_GetTicks();

        //Calculate the number of ticks ( ms ) for this frame
        m_FrameTime = static_cast<float>(currentTicks - prevTicks);
        frameTimes[currentFrame % NUM_SAMPLES] = m_FrameTime;

        //current ticks is now previous ticks
        prevTicks = currentTicks;

        //The number of frames to average
        int count;

        currentFrame++;

        if ( currentFrame < NUM_SAMPLES ) {
            count = currentFrame;
        } else {
            count = NUM_SAMPLES;
        }

        //Average all the frame times
        float frameTimeAverage = 0;
        for (int i = 0; i < count; i++) {
            frameTimeAverage += frameTimes[i];
        }

        frameTimeAverage /= count;

        //Calculate FPS
        if (frameTimeAverage > 0) {
            m_Fps = 1000.0f / frameTimeAverage;
        } else {
            m_Fps = 60.0f;
        }
    }

}



