#include "teacups.h"

Teacups::Teacups(){
    setRideName("Teacups");
    setHeightRestricted(false);

}

int Teacups::numTicketsNecessary(){
    tickets = 3;
    return tickets;
}

