#ifndef TIME_H
#define TIME_H

#include <SDL.h>
#include "defines.h"

class Time
{
    public:
        Time();

        void hold();

        unsigned int fps;
    protected:
    private:
        unsigned int ticks;
        unsigned int ticks2;
        unsigned int frames;
};

#endif // TIME_H
