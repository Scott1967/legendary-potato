#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    int bottles = 0;
    int minutes = 0;

    do
    {
      n = get_int(" How many minutes do you spend in the shower? ");
    }
    while (minutes > 0);

    bottles = (12 * n);
    minutes = n;

    printf("%i minutes.\n", minutes);
    printf("%i x 16 ounce bottles of water.\n", bottles);
}