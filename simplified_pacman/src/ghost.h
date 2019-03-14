#ifndef GHOST_H
#define GHOST_H
#include "constants.h"
#include "loadTexture.h"
#include <SDL2/SDL.h>
#include "rail.h"
#include "pacman.h"
#include <time.h>
#include "gameTimer.h"

//The dot that will move around on the screen
class Ghost
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 23;
    static const int DOT_HEIGHT = 23;
    
    //Maximum axis velocity of the dot
    static const int DOT_VEL = 80;
    bool collisionPacman = false;
    //Initializes the variables
    Ghost();
    Ghost(std::string kinds, float x, float y, Rail curRail);
        
    //Moves the dot
    void move( float timeStep, Pacman pacman );
    
    //Shows the dot on the screen
    std::string currentPic;
    void render(SDL_Renderer* gRenderer, Pacman pacman);
    std::string curDirection;
    bool isRoundEnd;
    //Scene textures
    LTexture mTexture;
    Rail curRail;
    Constants constants;
    Pacman pacman;
    int huntModeCounter = 0;
    bool isFood, foodModeNearDone;
    
private:
    
    bool isCollisionPcaman(Pacman pacman);
    bool isOutCurRail();
    bool onCurRailLeft();
    bool onCurRailRight();
    bool onCurRailUp();
    bool onCurRailDown();
    bool isLeftRail();
    bool isRightRail();
    bool isUpRail();
    bool isDownRail();

    
    std::string ghostKinds;
    
    float mPosX, mPosY;
    float mVelX, mVelY;
    std::string nextPic();
    int nextPicDelay;
};
#endif
