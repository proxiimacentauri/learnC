#include <stdio.h>

#define STACK_SIZE 10

int stack_buffer[STACK_SIZE];
int top = 0;

void push(int ele)
{
    printf("\n Pushed element:  %d on top of the stack.\n", ele);
    stack_buffer[top++] = ele;
}

int pop(void)
{
    if(top > 0)         // If stack is NOT empty
    {
        int tmp = top;
        printf("\n Poped element:  %d from top of the stack.\n", stack_buffer[--tmp]);
        return stack_buffer[--top];
    }
    else
    {
        printf("\n ERROR: Stack is Empty, no element left to pop().\n");
        return -1;
    }
}

int main(void)
{
    push(10);
    push(9);
    push(8);
    push(7);
    push(6);
    push(5);

    printf("\n\n")

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}