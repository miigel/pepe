#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <list>
#include <fstream>
#include <string>
#include "SDL_Font.h"
#include "Eventhandler.h"
#include "Screen.h"
#include "Gfx.h"
#include "Snd.h"
#include "Character.h"
#include "Time.h"
#include "util.h"
#include "Camera.h"
#include "Wall.h"
#include "WeaponSprite.h"
#include "Projectile.h"
#include "PickableObj.h"
#include "Badguy.h"
#include "Slime.h"
#include "Boss.h"
#include "BackgroundObject.h"
#include "CheckpointSave.h"

using namespace std;

class CheckpointSave;

class Game
{
    public:
        Game(Screen &screen, Gfx &gfx, SDL_Font &font, Snd &snd, string customMapName);
        ~Game();

        bool loop();
        void handleMovement();
        void handleShooting();
        void updateEnemies();
        void updatePhysics();
        void updateProjectiles();
        void checkForPickups();
        void handleDoors();
        void drawObjects();
        void drawUI();
        void handleDeath();
        void checkForFinish();
        void handleCheckpoints();
        void restartFromLastCheckpoint();
        void loadLevel(string fileName);
        void loadLevel(int map);
        void restartLevel();

        void loadMap(string fileName);
        void optimizeMap();


        Screen* screen = NULL;
        Gfx* gfx = NULL;
        Snd* snd = NULL;
        SDL_Font* font = NULL;
        Eventhandler event;
        Time time;
        Camera camera;

        bool quit = 0;
        bool victory = 0;

        int mapLBorder;
        int mapRBorder;
        int mapTBorder;
        int mapBBorder;

        bool customMap = 0;
        int map = 1;
        string currentLevelName = "";

        int score = 0;
        int startScore = 0;

        list<Object*> objects;
        list<Wall> walls;
        list<PickableObj> pickups;
        list<Projectile> projectiles;
        list<Badguy> badguys;
        list<Slime> slimes;
        list<Boss> bosses;
        list<Wall> doors;
        list<BackgroundObject> bgobjects;

        bool characterDeathFallTriggered = 0;

        CheckpointSave *checkpointSave;

        bool redKey = 0;
        bool blueKey = 0;
        bool yellowKey = 0;
        bool greenKey = 0;
        bool whiteKey = 0;
        bool blackKey = 0;

        Character* character = NULL;
        WeaponSprite* weaponSprite = NULL;
};

#endif // GAME_H
