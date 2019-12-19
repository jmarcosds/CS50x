/**
 * mario.c
 *
 * Joao Marcos
 * joaomarcos@tuta.io
 *
 * Recreates Nintendo Mario Bros double half-pyramid.
 * The piramid is created using hashes (#) and the
 * height is set by the user.
 *
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Declares the variable to determined the the double half-pyramid's height
    int height;

    // Gets an entry from user
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    // Variables that will construct the double half-pyramid
    int spaces = height - 1;
    int hashes = 1;

    // Loops that will assemble the double half-pyramid
    for (int he = 0; he < height; he++)
    {
        // Adds spaces to left blocks
        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }

        // Adds left blocks
        for (int ha = 0; ha < hashes; ha++)
        {
            printf("#");
        }

        // Adds the gap
        printf("  ");

        // Adds right blocks
        for (int ha = 0; ha < hashes; ha++)
        {
            printf("#");
        }

        printf("\n");

        spaces--;
        hashes++;

    }
}
