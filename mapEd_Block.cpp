#include "mapEd_Block.h"

void Block::draw(Gfx &gfx, Screen &screen, Camera &camera)
{
    SDL_Surface* s;
    switch (ID)
    {
        case 0:
            s = gfx.character;
            break;
        case 1:
        default:
            s = gfx.grass;
            break;
        case 2:
            s = gfx.weapon;
            break;
        case 3:
            s = gfx.badguy;
            break;
        case 4:
            s = gfx.heart;
            break;
        case 5:
            s = gfx.slime;
            break;
        case 6:
            s = gfx.coin;
            break;
        case 7:
            s = gfx.ammo;
            break;
        case 8:
            s = gfx.redkey;
            break;
        case 9:
            s = gfx.bluekey;
            break;
        case 10:
            s = gfx.yellowkey;
            break;
        case 11:
            s = gfx.greenkey;
            break;
        case 12:
            s = gfx.whitekey;
            break;
        case 13:
            s = gfx.blackkey;
            break;
        case 14:
            s = gfx.reddoor;
            break;
        case 15:
            s = gfx.bluedoor;
            break;
        case 16:
            s = gfx.yellowdoor;
            break;
        case 17:
            s = gfx.greendoor;
            break;
        case 18:
            s = gfx.whitedoor;
            break;
        case 19:
            s = gfx.blackdoor;
            break;
        case 20:
            s = gfx.dirt;
            break;
        case 21:
            s = gfx.bg1;
            break;
        case 22:
            s = gfx.bg2;
            break;
        case 23:
            s = gfx.bg3;
            break;
        case 24:
            s = gfx.finish;
            break;
        case 25:
            s = gfx.checkpoint;
            break;
        case 26:
            s = gfx.stone;
            break;
        case 27:
            s = gfx.torch;
            break;
        case 28:
            s = gfx.skeleton;
            break;
        case 29:
            s = gfx.boss;
            break;
        case 30:
            s = gfx.bosswall;
            break;
    }

    screen.drawImage(s, x*16-camera.x(), y*16-camera.y(), 0);
}
