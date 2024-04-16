#include "worldTour.h"

WorldTour::WorldTour(){
    setRideName("World Tour");
    setHeightRestricted(false);
}
int WorldTour::numTicketsNecessary(){
    tickets = 1;
    return tickets;
}
