import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class BattleshipGame
{
    public static final int BoardSize = 10;
    public static final char OpenCellChar = '.';
    public static final char ShipCellTaken = 'O';
    public static final char MissCell = 'M';
    public static final char HitCell = 'X';

    private char[][] _playerBoard;
    private char[][] _computerBoard;
    private List<Ship> playerShips;
    private List<Ship> computerShips;

    public BattleshipGame()
    {
        initGame();
        setComputerShips();
    }

    public char[][] getPlayerBoard()
    {
    	return _playerBoard;
    }

    public char[][] getComputerBoard()
    {
    	return _computerBoard;
    }
    
    public List<Ship> getPlayerShips()
    {
    	return playerShips;
    }

    public List<Ship> getComputerShips()
    {
    	return computerShips;
    }
    
    public BattleshipGame(boolean doComputerShips)
    {
        initGame();
        if (doComputerShips)
        {
            setComputerShips();
        }
    }

    public void setComputerShips()
    {
        Random random = new Random();
        for (int shipIdx = 0; shipIdx < 3; shipIdx ++)
        {
            Ship ship = computerShips.get(shipIdx);
            while (true)
            {
                int row = random.nextInt(BoardSize);
                int col = random.nextInt(BoardSize);
                if (placeShip(_computerBoard, row, col, ship))
                {
                    break;
                }
            }
        }
    }

    public boolean placeShip(char[][] board, int row, int col, Ship ship)
    {
        switch (ship.getType())
        {
            case Cruiser:
                return placeCruiser(board, row, col, (Cruiser) ship, true) &&
                        placeCruiser(board, row, col, (Cruiser) ship);
                
            case Destroyer:
                return placeDestroyer(board, row, col, (Destroyer) ship, true) &&
                        placeDestroyer(board, row, col, (Destroyer) ship);
                
            case Submarine:
                return placeSubmarine(board, row, col, (Submarine) ship, true) &&
                        placeSubmarine(board, row, col, (Submarine) ship);
                
            default:
                return false;
        }
    }

    public boolean checkGameOver(boolean checkPlayer)
    {
        if (checkPlayer)
        {
            return !stillHaveShips(_playerBoard);
        }
        else
        {
            return !stillHaveShips(_computerBoard);
        }
    }

    public boolean alreadyFired(boolean playerBoard, int row, int column)
    {
        if (!playerBoard)
        {
            return _computerBoard[row][column] == HitCell || _computerBoard[row][column] == MissCell;
        }
        else
        {
            return _playerBoard[row][column] == HitCell || _playerBoard[row][column] == MissCell;
        }
    }

    public boolean isHit(boolean playerBoard, int row, int column)
    {
        boolean retVal;

        if (playerBoard)
        {
            retVal = _computerBoard[row][column] == ShipCellTaken;
            if (_playerBoard[row][column] == ShipCellTaken)
            {
                _playerBoard[row][column] = HitCell;
            }
            else
            {
                _playerBoard[row][column] = MissCell;
            }
            return retVal;
        }
        else
        {
            retVal = _computerBoard[row][column] == ShipCellTaken;
            if (_computerBoard[row][column] == ShipCellTaken)
            {
                _computerBoard[row][column] = HitCell;
                _playerBoard[row][column] = HitCell;
            }
            else
            {
                _computerBoard[row][column] = MissCell;
                _playerBoard[row][column] = MissCell;
            }
            
            return retVal;
        }
    }

    public boolean placeCruiser(char[][] board, int row, int column, Cruiser ship)
    {
    	return placeCruiser(board, row, column, ship, false);
    }
    
    public boolean placeCruiser(char[][] board, int row, int column, Cruiser ship, boolean checkOnly)
    {
		//
		//  Add code here
		//
			
        return true;
    }

    public boolean placeDestroyer(char[][] board, int row, int column, Destroyer ship)
    {
		//
		//  Add code here
		//

    	return true;
    }

    public boolean placeSubmarine(char[][] board, int row, int column, Submarine ship)
    {
		//
		//  Add code here
		//

    	return true;
    }

    private void initGame()
    {
        _playerBoard = new char[BoardSize][BoardSize];
        _computerBoard = new char[BoardSize][BoardSize];

        playerShips = new ArrayList<>();
        playerShips.add(new Destroyer("USS Destroyer", 'D'));
        playerShips.add(new Submarine("USS Submarine", 'S'));
        playerShips.add(new Cruiser("USS Cruiser", 'C'));

        computerShips = new ArrayList<>();
        computerShips.add(new Destroyer("NCC Destroyer", 'D'));
        computerShips.add(new Submarine("NCC Submarine", 'S'));
        computerShips.add(new Cruiser("NCC Cruiser", 'C'));

        initializeBoards();
    }

    private void initializeBoards()
    {
        for (int row = 0; row < BoardSize; row ++)
        {
            for (int column = 0; column < BoardSize; column ++)
            {
                _playerBoard[row][column] = OpenCellChar;
                _computerBoard[row][column] = OpenCellChar;
            }
        }
    }

    private boolean stillHaveShips(char[][] board)
    {
        for (int row = 0; row < BoardSize; row ++)
        {
            for (int column = 0; column < BoardSize; column ++)
            {
                if (board[row][column] == ShipCellTaken)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
}
