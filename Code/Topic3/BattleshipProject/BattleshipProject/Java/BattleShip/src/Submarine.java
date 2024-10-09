
public class Submarine extends Ship
{
    public static final int SubmarineSize = 3;

    private boolean upwards;
    private boolean left;

    public Submarine(String name, char symbol)
    {
        super(name, Ship.ShipTypes.Submarine, symbol);
        upwards = false;
        left = false;
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
