
public class Ship
{
    public enum ShipTypes
    {
        Destroyer,
        Submarine,
        Cruiser
    }

    private String name;
    private ShipTypes type;
    private char symbol;

    public Ship(String name, ShipTypes type, char symbol)
    {
        this.name = name;
        this.type = type;
        this.symbol = symbol;
    }

    public String getName()
    {
        return name;
    }

    public ShipTypes getType()
    {
        return type;
    }

    public char getSymbol()
    {
        return symbol;
    }
}
