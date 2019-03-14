#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <string>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "constants.h"
#include <SDL2_ttf/SDL_ttf.h>

//Texture wrapper class
class LTexture
{
public:
    //Initializes variables
    LTexture();
    
    //Deallocates memory
    ~LTexture();
    
    //Loads image at specified path
    bool loadFromFile( std::string path, SDL_Renderer* gRenderer, std::string color = "NULL" );
    
#ifdef _SDL_TTF_H
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
#endif
    
    //Deallocates texture
    void free();
    
    //Renders texture at given point
    void render( int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
    //Pixel manipulators
    bool lockTexture();
    bool unlockTexture();
    void* getPixels();
    void copyPixels( void* pixels );
    int getPitch();
    Uint32 getPixel32( unsigned int x, unsigned int y );
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer );
    //Globally used font
    TTF_Font *gFont = NULL;
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    void* mPixels;
    int mPitch;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif
