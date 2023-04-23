#include <stdio.h>

int main()
{
    unsigned int num = 0x12345678;
    char *ptr = (char *)&num;

    printf("\n\n  Value of num: 0x%02X\n", num);
    printf("Address of num: %p\n", &num);
    printf("\n\nByte Order in memory is: \n\n");
    printf("\t--------------------------------\n");
    for (int i = 0; i < sizeof(num); i++)
    {
        printf("\t|  %p   |   0x%02X   |\n", (void *)(ptr + i), *(ptr + i));
        printf("\t--------------------------------\n");
    }

    if (*ptr == 0x78)
    {
        printf("\n\nThis machine is little-endian.\n");
    }
    else if (*ptr == 0x12)
    {
        printf("\n\nThis machine is big-endian.\n");
    }
    else
    {
        printf("\n\nUnable to determine endianness.\n");
    }
    return 0;
}
