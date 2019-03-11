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
    Rail hRail_1, hRail_2, hRail_3, hRail_4, hRail_5, hRail_6, hRail_7, hRail_8, hRail_9, hRail_10, hRail_11, hRail_12, hRail_13, hRail_14, hRail_15, hRail_16, hRail_17, hRail_18, hRail_19, hRail_20, hRail_21, hRail_22, hRail_23, hRail_24, hRail_25, hRail_26, hRail_27, hRail_28, hRail_29, hRail_30, hRail_31, hRail_32, hRail_33, hRail_34, hRail_35, hRail_36, hRail_37, hRail_38, hRail_39, hRail_40, hRail_41, hRail_42, hRail_43, hRail_44, hRail_45, hRail_46, hRail_47, hRail_48;
    
    Rail vRail_1, vRail_2, vRail_3, vRail_4, vRail_5, vRail_6, vRail_7, vRail_8, vRail_9, vRail_10, vRail_11, vRail_12, vRail_13, vRail_14, vRail_15, vRail_16, vRail_17, vRail_18, vRail_19, vRail_20, vRail_21, vRail_22, vRail_23, vRail_24, vRail_25, vRail_26, vRail_27, vRail_28, vRail_29, vRail_30, vRail_31, vRail_32, vRail_33, vRail_34, vRail_35, vRail_36, vRail_37, vRail_38, vRail_39, vRail_40, vRail_41;
    Rail horiRails[49];
    Rail vertRails[42];
    
    
private:
    void setHoriRails();
    void setVertRails();
};

#endif






