#include "helpers.h"
#include <stdio.h>

int main(int height, int width, RGBTRIPLE image[height][width])
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

            int GrayShade = ((red + blue + green) / 3.0);

            image[h][w].rgbtRed = GrayShade;
            image[h][w].rgbtBlue = GrayShade;
            image[h][w].rgbtGreen = GrayShade;
        }
    }
    return 0;
}