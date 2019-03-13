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
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
Constants constants;


std::vector<Pill> pills;

Pill pill(319, 339);
Pacman pacman;
Ghost pinky("pinky", 138, 37, constants.horiRails[1]);
Ghost blinky("blinky", 480, 37, constants.horiRails[4]);
Ghost clyde("clyde", 290, 215, constants.horiRails[22]);
Ghost inky("inky", 330, 215, constants.horiRails[23]);

Labyrinth labyrinth;



//Globally used font
TTF_Font *gFont = NULL;
//Rendered texture
LTexture gTextTexture;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();



//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
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
    
    //Load pacman texture
    if( !pacman.mTexture.loadFromFile( "data/images/pacman_right_1.png", gRenderer, "WHITE" ) )
    {
        printf( "Failed to load pacman texture!\n" );
        success = false;
    }
    
    
    if( !labyrinth.mTexture.loadFromFile( "data/images/hintergrund2.png", gRenderer ) )
    {
        printf( "Failed to load labyrinth texture!\n" );
        success = false;
    }
    
    return success;
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
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            pacman.setPills();
            pacman.setPowerPills();
            //Event handler
            SDL_Event e;
            

            
            //Keeps track of time between steps
            LTimer stepTimer;
            int huntTimeRecorder = 0;
            
            //While application is running
            while( !quit )
            {
                while( (!pinky.collisionPacman && !blinky.collisionPacman && !inky.collisionPacman && !clyde.collisionPacman) || pacman.inHuntMode){
                //Handle events on queue
                    while( SDL_PollEvent( &e ) != 0 )
                    {
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                        }
                        
                        //Handle input for the pacman
                        pacman.handleEvent( e );
                        if (e.type == SDL_KEYDOWN) {
                            huntTimeRecorder++;
                        }
                    }
                    
                    //Calculate time step
                    float timeStep = stepTimer.getTicks() / 1000.f;
                    //Move for time step
                    pacman.timeStep = timeStep;
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
                    //Render pacman
                    
                    if (pacman.inHuntMode) {
                        int couter = huntTimeRecorder % 30;
                        if (couter == 0) {
                            pacman.inHuntMode = 0;
                            pinky.currentPic = "data/images/escaping_ghost_white_1.png";
                            clyde.currentPic = "data/images/escaping_ghost_white_1.png";
                            inky.currentPic = "data/images/escaping_ghost_white_1.png";
                            blinky.currentPic = "data/images/escaping_ghost_white_1.png";
                            continue;
                        }

                        pinky.currentPic = "data/images/escaping_ghost_1.png";
                        clyde.currentPic = "data/images/escaping_ghost_1.png";
                        inky.currentPic = "data/images/escaping_ghost_1.png";
                        blinky.currentPic = "data/images/escaping_ghost_1.png";
                    }
                    pacman.renderAllPills(gRenderer);
                    pacman.renderAllPowerPills(gRenderer);
                    pinky.render(gRenderer);
                    clyde.render(gRenderer);
                    inky.render(gRenderer);
                    blinky.render(gRenderer);
                    pacman.render(gRenderer);
                    
                    
                    //Update screen
                    SDL_RenderPresent( gRenderer );
                }
                pacman.isDead = true;
                for (int i = 0; i < 10; i++) {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    labyrinth.render(gRenderer);
                    pacman.renderAllPills(gRenderer);
                    pacman.renderAllPowerPills(gRenderer);
                    pinky.render(gRenderer);
                    clyde.render(gRenderer);
                    inky.render(gRenderer);
                    blinky.render(gRenderer);
                    pacman.render(gRenderer);
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(150);
                }
                
                quit = true;
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}
