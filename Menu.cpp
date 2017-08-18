#include "Menu.h"

Menu::Menu(Screen &screen, SDL_Font &font, Gfx &gfx)
{
    this->screen = &screen;
    this->font = &font;
    this->gfx = &gfx;
}

bool Menu::loop()
{
    selection = 0;
    credits = 0;
    quit = 0;
    preplay = 0;
    play = 0;

    while(!event.quit() && !event.keyEsc() && !quit && !play)
    {
        event.update();

        screen->cls(255,255,255);

        handleKeys();
        drawMenu();

        time.hold(); //hold X milliseconds to cap fps

        screen->draw();
    }

    if (play) return 1; else return 0;
}

void Menu::handleKeys()
{
    static bool upHit;
    static bool downHit;
    static bool enterHit;

    if (!event.keyUp()) upHit = 0;
    if (!event.keyDown()) downHit = 0;
    if (!event.keyEnter()) enterHit = 0;

    if (event.keyUp() && !upHit)
    {
        upHit = 1;
        selection--;
        if (selection == -1) selection = 2;
    }

    if (event.keyDown() && !downHit)
    {
        downHit = 1;
        selection++;
        if (selection == 3) selection = 0;
    }

    if (event.keyEnter() && !enterHit)
    {
        enterHit = 1;
        if (preplay) play = 1; else
        {
            if (credits)
            {
                credits = 0;
            } else
            {
                switch (selection)
                {
                    case 0:
                    default:
                        preplay = 1;
                        break;
                    case 1:
                        credits = 1;
                        break;
                    case 2:
                        quit = 1;
                        break;
                }
            }
        }
    }
}

void Menu::drawMenu()
{
    screen->drawImage(gfx->menu, 0, 0, 0);

    if (preplay)
    {
        font->setColor(0, 0, 0);
        screen->text(*font, 10, 250, "you are pepe, a war invalid who lost his arm on a war. his other");
        screen->text(*font, 10, 270, "arm however, makes up for it as pepe has developed a serious");
        screen->text(*font, 10, 290, "triggerfinger to compensate for his missing limb.");
        screen->text(*font, 10, 330, "pepe has gone on a vacation to a faraway planet. pepe thought");
        screen->text(*font, 10, 350, "he was alone on the planet but he was wrong...");
        screen->text(*font, 10, 390, "use the arrow keys to move pepe, z to use pepe's immensely strong");
        screen->text(*font, 10, 410, "calf muscles to jump and x to fire your weapon (if you have one)");
        screen->text(*font, 10, 460, "press enter to begin your adventure!");

        return;
    }

    if (credits)
    {
        font->setColor(0, 0, 0);
        screen->text(*font, 205, 250, "programming: mikko nyman");
        screen->text(*font, 25, 270, "graphics/level design: mikko nyman, sami lindgren, jero nikkanen");
        font->setColor(255, 0, 0);
        screen->text(*font, 302, 400, "back");
    } else
    {
        if (selection == 0) font->setColor(255, 0, 0); else font->setColor(0, 0, 0);
        screen->text(*font, 300, 360, "play");
        if (selection == 1) font->setColor(255, 0, 0); else font->setColor(0, 0, 0);
        screen->text(*font, 287, 380, "credits");
        if (selection == 2) font->setColor(255, 0, 0); else font->setColor(0, 0, 0);
        screen->text(*font, 302, 400, "quit");
    }

    font->setColor(0, 0, 0);
}
