# User Defined Datatypes
## Struct
- It provides a way to group a set of related vars of diverse types into single unit of memory.
- It can be referenced by a single name, pointer.
- Structure members can be accessed individually.
- They can be passed to functions and returned from functions.
Generalization:

```C
    /*-------Struct Definition--------*/
    struct name_of_struct
    {
        // struct members
    };

    /*-------Declare Struct--------*/
    int main (void)
    {
        struct name_of_struct var_name;
        return 0
    }
```
- When the struct declaration is not followed by variable, it only describes the shape of the structure.
- No space in memory is reserved.
```C
    ----------------OR----------------

    /*-------Struct Definition--------*/
    struct name_of_struct
    {
        // struct members
    } var_name2, var_name2, var_name3;

    /*-------Declare Struct--------*/
    int main (void)
    {
        name_of_struct var_name1, var_name2, var_name3;
        return 0
    }

    // struct {.....} x, y, z; is analogous to int x, y, z;
```
Code Example
```C
    #include<stdio.h>
    struct Car
    {
        char brand[50];
        char model[50];
        int year;
    };

    int main (void)
    {
        struct Car car1 = {"BMW", "340i", 2023};
        printf("\n%s %s %d \n\n", car1.brand, car1.model, car1.year);
        return 0;
    }
```

</br>
</br>


## Application of Struct
- Use “.” to refer to a field in a struct
- Use “->” to refer to a field from a struct pointer

```C
    struct Point
    {
        float x,y;
    };

    int main(void)
    {
        struct Point p1 = {0.0, 1.2};
        struct Point *ptr_to_p1 = &p1;

        p1.x = 2.0;
        ptr_to_p1->y = 0.8; // OR we can write (*ptr_to_p1).y = 0.8;

        return 0;
    }
```

</br>
</br>


## Flexible Array Member(FAM)
- Feature introduced in C99
- We can declare an array without a dimension whose size is flexible in a struct
- Such an array should be declared as a last member of the struct (size can be changed at run-time)
- Such a struct should contain 1 or more members in addition to FAM

```C
        struct student
        {
            int stud_id;
            int name_len;
            int struct_size;
            char stud_name[];
        };
```

</br>
</br>


## Structure Alignments
- The structure will have 4 bytes of padding after the 'c'
- field to ensure that the 'i' field is properly aligned on an 8-byte boundary
```C
    struct mystruct
    {
        char c;
        int i;
    } __attribute__((aligned(8))); // ensure 8-byte alignment
                        8 - bytes
            +----+----+----+----+----+----+----+----+

            +----+
            | c  |<--------------Padding------------>
            +----+

            +----+----+----+----+
            |         i         |<------Padding----->
            +----+----+----+----+
```

- With the __attribute__((packed)) syntax indicating that the members should be packed tightly without any padding bytes between them.

```C
    struct foo
    {
        char a;
        int x[2] __attribute__((packed));
    };


                        ? - bytes (Depends on mem arch ?)
            +----+----+----+----+----+----+----+----+----+

            +----+----+----+----+----+----+----+----+----+
            | a  |        x[0]       |        x[1]       |
            +----+----+----+----+----+----+----+----+----+
```

</br>
</br>


## Memory Management Struct vs Union

</br>
</br>


### Struct
- Structs allocate memory for all their member variables and arrange them in memory one after another,
```C
    struct example_struct
    {
        int a;      // 4-bytes
        char b;     // 1-byte
        double c;   // 8-bytes
    };

                                            16 - Bytes
            +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

            +----+----+----+----+----+----+----+----+----+----+----+----+----+
            |           a       |  b |                c                      |<---Padding--->
            +----+----+----+----+----+----+----+----+----+----+----+----+----+
```

</br>
</br>


### Union
- unions allocate enough memory to hold their largest member variable and all their member variables share the same memory space.
- This means that a union can only hold one member variable at a time.
- Accessing a different member variable from the current one can lead to undefined behavior.

