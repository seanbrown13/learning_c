#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a positive number
    int n;
    do
    {
        n = get_int("Positive number: ");
    }
    // Send them back until they enter one from 1-8. Break if valid, move to loop.
    while (n < 0 || n > 8 || n == 0);

    // Rows: Print out this many (storeys of blocks, no. times for nested loop to run)
    for (int i = 0; i < n; i++)
    {
        // Cols: Print this many "."/" "
        for (int j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }
        // Cols: Print out this many #
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }
        printf("\n");
    }
}