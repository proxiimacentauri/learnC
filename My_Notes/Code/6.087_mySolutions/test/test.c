#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int mot(const char *str, const char *delims);

int main(void)
{
    unsigned int d;
    d = mot(" . This@@", "!");
    printf("\nValue = %u\n", d);
}

unsigned int mot(const char *str, const char *delims)
{
    // insert code here
    unsigned int flag;

    for(flag = 0; str != NULL; str++, flag++)
    {
        if(*str == *delims)
            break;
    }
    return flag;
}
