/*
Write a program in C to find the sum of all elements of the array.
    Test Data :
        Input the number of elements to be stored in the array :3
        Input 3 elements in the array :
        element - 0 : 2
        element - 1 : 5
        element - 2 : 8
    Expected Output :
        Sum of all elements stored in the array is : 15
*/

#include<stdio.h>
int main()
{
    // Get Array Size from User
    int ar_size = 0;
    printf("\nInput the number of elements to be stored in the array :");
    scanf("%d", &ar_size);

    int ar[ar_size];

    // Get Array ele from User
    printf("\nInput %d elements in the array :", ar_size);
    for (int i = 0; i < ar_size; i++)
    {
        printf("\nelement - %d : ", i);
        scanf("%d", &ar[i]);
    }

    // Perform Sum and Print
    int s = 0;
    for (int i = 0; i < ar_size; i++)
    {
        s += ar[i];
    }
    printf("\nSum of all elements stored in the array is : %d", s);
    printf("\n\n");
}