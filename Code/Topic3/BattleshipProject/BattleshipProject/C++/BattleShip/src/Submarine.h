//
// Created by DaveD on 1/2/2024.
//

#ifndef BATTLESHIP_SUBMARINE_H
#define BATTLESHIP_SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship
{
public:
    static const int SubmarineSize = 3;

    bool Upwards;
    bool Left;

    Submarine(string name, char symbol) :
            Ship(name, ShipTypes::Submarine, symbol),
            Upwards(false),
            Left(false) {}
};


#endif //BATTLESHIP_SUBMARINE_H
