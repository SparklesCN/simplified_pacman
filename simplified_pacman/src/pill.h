#ifndef PILL_H
#define PILL_H
#include "constants.h"
#include "loadTexture.h"
#include <SDL2/SDL.h>
#include <vector>

//The dot that will move around on the screen
class Pill
{
public:
    //Initializes the variables
    Pill();
    Pill(float x, float y);
    //Scene textures
    LTexture mTexture;
    float mPosX, mPosY;
    void render(SDL_Renderer* gRenderer);
    
};
#endif
