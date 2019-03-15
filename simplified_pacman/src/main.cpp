/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
 and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and, strings
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <SDL2_ttf/SDL_ttf.h>
#include "pacman.h"
#include "ghost.h"
#include "gameTimer.h"
#include "labyrinth.h"
#include "rail.h"
#include "pill.h"
#include "constants.h"
#include <SDL2_mixer/SDL_mixer.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
Constants constants;


std::vector<Pill> pills;

Pill pill(319, 339);
Pacman pacman;
Ghost pinky("pinky", 138, 37, constants.horiRails[1]);
Ghost blinky("blinky", 480, 37, constants.horiRails[4]);
Ghost clyde("clyde", 249, 174, constants.horiRails[16]);
Ghost inky("inky", 371, 174, constants.horiRails[19]);

Labyrinth labyrinth;
LTexture tagTexture_gameover, tagTexture_ready, tagTexture_score;
LTexture scoreBoardTexture, tagTexture_life, lifeLeftTexture;

//Rendered texture
LTexture gTextTexture;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void checkMusic(Pacman pacman);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gIntro = NULL;
Mix_Chunk *gDead = NULL;
Mix_Chunk *gHunting = NULL;
Mix_Chunk *gPill_1 = NULL;
Mix_Chunk *gPill_2 = NULL;

bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow( "PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    scoreBoardTexture.gFont = TTF_OpenFont( "data/fonts/Cheapmot.TTF", 28 );
    lifeLeftTexture.gFont = TTF_OpenFont( "data/fonts/Cheapmot.TTF", 28 );
    tagTexture_life.gFont = TTF_OpenFont( "data/fonts/Cheapmot.TTF", 28 );
    //Load music
    gMusic = Mix_LoadMUS( "data/sounds/siren_fast.wav" );
    gDead = Mix_LoadWAV( "data/sounds/death.wav" );
    gHunting = Mix_LoadWAV( "data/sounds/siren_fast.wav" );
    gPill_1 = Mix_LoadWAV( "data/sounds/munch_a.wav" );
    gPill_2 = Mix_LoadWAV( "data/sounds/munch_b.wav" );
    gIntro = Mix_LoadWAV("data/sounds/intro.wav");
    
    //Load pacman texture
    if( !pacman.mTexture.loadFromFile( "data/images/pacman_right_1.png", gRenderer, "WHITE" ) )
    {
        printf( "Failed to load pacman texture!\n" );
        success = false;
    }
    
    tagTexture_gameover.loadFromFile( "data/images/gameover.png", gRenderer, "BLACK" );
    tagTexture_score.loadFromFile( "data/images/gamescore.png", gRenderer, "BLACK");
    
    
    if( !tagTexture_ready.loadFromFile( "data/images/getready.png", gRenderer, "BLACK") )
    {
        printf( "Failed to load red\ady texture!\n" );
        success = false;
    }
    if( !labyrinth.mTexture.loadFromFile( "data/images/hintergrund2.png", gRenderer ) )
    {
        printf( "Failed to load labyrinth texture!\n" );
        success = false;
    }
    SDL_Color textColor = { 0xff, 0xff, 0xff };
    tagTexture_life.loadFromRenderedText( "Life", textColor, gRenderer );

    
    return success;
}
bool isPillMusicA = true;
void checkMusic(Pacman pacman)
{
    if(pacman.inHuntMode) {
        if( Mix_PlayingMusic() == 0 ) {
            Mix_PlayMusic( gMusic, -1 );
        }
    }
    else if (!pacman.inHuntMode) {
        Mix_PauseMusic();
    }
    if (pacman.isEatenPill) {
        if (isPillMusicA) {
            Mix_PlayChannel( -1, gPill_1, 0 );
            isPillMusicA = false;
        }
        else {
            Mix_PlayChannel( -1, gPill_2, 0 );
            isPillMusicA = true;
        }
        
    }
    
}

