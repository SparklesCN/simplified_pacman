#ifndef RAIL_H
#define RAIL_H
// reference and hinted by ebuc99's pacman
// Rail is the avaliable walkway for pacman and ghosts
// (x1, y1) <-> (x2, y2) is the Rail's coordinates

class Rail {
    public:
        Rail(int init_x1, int init_y1, int init_x2, int init_y2);
        ~Rail();
        int x1;
        int y1;
        int x2;
        int y2;
        /*
        // NOT FOR CURRENT VERSION
        int idxPills[12];
        int numPills;      // number of pills on this rail (visible and invisible)
        */
};
#endif

