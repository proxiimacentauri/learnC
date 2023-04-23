#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode(int data)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if(p != NULL)
    {
        p->data = data;
        p->next = NULL;
    }
    else
        prinf("\nError: Memory Allocation for %d has failed.\n", data)
    return p;
}

struct node *addfront(struct node *head, int data)
{
    struct node *p = newnode(data);
    if (p == NULL) return head;

    p->next = head;
    return p;
}
struct node* addback(struct node *head, int data)
{
    struct node *p = newnode(data);
    struct node *t = NULL;

    if (p == NULL) return head;
    if (head == NULL) head = p;
    else
    {
        for(t = head; t->next != NULL; t = t->next)
            ;
        t->next = p;
    }

    return head;
}

struct node* find(struct node* head, int data)
{
    struct node *t = NULL;
    unsigned int found = 0;

    if (head == NULL) return NULL;
    else
    {
        for(t = head; t->next != NULL; t = t->next)
        {
            if (t->data == data)
            {
                found = 1;
                break;
            }
        }
    }

    if (found == 1)
    {
        printf("\n Value Found: %d  \n", t->data);
        return t;
    }
    else
    {
        printf("\n Value NOT present. \n");
        return NULL;
    }
}

struct node* delnode(struct node* head, struct node* pdel)
{
    struct node *t = NULL;

    if (head == NULL || pdel == NULL) return NULL;
    else if (head == pdel) // If you want to delete the node after head
    {
        head = head->next;
        free(pdel);
    }
    else
    {
        for(t = head; t->next != pdel; t = t->next)
            ;
        printf("\n Deleting Node: %d \n", t->next->data);
        t->next = t->next->next;
        free(t);
    }

    return head;
}

void printLinkedlist(struct node *head)
{
    printf("\n\n");
    struct node *p = NULL;
    for(p = head; p != NULL; p = p->next)
        printf("%d ---> ", p->data);
    printf("NULL\n\n");
}

int main()
{
    struct node *head = NULL, *t = NULL;

    head = addfront (head, 1);
    head = addfront (head, 2);
    head = addfront (head, 3);
    head = addfront (head, 4);

    printLinkedlist(head);

    head = addback (head, 0);
    head = addback (head, -1);
    head = addback (head, -2);

    printLinkedlist(head);

    t = find(head, 0);
    t = find(head, 1);
    t = find(head, 8);

    head = delnode(head, find(head, 3));

    printLinkedlist(head);



    return 0;
}