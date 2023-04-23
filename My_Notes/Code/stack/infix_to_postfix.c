#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>       /* for isdigit(char ) */
#include<string.h>

#define Stack_Size 50

/* Global Vars */

int top = -1;
char stack[Stack_Size];

void push(char data);
int pop();
void showStack();
int isOperator(char symbol);
int precedence(char symbol);
int infixTopostfix(char infix_exp[], char postfix_exp[]);

int main()
{
    char infix[Stack_Size] = "(3^2*5)/(3*2-3)+5";
	char postfix[Stack_Size];

	// printf("\nEnter Infix expression : ");
	// gets(infix);

	infixTopostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */

	return 0;
}

/*----------------Step 1: ----------------*/

int infixTopostfix(char infix_exp[], char postfix_exp[])
{
    /*----------------Step 1: Add ( to stack and ) to end of infix string----------------*/
    push('(');
    strcat(infix_exp,")");

    /*----------------Step 2: Scan every element in infix (end of str = \0)----------------*/

    int i, j;
    i = j = 0;      // i for infix, j for postfix

    char symbol = infix_exp[i];
    char symbol_in_stack;

    while(symbol != '\0')
    {
        /*-----------Step 2a: If symbol = digit/alpha add to postfix-----------*/
        if(isdigit(symbol) || isalpha(symbol))
        {
            postfix_exp[j] = symbol;
            j++;
        }
        /*-----------Step 2b: If symbol = ( add to stack-----------*/
        else if(symbol == '(')
        {
            push(symbol);
        }
        /*-----------Step 2c: If symbol = operator-----------*/
        else if(isOperator(symbol) == 1)
        {
            symbol_in_stack = pop();

            /*------------------Step 2d:------------------
                check if(precedence(symbol in stack) > precedence(curr symbol))
                if precedence(symbol in stack) > then add to postfix expression
                do this for all the symbols in the the stack
            */
            while(isOperator(symbol_in_stack) && precedence(symbol_in_stack) >= precedence(symbol))
            {
                postfix_exp[j] = symbol_in_stack;
                j++;
                symbol_in_stack = pop();
            }
            push(symbol);
        }
        /*-----------Step 2b: If symbol = ( add to stack-----------*/
        else if(symbol == ')')
        {
            symbol_in_stack = pop();
            while(symbol_in_stack != '(')
            {
                postfix_exp[j] = symbol_in_stack;
                j++;
                symbol_in_stack = pop();
            }
        }
        else
        {
            printf("\nInvalid Symbol (Err:infixTopostfix())\n");
            return -1;
        }

        symbol = infix_exp[++i];
    }
    return 0;
}

int precedence(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*' || symbol == '/')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
    {
        printf("\nInvalid Symbol (Err:precedence())\n");
        return -1;
    }
}

int isOperator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
    {
        printf("\nInvalid Symbol (Err:isOperator())\n");
        return 0;
    }
}

void push(char data)
{
    // Check if there is overflow
    if(top == Stack_Size)
    {
        printf("\nStack Overflow.\n");
        exit(1);
    }

    // Move pointer forward pointing to store newly added data
    top++;

    // Add data to the stack
    stack[top] = data;
}

int pop()
{
    // Check for underflow
    if(top == -1)
    {
        printf("\nStack Underflow\n");
        exit(1);
    }

    int prevTop = top;

    // Move pointer so it points to previous data
    top--;

    return stack[prevTop];
}

void showStack()
{
    // Check for underflow
    if(top == -1)
    {
        printf("\nStack is Empty.\n");
        exit(1);
    }

    for(int i = top; i >= 0; i--)
        printf("%d --> ", stack[i]);

    printf("\n\n");
}