//
// Created by DaveD on 1/2/2024.
//

#ifndef BATTLESHIP_BATTLESHIP_H
#define BATTLESHIP_BATTLESHIP_H

#include <vector>
#include <ctime>
#include <thread> // For sleep

using namespace std;

#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"

class BattleshipGame
{
public:
    static const int BoardSize = 10;
    static const char OpenCellChar = '.';
    static const char ShipCellTaken = 'O';
    static const char MissCell = 'M';
    static const char HitCell = 'X';

    char PlayerBoard[BoardSize][BoardSize];
    char ComputerBoard[BoardSize][BoardSize];
    vector<Ship*> PlayerShips;
    vector<Ship*> ComputerShips;

    BattleshipGame();
    BattleshipGame(bool doComputerShips);
    void SetComputerShips();
    bool PlaceShip(char board[BoardSize][BoardSize], int row, int col, Ship* ship);
    bool CheckGameOver(bool checkPlayer);
    bool AlreadyFired(bool playerBoard, int row, int column);
    bool IsHit(bool playerBoard, int row, int column);
    bool PlaceCruiser(char board[BoardSize][BoardSize], int row, int column,
                                        Cruiser *ship, bool checkOnly = false);
    bool PlaceDestroyer(char board[BoardSize][BoardSize], int row, int column,
                                        Destroyer *ship, bool checkOnly = false);
    bool PlaceSubmarine(char board[BoardSize][BoardSize], int row, int column,
                                        Submarine *ship, bool checkOnly = false);

private:
    void InitGame();
    void InitializeBoards();
    bool StillHaveShips(char board[BoardSize][BoardSize]);
    void CopyBoard(const char source[BoardSize][BoardSize],
                   char destination[BoardSize][BoardSize]);
};

#endif //BATTLESHIP_BATTLESHIP_H
