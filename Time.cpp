#include "Time.h"

Time::Time()
{
    ticks = SDL_GetTicks();
    ticks2 = ticks;
    frames = 0;
    fps = 0;
}

void Time::hold()
{
    //framelimiting/fps capping:
    //hold the execution of the program so that the loop takes 1000/FPS milliseconds to execute
    if (SDL_GetTicks()-ticks < 1000/FPS) SDL_Delay(1000/FPS - (SDL_GetTicks()-ticks));
    ticks = SDL_GetTicks();

    //calculating fps:
    frames++;
    if (SDL_GetTicks() >= ticks2 + 1000)
    {
        fps = frames;
        frames = 0;
        ticks2 = SDL_GetTicks();
    }
}
