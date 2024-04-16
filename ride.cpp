#include "ride.h"

Ride::Ride(){
    setRideName("NONE");
    setHeightRestricted(true);
}
Ride::Ride(int num, string rideName, bool restricted){
    setRideName(rideName);
    setHeightRestricted(restricted);
}
Ride::Ride(const Ride& oldRide){
    name = oldRide.name;
    heightRestricted = oldRide.heightRestricted;
}
string Ride::getRideName(){
    return name;
}
void Ride::setRideName(string newName){
    name = newName;
}
bool Ride::getHeightRestricted(){
    return heightRestricted;
}
void Ride::setHeightRestricted(bool restricted){
    heightRestricted= restricted;
}
