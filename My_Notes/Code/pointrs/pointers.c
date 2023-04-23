#include<stdio.h>

int main ()
{
    int num[5] = {1,2,3,4,5};
    int *ptr_to_num = num;
    int *ptr_to_first_val = &num[0];
    int v1 = *ptr_to_first_val;

    printf("\n ptr_to_num = %p \n", (void *)ptr_to_num);
    printf("\n ptr_to_first_val = %p \n", (void *)ptr_to_first_val);
     printf("\n v1 = %d \n", v1);
}