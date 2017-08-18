#ifndef MENU_H
#define MENU_H

#include "Screen.h"
#include "SDL_Font.h"
#include "Gfx.h"
#include "Eventhandler.h"
#include "Time.h"

class Menu
{
    public:
        Menu(Screen &screen, SDL_Font &font, Gfx &gfx);
        bool loop();
        void handleKeys();
        void drawMenu();
    protected:
    private:
        Screen* screen = NULL;
        SDL_Font* font = NULL;
        Gfx* gfx = NULL;
        Eventhandler event;
        Time time;

        int selection = 0;
        bool credits = 0;
        bool quit = 0;
        bool preplay = 0;
        bool play = 0;
};

#endif // MENU_H
