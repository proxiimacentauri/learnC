#include<stdio.h>
#include<stdlib.h>

struct qnode
{
    int val;
    struct qnode *nxtPtr;
};

struct qnode *head = NULL;
struct qnode *tail = NULL;

void enq(int ele);
void deq();
void printq();

int main()
{
    enq(5);
    enq(6);
    enq(7);
    enq(8);
    enq(9);
    printq();

    deq();
    deq();
    printq();

    return 0;
}


void enq(int ele)
{
    // We want to add Always Add at the head

    // Create a new node and then assign it = ele
    struct qnode *new_node = (struct qnode*)malloc(sizeof(struct qnode));
    if (new_node == NULL) {printf("\nMemory was NOT allocated (Err:enq)\n"); exit (1);}
    new_node->val = ele;

    // The new node should point to where head points
    new_node->nxtPtr = head;

    // head should now point to the new node
    head = new_node;

    // If tail is == NULL point it to the new_node which is
    // the 1st and now the last node
    if (tail == NULL)
    {
        tail = new_node;
    }
}

void deq()
{
    printf("\nElement from Queue Dequeued = %d\n", tail->val);

    struct qnode *tmp_head = (struct qnode*)malloc(sizeof(struct qnode));
    if (tmp_head == NULL) {printf("\nMemory was NOT allocated (Err:deq)\n");exit (1);}
    tmp_head = head;

    // Find a member in q which points to the same as tail
    // Keep iterating until we find it
    while (tmp_head->nxtPtr != tail)
    {
        tmp_head = tmp_head->nxtPtr;
    }
    // After we find the 2nd last element --> make it the last element
    tmp_head->nxtPtr = NULL;
    // Tail should now point to the last element
    tail = tmp_head;
}

void printq()
{
    printf("\n\n");
    // Copy the mem loc where head is pointing
    struct qnode *tmp_head = (struct qnode*)malloc(sizeof(struct qnode));
    if (tmp_head == NULL) {printf("\nMemory was NOT allocated (Err:printq)\n"); exit (1);}
    tmp_head = head;

    // If the Head is pointing to NULL it means the q is empty
    if (tmp_head == NULL)
    {
        printf("\nThe Queue is Empty.\n");
        exit (1);
    }

    // Keep printing ele of q till we reach Null pointer
    while (tmp_head->nxtPtr != NULL)
    {
        printf(" %d ---> ", tmp_head->val);
        tmp_head = tmp_head->nxtPtr;
    }
    // The loop will break when the nextPtr = NULL print the last elemnt
    printf("%d ---> NULL\n\n", tmp_head->val);
}
