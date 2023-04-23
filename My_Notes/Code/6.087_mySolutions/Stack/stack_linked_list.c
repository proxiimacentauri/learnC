#include <stdio.h>
#include <stdlib.h>

struct stack_node
{
    int data;
    struct stack_node *next;
};
struct stack_node *stack_buffer = NULL;


void push(int ele)
{
    struct stack_node *new_node = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (new_node != NULL)
    {
        new_node->data = ele;
        new_node->next = stack_buffer;
        stack_buffer = new_node;
        printf("\n Pushed element:  %d on top of the stack.\n", ele);
    }
    else
    {
        printf("\n ERROR: Memory allocation for new_node failed.\n");
    }
}

int pop(void)
{
    if (stack_buffer != NULL)
    {
        struct stack_node *p = stack_buffer;
        int ele = p->data;
        stack_buffer = stack_buffer->next;
        free(p);
        printf("\n Poped element:  %d from top of the stack.\n", ele);
        return ele;
    }
    else
    {
        printf("\n ERROR: The stack is empty NO elements left to pop().\n");
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

    return 0;
}