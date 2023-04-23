#include<stdio.h>
#include<stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1

void selection_sort(int data[], int size_arr);

int main(int argc, char **argv)
{
    int rdata[10] = {55, 9, -7, -6, 99, 99, 33, 20, 5, 98};
    int size_arr  = sizeof(rdata)/sizeof(rdata[0]);

    printf("\n\n--------------Selection Sort--------------\n");

    selection_sort(rdata, size_arr);

    return EXIT_SUCCESS;
}

void selection_sort(int data[], int size_arr)
{

    printf("\n**** Unsorted Array ****\n\n");
    for(int m = 0; m < size_arr; m++)
    {
        printf("% 5d", data[m]);
    }

    int step, j, min_val_indx;

    for(step = 0; step < size_arr - 1; step++)
    {
        min_val_indx = step; // Min Value's Index

        for (j = step + 1; j < size_arr; j++)
        {
            if(data[min_val_indx] > data[j])
            {
                min_val_indx = j;
            }
        }

        // Swap
        int tmp = data[min_val_indx];
        data[min_val_indx] = data[step];
        data[step] = tmp;
    }

    printf("\n\n**** Sorted Array ****\n\n");
    for(int n = 0; n < size_arr; n++)
    {
        printf("% 5d", data[n]);
    }
    printf("\n\n");
}