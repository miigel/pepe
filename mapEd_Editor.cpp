#include "mapEd_Editor.h"

Editor::Editor(Screen &screen, Gfx &gfx, SDL_Font &font, string fileName)
{
    this->screen = &screen;
    this->gfx = &gfx;
    this->font = &font;
    this->fileName = fileName;

    cameraX = 0;
    cameraY = 0;
}

Editor::~Editor()
{
    //dtor
}

void Editor::loop()
{
    while(!event.quit() && !event.keyEsc())
    {
        event.update();

        getMouseCoordinates();

        handleBlockPlacement();
        handleBlockDestroying();

        handleMovement();
        camera.followPoint(cameraX, cameraY);

        screen->cls(0,255,255);
        screen->drawImage(gfx->background, 0, 0, 0);

        drawBlocks();

        drawMouseCursor(1);

        handleBrushSizeChange();

        if (event.keyEnter() && !enterPressed)
        {
            enterPressed = 1;
            blockSelect();
        }
        if (!event.keyEnter()) enterPressed = 0;

        screen->text(*font, 0,0, fileName);
        screen->text(*font, 0,15, "blocks: "+inttostr(numberOfBlocks));

        time.hold(); //hold X milliseconds to cap fps

        screen->draw();
    }
}

void Editor::blockSelect()
{
    while (!(event.keyEnter() && enterPressed == 0) && !event.quit())
    {
        screen->cls(255,255,255);
        event.update();
        if (!event.keyEnter()) enterPressed = 0;
        camera.followPoint(0,0);
        getMouseCoordinates();

        screen->drawImage(gfx->character, 0, 0, 0);
        screen->drawImage(gfx->grass, 16, 0, 0);
        screen->drawImage(gfx->weapon, 32, 0, 0);
        screen->drawImage(gfx->badguy, 48, 0, 0);
        screen->drawImage(gfx->heart, 80, 0, 0);
        screen->drawImage(gfx->slime, 96, 0, 0);
        screen->drawImage(gfx->coin, 144, 0, 0);
        screen->drawImage(gfx->ammo, 160, 0, 0);
        screen->drawImage(gfx->redkey, 176, 0, 0);
        screen->drawImage(gfx->bluekey, 192, 0, 0);
        screen->drawImage(gfx->yellowkey, 208, 0, 0);
        screen->drawImage(gfx->greenkey, 224, 0, 0);
        screen->drawImage(gfx->whitekey2, 240, 0, 0);
        screen->drawImage(gfx->blackkey, 256, 0, 0);
        screen->drawImage(gfx->reddoor, 272, 0, 0);
        screen->drawImage(gfx->bluedoor, 288, 0, 0);
        screen->drawImage(gfx->yellowdoor, 304, 0, 0);
        screen->drawImage(gfx->greendoor, 320, 0, 0);
        screen->drawImage(gfx->whitedoor, 336, 0, 0);
        screen->drawImage(gfx->blackdoor, 352, 0, 0);
        screen->drawImage(gfx->dirt, 368, 0, 0);
        screen->drawImage(gfx->bg1, 384, 0, 0);
        screen->drawImage(gfx->bg2, 432, 0, 0);
        screen->drawImage(gfx->bg3, 480, 0, 0);
        screen->drawImage(gfx->finish, 528, 0, 0);
        screen->drawImage(gfx->checkpoint, 544, 0, 0);
        screen->drawImage(gfx->stone, 560, 0, 0);
        screen->drawImage(gfx->torch, 576, 0, 0);
        screen->drawImage(gfx->skeleton, 592, 0, 0);
        screen->drawImage(gfx->boss, 0, 32, 0);
        screen->drawImage(gfx->bosswall, 624, 0, 0);

        if (event.mouseLeft())
        {
            if (gMouseX == 0 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 0;
            if (gMouseX == 1 && gMouseY == 0) currentBlock = 1;
            if (gMouseX == 2 && gMouseY == 0) currentBlock = 2;
            if (gMouseX >= 3 && gMouseX <= 4 && gMouseY >= 0 && gMouseY <= 1) currentBlock = 3;
            if (gMouseX == 5 && gMouseY == 0) currentBlock = 4;
            if (gMouseX >= 6 && gMouseX <=8 && gMouseY >= 0 && gMouseY <= 1) currentBlock = 5;
            if (gMouseX == 9 && gMouseY == 0) currentBlock = 6;
            if (gMouseX == 10 && gMouseY == 0) currentBlock = 7;
            if (gMouseX == 11 && gMouseY == 0) currentBlock = 8;
            if (gMouseX == 12 && gMouseY == 0) currentBlock = 9;
            if (gMouseX == 13 && gMouseY == 0) currentBlock = 10;
            if (gMouseX == 14 && gMouseY == 0) currentBlock = 11;
            if (gMouseX == 15 && gMouseY == 0) currentBlock = 12;
            if (gMouseX == 16 && gMouseY == 0) currentBlock = 13;
            if (gMouseX == 17 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 14;
            if (gMouseX == 18 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 15;
            if (gMouseX == 19 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 16;
            if (gMouseX == 20 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 17;
            if (gMouseX == 21 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 18;
            if (gMouseX == 22 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 19;
            if (gMouseX == 23 && gMouseY == 0) currentBlock = 20;
            if (gMouseX >= 24 && gMouseX <= 26 && gMouseY >= 0 && gMouseY <= 2) currentBlock = 21;
            if (gMouseX >= 27 && gMouseX <= 29 && gMouseY >= 0 && gMouseY <= 2) currentBlock = 22;
            if (gMouseX >= 30 && gMouseX <= 32 && gMouseY >= 0 && gMouseY <= 2) currentBlock = 23;
            if (gMouseX == 33 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 24;
            if (gMouseX == 34 && (gMouseY == 0 || gMouseY == 1)) currentBlock = 25;
            if (gMouseX == 35 && gMouseY == 0) currentBlock = 26;
            if (gMouseX == 36 && gMouseY == 0) currentBlock = 27;
            if (gMouseX >= 37 && gMouseX <= 38 && gMouseY >= 0 && gMouseY <= 2) currentBlock = 28;
            if (gMouseX >= 0 && gMouseX <= 9 && gMouseY >= 2 && gMouseY <= 8) currentBlock = 29;
            if (gMouseX == 39 && gMouseY == 0) currentBlock = 30;

        }
        screen->text(*font, 0,468, inttostr(gMouseX)+", "+inttostr(gMouseY));
        drawMouseCursor(0);
        time.hold();
        screen->draw();
    }
    enterPressed = 1;
}

void Editor::handleMovement()
{
    if (event.keyLeft()) cameraX-=16;
    if (event.keyRight()) cameraX+=16;
    if (event.keyUp()) cameraY-=16;
    if (event.keyDown()) cameraY+=16;
}

void Editor::getMouseCoordinates()
{
    gMouseX = event.mouseX() / 16 + camera.x()/16;
    gMouseY = event.mouseY() / 16 + camera.y()/16;

    sMouseX = event.mouseX() / 16 * 16;
    sMouseY = event.mouseY() / 16 * 16;
}

void Editor::handleBrushSizeChange()
{
    static bool Zhit;
    static bool Xhit;

    if (!event.keyZ()) Zhit = 0;
    if (!event.keyX()) Xhit = 0;

    if (event.keyZ() && !Zhit)
    {
        Zhit = 1;
        brushSize--;
        if (brushSize == 0) brushSize = 1;
    }

    if (event.keyX() && !Xhit)
    {
        Xhit = 1;
        brushSize++;
        if (brushSize == 21) brushSize = 20;
    }
}

void Editor::drawMouseCursor(bool mode)
{
    if (mode == 0)
    {
        for (int x=sMouseX; x<sMouseX+16; x++)
        {
            for (int y=sMouseY; y<sMouseY+16; y++)
            {
                if (x==sMouseX || x==sMouseX+15 || y==sMouseY || y==sMouseY+15)
                screen->drawPixel(x, y, 255,0,0);
            }
        }
    } else
    {
        for (int x = -(int)(brushSize*0.5+0.5)+1; x < (int)(brushSize*0.5)+1; x++)
        {
            for (int y = -(int)(brushSize*0.5+0.5)+1; y < (int)(brushSize*0.5)+1; y++)
            {
                for (int i=sMouseX+x*16; i<sMouseX+x*16+16; i++)
                {
                    for (int j=sMouseY+y*16; j<sMouseY+y*16+16; j++)
                    {
                        if (i==sMouseX+x*16 || i==sMouseX+x*16+15 || j==sMouseY+y*16 || j==sMouseY+y*16+15)
                        screen->drawPixel(i, j, 255,0,0);
                    }
                }
            }
        }
    }
}

void Editor::handleBlockPlacement()
{
    /*findBlockData data = findBlock(gMouseX, gMouseY);

    if (event.mouseLeft() && !data.exists)
    {
        Block block;
        block.x = gMouseX;
        block.y = gMouseY;
        block.ID = currentBlock;

        blocks.push_back(block);
        numberOfBlocks++;
    }*/



    if (event.mouseLeft())
    {
        for (int x = gMouseX - (int)(brushSize*0.5+0.5)+1; x < gMouseX + (int)(brushSize*0.5)+1; x++)
        {
            for (int y = gMouseY - (int)(brushSize*0.5+0.5)+1; y < gMouseY + (int)(brushSize*0.5)+1; y++)
            {
                findBlockData data = findBlock(x, y);
                if (!data.exists)
                {
                    Block block;
                    block.x = x;
                    block.y = y;
                    block.ID = currentBlock;

                    blocks.push_back(block);
                    numberOfBlocks++;
                }
            }
        }
    }
}

void Editor::handleBlockDestroying()
{
    /*findBlockData data = findBlock(gMouseX, gMouseY);

    if (event.mouseRight() && data.exists)
    {
        blocks.erase(data.block);
        numberOfBlocks--;
    }*/

    if (event.mouseRight())
    {
        for (int x = gMouseX - (int)(brushSize*0.5+0.5)+1; x < gMouseX + (int)(brushSize*0.5)+1; x++)
        {
            for (int y = gMouseY - (int)(brushSize*0.5+0.5)+1; y < gMouseY + (int)(brushSize*0.5)+1; y++)
            {
                findBlockData data = findBlock(x, y);
                if (data.exists)
                {
                    blocks.erase(data.block);
                    numberOfBlocks--;
                }
            }
        }
    }
}

void Editor::drawBlocks()
{
    for (list<Block>::iterator i = blocks.begin(); i != blocks.end(); i++)
    {
        i->draw(*gfx, *screen, camera);
    }
}

findBlockData Editor::findBlock(int x, int y)
{
    findBlockData data;
    data.exists = 0;

    for (list<Block>::iterator i = blocks.begin(); i != blocks.end(); i++)
    {
        if (i->x == x && i->y == y)
        {
            data.exists = 1;
            data.block = i;
            break;
        }
    }

    return data;
}

void Editor::saveMap()
{
    ofstream f(fileName.c_str(), ios::out | ios::binary | ios::trunc);
    if (!f.is_open()) return;

    f.write((char*)&numberOfBlocks, sizeof(int));

    for (list<Block>::iterator i = blocks.begin(); i != blocks.end(); i++)
    {
        f.write((char*)&i->x, sizeof(int));
        f.write((char*)&i->y, sizeof(int));
        f.write((char*)&i->ID, sizeof(int));
    }

    f.close();
}

void Editor::loadMap()
{
    ifstream f(fileName.c_str(), ios::in | ios::binary);
    if (!f.is_open()) return;

    f.read((char*)&numberOfBlocks, sizeof(int));

    Block block;
    for (int i=0; i<numberOfBlocks; i++)
    {
        f.read((char*)&block.x, sizeof(int));
        f.read((char*)&block.y, sizeof(int));
        f.read((char*)&block.ID, sizeof(int));

        blocks.push_back(block);
    }

    f.close();
}

