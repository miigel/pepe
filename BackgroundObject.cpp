#include "BackgroundObject.h"

BackgroundObject::BackgroundObject(Gfx &gfx, int x, int y, int ID)
{
    noPhysics = 1;

    this->x = x;
    this->y = y;
    this->ID = ID;

    switch (ID)
    {
        default:
        case 0:
            sprite.push_back(gfx.bg1);
            break;
        case 1:
            sprite.push_back(gfx.bg2);
            break;
        case 2:
            sprite.push_back(gfx.bg3);
            break;
        case 3:
            sprite.push_back(gfx.finish);
            break;
        case 4:
            sprite.push_back(gfx.checkpoint);
            sprite.push_back(gfx.checkpoint2);
            break;
        case 5:
            sprite.push_back(gfx.torch);
            sprite.push_back(gfx.torch2);
            sprite.push_back(gfx.torch3);
            break;
        case 6:
            sprite.push_back(gfx.skeleton);
            break;
        case 7:
            sprite.push_back(gfx.dirt);
            break;
        case 8:
            sprite.push_back(gfx.stone);
            break;
    }
}

void BackgroundObject::animUpdate()
{
    if (ID!=5) return;

    animTimer++;
    if (animTimer == 5)
    {
        animTimer = 0;
        animState++;
        if (animState == 3) animState = 0;
    }
}
