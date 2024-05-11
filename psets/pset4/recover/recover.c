// Recovers lost images from corrupted memory card

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // define buffer, BYTE and jpgcounter
    typedef uint8_t BYTE;
    BYTE buffer[512];       // Holds read data
    short BLOCK = 512;      // Size of block
    short imgNum = 0;       // Nr of images found
    char filename[8];       // 8 char array for filename
    FILE *image;            // File pointer for output file
    FILE *file;             // File pointer for input file

    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: recover IMAGE\n");
        return 1;
    }
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not read file\n");
        return 1;
    }

    // Repeat until end of card
    while (fread(&buffer, sizeof(BYTE), BLOCK, file) == BLOCK)
    {
        // Check for start of jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If first jpeg
            if (imgNum == 0)
            {
                // Make new jpg, write chunks, increment counter
                sprintf(filename, "%03i.jpg", imgNum);
                image = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK, image);
                imgNum++;
            }
            else
            {
                // Close file,  count up,  open new file
                fclose(image);
                sprintf(filename, "%03i.jpg", imgNum);
                image = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK, image);
                imgNum++;
            }
        }
        else
        {
            // If already found jpeg
            if ((buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff || (buffer[3] & 0xf0) != 0xe0) && imgNum > 0)
            {
                // Keep writing to current jpg
                fwrite(buffer, sizeof(BYTE), BLOCK, image);
            }
        }
    }
    // close any remaining files
    fclose(image);
    fclose(file);
    return 0;
}