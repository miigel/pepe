#ifndef WALL_H
#define WALL_H

#include "Object.h"
#include "Gfx.h"

class Wall : public Object
{
    public:
        Wall(Gfx &gfx, int x, int y, int ID);
        void animUpdate();

        int ID = 0;
    protected:
    private:
};

#endif // WALL_H
