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

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
