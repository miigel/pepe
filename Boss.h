#ifndef BOSS_H
#define BOSS_H

#include <math.h>

#include "Unit.h"
#include "Gfx.h"
#include "Projectile.h"

class Projectile;

class Boss : public Unit
{
    public:
        Boss(Gfx &gfx);
        void animUpdate();
        void move();
        void meleeAttack(list<Projectile> &projectiles, list<Object*> &objects);
        void laserAttack(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd);
        void update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd);
        void handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Gfx &gfx, Snd &snd);

        bool engage = 0;
        bool isMeleeAttacking = 0;
        int meleeAttackTime = 0;
        int laserAttackTime = 0;
        int laserAttackTime2 = 300;
    protected:
    private:
};

#endif // BOSS_H
