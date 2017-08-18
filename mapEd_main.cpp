#include <SDL.h>
#include <string>
#include <sstream>

#include "Screen.h"
#include "Eventhandler.h"
#include "mapEd_Editor.h"
#include "Gfx.h"
#include "SDL_Font.h"
#include "error.h"

using namespace std;

int main(int argc, char **argv)
{
    string fileName = "";
    stringstream ss;
    if (argc == 2)
    {
        int i = 0;
        while(argv[1][i] != '\0')
        {
            ss << argv[1][i];
            i++;
        }
        fileName = "maps/"+ss.str();
    } else makeError(4);
    if (error) return errorID;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) makeError(1);
    if (error) return errorID;

    SDL_WM_SetCaption("Pepe the game, Map Editor", NULL);

    Screen screen(0);
    Gfx gfx;

    screen.load();
    if (error) return errorID;

    SDL_Font font("gfx/font.png", 12, "abcdefghijklmnopqrstuvwxyzåäö0123456789.,-+_><*'!@#:%&/\\()=?");
    if (error) return errorID;
    font.setColor(0,0,0);

    gfx.load();
    if (error) return errorID;

    Editor editor(screen, gfx, font, fileName);
    editor.loadMap();
    editor.loop();
    editor.saveMap();

    SDL_Quit();

    return 0;
}
