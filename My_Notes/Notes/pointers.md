# Pointers

- Pointer is a variable that contains the memory address of another variable.

- Ex:
    - `p` is a pointer to `int` datatype.
    - Unary operator `*` is indirection or dereferencing operator
    - When `*` is applied to a pointer it accesses the object pointer points to
        ```C
        int *p;
        ```
    - Assigns memory address of variable `c` to the variable `p`
    - `p` is said to point to `c`
    - `&` operator only applied to objects in memory. (NOT to expressions, constants or register variables)
        ```C
        int c;
        p = &c;
        ```

</br>
</br>

## Pointers and Function Arguments
- C passes arguments to functions by VALUE.
- There is NO direct way for the called function to alter the argument variable in the function.

Ex:
- Function to swap 2 values.
    ```C
        swap(a, b);

        void swap(int x, int y)   // This is WRONG it will not alter a and b
        {
            int tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
    ```
- Because of CALL BY VALUE `swap()` CANT affect `a` and `b`, the function swaps the COPIES of `a` and `b`.
    ```C
        swap(&a, &b);
        void swap (int *px, int *py)
        {
            int tmp;
            tmp = *px;
            *px = *py;
            *py = tmp;
        }
    ```

</br>
</br>


## Pointers and Arraysa
- Any operation that can be achieved by array subscripting can also be done with pointers.
- Pointer version will generally be faster.

Ex:
```C
    int x, a[10];       // Defines array of size 10
    int *pa;            // pa is a pointer to an int datatype
    pa = &a[0];         // initializing the pa pointer to point to array a[10]'s first element

    x = *pa;            // Copies whatever pa points to (a[0]) and assign it to x
    x = *(pa + 1);      // increments the pa to point to a[1] and assign it to x
```

- Initialize Array:
    - `pa` and `a` have identical values since name of an array is a synonym for the location of the initial element.
        ```C
        pa  = &a[0];

        /*-----The above can also be written as-----*/
        pa = a;
        ```

    - In evaluating `a[i]`, C converts it to `*(a + i)` immediately.
    - This means that `a[i]` is equivalent to `pa[i] ===> *(pa + i)`.


- When an array name is passed to a function, what is passed is the LOCATION of the initial ELEMENT
- So within the function arg, array name is a POINTER, which points to the 1st element of the array

    ```C
    strlen("Akshay");

    int strlen(char *s)    // strlen will return an int, char *s , s is a pointer to a char data type
    {
        for (int len = 0; *s != '\0'; s++)  // we check value of whatever s points to to match '\0'
        {                                   // when iteration completes we need to move to next mem loc, which can be done by incrementing s
            len++;
        }
        return len++;
    }

    /*-------Both are equivalent--------*/

    int strlen(char *s) and int strlen(char s[])
    ```