add_library(BattleShip Ship.h Destroyer.h Cruiser.h Submarine.h BattleShipGame.cpp)

add_executable(BattleShipExe BattleShipGame.cpp Ship.h Destroyer.h
        Cruiser.h Submarine.h main.cpp)
