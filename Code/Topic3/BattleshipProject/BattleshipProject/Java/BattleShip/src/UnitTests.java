import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class UnitTests
{
    @Test
    public void testInit()
    {
        BattleshipGame game = new BattleshipGame(false);
        var ships = game.getPlayerShips();

        assertEquals("USS Destroyer", ships.get(0).getName());
        assertEquals(Ship.ShipTypes.Destroyer, ships.get(0).getType());
        assertEquals('D', ships.get(0).getSymbol());

        assertEquals("USS Submarine", ships.get(1).getName());
        assertEquals(Ship.ShipTypes.Submarine, ships.get(1).getType());
        assertEquals('S', ships.get(1).getSymbol());

        assertEquals("USS Cruiser", ships.get(2).getName());
        assertEquals(Ship.ShipTypes.Cruiser, ships.get(2).getType());
        assertEquals('C', ships.get(2).getSymbol());

        ships = game.getComputerShips();

        assertEquals("NCC Destroyer", ships.get(0).getName());
        assertEquals(Ship.ShipTypes.Destroyer, ships.get(0).getType());
        assertEquals('D', ships.get(0).getSymbol());

        assertEquals("NCC Submarine", ships.get(1).getName());
        assertEquals(Ship.ShipTypes.Submarine, ships.get(1).getType());
        assertEquals('S', ships.get(1).getSymbol());

        assertEquals("NCC Cruiser", ships.get(2).getName());
        assertEquals(Ship.ShipTypes.Cruiser, ships.get(2).getType());
        assertEquals('C', ships.get(2).getSymbol());

        char[][] playerBoard = game.getPlayerBoard();
        char[][] computerBoard = game.getComputerBoard();

        for (int row = 0; row < BattleshipGame.BoardSize; row ++)
        {
            for (int column = 0; column < BattleshipGame.BoardSize; column ++)
            {
                assertEquals(BattleshipGame.OpenCellChar, playerBoard[row][column]);
                assertEquals(BattleshipGame.OpenCellChar, computerBoard[row][column]);
            }
        }
    }

    @Test
    public void testCruiserPlacement()
    {
        BattleshipGame game = new BattleshipGame(false);
        var ships = game.getPlayerShips();
        Cruiser cruiser = (Cruiser) ships.get(2);

        boolean placed = game.placeCruiser(game.getPlayerBoard(), 3, 3, cruiser);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[3][3]);
        assertEquals('O', game.getPlayerBoard()[3][4]);
        assertEquals('O', game.getPlayerBoard()[3][5]);

        cruiser.setLeft(true);
        placed = game.placeCruiser(game.getPlayerBoard(), 4, 3, cruiser);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[4][3]);
        assertEquals('O', game.getPlayerBoard()[4][2]);
        assertEquals('O', game.getPlayerBoard()[4][1]);

        cruiser.setLeft(false);
        cruiser.setVertical(true);
        placed = game.placeCruiser(game.getPlayerBoard(), 7, 3, cruiser);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[7][3]);
        assertEquals('O', game.getPlayerBoard()[8][3]);
        assertEquals('O', game.getPlayerBoard()[9][3]);

        cruiser.setUpwards(true);
        placed = game.placeCruiser(game.getPlayerBoard(), 7, 4, cruiser);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[7][4]);
        assertEquals('O', game.getPlayerBoard()[6][4]);
        assertEquals('O', game.getPlayerBoard()[5][4]);

        // Bad Placements
        cruiser.setUpwards(false);
        cruiser.setVertical(false);
        cruiser.setLeft(false);
        placed = game.placeCruiser(game.getPlayerBoard(), 9, 9, cruiser);
        assertFalse(placed);

        cruiser.setLeft(true);
        placed = game.placeCruiser(game.getPlayerBoard(), 1, 1, cruiser);
        assertFalse(placed);

        cruiser.setLeft(false);
        cruiser.setVertical(true);
        placed = game.placeCruiser(game.getPlayerBoard(), 9, 3, cruiser);
        assertFalse(placed);

        cruiser.setUpwards(false);
        placed = game.placeCruiser(game.getPlayerBoard(), 9, 1, cruiser);
        assertFalse(placed);
    }

    @Test
    public void testDestroyerPlacement()
    {
        BattleshipGame game = new BattleshipGame(false);
        var ships = game.getPlayerShips();
        Destroyer destroyer = (Destroyer) ships.get(0);

        boolean placed = game.placeDestroyer(game.getPlayerBoard(), 3, 3, destroyer);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[3][3]);
        assertEquals('O', game.getPlayerBoard()[3][4]);
        assertEquals('O', game.getPlayerBoard()[4][3]);
        assertEquals('O', game.getPlayerBoard()[4][4]);

        destroyer.setLeft(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 4, 3, destroyer);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[4][2]);
        assertEquals('O', game.getPlayerBoard()[4][3]);
        assertEquals('O', game.getPlayerBoard()[5][2]);
        assertEquals('O', game.getPlayerBoard()[5][3]);

        destroyer.setLeft(false);
        destroyer.setUpwards(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 7, 3, destroyer);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[6][3]);
        assertEquals('O', game.getPlayerBoard()[6][4]);
        assertEquals('O', game.getPlayerBoard()[7][3]);
        assertEquals('O', game.getPlayerBoard()[7][4]);

        destroyer.setLeft(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 7, 4, destroyer);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[6][3]);
        assertEquals('O', game.getPlayerBoard()[6][4]);
        assertEquals('O', game.getPlayerBoard()[7][3]);
        assertEquals('O', game.getPlayerBoard()[7][4]);

        // Bad Placements
        destroyer.setUpwards(false);
        destroyer.setLeft(false);
        placed = game.placeDestroyer(game.getPlayerBoard(), 10, 10, destroyer);
        assertFalse(placed);

        destroyer.setLeft(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 10, 1, destroyer);
        assertFalse(placed);

        destroyer.setLeft(false);
        destroyer.setUpwards(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 1, 10, destroyer);
        assertFalse(placed);

        destroyer.setLeft(true);
        placed = game.placeDestroyer(game.getPlayerBoard(), 0, 0, destroyer);
        assertFalse(placed);
    }

    @Test
    public void testSubmarinePlacement()
    {
        BattleshipGame game = new BattleshipGame(false);
        var ships = game.getPlayerShips();
        Submarine submarine = (Submarine) ships.get(1);

        boolean placed = game.placeSubmarine(game.getPlayerBoard(), 4, 4, submarine);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[4][4]);
        assertEquals('O', game.getPlayerBoard()[5][5]);
        assertEquals('O', game.getPlayerBoard()[6][6]);

        submarine.setLeft(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 4, 3, submarine);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[4][3]);
        assertEquals('O', game.getPlayerBoard()[5][2]);
        assertEquals('O', game.getPlayerBoard()[6][1]);

        submarine.setLeft(false);
        submarine.setUpwards(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 3, 4, submarine);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[3][4]);
        assertEquals('O', game.getPlayerBoard()[2][5]);
        assertEquals('O', game.getPlayerBoard()[1][6]);

        submarine.setLeft(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 3, 3, submarine);
        assertTrue(placed);
        assertEquals('O', game.getPlayerBoard()[3][3]);
        assertEquals('O', game.getPlayerBoard()[2][2]);
        assertEquals('O', game.getPlayerBoard()[1][1]);

        // Bad Placements
        submarine.setUpwards(false);
        submarine.setLeft(false);
        placed = game.placeSubmarine(game.getPlayerBoard(), 10, 10, submarine);
        assertFalse(placed);

        submarine.setLeft(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 10, 1, submarine);
        assertFalse(placed);

        submarine.setLeft(false);
        submarine.setUpwards(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 1, 10, submarine);
        assertFalse(placed);

        submarine.setLeft(true);
        placed = game.placeSubmarine(game.getPlayerBoard(), 0, 0, submarine);
        assertFalse(placed);
    }

    @Test
    public void testEndGame()
    {
        BattleshipGame game = new BattleshipGame(false);
        boolean playerEndGame = game.checkGameOver(true);
        boolean computerEndGame = game.checkGameOver(false);

        assertTrue(playerEndGame);
        assertTrue(computerEndGame);

        game = null;
        game = new BattleshipGame(true);
        game.placeCruiser(game.getPlayerBoard(), 5, 5, new Cruiser("Cruiser 1", 'C'));
        playerEndGame = game.checkGameOver(true);
        computerEndGame = game.checkGameOver(false);

        assertFalse(playerEndGame);
        assertFalse(computerEndGame);
    }
}
