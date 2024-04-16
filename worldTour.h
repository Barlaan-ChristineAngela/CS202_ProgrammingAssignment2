#ifndef WORLDTOUR_H
#define WORLDTOUR_H
#include "ride.h"

class WorldTour : public Ride{

    int tickets;

    public:
        WorldTour();

        int numTicketsNecessary();
};
#endif