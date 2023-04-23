#include<stdio.h>
#include<stdlib.h>

struct snode
{
    int val;
    struct snode *nxt_addr;
};

struct snode *head = NULL;

void push(int ele);

void pop();

void print_stack();


int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    push(8);
    push(78);
    push(56);
    push(00);
    push(1234);

    print_stack();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    print_stack();

    return 0;
}

void print_stack()
{
    printf("\n\n");
    // Copy head
    struct snode *tmp_h = (struct snode*)malloc(sizeof(struct snode));
    tmp_h = head;

    if (tmp_h == NULL)
    {
        printf("\n\nThe Stack is Empty\n\n");
        exit (1);
    }

    // keep moving till we find a member which points to NULL
    while (tmp_h->nxt_addr != NULL)
    {
        printf(" %d ---> ", tmp_h->val);
        tmp_h = tmp_h->nxt_addr;
    }
    printf("%d ---> ", tmp_h->val);
    printf("NULL\n\n");
}

void push(int ele)
{
    // We need to insert ele at the start
    struct snode *new_mem = (struct snode*)malloc(sizeof(struct snode));
    new_mem->val = ele;
    new_mem->nxt_addr = head; // Point the new node to whatever head points to
    head = new_mem;           // head now points to new member
}

void pop()
{
    // Head points to 1st mem in stack .. become 1st member
    struct snode *first_mem = (struct snode*)malloc(sizeof(struct snode));
    first_mem = head;
    printf("\nPop: %d\n", first_mem->val);

    // Reset head to point to 2nd element in stack
    head = first_mem->nxt_addr;
}