#include <stdio.h>
#include <stdlib.h>

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
    // While there's still data left to read from the memory card
    while (fread(&sample, sample_size, 1, input) != 0)
    {
        sample *= factor;
        fwrite(&sample, sample_size, 1, output);
        counter++;
    }
        // Create JPEGs from the data
    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 5;
    }





}
