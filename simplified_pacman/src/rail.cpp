
#include "rail.h"
// reference and hinted by ebuc99's pacman
// Rail is the avaliable walkway for pacman and ghosts

Rail::Rail()
{
    
}

// (x1, y1) <-> (x2, y2) is the Rail's coordinates
Rail::Rail(int init_x1, int init_y1, int init_x2, int init_y2) {
    x1 = init_x1;
    y1 = init_y1;
    x2 = init_x2;
    y2 = init_y2;
}

Rail::~Rail() {
}


