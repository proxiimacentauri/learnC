/*
    Write a program in C to copy the elements of one array into another array.
    Test Data :
        Input the number of elements to be stored in the array :3
        Input 3 elements in the array :
        element - 0 : 15
        element - 1 : 10
        element - 2 : 12
    Expected Output :
        The elements stored in the first array are :
        15 10 12
        The elements copied into the second array are :
        15 10 12
*/
#include<stdio.h>

int main()
{
    int ar_size = 0;
    printf("\nInput the number of elements to be stored in the array :");
    scanf("%d", &ar_size);

    int ar[ar_size];

    printf("\nInput %d elements in the array :\n", ar_size);
    for(int i = 0; i < ar_size; i++)
    {
        printf("\nelement -  %d : ", i);
        scanf("%d", &ar[i]);
    }

    // Copy array into another array
    int ar_c[ar_size];
    for (int i = 0; i < ar_size; i++)
    {
        ar_c[i] = ar[i];
    }

    printf("\nThe elements stored in the first array are :");
    for(int i = 0; i < ar_size; i++)
    {
        printf("%d", ar[i]);
    }
    printf("\nThe elements copied into the second array are :");
    for(int i = 0; i < ar_size; i++)
    {
        printf("%d", ar_c[i]);
    }
     printf("\n\n");
}