#include "PickableObj.h"

PickableObj::PickableObj(Gfx &gfx)
{
    sprite.push_back(gfx.weapon);
    sprite.push_back(gfx.weapon2);
    sprite.push_back(gfx.heart);
    sprite.push_back(gfx.heart2);
    sprite.push_back(gfx.coin);
    sprite.push_back(gfx.coin2);
    sprite.push_back(gfx.ammo);
    sprite.push_back(gfx.ammo2);
    sprite.push_back(gfx.redkey);
    sprite.push_back(gfx.redkey2);
    sprite.push_back(gfx.bluekey);
    sprite.push_back(gfx.bluekey2);
    sprite.push_back(gfx.yellowkey);
    sprite.push_back(gfx.yellowkey2);
    sprite.push_back(gfx.greenkey);
    sprite.push_back(gfx.greenkey2);
    sprite.push_back(gfx.whitekey);
    sprite.push_back(gfx.whitekey2);
    sprite.push_back(gfx.blackkey);
    sprite.push_back(gfx.blackkey2);
}

void PickableObj::animUpdate()
{
    if (ID==1 && animState<2) animState=2;
    if (ID==2 && animState<4) animState=4;
    if (ID==3 && animState<6) animState=6;
    if (ID==4 && animState<8) animState=8;
    if (ID==5 && animState<10) animState=10;
    if (ID==6 && animState<12) animState=12;
    if (ID==7 && animState<14) animState=14;
    if (ID==8 && animState<16) animState=16;
    if (ID==9 && animState<18) animState=18;

    animTimer++;
    if (animTimer >= 10)
    {
        animState++;
        animTimer = 0;

        if (animState == 2) animState = 0;
        if (animState == 4) animState = 2;
        if (animState == 6) animState = 4;
        if (animState == 8) animState = 6;
        if (animState == 10) animState = 8;
        if (animState == 12) animState = 10;
        if (animState == 14) animState = 12;
        if (animState == 16) animState = 14;
        if (animState == 18) animState = 16;
        if (animState == 20) animState = 18;
    }

}
