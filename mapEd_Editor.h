#ifndef EDITOR_H
#define EDITOR_H

#include <SDL.h>
#include <list>
#include <fstream>
#include <string>
#include "Screen.h"
#include "Gfx.h"
#include "SDL_Font.h"
#include "Eventhandler.h"
#include "Time.h"
#include "Camera.h"
#include "mapEd_Block.h"
#include "util.h"

using namespace std;

struct findBlockData
{
    bool exists = 0;
    list<Block>::iterator block;
};


class Editor
{
    public:
        Editor(Screen &screen, Gfx &gfx, SDL_Font &font, string fileName);
        ~Editor();

        void loop();
        void handleMovement();
        void getMouseCoordinates();
        void drawMouseCursor(bool mode);
        void handleBrushSizeChange();
        void handleBlockPlacement();
        void handleBlockDestroying();
        void drawBlocks();
        void blockSelect();
        findBlockData findBlock(int x, int y);

        void saveMap();
        void loadMap();
    protected:
    private:
        Screen* screen = NULL;
        Gfx* gfx = NULL;
        SDL_Font* font = NULL;
        Eventhandler event;
        Time time;
        Camera camera;

        string fileName;

        int cameraX;
        int cameraY;
        int sMouseX;
        int sMouseY;
        int gMouseX;
        int gMouseY;

        list<Block> blocks;
        int currentBlock = 1;
        int numberOfBlocks = 0;
        int brushSize = 1;

        bool enterPressed = 0;
};

#endif // EDITOR_H
