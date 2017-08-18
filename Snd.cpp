#include "Snd.h"


Snd::~Snd()
{
    Mix_FreeChunk(jump);
    Mix_FreeChunk(laser);
    Mix_FreeChunk(falldeath);
    Mix_FreeChunk(coin);
    Mix_FreeChunk(heart);
    Mix_FreeChunk(hit);
    Mix_FreeChunk(hitenemy);
    Mix_FreeChunk(key);
    Mix_FreeChunk(kill);
    Mix_FreeChunk(weapon);
    Mix_FreeChunk(death);

    Mix_CloseAudio();
}

void Snd::load()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    loadSnd(&jump, "snd/jump.wav");
    loadSnd(&laser, "snd/laser.wav");
    loadSnd(&falldeath, "snd/death.wav");
    loadSnd(&coin, "snd/coin.wav");
    loadSnd(&heart, "snd/heart.wav");
    loadSnd(&hit, "snd/hit.wav");
    loadSnd(&hitenemy, "snd/hitenemy.wav");
    loadSnd(&key, "snd/key.wav");
    loadSnd(&kill, "snd/kill.wav");
    loadSnd(&weapon, "snd/weapon.wav");
    loadSnd(&death, "snd/death.wav");
}

void Snd::loadSnd(Mix_Chunk** snd, const char* file)
{
    *snd = Mix_LoadWAV(file);
    if (*snd == NULL) makeError(3, file);
    Mix_VolumeChunk(*snd, 40);
}

void Snd::play(int soundID)
{
    Mix_Chunk* sound = NULL;

    switch (soundID)
    {
        case SNDJUMP:
            sound = jump;
            break;
        case SNDLASER:
            sound = laser;
            break;
        case SNDFALLDEATH:
            sound = falldeath;
            break;
        case SNDCOIN:
            sound = coin;
            break;
        case SNDHEART:
            sound = heart;
            break;
        case SNDHIT:
            sound = hit;
            break;
        case SNDHITENEMY:
            sound = hitenemy;
            break;
        case SNDKEY:
            sound = key;
            break;
        case SNDKILL:
            sound = kill;
            break;
        case SNDWEAPON:
            sound = weapon;
            break;
        case SNDDEATH:
            sound = death;
            break;
        default:
            break;
    }

    if (sound != NULL) Mix_PlayChannel(-1, sound, 0);
}
