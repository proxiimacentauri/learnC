#include<stdio.h>
#include<stdlib.h>

struct snode
{
    int val;
    struct snode *link;
};

void push(int ele, struct snode **head);
int pop(struct snode **head);
void isEmpty(struct snode *tmp_head);
void prints(struct snode *tmp_head);
void rev_stack(struct snode **headOriStack);

int main(void)
{
    struct snode *headOriStack = NULL;

    printf("\n-----------Original Stack-----------\n");
    push(8, &headOriStack);
    push(9, &headOriStack);
    push(10, &headOriStack);
    push(11, &headOriStack);
    prints(headOriStack);

    printf("\n-----------Reversed Original Stack-----------\n");
    rev_stack(&headOriStack);
    prints(headOriStack);

    return 0;
}

void rev_stack(struct snode **headOriStack)
{
    struct snode *head_tmpStack1 = NULL;
    struct snode *head_tmpStack2 = NULL;

    // We need to empty the original Stack into a tmpStack1
    while((*headOriStack) != NULL)
    {
        push(pop(headOriStack), &head_tmpStack1);
    }

    // We need to empty the tmpStack1 into a tmpStack2
    while((head_tmpStack1) != NULL)
    {
        push(pop(&head_tmpStack1), &head_tmpStack2);
    }

    // We need to empty the tmpStack2 into the Original Stack
    while((head_tmpStack2) != NULL)
    {
        push(pop(&head_tmpStack2), headOriStack);
    }
}

int pop(struct snode **head)
{
    // The element to be pop will be the one head is pointing to
    int ele_to_pop = (*head)->val;

    // Now the head should be pointing to the next element
    *head = (*head)->link;

    return ele_to_pop;
}

void push(int ele, struct snode **head)
{
    // Push will occur at the top of the stack i.e to whatever head points to

    struct snode *new_memb = (struct snode *)malloc(sizeof(struct snode));
    if (new_memb == NULL) {printf("\nMemory was NOT allocated. (Err:push())\n");exit(1);}

    // Creating the new member of stack
    new_memb->val = ele;

    // The new member should point to whatever head is pointing to
    new_memb->link = *head;

    // Head should point to the new member
    *head = new_memb;
}

void isEmpty(struct snode *tmp_head)
{
    if(tmp_head == NULL)
    {
        printf("\nThe Stack is Empty.\n");
        exit(1);
    }
}

void prints(struct snode *tmp_head)
{
    // The end of a LL is denoted by its link pointing to NULL
    isEmpty(tmp_head);
    // Keep iterating through the LL till we can find NULL
    while(tmp_head->link != NULL)
    {
        printf("\n|  % 3d  |", tmp_head->val);
        tmp_head = tmp_head->link;
    }
    // The loop will break when it reaches the last member of the LL
    printf("\n|  % 3d  |\n", tmp_head->val);
}