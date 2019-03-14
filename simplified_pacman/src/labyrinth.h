#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "constants.h"
#include "loadTexture.h"
#include <SDL2/SDL.h>

//The dot that will move around on the screen
class Labyrinth
{
public:
    
    //Initializes the variables
    Labyrinth();
    
    
    //Shows the dot on the screen
    void render(SDL_Renderer* gRenderer);
    
    //Scene textures
    LTexture mTexture;
    
private:
    float mPosX, mPosY;
};
#endif

