#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int main(void)
{
    string s = get_string("fraction x / y: ");

    char x = s[0];
    char y = s[2];

    float numerator = x - 48.0;
    float denominator = y - 48.0;

    float z = ((numerator / denominator) * 8);

    int result = round(z);

    printf("eighths = %i\n", result);

}
