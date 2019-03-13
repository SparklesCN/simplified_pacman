#ifndef POWERPILL_H
#define POWERPILL_H
#include "constants.h"
#include "loadTexture.h"
#include <SDL2/SDL.h>
#include <vector>

//The dot that will move around on the screen
class PowerPill
{
public:
    //Initializes the variables
    PowerPill();
    PowerPill(float x, float y);
    //Scene textures
    LTexture mTexture;
    float mPosX, mPosY;
    void render(SDL_Renderer* gRenderer);
    std::string curPicture;
private:
    std::string nextPic();
    int nextPicDelay;
    
};
#endif
