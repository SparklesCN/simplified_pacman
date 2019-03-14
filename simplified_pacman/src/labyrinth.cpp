#include "labyrinth.h"

Labyrinth::Labyrinth()
{
    //Initialize the position
    mPosX = 0;
    mPosY = 0;
    
}

void Labyrinth::render(SDL_Renderer* gRenderer)
{
    //Show the dot
    mTexture.render( (int)mPosX, (int)mPosY, gRenderer );
}
