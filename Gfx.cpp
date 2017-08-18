#include "Gfx.h"


Gfx::~Gfx()
{
    //free memory
    SDL_FreeSurface(menu);

    SDL_FreeSurface(background);

    SDL_FreeSurface(character);
    SDL_FreeSurface(characterMove);
    SDL_FreeSurface(characterWpn);
    SDL_FreeSurface(characterWpnMove);
    SDL_FreeSurface(characterDead);
    SDL_FreeSurface(characterFlip);
    SDL_FreeSurface(characterMoveFlip);
    SDL_FreeSurface(characterWpnFlip);
    SDL_FreeSurface(characterWpnMoveFlip);
    SDL_FreeSurface(characterDeadFlip);

    SDL_FreeSurface(weapon);
    SDL_FreeSurface(weapon2);
    SDL_FreeSurface(weaponFlip);

    SDL_FreeSurface(badguy);
    SDL_FreeSurface(badguyMove);
    SDL_FreeSurface(badguyAttack);
    SDL_FreeSurface(badguyDeath1);
    SDL_FreeSurface(badguyDeath2);
    SDL_FreeSurface(badguyDeath3);
    SDL_FreeSurface(badguyDeath4);
    SDL_FreeSurface(badguyDeath5);
    SDL_FreeSurface(badguyDeath6);
    SDL_FreeSurface(badguyFlip);
    SDL_FreeSurface(badguyMoveFlip);
    SDL_FreeSurface(badguyAttackFlip);
    SDL_FreeSurface(badguyDeath1Flip);
    SDL_FreeSurface(badguyDeath2Flip);
    SDL_FreeSurface(badguyDeath3Flip);
    SDL_FreeSurface(badguyDeath4Flip);
    SDL_FreeSurface(badguyDeath5Flip);
    SDL_FreeSurface(badguyDeath6Flip);

    SDL_FreeSurface(slime);
    SDL_FreeSurface(slimeJump);
    SDL_FreeSurface(slimeDeath1);
    SDL_FreeSurface(slimeDeath2);
    SDL_FreeSurface(slimeDeath3);
    SDL_FreeSurface(slimeDeath4);
    SDL_FreeSurface(slimeFlip);
    SDL_FreeSurface(slimeJumpFlip);
    SDL_FreeSurface(slimeDeath1Flip);
    SDL_FreeSurface(slimeDeath2Flip);
    SDL_FreeSurface(slimeDeath3Flip);
    SDL_FreeSurface(slimeDeath4Flip);

    SDL_FreeSurface(boss);
    SDL_FreeSurface(bossAttack1);
    SDL_FreeSurface(bossAttack2);
    SDL_FreeSurface(bossDead);
    SDL_FreeSurface(bossFlip);
    SDL_FreeSurface(bossAttack1Flip);
    SDL_FreeSurface(bossAttack2Flip);
    SDL_FreeSurface(bossDeadFlip);

    SDL_FreeSurface(laser);
    SDL_FreeSurface(bossProjectile);

    SDL_FreeSurface(heart);
    SDL_FreeSurface(heart2);

    SDL_FreeSurface(ammo);
    SDL_FreeSurface(ammo2);

    SDL_FreeSurface(coin);
    SDL_FreeSurface(coin2);

    SDL_FreeSurface(redkey);
    SDL_FreeSurface(redkey2);
    SDL_FreeSurface(bluekey);
    SDL_FreeSurface(bluekey2);
    SDL_FreeSurface(yellowkey);
    SDL_FreeSurface(yellowkey2);
    SDL_FreeSurface(greenkey);
    SDL_FreeSurface(greenkey2);
    SDL_FreeSurface(whitekey);
    SDL_FreeSurface(whitekey2);
    SDL_FreeSurface(blackkey);
    SDL_FreeSurface(blackkey2);

    SDL_FreeSurface(reddoor);
    SDL_FreeSurface(reddoor2);
    SDL_FreeSurface(bluedoor);
    SDL_FreeSurface(bluedoor2);
    SDL_FreeSurface(yellowdoor);
    SDL_FreeSurface(yellowdoor2);
    SDL_FreeSurface(greendoor);
    SDL_FreeSurface(greendoor2);
    SDL_FreeSurface(whitedoor);
    SDL_FreeSurface(whitedoor2);
    SDL_FreeSurface(blackdoor);
    SDL_FreeSurface(blackdoor2);

    SDL_FreeSurface(finish);

    SDL_FreeSurface(checkpoint);
    SDL_FreeSurface(checkpoint2);

    SDL_FreeSurface(grass);
    SDL_FreeSurface(dirt);
    SDL_FreeSurface(stone);
    SDL_FreeSurface(bosswall);

    SDL_FreeSurface(bg1);
    SDL_FreeSurface(bg2);
    SDL_FreeSurface(bg3);
    SDL_FreeSurface(torch);
    SDL_FreeSurface(torch2);
    SDL_FreeSurface(torch3);
    SDL_FreeSurface(skeleton);
}

