#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include <list>
#include <vector>
#include "defines.h"
#include "Gfx.h"

using namespace std;

struct Collision;

class Object
{
    public:
        virtual ~Object() {};
        void updatePhysics(list<Object*> *objects);
        virtual void animUpdate() = 0;
        void destroy(list<Object*> &objects);

        int type = 0; //0=other 1=character 2=wall 3=enemy 4=projectile

        int animState = 0;
        int animTimer = 0;
        vector<SDL_Surface*> sprite;
        double x = 0;
        double y = 0;
        double xSpeed = 0;
        double ySpeed = 0;

        bool noPhysics = 0;
        bool isInvisible = 0;
        bool isAffectedByGravity = 0;
        bool canCollide = 0;
        bool collidesOnlyWithWalls = 0;
        bool isMovedFromCollision = 1;
        bool canBlock = 0;
        int hitboxW = 0;
        int hitboxH = 0;

        int hasCollided = 0;
        list<Collision> collisions;
        bool onGround = 0;
    protected:
    private:
};

struct Collision
{
    Object* obj;
    int side; //0=top 1=right 2=bottom 3=left
};

#endif // OBJECT_H
