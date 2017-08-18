#include "Wall.h"

Wall::Wall(Gfx &gfx, int x, int y, int ID)
{
    type = 2;
    canBlock = 1;
    this->x = x;
    this->y = y;
    this->ID = ID;

    switch (ID)
    {
        default:
        case 0:
            sprite.push_back(gfx.grass);
            break;
        case 1:
            sprite.push_back(gfx.reddoor);
            sprite.push_back(gfx.reddoor2);
            break;
        case 2:
            sprite.push_back(gfx.bluedoor);
            sprite.push_back(gfx.bluedoor2);
            break;
        case 3:
            sprite.push_back(gfx.yellowdoor);
            sprite.push_back(gfx.yellowdoor2);
            break;
        case 4:
            sprite.push_back(gfx.greendoor);
            sprite.push_back(gfx.greendoor2);
            break;
        case 5:
            sprite.push_back(gfx.whitedoor);
            sprite.push_back(gfx.whitedoor2);
            break;
        case 6:
            sprite.push_back(gfx.blackdoor);
            sprite.push_back(gfx.blackdoor2);
            break;
        case 7:
            sprite.push_back(gfx.dirt);
            break;
        case 8:
            sprite.push_back(gfx.stone);
            break;
        case 9:
            sprite.push_back(gfx.bosswall);
            break;
    }
}

void Wall::animUpdate()
{

}
