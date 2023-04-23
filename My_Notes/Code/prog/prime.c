#include <stdio.h>

int main()
{
    long long int min = 0, max = 0, flag = 0;
    printf("\n\n------------Prime Number Check------------\n\n");
    printf("\n Please specify the lower and upper bound: ");
    scanf("%lld %lld", &min, &max);

    for(long long int num = min; max > num; ++num)
    {
        flag = 0;           // Re-init flag for the next number

        if(num == 0 || num == 1)
        {
            flag = 1;       // 0 and 1 are NOT prime
        }

        for(long long int i = 2; i <= num/2; i++)
        {
            if(num % i == 0)
            {
                flag = 1;   // If the number is divisible its NOT prime
                break;
            }
        }

        if(flag == 0)
        {
            printf("%lld ", num);
        }
    }
    printf("\n");
    return 0;
}code 