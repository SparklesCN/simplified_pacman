#include "pill.h"

Pill::Pill(){}

Pill::Pill(float x, float y)
{
    mPosX = x;
    mPosY = y;
}

void Pill::render(SDL_Renderer* gRenderer)
{
    //update the pic
    
    mTexture.loadFromFile( "data/images/pille.png", gRenderer, "BLACK" );
    
    //Show the dot
    mTexture.render( (int)mPosX + 10, (int)mPosY + 10, gRenderer );
    
}
