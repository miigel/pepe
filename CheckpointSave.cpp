#include "CheckpointSave.h"

CheckpointSave::~CheckpointSave()
{
    delete character;
}

void CheckpointSave::save(const Game &game)
{
    score = game.score;
    walls = game.walls;
    pickups = game.pickups;
    projectiles = game.projectiles;
    badguys = game.badguys;
    slimes = game.slimes;
    bosses = game.bosses;
    doors = game.doors;
    bgobjects = game.bgobjects;
    if (character == NULL) character = new Character(*game.gfx);
    *character = *game.character;
    redKey = game.redKey;
    blueKey = game.blueKey;
    yellowKey = game.yellowKey;
    greenKey = game.greenKey;
    whiteKey = game.whiteKey;
    blackKey = game.blackKey;
}

void CheckpointSave::load(Game *game)
{
    game->score = score;
    game->walls = walls;
    game->pickups = pickups;
    game->projectiles = projectiles;
    game->badguys = badguys;
    game->slimes = slimes;
    game->bosses = bosses;
    game->doors = doors;
    game->bgobjects = bgobjects;
    game->redKey = redKey;
    game->blueKey = blueKey;
    game->yellowKey = yellowKey;
    game->greenKey = greenKey;
    game->whiteKey = whiteKey;
    game->blackKey = blackKey;

    game->objects.clear();
    delete game->character;
    delete game->weaponSprite;

    game->character = new Character(*game->gfx);
    *game->character = *character;
    game->weaponSprite = new WeaponSprite(*game->gfx, *game->character);

    game->characterDeathFallTriggered = 0;

    for (list<BackgroundObject>::iterator i = game->bgobjects.begin(); i != game->bgobjects.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    for (list<Wall>::iterator i = game->walls.begin(); i != game->walls.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    for (list<PickableObj>::iterator i = game->pickups.begin(); i != game->pickups.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    for (list<Badguy>::iterator i = game->badguys.begin(); i != game->badguys.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    for (list<Slime>::iterator i = game->slimes.begin(); i != game->slimes.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    game->objects.push_back(game->weaponSprite);
    game->weaponSprite->collisions.clear();
    game->objects.push_back(game->character);
    game->character->collisions.clear();
    for (list<Wall>::iterator i = game->doors.begin(); i != game->doors.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
    for (list<Boss>::iterator i = game->bosses.begin(); i!= game->bosses.end(); i++)
    {
        game->objects.push_back(&(*i));
        i->collisions.clear();
    }
}
