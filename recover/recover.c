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
        return 1;
    }

    // Remember filename
    char *infile = argv[1];

    // Open the memory card
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }

    BLOCK block;
    int block_size = sizeof(BLOCK);
    int blockCounter = 0;
    bool writingToFile = false;
    FILE *outptr;
    int fileCount = 0;
    char fileName[8];

    /*
        While there's still data left to read from the memory card
    */
    while (fread(&block, block_size, 1, inptr) != 0)
    {
        /*
            Create JPEGs from the data
        */
        if (block[0]==255 && block[1] == 216 && block[2] == 255 && block[3] >= 224) //
        {

            // If output file is open then close output file
            if (writingToFile)
            {
                fclose(outptr);
                writingToFile = false;
                fileCount++;
            }
            // create new file name
            if (fileCount < 10)
            {
                snprintf(fileName, 8, "00%d.jpg", fileCount);
            }
            else if (fileCount < 100)
            {
                snprintf(fileName, 8, "0%d.jpg", fileCount);
            }
            else if (fileCount < 1000)
            {
                snprintf(fileName, 8, "%d.jpg", fileCount);
            }
            else
            {
                printf("Too many files");
                return 6;
            }

            // Open new output file
            outptr = fopen(fileName, "w");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", fileName);
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

    // printf("Total blocks read = %i\n",blockCounter);
}
