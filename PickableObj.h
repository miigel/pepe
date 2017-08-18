#ifndef PICKABLEOBJ_H
#define PICKABLEOBJ_H

#include "Object.h"
#include "Gfx.h"

class PickableObj : public Object
{
    public:
        PickableObj(Gfx &gfx);
        void animUpdate();

        int ID;
    protected:
    private:
};

#endif // PICKABLEOBJ_H