```C
    union example_union
    {
        int a;      // 4-bytes
        char b;     // 1-byte
        double c;   // 8-bytes
    };

                                            16 - Bytes
            +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+

            +----+----+----+----+----+----+----+----+
            |                c                      |<----------------Padding--------------->
            +----+----+----+----+----+----+----+----+
            |           a       |<--------------------------Padding------------------------->
            +----+----+----+----+
            |  b |<----------------------------------Padding-------------------------------->
            +----+
```

</br>
</br>


## Usage Unions vs Structs

- Unions should be used over structs when we need to represent different types of data in the same memory space, and only one type of data is used at a time.

    Example:
    - Consider a system that needs to store the status of a battery.
    - The battery can be in one of three states:
        - charging      - signed integer
        - discharging   - signed float
        - idle          - Boolean

    - Each state is represented by a different data type.
    - Using a struct to store these values would be inefficient because we would need to allocate memory for all three types
    - Even though only one of them is used at a time.
    - union allocates enough memory to hold the largest member, which is the float for discharging.
        ```C
        union battery_status
        {
            bool idle;
            int charging;
            float discharging;
        };

        battery_status status;
        status.idle = true;
        status.charging = 10;       // OR
        status.discharging = 3.14;  // OR
        ```

</br>
</br>

## typedef and struct

- Combining typedef with struct can make code clear.

```C
/*-----------------------Without typedef----------------------------*/
    #include<stdio.h>
    #include<string.h>

    struct student
    {
        int s_rollno;
        char s_name[25];
    };

    int main (void)
    {
        struct student s1;

        strcpy(s1.s_name, "Akshay");

        s1.s_rollno = 8;

        printf("Student Roll Number: %d\n", s1.s_rollno);
        printf("Student Name: %s\n", s1.s_name);

        return 0;
    }
```

```C
/*-----------------------With typedef----------------------------*/
    #include<stdio.h>
    #include<string.h>

    typedef struct student stud_data_type;    // Define typedef with struct

    struct student
    {
        int s_rollno;
        char s_name[25];
    };

    int main (void)
    {
        stud_data_type s1;          // Code is clearer

        strcpy(s1.s_name, "Akshay");

        s1.s_rollno = 8;

        printf("Student Roll Number: %d\n", s1.s_rollno);
        printf("Student Name: %s\n", s1.s_name);

        return 0;
    }
```

</br>
</br>

# Bitfields

- Its a way to define a structure that packs several boolean values into a single integer value.
- It allows for the efficient use of memory by using fewer bytes than would be required for each boolean value individually.
- Each bitfield variable should be declared as an `unsigned int`
- The number after the colon specified the width in bits.

```C
struct my_flags
{
  unsigned char f1;
  unsigned char f2;
  unsigned char f3;
  unsigned char f4;
};
                        4 - bytes
        +----------+----------+----------+----------+
        |    f1    |    f2    |    f3    |     f4   |
        +----------+----------+----------+----------+
        |  byte 1  |  byte 2  |  byte 3  |  byte 4  |
        +----------+----------+----------+----------+

```

```C
struct my_flags
{
  unsigned int f1: 1; // the 1 specifies it is occupying 1 bit out of 8 bits
  unsigned int f2: 1;
  unsigned int f3: 1;
  unsigned int f4: 1;
};

                        4 - bytes
        +----------+
        | f1f2f3f4 |
        +----------+----------+----------+----------+
        |  byte 1  |  byte 2  |  byte 3  |  byte 4  |
        +----------+----------+----------+----------+
```

