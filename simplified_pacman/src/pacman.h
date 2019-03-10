#ifndef PACMAN_H
#define PACMAN_H
#include "constants.h"
#include "loadTexture.h"
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include "rail.h"

//The dot that will move around on the screen
class Pacman
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 114;
    
    //Initializes the variables
    Pacman();
    
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );
    
    //Moves the dot
    void move( float timeStep );
    
    //Shows the dot on the screen
    void render(SDL_Renderer* gRenderer);
    //Scene textures
    LTexture mTexture;
    Rail curRail;

private:
    Constants constants;
    bool isAvaliableRail();
    bool isOutCurRail();
    std::string getCurMoveDir();
    std::string currentPic;
    float mPosX, mPosY, prePosX, prePosY;
    float mVelX, mVelY;
    std::string nextPic();
    int nextPicDelay;
    std::string curDirection, furDirection;
};
#endif
