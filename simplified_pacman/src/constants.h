#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SDL2/SDL.h>

#include "rail.h"



class Constants
{
public:
    Constants();
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;
    Rail hRail_36, hRail_35;
    Rail horiRails[49];
//    Rail vertRails[42];
private:
    void setHoriRails();
//    void setVertRails();
};

























#endif
