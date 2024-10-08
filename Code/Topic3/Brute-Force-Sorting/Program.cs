using System;

class Program
{
    static void Main(string[] args)
    {
        // Define the original and scrambled strings
        string original = "EXAMPLE";
        char[] selectionArray = "XAMPLEE".ToCharArray();
        char[] bubbleArray = "XAMPLEE".ToCharArray();

        // Print the original and scrambled strings
        Console.WriteLine("Original string: " + original);
        Console.WriteLine("Scrambled string: " + new string(selectionArray));

        // Perform and display Selection Sort
        Console.WriteLine("\nSelection Sort Steps:");
        SelectionSort(selectionArray, original);

        // Perform and display Bubble Sort
        Console.WriteLine("\nBubble Sort Steps:");
        BubbleSort(bubbleArray, original);
    }

    // Selection Sort implementation
    static void SelectionSort(char[] arr, string target)
    {
        for (int i = 0; i < target.Length; i++)
        {
            int minIndex = -1;
            for (int j = i; j < arr.Length; j++)
            {
                if (arr[j] == target[i] && (minIndex == -1 || j < minIndex))
                {
                    minIndex = j;
                }
            }
            if (minIndex != -1 && minIndex != i)
            {
                char temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
            Console.WriteLine(new string(arr));
        }
    }

    // Enhanced Bubble Sort implementation
    static void BubbleSort(char[] arr, string target)
    {
        for (int i = 0; i < arr.Length - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < arr.Length - 1 - i; j++)
            {
                // Compare adjacent characters using enhanced comparison for repeated characters
                if (CompareChars(arr, j, j + 1, target) > 0)
                {
                    // Swap characters if they are in the wrong order
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            Console.WriteLine(new string(arr));

            // Stop if no swaps occurred in this pass
            if (!swapped)
                break;
        }
    }

    // Enhanced CompareChars method to handle repeated characters based on position
    static int CompareChars(char[] arr, int index1, int index2, string target)
    {
        int pos1 = FindPosition(arr, index1, target);
        int pos2 = FindPosition(arr, index2, target);

        return pos1.CompareTo(pos2);
    }

    // Find the correct position of a character in the target string, handling repeated characters
    static int FindPosition(char[] arr, int index, string target)
    {
        char character = arr[index];
        int count = 0;

        // Count occurrences of the character before the current index
        for (int i = 0; i <= index; i++)
        {
            if (arr[i] == character) count++;
        }

        // Find the correct nth occurrence of the character in the target string
        int occurrence = 0;
        for (int i = 0; i < target.Length; i++)
        {
            if (target[i] == character)
            {
                occurrence++;
                if (occurrence == count)
                {
                    return i;  // Return the correct index in the target string
                }
            }
        }

        return target.Length;  // If the character is not found, return a large value
    }
}
