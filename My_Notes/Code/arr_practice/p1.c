/*
    Write a program in C to store elements in an array and print it.
    Test Data :
        Input 10 elements in the array :
        element - 0 : 1
        element - 1 : 1
        element - 2 : 2
    Expected Output :
        Elements in array are: 1 1 2 3 4 5 6 7 8 9
*/

#include<stdio.h>

int main()
{
    int a[10]; // Declare Array

    // Get Array from User
    printf("\nInput 10 elements in the array : \n");
    for(int i = 0; i < 10; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &a[i]);
    }

    // Print Array
    printf("\nExpected Output :\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}