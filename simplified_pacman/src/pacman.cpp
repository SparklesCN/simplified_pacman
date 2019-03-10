#include "pacman.h"
#include <cstdlib>
Pacman::Pacman()
{
    //Initialize the position
    mPosX = 310;
    mPosY = 339;
    
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
//                curDirection = "UP";
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
//                curDirection = "DOWN";
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
//                curDirection = "LEFT";
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
//                curDirection = "RIGHT";
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
    prePosX = mPosX;
    prePosY = mPosY;
    //Move the dot left or right
    mPosX += mVelX * timeStep;

//    //If the dot went too far to the left or right
//    if( mPosX < 0 )
//    {
//        mPosX = 0;
//    }
//    else if( mPosX > Constants::SCREEN_WIDTH - DOT_WIDTH )
//    {
//        mPosX = Constants::SCREEN_WIDTH - DOT_WIDTH;
//    }
    //Move the dot up or down
    
    mPosY += mVelY * timeStep;
    int velXrecord = mVelX;
    int velYrecord = mVelY;
    if (isOutCurRail()) {
//        if (ableKeepMove()) {
//            // don't reset speed
//            // change current rail to next avaliable one
//        }
//        else {
//            // reset the position
//            // reset the speed
//            mPosX = prePosX;
//            mPosY = prePosY;
//        }
        mPosX = prePosX;
        mPosY = prePosY;
        mVelX = 0;
        mVelY = 0;
    }
    if (isAvaliableRail()) {
        
    }
    //If the dot went too far up or down
//    if( mPosY < 0 )
//    {
//        mPosY = 0;
//    }
//    else if( mPosY > Constants::SCREEN_HEIGHT - DOT_HEIGHT )
//    {
//        mPosY = Constants::SCREEN_HEIGHT - DOT_HEIGHT;
//    }
//    std::cout << "curX: " << mPosX << " preX: " << prePosX << std::endl;
//    std::cout << "curY: " << mPosY << " preY: " << prePosY << std::endl;
    
    curDirection = getCurMoveDir();
//    std::cout << "curDir: " << curDirection << std::endl;
//    std::cout << "curPos: " << mPosX << ", " << mPosY << " ; prePos: " << prePosX << ", " << prePosY << std::endl;
//    std::cout << "CurDir: " << getCurMoveDir() << std::endl;
}

bool Pacman::isAvaliableRail()
{
    // for loop all rails
    return true;
    
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
