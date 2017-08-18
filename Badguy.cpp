#include "Badguy.h"

Badguy::Badguy(Gfx &gfx)
{
    type = 3;
    isAffectedByGravity = 1;
    canCollide = 1;
    canBlock = 1;

    hitboxW = 15;
    hitboxH = 33;

    sprite.push_back(gfx.badguy);
    sprite.push_back(gfx.badguyMove);
    sprite.push_back(gfx.badguyAttack);
    sprite.push_back(gfx.badguyDeath1);
    sprite.push_back(gfx.badguyDeath2);
    sprite.push_back(gfx.badguyDeath3);
    sprite.push_back(gfx.badguyDeath4);
    sprite.push_back(gfx.badguyDeath5);
    sprite.push_back(gfx.badguyDeath6);
    sprite.push_back(gfx.badguyFlip);
    sprite.push_back(gfx.badguyMoveFlip);
    sprite.push_back(gfx.badguyAttackFlip);
    sprite.push_back(gfx.badguyDeath1Flip);
    sprite.push_back(gfx.badguyDeath2Flip);
    sprite.push_back(gfx.badguyDeath3Flip);
    sprite.push_back(gfx.badguyDeath4Flip);
    sprite.push_back(gfx.badguyDeath5Flip);
    sprite.push_back(gfx.badguyDeath6Flip);

    health = 5;
}

void Badguy::animUpdate()
{
    if (dead)
    {
        if (animState == 8 || animState == 17) return; //animation finished
        if (!(animState >= 3 && animState <= 8) && !(animState >= 12))
        {
            if (facingDir == 0) animState = 3; else animState = 12;
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
        if (facingDir == 0) animState = 0; else animState = 9;
        return;
    }

    if (isAttacking && attackTime<15)
    {
        if (facingDir == 0) animState = 2; else animState = 11;
        return;
    }

    if (xSpeed > 0)
    {
        if (animState!=0 && animState!=1) animState=0;
        animTimer++;
        if (animTimer >= 10)
        {
            animTimer = 0;
            animState++;
            if (animState == 2) animState = 0;
        }
        return;
    }

    if (xSpeed < 0)
    {
        if (animState!=9 && animState!=10) animState=9;
        animTimer++;
        if (animTimer >= 10)
        {
            animTimer = 0;
            animState++;
            if (animState == 11) animState = 9;
        }
        return;
    }

    if (animState != 9 && facingDir == 1) animState = 9;
    if (animState != 0 && facingDir == 0) animState = 0;
}

void Badguy::move()
{
    if (facingDir == 1 && !dead && !isAttacking)
    {
        xSpeed -= MOVE_ACCELERATION;
        if (xSpeed < -MOVE_MAX_SPEED*0.5) xSpeed = -MOVE_MAX_SPEED*0.5;
    }
    if (facingDir == 0 && !dead && !isAttacking)
    {
        xSpeed += MOVE_ACCELERATION;
        if (xSpeed > MOVE_MAX_SPEED*0.5) xSpeed = MOVE_MAX_SPEED*0.5;
    }
}

void Badguy::attack(list<Projectile> &projectiles, list<Object*> &objects)
{
    if (!isAttacking)
    {
        isAttacking = 1;
        attackTime = 0;

        Projectile projectile(NULL, PROJECTILECLUBHIT);
        projectile.isInvisible = 1;
        projectile.hitboxW = 10;
        projectile.hitboxH = 10;
        if (facingDir == 0) projectile.x = x + 16; else projectile.x = x - 16;
        projectile.y = y - 9;

        projectiles.push_back(projectile);
        objects.push_back(&projectiles.back());
    }
}


void Badguy::update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls)
{
    if (onGround) //slowing down
    {
        if (xSpeed > 0)
        {
            xSpeed -= MOVE_DEACCELERATION;
            if (xSpeed < 0) xSpeed = 0;
        }
        if (xSpeed < 0)
        {
            xSpeed += MOVE_DEACCELERATION;
            if (xSpeed > 0) xSpeed = 0;
        }
    }

    if (isAttacking)
    {
        attackTime++;
        if (attackTime>=80) isAttacking = 0;
    }

    if (!dead) handleAI(character, projectiles, objects, walls);
}


void Badguy::handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls)
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

    if (AI_DistanceToEdge(walls) < 5) facingDir = !facingDir;

    if (status == 0)
    {
        idleTime--;
        if (idleTime<=0)
        {
            if (moveTime<=0)
            {
                facingDir = random(0,1);
                moveTime = random(5,20);
            }

            if (moveTime>0)
            {
                move();
                moveTime--;
                if (moveTime==0) idleTime = random(30,300);
            }
        }
    } else
    {
        if (x < character.x) facingDir = 0; else facingDir = 1;
        if (abs(x - character.x) >= 25 && AI_DistanceToEdge(walls) >= 5) move();
        if (abs(x - character.x) < 25 && abs(y - character.y) < 32) attack(projectiles, objects);
    }
}
