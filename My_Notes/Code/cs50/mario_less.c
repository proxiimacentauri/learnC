#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get a Positive Int from User
    int h;
    do
    {
        h = get_int("\nEnter Height: ");
    }
    while (h < 1 || h > 8);

    // Right Aligned Pyramid
    for (int i = 0; i < h; i++)
    {
        // Spaces are h-i; i=4; Spaces: 3,2,1,0
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        // i=0to4; Hash(k<=i): 0,1,2,3,4
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    // Left Aligned Pyramid
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    // Right and Left Aligned Pyramid
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}