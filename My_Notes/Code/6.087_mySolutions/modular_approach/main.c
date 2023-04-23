#include <stdio.h>
#include "math_funcs.h"
int main(void)
{
    vect p, q;
    p.x = 1.0f;
    p.y = 2.0f;
    q.x = 6.0f;
    q.y = 9.0f;

    addVect(&p, &q);

    printf("\nResult: p->x = %f   p->y = %f\n", p.x, p.y);
}