```C
struct my_flags
{
  unsigned int f1: 1;
  unsigned int f2: 1;
  unsigned int f3: 1;
  unsigned int f4: 8;
};

                        4 - bytes
        +----------+----------+
        | f1f2f3   |     f4   |
        +----------+----------+----------+----------+
        |  byte 1  |  byte 2  |  byte 3  |  byte 4  |
        +----------+----------+----------+----------+
```
- ### Bitfields vs Masks
    - Suppose we have a byte variable that represents the status of three flags: flag1, flag2, and flag3.
        - We want to write a function that sets flag1 to 1
        - Leaves flag2 and flag3 unchanged.
        ```C
            /*------------------Bit Fields---------------*/
            #include <stdio.h>

            // Define a struct with three boolean bit fields
            struct flags
            {
                unsigned int flag1 : 1;
                unsigned int flag2 : 1;
                unsigned int flag3 : 1;
            };

            // Set flag1 using a bit field assignment
            void set_flag1(struct flags *f)
            {
                f->flag1 = 1;
            }

            int main()
            {
                // Initialize a struct with some sample values
                struct flags my_flags = {0, 1, 0};

                // Print the values of the flags before setting flag1
                printf("Before setting flag1:\n");
                printf("Flag1: %d\n", my_flags.flag1);
                printf("Flag2: %d\n", my_flags.flag2);
                printf("Flag3: %d\n", my_flags.flag3);

                // Set flag1 using a bit field assignment
                set_flag1(&my_flags);

                // Print the values of the flags after setting flag1
                printf("After setting flag1:\n");
                printf("Flag1: %d\n", my_flags.flag1);
                printf("Flag2: %d\n", my_flags.flag2);
                printf("Flag3: %d\n", my_flags.flag3);

                return 0;
            }
        ```

        ```C
            /*------------------Masks---------------*/
            #include <stdio.h>

            // Define masks for each flag
            #define FLAG1_MASK 0x01
            #define FLAG2_MASK 0x02
            #define FLAG3_MASK 0x04

            // Set flag1 using a mask
            void set_flag1(unsigned char *f)
            {
                *f |= FLAG1_MASK;
            }

            int main()
            {
                // Initialize a byte variable with some sample values
                unsigned char my_byte = 0x02;

                // Print the values of the flags before setting flag1
                printf("Before setting flag1:\n");
                printf("Flag1: %d\n", (my_byte & FLAG1_MASK) ? 1 : 0);
                printf("Flag2: %d\n", (my_byte & FLAG2_MASK) ? 1 : 0);
                printf("Flag3: %d\n", (my_byte & FLAG3_MASK) ? 1 : 0);

                // Set flag1 using a mask
                set_flag1(&my_byte);

                // Print the values of the flags after setting flag1
                printf("After setting flag1:\n");
                printf("Flag1: %d\n", (my_byte & FLAG1_MASK) ? 1 : 0);
                printf("Flag2: %d\n", (my_byte & FLAG2_MASK) ? 1 : 0);
                printf("Flag3: %d\n", (my_byte & FLAG3_MASK) ? 1 : 0);

                return 0;
            }
        ```


</br>
</br>

# Compound Data Types
- Consider this compound data structure, assume 32-bit x86 processor.

    ```C
        #include <stdio.h>

        struct foo              /*-----16 bytes------*/
        {
            short s;                // 2 bytes
            union                   // int > char
            {                       // 4 bytes
                int i;              // 32-bit = 4 bytes aligned
                char c;
            }u;
            unsigned int flag_s: 1; // 1 - byte
            unsigned int flag_u: 2; // 1 - byte
            unsigned int bar;       // 4 - bytes
        };                          // 32-bit = 4 bytes aligned

        int main()
        {
            printf("The size of short is %zu bytes.\n", sizeof(struct foo));
            return 0;
        }
    ```

- We can re-arrage this data structure and optimize the size of the DS.

    ```C
        #include <stdio.h>

        struct foo              /*-----12 bytes------*/
        {
            union                   // int > char
            {                       // 4 bytes
                int i;              // 32-bit = 4 bytes aligned
                char c;
            }u;
            unsigned int bar;       // 4 - bytes
            short s;                // 2 bytes
            unsigned int flag_s: 1; // 1 - byte
            unsigned int flag_u: 2; // 1 - byte
        };

        int main()
        {
            printf("The size of short is %zu bytes.\n", sizeof(struct foo));
            return 0;
        }
    ```
