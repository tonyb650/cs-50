#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            RGBTRIPLE pixel = image[row][column];
            int pixel_brightness = round(((double)pixel.rgbtBlue + (double)pixel.rgbtGreen + (double)pixel.rgbtRed)/3);
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
            // int pixel_brightness = round(((double) pixel.rgbtBlue + (double) pixel.rgbtGreen + (double) pixel.rgbtRed)/3);
            int pixelRed =round(.393 * (double) pixel.rgbtRed + .769 * (double) pixel.rgbtGreen + .189 * (double) pixel.rgbtBlue);
            int pixelGreen = round(.349 * (double) pixel.rgbtRed + .686 * (double) pixel.rgbtGreen + .168 * (double) pixel.rgbtBlue);
            int pixelBlue = round(.272 * (double) pixel.rgbtRed + .534 * (double) pixel.rgbtGreen + .131 * (double) pixel.rgbtBlue);
            if ( pixelRed <= 255 )
            {
                image[row][column].rgbtRed = pixelRed;
            } else {
                image[row][column].rgbtRed = 255;
            }
            if ( pixelGreen <= 255 )
            {
                image[row][column].rgbtGreen = pixelGreen;
            } else {
                image[row][column].rgbtGreen = 255;
            }
            if ( pixelBlue <= 255 )
            {
                image[row][column].rgbtBlue = pixelBlue;
            } else {
                image[row][column].rgbtBlue = 255;
            }
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
            image[row][column] = tempRow[width-column-1];
         }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
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
            int redTotal = 0;
            int blueTotal = 0;
            int pixelCount = 0;
            for (int boxRow = -1; boxRow < 2; boxRow++)
            {
                for (int boxColumn = -1; boxColumn < 2; boxColumn++)
                {
                    if (boxRow + row >=0 && boxRow + row < height && boxColumn + column >=0 && boxColumn + column < width)
                    {
                        greenTotal += copy[row+boxRow][column+boxColumn].rgbtGreen;
                        redTotal += copy[row+boxRow][column+boxColumn].rgbtRed;
                        blueTotal += copy[row+boxRow][column+boxColumn].rgbtBlue;
                        pixelCount++;
                    }
                }
            }
            image[row][column].rgbtGreen = round((double) greenTotal / (double) pixelCount);
            image[row][column].rgbtRed = round((double) redTotal / (double) pixelCount);
            image[row][column].rgbtBlue = round((double) blueTotal / (double) pixelCount);
        }
    }
    return;
}
