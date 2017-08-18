#ifndef SLIME_H
#define SLIME_H

#include "Unit.h"
#include "Character.h"
#include "Projectile.h"

class Projectile;

class Slime : public Unit
{
    public:
        Slime(Gfx &gfx);
        void animUpdate();
        void jump();
        void update(Character &character, list<Projectile> &projectiles, list<Object*> &objects, Snd &snd, list<Wall> &walls);
        void handleAI(Character &character, list<Projectile> &projectiles, list<Object*> &objects, list<Wall> &walls);

        int engageTime = 0;
        int idleTime = 0;
        bool hasJumped = 0;
    protected:
    private:
};

#endif // SLIME_H
