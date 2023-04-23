#include<stdio.h>
#include<string.h>

int print_string(char *ch, int len);

int main(void)
{
    char s[] = "I like C!";

    print_string(s, strlen(s));

    return 0;
}

int print_string(char *ch, int len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%c", *(ch + i));
    }
    printf("\n");

    printf("%s", ch);
    return 0;
}