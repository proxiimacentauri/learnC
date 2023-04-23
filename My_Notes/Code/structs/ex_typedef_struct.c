#include<stdio.h>
#include<string.h>

typedef struct student stud_data_type;

struct student
{
    int s_rollno;
    char s_name[25];
};

int main (void)
{
    stud_data_type s1;

    strcpy(s1.s_name, "Akshay");

    s1.s_rollno = 8;

    printf("Student Roll Number: %d\n", s1.s_rollno);
    printf("Student Name: %s\n", s1.s_name);

    return 0;
}