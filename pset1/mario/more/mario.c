#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int s;
    int x;
    int j;
    // get user input
    do
    {
        n = get_int("Pyramid height: ");
    }
    while (n < 0 || n > 23);

    // Bricks
    for (x = 0; x < n; x++)
    {
        // Spaces
        for (s = 0; s < n; s++)
        {
            if (s + x < n - 1)
            {
                // spaces
                printf(" ");
            }
            else
            {
                // bricks
                printf("#");
            }
        }

        // separation between half pyramids
        printf("  ");

        // second half of pyramid
        for (j = 0; j < x + 1; j++)
        {
            if (j <= x)
            {
                printf("#");
            }
        }
        printf("\n");
    }

}


