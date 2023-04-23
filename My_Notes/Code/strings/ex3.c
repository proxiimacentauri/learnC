#include<stdio.h>
#include<string.h>

#define ROWS 2
#define COLS 15

int print_str(char *c, int rows, int cols);

int main(void)
{
    char str[ROWS][COLS] = { "You know what", "C is powerful." };
    print_str(&str[0][0], ROWS, COLS);
    return 0;
}

int print_str(char *c, int rows, int cols)
{
    size_t i, j;
    for ( i = 0; i < rows; i++ )
    {
        for ( j = 0; j < cols; j++ )
        {
            printf("%c", *(c + (i * cols + j)));
        }
    }

    return 0;
}