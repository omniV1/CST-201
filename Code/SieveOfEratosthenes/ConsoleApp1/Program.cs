namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // maximum data set to iterate through is 100
            int maximum = 100;


            bool[] prime = new maximum(maximum + 1);

            // iterate through all values from maxium and set them to true 
            for (int i = 0; i < maximum; i++)
            {
                // 
                prime[i] = true;

            }

            // assume 0 and 1 are known false becasue they do not result in prime 
            prime[1] = false;
            prime[0] = false;

            //iterate from 2 to the square root of the limit
            for (int p = 2; p * p <= maximum; ++p)
            {
                // if p is prime mark multiples as prime
                if (prime[p])
                {
                    for (int i = p * p; i <= maximum; i += p)
                    {
                        maximum[i] = false;
                    }
                }
                for (int i = 2; i <= maximum; i++)
                {
                    if (maximum[i])
                    {
                        Console.WriteLine(i);
                    }
                }

            }
        }
    }
}
