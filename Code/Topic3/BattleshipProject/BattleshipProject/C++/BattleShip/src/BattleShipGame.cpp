//
// Created by DaveD on 1/2/2024.
//

#include "BattleShipGame.h"

BattleshipGame::BattleshipGame()
{
    InitGame();
    SetComputerShips();
}

BattleshipGame::BattleshipGame(bool doComputerShips)
{
    InitGame();
    if (doComputerShips)
    {
        SetComputerShips();
    }
}

void BattleshipGame::SetComputerShips()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int shipIdx = 0; shipIdx < 3; shipIdx ++)
    {
        Ship* ship = ComputerShips[shipIdx];
        while (true)
        {
            int row = rand() % BoardSize;
            int col = rand() % BoardSize;

            if (PlaceShip(ComputerBoard, row, col, ship))
            {
                break;
            }
        }
    }
}

bool BattleshipGame::PlaceShip(char board[BoardSize][BoardSize], int row, int col, Ship* ship)
{
    switch (ship->Type)
    {
        case Ship::ShipTypes::Cruiser:
            return PlaceCruiser(board, row, col, static_cast<Cruiser *>(ship));

        case Ship::ShipTypes::Destroyer:
            return PlaceDestroyer(board, row, col, static_cast<Destroyer*>(ship));

        case Ship::ShipTypes::Submarine:
            return PlaceSubmarine(board, row, col, static_cast<Submarine*>(ship));
    }

    return false;
}

bool BattleshipGame::CheckGameOver(bool checkPlayer)
{
    char board[BoardSize][BoardSize];
    if (checkPlayer) {
        CopyBoard(PlayerBoard, board);
    }
    else {
        CopyBoard(ComputerBoard, board);
    }

    return !StillHaveShips(board);
}

bool BattleshipGame::AlreadyFired(bool playerBoard, int row, int column)
{
    if (playerBoard)
    {
        return PlayerBoard[row][column] == HitCell || PlayerBoard[row][column] == MissCell;
    }

    return ComputerBoard[row][column] == HitCell || ComputerBoard[row][column] == MissCell;
}

bool BattleshipGame::IsHit(bool playerBoard, int row, int column)
{
    char& playerCell = PlayerBoard[row][column];
    char& computerCell = ComputerBoard[row][column];

    bool isHit = false;

    if (playerBoard)
    {
        isHit = computerCell == ShipCellTaken;
        playerCell = isHit ? HitCell : MissCell;
    }
    else
    {
        isHit = computerCell == ShipCellTaken;
        computerCell = playerCell = isHit ? HitCell : MissCell;
    }

    return isHit;
}

bool BattleshipGame::PlaceCruiser(char board[BoardSize][BoardSize], int row, int column,
                                  Cruiser *ship, bool checkOnly)
{
	//
	//  Add code here
	//
			
    return true;
}

bool BattleshipGame::PlaceDestroyer(char board[BoardSize][BoardSize], int row, int column,
                                    Destroyer *ship, bool checkOnly)
{
	//
	//  Add code here
	//
			

    return true;
}

bool BattleshipGame::PlaceSubmarine(char board[BoardSize][BoardSize], int row,
                                    int column, Submarine *ship, bool checkOnly)
{
	//
	//  Add code here
	//
			
    return false;
}

void BattleshipGame::InitGame()
{
    PlayerShips.push_back(new Destroyer("USS Destroyer", 'D'));
    PlayerShips.push_back(new Submarine("USS Submarine", 'S'));
    PlayerShips.push_back(new Cruiser("USS Cruiser", 'C'));

    ComputerShips.push_back(new Destroyer("NCC Destroyer", 'D'));
    ComputerShips.push_back(new Submarine("NCC Submarine", 'S'));
    ComputerShips.push_back(new Cruiser("NCC Cruiser", 'C'));

    InitializeBoards();
}

void BattleshipGame::InitializeBoards()
{
    for (int row = 0; row < BoardSize; row ++)
    {
        for (int col = 0; col < BoardSize; col ++)
        {
            PlayerBoard[row][col] = OpenCellChar;
            ComputerBoard[row][col] = OpenCellChar;
        }
    }
}

bool BattleshipGame::StillHaveShips(char board[BoardSize][BoardSize])
{
    for (int row = 0; row < BoardSize; row ++)
    {
        for (int col = 0; col < BoardSize; col ++)
        {
            if (board[row][col] == ShipCellTaken)
            {
                return true;
            }
        }
    }

    return false;
}

void BattleshipGame::CopyBoard(const char source[BoardSize][BoardSize],
               char destination[BoardSize][BoardSize])
{
    for (int row = 0; row < BoardSize; row ++)
    {
        for (int col = 0; col < BoardSize; col ++)
        {
            destination[row][col] = source[row][col];
        }
    }
}
