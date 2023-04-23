#include <stdio.h>
#include <stdlib.h>

struct qnode
{
    int data;
    struct qnode *next;
};
struct qnode *qbuff = NULL;
struct qnode *rear = NULL;      // No need to track front

void enq(int ele)
{
    struct qnode *new_node = (struct qnode *)malloc(sizeof(struct qnode));
    if(new_node != NULL)
    {
        printf("\n Enqueue -->  %d on front of the queue.\n", ele);
        new_node->data = ele;
        new_node->next = NULL;

        if(rear != NULL) // When the queue has an element in it
            rear->next = new_node;
        else             // When queue is empty and adding the 1st element
            qbuff = new_node;

        rear = new_node;
    }
    else
    {
        printf("\n ERROR: Memory could NOT be allocated to new_node for enqueue().\n");
    }
}

int deq(void)
{
    if(qbuff != NULL)
    {
        struct qnode *p = qbuff;
        int ele = qbuff->data;
        qbuff = qbuff->next;

        if(p == rear)       // Queue reaches its End
            rear = NULL;

        printf("\n Dequeue <--  %d from rear of the queue.\n", ele);
        free(p);            // Remove node from Memory
        return ele;
    }
    else
    {
        printf("\n ERROR: Dequeue can't be performed as queue buffer is empty.\n");
        return 0;
    }
}

int main(void)
{
    enq(10);
    enq(9);
    enq(8);
    enq(7);
    enq(6);
    enq(5);

    printf("\n\n");

    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
    deq();
}