#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.h>

class Eventhandler
{
    public:
        Eventhandler();

        void update();

        int mouseX();
        int mouseY();
        bool mouseLeft();
        bool mouseRight();

        bool quit();
        bool keyUp();
        bool keyLeft();
        bool keyRight();
        bool keyDown();
        bool keyZ();
        bool keyX();
        bool keySpace();
        bool keyEsc();
        bool keyEnter();
    private:
        SDL_Event event;
        Uint8* keystate;

        bool quit_ = 0;
        int mouseX_ = 0;
        int mouseY_ = 0;
        bool mouseLeft_ = 0;
        bool mouseRight_ = 0;
};

#endif // EVENTHANDLER_H
