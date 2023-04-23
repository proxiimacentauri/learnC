```C
/*------------- Operators ------------*/
#include <stdio.h>

int main() {
    // Unary operators
    int x = 10, y = -5;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("++x = %d\n", ++x); // Pre-increment, x is now 11
    printf("y++ = %d\n", y++); // Post-increment, y is now -4, but this statement returns -5
    printf("--y = %d\n", --y);
    printf("~x = %d\n", ~x);
    printf("!y = %d\n", !y);
    printf("-x = %d\n", -x);

    // Binary operators
    int a = 7, b = 3;
    printf("\na = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    // Ternary operator
    int age = 17;
    char *status = (age >= 18) ? "Adult" : "Minor";
    printf("\nAge: %d, Status: %s\n", age, status);

    return 0;
}

/*------------- Datatypes ------------*/
U or u                  : Unsigned integer
L or l                  : Long integer
F or f                  : Float
L or l                  : Long double
LL or ll                : Long long integer
UL or Ul or uL or ul    : Unsigned long integer
ULL or Ull or uLL or ull: Unsigned long long integer

int x = 123U;                   // Unsigned integer
long y = 456L;                  // Long integer
unsigned long z = 789UL;        // Unsigned long integer
long long a = 123LL;            // Long long integer
unsigned long long b = 456ULL;  // Unsigned long long integer
float c = 3.14F;                // Float
long double d = 3.14L;          // Long double

/*------------- Machine Memory Addressing ------------*/

#include <stdio.h>

int main() {
    unsigned int num = 0x12345678;
    char *ptr = (char *)&num;
    printf("The value of num is: 0x%X\n", num);
    printf("The address of num is: %p\n", &num);
    printf("The byte order of num in memory is: ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02X ", *(ptr + i));
    }
    printf("\n");
    if (*ptr == 0x78) {
        printf("This machine is little-endian.\n");
    } else if (*ptr == 0x12) {
        printf("This machine is big-endian.\n");
    } else {
        printf("Unable to determine endianness.\n");
    }
    return 0;
}

/*------------- Compilation Linking of Multiple Source Files ------------*/

// myheader.h
extern int myvar;

// myvar.c
int myvar = 42;

// main.c
#include <stdio.h>
#include "myheader.h"

int main() {
    printf("The value of myvar is %d\n", myvar);
    return 0;
}
// Console
gcc -c main.c
gcc -c myvar.c
gcc -o myprogram main.o myvar.o



/*------------- Performance Memory Location vs Register ------------*/
#include <stdio.h>
#include <time.h>

#define N 1000000000

int main() {

    double elapsed_time_no_reg = 0.0;
    double elapsed_time_with_reg = 0.0;

    for (int k = 0; k < 10; k++) {

        int sum = 0;
        clock_t start = clock();

        for (int j = 0; j < N; j++) {
            sum += j;
        }

        clock_t end = clock();
        elapsed_time_no_reg += (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sum without register keyword: %d\n", sum);

        register long int sumr = 0;
        start = clock();

        for (register long int i = 0; i < N; i++) {
            sumr += i;
        }

        end = clock();
        elapsed_time_with_reg += (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sum with register keyword: %d\n", sumr);
    }

    double avg_time_no_reg = elapsed_time_no_reg / 10.0;
    double avg_time_with_reg = elapsed_time_with_reg / 10.0;

    printf("Elapsed time without register keyword: %f seconds\n", avg_time_no_reg);
    printf("Elapsed time with register keyword: %f seconds\n", avg_time_with_reg);

    return 0;
}


/*------------- Static Variable ------------*/
#include <stdio.h>

void increment() {
  static int x = 0; // static variable
  x++;
  printf("%d\n", x);
}

int main() {
  increment(); // Output: 1
  increment(); // Output: 2
  increment(); // Output: 3
  return 0;
}

/*------------- Static Function ------------*/
#include <stdio.h>

static int multiply(int a, int b) { // static function
  return a * b;
}

int main() {
  int result = multiply(2, 3);
  printf("%d\n", result); // Output: 6
  return 0;
}


/*------------- Performance of Switch vs If else ------------*/
#include <stdio.h>
#include <time.h>

void run_switch(int loops);
void run_ifelse(int loops);

int main() {

    int loops = 100;
    clock_t start_time, end_time;
    double time_elapsed_switch, time_elapsed_ifelse;

    // Benchmark switch statement
    start_time = clock();
    run_switch(loops);
    end_time = clock();
    time_elapsed_switch = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Benchmark if/else ladder
    start_time = clock();
    run_ifelse(loops);
    end_time = clock();
    time_elapsed_ifelse = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Switch statement: %f seconds\n", time_elapsed_switch);
    printf("If/else ladder: %f seconds\n", time_elapsed_ifelse);

    return 0;
}

void run_switch(int loops) {
    int input = 3;
    int output = 0;
    int i, j;
    for (j = 0; j < loops; j++) {
        for (i = 0; i < 100000000; i++) {
            switch (input) {
                case 1:
                    output = 10;
                    break;
                case 2:
                    output = 20;
                    break;
                case 3:
                    output = 30;
                    break;
                case 4:
                    output = 40;
                    break;
                default:
                    output = 0;
                    break;
            }
        }
    }
}

void run_ifelse(int loops) {
    int input = 3;
    int output = 0;
    int i, j;
    for (j = 0; j < loops; j++) {
        for (i = 0; i < 100000000; i++) {
            if (input == 1) {
                output = 10;
            } else if (input == 2) {
                output = 20;
            } else if (input == 3) {
                output = 30;
            } else if (input == 4) {
                output = 40;
            } else {
                output = 0;
            }
        }
    }
}
 // Switch : 20.72s
 // If     : 22.84s

/*------------- Usecase of goto ------------*/
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (i * j > 50) {
                goto exit_loop;
            }
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }

exit_loop:
    printf("Exited the nested loop at i=%d and j=%d\n", i, j);

    return 0;
}

/*------------- Code wihtout goto ------------*/
#include <stdio.h>

int main() {
    int i, j;
    int exit_flag = 0;

    for (i = 1; i <= 10 && !exit_flag; i++) {
        for (j = 1; j <= 10 && !exit_flag; j++) {
            if (i * j > 50) {
                exit_flag = 1;
            }
            else {
                printf("%d * %d = %d\n", i, j, i*j);
            }
        }
    }

    printf("Exited the nested loop at i=%d and j=%d\n", i-1, j-1);

    return 0;
}

/*------------- printf() Format Specifiers ------------*/
// Basic format specifiers:
printf("%d", 42);      // prints an integer
printf("%f", 3.14);    // prints a floating-point number
printf("%c", 'a');     // prints a character
printf("%s", "hello"); // prints a string

// Flags:
printf("%+d", 42);     // prints a signed integer with a plus sign
printf("%06d", 42);    // prints an integer with leading zeros
printf("%#x", 42);     // prints a hexadecimal number with a prefix
printf("%-5s", "hi");  // prints a left-justified string with a minimum width of 5

// Width and precision:
printf("%5d", 42);     // prints an integer with a minimum width of 5
printf("%.2f", 3.1415);// prints a floating-point number with 2 decimal places
printf("%.*s", 3, "hello"); // prints the first 3 characters of a string

// Modifiers:
printf("%ld", 42L);    // prints a long integer
printf("%hd", 42);     // prints a short integer
printf("%zd", sizeof(int)); // prints a size_t value
printf("%e", 1000.0);  // prints a floating-point number in scientific notation
printf("%p", &x);      // prints a pointer value

// Combining format specifiers:
printf("%-8.3f", 3.14159); // prints a left-justified floating-point number with a minimum width of 8 and 3 decimal places
printf("%+06d", 42);       // prints a signed integer with a plus sign, leading zeros, and a minimum width of 6


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // printf() - prints to stdout
    printf("Hello, world!\n");

    // sprintf() - writes to a string instead of stdout
    char buffer[100];
    sprintf(buffer, "The value of pi is approximately %.2f", 3.14159);
    printf("%s\n", buffer);

    // fprintf() - writes to a file instead of stdout
    FILE *file = fopen("output.txt", "w");
    fprintf(file, "This is written to a file.\n");
    fclose(file);

    // scanf() - reads input from stdin
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered %d.\n", number);

    // sscanf() - reads input from a string instead of stdin
    char input[] = "John Smith 42";
    char name[20];
    int age;
    sscanf(input, "%s %*s %d", name, &age);
    printf("%s is %d years old.\n", name, age);

    // fscanf() - reads input from a file instead of stdin
    file = fopen("input.txt", "r");
    char word[20];
    while (fscanf(file, "%s", word) == 1) {
        printf("%s\n", word);
    }
    fclose(file);

    // getc() - reads a single character from stdin
    printf("Enter a single character: ");
    char character = getc(stdin);
    printf("You entered '%c'.\n", character);

    // getchar() - reads a single character from stdin, but waits for Enter to be pressed
    printf("Press Enter to continue...");
    getchar();
    printf("Continuing.\n");

    // fgets() - reads a line of input from stdin
    char line[100];
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = 0; // remove trailing newline character
    printf("You entered: %s\n", line);

    // putc() - writes a single character to stdout
    putc('A', stdout);
    printf("\n");

    // fputs() - writes a string to stdout
    fputs("This is a string.\n", stdout);

    return 0;
}


int printf(const char *format, ...);
int sprintf(char *str, const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int scanf(const char *format, ...);
int sscanf(const char *str, const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int getc(FILE *stream);
int getchar(void);
char *fgets(char *str, int size, FILE *stream);
int putc(int character, FILE *stream);
int putchar(int character);
int fputs(const char *str, FILE *stream);

```
