#ifndef PROJECTILE_H
#define PROJECTILE_H

#define PROJECTILELASER 0
#define PROJECTILECLUBHIT 1
#define PROJECTILESWORDHIT 2
#define PROJECTILEBOSS 3


#include "Object.h"
#include "Gfx.h"
#include "Character.h"
#include "error.h"
#include "Badguy.h"
#include "Slime.h"
#include "Boss.h"

class Badguy;
class Slime;
class Boss;

class Projectile : public Object
{
    public:
        Projectile(Gfx *gfx, int ID);
        ~Projectile();
        void animUpdate() {};
        bool update(Character &character, list<Badguy> &badguys, list<Slime> &slimes, list<Boss> &bosses, list<Object*> &objects, Snd &snd);

        int ID = 0;
        int lifetime = 0;
    protected:
    private:
};

#endif // PROJECTILE_H
