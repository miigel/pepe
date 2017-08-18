#ifndef WEAPONSPRITE_H
#define WEAPONSPRITE_H

#include "Object.h"
#include "Gfx.h"
#include "Character.h"

class WeaponSprite : public Object
{
    public:
        WeaponSprite(Gfx &gfx, Character &character);
        void animUpdate();
        void update();
    protected:
    private:
        Character* character = NULL;
};

#endif // WEAPONSPRITE_H
