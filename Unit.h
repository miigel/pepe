#ifndef UNIT_H
#define UNIT_H

#include <SDL.h>
#include <math.h>
#include "Object.h"
#include "Wall.h"

class Unit : public Object
{
    public:
        bool handleDeath(list<Object*> &objects);
        int AI_DistanceToEdge(list<Wall> &walls);

        bool facingDir = 0; //0=right 1=left
        int health = 1;
        bool dead = 0;
        int deadTimer = 0;
        bool recentlyDied = 0;
    protected:
    private:
};

#endif // UNIT_H
