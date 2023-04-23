/*
     ========= FULL Binary Tree / PROPER Binary Trees =========

    A full Binary tree is a special type of binary tree in which:
    - Every parent node/internal node has either 2 or NO children.

     ========= PERFECT Binary Trees =========

    A perfect Binary tree is a special type of binary tree in which:
    - Every parent node/internal node has 2 children.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define COUNT 10

struct tree
{
    int val;
    struct tree *l;
    struct tree *r;
};

struct tree *crnode(int data);
void in_order2D(struct tree *root, int space);
bool chk_full_bin_tree(struct tree *root);
bool chk_perfect_bin_tree(struct tree *root);

int main()
{

    printf("\n\n-----------------------------Check Full/Proper Bin Tree---------------------------\n\n");

    // Create Root Node
    struct tree *root = (struct tree*)malloc(sizeof(struct tree));
    if (root == NULL) {printf("\nRoot Node was NOT created.\n");exit(1);}
    root = crnode(0);

    // Insert on Left of Root
    root->l = crnode(1);
    root->l->l = crnode(2);
    root->l->r = crnode(3);
    root->l->l->l = crnode(4);
    root->l->l->r = crnode(5);
    root->l->r->l = crnode(6);
    root->l->r->r = crnode(7);
    root->l->l->l->l = crnode(8);

    // Insert on Right of Root
    root->r = crnode(-1);
    root->r->l = crnode(-2);
    root->r->r = crnode(-3);
    root->r->r->l = crnode(-4);
    root->r->r->r = crnode(-5);
    root->r->l->l = crnode(-6);
    root->r->l->r = crnode(-7);

    // Print the tree
    in_order2D(root, 0);


    // Check if the Tree if FULL Bin Tree or not
    if(chk_full_bin_tree(root))
        printf("\n-----It is a FULL Bin Tree------\n");
    else
        printf("\n-----It is NOT a FULL Bin Tree------\n");


    printf("\n\n-----------------------------Check Perfect Bin Tree---------------------------\n\n");

    // Check if the Tree if Perfect Tree or not
    if(chk_perfect_bin_tree(root))
        printf("\n-----It is a Perfect Bin Tree------\n");
    else
        printf("\n-----It is NOT a Perfect Bin Tree------\n");


    printf("\n\n\n\n");
    return EXIT_SUCCESS;
}

struct tree *crnode(int data)
{
    struct tree *tmpn = (struct tree *)malloc(sizeof(tmpn));
    if(tmpn == NULL) {printf("\nMemory was NOT allocated (Err:crnode)\n");exit(1);}

    tmpn->val = data;
    tmpn->l = NULL;
    tmpn->r = NULL;

    return tmpn;
}


void in_order2D(struct tree *root, int space)
{
    if(root == NULL) return;
    space += COUNT;
    in_order2D(root->r, space);
    printf("\n");
    for(int i = COUNT; i < space; i++)
        printf(" ");
    printf("% 3d\n", root->val);
    in_order2D(root->l, space);
}

bool chk_full_bin_tree(struct tree *root)
{
    // If it only Has root its a Full Bin Tree
    if(root == NULL)
        return true;

    // If both children are NOT present then its a Full Bin Tree
    if(root->l == NULL && root->r == NULL)
        return true;

    // if children exsists check if they have children
    if((root->l != NULL) && (root->r != NULL))
        return (chk_full_bin_tree(root->l) && chk_full_bin_tree(root->r));

    return false;
}

bool chk_perfect_bin_tree(struct tree *root, int d, int level)
{
    if(root == NULL)
        return true;

    if(root->l == NULL && root->r == NULL)
        return (d == level + 1);

    if(root->l != NULL && root->r != NULL)
        return


    return false
}