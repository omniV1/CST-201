
public class Destroyer extends Ship
{
    public static final int DestroyerSize = 2;

    private boolean upwards;
    private boolean left;

    public Destroyer(String name, char symbol)
    {
        super(name, Ship.ShipTypes.Destroyer, symbol);
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
