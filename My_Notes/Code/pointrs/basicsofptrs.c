#include<stdio.h>

int main (void)
{
    int x = 1, y = 5, z[10];
    int *iptr;           // iptr points to int datatype

    iptr = &x;           // iptr holds the mem address of x which is of int datatype

    y = *iptr;           // *iptr --> deref the ptr iptr points to x which has value 1 --> y = 1

    *iptr = 10;          // *iptr points to x --> set its value to 10 ---> x = 10

    iptr = &z[10];       // iptr is now re-initilized and points to z[10]

/*-------------Unary Operators Bind more Tightly than Arithmatic------------------*/

    y = *iptr + 1;        // takes whatever ip points to ADDS 1 to it and then assigns it to y

    *iptr += 1;           // increments whatever ip points at
    ++*iptr;              // same ^^^
    (*iptr)++;            // same ^^^ () are necessary without them
                          // expression will increment ip instead of what it points to

    // Unary operators like * and ++ associate RIGHT ---> LEFT

/*--------------Pointers can be copied by other pointers of same datatype-----------------*/

    int *iq;

    iq = iptr;            // iq copies content of iptr, thus iq points to whatever iptr points to
    return 0;
}