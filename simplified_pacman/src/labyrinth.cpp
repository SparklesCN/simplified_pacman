#include "labyrinth.h"

Labyrinth::Labyrinth()
{
    //Initialize the position
    mPosX = 0;
    mPosY = 0;
    
}

//void Labyrinth::handleEvent( SDL_Event& e )
//{
//    //If a key was pressed
//    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
//    {
//        //Adjust the velocity
//        switch( e.key.keysym.sym )
//        {
//            case SDLK_UP: mVelY = 0; mVelX = 0; mVelY -= DOT_VEL; break;
//            case SDLK_DOWN: mVelY = 0; mVelX = 0; mVelY += DOT_VEL; break;
//            case SDLK_LEFT: mVelY = 0; mVelX = 0; mVelX -= DOT_VEL; break;
//            case SDLK_RIGHT: mVelY = 0; mVelX = 0; mVelX += DOT_VEL; break;
//        }
//    }
//}

//void Labyrinth::move( float timeStep )
//{
//    //Move the dot left or right
//    mPosX += mVelX * timeStep;
//
//    //If the dot went too far to the left or right
//    if( mPosX < 0 )
//    {
//        mPosX = 0;
//    }
//    else if( mPosX > Constants::SCREEN_WIDTH - DOT_WIDTH )
//    {
//        mPosX = Constants::SCREEN_WIDTH - DOT_WIDTH;
//    }
//
//    //Move the dot up or down
//    mPosY += mVelY * timeStep;
//
//    //If the dot went too far up or down
//    if( mPosY < 0 )
//    {
//        mPosY = 0;
//    }
//    else if( mPosY > Constants::SCREEN_HEIGHT - DOT_HEIGHT )
//    {
//        mPosY = Constants::SCREEN_HEIGHT - DOT_HEIGHT;
//    }
//}

void Labyrinth::render(SDL_Renderer* gRenderer)
{
    //Show the dot
    mTexture.render( (int)mPosX, (int)mPosY, gRenderer );
}
