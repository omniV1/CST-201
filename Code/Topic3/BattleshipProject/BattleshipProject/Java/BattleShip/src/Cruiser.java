
public class Cruiser extends Ship
{
    public static final int CruiserSize = 3;

    private boolean vertical;
    private boolean upwards;
    private boolean left;

    public Cruiser(String name, char symbol)
    {
        super(name, Ship.ShipTypes.Cruiser, symbol);
        vertical = false;
        left = false;
        upwards = false;
    }

    public boolean isVertical()
    {
        return vertical;
    }

    public void setVertical(boolean vertical)
    {
        this.vertical = vertical;
    }

    public boolean isUpwards()
    {
        return upwards;
    }

    public void setUpwards(boolean upwards)
    {
        this.upwards = upwards;
    }

    public boolean isLeft()
    {
        return left;
    }

    public void setLeft(boolean left)
    {
        this.left = left;
    }
}
