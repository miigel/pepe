#include "Character.h"

Character::Character(Gfx &gfx)
{
    type = 1;
    isAffectedByGravity = 1;
    canCollide = 1;
    canBlock = 1;

    hitboxW = 10;
    hitboxH = 32;

    sprite.push_back(gfx.character);
    sprite.push_back(gfx.characterMove);
    sprite.push_back(gfx.characterWpn);
    sprite.push_back(gfx.characterWpnMove);
    sprite.push_back(gfx.characterDead);
    sprite.push_back(gfx.characterFlip);
    sprite.push_back(gfx.characterMoveFlip);
    sprite.push_back(gfx.characterWpnFlip);
    sprite.push_back(gfx.characterWpnMoveFlip);
    sprite.push_back(gfx.characterDeadFlip);

    health = 5;
}


void Character::animUpdate()
{
    if (dead)
    {
        if (facingDir == 0) animState = 4; else animState = 9;
        return;
    }

    if (!onGround)
    {
        if (facingDir == 0) animState = 0; else animState = 5;
        if (currentWeapon) animState += 2;
        return;
    }

    if (facingDir == 0 && xSpeed != 0)
    {
        if (animState!=0 && animState!=1 && !currentWeapon) animState=0;
        if (animState!=2 && animState!=3 && currentWeapon) animState=2;
        animTimer++;
        if (animTimer >= 10)
        {
            animTimer = 0;
            animState++;
            if (animState == 2) animState = 0;
            if (animState == 4) animState = 2;
        }
        return;
    }

    if (facingDir == 1 && xSpeed < 0)
    {
        if (animState!=5 && animState!=6 && !currentWeapon) animState=5;
        if (animState!=7 && animState!=8 && currentWeapon) animState=7;
        animTimer++;
        if (animTimer >= 10)
        {
            animTimer = 0;
            animState++;
            if (animState == 7) animState = 5;
            if (animState == 9) animState = 7;
        }
        return;
    }

    if (animState != 5 && facingDir == 1) animState = 5;
    if (animState != 0 && facingDir == 0) animState = 0;
    if (currentWeapon) animState += 2;
}

void Character::takeDmg(int dmg, Snd &snd)
{
    if (!immuneToDmg && !dead)
    {
        health -= dmg;
        if (health < 0) health = 0;
        if (health != 0) immuneToDmg = 1;
        immuneTime = INVULNERABILITYTIME;
        snd.play(SNDHIT);
    }
}

void Character::updateImmunity()
{
    if (immuneToDmg)
    {
        immuneTime--;
        if (immuneTime % 2 == 0) isInvisible = 0; else isInvisible = 1; //flashing effect
        if (immuneTime == 0) immuneToDmg = 0;
    }
}
