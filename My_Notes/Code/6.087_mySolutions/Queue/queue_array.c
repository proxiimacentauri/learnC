#include <stdio.h>
#define BUFF_SIZE 3

int qbuff[BUFF_SIZE], front = 0, count = 0;

void enq(int ele)
{
    // If you remove if-else statements it will
    // Override exsisting elements if you try to enq if queue is full
    if(count < BUFF_SIZE)        // Guard rail so we dont overwrite existing data in queue
    {
        qbuff[(front + count) % BUFF_SIZE] = ele;
        count++;
        printf("\n Enqueue -->  %d on front of the queue.\n", ele);
    }
    else
    {
        printf("\n ERROR: Enqueue can't be performed cause Queue is FULL.\n");
    }
}

int deq(void)
{
    if(count > 0)       // Queue is NOT empty proceed to deq(ele)
    {
        int ele = qbuff[front];
        printf("\n Dequeue <--  %d from rear of the queue.\n", ele);
        count--;
        front++;
        if(front == BUFF_SIZE)   // Guard rail against going over queue buffer size
            front = 0;
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