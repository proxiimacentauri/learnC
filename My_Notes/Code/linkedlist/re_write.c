#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int val;
    struct llnode *next_addr;
};

struct llnode *head = NULL;

void insert_start(int ele_val);

void insert_end(int ele_val);

void find_ele(int ele_val);

void del_ele(int ele_val);

void print_ll();

int main()
{
    insert_start(5);
    insert_start(6);
    insert_start(7);
    insert_end(55);
    insert_start(1);
    insert_start(0);
    insert_end(85);
    insert_end(88);
    insert_end(100);

    print_ll();

    find_ele(88);
    del_ele(88);

    print_ll();

    return 0;
}

void del_ele(int ele_val)
{
    // In order to delete it we need to find it
    struct llnode *tmp_head = (struct llnode*)malloc(sizeof(struct llnode));
    tmp_head = head;

    // creating a pointer which will remember previous node
    struct llnode *prev_n = (struct llnode*)malloc(sizeof(struct llnode));

    // keep moving to next node till we find it
    while (tmp_head->val != ele_val)
    {
        prev_n = tmp_head;               // store prev node info
        tmp_head = tmp_head->next_addr;  // Move to the next node if curr node doesnt have the ele_val
        if (tmp_head->next_addr == NULL)
        {
            printf("\nThe element to delete was NOT found in the LL.\n");
            exit (1);
        }
    }
    printf("\nThe Node Prior to deleted Node = %d\n", prev_n->val);
    printf("\nThe Node to DELETE = %d\n", tmp_head->val);

    // Copy the curr ele pointer to we can copy it to prev ele's pointer
    prev_n->next_addr = tmp_head->next_addr;

    // set the ele's pointer to NULL
    tmp_head->next_addr = NULL;
}

void find_ele(int ele_val)
{
    // We need to copy the head pointer as the ll starts there
    struct llnode *tmp_head = (struct llnode*)malloc(sizeof(struct llnode));
    tmp_head = head;

    // We will keep moving through the list until we find the ele we are looking for
    while (tmp_head->val != ele_val)
    {
        tmp_head = tmp_head->next_addr;
        // iF we reached the End and its NOT present send message
        if (tmp_head->next_addr == NULL)
        {
            printf("\nElement is NOT present in the LL.\n");
            exit (1);
        }
    }
    printf("\nWe found the element: %d in the LL.\n", tmp_head->val);
}


void insert_end(int ele_val)
{
    printf("\nInserting %d at the end.\n", ele_val);
    struct llnode *end_node = (struct llnode*)malloc(sizeof(struct llnode));
    end_node->val = ele_val;
    end_node->next_addr = NULL;

    struct llnode *tmp_head = (struct llnode*)malloc(sizeof(struct llnode));
    tmp_head = head; // Copying where the head is pointing to

    // We need to find the current last node in the ll
    // It will be the node whose next_addr is = NULL

    while (tmp_head->next_addr != NULL) // Keep the Loop going till we find NULL
    {
        tmp_head = tmp_head->next_addr; // Need to keep moving to next node in ll
    }
    tmp_head->next_addr = end_node;
}


void insert_start(int ele_val)
{
    printf("\nInserting %d at the start.\n", ele_val);
    struct llnode *new_node = (struct llnode*)malloc(sizeof(struct llnode));
    new_node->val = ele_val;
    new_node->next_addr = head; // The new node will point to whatever the head is pointing to
    head = new_node;            // Now the head will point to new node because the new node
                                // is at the start
}

void print_ll()
{
    printf("\nPrinting the Linked List\n\n");
    struct llnode *tmp_head = (struct llnode*)malloc(sizeof(struct llnode));
    tmp_head = head;
    if (tmp_head == NULL)
    {
        printf("\nThe List is Empty.\n");
        exit (1);
    }
    while (tmp_head->next_addr != NULL)
    {
        printf(" %d -->", tmp_head->val);
        tmp_head = tmp_head-> next_addr;
        if (tmp_head->next_addr == NULL)
        {
            printf(" %d -->", tmp_head->val);
        }
    }
    printf(" NULL\n\n");
}
