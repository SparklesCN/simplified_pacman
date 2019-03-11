#ifndef PACMAN_H
#define PACMAN_H
#include "constants.h"
#include "loadTexture.h"
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include "rail.h"
#include <vector>
#include "pill.h"

//The dot that will move around on the screen
class Pacman
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 114;
    float mPosX, mPosY, prePosX, prePosY;
    //Initializes the variables
    Pacman();
    
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );
    
    //Moves the dot
    void move();
    float timeStep;
    //Shows the dot on the screen
    void render(SDL_Renderer* gRenderer);
    //Scene textures
    LTexture mTexture;
    Rail curRail;
    std::vector<Pill> pills;
    void setPills();
    void renderAllPills(SDL_Renderer* gRenderer);
    void checkPillCollison();

private:
    bool isMoving();
    bool isLeftRail(), isRightRail(), isUpRail(), isDownRail();
    bool onCurRailDown(), onCurRailUp(), onCurRailLeft(), onCurRailRight();
    bool isCurRailHori(), isCurRailVert();
    Constants constants;
    bool isAvaliableRail();
    bool isOutCurRail();
    std::string getCurMoveDir();
    std::string currentPic;
    
    float mVelX, mVelY;
    std::string nextPic();
    int nextPicDelay;
    std::string curDirection, furDirection;
};
#endif
