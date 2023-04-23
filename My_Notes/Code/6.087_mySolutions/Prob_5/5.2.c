////////////////////////////////////////////
//
//  Binary Trees
//
////////////////////////////////////////////

In this problem, we continue our study of binary trees.
Let the nodes in the list have the following structure:

    struct tnode
    {
        int data;
        struct tnode *left;
        struct tnode *right;
    };


---------------------------------------------
(a) Write the function:
     struct tnode* talloc(int data)

     - That allocates a new node with the given data.

>>

    struct tnode *addnode(struct tnode *root, int data)
    {
        if(root == NULL)
        {
            // Allocate node
            root = talloc(data);
            return root;
        }
        // recursive call
        else if(root->data > data)
            root->left = addnode(root->left, data);

        else if(root->data < data)
            root->right = addnode(root->right, data);

        else if(root->data == data)
            return root;

        return root;
    }


---------------------------------------------
(b) Complete the function:
     addnode()

     - By filling in the missing section.
     - Insert elements 3, 1, 0, 2, 8, 6, 5, 9 in the same order.
>>

    void preorderTraversal(struct tnode *root)
    {
    if (root == NULL) return;
    printf(" %d --> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    }



---------------------------------------------
(c) Write the function:
    void preorder(struct tnode* root)

    - To display the elements using pre-order traversal.
>>





---------------------------------------------
(d) Write the function:
    void inorder(struct tnode* root)

    - To display the elements using in-order traversal.
    - Note that the elements are sorted.
>>
    void inorderTraversal(struct tnode *root)
    {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf(" %d --> ", root->data);
    inorderTraversal(root->right);
    }




---------------------------------------------
(e) Write the function:
    int deltree (struct tnode* root)

    - To delete all the elements of the tree.
    - The function must return the number of nodes deleted.
    - Make sure not to use any pointer after it has been freed.
     (Hint: use post-order traversal)
>>
    int deltree (struct tnode *root)
    {
        int delNodes = 0;
        if (root == NULL) return 0;
        delNodes += deltree(root->left);
        delNodes += deltree(root->right);
        free(root);

        return ++delNodes;
    }





---------------------------------------------
(f) Write test code to illustrate the working of each of the above functions


>> see 5.2_test.c
