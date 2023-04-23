#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int val;
    struct llnode *link;
};

struct llnode *push(int value, struct llnode *head);
struct llnode *pop(struct llnode *head);
void printll(struct llnode *head);
void isEmpty(struct llnode *head);

int main ()
{
    struct llnode *head = NULL;
    struct llnode *head1 = NULL;
    struct llnode *head2 = NULL;
    struct llnode *tmp = NULL;

    printf("\n-----------Stack 1-----------\n");
    head = push(1, head);
    head = push(10, head);
    head = push(100, head);
    head = push(1000, head);
    printll(head);

    printf("\n-----------Stack 2-----------\n");
    tmp = pop(head); head = tmp->link;
    head1 = push(tmp->val, head1);
    tmp = pop(head); head = tmp->link;
    head1 = push(tmp->val, head1);
    tmp = pop(head); head = tmp->link;
    head1 = push(tmp->val, head1);
    tmp = pop(head); head = tmp->link;
    head1 = push(tmp->val, head1);
    printll(head1);

    printf("\n-----------Stack 3-----------\n");
    tmp = pop(head1); head1 = tmp->link;
    head2 = push(tmp->val, head2);
    tmp = pop(head1); head1 = tmp->link;
    head2 = push(tmp->val, head2);
    tmp = pop(head1); head1 = tmp->link;
    head2 = push(tmp->val, head2);
    tmp = pop(head1); head1 = tmp->link;
    head2 = push(tmp->val, head2);
    printll(head2);

    printf("\n-----------Stack 1-----------\n");
    tmp = pop(head2); head2 = tmp->link;
    head = push(tmp->val, head);
    tmp = pop(head2); head2 = tmp->link;
    head = push(tmp->val, head);
    tmp = pop(head2); head2 = tmp->link;
    head = push(tmp->val, head);
    tmp = pop(head2); head2 = tmp->link;
    head = push(tmp->val, head);
    printll(head);

    return 0;
}

struct llnode *pop(struct llnode *head)
{
    struct llnode *mem_to_pop= (struct llnode *)malloc(sizeof(struct llnode));
    if (mem_to_pop == NULL) {printf("\nMemory was NOT allocated (Err:pop)\n");exit(1);}

    // Member to pop is whatver head is pointing to
    mem_to_pop = head;
    // Print the poped member
    printf("\nPoped element is: %d\n", mem_to_pop->val);

    return mem_to_pop; // This will hold Data & where Head should point after the pop
}

struct llnode *push(int value, struct llnode *head)
{
    // Create a new member of the LL
    // Assign value and set link to point to whatver head points to
    struct llnode *new_mem = (struct llnode *)malloc(sizeof(struct llnode));
    if (new_mem == NULL) {printf("\nMemory was NOT allocated (Err:push)\n");exit(1);}

    new_mem->val = value;
    // Now new node should point to whatever Head is pointing to
    new_mem->link = head;
    // now head should point to the new member
    head = new_mem;
    return head;
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
        printf(" %d ---> ", head->val);
        head = head->link;
    }

    // The loop will break when it has found the member whos link points to NULL
    printf(" %d ---> NULL\n\n", head->val);
}
