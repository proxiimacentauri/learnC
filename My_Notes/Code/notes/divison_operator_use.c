/*
    Script will showcase how to use the '/' and '%' operator to manipulate number
    - Extract digit 1 by 1 from a big number
    - perform operation on those extracted digits
*/


#include <stdio.h>

int main()
{
    /*
        When you '/' a number by 10:
        Ex:
            14687 / 10 = 1468

        - You can use this to count the number of digits

        When you '%' a number by 10:
        Ex:
            14687 % 10 = 7

        - You can use this to extract the last digit from a large number

        Together '%' and '/' can be used to sum indivisual digits of a big number
        Ex:
            14687 % 10 = 7 -----> store 7 + 0
            14687 / 10 = 1468
            1468  % 10 = 8 -----> store 8 + 7 + 0
            1468  / 10 = 146
            146   % 10 = 6 -----> store 6 + 8 + 7 + 0
            146   / 10 = 14
            .
            .
    */

    int n;
    scanf("%d", &n);

    int count = 0, tmpNum = n, sum = 0 ;

    while(tmpNum)
    {
        tmpNum = tmpNum / 10;
        count++;
    }

    for(int i = 0; i < count; i++)
    {
        sum += n % 10;
        n = n /10;
    }
    printf("%d", sum);
    return 0;
}
