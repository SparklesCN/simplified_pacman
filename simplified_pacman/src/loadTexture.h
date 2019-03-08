#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H
#include <string>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
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
    
    //Deallocates texture
    void free();
    
    //Renders texture at given point
    void render( int x, int y, SDL_Renderer* gRenderer );
    
    //Gets image dimensions
    int getWidth();
    int getHeight();
    
private:
    //The actual hardware texture
    SDL_Texture* mTexture;
    
    //Image dimensions
    int mWidth;
    int mHeight;
};
#endif
