#include<stdio.h>
#include<string.h>


void pallindrome_chk(char str[]);

int main(int argc, char **argv)
{
    char *chk_str = argv[1];

    printf("\n\nString to check = %s \n", chk_str);

    pallindrome_chk(chk_str);

    return 0;
}

void pallindrome_chk(char str[])
{
    int start = 0;
    int end = strlen(str) - 1; // All string end with \0 which we want to eliminate

    while(end > start)
    {
        if(str[start++] != str[end--])
        {
            printf("\n\n '%s' is NOT a pallindrome\n\n", str);
            return;
        }
    }
    printf("\n\n'%s' is a pallindrome\n\n", str);
}