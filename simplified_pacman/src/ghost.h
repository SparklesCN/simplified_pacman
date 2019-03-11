#ifndef GHOST_H
#define GHOST_H
#include "constants.h"
#include "loadTexture.h"
#include <SDL2/SDL.h>

//The dot that will move around on the screen
class Ghost
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 23;
    static const int DOT_HEIGHT = 20;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 80;
    
    //Initializes the variables
    Ghost();
    Ghost(std::string kinds, float x, float y);
    
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );
    
    //Moves the dot
    void move( float timeStep );
    
    //Shows the dot on the screen
    void render(SDL_Renderer* gRenderer);
    
    //Scene textures
    LTexture mTexture;
    
private:
    std::string ghostKinds;
    std::string currentPic;
    float mPosX, mPosY;
    float mVelX, mVelY;
    std::string nextPic();
    int nextPicDelay;
};
#endif
