#include<stdio.h>

struct Point
{
    int x, y;
};


int main (void)
{
    // Create variable pt1 a Structure of Point
    struct Point pt1;

    // Create a POINTER to struct pt1
    struct Point *ppt1;

    // Alternatively
    // struct Point pt1, *ppt1 = &pt1;

    // It says that pp is a POINTER to a structure of type struct Point
    // If pp points to a POINT structure
    //   *pp is the structure
    //  (*pp).x and (*pp).y are the members
    //  The parentheses is necessary cause the precedence of struct mem operator . is higher then * of pointer
    ppt1 = &pt1;

    printf("\nUsing pt1.x|y Notation:\n"
           "\n Point 1 = {%d, %d}\n",
           pt1.x, pt1.y);

    // Pointer can refer to member of struct
    (*ppt1).x = 0;
    (*ppt1).y = 1;

    printf("\nUsing (*ppt1).x|y Notation:\n"
           "\n Point 1 = {%d, %d}\n",
           (*ppt1).x, (*ppt1).y);

    // Alternatively
    ppt1->x = 10;
    ppt1->y = 11;

    printf("\nUsing pptr->x|y Notation:\n"
           "\n Point 1 = {%d, %d}\n",
           ppt1->x, ppt1->y);
    return 0;
}