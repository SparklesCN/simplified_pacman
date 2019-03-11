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
    
    furDirection = "NULL";
    
    curRail = constants.horiRails[36];
}

std::string Pacman::nextPic()
{
    if (nextPicDelay++ == 50) {
        std::string nextPicture;
//        if (mVelX == 0 && mVelY == 0) {
//            nextPicture = currentPic;
//        }
        if (currentPic == "data/images/pacman_right_1.png") {
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
                
                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown()){
                    currentPic = "data/images/pacman_up_1.png";
                    curDirection = "UP";
                    mVelY = 0;
                    mVelX = 0;
                    mVelY = -144;
                }
                
                break;
            case SDLK_DOWN:
                
                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown()){
                    currentPic = "data/images/pacman_down_1.png";
                    curDirection = "DOWN";
                    mVelY = 0;
                    mVelX = 0;
                    mVelY = 144;
                }

                
                break;
            case SDLK_LEFT:
                
                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown() || mPosX == 310){
                    currentPic = "data/images/pacman_left_1.png";
                    curDirection = "LEFT";
                    mVelY = 0;
                    mVelX = 0;
                    mVelX = -144;
                }
                
                break;
            case SDLK_RIGHT:
                
                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown() || mPosX == 310){
                    currentPic = "data/images/pacman_right_1.png";
                    curDirection = "RIGHT";
                    mVelY = 0;
                    mVelX = 0;
                    mVelX = 144;
                }

                
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

void Pacman::move()
{
    
    //Move the dot left or right
    mPosX += mVelX * timeStep;
    mPosY += mVelY * timeStep;
    if (isOutCurRail()) {

        mVelX = 0;
        mVelY = 0;
        
        if (curDirection == "LEFT") {
            mPosX = curRail.x1;
            isLeftRail();

        }
        else if (curDirection == "RIGHT") {
            mPosX = curRail.x2;
            isRightRail();
        }
        else if (curDirection == "UP") {
            mPosY = curRail.y1;
//            std::cout << "x: " << mPosX << " y: " << mPosY << std::endl;
            isUpRail();
        }
        else if (curDirection == "DOWN") {
            mPosY = curRail.y2;
            isDownRail();
        }
    }
    checkPillCollison();
    prePosX = mPosX;
    prePosY = mVelY;
    std::cout << "x: " << mPosX << " y: " << mPosY << std::endl;
    
}
bool Pacman::isMoving() {
    if (prePosX != mPosX || prePosY != mVelY) {
        return true;
    }
    return false;
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


    return "BAD RETURN";
}

void Pacman::setPills()
{
    // loop all horiRail
//        for (int i=1; i <= 48; i++) {
//            for (int x=constants.horiRails[i].x1; x<constants.horiRails[i].x2 ; x+=14) {
//                pills.push_back(Pill(x, constants.horiRails[i].y1));
//            }
//        }
//    //    std::cout << "size: " << pills.size()<<std::endl;
//    // loop all vertRail

    // row_1
    for (int i = 138; i <= 290 + 5; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    for (int i = 330; i <= 480 + 5; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    //row_2
    for (int i = 138; i <= 290; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 290; i <= 330; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 330; i <= 480 + 5; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    // row_3
    for (int i = 138; i <= 207; i+=14) {
        pills.push_back(Pill(i, 133));
    }
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 133));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 133));
    }
    for (int i = 412; i <= 480 + 5; i+=14) {
        pills.push_back(Pill(i, 133));
    }
    
    
    for (int i = 37; i <= 380 + 10; i+=14) {
        pills.push_back(Pill(207, i));
    }
//    for (int i = 330; i <= 412; i+=14) {
//        pills.push_back(Pill(i, 92));
//    }
//    for (int i = 330; i <= 412; i+=14) {
//        pills.push_back(Pill(i, 92));
//    }
//    for (int i = 330; i <= 412; i+=14) {
//        pills.push_back(Pill(i, 92));
//    }
//    for (int i = 330; i <= 412; i+=14) {
//        pills.push_back(Pill(i, 92));
//    }


//    pills.push_back(Pill(138, 37));
//    pills.push_back(Pill(218, 339));
//
//    pills.push_back(Pill(290, 37));
//
//    pills.push_back(Pill(138, 421));
//    pills.push_back(Pill(152, 421));
//    pills.push_back(Pill(166, 421));
//    pills.push_back(Pill(180, 421));
//    pills.push_back(Pill(194, 421));
//    pills.push_back(Pill(208, 421));
//    pills.push_back(Pill(222, 421));
//    pills.push_back(Pill(236, 421));
//    pills.push_back(Pill(250, 421));
//    pills.push_back(Pill(264, 421));
    //    pills.erase(pills.begin()+1);
}
void Pacman::renderAllPills(SDL_Renderer* gRenderer)
{
    for (int i=0; i<pills.size(); i++) {
        pills[i].render(gRenderer);
    }
}

void Pacman::checkPillCollison()
{
    for (int i=0; i<pills.size(); i++) {
        if (mPosX-10 <= pills[i].mPosX && mPosX+10 >= pills[i].mPosX && mPosY-10 <= pills[i].mPosY && mPosY+10 >= pills[i].mPosY) {
            pills.erase(pills.begin()+i);
        }
    }
}
