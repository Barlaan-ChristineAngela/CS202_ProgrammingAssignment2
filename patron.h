#ifndef PATRON_H
#define PATRON_H

#include "magicCarpet.h"
#include "teacups.h"
#include "worldTour.h"
#include "dollars.h"
#include "ariarys.h"
#include "calculator.h"

class Patron{
    string firstName, lastName;
    int patronNumber, numRides, numTickets; 
    Ride* patronRides[300];

    public:
        Patron();
        ~Patron();
        Patron(string, string, int, int, int, Ride*);
        Patron(const Patron&);

        string getFirstName();
        string getLastName();
        int getPatronNumber();
        Ride* getPatronRides();
        int getNumTickets();

        void setFirstName(string);
        void setLastName(string);
        void setPatronNumber(int);
        void addPatronRide(Ride*);
        void setNumTickets(int);

        void displayName();
        void displayPatronData();
};
#endif