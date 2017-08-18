#include "Game.h"

Game::Game(Screen &screen, Gfx &gfx, SDL_Font &font, Snd &snd, string customMapName)
{
    this->screen = &screen;
    this->gfx = &gfx;
    this->font = &font;
    this->snd = &snd;

    checkpointSave = new CheckpointSave;

    if (customMapName != "")
    {
        customMap = 1;
        loadLevel(customMapName);
    } else customMap = 0;
}


Game::~Game()
{
    delete checkpointSave;

    delete character;
    delete weaponSprite;
}


bool Game::loop()
{
    quit = 0;
    victory = 0;
    score = 0;
    map = 1;
    if (!customMap) loadLevel(map);

    while(!event.quit() && !event.keyEsc() && !quit)
    {
        event.update();
        handleMovement();
        handleShooting();
        updateEnemies();
        updatePhysics();
        character->updateImmunity();
        weaponSprite->update();
        updateProjectiles();
        checkForPickups();
        handleDoors();
        handleDeath();
        checkForFinish();
        handleCheckpoints();

        if (!character->dead) camera.followPoint(character->x, character->y, 1, mapLBorder, mapRBorder, mapTBorder, mapBBorder);

        if (map == 5)
        {
            screen->cls(50,50,50);
        } else
        {
            screen->cls(0,255,255);
            screen->drawImage(gfx->background, 0, 0, 0);
        }


        drawObjects();
        drawUI();

        time.hold(); //hold X milliseconds to cap fps

        screen->draw();
    }
    if (victory) return 1; else return 0;
}

void Game::updatePhysics()
{
    for (list<Object*>::iterator i = objects.begin(); i != objects.end(); i++)
    {
        (*i)->updatePhysics(&objects);
    }
}

void Game::updateProjectiles()
{
    for (list<Projectile>::iterator i = projectiles.begin(); i != projectiles.end();)
    {
        if (i->update(*character, badguys, slimes, bosses, objects, *snd) == 0) //projectile gets destroyed
        {
            i = projectiles.erase(i);
            continue;
        }
        i++;
    }
}

void Game::updateEnemies()
{
    for (list<Badguy>::iterator i = badguys.begin(); i != badguys.end(); i++)
    {
        i->update(*character, projectiles, objects, walls);
    }

    for (list<Slime>::iterator i = slimes.begin(); i != slimes.end(); i++)
    {
        i->update(*character, projectiles, objects, *snd, walls);
    }

    for (list<Boss>::iterator i = bosses.begin(); i != bosses.end(); i++)
    {
        i->update(*character, projectiles, objects, *gfx, *snd);
    }
}

void Game::checkForPickups()
{
    for (list<Collision>::iterator i = character->collisions.begin(); i != character->collisions.end();)
    {
        bool skip = 0;
        for (list<PickableObj>::iterator j = pickups.begin(); j != pickups.end(); j++)
        {
            if (&*i->obj == &*j)
            {
                switch (j->ID)
                {
                    case 0:
                        character->currentWeapon = 1;
                        character->ammo += AMMOFROMWEAPON;
                        if (character->ammo > 99) character->ammo = 99;
                        score += SCOREWEAPON;
                        snd->play(SNDWEAPON);
                        break;
                    case 1:
                        character->health++;
                        if (character->health > 5) character->health = 5;
                        score += SCOREHEART;
                        snd->play(SNDHEART);
                        break;
                    case 2:
                        score += SCORECOIN;
                        snd->play(SNDCOIN);
                        break;
                    case 3:
                        character->ammo += AMMOFROMPACK;
                        if (character->ammo > 99) character->ammo = 99;
                        score += SCOREAMMO;
                        snd->play(SNDWEAPON);
                        break;
                    case 4:
                        redKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    case 5:
                        blueKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    case 6:
                        yellowKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    case 7:
                        greenKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    case 8:
                        whiteKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    case 9:
                        blackKey = 1;
                        score += SCOREKEY;
                        snd->play(SNDKEY);
                        break;
                    default:
                        break;
                }

                i = character->collisions.erase(i);
                skip = 1;
                j->destroy(objects);
                pickups.erase(j);
                break;
            }
        }
        if (!skip) i++;
    }
}

