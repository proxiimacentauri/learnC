////////////////////////////////////////////
//
//  Linked List
//
////////////////////////////////////////////

In this problem, we continue our study of linked lists.
Let the nodes in the list have the following structure:

    struct node
    {
        int data;
        struct node *next;
    };


---------------------------------------------
(a) Write the function:
     void display(struct node *head)

  That displays all the elements of the list.

>>
    void printLinkedlist(struct node *head)
    {
        printf("\n\n");
        struct node *p = NULL;
        for(p = head; p != NULL; p = p->next)
            printf("%d ---> ", p->data);
        printf("NULL\n\n");
    }


---------------------------------------------
(b) Write the function:
     struct node* addback(struct node* head,int data)

     - That adds an element to the end of the list.
     - The function should return the new head node to the list

>>
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

---------------------------------------------
(c) Write the function:
    struct node* find(struct node* head,int data)

    - That returns a pointer to the element in the list having the given data.
    - The function should return NULL if the item does not exist.

>>
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


---------------------------------------------
(d) Write the function:
    struct node* delnode(struct node* head, struct node* pelement)

    - That deletes the element pointed to by pelement (obtained using find).
    - The function should return the updated head node.
    - Make sure you consider the case when pelement points to the head node
>>
    struct node* delnode(struct node* head, struct node* pdel)
    {
        struct node *t = NULL;

        if (head == NULL || pdel == NULL) return NULL;
        else if (head == pdel)
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




---------------------------------------------
(e) Write the function:
    void freelist (struct node* head)

    - That deletes all the element of the list.
    - Make sure you do not use any pointer after it is freed.
>>






---------------------------------------------
(f) Write test code to illustrate the working of each of the above functions


>>


-------------------------------------------------------------------------------
------------------------------ Code Illustration ------------------------------
-------------------------------------------------------------------------------

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

struct node *head = NULL;

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

    struct node *p = (struct node*)malloc(sizeof(struct node));
    if(p != NULL)
    {
        p->data = data;
        p->next = NULL;
    }

        - p will hold the mem. addr. of memory which is the size of struct:
            Which has 2 members:
                - data
                - self-ref. struct pointer (*next)

                          +--------+
                    data: |   10   |
                          +--------+
                    next: |  NULL  |
                          +--------+
                            0x1000

                    *p = Will return nothing because we assigned memory acc to the struct
                         Now to access the values at mem. addr. p
               p->data = 10
               p->next = NULL
                     p = 0x1000


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

    struct node *head = NULL;
        - Here 'head' holds a value = NULL and it cant hold 2 values like above
          because we did not assign it any memory like above

                  +--------+
                  |  NULL  |
                  +--------+
                    0x1000

                  *head = NULL

    head = 0x2088

                  +--------+
                  | 0x2088 |
                  +--------+
                    0x1000

                    *head = 0x2088;


-------------------------------------------------------------------------------
------------------------------ Code Illustration ------------------------------
-------------------------------------------------------------------------------

struct node *addfront(struct node *head, int data)
{
    struct node *p = newnode(data);
    if (p == NULL) return head;

    p->next = head;
    return p;
}

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

+--------+
|  NULL  |
+--------+
  0x1000

------------------ 1st Call to the function -----------------

    struct node *p = newnode(10); OR  struct node *p = NULL;
                                                   p = newnode(10);

        - '*p' - Value at p = NULL
        -  'p' - Holds address = 0x2000 if newnode(10) is successful

        +--------+     +--------+
        |  NULL  |     |   10   |
        +--------+     +--------+
          0x1000       |  NULL  |
                       +--------+
                         p=0x2000

    p->next = head;

        - head = NULL, the above statement will
        - p->next = head = NULL

    return p;

        - Now head = *p
        - Head will hold the address of p

        +--------+     +--------+
        | 0x2000 |---->|   10   |
        +--------+     +--------+
          0x1000       |  NULL  |
                       +--------+
                         0x2000



------------------ 2nd Call to the function -----------------

        +--------+     +--------+
        | 0x2000 |---->|   10   |
        +--------+     +--------+
          0x1000       |  NULL  |
                       +--------+
                         0x2000

     struct node *p = newnode(20);

        - *p will hold address 0x3000 if newnode(20) is successful

        +--------+     +--------+     +--------+
        | 0x2000 |---->|   10   |     |   20   |
        +--------+     +--------+     +--------+
          0x1000       |  NULL  |     |  NULL  |
                       +--------+     +--------+
                         0x2000          0x3000

    p->next = head;

        - head = 0x2000, the above statement will
        - p->next = 0x2000

        +--------+     +--------+     +--------+
        | 0x2000 |---->|   10   |     |   20   |
        +--------+     +--------+     +--------+
          0x1000       |  NULL  |     | 0x2000 |
                       +--------+     +--------+
                         0x2000          0x3000

    return p;

        - Now head = 0x3000
        - Head will hold the address of p

        +--------+     +--------+     +--------+
        | 0x3000 |---->|   20   |---->|   10   |
        +--------+     +--------+     +--------+
          0x1000       | 0x2000 |     |  NULL  |
                       +--------+     +--------+
                         0x3000          0x2000


-------------------------------------------------------------------------------
------------------------------ Code Illustration ------------------------------
-------------------------------------------------------------------------------

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

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
+--------+
|  NULL  |
+--------+
  0x1000

------------------ 1st Call to the function -----------------

    struct node *p = newnode(15);
    struct node *t = NULL;
    if (p == NULL) return head;

        - p will hold address 0x2000 if newnode(15) is successful
        - if p=NULL which means mem. alloc. failed, so return the value of head as it is.

        +--------+     +--------+
        |  NULL  |     |   15   |
        +--------+     +--------+
         head=0x1000   |  NULL  |
                       +--------+
                         p=0x2000

        +--------+
        |  NULL  |
        +--------+
          t=0x4000

    if (head == NULL) head = p;
    return head;

        - SPECIAL CASE: if the list is empty head should hold address of new created node p.

        +--------+     +--------+
        | 0x2000 |---->|   15   |
        +--------+     +--------+
         head=0x1000   |  NULL  |
                       +--------+
                         p=0x2000

        +--------+
        |  NULL  |
        +--------+
          t=0x4000


------------------ 2nd Call to the function -----------------

        +--------+     +--------+
        | 0x2000 |---->|   15   |
        +--------+     +--------+
         head=0x1000   |  NULL  |
                       +--------+
                         0x2000


    struct node *p = newnode(15);
    struct node *t = NULL;

        - p will hold address 0x3000 if newnode(25) is successful

        +--------+     +--------+     +--------+
        | 0x2000 |---->|   15   |     |   25   |
        +--------+     +--------+     +--------+
         head=0x1000   |  NULL  |     |  NULL  |
                       +--------+     +--------+
                         0x2000        p=0x3000

        +--------+
        |  NULL  |
        +--------+
         t=0x4000


    if (head == NULL) head = p; // Will go to else block
    else
    {
        for(t = head; t->next != NULL; t = t->next)
            ;
        t->next = p;
    }

        - head which is a pointer if it is NOT NULL
        - t = mem. addr. stored in head = 0x2000


        +--------+     +--------+     +--------+
        | 0x2000 |---->|   15   |     |   25   |
        +--------+     +--------+     +--------+
         head=0x1000   |  NULL  |     |  NULL  |
                       +--------+     +--------+
                         0x2000        p=0x3000

        +--------+      +------------ For Loop -----------------------------
      t | 0x2000 |      |    +--------+
        +--------+      |  t | 0x2000 |   0x2000 -> next = NULL
          0x4000        |    +--------+        Break for Loop
                        |      0x4000     Make 0x2000 -> next = point to new
                                                                node
                                               0x2000 -> next = 0x3000

        +--------+     +--------+     +--------+
        | 0x2000 |---->|   15   |---->|   25   |
        +--------+     +--------+     +--------+
         head=0x1000   | 0x3000 |     |  NULL  |
                       +--------+     +--------+
                         0x2000        p=0x3000



        return head;
            - Return head as it is, since its position has not been modified.