#ifndef CHECKPOINTSAVE_H
#define CHECKPOINTSAVE_H

#include "Game.h"

class Game;

class CheckpointSave
{
    public:
        ~CheckpointSave();
        void save(const Game &game);
        void load(Game *game);
    protected:
    private:
        int score = 0;

        list<Wall> walls;
        list<PickableObj> pickups;
        list<Projectile> projectiles;
        list<Badguy> badguys;
        list<Slime> slimes;
        list<Boss> bosses;
        list<Wall> doors;
        list<BackgroundObject> bgobjects;

        Character *character = NULL;

        bool redKey = 0;
        bool blueKey = 0;
        bool yellowKey = 0;
        bool greenKey = 0;
        bool whiteKey = 0;
        bool blackKey = 0;
};

#endif // CHECKPOINTSAVE_H
