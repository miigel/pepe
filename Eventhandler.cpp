#include "Eventhandler.h"

Eventhandler::Eventhandler()
{
    keystate = SDL_GetKeyState(NULL); //store key press information in this variable
}

void Eventhandler::update()
{
    quit_ = 0;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) quit_ = 1; //when user wants to quit the program
    }

    SDL_GetMouseState(&mouseX_, &mouseY_);
}

bool Eventhandler::quit()
{
    return quit_;
}

int Eventhandler::mouseX()
{
    return mouseX_;
}

int Eventhandler::mouseY()
{
    return mouseY_;
}

bool Eventhandler::mouseLeft()
{
    return (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1));
}

bool Eventhandler::mouseRight()
{
    return (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(3));
}




//key presses:

bool Eventhandler::keyUp()
{
    return keystate[SDLK_UP];
}

bool Eventhandler::keyLeft()
{
    return keystate[SDLK_LEFT];
}

bool Eventhandler::keyRight()
{
    return keystate[SDLK_RIGHT];
}

bool Eventhandler::keyDown()
{
    return keystate[SDLK_DOWN];
}

bool Eventhandler::keyZ()
{
    return keystate[SDLK_z];
}

bool Eventhandler::keyX()
{
    return keystate[SDLK_x];
}

bool Eventhandler::keySpace()
{
    return keystate[SDLK_SPACE];
}

bool Eventhandler::keyEsc()
{
    return keystate[SDLK_ESCAPE];
}

bool Eventhandler::keyEnter()
{
    return keystate[SDLK_RETURN];
}
