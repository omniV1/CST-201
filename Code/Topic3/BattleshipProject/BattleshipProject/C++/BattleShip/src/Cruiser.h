//
// Created by DaveD on 1/2/2024.
//

#ifndef BATTLESHIP_CRUISER_H
#define BATTLESHIP_CRUISER_H

#include "Ship.h"

class Cruiser : public Ship
{
public:
    static const int CruiserSize = 3;

    bool Vertical;
    bool Upwards;
    bool Left;

    Cruiser(string name, char symbol) :
            Ship(name, ShipTypes::Cruiser, symbol),
            Vertical(false),
            Upwards(false),
            Left(false) {}
};


#endif //BATTLESHIP_CRUISER_H
