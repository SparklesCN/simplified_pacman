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
    powerPillNextPicDelay = 0;
    
    furDirection = "NULL";
    powerPillCurPic = "data/images/superpille_1.png";
    curRail = constants.horiRails[36];
    
}

std::string Pacman::nextPic()
{
    std::string nextPicture;
    if (isDead) {
        if (currentPic == "data/images/pacman_die_1.png") {
            nextPicture = "data/images/pacman_die_2.png";
        }
        else if (currentPic == "data/images/pacman_die_2.png") {
            nextPicture = "data/images/pacman_die_3.png";
        }
        else if (currentPic == "data/images/pacman_die_3.png") {
            nextPicture = "data/images/pacman_die_4.png";
        }
        else if (currentPic == "data/images/pacman_die_4.png") {
            nextPicture = "data/images/pacman_die_5.png";
        }
        else if (currentPic == "data/images/pacman_die_5.png") {
            nextPicture = "data/images/pacman_die_6.png";
        }
        else if (currentPic == "data/images/pacman_die_6.png") {
            nextPicture = "data/images/pacman_die_7.png";
        }
        else if (currentPic == "data/images/pacman_die_7.png") {
            nextPicture = "data/images/pacman_die_8.png";
        }
        else if (currentPic == "data/images/pacman_die_8.png") {
            nextPicture = "data/images/pacman_die_9.png";
        }
        else if (currentPic == "data/images/pacman_die_9.png") {
            nextPicture = "data/images/pacman_die_10.png";
        }
        else {
            nextPicture = "data/images/pacman_die_1.png";
        }
        currentPic = nextPicture;
        return nextPicture;
    }
    else if (nextPicDelay++ == 50) {
        
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
                
//                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown()){
                currentPic = "data/images/pacman_up_1.png";
                curDirection = "UP";
                mVelY = 0;
                mVelX = 0;
                mVelY = -144;
//                }
                
                break;
            case SDLK_DOWN:
                
//                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown()){
                currentPic = "data/images/pacman_down_1.png";
                curDirection = "DOWN";
                mVelY = 0;
                mVelX = 0;
                mVelY = 144;
//                }

                
                break;
            case SDLK_LEFT:
                
//                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown() || mPosX == 310){
                currentPic = "data/images/pacman_left_1.png";
                curDirection = "LEFT";
                mVelY = 0;
                mVelX = 0;
                mVelX = -144;
//                }
                
                break;
            case SDLK_RIGHT:
                
//                if  (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown() || mPosX == 310){
                currentPic = "data/images/pacman_right_1.png";
                curDirection = "RIGHT";
                mVelY = 0;
                mVelX = 0;
                mVelX = 144;
//                }

                
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
    checkPowerPillCollison();
    if (huntModeTimer.getTicks() / 1000.f >= 10) {
        inHuntMode = false;
        hunModeNearDone = false;
    }
    else if (huntModeTimer.getTicks() / 1000.f >= 7) {
        hunModeNearDone = true;
    }
    prePosX = mPosX;
    prePosY = mVelY;
    
    
}
bool Pacman::isMoving() {
    if (mVelX == 0 && mVelY == 0) {
        return false;
    }
    return true;
}
bool Pacman::isAvaliableRail()
{
    // for loop all rails
    // loop all horizontal rails
    for (int i = 1; i <= 48; i++) {
        
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

void Pacman::setPowerPills()
{
    powerPills.push_back(PowerPill(138, 64));
    powerPills.push_back(PowerPill(480, 64));
    powerPills.push_back(PowerPill(138, 339));
    powerPills.push_back(PowerPill(480, 339));
    powerPills.push_back(PowerPill(1000, 339));
}
std::string Pacman::powerPillNextPic()
{
    std::string nextPicture;
    if (powerPillNextPicDelay++ == 50)
    {
        if (powerPillCurPic == "data/images/superpille_1.png") {
            nextPicture = "data/images/superpille_2.png";
        }
        else if (powerPillCurPic == "data/images/superpille_2.png") {
            nextPicture = "data/images/superpille_3.png";
        }
        else if (powerPillCurPic == "data/images/superpille_3.png") {
            nextPicture = "data/images/superpille_1.png";
        }
        powerPillCurPic = nextPicture;
        powerPillNextPicDelay = 0;
        return nextPicture;
    }
    return powerPillCurPic;
}

void Pacman::renderAllPowerPills(SDL_Renderer* gRenderer)
{
    powerPillTexture.loadFromFile( powerPillNextPic(), gRenderer, "BLACK" );
    for (int i=0; i<powerPills.size(); i++) {
        //Show the dot
        
        powerPillTexture.render( (int)powerPills[i].mPosX + 6, (int)powerPills[i].mPosY + 6, gRenderer );
    }
}

void Pacman::checkPowerPillCollison()
{
    for (int i=0; i<pills.size(); i++) {
        if (mPosX-10 <= powerPills[i].mPosX && mPosX+10 >= powerPills[i].mPosX && mPosY-10 <= powerPills[i].mPosY && mPosY+10 >= powerPills[i].mPosY) {
            powerPills.erase(powerPills.begin()+i);
            inHuntMode = true;
            huntModeTimer.start();
        }
    }
}

void Pacman::setPills()
{
    // row_1
    for (int i = 138; i <= 207; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    for (int i = 207; i <= 290; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    for (int i = 330; i <= 412; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    for (int i = 412; i <= 480; i+=14) {
        pills.push_back(Pill(i, 37));
    }
    //row_2
    for (int i = 138; i <= 207; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 207; i <= 249; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 290; i <= 330; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 371; i <= 412; i+=14) {
        pills.push_back(Pill(i, 92));
    }
    for (int i = 412; i <= 480; i+=14) {
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
    for (int i = 412; i <= 480; i+=14) {
        pills.push_back(Pill(i, 133));
    }
    // row_4
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 174));
    }
    for (int i = 290; i <= 330; i+=14) {
        pills.push_back(Pill(i, 174));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 174));
    }
    // row_5
    for (int i = 138; i <= 249; i+=14) {
        pills.push_back(Pill(i, 215));
    }
    for (int i = 371; i <= 480+5; i+=14) {
        pills.push_back(Pill(i, 215));
    }
    // row_6
    for (int i = 249; i <= 371; i+=14) {
        pills.push_back(Pill(i, 257));
    }
    // row_7
    for (int i = 138; i <= 207; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    for (int i = 207; i <= 249; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    for (int i = 371; i <= 412; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    for (int i = 412; i <= 480; i+=14) {
        pills.push_back(Pill(i, 298));
    }
    // row_8
    for (int i = 138; i <= 166; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 207; i <= 249; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 290; i <= 330; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 371; i <= 412; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    for (int i = 452; i <= 480; i+=14) {
        pills.push_back(Pill(i, 339));
    }
    // row_9
    for (int i = 138; i <= 207; i+=14) {
        pills.push_back(Pill(i, 380));
    }
    for (int i = 249; i <= 290; i+=14) {
        pills.push_back(Pill(i, 380));
    }
    for (int i = 330; i <= 371; i+=14) {
        pills.push_back(Pill(i, 380));
    }
    for (int i = 412; i <= 480; i+=14) {
        pills.push_back(Pill(i, 380));
    }
    // row_10
    for (int i = 138; i <= 290; i+=14) {
        pills.push_back(Pill(i, 421));
    }
    for (int i = 290; i <= 330; i+=14) {
        pills.push_back(Pill(i, 421));
    }
    for (int i = 330; i <= 480; i+=14) {
        pills.push_back(Pill(i, 421));
    }
    
    // col_1
    for (int i = 37; i <= 133; i+=14) {
        pills.push_back(Pill(138, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(138, i));
    }
    for (int i = 380; i <= 421; i+=14) {
        pills.push_back(Pill(138, i));
    }
    
    // col_2
    for (int i = 37; i <= 92; i+=14) {
        pills.push_back(Pill(207, i));
    }
    for (int i = 92; i <= 133; i+=14) {
        pills.push_back(Pill(207, i));
    }
    for (int i = 133; i <= 215; i+=14) {
        pills.push_back(Pill(207, i));
    }
    for (int i = 215; i <= 298; i+=14) {
        pills.push_back(Pill(207, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(207, i));
    }
    for (int i = 339; i <= 380+5; i+=14) {
        pills.push_back(Pill(207, i));
    }
    // col_3
    for (int i = 92; i <= 133; i+=14) {
        pills.push_back(Pill(249, i));
    }
    for (int i = 174; i <= 215; i+=14) {
        pills.push_back(Pill(249, i));
    }
    for (int i = 215; i <= 257; i+=14) {
        pills.push_back(Pill(249, i));
    }
    for (int i = 257; i <= 298; i+=14) {
        pills.push_back(Pill(249, i));
    }
    for (int i = 339; i <= 380; i+=14) {
        pills.push_back(Pill(249, i));
    }
    // col_4
    for (int i = 37; i <= 92; i+=14) {
        pills.push_back(Pill(290, i));
    }
    for (int i = 133; i <= 174; i+=14) {
        pills.push_back(Pill(290, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(290, i));
    }
    for (int i = 380; i <= 421; i+=14) {
        pills.push_back(Pill(290, i));
    }
    // col_5
    for (int i = 37; i <= 92; i+=14) {
        pills.push_back(Pill(330, i));
    }
    for (int i = 133; i <= 174; i+=14) {
        pills.push_back(Pill(330, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(330, i));
    }
    for (int i = 380; i <= 421; i+=14) {
        pills.push_back(Pill(330, i));
    }
    // col_6
    for (int i = 92; i <= 133+5; i+=14) {
        pills.push_back(Pill(371, i));
    }
    for (int i = 174; i <= 215; i+=14) {
        pills.push_back(Pill(371, i));
    }
    for (int i = 215; i <= 257; i+=14) {
        pills.push_back(Pill(371, i));
    }
    for (int i = 257; i <= 298; i+=14) {
        pills.push_back(Pill(371, i));
    }
    for (int i = 339; i <= 380+5; i+=14) {
        pills.push_back(Pill(371, i));
    }
    // col_7
    for (int i = 37; i <= 92; i+=14) {
        pills.push_back(Pill(412, i));
    }
    for (int i = 92; i <= 133; i+=14) {
        pills.push_back(Pill(412, i));
    }
    for (int i = 133; i <= 215; i+=14) {
        pills.push_back(Pill(412, i));
    }
    for (int i = 215; i <= 298; i+=14) {
        pills.push_back(Pill(412, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(412, i));
    }
    for (int i = 339; i <= 380; i+=14) {
        pills.push_back(Pill(412, i));
    }
    // col_8
    for (int i = 37; i <= 92; i+=14) {
        pills.push_back(Pill(480, i));
    }
    for (int i = 92; i <= 133+5; i+=14) {
        pills.push_back(Pill(480, i));
    }
    for (int i = 298; i <= 339; i+=14) {
        pills.push_back(Pill(480, i));
    }
    for (int i = 380; i <= 421+5; i+=14) {
        pills.push_back(Pill(480, i));
    }
    
    for (int i = 0; i <= 100; i+=14) {
        pills.push_back(Pill(1000, 1000));
    }
    
    
//    for (int i = 37; i <= 92; i+=14) {
//        pills.push_back(Pill(480, i));
//    }
//    for (int i = 92; i <= 133+5; i+=14) {
//        pills.push_back(Pill(480, i));
//    }
    
//    for (int i = 37; i <= 380 + 10; i+=14) {
//        pills.push_back(Pill(207, i));
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
    pillTexture.loadFromFile( "data/images/pille.png", gRenderer, "BLACK" );
    for (int i=0; i<pills.size(); i++) {
        //Show the dot
        
        pillTexture.render( (int)pills[i].mPosX + 10, (int)pills[i].mPosY + 10, gRenderer );
    }
}

void Pacman::checkPillCollison()
{
    for (int i=0; i<pills.size(); i++) {
        if (mPosX-5 <= pills[i].mPosX && mPosX+5 >= pills[i].mPosX && mPosY-5 <= pills[i].mPosY && mPosY+5 >= pills[i].mPosY) {
            pills.erase(pills.begin()+i);
            std::cout << pills.size() << std::endl;
        }
    }
}
