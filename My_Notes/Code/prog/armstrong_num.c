#include<stdio.h>
#include<math.h>

int main()
{
    printf("\n\n-------------Armstrong Number Check--------------\n\n");

    long long int num, tmp_num, ori_num;
    long long int min, max;
    long long int remainder, result=0;
    int num_len = 0;

    printf("\nEnter a positive lower and upper bound: ");
    scanf("%lli %lli", &min, &max);

    printf("\n Armstrong Numbers in range (%lli-%lli): ", min, max);
    for(; max >= min; min++)
    {
        num = min;              // We are going to perform operation on num
        tmp_num = num;          // Save it to another var to count how many digits
        result = 0;             // init result = 0 for every new number
        num_len = 0;            // init num_len = 0 for every new number

        while(tmp_num > 0)
        {
            tmp_num = tmp_num / 10;
            num_len++;
        }

        while (num > 0)
        {
            remainder = num % 10;              // get the last digit
            result += pow(remainder, num_len);
            num = num / 10;                    // shave off the last digit
        }

        if(min == result)     // Condition to for being an Armstrong Number
        {
            printf("%lli ", min);
        }
    }
    printf("\n\n");
    return 0;
}