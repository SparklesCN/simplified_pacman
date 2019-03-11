#include "pacman.h"
#include <cstdlib>
Pacman::Pacman()
{
    //Initialize the position
    mPosX = 310;
    mPosY = 339;
    prePosX = 310;
    prePosY = 339;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    
    //Initialize the currentPic
    currentPic = "data/images/pacman_right_1.png";
    nextPicDelay = 0;
    
    curRail = constants.horiRails[36];
}

std::string Pacman::nextPic()
{
    if (nextPicDelay++ == 50) {
        std::string nextPicture;
        if (mVelX == 0 && mVelY == 0) {
            nextPicture = currentPic;
        }
        else if (currentPic == "data/images/pacman_right_1.png") {
            nextPicture = "data/images/pacman_right_2.png";
        }
        
        else if (currentPic == "data/images/pacman_right_2.png") {
            nextPicture = "data/images/pacman_right_1.png";
        }
        
        else if (currentPic == "data/images/pacman_up_1.png") {
            nextPicture = "data/images/pacman_up_2.png";
        }
        
        else if (currentPic == "data/images/pacman_up_2.png") {
            nextPicture = "data/images/pacman_up_1.png";
        }
        
        else if (currentPic == "data/images/pacman_left_1.png") {
            nextPicture = "data/images/pacman_left_2.png";
        }
        else if (currentPic == "data/images/pacman_left_2.png") {
            nextPicture = "data/images/pacman_left_1.png";
        }
        else if (currentPic == "data/images/pacman_down_1.png") {
            nextPicture = "data/images/pacman_down_2.png";
        }
        else if (currentPic == "data/images/pacman_down_2.png") {
            nextPicture = "data/images/pacman_down_1.png";
        }
        
        currentPic = nextPicture;
        nextPicDelay = 0;
        return nextPicture;
    }
    return currentPic;
}

void Pacman::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                currentPic = "data/images/pacman_up_1.png";
//                if (curDirection == "UP") {
//                    furDirection = "KEEP";
//                }
//                else {
//                    furDirection = "UP";
//                }
                curDirection = "UP";
                mVelY = 0;
                mVelX = 0;
                mVelY = -144;
                break;
            case SDLK_DOWN:
                currentPic = "data/images/pacman_down_1.png";
//                if (curDirection == "DOWN") {
//                    furDirection = "KEEP";
//                }
//                else {
//                    furDirection = "DOWN";
//                }
                curDirection = "DOWN";
                mVelY = 0;
                mVelX = 0;
                mVelY = 144;
                break;
            case SDLK_LEFT:
                currentPic = "data/images/pacman_left_1.png";
//                if (curDirection == "LEFT") {
//                    furDirection = "KEEP";
//                }
//                else {
//                    furDirection = "LEFT";
//                }
                curDirection = "LEFT";
                mVelY = 0;
                mVelX = 0;
                mVelX = -144;
                break;
            case SDLK_RIGHT:
                currentPic = "data/images/pacman_right_1.png";
//                if (curDirection == "RIGHT") {
//                    furDirection = "KEEP";
//                }
//                else {
//                    furDirection = "RIGHT";
//                }
                curDirection = "RIGHT";
                mVelY = 0;
                mVelX = 0;
                mVelX = 144;
                break;
        }
    }
}

bool Pacman::isOutCurRail()
{
    if(mPosX < curRail.x1 || mPosX > curRail.x2 || mPosY < curRail.y1 || mPosY > curRail.y2) {
        return true;
    }
//    std::cout << "??????" << curDirection << std::endl;
    return false;
}

void Pacman::move( float timeStep )
{
    
    //Move the dot left or right
    mPosX += mVelX * timeStep;


    
    mPosY += mVelY * timeStep;
    if (isOutCurRail()) {
//        printf("!!!!");
//        mPosX = prePosX;
//        mPosY = prePosY;
        mVelX = 0;
        mVelY = 0;
//        if (curDirection == "RIGHT") {
//            mPosX = curRail.x2;
//        }
        
        if (curDirection == "LEFT") {
            mPosX = curRail.x1;
//            std::cout << "beforex1: " << curRail.x1 << " beforey1: " << curRail.y1 << std::endl;
            isLeftRail();
//            std::cout << "x1: " << curRail.x1 << " y1: " << curRail.y1 << std::endl;

        }
        if (curDirection == "RIGHT") {
            mPosX = curRail.x2;
            isRightRail();
        }
        if (curDirection == "UP") {
            mPosY = curRail.y1;
//            std::cout << "x: " << mPosX << " y: " << mPosY << std::endl;
            isUpRail();
        }
        else if (curDirection == "DOWN") {
            mPosY = curRail.y2;
            isDownRail();
        }
//        prePosX = mPosX;
//        prePosY = mPosY;
    }
    
//    std::cout << "x: " << mPosX << " y: " << mPosY << std::endl;
    
}

