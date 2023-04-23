#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int rollno;
    int name_len;
    int struct_size;
    char stud_name[];
};

int main (void)
{
    struct student s1;
    struct student *ptr_to_s1;

    printf("\n sizeof(s1)=%lu", sizeof(ptr_to_s1));
    ptr_to_s1 = malloc(sizeof(*ptr_to_s1) + sizeof(char) * strlen("Akshay"));
    printf("\n sizeof(s1)=%lu", sizeof(ptr_to_s1) + sizeof(char) * strlen("Akshay"));

    (*ptr_to_s1).rollno = 8;
    (*ptr_to_s1).name_len = 6;
    (*ptr_to_s1).struct_size = sizeof(ptr_to_s1);
    strcpy((*ptr_to_s1).stud_name, "Akshay");

    printf("\nRoll Number: %d"
           "\nName Length: %d"
           "\nStructure Size: %d"
           "\nStudent Name: %s",
           (*ptr_to_s1).rollno,
           (*ptr_to_s1).name_len,
           (*ptr_to_s1).struct_size,
           (*ptr_to_s1).stud_name);

    printf("\n");
    return 0;
}