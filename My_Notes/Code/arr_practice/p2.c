/*
Write a program in C to read n number of values in an array and display it in reverse order.
    Test Data :
        Input the number of elements to store in the array :3
        Input 3 number of elements in the array :
        element - 0 : 2
        element - 1 : 5
        element - 2 : 7
    Expected Output :
        The values store into the array are :
        2 5 7
        The values store into the array in reverse are :
        7 5 2
*/
#include<stdio.h>

int main()
{
    // Get Size of Array from User
    int ar_size = 0;
    printf("\nInput the number of elements to store in the array :");
    scanf("%d", &ar_size);

    // Declare Array with User Length
    int ar[ar_size];

    // Get Array Elements from User
    printf("\nInput %d number of elements in the array :\n", ar_size);
    for(int i = 0; i < ar_size; i++)
    {
        printf("\nelement - %d : ", i);
        scanf("%d", &ar[i]);
    }

    // Print Array Elements in Order
    printf("\nThe values store into the array are :\n");
    for (int i = 0; i < ar_size; i++)
    {
        printf("% 3d", ar[i]);
    }

    // Print Array Elements in Reverse Order
    printf("\nThe values store into the array in reverse are :\n");
    for (int j = ar_size -1; j >= 0; j--)
    {
        printf("% 3d", ar[j]);
    }
    printf("\n\n");
}