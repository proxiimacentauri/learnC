/////////////////////////////////////////////////////
//  Write logical expressions that tests whether a given character variable c is:
//  - Lower Case
//  - Upper Case
//  - digit
//  - whitespace (space, tab, new line)
/////////////////////////////////////////////////////

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int agrc, char **argv)
{
    int c = argv[1][0]; // char c = argv[1][0];
    char *res = NULL;

    printf("\n\n\t\t Checking --> %c\n", c);

    if (islower(c)) // (c >= 'a' && c <= 'z')
        res = "Lowercase";

    else if (isupper(c)) // (c >= 'A' && c <= 'Z')
        res = "Uppercase";

    else if (isdigit(c))  // (c >= '0' && c <= '9')
        res = "Digit";

    else if (isspace(c)) // (c >= '\n' && c <= '\t' && c <= '')
        res = "Whitespace";

    else
        res = "Undefined";

    printf ("\n\n Result: \'%c\' ---> %s\n", c, res);

    printf("\n\n ----------- Learnings -----------\n\n");

    printf("sizeof(argv[1])    --> %lu\n\n", sizeof(argv[1]));
    printf("sizeof(argv[1][0]) --> %lu\n\n", sizeof(argv[1][0]));

    return 0;
}



/*      Learnings       */
/*
    - The argument for islower, isupper and isdigit is INT not CHAR
    - To define a string --> char *str = NULL; Always set it to NULL if value is going to come later.
    - Here we see that
        int c = '8'

        printf("The value of c = %c", c);  ----->  8
        printf("The value of c = %d", c);  ----->  56

    if (islower(c)) ---> 'c' needs to be declared as an int
    if (c >= 'a' && c <= 'z') ---> 'c' need to be declared as a char

        ./myprogram hello world

     argv[0] ---> "./myprogram"
     argv[1] ---> "hello"
     argv[2] ---> "world"
     argv[1][0] ---> 'h'
        Which is the 1st char of the 2nd CLI arg "hello"
*/
