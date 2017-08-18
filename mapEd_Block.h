#ifndef BLOCK_H
#define BLOCK_H

#include "Gfx.h"
#include "Screen.h"
#include "Camera.h"


class Block
{
    public:
        void draw(Gfx &gfx, Screen &screen, Camera &camera);

        int x = 0;
        int y = 0;
        int ID = 0;
    protected:
    private:
};

#endif // BLOCK_H
