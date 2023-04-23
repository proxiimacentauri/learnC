#include<stdio.h>
#include<stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1
#define CIRC_BUF_SIZE 5

// Global Head and Tail Pointers for the Circular Buffer
int head = -1;
int tail = -1;
int cbuf[CIRC_BUF_SIZE];

// Enqueue
void enq(int data);
// Dequeue
int deq(void);
// Is the Circular Buffer Empty
int isEmpty(void);
// Is the Circular Buffer Full
int isFull(void);
// Print Circular Buffer
void printcbuf(void);

int main(void)
{
    printf("\n\n-------------------Circular Buffer [Array Implementation]-------------------\n\n");

    enq(5);
    enq(6);
    enq(7);
    enq(8);
    enq(9);
    printcbuf();

    deq();
    deq();
    deq();
    printcbuf();

    enq(88);
    enq(100);
    enq(1000);
    printcbuf();

    deq();
    deq();
    deq();
    printcbuf();

    return EXIT_SUCCESS;
}

// Enqueue
void enq(int data)
{
    if(isFull() == EXIT_SUCCESS)
    {
        printf("\nThe Cir Buf is FULL cant add more data.(Err:enq)\n\n");
        exit (1);
    }

    // If the Cir Buf is Empty we will initialize the head and tail pointer to point to the
    // First Value
    if(isEmpty() == EXIT_SUCCESS)
    {
        head = 0;
        tail =0;
    }
    else
    {
        tail = (tail + 1)%CIRC_BUF_SIZE;
    }
    // When we add data the tail pointer will move
    cbuf[tail] = data;
}

// Dequeue
int deq(void)
{
    if(isEmpty() == EXIT_SUCCESS)
    {
        printf("\nThe Cir Buf is Empty (Err:deq)\n\n");
        exit (1);
    }

    int store_tmp_data = cbuf[head];
    head = (head + 1)%CIRC_BUF_SIZE;

    return store_tmp_data;
}

// Is the Circular Buffer Empty
int isEmpty(void)
{
    if(head == -1 && tail == -1) return EXIT_SUCCESS; // CBuf is Empty
    return EXIT_FAILURE;
}

// Is the Circular Buffer Full
int isFull(void)
{
    // There are 2 conditions:
    // - If head = 0 and tail = (CIRC_BUF_SIZE - 1) (As array starts from index 0)
    // - If head = (tail + 1)

   if((head == 0 && tail == (CIRC_BUF_SIZE - 1)) || (head == tail + 1)) return EXIT_SUCCESS; // CBuf is FULL
   return EXIT_FAIL;
}

// Print Circular Buffer
void printcbuf(void)
{
    // Its a Queue i.e FIFO, we need to start with head and print till we reach tail

    if(isEmpty() == EXIT_SUCCESS)
    {
        printf("\nThe CBuf is Empty.(Err:printcbuf)\n\n");
        exit(1);
    }

    int i;
    printf("\nHead -> %d\n", head);

    for(i = head; i != tail; i = (i+1)%CIRC_BUF_SIZE)
    {
        printf("\n Data ---> %d", cbuf[i]);
    }
    // Print whatever tail points to
    printf("\n Data ---> %d", cbuf[i]);

    printf("\nTail -> %d\n\n\n", tail);
}