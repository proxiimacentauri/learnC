#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(int data)
{
    struct tnode *p = (struct tnode *)malloc(sizeof(struct tnode));
    if (p != NULL)
    {
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

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

void preorderTraversal(struct tnode *root)
{
  if (root == NULL) return;
  printf(" %d --> ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(struct tnode *root)
{
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf(" %d --> ", root->data);
  inorderTraversal(root->right);
}

void postorderTraversal(struct tnode *root)
{
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf(" %d --> ", root->data);
}

int deltree (struct tnode *root)
{
    int delNodes = 0;
    if (root == NULL) return 0;
    delNodes += deltree(root->left);
    delNodes += deltree(root->right);
    free(root);

    return ++delNodes;
}

int main(void)
{
    struct tnode *root = NULL;

    root = addnode(root, 3);
    root = addnode(root, 1);
    root = addnode(root, 0);
    root = addnode(root, 2);
    root = addnode(root, 8);
    root = addnode(root, 6);
    root = addnode(root, 5);
    root = addnode(root, 9);

    printf("\n\nPre-Order Traversal: \n\n");
    preorderTraversal(root);

    printf("\n\nIn-Order Traversal: \n\n");
    inorderTraversal(root);

    printf("\n\nPost-Order Traversal: \n\n");
    postorderTraversal(root);

    printf("\n\n Total Number of Nodes Deleted: %d \n\n", deltree(root));

}