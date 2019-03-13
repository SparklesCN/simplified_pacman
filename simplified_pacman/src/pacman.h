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
#include "powerPill.h"
#include "gameTimer.h"

//The dot that will move around on the screen
class Pacman
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 23;
    static const int DOT_HEIGHT = 23;
    
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
    LTexture pillTexture;
    LTexture powerPillTexture;
    Rail curRail;
    std::vector<Pill> pills;
    std::vector<PowerPill> powerPills;
    void setPills();
    void renderAllPills(SDL_Renderer* gRenderer);
    void checkPillCollison();
    bool isMoving();
    bool isDead;
    void setPowerPills();
    void renderAllPowerPills(SDL_Renderer* gRenderer);
    void checkPowerPillCollison();
    std::string currentPic;
    bool inHuntMode;
    bool hunModeNearDone;
    LTimer huntModeTimer;
    float huntTimeCounter;

private:
    
    
    bool isLeftRail(), isRightRail(), isUpRail(), isDownRail();
    bool onCurRailDown(), onCurRailUp(), onCurRailLeft(), onCurRailRight();
    bool isCurRailHori(), isCurRailVert();
    Constants constants;
    bool isAvaliableRail();
    bool isOutCurRail();
    std::string getCurMoveDir();
    int powerPillNextPicDelay;
    std::string powerPillCurPic;
    std::string powerPillNextPic();
    float mVelX, mVelY;
    std::string nextPic();
    int nextPicDelay;
    bool isMoved = false;
    std::string curDirection, furDirection;
};
#endif
