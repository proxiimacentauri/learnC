# Binary Tree
- It is a dynamic data structure
- Each node has `atmost 2 children`.
- A `binary search tree` is a binary tree with ordering among its children
- Usually all the elements in the `left sub-tree` are assumed to be `less` than the `root element` and all the elements in the `right sub-tree` which are `> root`

### Define Binary Tree Structure
```C
    struct tnode
    {
        int data;
        int tnode *left;
        int tnode *right;
    };
```

### Add Node
```C
    struct tnode *addNode(struct tnode *root, int data)
    {
        struct tnode *p = NULL;
        if(root == NULL)
        {
            // allocate a new node
            // return new root
        }
        // recursive call

        else if (data < (root->data))
            root->left = addNode(root->left, data);
        else
            root->right = addNode(root->right, data);
    }
```