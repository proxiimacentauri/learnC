/*
Write a program in C to count a total number of duplicate elements in an array.
    Test Data :
        Input the number of elements to be stored in the array :3
        Input 3 elements in the array :
        element - 0 : 5
        element - 1 : 1
        element - 2 : 1
    Expected Output :
        Total number of duplicate elements found in the array is : 1
*/
#include<stdio.h>

int main()
{
    printf("\n\nCount Total Number of Duplicate Elements in an Array:\n");
    printf("---------------------------------------------------------\n");

/*----------------- get usr specfied ele in array -----------------*/
    int ar_size = 0;
    printf("\nInput the number of elements to be stored in the array :");
    scanf("%d", &ar_size);

    int ar[ar_size];
    printf("\nInput %d elements in the array :", ar_size);
    for (int i = 0; i < ar_size; i++)
    {
       printf("\nelement - %d : ", i);
       scanf("%d", &ar[i]);
    }

/*----------------- Compare 2 Same Arrays 1 ele with all others -----------------*/
    int match = 0, tot_ele_duplicate = 0;
    for (int i = 0; i < ar_size; i++)
    {
        // Compare 1 ele of arr with all ele of array
        for (int j = 0; j < ar_size; j++)
        {
            if ( ar[i] == ar[j] )
            {
                match++;
            }

            // If there is a duplicate element
            // Increment counter
            if ( match == 2 )
            {
                tot_ele_duplicate++;
            }
        }
        match = 0; // Reset match counter for next ele in the array
    }

    printf("\nTotal number of duplicate elements found in the array is : %d", tot_ele_duplicate);
    printf("\n\n");
}