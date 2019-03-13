#include "ghost.h"

Ghost::Ghost()
{
    //Initialize the position
    mPosX = 309;
    mPosY = 339;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    
    //Initialize the currentPic
    currentPic = "data/images/pacman_right_1.png";
    nextPicDelay = 0;
}

Ghost::Ghost(std::string kinds, float x, float y, Rail rail)
{
    //Initialize the position
    mPosX = x;
    mPosY = y;
    
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    
    ghostKinds = kinds;
    
    //Initialize the currentPic
    currentPic = "data/images/" + ghostKinds + "_up_1.png";
    nextPicDelay = 0;
    curRail = rail;
    isRoundEnd = true;
}

std::string Ghost::nextPic()
{
    if (nextPicDelay++ == 100) {
        std::string nextPicture;
        
        if (isFood) {
            if (foodModeNearDone) {
                if (currentPic == "data/images/escaping_ghost_white_1.png") {
                    nextPicture = "data/images/escaping_ghost_1.png";
                }
                else if (currentPic == "escaping_ghost_1.png") {
                    nextPicture = "data/images/escaping_ghost_white_1.png";
                }
                else{
                    nextPicture = "data/images/escaping_ghost_white_1.png";
                }
                currentPic = nextPicture;
                nextPicDelay = 0;
                return nextPicture;
            }
            else {
                if (currentPic == "data/images/escaping_ghost_1.png") {
                    nextPicture = "data/images/escaping_ghost_2.png";
                }
                else if (currentPic == "data/images/escaping_ghost_2.png") {
                    nextPicture = "data/images/escaping_ghost_1.png";
                }
                else{
                    nextPicture = "data/images/escaping_ghost_1.png";
                }
                currentPic = nextPicture;
                nextPicDelay = 0;
                return nextPicture;
            }
        }
        
        else {
            if (currentPic == "data/images/" + ghostKinds + "_up_1.png") {
                nextPicture = "data/images/" + ghostKinds + "_up_2.png";
            }
            else if (currentPic == "data/images/" + ghostKinds + "_up_2.png") {
                nextPicture = "data/images/" + ghostKinds + "_up_1.png";
            }
            
            else if (currentPic == "data/images/" + ghostKinds + "_down_1.png") {
                nextPicture = "data/images/" + ghostKinds + "_down_2.png";
            }
            else if (currentPic == "data/images/" + ghostKinds + "_down_2.png") {
                nextPicture = "data/images/" + ghostKinds + "_down_1.png";
            }
            
            else if (currentPic == "data/images/" + ghostKinds + "_left_1.png") {
                nextPicture = "data/images/" + ghostKinds + "_left_2.png";
            }
            else if (currentPic == "data/images/" + ghostKinds + "_left_2.png") {
                nextPicture = "data/images/" + ghostKinds + "_left_1.png";
            }
            
            else if (currentPic == "data/images/" + ghostKinds + "_right_1.png") {
                nextPicture = "data/images/" + ghostKinds + "_right_2.png";
            }
            else if (currentPic == "data/images/" + ghostKinds + "_right_2.png") {
                nextPicture = "data/images/" + ghostKinds + "_right_1.png";
            }
            else
            {
                nextPicture = "data/images/" + ghostKinds + "_up_1.png";
            }
            
            currentPic = nextPicture;
            nextPicDelay = 0;
            return nextPicture;
        }
    }
    return currentPic;
}

void Ghost::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: currentPic = "data/images/" + ghostKinds + "_up_1.png"; mVelY = 0; mVelX = 0; mVelY -= DOT_VEL; break;
            case SDLK_DOWN: currentPic = "data/images/" + ghostKinds + "_down_1.png"; mVelY = 0; mVelX = 0; mVelY += DOT_VEL; break;
            case SDLK_LEFT: currentPic = "data/images/" + ghostKinds + "_left_1.png"; mVelY = 0; mVelX = 0; mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: currentPic = "data/images/" + ghostKinds + "_right_1.png"; mVelY = 0; mVelX = 0; mVelX += DOT_VEL; break;
        }
    }
}

bool Ghost::isOutCurRail()
{
    if(mPosX < curRail.x1 || mPosX > curRail.x2 || mPosY < curRail.y1 || mPosY > curRail.y2) {
        return true;
    }
    //    std::cout << "??????" << curDirection << std::endl;
    return false;
}

