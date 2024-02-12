#include "helpers.h"

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
        for (int column = 1; column < width-1; column++)
        {
            RGBTRIPLE pixel = image[row][column];
            // int pixel_brightness = (pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed)/3;
            image[row][column].rgbtBlue = (tempRow[column].rgbtBlue+tempRow[column].rgbtBlue+tempRow[column].rgbtBlue)/3;
            image[row][column].rgbtGreen = (tempRow[column].rgbtGreen+tempRow[column].rgbtGreen+tempRow[column].rgbtGreen)/3;
            image[row][column].rgbtRed = (tempRow[column].rgbtRed+tempRow[column].rgbtRed+tempRow[column].rgbtRed)/3;
            // image[row][column].rgbtGreen = pixel_brightness;
            // image[row][column].rgbtRed = pixel_brightness;
         }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
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
