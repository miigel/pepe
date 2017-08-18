#include "Object.h"

void Object::updatePhysics(list<Object*> *objects)
{
    if (noPhysics) return;

    //gravity:
    if (isAffectedByGravity)
    {
        ySpeed = ySpeed + GRAVITY;
        if (ySpeed > GRAVITY_SPEED_MAX) ySpeed = GRAVITY_SPEED_MAX;
        onGround = 0;
    }

    //movement and collision:
    hasCollided = 0;
    collisions.clear();

    int hb1X, hb1Y, hb2X, hb2Y;
    if (hitboxW) hb1X = hitboxW/2; else hb1X = sprite[0]->w/2;
    if (hitboxH) hb1Y = hitboxH/2; else hb1Y = sprite[0]->h/2;

    Collision collision;

    x = x + xSpeed;

    if (canCollide)
    {
        for (list<Object*>::iterator i = objects->begin(); i != objects->end(); i++)
        {
            if (this == (*i)) continue;

            if ((*i)->hitboxW) hb2X = (*i)->hitboxW/2; else hb2X = (*i)->sprite[0]->w/2;
            if ((*i)->hitboxH) hb2Y = (*i)->hitboxH/2; else hb2Y = (*i)->sprite[0]->h/2;

            if (x-hb1X < (*i)->x+hb2X &&
                x+hb1X > (*i)->x-hb2X &&
                y-hb1Y < (*i)->y+hb2Y &&
                y+hb1Y > (*i)->y-hb2Y)
            {
                if (xSpeed >= 0) collision.side = 1; else collision.side = 3;
                if (isMovedFromCollision && (*i)->canBlock)
                {
                    if (!collidesOnlyWithWalls || (*i)->type == 2)
                    {
                        if (xSpeed >= 0) x -= (x+hb1X) - ((*i)->x-hb2X); else x += ((*i)->x+hb2X) - (x-hb1X);
                        xSpeed = 0;
                    }
                }
                hasCollided = 1;
                collision.obj = *i;
                collisions.push_back(collision);
            }
        }
    }


    y = y + ySpeed;

    if (canCollide)
    {
        for (list<Object*>::iterator i = objects->begin(); i != objects->end(); i++)
        {
            if (this == (*i) || (*i)->canBlock == 0) continue;

            if ((*i)->hitboxW) hb2X = (*i)->hitboxW/2; else hb2X = (*i)->sprite[0]->w/2;
            if ((*i)->hitboxH) hb2Y = (*i)->hitboxH/2; else hb2Y = (*i)->sprite[0]->h/2;

            if (x-hb1X < (*i)->x+hb2X &&
                x+hb1X > (*i)->x-hb2X &&
                y-hb1Y < (*i)->y+hb2Y &&
                y+hb1Y > (*i)->y-hb2Y)
            {
                if (ySpeed >= 0) collision.side = 2; else collision.side = 0;
                if (isMovedFromCollision && (*i)->canBlock)
                {
                    if (!collidesOnlyWithWalls || (*i)->type == 2)
                    {
                        if (ySpeed >= 0)
                        {
                            y -= (y+hb1Y) - ((*i)->y-hb2Y);
                            onGround = 1;
                        } else y += ((*i)->y+hb2Y) - (y-hb1Y);
                        ySpeed = 0;
                    }
                }
                hasCollided = 2;
                collision.obj = *i;
                collisions.push_back(collision);
            }
        }
    }
}

void Object::destroy(list<Object*> &objects)
{
    for (list<Object*>::iterator i = objects.begin(); i != objects.end(); i++)
    {
        for (list<Collision>::iterator j = (*i)->collisions.begin(); j != (*i)->collisions.end();)
        {
            if (this == j->obj)
            {
                j = (*i)->collisions.erase(j);
                continue;
            }
            j++;
        }
    }

    for (list<Object*>::iterator i = objects.begin(); i != objects.end(); i++)
    {
        if (this == *i)
        {
            objects.erase(i);
            break;
        }
    }
}
