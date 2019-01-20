// program for recovering lost or deleted photographs
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // check for proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }

    // open file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 2;
    }

    // initialize img file pointer
    FILE *img = NULL;

    // variable for storing jpeg title numbers
    int count = 0;

    // character variable to store jpeg names e.g. 001.jpg
    char title[8];

    // create buffer to store img data
    BYTE buffer[512];

    // read data on infile and loop through for jpeg signatures
    while (fread(&buffer, 512, 1, inptr))
    {
        // if jpeg signatures are found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // check if img is not NULL
            if (img)
            {
                // close old img
                fclose(img);
            }

            // create titles for jpegs
            sprintf(title, "%03i.jpg", count);

            // create and open new img file for writing
            img = fopen(title, "w");

            // change img title numbers
            count++;

        }

        // found first jpeg so start writing
        if (img)
        {
            // write img files
            fwrite(&buffer, 512, 1, img);
        }

    }

    // close & save img file
    fclose(img);

    // close infile
    fclose(inptr);

    // all good
    return 0;
}
