#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>

#include "Screen.h"
#include "Eventhandler.h"
#include "Game.h"
#include "Gfx.h"
#include "Snd.h"
#include "SDL_Font.h"
#include "error.h"
#include "Menu.h"

using namespace std;

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) makeError(1);
    if (error) return errorID;

    SDL_WM_SetCaption("Pepe the game", NULL);

    srand(time(NULL));

    bool fullscreen = 1;
    string customMapName = "";


    if (argc>=2)
    {
        for (int i = 1; i < argc; i++)
        {
            if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "-windowed")) fullscreen = 0;
            if (!strcmp(argv[i], "-map") || !strcmp(argv[i], "-level"))
            {
                if (argc > i+1)
                {
                    stringstream ss;
                    ss << argv[i+1];
                    customMapName = ss.str();
                }
            }
        }
    }

    Screen screen(fullscreen);
    Gfx gfx;
    Snd snd;

    screen.load();
    if (error) return errorID;

    SDL_Font font("gfx/font.png", 12, "abcdefghijklmnopqrstuvwxyzåäö0123456789.,-+_><*'!@#:%&/\\()=?");
    if (error) return errorID;
    font.setColor(0,0,0);

    gfx.load();
    if (error) return errorID;

    snd.load();
    if (error) return errorID;

    Menu menu(screen, font, gfx);

    Game game(screen, gfx, font, snd, customMapName);
    if (error) return errorID;

    while(1)
    {
        if (customMapName == "")
        {
            if (menu.loop())
            {
                if (!game.loop()) break;
            } else break;
        } else
        {
            if (!game.loop()) break;
            customMapName = "";
            game.customMap = 0;
        }

    }


    SDL_Quit();

    return 0;
}