void close()
{
    //Free loaded images
    pacman.mTexture.free();
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


int main( int argc, char* args[] )
{
    //Start up SDL and create window
    init();
    loadMedia();
    //Main loop flag
    bool quit = false;
    pacman.setPills();
    pacman.setPowerPills();
    
    Mix_PlayChannel( -1, gIntro, 0 );
    
    //Event handler
    SDL_Event e;
    //Keeps track of time between steps
    LTimer stepTimer, readyTimer;
    //While application is running
    readyTimer.start();
    while( !quit )
    {
        while( (!pinky.collisionPacman && !blinky.collisionPacman && !inky.collisionPacman && !clyde.collisionPacman && !quit) || pacman.inHuntMode){
        //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                    pacman.lifeLeft = -1;
                }
                //Handle input for the pacman
                pacman.handleEvent( e );
            }
            //Calculate time step
            float timeStep = stepTimer.getTicks() / 1000.f;
            //Move for time step
            pacman.timeStep = timeStep;
            checkMusic(pacman);
            pacman.move();
            
            pinky.move( timeStep, pacman );
            blinky.move(timeStep, pacman);
            inky.move(timeStep, pacman);
            clyde.move(timeStep, pacman);
            //Restart step timer
            stepTimer.start();
            
            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            labyrinth.render(gRenderer);
            tagTexture_score.render(530, 30, gRenderer);
            SDL_Color textColor = { 250, 255, 0 };
            scoreBoardTexture.loadFromRenderedText( std::to_string(pacman.score*10), textColor, gRenderer );
            lifeLeftTexture.loadFromRenderedText( std::to_string(pacman.lifeLeft), textColor, gRenderer );

            if (readyTimer.getTicks()/1000.f > 4) {
                pacman.inReady = false;
            }
            if (pacman.inReady) {
                tagTexture_ready.render(242, 257, gRenderer);
            }
            
            tagTexture_life.render(540, 340, gRenderer);
            lifeLeftTexture.render(550, 380, gRenderer);
            scoreBoardTexture.render(540, 60, gRenderer);
            pacman.renderAllPills(gRenderer);
            pacman.renderAllPowerPills(gRenderer);
            pinky.render(gRenderer, pacman);
            clyde.render(gRenderer, pacman);
            inky.render(gRenderer, pacman);
            blinky.render(gRenderer, pacman);
            pacman.render(gRenderer);
            
            
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
        
        pacman.isDead = true;
        Mix_PlayChannel( -1, gDead, 0 );
        for (int i = 0; i < 10; i++) {
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            labyrinth.render(gRenderer);
            tagTexture_score.render(530, 30, gRenderer);
            scoreBoardTexture.render(540, 60, gRenderer);
            tagTexture_life.render(540, 340, gRenderer);
            lifeLeftTexture.render(550, 380, gRenderer);
            pacman.renderAllPills(gRenderer);
            pacman.renderAllPowerPills(gRenderer);
            pinky.render(gRenderer, pacman);
            clyde.render(gRenderer, pacman);
            inky.render(gRenderer, pacman);
            blinky.render(gRenderer,pacman);
            pacman.render(gRenderer);
            SDL_RenderPresent( gRenderer );
            SDL_Delay(150);
        }
        
        SDL_Delay(1500);
        
        if (pacman.lifeLeft-- > 0) {
            Mix_PlayChannel( -1, gIntro, 0 );
            quit = false;
            pacman.isDead = false;
            //Initialize the position
            pacman.mPosX = 310;
            pacman.mPosY = 339;
            pacman.prePosX = 310;
            pacman.prePosY = 339;
            //Initialize the velocity
            pacman.mVelX = 0;
            pacman.mVelY = 0;
            //Initialize the currentPic
            pacman.currentPic = "data/images/pacman_right_1.png";
            pacman.nextPicDelay = 0;
            pacman.powerPillNextPicDelay = 0;
            pacman.powerPillCurPic = "data/images/superpille_1.png";
            pacman.curRail = constants.horiRails[36];
            pinky = Ghost ("pinky", 138, 37, constants.horiRails[1]);
            blinky = Ghost ("blinky", 480, 37, constants.horiRails[4]);
            clyde = Ghost ("clyde", 249, 174, constants.horiRails[16]);
            inky = Ghost ("inky", 371, 174, constants.horiRails[19]);
            readyTimer.start();
            pacman.inReady = true;
        }
        else {
            pacman.isDead = true;
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            
            labyrinth.render(gRenderer);
            tagTexture_score.render(530, 30, gRenderer);
            scoreBoardTexture.render(540, 60, gRenderer);
            tagTexture_life.render(540, 340, gRenderer);
            lifeLeftTexture.render(550, 380, gRenderer);
            pacman.renderAllPills(gRenderer);
            pacman.renderAllPowerPills(gRenderer);
            pinky.render(gRenderer, pacman);
            clyde.render(gRenderer, pacman);
            inky.render(gRenderer, pacman);
            blinky.render(gRenderer,pacman);
            tagTexture_gameover.render(160, 200, gRenderer);
            SDL_RenderPresent( gRenderer );
            SDL_Delay(3000);
            quit = true;
        }
        
    }
    //Free resources and close SDL
    close();
    
    return 0;
}
    


