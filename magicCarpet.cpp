#include "magicCarpet.h"

MagicCarpet::MagicCarpet(){
    setRideName("Magic Carpet");
    setHeightRestricted(true);
}

int MagicCarpet::numTicketsNecessary(){
    tickets = 2;
    return tickets;
}

