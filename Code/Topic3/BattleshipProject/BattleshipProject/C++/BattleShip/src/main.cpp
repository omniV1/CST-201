#include <iostream>

#include "BattleShipGame.h"

void DisplayBoard(char board[BattleshipGame::BoardSize][BattleshipGame::BoardSize]);
void SetPlayerShips(BattleshipGame &currGame);
pair<int, int> GetUserInput();
int GetInput(const string &rowOrColumnStr);
bool GoodInput(int num);
void GetPlacementDirections(Ship *ship);
bool GetYesOrNoAnswer(const string &prompt);
void PlayerTurn(BattleshipGame &game);
string GetShipDisplayName(Ship::ShipTypes type);

void DisplayBoard(char board[BattleshipGame::BoardSize][BattleshipGame::BoardSize])
{
    cout << "   1 2 3 4 5 6 7 8 9 10\n";
    for (int row = 0; row < BattleshipGame::BoardSize; row ++)
    {
        cout << row + 1 << "  ";
        for (int column = 0; column < BattleshipGame::BoardSize; column ++)
        {
            cout << board[row][column] << " ";
        }
        cout << endl;
    }
}

void SetPlayerShips(BattleshipGame &currGame)
{
    auto& playerShips = currGame.PlayerShips;
    for (int shipIdx = 0; shipIdx < 3; shipIdx ++)
    {
        auto ship = playerShips[shipIdx];
        cout << "Set your " << ship->Name <<
                        " (ship: " << GetShipDisplayName(ship->Type) << ")" << endl;

        while (true)
        {
            cout << "Enter the starting position: ";
            auto [row, column] = GetUserInput();
            GetPlacementDirections(ship);

            if (!currGame.PlaceShip(currGame.PlayerBoard, row, column, ship))
            {
                cout << "Invalid ship placement. Please choose another position." << endl;
                continue;
            }

            break;
        }

        cout << "Player's board:" << endl;
        DisplayBoard(currGame.PlayerBoard);
    }
}

pair<int, int> GetUserInput()
{
    int row = GetInput("row");
    int column = GetInput("column");
    return make_pair(row - 1, column - 1);
}

int GetInput(const string &rowOrColumnStr)
{
    while (true)
    {
        cout << "Please enter " << rowOrColumnStr << ": ";
        string input;
        getline(cin, input);
        int num = stoi(input);
        if (GoodInput(num))
        {
            return num;
        }

        cout << "Please enter a value of 1 to 10." << endl;
    }
}

bool GoodInput(int num)
{
    return num >= 1 && num <= BattleshipGame::BoardSize;
}

void GetPlacementDirections(Ship *ship)
{
    switch (ship->Type)
    {
        case Ship::ShipTypes::Submarine:
        {
            auto submarine = dynamic_cast<Submarine*>(ship);
            submarine->Left = GetYesOrNoAnswer("Do you want the Submarine direction to the left (y/n)? ");
            submarine->Upwards = GetYesOrNoAnswer("Do you want the Submarine direction upwards (y/n)? ");
            break;
        }

        case Ship::ShipTypes::Cruiser:
        {
            auto cruiser = dynamic_cast<Cruiser*>(ship);
            cruiser->Vertical = GetYesOrNoAnswer("Do you want the Cruiser direction vertical (y/n)? ");
            cruiser->Upwards = GetYesOrNoAnswer("Do you want the Cruiser direction upwards (y/n)? ");
            cruiser->Left = GetYesOrNoAnswer("Do you want the Cruiser direction to the left (y/n)? ");
            break;
        }

        case Ship::ShipTypes::Destroyer:
        {
            auto destroyer = dynamic_cast<Destroyer*>(ship);
            destroyer->Left = GetYesOrNoAnswer("Do you want the Destroyer direction to the left (y/n)? ");
            destroyer->Upwards = GetYesOrNoAnswer("Do you want the Destroyer direction upwards (y/n)? ");
            break;
        }

        default:
            break;
    }
}

bool GetYesOrNoAnswer(const string &prompt)
{
    while (true)
    {
        cout << prompt;
        string answer;
        getline(cin, answer);
        if (answer == "y" || answer == "Y")
        {
            return true;
        }
        else if (answer == "n" || answer == "N")
        {
            return false;
        }

        cout << "Please enter y or n." << endl;
    }
}

void PlayerTurn(BattleshipGame &game)
{
    cout << "Your turn!" << endl;
    while (true)
    {
        cout << "Enter your target position: ";
        auto [row, column] = GetUserInput();
        if (game.AlreadyFired(false, row, column))
        {
            cout << "You've already fired at this position. Choose another one." << endl;
            continue;
        }

        cout << (game.IsHit(false, row, column) ? "Hit!" : "Miss!") << endl;
        break;
    }
}

void ComputerTurn(BattleshipGame &game)
{
    cout << "Computer's turn!" << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delay for dramatic effect

    while (true)
    {
        int row = rand() % BattleshipGame::BoardSize;
        int column = rand() % BattleshipGame::BoardSize;

        if (game.AlreadyFired(true, row, column))
        {
            continue;
        }

        cout << (game.AlreadyFired(true, row, column) ?
                    "Computer hit at " : "Computer missed at ")
                  << row + 1 << "," << column + 1 << "!" << endl;
        break;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    BattleshipGame game;
    cout << "Welcome to Battleship! Let's set up your ships." << endl;
    SetPlayerShips(game);

    cout << "Player's board:" << endl;
    DisplayBoard(game.PlayerBoard);

//    cout << "Computer's board:" << endl;
//    DisplayBoard(game.ComputerBoard);

    cout << "Both boards are set up. Let's start the game!" << endl;

    while (true)
    {
        PlayerTurn(game);
        DisplayBoard(game.PlayerBoard);
        if (game.CheckGameOver(false))
        {
            cout << "Congratulations! You've sunk all the computer's ships. You win!"
                                            << endl;
            break;
        }

        ComputerTurn(game);
        DisplayBoard(game.PlayerBoard);
        if (!game.CheckGameOver(true))
        {
            continue;
        }

        cout << "Game over! The computer has sunk all your ships. You lose." << endl;
        break;
    }

    cout << "Press any key to exit...";
    cin.get();

    return 0;
}

string GetShipDisplayName(Ship::ShipTypes type)
{
    switch (type)
    {
        case Ship::ShipTypes::Cruiser:
            return "Cruiser";

        case Ship::ShipTypes::Destroyer:
            return "Destroyer";

        case Ship::ShipTypes::Submarine:
            return "Submarine";
    }
}
