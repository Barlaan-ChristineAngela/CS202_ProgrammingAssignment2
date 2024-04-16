#ifndef RIDE_H
#define RIDE_H
#include <iostream>
using namespace std;
class Ride{
    string name; 
    bool heightRestricted; 

    public:

      Ride();
      Ride(int, string, bool);
      Ride(const Ride&);

      string getRideName();
      bool getHeightRestricted();

      void setRideName(string);
      void setHeightRestricted(bool);

      virtual int numTicketsNecessary() = 0;
       
};

#endif