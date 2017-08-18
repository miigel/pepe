#ifndef SDL_FONT_H
#define SDL_FONT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "error.h"

class SDL_Font
{
    public:
        SDL_Font(std::string file, int width, std::string chars);
        ~SDL_Font();
        void text(SDL_Surface* surface, int x, int y, std::string text);
        void setColor(Uint8 r, Uint8 g, Uint8 b);
        void getColor(Uint8 &r, Uint8 &g, Uint8 &b);
        void setGap(int gap);
        int getGap();


        SDL_Surface* srfc = NULL;
    private:
        std::string chars;
        int *size = NULL;
        int width;
        int gap;
        Uint8 r,g,b;
};

#endif
