#include "math_funcs.h"

void addVect (vect *a, vect *b)
{
    a->x = a->x + b->x;
    a->y = a->y + b->y;
}