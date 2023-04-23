#include<stdio.h>

int addThree (int *ptr_arr);
int alter_addThree (int arr[]);

int main(void)
{
    int list[] = {3, 2, 10};
    int res1, res2, res3, res4;

/*-----------------Passing Arr Name in Func Arg----------------*/
    res1 = addThree(list);
    res2 = alter_addThree(list);

/*----------Passing Pointer ---> Pointing to 1st ele of Array in Func Arg-------*/
    int *ptr_list = list;

    res3 = addThree(ptr_list);
    res4 = alter_addThree(ptr_list);

    printf("\n Passing Array to Func Arg Ptr = %d\n", res1);
    printf("\n Passing Array to Func Arg Array = %d\n", res2);

    printf("\n Passing Ptr to Func Arg Ptr = %d\n", res3);
    printf("\n Passing Ptr to Func Arg Array = %d\n", res4);

    return 0;
}

/*----Func Arg *ptr_arr can accept array name & Pointer ---> Pointing to 1st ele of Array------*/
int addThree (int *ptr_arr)
{
    size_t i;
    int res = 0;
    for (i = 0; i < 3; i++)
    {
        res += *(ptr_arr + i);
    }
    return res;
}

int alter_addThree (int arr[])
{
    size_t i;
    int res = 0;
    for (i = 0; i < 3; i++)
    {
        res += arr[i];
    }
    return res;
}