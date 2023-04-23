#include<stdio.h>

int main()
{
    int ar1[10];    // Delcare Array

    // User adds aray elements
    printf("\n Please Enter 10 Elements into an Array (followed by a space):\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &ar1[i]);
    }

    // Print Array
    printf("\n The Value of the Array Store is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", ar1[i]);
    }
}