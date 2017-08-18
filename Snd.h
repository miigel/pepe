#ifndef SND_H
#define SND_H

#define SNDJUMP 0
#define SNDLASER 1
#define SNDFALLDEATH 2
#define SNDCOIN 3
#define SNDHEART 4
#define SNDHIT 5
#define SNDHITENEMY 6
#define SNDKEY 7
#define SNDKILL 8
#define SNDWEAPON 9
#define SNDDEATH 10

#include <SDL_mixer.h>
#include "error.h"

class Snd
{
    public:
        ~Snd();

        void load();
        void loadSnd(Mix_Chunk** snd, const char* file);
        void play(int soundID);

        Mix_Chunk* jump = NULL;
        Mix_Chunk* laser = NULL;
        Mix_Chunk* falldeath = NULL;
        Mix_Chunk* coin = NULL;
        Mix_Chunk* heart = NULL;
        Mix_Chunk* hit = NULL;
        Mix_Chunk* hitenemy = NULL;
        Mix_Chunk* key = NULL;
        Mix_Chunk* kill = NULL;
        Mix_Chunk* weapon = NULL;
        Mix_Chunk* death = NULL;
    protected:
    private:
};

#endif // SND_H
