/*
     ========= Binary Tree =========
    A binary tree is a tree data structure in which
    - Each parent node can have at most 2 children.
    - Each node of a binary tree consists of 3 items:
        - data item
        - address of left child
        - address of right child
*/

#include<stdio.h>
#include<stdlib.h>

#define COUNT 10

struct tree
{
    int val;
    struct tree *leftl;
    struct tree *rightl;
};

struct tree *createnode(struct tree *root, int data);
struct tree *insertleft(struct tree *root, int data);
struct tree *insertright(struct tree *root, int data);
void pre_order(struct tree *root);
void in_order(struct tree *root);
void post_order(struct tree *root);
void in_order_2D(struct tree *root, int space);

int main()
{
    printf("\n\n--------------------------Binary Tree-------------------------\n\n");

    // Create Root Node
    struct tree *root = (struct tree*)malloc(sizeof(struct tree));
    root = createnode(root, 0);

    // Insert Element on Left of Root
    insertleft(root, 1);
    insertleft(root->leftl, 2);
    insertright(root->leftl, 3);

    // Insert Element on Right of Root
    insertright(root, -1);
    insertleft(root->rightl, -2);
    insertright(root->rightl, -3);



    // Traverse tree Root --> Left and Root --> Right
    printf("Pre-order traversal \n");
    pre_order(root);
    printf("\n\nIn-Order traversal \n");
    in_order(root);
    printf("\n\nPost-Order traversal \n");
    post_order(root);
    printf("\n\n2D In-Order traversal \n");
    in_order_2D(root, 0);
    printf("\n\n\n\n");

    return EXIT_SUCCESS;
}

struct tree *createnode(struct tree *root, int data)
{
    struct tree *tmpnode = (struct tree *)malloc(sizeof(struct tree));
    if(tmpnode == NULL) {printf("\nMemeory was NOT allocated (Err:createnode)\n");exit(1);}

    tmpnode->val = data;
    tmpnode->leftl = NULL;
    tmpnode->rightl = NULL;

    return tmpnode;
}

struct tree *insertleft(struct tree *root, int data)
{
    root->leftl = createnode(root, data);

    return root->leftl;
}

struct tree *insertright(struct tree *root, int data)
{
    root->rightl = createnode(root, data);

    return root->rightl;
}

void pre_order(struct tree *root)
{
    if (root == NULL) return;
    printf(" % 3d --> ", root->val);
    pre_order(root->leftl);
    pre_order(root->rightl);
}

void in_order(struct tree *root)
{
    if (root == NULL) return;
    in_order(root->leftl);
    printf(" % 3d --> ", root->val);
    in_order(root->rightl);
}

void post_order(struct tree *root)
{
    if (root == NULL) return;
    post_order(root->leftl);
    post_order(root->rightl);
    printf(" % 3d --> ", root->val);
}

void in_order_2D(struct tree *root, int space)
{
    if (root == NULL) return;

    space += COUNT;
    in_order_2D(root->rightl, space);
    printf("\n");
    for(int i = COUNT; i < space; i++)
        printf(" ");
    printf(" % 3d\n", root->val);

    in_order_2D(root->leftl, space);
}
