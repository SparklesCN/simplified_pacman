#include "constants.h"

Constants::Constants()
{
    // Rails
    // ROWS
    // row_1  (y = 37)
    hRail_1 = Rail(138, 37, 207, 37);
    hRail_2 = Rail(207, 37, 290, 37);
    hRail_3 = Rail(330, 37, 412, 37);
    hRail_4 = Rail(412, 37, 480, 37);
    // row_2  (y = 92)
    hRail_5 = Rail(138, 92, 207, 92);
    hRail_6 = Rail(207, 92, 249, 92);
    hRail_7 = Rail(249, 92, 290, 92);
    hRail_8 = Rail(290, 92, 330, 92);
    hRail_9 = Rail(330, 92, 371, 92);
    hRail_10 = Rail(371, 92, 412, 92);
    hRail_11 = Rail(412, 92, 480, 92);
    // row_3  (y = 133)
    hRail_12 = Rail(138, 133, 207, 133);
    hRail_13 = Rail(249, 133, 290, 133);
    hRail_14 = Rail(330, 133, 371, 133);
    hRail_15 = Rail(412, 133, 480, 133);
    // row_4  (y = 174)
    hRail_16 = Rail(249, 174, 290, 174);
    hRail_17 = Rail(290, 174, 310, 174);
    hRail_18 = Rail(310, 174, 330, 174);
    hRail_19 = Rail(330, 174, 371, 174);
    // row_5 (y = 215)
    hRail_20 = Rail(138, 215, 207, 215); // left tunnel
    hRail_21 = Rail(207, 215, 249, 215);
    hRail_22 = Rail(290, 215, 310, 215);
    hRail_23 = Rail(310, 215, 330, 215);
    hRail_24 = Rail(371, 215, 412, 215);
    hRail_25 = Rail(412, 215, 480, 215); // right tunnel
    // row_6 (y = 257)
    hRail_26 = Rail(249, 257, 371, 257);
    // row_7 (y = 298)
    hRail_27 = Rail(138, 298, 207, 298);
    hRail_28 = Rail(207, 298, 249, 298);
    hRail_29 = Rail(249, 298, 290, 298);
    hRail_30 = Rail(330, 298, 371, 298);
    hRail_31 = Rail(371, 298, 412, 298);
    hRail_32 = Rail(412, 298, 480, 298);
    // row_8  (y = 339)
    hRail_33 = Rail(138, 339, 166, 339);
    hRail_34 = Rail(207, 339, 249, 339);
    hRail_35 = Rail(249, 339, 290, 339);
    hRail_36 = Rail(290, 339, 330, 339);
    hRail_37 = Rail(330, 339, 371, 339);
    hRail_38 = Rail(371, 339, 412, 339);
    hRail_39 = Rail(452, 339, 480, 339);
    // row_9 (y = 380)
    hRail_40 = Rail(138, 380, 166, 380);
    hRail_41 = Rail(166, 380, 207, 380);
    hRail_42 = Rail(249, 380, 290, 380);
    hRail_43 = Rail(330, 380, 371, 380);
    hRail_44 = Rail(412, 380, 452, 380);
    hRail_45 = Rail(452, 380, 480, 380);
    // row_10 (y = 421)
    hRail_46 = Rail(138, 421, 290, 421);
    hRail_47 = Rail(290, 421, 330, 421);
    hRail_48 = Rail(330, 421, 480, 421);
    // COLUMNS
    // col_1 (x = 138)
    vRail_1 = Rail(138, 37, 138, 92);
    vRail_2 = Rail(138, 92, 138, 133);
    vRail_3 = Rail(138, 298, 138, 339);
    vRail_4 = Rail(138, 380, 138, 421);
    // col_2 (x = 166)
    vRail_5 = Rail(166, 339, 166, 380);
    // col_3 (x = 207)
    vRail_6 = Rail(207, 37, 207, 92);
    vRail_7 = Rail(207, 92, 207, 133);
    vRail_8 = Rail(207, 133, 207, 215);
    vRail_9 = Rail(207, 215, 207, 298);
    vRail_10 = Rail(207, 298, 207, 339);
    vRail_11 = Rail(207, 339, 207, 380);
    // col_4 (x = 249)
    vRail_12 = Rail(249, 92, 249, 133);
    vRail_13 = Rail(249, 174, 249, 215);
    vRail_14 = Rail(249, 215, 249, 257);
    vRail_15 = Rail(249, 257, 249, 298);
    vRail_16 = Rail(249, 339, 249, 380);
    // col_5 (x = 290)
    vRail_17 = Rail(290, 37, 290, 92);
    vRail_18 = Rail(290, 133, 290, 174);
    vRail_19 = Rail(290, 298, 290, 339);
    vRail_20 = Rail(290, 380, 290, 421);
    // col_6 (x = 310)
    vRail_21 = Rail(310, 174, 310, 215);
    // col_7 (x = 330)
    vRail_22 = Rail(330, 37, 330, 92);
    vRail_23 = Rail(330, 133, 330, 174);
    vRail_24 = Rail(330, 298, 330, 339);
    vRail_25 = Rail(330, 380, 330, 421);
    // col_8 (x = 371)
    vRail_26 = Rail(371, 92, 371, 133);
    vRail_27 = Rail(371, 174, 371, 215);
    vRail_28 = Rail(371, 215, 371, 257);
    vRail_29 = Rail(371, 257, 371, 298);
    vRail_30 = Rail(371, 339, 371, 380);
    // col_9 (x = 412)
    vRail_31 = Rail(412, 37, 412, 92);
    vRail_32 = Rail(412, 92, 412, 133);
    vRail_33 = Rail(412, 133, 412, 215);
    vRail_34 = Rail(412, 215, 412, 298);
    vRail_35 = Rail(412, 298, 412, 339);
    vRail_36 = Rail(412, 339, 412, 380);
    // col_10 (x = 452)
    vRail_37 = Rail(452, 339, 452, 380);
    // col_11 (x = 480)
    vRail_38 = Rail(480, 37, 480, 92);
    vRail_39 = Rail(480, 92, 480, 133);
    vRail_40 = Rail(480, 298, 480, 339);
    vRail_41 = Rail(480, 380, 480, 421);
    setHoriRails();
}

void Constants::setHoriRails()
{
    horiRails[36] = hRail_36;
    horiRails[35] = hRail_35;
}

void Constants::setVertRails()
{
    
}
