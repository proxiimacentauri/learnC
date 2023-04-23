# Linked List
- Its a dynamic data structure that consists of a sequence of records.
- Where each element contains a `link` to the next record in the sequence.
- There are many types of linked lists:
    - Singly linked
    - Doubly linked
    - Circular

- Every node has a `payload` and a `link` to the next node in teh list.
- The `start(head)` of the list is maintained in a seperate variable.
- End of the list is indicated by `NULL` (sentinel).

```
    ╔═══════════╦═══════╦═════════════╗
    ║ Operation ║ Array ║ Linked List ║
    ╠═══════════╬═══════╬═════════════╣
    ║ Indexing  ║ O(n)  ║ O(1)        ║
    ╠═══════════╬═══════╬═════════════╣
    ║ Insertion ║ O(1)  ║ O(n)        ║
    ╠═══════════╬═══════╬═════════════╣
    ║ Deletion  ║ O(1)  ║ O(n)        ║
    ╚═══════════╩═══════╩═════════════╝
        O() - Worst Case Senario
```

### Define Linked List Structure
```C
    struct node
    {
        int data;
        int node *link;
    };
    struct node *head;
```

### Create a New Element
```C
    struct node *newnode(int data)
    {
        struct node *p = (struct node*)malloc(sizeof(node));
        if(p != NULL)
        {
            p->data = data;
            p->link = NULL;
        }
    }
```

### Add Node to the Front
```C
    struct node *addfront(struct node *head, int data)
    {
        struct node *p = newnode(data);
        if(p == NULL) return head;

        p->link = head;
        return p;
    }
```

### Iterate and Print
```C
    void printll(struct node *head)
    {
        struct node *p;
        for(p = head; (p->next) != NULL; p = p->next)
        {
            printf("\nValue: %d\n", p->data);
        }
    }
```