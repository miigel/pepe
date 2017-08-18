#include "Boss.h"

Boss::Boss(Gfx &gfx)
{
    type = 3;
    isAffectedByGravity = 1;
    canCollide = 1;
    canBlock = 1;

    hitboxW = 55;
    hitboxH = 107;

    sprite.push_back(gfx.boss);
    sprite.push_back(gfx.bossAttack1);
    sprite.push_back(gfx.bossAttack2);
    sprite.push_back(gfx.bossDead);
    sprite.push_back(gfx.bossFlip);
    sprite.push_back(gfx.bossAttack1Flip);
    sprite.push_back(gfx.bossAttack2Flip);
    sprite.push_back(gfx.bossDeadFlip);

    health = 50;
}

void Boss::animUpdate()
{
    if (dead)
    {
        if (facingDir == 0) animState = 3; else animState = 7;
        return;
    }

    if (isMeleeAttacking && meleeAttackTime<40)
    {
        if (facingDir == 0) animState = 1; else animState = 5;
        return;
    }

    if (isMeleeAttacking && meleeAttackTime>=40 && meleeAttackTime<90)
    {
        if (facingDir == 0) animState = 2; else animState = 6;
        return;
    }


    if (animState != 4 && facingDir == 1) animState = 4;
    if (animState != 0 && facingDir == 0) animState = 0;
}

void Boss::move()
{
    if (facingDir == 1 && !dead)
    {
        xSpeed -= MOVE_ACCELERATION;
        if (xSpeed < -MOVE_MAX_SPEED*0.3) xSpeed = -MOVE_MAX_SPEED*0.3;
    }
    if (facingDir == 0 && !dead)
    {
        xSpeed += MOVE_ACCELERATION;
        if (xSpeed > MOVE_MAX_SPEED*0.3) xSpeed = MOVE_MAX_SPEED*0.3;
    }
}

void Boss::meleeAttack(list<Projectile> &projectiles, list<Object*> &objects)
{
    if (!isMeleeAttacking)
    {
        isMeleeAttacking = 1;
        meleeAttackTime = 0;
    }
}

void Boss::laserAttack(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd)
{
    double angle;
    double Xdelta;
    double Ydelta;

    snd.play(SNDLASER);

    Projectile projectile(&gfx, PROJECTILEBOSS);
    if (facingDir == 0) projectile.x = x + 13; else projectile.x = x - 13;
    projectile.y = y - 40;

    Xdelta = character.x - projectile.x;
    Ydelta = character.y - projectile.y;
    if (Xdelta == 0) Xdelta = 0.0001;
    angle = atan2(Ydelta, Xdelta);

    projectile.xSpeed = cos(angle)*BOSS_PROJECTILE_SPEED;
    projectile.ySpeed = sin(angle)*BOSS_PROJECTILE_SPEED;

    projectiles.push_back(projectile);
    objects.push_back(&projectiles.back());
}

void Boss::update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd)
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

    if (dead && recentlyDied) ySpeed = -10;

    if (isMeleeAttacking)
    {
        if (meleeAttackTime == 40)
        {
            Projectile projectile(NULL, PROJECTILESWORDHIT);
            projectile.isInvisible = 1;
            projectile.hitboxW = 80;
            projectile.hitboxH = 130;
            if (facingDir == 0) projectile.x = x + 40; else projectile.x = x - 40;
            projectile.y = y;

            projectiles.push_back(projectile);
            objects.push_back(&projectiles.back());
        }
        meleeAttackTime++;
        if (meleeAttackTime>=150) isMeleeAttacking = 0;
    }

    if (!dead) handleAI(character, projectiles, objects, gfx, snd);
}


void Boss::handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd)
{
    if (abs(y - character.y) < 64 && abs(x - character.x) < 300) engage = 1;

    if (x < character.x) facingDir = 0; else facingDir = 1;

    if (engage)
    {
        meleeAttack(projectiles, objects);
        if (abs(x - character.x) >= 70) move();

        laserAttackTime--;
        laserAttackTime2--;
        if (laserAttackTime <= 0 && laserAttackTime2 <= 40)
        {
            laserAttack(character, projectiles, objects, gfx, snd);
            laserAttackTime = 10;
        }
        if (laserAttackTime2 <= 0) laserAttackTime2 = 300;
    }
}
