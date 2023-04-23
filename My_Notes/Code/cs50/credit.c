#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<stdlib.h>

int calc_Len_of_Num(long n)
{
    int len = 0;

    if (n < 10) return 1;
    while (n)
    {
        n /= 10;
        len++;
    }
    printf("\nLenght of n = %d\n",len);
    return len;
}

int* store_num_to_arr(long long card_Num, int card_Len)
{
    int *arr_num = (int*)malloc(card_Len * sizeof(int));
    if (arr_num == NULL)
    {
        printf("Memory not alocated.\n");
        return NULL;
    }
    else
    {
        for (int i=0; i < card_Len; i++)
        {
            arr_num[i] = (long long)( card_Num / pow(10, card_Len - 1 -i )) % 10;
            printf("Card Num in Array Index [%d] = %d\n", i, arr_num[i]);
        }
        printf("\n");
        return arr_num;
    }
}

int main(void)
{
    // Get Number from User
    long long card_Num = 0;
    int card_Len;
    do
    {
        card_Num = get_long_long("Enter Card Number: ");
        card_Len = calc_Len_of_Num(card_Num);
    }
    while(card_Len < 1 || card_Len > 16);

    // Implement Luhns Algo

        // Store CC No. as an Array
        int *card_Digits = store_num_to_arr(card_Num, card_Len);

        // Get sum_Digitsto multiply with 2
        int mul2_Numbers[card_Len];
        int m = 0;
        for (int j = (card_Len - 2); j >= 0; j--, m++)
        {
            mul2_Numbers[m] = (*(card_Digits + j) * 2);
            printf("The Number x2 = %d and the current sum = %d\n", *(card_Digits + j), mul2_Numbers[m]);
            j -= 1;
        }
        printf("\n");

        int sum_Digits = 0;
        for (int n = 0 ; n <= m -1 ; n++)
        {
            int len_Num = calc_Len_of_Num(mul2_Numbers[n]);

            if (len_Num > 1)
            {
                for (int i=0; i < len_Num; i++)
                {
                    sum_Digits+= (long long)( mul2_Numbers[n] / pow(10, len_Num - 1 - i )) % 10;
                    printf("Num = %d -- Iteration [%d] = %d\n", mul2_Numbers[n], i, sum_Digits);
                }
            }
            else
            {
                sum_Digits += mul2_Numbers[n];
                printf("Num = %d -- Iteration [%d] = %d\n", mul2_Numbers[n], m, sum_Digits);
            }
        }
        printf("\n");

        // Add sum to sum_Digitswhich were !multiplied by 2
        int final_sum = sum_Digits;
        for (int k = (card_Len - 1); k >0; k--)
        {
            final_sum += (*(card_Digits + k));
            printf("\nThe Final Sum [%d]--%d = %d", k, *(card_Digits + k), final_sum);
            k -= 1;
        }
        printf("\n");

        // Check last digit of the above sum
        int nlen_fin_sum = calc_Len_of_Num(final_sum);
        int *fin_arr = store_num_to_arr(final_sum, nlen_fin_sum);
        int last_Digit = fin_arr[1];

        printf("\n The Final Sum = %d, Last Digit = %d", final_sum, last_Digit);

        // Print which card it is
        if (last_Digit == 0)
        {
            // VISA = Starts with 4
            if (*(card_Digits + 0) == 4)
            {
                printf("\nVISA\n");
            }
            // Amex = Starts with 34 37
            else if ((*(card_Digits + 0) == 3) && (*(card_Digits + 1) == 4 || *(card_Digits + 1) == 7))
            {
                printf("\nAmerican Express\n");
            }
            // MasterCard = Starts with 51 52 53 54 55
            else if (*(card_Digits + 0) == 5)
            {
                for (int t=0; t <= 5; t++)
                {
                    if (*(card_Digits + 1) == t)
                    {
                        printf("\nMasterCard\n");
                    }
                }
            }
            else
            {
                printf("\n Card is VALID !!\n");
            }
        }
        else
        {
            printf("\nINVALID !!\n");
        }
}