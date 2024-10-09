
namespace BattleShip.Library
{
    public class BattleshipGame
    {
        public const int BoardSize = 10;
        public const char OpenCellChar = '.';
        public const char ShipCellTaken = 'O';
        public const char MissCell = 'M';
        public const char HitCell = 'X';

        public char[,]? PlayerBoard { get; set; }
        public char[,]? ComputerBoard { get; set; }
        public List<Ship>? PlayerShips { get; set; }
        public List<Ship>? ComputerShips { get; set; }

        public BattleshipGame()
        {
            InitGame();
            SetComputerShips();
        }

        public BattleshipGame(bool doComputerShips)
        {
            InitGame();
            if (doComputerShips)
            {
                SetComputerShips();
            }
        }

        public void SetComputerShips()
        {
            var random = new Random();
            for (var shipIdx = 0; shipIdx < 3; shipIdx ++)
            {
                var ship = ComputerShips[shipIdx];
                while (true)
                {
                    var row = random.Next(BoardSize);
                    var col = random.Next(BoardSize);

                    if (PlaceShip(ComputerBoard, row, col, ship))
                    {
                        break;
                    }
                }
            }
        }

        public bool PlaceShip(char[,] board, int row, int col, Ship ship)
        {
            return ship.Type switch
            {
                Ship.ShipTypes.Cruiser => PlaceCruiser(board, row, col, (Cruiser)ship, true) &&
                                          PlaceCruiser(board, row, col, (Cruiser)ship),
                Ship.ShipTypes.Destroyer => PlaceDestroyer(board, row, col, (Destroyer)ship, true) &&
                                            PlaceDestroyer(board, row, col, (Destroyer)ship),
                Ship.ShipTypes.Submarine => PlaceSubmarine(board, row, col, (Submarine)ship, true) &&
                                            PlaceSubmarine(board, row, col, (Submarine)ship),
                _ => false
            };
        }

        public bool CheckGameOver(bool checkPlayer)
        {
            if (checkPlayer)
            {
                return !StillHaveShips(PlayerBoard);
            }

            return !StillHaveShips(ComputerBoard);
        }

        public bool AlreadyFired(bool playerBoard, int row, int column)
        {
            if (!playerBoard)
            {
                return ComputerBoard[row, column] is HitCell or MissCell;
            }

            return PlayerBoard[row, column] is HitCell or MissCell;
        }

        public bool IsHit(bool playerBoard, int row, int column)
        {
            var retVal = false;

            if (playerBoard)
            {
                retVal = ComputerBoard[row, column] is ShipCellTaken;
                if (PlayerBoard[row, column] is ShipCellTaken)
                {
                    PlayerBoard[row, column] = HitCell;
                }
                else
                {
                    PlayerBoard[row, column] = MissCell;
                }

                return retVal;
            }

            retVal = ComputerBoard[row, column] is ShipCellTaken;
            if (ComputerBoard[row, column] is ShipCellTaken)
            {
                ComputerBoard[row, column] = HitCell;
                PlayerBoard[row, column] = HitCell;
            }
            else
            {
                ComputerBoard[row, column] = MissCell;
                PlayerBoard[row, column] = MissCell;
            }

            return retVal;
        }

        public bool PlaceCruiser(char[,] board, int row, int column, Cruiser ship, bool checkOnly = false)
        {
			//
			//  Add code here
			//
			
            return true;
        }

        public bool PlaceDestroyer(char[,] board, int row, int column, Destroyer ship, bool checkOnly = false)
        {
			//
			//  Add code here
			//
			
            return true;
        }

        public bool PlaceSubmarine(char[,] board, int row, int column, Submarine ship, bool checkOnly = false)
        {
			//
			//  Add code here
			//
			
			return true;
		}

            return false;
        }

        private void InitGame()
        {
            PlayerBoard = new char[BoardSize, BoardSize];
            ComputerBoard = new char[BoardSize, BoardSize];

            PlayerShips = new List<Ship>
            {
                new Destroyer("USS Destroyer", 'D'),
                new Submarine("USS Submarine", 'S'),
                new Cruiser("USS Cruiser", 'C')
            };

            ComputerShips = new List<Ship>
            {
                new Destroyer("NCC Destroyer", 'D'),
                new Submarine("NCC Submarine", 'S'),
                new Cruiser("NCC Cruiser", 'C')
            };

            InitializeBoards();
        }

        private void InitializeBoards()
        {
            for (var row = 0; row < BoardSize; row ++)
            {
                for (var column = 0; column < BoardSize; column ++)
                {
                    PlayerBoard[row, column] = OpenCellChar;
                    ComputerBoard[row, column] = OpenCellChar;
                }
            }
        }

        private bool StillHaveShips(char[,] board)
        {
            for (var row = 0; row < BoardSize; row++)
            {
                for (var column = 0; column < BoardSize; column++)
                {
                    if (board[row, column] == ShipCellTaken)
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }
}
