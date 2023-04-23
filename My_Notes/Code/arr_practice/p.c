#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // Get card number
    long n = get_long("Number: ");
    // Count length
    int i = 0;
    long cc = n;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }

    // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        sum1 = sum1 + mod1;
        // Shorten the Number
        x = x / 10;
        // Remove second last digit
        mod2 = x % 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
        // Shorten the Number
        x = x / 10;
    }
    while (x > 0);
    total = sum1 + sum2;
}