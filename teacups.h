
#ifndef TEACUPS_H
#define TEACUPS_H
#include "ride.h"

class Teacups : public Ride{

    int tickets;

    public:
        Teacups();

        int numTicketsNecessary();
};
#endif