void Ghost::move( float timeStep, Pacman pacman )
{
    int randInt = (rand() % (4-1+1))+ 1;
    
//    if (pacman.mPosX < mPosX) {
//        // move left set
//        currentPic = "data/images/" + ghostKinds + "_left_1.png";
//        curDirection = "LEFT";
//        mVelY = 0;
//        mVelX = 0;
//        mVelX = -144;
//    }
//    else if(pacman.mPosX > mPosX) {
//        // move right set
//        currentPic = "data/images/" + ghostKinds + "_right_1.png";
//        curDirection = "RIGHT";
//        mVelY = 0;
//        mVelX = 0;
//        mVelX = 144;
//    }
//    else if(pacman.mPosY < mPosY) {
//        // move up set
//        currentPic = "data/images/" + ghostKinds + "_up_1.png";
//        curDirection = "UP";
//        mVelY = 0;
//        mVelX = 0;
//        mVelY = -144;
//    }
//    else if(pacman.mPosY > mPosY) {
//        // move down set
//        currentPic = "data/images/" + ghostKinds + "_down_1.png";
//        curDirection = "DOWN";
//        mVelY = 0;
//        mVelX = 0;
//        mVelY = 144;
//    }

    if (pacman.isMoving() && randInt == 1 && (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown())) {
        // move left set
        if (!isFood) {
            currentPic = "data/images/" + ghostKinds + "_left_1.png";
        }
        
        curDirection = "LEFT";
        mVelY = 0;
        mVelX = 0;
        mVelX = -144;
    }
    else if (pacman.isMoving() && randInt == 2 && (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown())) {
        // move right set
        if (!isFood) {
            currentPic = "data/images/" + ghostKinds + "_right_1.png";
        }
        curDirection = "RIGHT";
        mVelY = 0;
        mVelX = 0;
        mVelX = 144;
    }
    else if (pacman.isMoving() && randInt == 3 && (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown())) {
        // move up set
        if (!isFood) {
            currentPic = "data/images/" + ghostKinds + "_up_1.png";
        }
        curDirection = "UP";
        mVelY = 0;
        mVelX = 0;
        mVelY = -144;
    }
    else if (pacman.isMoving() && randInt == 4 && (onCurRailLeft() || onCurRailRight() || onCurRailUp() || onCurRailDown())) {
        // move down set
        if (!isFood) {
            currentPic = "data/images/" + ghostKinds + "_down_1.png";
        }
        curDirection = "DOWN";
        mVelY = 0;
        mVelX = 0;
        mVelY = 144;
    }
    
    
        
    
    if (pacman.isMoving()) {
        
    
    
        mPosX += mVelX * timeStep;
        mPosY += mVelY * timeStep;
        
        if (isOutCurRail()) {
            
            mVelX = 0;
            mVelY = 0;
            
            if (curDirection == "LEFT") {
                mPosX = curRail.x1;
        //                mPosY -= mVelY * timeStep;
                isLeftRail();
                
            }
            else if (curDirection == "RIGHT") {
                mPosX = curRail.x2;
        //                mPosY -= mVelY * timeStep;
                isRightRail();
            }
            else if (curDirection == "UP") {
                mPosY = curRail.y1;
        //                mPosX -= mVelX * timeStep;
                //            std::cout << "x: " << mPosX << " y: " << mPosY << std::endl;
                isUpRail();
            }
            else if (curDirection == "DOWN") {
                mPosY = curRail.y2;
        //                mPosX -= mVelX * timeStep;
                isDownRail();
            }
        }
    }
    
    collisionPacman = isCollisionPcaman(pacman);

    
    
}
bool Ghost::isCollisionPcaman(Pacman pacman)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    //Calculate the sides of rect A
    leftA = pacman.mPosX;
    rightA = pacman.mPosX + pacman.DOT_WIDTH;
    topA = pacman.mPosY;
    bottomA = pacman.mPosY + pacman.DOT_HEIGHT;
    
    //Calculate the sides of rect B
    leftB = mPosX;
    rightB = mPosX + DOT_WIDTH;
    topB = mPosY;
    bottomB = mPosY + DOT_HEIGHT;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    //If none of the sides from A are outside B
    
    return true;
}
bool Ghost::onCurRailLeft()
{
    if (curRail.y1 == curRail.y2 && mPosX == curRail.x1) {
        return true;
    }
    return false;
}
bool Ghost::onCurRailRight()
{
    if (curRail.y1 == curRail.y2 && mPosX == curRail.x2) {
        return true;
    }
    return false;
}
bool Ghost::onCurRailUp()
{
    if (curRail.x1 == curRail.x2 && mPosY == curRail.y1) {
        return true;
    }
    return false;
}
bool Ghost::onCurRailDown()
{
    if (curRail.x1 == curRail.x2 && mPosY == curRail.y2) {
        return true;
    }
    return false;
}
// set curRail as that one if found;
bool Ghost::isLeftRail()
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
bool Ghost::isRightRail()
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
bool Ghost::isUpRail()
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
bool Ghost::isDownRail()
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

void Ghost::render(SDL_Renderer* gRenderer, Pacman pacman)
{
    if (pacman.inHuntMode) {
        isFood = true;
        if (pacman.hunModeNearDone) {
            foodModeNearDone = true;
        }
    }
    else {
        foodModeNearDone = false;
        isFood = false;
    }
    //update the pic
    mTexture.loadFromFile( nextPic(), gRenderer, "BLACK" );
    
    //Show the dot
    mTexture.render( (int)mPosX, (int)mPosY, gRenderer );
    
}