void Game::handleDoors()
{
    for (list<Collision>::iterator i = character->collisions.begin(); i != character->collisions.end(); i++)
    {
        for (list<Wall>::iterator j = doors.begin(); j != doors.end(); j++)
        {
            if (&*i->obj == &*j)
            {
                if (j->ID == 1 && redKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
                if (j->ID == 2 && blueKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
                if (j->ID == 3 && yellowKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
                if (j->ID == 4 && greenKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
                if (j->ID == 5 && whiteKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
                if (j->ID == 6 && blackKey && j->animState == 0)
                {
                    j->animState = 1;
                    j->canBlock = 0;
                    score += SCOREDOOR;
                }
            }
        }
    }
}

void Game::drawObjects()
{
    for (list<Object*>::iterator i = objects.begin(); i != objects.end(); i++)
    {
        (*i)->animUpdate();
        if ((*i)->animState >= 0 && !(*i)->isInvisible) screen->drawImage((*i)->sprite[(*i)->animState], SCREENWIDTH/2-(camera.x()-(*i)->x), SCREENHEIGHT/2-(camera.y()-(*i)->y));
    }
}

void Game::drawUI()
{
    screen->text(*font, 558, 30, "ammo: " + inttostr(character->ammo));
    screen->text(*font, 5, 5, "score: " + inttostr(score));

    for (int i = 0; i<character->health; i++)
    {
        screen->drawImage(gfx->heart, 555+i*17, 8, 0);
    }

    if (redKey) screen->drawImage(gfx->redkey, 622, 50, 0);
    if (blueKey) screen->drawImage(gfx->bluekey, 606, 50, 0);
    if (yellowKey) screen->drawImage(gfx->yellowkey, 590, 50, 0);
    if (greenKey) screen->drawImage(gfx->greenkey, 574, 50, 0);
    if (whiteKey) screen->drawImage(gfx->whitekey, 558, 50, 0);
    if (blackKey) screen->drawImage(gfx->blackkey, 542, 50, 0);
}

void Game::handleMovement()
{
    //movement:
    if (event.keyLeft() && !character->dead)
    {
        character->xSpeed -= MOVE_ACCELERATION;
        if (character->xSpeed < -MOVE_MAX_SPEED) character->xSpeed = -MOVE_MAX_SPEED;
        character->facingDir = 1;
    }
    if (event.keyRight() && !character->dead)
    {
        character->xSpeed += MOVE_ACCELERATION;
        if (character->xSpeed > MOVE_MAX_SPEED) character->xSpeed = MOVE_MAX_SPEED;
        character->facingDir = 0;
    }
    if (character->onGround) //slowing down
    {
        if (character->xSpeed > 0)
        {
            character->xSpeed -= MOVE_DEACCELERATION;
            if (character->xSpeed < 0) character->xSpeed = 0;
        }
        if (character->xSpeed < 0)
        {
            character->xSpeed += MOVE_DEACCELERATION;
            if (character->xSpeed > 0) character->xSpeed = 0;
        }
    }

    //jumping:
    if (character->onGround || character->hasCollided == 2) character->jumpTime = JUMP_MAX_HOLD+1;
    if (event.keyZ() && character->onGround && !character->jumping && !character->dead)
    {
        character->onGround = 0;
        character->jumping = 1;
        character->jumpTime = 0;
        snd->play(SNDJUMP);
    }
    if (!event.keyZ() || character->dead) character->jumping = 0;
    if (event.keyZ() && character->jumping && character->jumpTime<=JUMP_MAX_HOLD && !character->dead)
    {
        character->ySpeed = -JUMP_FORCE;
        character->jumpTime++;
    }
}


void Game::handleShooting()
{
    static bool hasShot;
    if (!event.keyX()) hasShot=0;
    if (event.keyX() && !hasShot && character->currentWeapon==1 && !character->dead && character->ammo > 0 && character->weaponCooldown == 0)
    {
        hasShot = 1;
        character->ammo--;
        character->weaponCooldown = WEAPONCOOLDOWN;
        snd->play(SNDLASER);

        Projectile projectile(gfx, PROJECTILELASER);
        if (character->facingDir == 0) projectile.x = character->x + 7; else projectile.x = character->x - 7;
        projectile.y = character->y - 4;
        if (character->facingDir == 0) projectile.xSpeed = LASER_SPEED; else projectile.xSpeed = -LASER_SPEED;

        projectiles.push_back(projectile);
        objects.push_back(&projectiles.back());
    }

    if (character->weaponCooldown) character->weaponCooldown--;
}


void Game::handleDeath()
{
    if (character->y > mapBBorder && !character->dead)
    {
        snd->play(SNDFALLDEATH);
        character->health = 0;
        characterDeathFallTriggered = 1; //we don't want the "death" animation for falling death
    }

    for (list<Badguy>::iterator i = badguys.begin(); i != badguys.end();)
    {
        if (i->y > mapBBorder && !i->dead) i->health = 0;
        if (i->dead && i->recentlyDied)
        {
            i->recentlyDied = 0;
            score += SCOREBADGUY;
            snd->play(SNDKILL);
        }
        if (!i->handleDeath(objects))
        {
            i = badguys.erase(i);
            continue;
        }
        i++;
    }

    for (list<Slime>::iterator i = slimes.begin(); i != slimes.end();)
    {
        if (i->y > mapBBorder && !i->dead) i->health = 0;
        if (i->dead && i->recentlyDied)
        {
            i->recentlyDied = 0;
            score += SCORESLIME;
            snd->play(SNDKILL);
        }
        if (!i->handleDeath(objects))
        {
            i = slimes.erase(i);
            continue;
        }
        i++;
    }

    for (list<Boss>::iterator i = bosses.begin(); i != bosses.end();)
    {
        if (i->y > mapBBorder && !i->dead) i->health = 0;
        if (i->dead && i->recentlyDied)
        {
            i->recentlyDied = 0;
            i->canCollide = 0;
            score += SCOREBOSS;
            snd->play(SNDKILL);

            for (list<Wall>::iterator j = walls.begin(); j != walls.end();)
            {
                if (j->ID == 9)
                {
                    j->destroy(objects);
                    j = walls.erase(j);
                    continue;
                }
                j++;
            }
        }
        if (!i->handleDeath(objects))
        {
            i = bosses.erase(i);
            continue;
        }
        i++;
    }



    if (character->dead)
    {
        character->canCollide = 0;
        character->currentWeapon = 0;

        if (!characterDeathFallTriggered)
        {
            characterDeathFallTriggered = 1;
            if (character->facingDir == 0) character->xSpeed = random(10, 30)*0.1;
            if (character->facingDir == 1) character->xSpeed = random(10, 30)*-0.1;
            character->ySpeed = random(-10, -5);
            snd->play(SNDDEATH);
        }
    }

    if (!character->handleDeath(objects)) restartFromLastCheckpoint();
}

void Game::checkForFinish()
{
    bool finished = 0;
    for (list<Collision>::iterator i = character->collisions.begin(); i != character->collisions.end(); i++)
    {
        for (list<BackgroundObject>::iterator j = bgobjects.begin(); j != bgobjects.end(); j++)
        {
            if (&*i->obj == &*j && j->ID == 3)
            {
                if (!character->dead) finished = 1;
                break;
            }
        }
    }

    if (finished)
    {
        if (customMap)
        {
            quit = 1;
            victory = 1;
        } else
        {
            map++;
            if (map <= MAPCOUNT) loadLevel(map); else
            {
                quit = 1;
                victory = 1;
            }
        }
    }
}


void Game::handleCheckpoints()
{
    for (list<Collision>::iterator i = character->collisions.begin(); i != character->collisions.end(); i++)
    {
        for (list<BackgroundObject>::iterator j = bgobjects.begin(); j != bgobjects.end(); j++)
        {
            if (&*i->obj == &*j && j->ID == 4 && j->animState == 0 && !character->dead)
            {
                j->animState = 1;
                checkpointSave->save(*this);
            }
        }
    }
}


void Game::restartFromLastCheckpoint()
{
    checkpointSave->load(this);
}


void Game::loadLevel(string fileName)
{
    objects.clear();
    walls.clear();
    pickups.clear();
    projectiles.clear();
    badguys.clear();
    slimes.clear();
    bosses.clear();
    doors.clear();
    bgobjects.clear();
    delete character;
    delete weaponSprite;

    currentLevelName = fileName;
    loadMap(fileName);
    optimizeMap();

    weaponSprite = new WeaponSprite(*gfx, *character);


    //to control drawing order, we don't push these to the object list until now:
    for (list<BackgroundObject>::iterator i = bgobjects.begin(); i != bgobjects.end(); i++)
    {
        objects.push_back(&(*i));
    }
    for (list<Wall>::iterator i = walls.begin(); i != walls.end(); i++)
    {
        objects.push_back(&(*i));
    }
    for (list<PickableObj>::iterator i = pickups.begin(); i != pickups.end(); i++)
    {
        objects.push_back(&(*i));
    }
    for (list<Badguy>::iterator i = badguys.begin(); i != badguys.end(); i++)
    {
        objects.push_back(&(*i));
    }
    for (list<Slime>::iterator i = slimes.begin(); i != slimes.end(); i++)
    {
        objects.push_back(&(*i));
    }
    objects.push_back(weaponSprite);
    objects.push_back(character);
    for (list<Wall>::iterator i = doors.begin(); i != doors.end(); i++)
    {
        objects.push_back(&(*i));
    }
    for (list<Boss>::iterator i = bosses.begin(); i!= bosses.end(); i++)
    {
        objects.push_back(&(*i));
    }

    startScore = score;

    characterDeathFallTriggered = 0;
    redKey = 0;
    blueKey = 0;
    yellowKey = 0;
    greenKey = 0;
    whiteKey = 0;
    blackKey = 0;

    checkpointSave->save(*this);
}

void Game::restartLevel()
{
    score = startScore;
    loadLevel(currentLevelName);
}

void Game::loadLevel(int map)
{
    loadLevel("level" + inttostr(map) + ".map");
}


void Game::loadMap(string fileName)
{
    fileName = "maps/" + fileName;
    ifstream f(fileName.c_str(), ios::in | ios::binary);
    if (!f.is_open())
    {
        makeError(3, fileName.c_str());
        return;
    }

    int numberOfBlocks, x, y, ID;
    Wall *wall = NULL;
    PickableObj pickup(*gfx);
    Badguy badguy(*gfx);
    Slime slime(*gfx);
    Boss boss(*gfx);
    BackgroundObject *bgobject = NULL;

    f.read((char*)&numberOfBlocks, sizeof(int));

    for (int i=0; i<numberOfBlocks; i++)
    {
        f.read((char*)&x, sizeof(int));
        f.read((char*)&y, sizeof(int));
        f.read((char*)&ID, sizeof(int));

        x = x*16;
        y = y*16;

        if (i==0)
        {
            mapLBorder = x;
            mapRBorder = x;
            mapTBorder = y;
            mapBBorder = y;
        } else
        {
            if (x < mapLBorder) mapLBorder = x;
            if (x > mapRBorder) mapRBorder = x;
            if (y < mapTBorder) mapTBorder = y;
            if (y > mapBBorder) mapBBorder = y;
        }

        switch (ID)
        {
            case 0:
                character = new Character(*gfx);
                character->x = x;
                character->y = y+8;
                break;
            case 1:
            default:
                wall = new Wall(*gfx, x, y, 0);
                walls.push_back(*wall);
                delete wall;
                break;
            case 2:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 0;

                pickups.push_back(pickup);
                break;
            case 3:
                badguy.x = x+9;
                badguy.y = y+8;

                badguys.push_back(badguy);
                break;
            case 4:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 1;

                pickups.push_back(pickup);
                break;
            case 5:
                slime.x = x+9;
                slime.y = y+5;

                slimes.push_back(slime);
                break;
            case 6:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 2;

                pickups.push_back(pickup);
                break;
            case 7:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 3;

                pickups.push_back(pickup);
                break;
            case 8:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 4;

                pickups.push_back(pickup);
                break;
            case 9:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 5;

                pickups.push_back(pickup);
                break;
            case 10:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 6;

                pickups.push_back(pickup);
                break;
            case 11:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 7;

                pickups.push_back(pickup);
                break;
            case 12:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 8;

                pickups.push_back(pickup);
                break;
            case 13:
                pickup.x = x;
                pickup.y = y;
                pickup.ID = 9;

                pickups.push_back(pickup);
                break;
            case 14:
                wall = new Wall(*gfx, x, y+8, 1);
                doors.push_back(*wall);
                delete wall;
                break;
            case 15:
                wall = new Wall(*gfx, x, y+8, 2);
                doors.push_back(*wall);
                delete wall;
                break;
            case 16:
                wall = new Wall(*gfx, x, y+8, 3);
                doors.push_back(*wall);
                delete wall;
                break;
            case 17:
                wall = new Wall(*gfx, x, y+8, 4);
                doors.push_back(*wall);
                delete wall;
                break;
            case 18:
                wall = new Wall(*gfx, x, y+8, 5);
                doors.push_back(*wall);
                delete wall;
                break;
            case 19:
                wall = new Wall(*gfx, x, y+8, 6);
                doors.push_back(*wall);
                delete wall;
                break;
            case 20:
                wall = new Wall(*gfx, x, y, 7);
                walls.push_back(*wall);
                delete wall;
                break;
            case 21:
                bgobject = new BackgroundObject(*gfx, x, y+16, 0);
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 22:
                bgobject = new BackgroundObject(*gfx, x, y+16, 1);
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 23:
                bgobject = new BackgroundObject(*gfx, x, y+16, 2);
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 24:
                bgobject = new BackgroundObject(*gfx, x, y+8, 3);
                bgobject->noPhysics = 0;
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 25:
                bgobject = new BackgroundObject(*gfx, x, y+8, 4);
                bgobject->noPhysics = 0;
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 26:
                wall = new Wall(*gfx, x, y, 8);
                walls.push_back(*wall);
                delete wall;
                break;
            case 27:
                bgobject = new BackgroundObject(*gfx, x, y, 5);
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 28:
                bgobject = new BackgroundObject(*gfx, x, y, 6);
                bgobjects.push_back(*bgobject);
                delete bgobject;
                break;
            case 29:
                boss.x = x+72;
                boss.y = y+45;
                bosses.push_back(boss);
                break;
            case 30:
                wall = new Wall(*gfx, x, y, 9);
                walls.push_back(*wall);
                delete wall;
                break;
        }
    }

    mapLBorder -= 8;
    mapRBorder += 8;
    mapTBorder -= 8;
    mapBBorder += 8;


    f.close();
}

void Game::optimizeMap()
{
    bool top, bottom, left, right;
    BackgroundObject *bgobject;
    list<list<Wall>::iterator> wallsToBeDeleted;

    for (list<Wall>::iterator i = walls.begin(); i != walls.end(); i++)
    {
        if (i->ID != 7 && i->ID != 8) continue;

        top = bottom = left = right = 0;

        for (list<Wall>::iterator j = walls.begin(); j != walls.end(); j++)
        {
            if ((j->ID >= 1 && j->ID <= 6) || j->ID == 9) continue;

            if (i->x == j->x - 16 && i->y == j->y) left = 1;
            if (i->x == j->x + 16 && i->y == j->y) right = 1;
            if (i->y == j->y - 16 && i->x == j->x) top = 1;
            if (i->y == j->y + 16 && i->x == j->x) bottom = 1;
        }

        if (top && bottom && left && right)
        {
            if (i->ID == 7) bgobject = new BackgroundObject(*gfx, i->x, i->y, 7); else bgobject = new BackgroundObject(*gfx, i->x, i->y, 8);
            bgobjects.push_back(*bgobject);
            delete bgobject;

            wallsToBeDeleted.push_back(i);
        }
    }

    for (list<list<Wall>::iterator>::iterator i = wallsToBeDeleted.begin(); i != wallsToBeDeleted.end(); i++)
    {
        walls.erase(*i);
    }
}
