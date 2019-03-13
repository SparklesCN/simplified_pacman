#include "powerPill.h"

PowerPill::PowerPill(){}

PowerPill::PowerPill(float x, float y)
{
    mPosX = x;
    mPosY = y;
    curPicture = "data/images/superpille_1.png";
    nextPicDelay = 0;
}

void PowerPill::render(SDL_Renderer* gRenderer)
{
    //update the pic
    
    mTexture.loadFromFile( nextPic(), gRenderer, "BLACK" );
    
    //Show the dot
    mTexture.render( (int)mPosX + 10, (int)mPosY + 10, gRenderer );
    
}

std::string PowerPill::nextPic()
{
    std::string nextPicture;
    if (nextPicDelay++ == 50)
    {
        if (curPicture == "data/images/superpille_1.png") {
            nextPicture = "data/images/superpille_2.png";
        }
        else if (curPicture == "data/images/superpille_2.png") {
            nextPicture = "data/images/superpille_3.png";
        }
        curPicture = nextPicture;
        return nextPicture;
    }
    return curPicture;
}
