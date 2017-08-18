#ifndef BADGUY_H
#define BADGUY_H

#include <math.h>

#include "Unit.h"
#include "util.h"
#include "Character.h"
#include "Projectile.h"

class Projectile;

class Badguy : public Unit
{
    public:
        Badguy(Gfx &gfx);
        void animUpdate();
        void move();
        void attack(list<Projectile> &projectiles, list<Object*> &objects);
        void update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls);
        void handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls);

        int idleTime = 0;
        int moveTime = 0;
        int engageTime = 0;
        bool isAttacking = 0;
        int attackTime = 0;
    protected:
    private:
};

#endif // BADGUY_H
