#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef BYTE BLOCK[512];

int main(int argc, char *argv[])
{
     // Accept a single command-line argument

    // Ensure proper usage
    if (argc !=  2)
    {
        printf("Usage: ./recover infile\n");
        return 3;
    }

    // Remember filename
    char *infile = argv[1];
    // printf("infile %s\n",infile);

    // Open the memory card
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }
    // Syntax fread:
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    // ... reads data from the given 'stream' into the array pointed to, by 'ptr'

    BLOCK block;
    int block_size = sizeof(BLOCK);
    int blockCounter = 0;
    bool writingToFile = false;
    FILE *outptr;
    int fileCount = 0;
    char *fileName = "000.jpg";

    /*
        While there's still data left to read from the memory card
    */

    // TODO: define first file name

    while (fread(&block, block_size, 1, inptr) != 0)
    {
        /*
            Create JPEGs from the data
        */
        if (block[0]==255 && block[1] == 216 && block[2] == 255 && block[3] >= 224 && blockCounter < 23 ) //
        {
            // printf("at block %i\n",blockCounter);
            // printf("1st byte %04x\n", block[0]);
            // printf("2nd byte %04x\n", block[1]);
            // printf("3rd byte %04x\n", block[2]);
            // printf("4th byte %i\n", block[3]);

            // If output file is open then close output file
            if (writingToFile)
            {
                fclose(outptr);
                writingToFile = false;
            }
            // create new file name
            filename = "00"+

            // Open new output file
            outptr = fopen("000.jpg", "w");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", "000.jpg");
                return 5;
            } else {
                writingToFile = true;
            }
        }
        if ( writingToFile) {
            // Write to open output file
            fwrite(&block, block_size, 1, outptr);
        }
        blockCounter++;
    }
    // Close output file
    fclose(outptr);
    // Close input file
    fclose(inptr);

    printf("Total blocks read = %i\n",blockCounter);
}
