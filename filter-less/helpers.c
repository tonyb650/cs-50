#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixel = image[row][column];
            int pixel_brightness = (pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed)/3;
            image[row][column].rgbtBlue = pixel_brightness;
            image[row][column].rgbtGreen = pixel_brightness;
            image[row][column].rgbtRed = pixel_brightness;
         }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixel = image[row][column];
            int pixel_brightness = (pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed)/3;

            image[row][column].rgbtBlue = pixel_brightness * 0.5;
            image[row][column].rgbtGreen = pixel_brightness;
            image[row][column].rgbtRed = pixel_brightness;
         }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        RGBTRIPLE tempRow[width];
        for (int column = 0; column < width; column++)
        {
            tempRow[column] = image[row][column];
         }
        for (int column = 0; column < width; column++)
        {
            image[row][column] = tempRow[width-column];
         }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    printf("height= %i , width= %i\n", height, width);
    // start by making a full copy of image
    RGBTRIPLE copy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }
    // copy is made, now alter original
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int greenTotal = 0;
            int pixelCount = 0;
            for (int boxRow = -1; boxRow < 2; boxRow++)
            {
                for (int boxColumn = -1; boxColumn < 2; boxColumn++)
                {
                    if (column >400)
                    {
                        printf("boxRow+row= %i\n",boxRow+row);
                        printf("boxColumn+column= %i\n",boxColumn+column);
                    }
                    if (boxRow+row >=0 && boxRow+row <=width && boxColumn+column >=0 && boxColumn+column <= height)
                    {
                        greenTotal += copy[row+boxRow][column+boxColumn].rgbtGreen;
                        pixelCount++;
                    }
                }
            }
            printf("got here, row= %i column=%i greenTotal=%i pixelCount=%i\n", row, column, greenTotal, pixelCount);
            image[row][column].rgbtGreen = (int) greenTotal / pixelCount;
        }
    }
    return;
}
