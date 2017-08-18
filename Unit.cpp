#include "Unit.h"

bool Unit::handleDeath(list<Object*> &objects)
{
    if (health <= 0 && !dead)
    {
        dead = 1;
        recentlyDied = 1;
        if (type == 1) deadTimer = DEATHTIME; else deadTimer = 500;
    }

    if (dead)
    {
        canBlock = 0;
        collidesOnlyWithWalls = 1;
    }

    deadTimer--;

    if (dead && deadTimer<0)
    {
        destroy(objects);
        return 0;
    }
    return 1;
}


int Unit::AI_DistanceToEdge(list<Wall> &walls)
{
    Object *start = NULL;
    Object *current = NULL;

    for (list<Collision>::iterator i = collisions.begin(); i != collisions.end(); i++)
    {
        if (i->side == 2 && i->obj->type == 2)
        {
            start = i->obj;
            break;
        }
    }
    if (start == NULL) return 0;

    current = start;
    for (list<Wall>::iterator i = walls.begin(); i != walls.end();)
    {
        if ( (facingDir == 0 && i->x == current->x+16 && i->y == current->y) || (facingDir == 1 && i->x == current->x-16 && i->y == current->y) )
        {
            current = &*i;
            i = walls.begin();
            continue;
        }
        i++;
    }

    return abs(current->x - x);
}
