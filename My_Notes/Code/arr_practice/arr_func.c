#include<stdio.h>

#define arr_len(arr) ( sizeof(arr)/sizeof(arr[0]) )

void print_2d_arr(size_t rows, size_t cols, int *pointer_arr)
{
    size_t i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("% 2d", pointer_arr[i * cols + j]);
        }
        printf("\n");
    }
}

int main(void)
{
    // int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // int len = arr_len(arr);
    // printf("%d", len);

    int arr[][3] = {
        {1,2,3},
        {4,5,6}
    };

    size_t i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("% 2d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    print_2d_arr(2, 3, arr[0]);


    return 0;
}