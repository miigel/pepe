#include "Slime.h"

Slime::Slime(Gfx &gfx)
{
    type = 3;
    isAffectedByGravity = 1;
    canCollide = 1;
    canBlock = 1;

    hitboxW = 23;
    hitboxH = 18;

    sprite.push_back(gfx.slime);
    sprite.push_back(gfx.slimeJump);
    sprite.push_back(gfx.slimeDeath1);
    sprite.push_back(gfx.slimeDeath2);
    sprite.push_back(gfx.slimeDeath3);
    sprite.push_back(gfx.slimeDeath4);
    sprite.push_back(gfx.slimeFlip);
    sprite.push_back(gfx.slimeJumpFlip);
    sprite.push_back(gfx.slimeDeath1Flip);
    sprite.push_back(gfx.slimeDeath2Flip);
    sprite.push_back(gfx.slimeDeath3Flip);
    sprite.push_back(gfx.slimeDeath4Flip);

    health = 3;
}

void Slime::animUpdate()
{
    if (dead)
    {
        if (animState == 5 || animState == 11) return; //animation finished
        if (!(animState >= 2 && animState <= 5) && !(animState >= 8))
        {
            if (facingDir == 0) animState = 2; else animState = 8;
        }
        animTimer++;
        if (animTimer >= 8)
        {
            animTimer = 0;
            animState++;
        }
        return;
    }

    if (!onGround)
    {
        if (facingDir == 0) animState = 1; else animState = 7;
        return;
    }

    if (animState != 6 && facingDir == 1) animState = 6;
    if (animState != 0 && facingDir == 0) animState = 0;
}

void Slime::jump()
{
    if (facingDir == 1 && !dead && onGround)
    {
        xSpeed = -random(10, 30)*0.1;
        ySpeed = -random(5, 10);
        onGround = 0;
    }
    if (facingDir == 0 && !dead && onGround)
    {
        xSpeed = random(10, 30)*0.1;
        ySpeed = -random(5, 10);
        onGround = 0;
    }
}

void Slime::update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Snd &snd, list<Wall> &walls)
{
    if (onGround) xSpeed = 0;
    for (list<Collision>::iterator i = character.collisions.begin(); i != character.collisions.end(); i++)
    {
        if (i->obj == this && i->side!=2 && !dead) character.takeDmg(1, snd);
    }
    for (list<Collision>::iterator i = collisions.begin(); i != collisions.end(); i++)
    {
        if (&*i->obj == &character && i->side!=0 && !dead) character.takeDmg(1, snd);
    }
    if (!dead) handleAI(character, projectiles, objects, walls);
}


void Slime::handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls)
{
    bool status; //0=wandering, 1=engaging

    if (abs(y - character.y) < 40 && abs(x - character.x) < 300)
    {
        engageTime = 60;
        status = 1;
    }
    engageTime--;
    if (status == 1 && engageTime<=0) status = 0;
    if (character.dead) status = 0;

    idleTime--;
    if (idleTime<=0)
    {
        if (!hasJumped && onGround)
        {
            if (status == 0) facingDir = random(0,1); else
            {
                if (x < character.x) facingDir = 0; else facingDir = 1;
            }
            if (AI_DistanceToEdge(walls) < 64) facingDir = !facingDir;
            jump();
            hasJumped = 1;
        }
        if (hasJumped && onGround)
        {
            idleTime = random(30,300);
            if (status == 1) idleTime = (int)(idleTime * 0.33 + 0.5);
            hasJumped = 0;
        }
    }

}
