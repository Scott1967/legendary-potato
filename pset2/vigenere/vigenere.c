#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //initialize variables
    int i;

    int j = 0;

    int k;

    int p;

    int c;

    string plaintext;

    //check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    //iterate over argv[1] for correct input
    for (int l = 0; l < strlen(argv[1]); l++)
    {
        if (ispunct(argv[1][l]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        if (isdigit(argv[1][l]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        if (iscntrl(argv[1][l]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        if (isspace(argv[1][l]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        if (isblank(argv[1][l]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    //get user input of plaintext
    do
    {
        plaintext = get_string("plaintext: ");
    }
    while (plaintext < 0);

    //print ciphertext label
    printf("ciphertext: ");

    //iterate over plaintext & argv[1]
    for (i = 0, j = 0; i < strlen(plaintext); i++)
    {
        p = plaintext[i];

        k = argv[1][j];

        //check for lowercase
        if (islower(k))
        {
            k = k - 97;
        }

        //check for uppercase
        if (isupper(k))
        {
            k = k - 65;
        }

        //check for numbers and print as is
        if (isdigit(p))
        {
            printf("%c", p);
        }

        //check for punctuation and print as is
        if (ispunct(p))
        {
            printf("%c", p);
        }

        //check for spaces and print as is
        if (isspace(p))
        {
            printf("%c", p);
        }

        //encript plaintext alpha characters
        if (isalpha(p))
        {
            //check for lowercase
            if (islower(p))
            {
                //encription algorythm for lowercase
                c = ((p + k - 97) % 26 + 97);

                printf("%c", c);
            }

            //check for uppercase
            if (isupper(p))
            {
                //encription algorythm for uppercase
                c = ((p + k - 65) % 26 + 65);

                printf("%c", c);
            }

            //raise the value of j
            j++;

            //check for end of keyword & return to the first character
            if (argv[1][j] == '\0')
            {
                j = 0;
            }
        }

    }

    //print new line
    printf("\n");

    return 0;
}