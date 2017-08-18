#ifndef GFX_H
#define GFX_H

#include <SDL.h>
#include <SDL_image.h>
#include "error.h"

class Gfx
{
    public:
        ~Gfx();

        void load();
        void loadGfx(SDL_Surface** srfc, const char* file);
        SDL_Surface* createFlipImg(SDL_Surface* src);

        SDL_Surface* menu = NULL;

        SDL_Surface* background = NULL;

        SDL_Surface* character = NULL;
        SDL_Surface* characterMove = NULL;
        SDL_Surface* characterWpn = NULL;
        SDL_Surface* characterWpnMove = NULL;
        SDL_Surface* characterDead = NULL;
        SDL_Surface* characterFlip = NULL;
        SDL_Surface* characterMoveFlip = NULL;
        SDL_Surface* characterWpnFlip = NULL;
        SDL_Surface* characterWpnMoveFlip = NULL;
        SDL_Surface* characterDeadFlip = NULL;

        SDL_Surface* weapon = NULL;
        SDL_Surface* weapon2 = NULL;
        SDL_Surface* weaponFlip = NULL;

        SDL_Surface* badguy = NULL;
        SDL_Surface* badguyMove = NULL;
        SDL_Surface* badguyAttack = NULL;
        SDL_Surface* badguyDeath1 = NULL;
        SDL_Surface* badguyDeath2 = NULL;
        SDL_Surface* badguyDeath3 = NULL;
        SDL_Surface* badguyDeath4 = NULL;
        SDL_Surface* badguyDeath5 = NULL;
        SDL_Surface* badguyDeath6 = NULL;
        SDL_Surface* badguyFlip = NULL;
        SDL_Surface* badguyMoveFlip = NULL;
        SDL_Surface* badguyAttackFlip = NULL;
        SDL_Surface* badguyDeath1Flip = NULL;
        SDL_Surface* badguyDeath2Flip = NULL;
        SDL_Surface* badguyDeath3Flip = NULL;
        SDL_Surface* badguyDeath4Flip = NULL;
        SDL_Surface* badguyDeath5Flip = NULL;
        SDL_Surface* badguyDeath6Flip = NULL;

        SDL_Surface* slime = NULL;
        SDL_Surface* slimeJump = NULL;
        SDL_Surface* slimeDeath1 = NULL;
        SDL_Surface* slimeDeath2 = NULL;
        SDL_Surface* slimeDeath3 = NULL;
        SDL_Surface* slimeDeath4 = NULL;
        SDL_Surface* slimeFlip = NULL;
        SDL_Surface* slimeJumpFlip = NULL;
        SDL_Surface* slimeDeath1Flip = NULL;
        SDL_Surface* slimeDeath2Flip = NULL;
        SDL_Surface* slimeDeath3Flip = NULL;
        SDL_Surface* slimeDeath4Flip = NULL;

        SDL_Surface* boss = NULL;
        SDL_Surface* bossAttack1 = NULL;
        SDL_Surface* bossAttack2 = NULL;
        SDL_Surface* bossDead = NULL;
        SDL_Surface* bossFlip = NULL;
        SDL_Surface* bossAttack1Flip = NULL;
        SDL_Surface* bossAttack2Flip = NULL;
        SDL_Surface* bossDeadFlip = NULL;

        SDL_Surface* laser = NULL;
        SDL_Surface* bossProjectile = NULL;

        SDL_Surface* heart = NULL;
        SDL_Surface* heart2 = NULL;

        SDL_Surface* ammo = NULL;
        SDL_Surface* ammo2 = NULL;

        SDL_Surface* coin = NULL;
        SDL_Surface* coin2 = NULL;

        SDL_Surface* redkey = NULL;
        SDL_Surface* redkey2 = NULL;
        SDL_Surface* bluekey = NULL;
        SDL_Surface* bluekey2 = NULL;
        SDL_Surface* yellowkey = NULL;
        SDL_Surface* yellowkey2 = NULL;
        SDL_Surface* greenkey = NULL;
        SDL_Surface* greenkey2 = NULL;
        SDL_Surface* whitekey = NULL;
        SDL_Surface* whitekey2 = NULL;
        SDL_Surface* blackkey = NULL;
        SDL_Surface* blackkey2 = NULL;

        SDL_Surface* reddoor = NULL;
        SDL_Surface* reddoor2 = NULL;
        SDL_Surface* bluedoor = NULL;
        SDL_Surface* bluedoor2 = NULL;
        SDL_Surface* yellowdoor = NULL;
        SDL_Surface* yellowdoor2 = NULL;
        SDL_Surface* greendoor = NULL;
        SDL_Surface* greendoor2 = NULL;
        SDL_Surface* whitedoor = NULL;
        SDL_Surface* whitedoor2 = NULL;
        SDL_Surface* blackdoor = NULL;
        SDL_Surface* blackdoor2 = NULL;

        SDL_Surface* finish = NULL;

        SDL_Surface* checkpoint = NULL;
        SDL_Surface* checkpoint2 = NULL;

        SDL_Surface* grass = NULL;
        SDL_Surface* dirt = NULL;
        SDL_Surface* stone = NULL;
        SDL_Surface* bosswall = NULL;

        SDL_Surface* bg1 = NULL;
        SDL_Surface* bg2 = NULL;
        SDL_Surface* bg3 = NULL;
        SDL_Surface* torch = NULL;
        SDL_Surface* torch2 = NULL;
        SDL_Surface* torch3 = NULL;
        SDL_Surface* skeleton = NULL;
    protected:
    private:
};

#endif // GFX_H
