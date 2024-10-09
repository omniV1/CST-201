//
// Created by DaveD on 1/2/2024.
//

#include <gtest/gtest.h>
#include "../src/BattleShipGame.h"

TEST(TestBattleship, BattleshipInit)
{
    BattleshipGame game1(false);
    auto ships = game1.PlayerShips;
    ASSERT_EQ(ships[0]->Name, "USS Destroyer");
    ASSERT_EQ(ships[0]->Type, Ship::ShipTypes::Destroyer);
    ASSERT_EQ(ships[0]->Symbol, 'D');
    ASSERT_EQ(ships[1]->Name, "USS Submarine");
    ASSERT_EQ(ships[1]->Type, Ship::ShipTypes::Submarine);
    ASSERT_EQ(ships[1]->Symbol, 'S');
    ASSERT_EQ(ships[2]->Name, "USS Cruiser");
    ASSERT_EQ(ships[2]->Type, Ship::ShipTypes::Cruiser);
    ASSERT_EQ(ships[2]->Symbol, 'C');

    BattleshipGame game2(false);
    ships = game2.ComputerShips;
    ASSERT_EQ(ships[0]->Name, "NCC Destroyer");
    ASSERT_EQ(ships[0]->Type, Ship::ShipTypes::Destroyer);
    ASSERT_EQ(ships[0]->Symbol, 'D');
    ASSERT_EQ(ships[1]->Name, "NCC Submarine");
    ASSERT_EQ(ships[1]->Type, Ship::ShipTypes::Submarine);
    ASSERT_EQ(ships[1]->Symbol, 'S');
    ASSERT_EQ(ships[2]->Name, "NCC Cruiser");
    ASSERT_EQ(ships[2]->Type, Ship::ShipTypes::Cruiser);
    ASSERT_EQ(ships[2]->Symbol, 'C');

    auto playerBoard = game1.PlayerBoard;
    auto computerBoard = game1.ComputerBoard;
    for (auto row = 0; row < BattleshipGame::BoardSize; row ++)
    {
        for (auto column = 0; column < BattleshipGame::BoardSize; column ++)
        {
            ASSERT_EQ(playerBoard[row][column], '.');
            ASSERT_EQ(computerBoard[row][column], '.');
        }
    }
}

TEST(TestBattleship, TestCruiserPlacement)
{
    BattleshipGame game(false);
    auto ships = game.PlayerShips;
    auto cruiser = static_cast<Cruiser *>(ships[2]);
    auto placed = game.PlaceCruiser(game.PlayerBoard, 3, 3, cruiser);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[3][3], 'O');
    ASSERT_EQ(game.PlayerBoard[3][4], 'O');
    ASSERT_EQ(game.PlayerBoard[3][5], 'O');

    cruiser->Left = true;
    placed = game.PlaceCruiser(game.PlayerBoard, 4, 3, cruiser);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[4][3], 'O');
    ASSERT_EQ(game.PlayerBoard[4][2], 'O');
    ASSERT_EQ(game.PlayerBoard[4][1], 'O');

    cruiser->Left = false;
    cruiser->Vertical = true;
    placed = game.PlaceCruiser(game.PlayerBoard, 7, 3, cruiser);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[7][3], 'O');
    ASSERT_EQ(game.PlayerBoard[8][3], 'O');
    ASSERT_EQ(game.PlayerBoard[9][3], 'O');

    cruiser->Upwards = true;
    placed = game.PlaceCruiser(game.PlayerBoard, 7, 4, cruiser);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[7][4], 'O');
    ASSERT_EQ(game.PlayerBoard[6][4], 'O');
    ASSERT_EQ(game.PlayerBoard[5][4], 'O');

    //
    //  Bad Placements
    //

    cruiser->Upwards = false;
    cruiser->Vertical = false;
    cruiser->Left = false;
    placed = game.PlaceCruiser(game.PlayerBoard, 9, 9, cruiser);
    ASSERT_FALSE(placed);

    cruiser->Left = true;
    placed = game.PlaceCruiser(game.PlayerBoard, 1, 1, cruiser);
    ASSERT_FALSE(placed);

    cruiser->Left = false;
    cruiser->Vertical = true;
    placed = game.PlaceCruiser(game.PlayerBoard, 9, 3, cruiser);
    ASSERT_FALSE(placed);

    cruiser->Upwards = false;
    placed = game.PlaceCruiser(game.PlayerBoard, 9, 1, cruiser);
    ASSERT_FALSE(placed);
}

