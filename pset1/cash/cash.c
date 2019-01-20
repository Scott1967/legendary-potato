#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;

    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    int dollars = round(n * 100);
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int qcount = 0;
    int dcount = 0;
    int ncount = 0;
    int pcount = 0;
    int coins = 0;

    while (dollars >= quarters)
    {
        dollars = dollars - 25; qcount++; coins++;
    }

    while (dollars >= dimes)
    {
        dollars = dollars - 10; dcount++; coins++;
    }

    while (dollars >= nickels)
    {
        dollars = dollars - 5; ncount++; coins++;
    }

    while (dollars >= pennies)
    {
        dollars = dollars - 1; pcount++; coins++;
    }

    printf("Total coins used: %i\n", coins);
    printf("Type of coins used:");
    printf(" %i quarters,", qcount);
    printf(" %i dimes,", dcount);
    printf(" %i nickels,", ncount);
    printf(" %i pennies.\n", pcount);
}