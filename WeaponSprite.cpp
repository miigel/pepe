#include "WeaponSprite.h"

WeaponSprite::WeaponSprite(Gfx &gfx, Character &character)
{
    this->character = &character;

    sprite.push_back(gfx.weapon);
    sprite.push_back(gfx.weaponFlip);
}


void WeaponSprite::animUpdate()
{
    if (character->currentWeapon == 0) animState = -1; else
    {
        animState = character->currentWeapon - 1;
        if (character->facingDir == 1) animState += 1;
    }
}


void WeaponSprite::update()
{
    isInvisible = character->isInvisible;

    switch (character->currentWeapon)
    {
        case 1:
            if (character->facingDir==0) x = character->x + 9;
            if (character->facingDir==1) x = character->x - 9;

            y = character->y - 3;
            break;
        default:
            break;
    }
}
