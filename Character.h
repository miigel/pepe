#ifndef CHARACTER_H
#define CHARACTER_H

#include "Unit.h"
#include "Gfx.h"
#include "Snd.h"


class Character : public Unit
{
    public:
        Character(Gfx &gfx);

        void animUpdate();
        void takeDmg(int dmg, Snd &snd);
        void updateImmunity();

        bool jumping = 0;
        int jumpTime = 0;
        int currentWeapon = 0;
        int weaponCooldown = 0;
        int ammo = 0;
        bool immuneToDmg = 0;
        int immuneTime = 0;
    protected:
    private:
};

#endif // CHARACTER_H
