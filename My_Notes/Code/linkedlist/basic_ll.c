#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int ele_val;
    struct llnode *nxt_mem_addr;
};

struct llnode *head = NULL;

void print_ll();
void add_node_start(int val);

int main()
{
    add_node_start (1);
    add_node_start (2);
    add_node_start (3);
    add_node_start (4);
    add_node_start (5);
    add_node_start (6);
    add_node_start (7);

    // root = (struct llnode*)malloc(sizeof(struct llnode));
    // if (root == NULL)
    // {
    //     printf("\nThe memory address was NOT allocated.\n");
    // }
    // root->ele_val = 88;
    // root->nxt_mem_addr = NULL;

    // struct llnode *mem1 = (struct llnode*)malloc(sizeof(struct llnode));
    // if (mem1 == NULL)
    // {
    //     printf("\nThe memory address was NOT allocated\n");
    // }
    // mem1->ele_val = 99;
    // mem1->nxt_mem_addr = NULL;

    // root->nxt_mem_addr = mem1;

    print_ll();

    return 0;
}

void add_node_start(int val)
{
    struct llnode *new_node = (struct llnode*)malloc(sizeof(struct llnode));
    if (new_node == NULL)
    {
        printf("\nThe memory is NOT allocated.\n");
        exit (1);
    }
    new_node->ele_val = val;
    new_node->nxt_mem_addr = head; // First time it will be NULL but after that it will hold a value
    head = new_node;
}



void print_ll()
{
    struct llnode *tmp_head = head;
    if (tmp_head == NULL)
    {
        printf("\nThe list is Empty\n");
    }

    while(tmp_head != NULL)
    {
        printf("%d ---> ", tmp_head->ele_val);
        tmp_head = tmp_head->nxt_mem_addr;
    }
}