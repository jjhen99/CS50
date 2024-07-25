#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Set an output file
    FILE *output = NULL;

    // Create buffer for block of data
    uint8_t buffer[512];

    // Set a jpeg counter
    int jpeg = 0;

    // Set up an array that holds file names
    char filename[50];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data

        // First three bytes in a JPEG are 0xff 0xd8 0xff
        // Fourth bytes first four bits are 1110
        // These first 4 bytes demarcate the start of a JPEG

        // Check to see if the start of a new jpg file has been detected
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if output file already exists, close the output file
            if (output != NULL)
            {
                fclose(output);
            }

            // Create name of new jpg file
            sprintf(filename, "%03d.jpg", jpeg++);

            // Create output file using name made previously
            output = fopen(filename, "w");

            // If output file doesn't exist, end program and return 1
            if (output == NULL)
            {
                printf("Could not create output JPEG file.\n");
                return 1;
            }
        }

        // If output file exists, write buffer to output file
        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }

    // close last opened output
    if (output != NULL)
    {
        fclose(output);
    }

    // close card.raw file
    fclose(card);
    return 0;
}
