// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef uint16_t SAMPLE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Syntax fread:
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    // ... reads data from the given 'stream' into the array pointed to, by 'ptr'

    BYTE header_data[HEADER_SIZE];
    fread(header_data, 1, HEADER_SIZE, input);
    fwrite(header_data, 1, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    SAMPLE sample;
    int sample_size = sizeof(SAMPLE);
    while (fread(&sample, sample_size, 1, input) != 0)
    {
        sample *= factor;
        fwrite(&sample, sample_size, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
