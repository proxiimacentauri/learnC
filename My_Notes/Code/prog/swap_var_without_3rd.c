#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("\n\nERROR: CLI Args are not Correct.\n\n");
        exit(1);
    }

    // atoi, atol, atoll, atof convert a string of numeric characters to
    // the equivalent int, long, long long, or float value

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("\n\n---------------Swapping 2 Values without using 3rd Variable----------------\n");

    printf("\n\nBefore Swap\n");

    printf("\nValue of a = %d\n", a);
    printf("\nValue of b = %d\n", b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\n\nAfter Swap\n");
    printf("\nValue of a = %d\n", a);
    printf("\nValue of b = %d\n", b);

    return 0;
}