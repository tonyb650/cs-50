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
    //
    // BYTE header_data[HEADER_SIZE];
    // fread(header_data, HEADER_SIZE, 1, input);
    // fwrite(header_data, HEADER_SIZE, 1, output);
    BLOCK block;
    int block_size = sizeof(BLOCK);
    int counter = 0;

    /*
        While there's still data left to read from the memory card
    */

    while (fread(&block, block_size, 1, inptr) != 0)
    {
        // sample *= factor;
        // fwrite(&sample, sample_size, 1, output);
        if (counter == 2)
        {
            printf("first byte %04x\n", block[0]);
            printf("first byte %04x\n", block[1]);
            printf("first byte %04x\n", block[2]);
            printf("first byte %04x\n", block[3]);
            printf("first byte %i\n", block[3]);
        }
        
        counter++;
    }
    printf("Counter = %i\n",counter);
        // Create JPEGs from the data




    // // Open output file
    // FILE *outptr = fopen(outfile, "w");
    // if (outptr == NULL)
    // {
    //     fclose(inptr);
    //     printf("Could not create %s.\n", outfile);
    //     return 5;
    // }


    fclose(inptr);



}
