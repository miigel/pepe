#include "Projectile.h"

Projectile::Projectile(Gfx *gfx, int ID)
{
    if (gfx != NULL)
    {
        if (ID==0) sprite.push_back(gfx->laser);
        if (ID==3) sprite.push_back(gfx->bossProjectile);
    }

    this->ID = ID;

    type = 4;

    canCollide = 1;
    isMovedFromCollision = 0;

    hitboxW = 7;
    hitboxH = 7;
}

Projectile::~Projectile()
{
    //dtor
}

bool Projectile::update(Character &character, list<Badguy> &badguys, list<Slime> &slimes, list<Boss> &bosses, list<Object*> &objects, Snd &snd)
{
    lifetime++;
    if (ID==0 && lifetime > LASERMAXLIFETIME)
    {
        destroy(objects);
        return 0;
    }
    if ((ID==1 || ID==2) && lifetime > 1)
    {
        destroy(objects);
        return 0;
    }
    if (ID==3 && lifetime > BOSS_PROJECTILE_MAXLIFETIME)
    {
        destroy(objects);
        return 0;
    }

    if (hasCollided)
    {
        for (list<Collision>::iterator i = collisions.begin(); i != collisions.end(); i++)
        {
            if (i->obj->type == 1 && (ID==1 || ID==3))
            {
                character.takeDmg(1, snd);
                destroy(objects);
                return 0;
            }
            if (i->obj->type == 1 && ID==2)
            {
                character.takeDmg(2, snd);
                destroy(objects);
                return 0;
            }
            if (i->obj->type == 2 && (ID==0 || ID==3) && i->obj->canBlock)
            {
                destroy(objects);
                return 0;
            }
            if (i->obj->type == 3 && ID==0)
            {
                for (list<Badguy>::iterator j = badguys.begin(); j != badguys.end(); j++)
                {
                    if (&*i->obj == &*j && !j->dead)
                    {
                        j->health--;
                        destroy(objects);
                        snd.play(SNDHITENEMY);
                        return 0;
                    }
                }
                for (list<Slime>::iterator j = slimes.begin(); j != slimes.end(); j++)
                {
                    if (&*i->obj == &*j && !j->dead)
                    {
                        j->health--;
                        destroy(objects);
                        snd.play(SNDHITENEMY);
                        return 0;
                    }
                }
                for (list<Boss>::iterator j = bosses.begin(); j != bosses.end(); j++)
                {
                    if (&*i->obj == &*j && !j->dead)
                    {
                        j->health--;
                        j->engage = 1;
                        destroy(objects);
                        snd.play(SNDHITENEMY);
                        return 0;
                    }
                }
            }
        }
    }



    return 1;
}
