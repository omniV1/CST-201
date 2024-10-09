import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class MainDriver
{
    private static final int BoardSize = 10;

    public static void main(String[] args)
    {
        BattleshipGame game = new BattleshipGame();

        System.out.println("Welcome to Battleship! Let's set up your ships.");
        setPlayerShips(game);

        clearConsole();
        System.out.println("Player's board:");
        displayBoard(game.getPlayerBoard());

        System.out.println("Computer's board:");
        displayBoard(game.getComputerBoard());

        clearConsole();
        System.out.println("Both boards are set up. Let's start the game!");

        while (true)
        {
            playerTurn(game);
            displayBoard(game.getPlayerBoard());
            if (game.checkGameOver(false))
            {
                System.out.println("Congratulations! You've sunk all the computer's ships. You win!");
                break;
            }

            computerTurn(game);
            displayBoard(game.getPlayerBoard());
            if (!game.checkGameOver(true))
            {
                continue;
            }

            System.out.println("Game over! The computer has sunk all your ships. You lose.");
            break;
        }

        System.out.println("Press any key to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
    }

    private static void displayBoard(char[][] board)
    {
        System.out.println("   1 2 3 4 5 6 7 8 9 10");
        for (int row = 0; row < BoardSize; row ++)
        {
            System.out.printf("%2d ", row + 1);
            for (int column = 0; column < BoardSize; column ++)
            {
                System.out.print(board[row][column] + " ");
            }
            
            System.out.println();
        }
    }

    private static void setPlayerShips(BattleshipGame game)
    {
        List<Ship> playerShips = game.getPlayerShips();
        for (int shipIdx = 0; shipIdx < 3; shipIdx ++)
        {
            Ship ship = playerShips.get(shipIdx);
            System.out.printf("Set your %s (ship: %s)%n", ship.getName(), ship.getType());

            while (true)
            {
                System.out.print("Enter the starting position: ");
                int[] position = getUserInput();

                getPlacementDirections(ship);

                if (!game.placeShip(game.getPlayerBoard(), position[0], position[1], ship))
                {
                    System.out.println("Invalid ship placement. Please choose another position.");
                    continue;
                }

                clearConsole();
                System.out.println("Player's board:");
                displayBoard(game.getPlayerBoard());
                break;
            }
        }
    }

    private static int[] getUserInput()
    {
        int row = getInput("row");
        int column = getInput("column");
        return new int[]{row - 1, column - 1};
    }

    private static int getInput(String rowOrColumnStr)
    {
        Scanner scanner = new Scanner(System.in);
        int num;
        while (true)
        {
            System.out.printf("Please enter %s: ", rowOrColumnStr);
            String input = scanner.nextLine().trim();
            try
            {
                num = Integer.parseInt(input);
                if (goodInput(num))
                {
                    return num;
                }
                
                System.out.println("Please enter a value of 1 to 10.");
            }
            
            catch (NumberFormatException e)
            {
                System.out.println("Invalid input. Please enter a number.");
            }
        }
    }

    private static boolean goodInput(int num)
    {
        return num >= 1 && num <= BoardSize;
    }

    private static void getPlacementDirections(Ship ship)
    {
        switch (ship.getType())
        {
            case Submarine:
                Submarine submarine = (Submarine) ship;
                submarine.setLeft(getYesOrNoAnswer("Do you want the Submarine direction to the left (y/n)? "));
                submarine.setUpwards(getYesOrNoAnswer("Do you want the Submarine direction upwards (y/n)? "));
                break;
                
            case Cruiser:
                Cruiser cruiser = (Cruiser) ship;
                cruiser.setVertical(getYesOrNoAnswer("Do you want the Cruiser direction vertical (y/n)? "));
                cruiser.setUpwards(getYesOrNoAnswer("Do you want the Cruiser direction upwards (y/n)? "));
                cruiser.setLeft(getYesOrNoAnswer("Do you want the Destroyer direction to the left (y/n)? "));
                break;
                
            case Destroyer:
                Destroyer destroyer = (Destroyer) ship;
                destroyer.setLeft(getYesOrNoAnswer("Do you want the Destroyer direction to the left (y/n)? "));
                destroyer.setUpwards(getYesOrNoAnswer("Do you want the Destroyer direction upwards (y/n)? "));
                break;
        }
    }

    private static boolean getYesOrNoAnswer(String prompt)
    {
        Scanner scanner = new Scanner(System.in);
        while (true)
        {
            System.out.print(prompt);
            String answer = scanner.nextLine().trim().toLowerCase();
            switch (answer)
            {
                case "y":
                    return true;
                    
                case "n":
                    return false;
                    
                default:
                    System.out.println("Please enter y or n.");
                    break;
            }
        }
    }

    private static void playerTurn(BattleshipGame game)
    {
        System.out.println("Your turn!");
        while (true)
        {
            System.out.print("Enter your target position: ");
            int[] target = getUserInput();
            if (game.alreadyFired(false, target[0], target[1]))
            {
                System.out.println("You've already fired at this position. Choose another one.");
                continue;
            }

            System.out.println(game.isHit(false, target[0], target[1]) ? "Hit!" : "Miss!");
            break;
        }
    }

    private static void computerTurn(BattleshipGame game)
    {
        Random random = new Random();
        System.out.println("Computer's turn!");

        while (true)
        {
            int row = random.nextInt(BoardSize);
            int column = random.nextInt(BoardSize);

            if (game.alreadyFired(true, row, column))
            {
                continue;
            }

            System.out.println(game.alreadyFired(true, row, column)
                    ? String.format("Computer hit at %d,%d!", row + 1, column + 1)
                    : String.format("Computer missed at %d,%d.", row + 1, column + 1));
            break;
        }
    }

    private static void clearConsole()
    {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}

