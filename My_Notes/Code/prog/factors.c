#include<stdio.h>

int main()
{
    printf("\n\n------------Factors of a Number-----------\n");

    long int num;
    printf("\n\nEnter a positve integer: ");
    scanf("%li", &num);

    printf("\n Factors of '%li' are: ", num);
    for(long int i = 1; i <= num ; i++)
    {
        if(num % i == 0)
        {
            printf("%li ", i);
        }
    }
    printf("\n\n");
    return 0;
}