bool Pacman::isAvaliableRail()
{
    // for loop all rails
    // loop all horizontal rails
    for (int i = 1; i <= 48; i++) {
//        std::cout << "x1: " << constants.horiRails[i].x1 << " y1: " << constants.horiRails[i].y1 << std::endl;
        
    }
    return true;
    
}

bool Pacman::onCurRailLeft()
{
    if (curRail.y1 == curRail.y2 && mPosX == curRail.x1) {
        return true;
    }
    return false;
}
bool Pacman::onCurRailRight()
{
    if (curRail.y1 == curRail.y2 && mPosX == curRail.x2) {
        return true;
    }
    return false;
}
bool Pacman::onCurRailUp()
{
    if (curRail.x1 == curRail.x2 && mPosY == curRail.y1) {
        return true;
    }
    return false;
}
bool Pacman::onCurRailDown()
{
    if (curRail.x1 == curRail.x2 && mPosY == curRail.y2) {
        return true;
    }
    return false;
}
// set curRail as that one if found;
bool Pacman::isLeftRail()
{
    for (int i = 1; i <= 48; i++) {
        if (onCurRailLeft()) {
            if (constants.horiRails[i].x2 == curRail.x1 && constants.horiRails[i].y2 == curRail.y1) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
        if (onCurRailRight()) {
//            if (constants.horiRails[i].x1 == curRail.x2 && constants.horiRails[i].y1 == curRail.y2) {
//                curRail = constants.horiRails[i];
//                return true;
//            }
            return true;
        }
        if (onCurRailUp()) {
            if (constants.horiRails[i].x2 == curRail.x1 && constants.horiRails[i].y2 == curRail.y1) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
        if (onCurRailDown()) {
            if (constants.horiRails[i].x2 == curRail.x2 && constants.horiRails[i].y2 == curRail.y2) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
    }
    return false;
}
bool Pacman::isRightRail()
{
    for (int i = 1; i <= 48; i++) {
        if (onCurRailLeft()) {
//            if (constants.horiRails[i].x2 == curRail.x1 && constants.horiRails[i].y2 == curRail.y1) {
//                curRail = constants.horiRails[i];
//                return true;
//            }
            return true;
        }
        if (onCurRailRight()) {
            if (constants.horiRails[i].x1 == curRail.x2 && constants.horiRails[i].y1 == curRail.y2) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
        if (onCurRailUp()) {
            if (constants.horiRails[i].x1 == curRail.x1 && constants.horiRails[i].y1 == curRail.y1) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
        if (onCurRailDown()) {
            if (constants.horiRails[i].x1 == curRail.x2 && constants.horiRails[i].y1 == curRail.y2) {
                curRail = constants.horiRails[i];
                return true;
            }
        }
    }
    return false;
}
bool Pacman::isUpRail()
{
    for (int i = 1; i <= 41; i++) {
        if (onCurRailLeft()) {
            if (constants.vertRails[i].x2 == curRail.x1 && constants.vertRails[i].y2 == curRail.y1) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
        if (onCurRailRight()) {
            if (constants.vertRails[i].x2 == curRail.x2 && constants.vertRails[i].y2 == curRail.y2) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
        if (onCurRailUp()) {
            if (constants.vertRails[i].x2 == curRail.x1 && constants.vertRails[i].y2 == curRail.y1) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
        if (onCurRailDown()) {
            return true;
        }
    }
    return false;
}
bool Pacman::isDownRail()
{
    for (int i = 1; i <= 41; i++) {
        if (onCurRailLeft()) {
            if (constants.vertRails[i].x1 == curRail.x1 && constants.vertRails[i].y1 == curRail.y1) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
        if (onCurRailRight()) {
            if (constants.vertRails[i].x1 == curRail.x2 && constants.vertRails[i].y1 == curRail.y2) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
        if (onCurRailUp()) {
            return true;
        }
        if (onCurRailDown()) {
            if (constants.vertRails[i].x1 == curRail.x2 && constants.vertRails[i].y1 == curRail.y2) {
                curRail = constants.vertRails[i];
                return true;
            }
        }
    }
    return false;
}

void Pacman::render(SDL_Renderer* gRenderer)
{
    //update the pic
    mTexture.loadFromFile( nextPic(), gRenderer, "WHITE" );
    
    //Show the dot
    mTexture.render( (int)mPosX, (int)mPosY, gRenderer );
}


std::string Pacman::getCurMoveDir()
{

//    if (prePosX < mPosX) {
//        return "RIGHT";
//    }
//    else if (prePosX > mPosX) {
//        return "LEFT";
//    }
//    else if (prePosY < mPosY) {
//        return "DOWN";
//    }
//    else if (prePosY > mPosY) {
//        return "UP";
//    }
//    else if (prePosX == mPosX && prePosY == mPosY) {
//        return "STAND";
//    }
    return "BAD RETURN";
}
