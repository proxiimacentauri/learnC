#include<stdio.h>
#include<stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1

void selection_sort(int data[], int size_arr);
void bubbleSort(int rdata[], int arr_size);
void swap(int *a, int *b);
void print_arr(int *arr, int size_arr);

int main(int argc, char **argv)
{
    int rdata[10] = {55, 9, -7, -6, 99, 99, 33, 20, 5, 98};
    int size_arr  = sizeof(rdata)/sizeof(rdata[0]);

    printf("\n\n--------------Selection Sort--------------\n");
    selection_sort(rdata, size_arr);
    int rdata1[10] = {55, 9, -7, -6, 99, 99, 33, 20, 5, 98};
    printf("\n\n--------------Bubble Sort--------------\n");
    bubbleSort(rdata1, size_arr);

    return EXIT_SUCCESS;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int *arr, int size_arr)
{
    for(int p = 0; p < size_arr; p++)
    {
        printf("% 5d", arr[p]);
    }
}

void selection_sort(int data[], int size_arr)
{

    printf("\n**** Unsorted Array ****\n\n");
    print_arr(&data[0], size_arr);

/*---------------------------------------------------------------------------*/
    int step, j;

    for(step = 0; step < size_arr - 1; step++)
    {
        int minv_indx = step; // Selecting index as min per iteration {0 ... size_arr}
        for(j = step + 1; j < size_arr; j++)
        {
            if(data[minv_indx] > data[j]) // if currele (min) >  next_elem
            {
                minv_indx = j;      // set next index as min_ele
            }
        }
        swap(&data[step], &data[minv_indx]); // place min_ele at the front of unsorted list
    }

/*---------------------------------------------------------------------------*/

    printf("\n\n**** Sorted Array ****\n\n");
    print_arr(&data[0], size_arr);
    printf("\n\n");
}

void bubbleSort(int rdata[], int size_arr)
{
    printf("\n**** Unsorted Array ****\n\n");
    print_arr(&rdata[0], size_arr);

/*---------------------------------------------------------------------------*/
    int step, j;

    for(step = 0; step < size_arr - 1; step++)
    {
        for(j = 0; j < size_arr - step - 1; j++)
        {
            if(rdata[j] > rdata[j+1])
            {
                swap(&rdata[j], &rdata[j+1]);
            }
        }
    }
/*---------------------------------------------------------------------------*/

    printf("\n\n**** Sorted Array ****\n\n");
    print_arr(&rdata[0], size_arr);
    printf("\n\n");
}