TEST(TestBattleship, TestDestroyerPlacement)
{
    BattleshipGame game(false);
    auto ships = game.PlayerShips;
    auto destroyer = static_cast<Destroyer *>(ships[0]);
    auto placed = game.PlaceDestroyer(game.PlayerBoard, 3, 3, destroyer);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[3][3], 'O');
    ASSERT_EQ(game.PlayerBoard[3][4], 'O');
    ASSERT_EQ(game.PlayerBoard[4][3], 'O');
    ASSERT_EQ(game.PlayerBoard[4][4], 'O');

    destroyer->Left = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 4, 2, destroyer);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[4][2], 'O');
    ASSERT_EQ(game.PlayerBoard[4][1], 'O');
    ASSERT_EQ(game.PlayerBoard[5][2], 'O');
    ASSERT_EQ(game.PlayerBoard[5][1], 'O');

    destroyer->Left = false;
    destroyer->Upwards = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 7, 3, destroyer);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[6][3], 'O');
    ASSERT_EQ(game.PlayerBoard[6][4], 'O');
    ASSERT_EQ(game.PlayerBoard[7][3], 'O');
    ASSERT_EQ(game.PlayerBoard[7][4], 'O');

    destroyer->Left = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 5, 6, destroyer);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[4][5], 'O');
    ASSERT_EQ(game.PlayerBoard[4][6], 'O');
    ASSERT_EQ(game.PlayerBoard[5][5], 'O');
    ASSERT_EQ(game.PlayerBoard[5][6], 'O');

    //
    //  Bad Placements
    //

    destroyer->Upwards = false;
    destroyer->Left = false;
    placed = game.PlaceDestroyer(game.PlayerBoard, 10, 10, destroyer);
    ASSERT_FALSE(placed);

    destroyer->Left = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 10, 1, destroyer);
    ASSERT_FALSE(placed);

    destroyer->Left = false;
    destroyer->Upwards = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 1, 10, destroyer);
    ASSERT_FALSE(placed);

    destroyer->Left = true;
    placed = game.PlaceDestroyer(game.PlayerBoard, 0, 0, destroyer);
    ASSERT_FALSE(placed);
}

TEST(TestBattleship, TestSubmarinePlacement)
{
    BattleshipGame game(false);
    auto ships = game.PlayerShips;
    auto submarine = static_cast<Submarine *>(ships[1]);
    auto placed = game.PlaceSubmarine(game.PlayerBoard, 4, 4, submarine);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[4][4], 'O');
    ASSERT_EQ(game.PlayerBoard[5][5], 'O');
    ASSERT_EQ(game.PlayerBoard[6][6], 'O');

    ASSERT_EQ(game.PlayerBoard[4][5], '.');
    ASSERT_EQ(game.PlayerBoard[4][6], '.');
    ASSERT_EQ(game.PlayerBoard[5][4], '.');
    ASSERT_EQ(game.PlayerBoard[5][6], '.');
    ASSERT_EQ(game.PlayerBoard[6][4], '.');
    ASSERT_EQ(game.PlayerBoard[6][5], '.');

    submarine->Left = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 4, 3, submarine);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[4][3], 'O');
    ASSERT_EQ(game.PlayerBoard[5][2], 'O');
    ASSERT_EQ(game.PlayerBoard[6][1], 'O');

    submarine->Left = false;
    submarine->Upwards = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 3, 4, submarine);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[3][4], 'O');
    ASSERT_EQ(game.PlayerBoard[2][5], 'O');
    ASSERT_EQ(game.PlayerBoard[1][6], 'O');

    submarine->Left = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 3, 3, submarine);
    ASSERT_TRUE(placed);
    ASSERT_EQ(game.PlayerBoard[3][3], 'O');
    ASSERT_EQ(game.PlayerBoard[2][2], 'O');
    ASSERT_EQ(game.PlayerBoard[1][1], 'O');

    //
    //  Bad Placements
    //

    submarine->Upwards = false;
    submarine->Left = false;
    placed = game.PlaceSubmarine(game.PlayerBoard, 10, 10, submarine);
    ASSERT_FALSE(placed);

    submarine->Left = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 10, 1, submarine);
    ASSERT_FALSE(placed);

    submarine->Left = false;
    submarine->Upwards = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 1, 10, submarine);
    ASSERT_FALSE(placed);

    submarine->Left = true;
    placed = game.PlaceSubmarine(game.PlayerBoard, 0, 0, submarine);
    ASSERT_FALSE(placed);
}

TEST(TestBattleship, TestEndGame)
{
    BattleshipGame game1(false);
    auto playerEndGame = game1.CheckGameOver(true);
    auto computerEndGame = game1.CheckGameOver(false);
    ASSERT_TRUE(playerEndGame);
    ASSERT_TRUE(computerEndGame);

    BattleshipGame game2(true);
    game2.PlaceCruiser(game2.PlayerBoard, 5, 5,
                       new Cruiser("Cruiser 1", 'C'));
    playerEndGame = game2.CheckGameOver(true);
    computerEndGame = game2.CheckGameOver(false);
    ASSERT_FALSE(playerEndGame);
    ASSERT_FALSE(computerEndGame);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
