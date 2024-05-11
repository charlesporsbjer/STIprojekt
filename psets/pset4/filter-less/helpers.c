#include "helpers.h"
#include <stdio.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //  retrieve and set max width and height
    int W = width;
    int H = height;

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;
            int blue = image[h][w].rgbtBlue;

            int GrayShade = round((red + blue + green) / 3.0);

            image[h][w].rgbtRed = GrayShade;
            image[h][w].rgbtBlue = GrayShade;
            image[h][w].rgbtGreen = GrayShade;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //  retrieve and set max width and height
    int W = width;
    int H = height;

    // loop through all pixels
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            // retrieve rgb values into ints
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;
            int blue = image[h][w].rgbtBlue;

            // use formula to convert rgb values into sepia values
            int Sred = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            if (Sred > 255)
            {
                Sred = 255;
            }

            int Sgreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            if (Sgreen > 255)
            {
                Sgreen = 255;
            }

            int Sblue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));
            if (Sblue > 255)
            {
                Sblue = 255;
            }

            // write sepia values over original values
            image[h][w].rgbtRed = Sred;
            image[h][w].rgbtGreen = Sgreen;
            image[h][w].rgbtBlue = Sblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // initialize value that will decrement from right
    int WidthDec = width;

    // iterate through arrays
    for (int CrntHeight = 0; CrntHeight < height; CrntHeight++)
    {
        WidthDec = width;

        // counter increments from left and decrements from right
        for (int CrntWidth = 0; CrntWidth < (width/2); CrntWidth++)
        {
            // decrement right-value
            WidthDec--;

            // get rgb from left
            RGBTRIPLE left = image[CrntHeight][CrntWidth];

            // assign a temporary holder value of left
            RGBTRIPLE temp = left;

            // retrieve pixelss from right
            RGBTRIPLE right = image[CrntHeight][WidthDec];

            // write right onto left coordinates
            image[CrntHeight][CrntWidth] = right;

            // write temporary holder onto right coordinates
            image[CrntHeight][WidthDec] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declare loop ints now cause why the hell not
    int i = 0, j = 0, k = 0, l = 0;

    //declare a copy for later use
    RGBTRIPLE copypx[height][width];

    // iterate through all pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // initialize pixel counter and color sums
            float pxls = 1;
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;

            // add main pixels colors to sums
            sumR += image[i][j].rgbtRed;
            sumG += image[i][j].rgbtGreen;
            sumB += image[i][j].rgbtBlue;

            /* iterate through surrounding pixels
            If they are not out of bounds; add colors to sum
            then increment the pixel counter */
            if ((i-1 >= 0 && i-1 <= height-1) && (j-1 >= 0 && j-1 <= width-1))
            {
                sumR += image[i-1][j-1].rgbtRed;
                sumG += image[i-1][j-1].rgbtGreen;
                sumB += image[i-1][j-1].rgbtBlue;
                pxls++;
            }

            if ((i-1 >= 0 && i-1 <= height-1) && (j >= 0 && j <= width-1))
            {
                sumR += image[i-1][j].rgbtRed;
                sumG += image[i-1][j].rgbtGreen;
                sumB += image[i-1][j].rgbtBlue;
                pxls++;
            }

            if ((i-1 >= 0 && i-1 <= height-1) && (j+1 >= 0 && j+1 <= width-1))
            {
                sumR += image[i-1][j+1].rgbtRed;
                sumG += image[i-1][j+1].rgbtGreen;
                sumB += image[i-1][j+1].rgbtBlue;
                pxls++;
            }

            if ((i >= 0 && i <= height-1) && (j-1 >= 0 && j-1 <= width-1))
            {
                sumR += image[i][j-1].rgbtRed;
                sumG += image[i][j-1].rgbtGreen;
                sumB += image[i][j-1].rgbtBlue;
                pxls++;
            }

            if ((i >= 0 && i <= height-1) && (j+1 >= 0 && j+1 <= width-1))
            {
                sumR += image[i][j+1].rgbtRed;
                sumG += image[i][j+1].rgbtGreen;
                sumB += image[i][j+1].rgbtBlue;
                pxls++;
            }

            if ((i+1 >= 0 && i+1 <= height-1) && (j-1 >= 0 && j-1 <= width-1))
            {
                sumR += image[i+1][j-1].rgbtRed;
                sumG += image[i+1][j-1].rgbtGreen;
                sumB += image[i+1][j-1].rgbtBlue;
                pxls++;
            }

            if ((i+1 >= 0 && i+1 <= height-1) && (j >= 0 && j <= width-1))
            {
                sumR += image[i+1][j].rgbtRed;
                sumG += image[i+1][j].rgbtGreen;
                sumB += image[i+1][j].rgbtBlue;
                pxls++;
            }

            if ((i+1 >= 0 && i+1 <= height-1) && (j+1 >= 0 && j+1 <= width-1))
            {
                sumR += image[i+1][j+1].rgbtRed;
                sumG += image[i+1][j+1].rgbtGreen;
                sumB += image[i+1][j+1].rgbtBlue;
                pxls++;
            }

            // write sums/counter into copy
            copypx[i][j].rgbtRed = round(sumR / pxls);
            copypx[i][j].rgbtGreen = round(sumG / pxls);
            copypx[i][j].rgbtBlue = round(sumB / pxls);
        }
    }
    // iterate through all pixels again
    for (k = 0; k < height; k++)
    {
        for (l = 0; l < width; l++)
        {
            // write copy onto original
            image[k][l] = copypx[k][l];
        }
    }
    return;
}