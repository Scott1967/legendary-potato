// copies and can alter the size of a bitmap image (if it works?)

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // check for incorrect number
    if (factor < 1 || factor > 100)
    {
        fprintf(stderr, "A number between 1 and 100\n");
        return 2;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(outptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // bf contains information about the old file
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // bi contains information about the old file
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // Width is the old width
    LONG oldWidth = bi.biWidth;
    LONG oldHeight = abs(bi.biHeight);

    // New width
    bi.biWidth *= factor;

    // New height
    bi.biHeight *= factor;

    // calculate the old padding
    int padding = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate new padding
    int newpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate new header information
    bi.biSizeImage = (((bi.biWidth * sizeof(RGBTRIPLE)) + newpadding) * abs(bi.biHeight));
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;

    // write the values to new BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write the values to new BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < oldHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < oldWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // print out where cursor is in scanline
            printf("Loop RGBTRIPLE: inptr = %ld\n", ftell(inptr));

            // write RGBTRIPLE factor times
            for (int k = 0; k < factor; k++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

            }

        }

        // skip over old padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // insert new padding
        for (int l = 0; l < newpadding; l++)
        {
            fputc(0x00, outptr);
        }

        // check factor and write RGBTRIPLE again to outfile for height (if required)
        for (int m = 0; m < factor - 1; m++)
        {
            // move cursor back to beginning of scanline
            fseek(inptr, -(oldWidth * sizeof(RGBTRIPLE) + padding), SEEK_CUR);

            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // print out where cursor is in scanline
                printf("Loop RGBTRIPLE: inptr = %ld\n", ftell(inptr));

                for (int k = 0; k < factor; k++)
                {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // skip over old padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // insert new padding
            for (int l = 0; l < newpadding; l++)
            {
                 fputc(0x00, outptr);
            }

        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;

}


