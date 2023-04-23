#include<stdio.h>
#include<stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1

void bubbleSort(int rdata[], int arr_size);

int main()
{
    int raw_data[10] = {55, 9, -7, -6, 99, 99, 33, 20, 5, 98};
    int size_raw_data = sizeof(raw_data)/sizeof(raw_data[0]);

    printf("\n\n--------------Bubble Sort--------------\n");

    bubbleSort(raw_data, size_raw_data);

    return EXIT_SUCCESS;
}

void bubbleSort(int rdata[], int arr_size)
{
    printf("\n**** Unsorted Array ****\n\n");
    for(int i = 0; i < arr_size; i++)
    {
        printf("% 5d", rdata[i]);
    }

    for(int step = 0; step < arr_size - 1; step++)
    {
        //int swapped = 0;                        /*---Optimization---*/
        for(int j = 0; j < arr_size - step - 1; j++)
        {
            if(rdata[j] > rdata[j+1])
            {
                int tmp = rdata[j+1];
                rdata[j+1] = rdata[j];
                rdata[j] = tmp;
                // swapped = 1;                    /*---Optimization---*/
            }
            // if(swapped == 1) {break;}           /*---Optimization---*/
        }
    }

    printf("\n\n**** Sorted Array ****\n\n");
    for(int i = 0; i < arr_size; i++)
    {
        printf("% 5d", rdata[i]);
    }
    printf("\n\n");
}