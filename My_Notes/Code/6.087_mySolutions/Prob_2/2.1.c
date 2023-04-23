//////////////////////////////////////////////
// Determine the size,minimum and maximum value following data types.
// Please specify if your machine is 32 bit or 64 bits in the answer
//////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    // If the sizeof void pointer is 8 bytes its a 64-bit machine
    if (sizeof(void*) == 8)
        printf("\n\t\t Its a 64 bit machine \n\n");
    else
        printf("\n\t\t Its a 32 bit machine \n\n");

    printf("\n Size of char          --> %lu \t\t Range: %d to %d \n",   sizeof(char),            CHAR_MIN, SCHAR_MAX);
    printf("\n Size of unsigned char --> %lu \t\t Range: %d to %d \n\n", sizeof(unsigned char),   0, UCHAR_MAX);

    printf("\n Size of short         --> %lu \t\t Range: %d to %d \n\n", sizeof(short),           SHRT_MIN, SHRT_MAX);

    printf("\n Size of int           --> %lu \t\t Range: %d to %d \n",   sizeof(int),             INT_MIN, INT_MAX);
    printf("\n Size of unsigned int  --> %lu \t\t Range: %d to %u \n\n", sizeof(unsigned int),    0, UINT_MAX);

    printf("\n Size of long          --> %lu \t\t Range: %lu to %lu \n",  sizeof(long),           LONG_MIN, LONG_MAX);
    printf("\n Size of unsigned long --> %lu \t\t Range: %d to %lu \n\n", sizeof(unsigned long),  0, ULONG_MAX);

    printf("\n Size of float         --> %lu \t\t Range: %e to %e \n",   sizeof(float),           FLT_MIN, FLT_MAX);
    printf("\n Size of double        --> %lu \t\t Range: %e to %e \n\n", sizeof(double),          DBL_MIN, DBL_MAX);
    printf("\n\n");
}


/*   Learnings   */
/*
    %e   --> Represent in Exponential Form
    %lu  --> Return of sizeof() --> Unsigned Long
    %u   --> Use for unsigned data type

    We can find out if the machine on which the code is running is 64-bit or 32 bit
    check the size of (*void) pointer if == 8 its a 64-bit machine
*/