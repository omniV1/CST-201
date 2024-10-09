//
// Created by DaveD on 1/2/2024.
//

#ifndef BATTLESHIP_DESTROYER_H
#define BATTLESHIP_DESTROYER_H

#include "Ship.h"

class Destroyer : public Ship
{
public:
    static const int DestroyerSize = 2;

    bool Upwards;
    bool Left;

    Destroyer(string name, char symbol) :
            Ship(name, ShipTypes::Destroyer, symbol),
            Upwards(false),
            Left(false) {}
};


#endif //BATTLESHIP_DESTROYER_H
