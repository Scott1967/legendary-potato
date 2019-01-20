#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // initialise integers
    int n = 0;
    int outerLoop = 0;
    int innerLoop = 0;
    do
    {
        // get pyramid height from user
        n = get_int("Number please between 0 - 23: ");
    }

    // validate user input
    while (n < 0 || n > 23);

    // outer loop
    for (outerLoop = 0; outerLoop < n; outerLoop++)
    {
        // inner loop
        for (innerLoop = 0; innerLoop < n + 1; innerLoop++)
        {
            // algorythm for creating pyramid shape
            if (innerLoop + outerLoop < n - 1)
        {
            // print spaces
            printf(" ");
        }
            else
        {
            // print hash tags
            printf("#");
        }

        }
        // start new line
        printf("\n");
    }
}