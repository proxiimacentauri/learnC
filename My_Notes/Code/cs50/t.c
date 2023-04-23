#include <stdio.h>nclude <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *fullstr = NULL;
    scanf("%s", fullstr);
    int i;
    int c1, c2, c3, c4, c5, c6, c7, c8, c9, c0;
    c1=c2=c3=c4=c5=c6=c7=c8=c9=c0=0;
    for(i = 0; i < strlen(fullstr) - 1 ; i++) // iterate over all chars
    {
        if('1' == fullstr[i])
            c1++;
        else if('2' == fullstr[i])
            c2++;
        else if('3' == fullstr[i])
            c3++;
        else if('4' == fullstr[i])
            c4++;
        else if('5' == fullstr[i])
            c5++;
        else if('6' == fullstr[i])
            c6++;
        else if('7' == fullstr[i])
            c7++;
        else if('8' == fullstr[i])
            c8++;
        else if('9' == fullstr[i])
            c9++;
        else if('0' == fullstr[i])
            c0++;
        else
            continue;
    }
    printf("%2d %2d %2d %2d %2d %2d %2d %2d %2d %2d", c0, c1, c2, c3, c4, c5, c6, c7, c8, c9 );
    return 0;
}
