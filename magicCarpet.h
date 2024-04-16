#ifndef MAGICCARPET_H
#define MAGICCARPET_H
#include "ride.h"

class MagicCarpet : public Ride{

    int tickets;

    public:
        MagicCarpet();

        int numTicketsNecessary();
};
#endif
