#include<stdio.h>
#define XMAX 5
#define YMAX 5

struct Point
{
    int x, y;
};

struct Rectangle
{
    struct Point p1;
    struct Point p2;
};

/*-----------------Create a Point (Return a Struct)-------------------*/
struct Point make_point (int a, int b)
{
    struct Point tmp_var;

    tmp_var.x = a;
    tmp_var.y = b;

    return tmp_var;
}

/*-----------------Adds Points (Accept a Struct and Return a Struct)-------------------*/
struct Point add_points (struct Point pt1, struct Point pt2)
{
    pt1.x += pt2.x;
    pt1.y += pt2.y;

    return pt1;
}

int main(void)
{

    printf("\n\nCreating a Screen which has a Rectangle in it with 2 Points\n\n");

    struct Rectangle screen;

    screen.p1 = make_point(0, 0);
    screen.p2 = make_point(XMAX, YMAX);

    struct Point middle;
    middle = make_point((screen.p1.x + screen.p1.y)/2, (screen.p2.x + screen.p2.y)/2);

    printf("Point 1 = {%d, %d}\n"
           "Point 2 = {%d, %d}\n"
           "Middle = {%d, %d}\n\n",
            screen.p1.x, screen.p1.y,
            screen.p2.x, screen.p2.y,
            middle.x, middle.y);

    struct Point p3;
    p3 = add_points (screen.p1, screen.p2);

    printf("Point 1 = {%d, %d}\n"
           "Point 2 = {%d, %d}\n"
           "Point 3 = {%d, %d}\n\n",
            screen.p1.x, screen.p1.y,
            screen.p2.x, screen.p2.y,
            p3.x, p3.y);

    return 0;
}