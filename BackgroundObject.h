#ifndef BACKGROUNDOBJECT_H
#define BACKGROUNDOBJECT_H

#include "Object.h"
#include "Gfx.h"


class BackgroundObject : public Object
{
    public:
        BackgroundObject(Gfx &gfx, int x, int y, int ID);
        void animUpdate();

        int ID;
    protected:
    private:
};

#endif // BACKGROUNDOBJECT_H
