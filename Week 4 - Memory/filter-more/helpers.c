#include "helpers.h"
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    int average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue

            average = round((float) (image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen +
                                     (float) image[i][j].rgbtRed) /
                            3.0);

            // Update pixel values

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Take half of the width

    int widthHalf = width / 2;

    // Loop over all pixels but half of the width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < widthHalf; j++)
        {
            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Change each pixel value of copy

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;

            int count = 0;

            // Iterate through a 3x3 grid
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check to see neighbouring pixels are within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        totalRed += copy[ni][nj].rgbtRed;
                        totalGreen += copy[ni][nj].rgbtGreen;
                        totalBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            // Calculate the average
            image[i][j].rgbtRed = round((float) totalRed / count);
            image[i][j].rgbtGreen = round((float) totalGreen / count);
            image[i][j].rgbtBlue = round((float) totalBlue / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Change each pixel value of copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0;
            int GxGreen = 0;
            int GxBlue = 0;

            int GyRed = 0;
            int GyGreen = 0;
            int GyBlue = 0;

            int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

            int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            // Iterate through a 3x3 grid
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighbor pixel is within the image boundaries
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        GxRed += copy[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        GxGreen += copy[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        GxBlue += copy[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];

                        GyRed += copy[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                        GyGreen += copy[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        GyBlue += copy[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }

                    else
                    {
                        // Treat out-of-bounds as black pixel (0, 0, 0)
                        GxRed += 0;
                        GxGreen += 0;
                        GxBlue += 0;

                        GyRed += 0;
                        GyGreen += 0;
                        GyBlue += 0;
                    }
                }
            }
            // Calculate square root of Gx^2 + Gy^2

            int sobelAverageRed = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            int sobelAverageGreen = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            int sobelAverageBlue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));

            // Check to see if any averages are bigger than 255
            if (sobelAverageRed > 255)
            {
                sobelAverageRed = 255;
            }

            if (sobelAverageGreen > 255)
            {
                sobelAverageGreen = 255;
            }

            if (sobelAverageBlue > 255)
            {
                sobelAverageBlue = 255;
            }

            // Calculate the average
            image[i][j].rgbtRed = sobelAverageRed;
            image[i][j].rgbtGreen = sobelAverageGreen;
            image[i][j].rgbtBlue = sobelAverageBlue;
        }
    }

    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}
