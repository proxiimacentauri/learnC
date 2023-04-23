/*
    Write a program in C to merge two arrays of same size sorted in decending order
    Test Data :
        Input the number of elements to be stored in the first array :3
        Input 3 elements in the array :
        element - 0 : 1
        element - 1 : 2
        element - 2 : 3
        Input the number of elements to be stored in the second array :3
        Input 3 elements in the array :
        element - 0 : 1
        element - 1 : 2
        element - 2 : 3
    Expected Output :
        The merged array in decending order is :
        3 3 2 2 1 1
*/
#include<stdio.h>

int main()
{
    printf("\n\nMerge 2 Arrays of Same Size Sorted in Decending Order:\n");
    printf("---------------------------------------------------------\n");

/*----------------- get usr specfied ele in array -----------------*/

    int size_of_ar1 = 0;
    printf("\nInput the number of elements to be stored in the first array :");
    scanf("%d",&size_of_ar1);

    int ar1[size_of_ar1];
    printf("\nInput %d elements in the array :", size_of_ar1);
    for (int i = 0; i < size_of_ar1; i++)
    {
        printf("\nelement - %d : ", i);
        scanf("%d", &ar1[i]);
    }

    int size_of_ar2 = 0;
    printf("\nInput the number of elements to be stored in the second array :");
    scanf("%d",&size_of_ar2);

    int ar2[size_of_ar2];
    printf("\nInput %d elements in the array :", size_of_ar2);
    for (int i = 0; i < size_of_ar2; i++)
    {
        printf("\nelement - %d : ", i);
        scanf("%d", &ar2[i]);
    }

/*----------------- Merge 2 Arrays -----------------*/

    int size_of_ar3 = size_of_ar1 + size_of_ar2;
    int ar3[size_of_ar3];
    for (int i = 0; i < size_of_ar1; i++)
    {
        ar3[i] = ar1[i];
        printf("ar3[%d] = %d\n",i, ar3[i]);
    }
    for (int j = size_of_ar1; j < size_of_ar3; j++)
    {
        ar3[j] = ar2[j];
        printf("ar3[%d] = %d\n",j, ar3[j]);
    }
    printf("size_of_ar3 = %d\n",size_of_ar3);
    for (int i = 0; i < size_of_ar3; i++)
    {
        printf("%d", ar3[i]);
    }
}