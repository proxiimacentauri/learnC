#include<stdio.h>

typedef unsigned long ulong;

int main (void)
{
    ulong var1=0;

    var1 = 8888888888888888888;
mv typedef.c
    printf("\n Value of var1 = %lu\n", var1);

    return 0;
}