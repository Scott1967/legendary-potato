// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    char x = fraction[0];
    char y = fraction[2];

    float numerator = x - 48.0;
    float denominator = y - 48.0;

    float z = ((numerator / denominator) * 8);

    int result = round(z);

    return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double f = 32.7032;
    double h = 0;
    int n = 0;

    char key = note[0];
    char accidental = note[1];
    char octave = note[2];

    if (note[2] == '\0')
    {
        accidental = '\0';
        octave = note[1];
    }

    switch(key)
    {
        case 'C':
        n += 0;
        break;
        case 'D':
        n += 2;
        break;
        case 'E':
        n += 4;
        break;
        case 'F':
        n += 5;
        break;
        case 'G':
        n += 7;
        break;
        case 'A':
        n += 9;
        break;
        case 'B':
        n += 11;
        break;
    }

    // Key A, Octave 0
    if (octave == '0' && key == 'A')
    {
        f = 27.5000;
        n -= 9;
    }
    // Key B, Octave 0
    if (octave == '0' && key == 'B')
    {
        f = 30.8677;
        n -= 11;
    }
    // C1
    if (octave == '1')
    {
        n += 0;
    }
    // C2
    if (octave == '2')
    {
        n += 12;
    }
    // C3
    if (octave == '3')
    {
        n += 24;
    }
    // C4
    if (octave == '4')
    {
        n += 36;
    }
    // C5
    if (octave == '5')
    {
        n += 48;
    }
    // C6
    if (octave == '6')
    {
        n += 60;
    }
    // C7
    if (octave == '7')
    {
        n += 72;
    }
    // C8
    if (octave == '8')
    {
        n += 84;
    }
    // Flat notes
    if (accidental == 'b')
    {
        n -= 1;
    }
    // Sharp notes
    if (accidental == '#')
    {
        n += 1;
    }

    h = (f * pow(2, n / 12.0));
    int hertz = round(h);

    return hertz;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(s[0] == '\0' || s[0] == 32)
    {
        return true;
    }
    else
    {
        return false;
    }

}

