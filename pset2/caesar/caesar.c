#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;

    int p;

    int encypher;

    char cyphertext;

    string plaintext;

    if (argc == 1)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    key = atoi(argv[1]);

    do
    {
        // get plaintext from user
        plaintext = get_string("plaintext: ");
    }

    while (plaintext < 0);

    // print cyphertext label
    printf("ciphertext: ");

    // iterate through the plaintext string
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // convert string to int
        p = ((int) plaintext[i]);

        // check for numbers and leave as is
        if (isdigit(p))
        {
            encypher = p;
            cyphertext = encypher;
            printf("%c", cyphertext);
        }

        // check for spaces and print them
        else if (isspace(p))
        {
            printf(" ");
        }

        // check for uppercase
        else if (isupper(p))
        {
            // wrap around algorythm for uppercase letters
            encypher = ((p - 65 + key) % 26 + 65);
            cyphertext = encypher;
            printf("%c", cyphertext);
        }

        //check for lowercase
        else if (islower(p))
        {
            // wrap around algorythm for lowercase letters
            encypher = ((p - 97 + key) % 26 + 97);
            cyphertext = encypher;
            printf("%c", cyphertext);
        }

        // check for punctuation and print as is
        else if (ispunct(p))
        {
            encypher = p;
            cyphertext = encypher;
            printf("%c", cyphertext);
        }

        else
        {
            // encypher the plaintext
            encypher = ((p + key));
            cyphertext = encypher;
            printf("%c", cyphertext);

        }

    }

    printf("\n");

    return 0;

}