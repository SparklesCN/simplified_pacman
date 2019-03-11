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

Ghost::Ghost(std::string kinds, float x, float y)
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
}

std::string Ghost::nextPic()
{
    if (nextPicDelay++ == 100) {
        std::string nextPicture;
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
        
        currentPic = nextPicture;
        nextPicDelay = 0;
        return nextPicture;
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

void Ghost::move( float timeStep )
{
    //Move the dot left or right
    mPosX += mVelX * timeStep;
    
    //If the dot went too far to the left or right
    if( mPosX < 0 )
    {
        mPosX = 0;
    }
    else if( mPosX > Constants::SCREEN_WIDTH - DOT_WIDTH )
    {
        mPosX = Constants::SCREEN_WIDTH - DOT_WIDTH;
    }
    
    //Move the dot up or down
    mPosY += mVelY * timeStep;
    
    //If the dot went too far up or down
    if( mPosY < 0 )
    {
        mPosY = 0;
    }
    else if( mPosY > Constants::SCREEN_HEIGHT - DOT_HEIGHT )
    {
        mPosY = Constants::SCREEN_HEIGHT - DOT_HEIGHT;
    }
}

void Ghost::render(SDL_Renderer* gRenderer)
{
    //update the pic
    mTexture.loadFromFile( nextPic(), gRenderer, "BLACK" );
    
    //Show the dot
    mTexture.render( (int)mPosX, (int)mPosY, gRenderer );
    
}