void Gfx::load()
{
    //load gfx
    loadGfx(&menu, "gfx/menu.png");
    loadGfx(&background, "gfx/background.png");
    loadGfx(&character, "gfx/pepe.png");
    loadGfx(&characterMove, "gfx/pepe2.png");
    loadGfx(&characterWpn, "gfx/pepe3.png");
    loadGfx(&characterWpnMove, "gfx/pepe4.png");
    loadGfx(&characterDead, "gfx/pepe5.png");
    loadGfx(&weapon, "gfx/weapon.png");
    loadGfx(&weapon2, "gfx/weapon2.png");
    loadGfx(&badguy, "gfx/badguy.png");
    loadGfx(&badguyMove, "gfx/badguy2.png");
    loadGfx(&badguyAttack, "gfx/badguy3.png");
    loadGfx(&badguyDeath1, "gfx/badguy4.png");
    loadGfx(&badguyDeath2, "gfx/badguy5.png");
    loadGfx(&badguyDeath3, "gfx/badguy6.png");
    loadGfx(&badguyDeath4, "gfx/badguy7.png");
    loadGfx(&badguyDeath5, "gfx/badguy8.png");
    loadGfx(&badguyDeath6, "gfx/badguy9.png");
    loadGfx(&slime, "gfx/slime.png");
    loadGfx(&slimeJump, "gfx/slime2.png");
    loadGfx(&slimeDeath1, "gfx/slime3.png");
    loadGfx(&slimeDeath2, "gfx/slime4.png");
    loadGfx(&slimeDeath3, "gfx/slime5.png");
    loadGfx(&slimeDeath4, "gfx/slime6.png");
    loadGfx(&boss, "gfx/boss.png");
    loadGfx(&bossAttack1, "gfx/boss2.png");
    loadGfx(&bossAttack2, "gfx/boss3.png");
    loadGfx(&bossDead, "gfx/boss4.png");
    loadGfx(&laser, "gfx/laser.png");
    loadGfx(&bossProjectile, "gfx/bossprojectile.png");
    loadGfx(&heart, "gfx/heart.png");
    loadGfx(&heart2, "gfx/heart2.png");
    loadGfx(&ammo, "gfx/ammo.png");
    loadGfx(&ammo2, "gfx/ammo2.png");
    loadGfx(&coin, "gfx/coin.png");
    loadGfx(&coin2, "gfx/coin2.png");
    loadGfx(&redkey, "gfx/redkey.png");
    loadGfx(&redkey2, "gfx/redkey2.png");
    loadGfx(&bluekey, "gfx/bluekey.png");
    loadGfx(&bluekey2, "gfx/bluekey2.png");
    loadGfx(&yellowkey, "gfx/yellowkey.png");
    loadGfx(&yellowkey2, "gfx/yellowkey2.png");
    loadGfx(&greenkey, "gfx/greenkey.png");
    loadGfx(&greenkey2, "gfx/greenkey2.png");
    loadGfx(&whitekey, "gfx/whitekey.png");
    loadGfx(&whitekey2, "gfx/whitekey2.png");
    loadGfx(&blackkey, "gfx/blackkey.png");
    loadGfx(&blackkey2, "gfx/blackkey2.png");
    loadGfx(&reddoor, "gfx/reddoor.png");
    loadGfx(&reddoor2, "gfx/reddoor2.png");
    loadGfx(&bluedoor, "gfx/bluedoor.png");
    loadGfx(&bluedoor2, "gfx/bluedoor2.png");
    loadGfx(&yellowdoor, "gfx/yellowdoor.png");
    loadGfx(&yellowdoor2, "gfx/yellowdoor2.png");
    loadGfx(&greendoor, "gfx/greendoor.png");
    loadGfx(&greendoor2, "gfx/greendoor2.png");
    loadGfx(&whitedoor, "gfx/whitedoor.png");
    loadGfx(&whitedoor2, "gfx/whitedoor2.png");
    loadGfx(&blackdoor, "gfx/blackdoor.png");
    loadGfx(&blackdoor2, "gfx/blackdoor2.png");
    loadGfx(&finish, "gfx/finish.png");
    loadGfx(&checkpoint, "gfx/checkpoint.png");
    loadGfx(&checkpoint2, "gfx/checkpoint2.png");
    loadGfx(&grass, "gfx/grass.png");
    loadGfx(&dirt, "gfx/dirt.png");
    loadGfx(&stone, "gfx/stone.png");
    loadGfx(&bosswall, "gfx/bosswall.png");
    loadGfx(&bg1, "gfx/bg1.png");
    loadGfx(&bg2, "gfx/bg2.png");
    loadGfx(&bg3, "gfx/bg3.png");
    loadGfx(&torch, "gfx/torch.png");
    loadGfx(&torch2, "gfx/torch2.png");
    loadGfx(&torch3, "gfx/torch3.png");
    loadGfx(&skeleton, "gfx/skeleton.png");

    //make flip images
    characterFlip = createFlipImg(character);
    characterMoveFlip = createFlipImg(characterMove);
    characterWpnFlip = createFlipImg(characterWpn);
    characterWpnMoveFlip = createFlipImg(characterWpnMove);
    characterDeadFlip = createFlipImg(characterDead);
    weaponFlip = createFlipImg(weapon);
    badguyFlip = createFlipImg(badguy);
    badguyMoveFlip = createFlipImg(badguyMove);
    badguyAttackFlip = createFlipImg(badguyAttack);
    badguyDeath1Flip = createFlipImg(badguyDeath1);
    badguyDeath2Flip = createFlipImg(badguyDeath2);
    badguyDeath3Flip = createFlipImg(badguyDeath3);
    badguyDeath4Flip = createFlipImg(badguyDeath4);
    badguyDeath5Flip = createFlipImg(badguyDeath5);
    badguyDeath6Flip = createFlipImg(badguyDeath6);
    slimeFlip = createFlipImg(slime);
    slimeJumpFlip = createFlipImg(slimeJump);
    slimeDeath1Flip = createFlipImg(slimeDeath1);
    slimeDeath2Flip = createFlipImg(slimeDeath2);
    slimeDeath3Flip = createFlipImg(slimeDeath3);
    slimeDeath4Flip = createFlipImg(slimeDeath4);
    bossFlip = createFlipImg(boss);
    bossAttack1Flip = createFlipImg(bossAttack1);
    bossAttack2Flip = createFlipImg(bossAttack2);
    bossDeadFlip = createFlipImg(bossDead);
}

void Gfx::loadGfx(SDL_Surface** srfc, const char* file)
{
    *srfc = IMG_Load(file);
    if (*srfc == NULL) makeError(3, file);
}

SDL_Surface* Gfx::createFlipImg(SDL_Surface* src)
{
    //create a new blank surface
    SDL_Surface* dest = SDL_CreateRGBSurface(0, src->w, src->h, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);

    //get pixel data
    Uint32 *pixels = (Uint32*)src->pixels;
    Uint32 *pixels2 = (Uint32*)dest->pixels;

    //draw pixels from right to left in stripes
    for (int x=0; x<src->w; x++)
    {
        for (int y=0; y<src->h; y++)
        {
            pixels2[y*src->w+(src->w-1-x)] = pixels[y*src->w+x];
        }
    }

    return dest;
}
