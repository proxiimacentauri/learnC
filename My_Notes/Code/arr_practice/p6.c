/*
Write a program in C to print all unique elements in an array.
    Test Data :
        Print all unique elements of an array:
        ------------------------------------------
        Input the number of elements to be stored in the array: 4
        Input 4 elements in the array :
        element - 0 : 3
        element - 1 : 2
        element - 2 : 2
        element - 3 : 5
    Expected Output :
        The unique elements found in the array are:
        3 5
*/
#include<stdio.h>
int main()
{
    printf("\n\nPrint all unique elements of an array:\n");
    printf("------------------------------------------\n\n");

/*--------------------- Get User Defined Array as Input ---------------------*/
    int ar_size = 0;
    printf("\nInput the number of elements to be stored in the array: ");
    scanf("%d", &ar_size);

    int ar[ar_size];
    printf("\nInput %d elements in the array :", ar_size);
    for (int i = 0; i < ar_size; i++)
    {
        printf("\nelement - %d : ", i);
        scanf("%d", &ar[i]);
    }

/*--------------------- Find Unique Elements in the Array ---------------------*/
    int uniq_cntr = 0, k = 0;
    int ar1[ar_size];
    for (int i = 0; i < ar_size; i++)
    {
        for (int j = 0; j < ar_size; j++)
        {
            // Compare 1 ele of arr with all ele of array
            if ( ar[i] == ar[j] )
            {
                uniq_cntr++;
            }
        }

        // If uniq ele found store in another array
        if ( uniq_cntr == 1 )
        {
            ar1[k] = ar[i];
            k++;
        }
        uniq_cntr = 0; // Reset uniq_cntr = 0 for next ele in array
    }

/*--------------------- Print Unique Elements in the Array ---------------------*/
    printf("\nThe unique elements found in the array are:\n");
    int no_of_uniq_ele = k;
    for (int i = 0; i < no_of_uniq_ele; i++)
    {
        printf("% 3d", ar1[i]);
    }
    printf("\n\n");
}