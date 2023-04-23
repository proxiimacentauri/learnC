#include<stdio.h>
#include<stdlib.h>

#define Stack_Size 50

/* Global Vars */

int top = -1;
int stack[Stack_Size];

void push(int data);
int pop();
void showStack();

int main()
{
    push(1);
    push(14);
    push(28);
    push(90);
    showStack();
    pop();
    showStack();
    push(pop());
    showStack();
}

void push(int data)
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