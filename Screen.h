#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include <string>
#include "SDL_Font.h"
#include "defines.h"
#include "error.h"

class Screen
{
    public:
        Screen(bool fullscreen);
        ~Screen();

        void load();
        void draw();
        void drawImage(SDL_Surface* img, int x, int y, bool centerOrigin=1);
        void drawPixel(int x, int y, int r, int g, int b);
        void text(SDL_Font &font, int x, int y, std::string text);
        void cls(Uint32 R, Uint32 G, Uint32 B);

    private:
        SDL_Surface *srfc = NULL;
        bool fullscreen;
};

#endif // SCREEN_H
