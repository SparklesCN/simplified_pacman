#include "constants.h"

Constants::Constants()
{
    hRail_36 = Rail(290, 339, 330, 339);
    hRail_35 = Rail(249, 339, 290, 339);
    setHoriRails();
}

void Constants::setHoriRails()
{
    horiRails[36] = hRail_36;
    horiRails[35] = hRail_35;
}
