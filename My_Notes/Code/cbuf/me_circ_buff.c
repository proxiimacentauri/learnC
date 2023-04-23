#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 0
#define FAIL 1

struct cbnode
{
  int data;
  struct cbnode *link;
};

int pop(struct cbnode **tail);
void push(int val, struct cbnode **tail);
void printcb(struct cbnode *tail);

int main(int agrc, char **argv)
{
    struct cbnode *tail = NULL;

    printf("\n----------Circular Buffer----------\n\n");
    push(9, &tail);
    push(10, &tail);
    push(11, &tail);
    push(12, &tail);
    push(13, &tail);
    printcb(tail);

    pop(&tail);
    printcb(tail);
    pop(&tail);
    printcb(tail);

    return SUCCESS;
}

int pop(struct cbnode **tail)
{
    // Circular Queue is a FIFO
    // WE will pop whatver Tail points to

    int poped_data = (*tail)->data;
    printf("\nPoped Data = %d\n", poped_data);

    struct cbnode *first_node = (*tail)->link;
    struct cbnode *moving_node = (*tail)->link;

    while(moving_node == (*tail))
    {
        moving_node = moving_node->link;
    }
    (*tail) = m5oving_node;
    moving_node->link = first_node;

    return poped_data;
}


void printcb(struct cbnode *tail)
{
    // Save link of last node
    struct cbnode *end_node = tail;

    // from Last node go to the first node
    struct cbnode *first_node = tail->link;

    // Stop when we reach last node
    printf("  +-------->+\n"
           "  |         |\n");
    while(first_node != end_node)
    {
        printf("  |     |  % 3d  |\n", first_node->data);
        first_node = first_node->link;
    }

    printf("  |     |  % 3d  |\n"
           "  |         |\n"
           "  +<--------+\n"
            ,first_node->data);
}

void push(int val, struct cbnode **tail)
{
    // Add a New member At the start
    struct cbnode *new_ele = (struct cbnode *) malloc(sizeof(struct cbnode));
    if (new_ele == NULL) {printf("\nMemory was NOT allocated (Err:push).\n");exit(1);}

    new_ele->data = val;
    if (*tail == NULL)
    {
        new_ele->link = new_ele;
        (*tail)= new_ele;
    }
    else
    {
        new_ele->link = (*tail)->link; // New ele should point to whatever head points tod
        (*tail)->link = new_ele;       // The last nodes Link is pointing to the New Element
    }
}

