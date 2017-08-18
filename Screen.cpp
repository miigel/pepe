#include "Screen.h"

Screen::Screen(bool fullscreen)
{
    this->fullscreen = fullscreen;
}


Screen::~Screen()
{

}

void Screen::load()
{
    if (fullscreen) srfc = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, 32, SDL_SWSURFACE|SDL_FULLSCREEN); else srfc = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, 32, SDL_SWSURFACE);
    if (srfc == NULL) makeError(2);
}

void Screen::draw()
{
    SDL_Flip(srfc);
}

//draw image to game screen
void Screen::drawImage(SDL_Surface* img, int x, int y, bool centerOrigin) //centerOrigin = coordinates are in the middle of the image
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    if (centerOrigin)
    {
        rect.x -= img->w/2;
        rect.y -= img->h/2;
    }

    SDL_BlitSurface(img, NULL, srfc, &rect);
}

void Screen::drawPixel(int x, int y, int r, int g, int b)
{
    Uint32* pixels = (Uint32*) srfc->pixels;
    if (x >= 0 && y >= 0 && x < SCREENWIDTH && y < SCREENHEIGHT) pixels[(y*srfc->w) + x] = SDL_MapRGBA(srfc->format, r, g, b, 255);
}

void Screen::text(SDL_Font &font, int x, int y, std::string text)
{
    font.text(srfc, x, y, text);
}

//clear screen to black
void Screen::cls(Uint32 R, Uint32 G, Uint32 B)
{
    SDL_FillRect(srfc, NULL, SDL_MapRGB(srfc->format, R, G, B));
}
