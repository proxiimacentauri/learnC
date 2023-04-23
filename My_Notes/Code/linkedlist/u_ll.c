#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next_addr;
};

struct node *head = NULL;

void printll();

int main()
{
    struct node *mem1 = (struct node*)malloc(sizeof(struct node));
    mem1->val = 5;
    mem1->next_addr = NULL;

    struct node *mem2 = (struct node*)malloc(sizeof(struct node));
    mem2->val = 8;
    mem2->next_addr = NULL;

    printf("\n\n mem1            = %p \n mem1->next_addr = %p"
             "\n mem2            = %p \n mem2->next_addr = %p"
             "\n head            = %p\n\n",
               mem1, mem1->next_addr,
               mem2, mem2->next_addr,
               head);

    mem1->next_addr = mem2;
    head = mem1;


    printll();

    printf("\n\n mem1            = %p \n mem1->next_addr = %p"
             "\n mem2            = %p \n mem2->next_addr = %p"
             "\n head            = %p\n\n",
               mem1, mem1->next_addr,
               mem2, mem2->next_addr,
               head);

    return 0;
}

void printll()
{
    // End of LL is denoted by a NULL
    // We will keep moving till we find a NULL pointer in the member

    struct node *tmp_head = (struct node*)malloc(sizeof(struct node));
    tmp_head = head;

    if (tmp_head == NULL)
    {
        printf("\nThe list is empty\n");
    }
    while (tmp_head->next_addr != NULL)
    {
        printf(" %d ---> ", tmp_head->val);
        tmp_head = tmp_head->next_addr;
    }
    printf(" %d ---> ", tmp_head->val);
    printf("NULL\n\n");
}