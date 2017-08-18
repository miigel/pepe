#include "SDL_Font.h"


SDL_Font::SDL_Font(std::string file, int width, std::string chars)
{
    SDL_Surface* srfc2 = IMG_Load(file.c_str());
    if (srfc2 == NULL)
    {
        makeError(3, file);
        return;
    }
    srfc=SDL_DisplayFormatAlpha(srfc2);
    SDL_FreeSurface(srfc2);

    this->chars=chars;
    this->width=width;
    size=new int[chars.length()];
    gap=2;
    r=g=b=0;
    Uint8 R,G,B;
    bool emptyline;
    Uint32* p = (Uint32*)srfc->pixels;

    for (unsigned int i=0; i<chars.length(); i++)
    {
        for (int x=width-1; x>=0; x--)
        {
            emptyline=1;
            for (int y=0; y<srfc->h; y++)
            {
                SDL_GetRGB(p[x+i*width+y*srfc->w], srfc->format, &R,&G,&B);
                if (R==0 && G==0 && B==0)
                {
                    emptyline=0;
                    break;
                }
            }
            if (emptyline==0)
            {
                size[i]=x+1;
                break;
            }
        }
    }
    setColor(255,255,255);
}


SDL_Font::~SDL_Font()
{
    SDL_FreeSurface(srfc);
    delete [] size;
}


void SDL_Font::text(SDL_Surface* surface, int x, int y, std::string text)
{
    SDL_Rect rect, pos;
    rect.h=srfc->h;
    pos.x=x;
    pos.y=y;
    for (unsigned int i=0; i<text.length(); i++)
    {
        if (text[i]==' ')
        {
            pos.x+=gap*2;
            continue;
        }
        for (unsigned int j=0; j<chars.length(); j++)
        {
            if (text[i]==chars[j])
            {
                rect.x=j*width;
                rect.y=0;
                rect.w=size[j];
                SDL_BlitSurface(srfc, &rect, surface, &pos);
                pos.x+=size[j]+gap;
                break;
            }
        }
    }
}


void SDL_Font::setColor(Uint8 r, Uint8 g, Uint8 b)
{
    Uint32* p = (Uint32*)srfc->pixels;

    for (int x=0; x<srfc->w; x++)
    {
        for (int y=0; y<srfc->h; y++)
        {
            if (p[x+y*srfc->w]==SDL_MapRGB(srfc->format, this->r, this->g, this->b)) p[x+y*srfc->w]=SDL_MapRGB(srfc->format, r, g, b);
        }
    }

    this->r=r;
    this->g=g;
    this->b=b;
}


void SDL_Font::getColor(Uint8 &r, Uint8 &g, Uint8 &b)
{
    r=this->r;
    g=this->g;
    b=this->b;
}


void SDL_Font::setGap(int gap)
{
    if (gap<0) return;
    this->gap=gap;
}


int SDL_Font::getGap()
{
    return this->gap;
}
