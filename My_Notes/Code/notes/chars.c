/*
    Script will help with how to deal with
    - Single Chars
    - Words
    - Sentences

    Give the following input to the script:

        C
        Language
        Is the best
*/


#include <stdio.h>
#include <string.h>

int main()
{
    /*
        To take a sentence as an input
        %*c - It reads the new line char and the '*' discards the new line char
    */

    char ch, word[20], sentence[20];

    scanf("%c \n %s %[^\n]c", &ch, word, sentence);
    printf("%c\n", ch);
    printf("%s\n", word);
    printf("%s", sentence);
    return 0;
}