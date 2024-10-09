//
// Created by DaveD on 1/2/2024.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <string>

using namespace std;

class Ship
{
public:
    enum ShipTypes
    {
        Destroyer,
        Submarine,
        Cruiser
    };

    string Name;
    ShipTypes Type;
    char Symbol;

    virtual ~Ship() = default; // Adding a virtual destructor (or any virtual function)

    Ship(string name, ShipTypes type, char symbol) :
            Name(name),
            Type(type),
            Symbol(symbol) {}
};

#endif //BATTLESHIP_SHIP_H
