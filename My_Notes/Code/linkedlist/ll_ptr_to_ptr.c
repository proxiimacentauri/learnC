#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int val;
    struct llnode *link;
};

void push(int value, struct llnode **head);
int pop(struct llnode **head);
void printll(struct llnode *head);
void isEmpty(struct llnode *head);

int main ()
{
    struct llnode *head = NULL;
    struct llnode *head1 = NULL;
    struct llnode *head2 = NULL;
    int data;

    printf("\n-----------Stack 1-----------\n");
    push(1, &head);
    push(10, &head);
    push(100, &head);
    push(1000, &head);
    printll(head);

    printf("\n-----------Stack 2-----------\n");
    data = pop(&head);push(data, &head1);
    data = pop(&head);push(data, &head1);
    data = pop(&head);push(data, &head1);
    data = pop(&head);push(data, &head1);
    printll(head1);

    printf("\n-----------Stack 3-----------\n");
    data = pop(&head1);push(data, &head2);
    data = pop(&head1);push(data, &head2);
    data = pop(&head1);push(data, &head2);
    data = pop(&head1);push(data, &head2);
    printll(head2);

    printf("\n-----------Stack 1-----------\n");
    data = pop(&head2);push(data, &head);
    data = pop(&head2);push(data, &head);
    data = pop(&head2);push(data, &head);
    data = pop(&head2);push(data, &head);
    printll(head);

    return 0;
}

void push(int value, struct llnode **head)
{
    // Create a new member of the LL
    // Assign value and set link to point to whatver head points to
    struct llnode *new_mem = (struct llnode *)malloc(sizeof(struct llnode));
    if (new_mem == NULL) {printf("\nMemory was NOT allocated (Err:push)\n");exit(1);}

    new_mem->val = value;
    // Now new node should point to whatever Head is pointing to
    new_mem->link = *head;
    // now head should point to the new member
    *head = new_mem;
}

int pop(struct llnode **head)
{
    int val_to_pop = (*head)->val;
    // Print the poped member
    printf("\nPoped element is: %d\n", val_to_pop);

    *head = (*head)->link;

    return val_to_pop; // This will hold Data after the pop
}

void isEmpty(struct llnode *head)
{
    if (head == NULL)
    {
        printf("\nThe Linked List is Empty.\n");
        exit(1);
    }
}

void printll(struct llnode *head)
{
    // End of a LL can be found when the last members Link points to NULL
    // So from head to that element we can traverse the LL
    isEmpty(head);
    printf("\n\n");

    // we will keep iterating and traversing till we find the member whos link points to NULL
    while (head->link != NULL)
    {
        printf("|  % 5d  |\n", head->val);
        head = head->link;
    }

    // The loop will break when it has found the member whos link points to NULL
    printf("|  % 5d  |\n\n", head->val);
}
