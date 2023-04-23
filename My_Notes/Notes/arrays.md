# Arrays

- It has fixed num of elements of any 1 type.
- Elements are stored contiguously in memory without gaps or padding.
- C allows multi-dim array and array of pointers.
- C supports dynamically allocated array whose size can be determined at run-time.
- C99 and later supports variable length array VLA
- Declaring array of 0 length is not allowed

> Generalization: datatype arrName[size];

Ex:
- An array of 10 int variables:
    ```C
        int array[10];
        int array[10] = {0};     // All hold value = 0
        int array[10] = {1,2,3}  // The non ini-vars array[4] to [10] will hold value = 0

        int array[3] = {[3] = 100, [1] = 101, [2] = 102}  // array[3] = {100, 101, 102}
        int array[] = {1 ,2 ,3}                           // Array of len = 3
        int array[] = {[3] = 8, [0] = 9}                  // Array of len = 4
    ```
- Iterate
    ```C
        #define ARRLEN 10000
        int arr[ARRLEN][ARRLEN];

        size_t i, j;
        for (i = 0; i < ARRLEN; ++i)
        {
            for (j = 0; j < ARRLEN; ++j)
            {
                arr[i][j] = 0; // The inefficient way is to do arr[j][i]
            }
        }
    ```
- Array Length
    - In most cases array's are converted to / decay to a POINTER to its first element.
    - `sizeof()` is one of the small exceptions to the above line.
    - When we pass an array to a function, a pointer to the array's 1st element is passed to the function.
    ```C
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // Length = (Total Size of Array / Size of 1st Element)
        size_t arr_len = sizeof(arr) / sizeof(arr[0])
    ```
    - Use a MACRO to calculate array length
    ```C
        #define arr_len(arr) ( sizeof(arr)/sizeof(arr[0]) ) // This will not work inside a function ;P
    ```
- Array CANT be an actual arg to a func they DECAY TO POINTER.
- Array Length cant be calculated inside a func.

</br>
</br>

## Multi-Dimensional Arrays

- A 2D-Array is a LIST of 1D-Array
- C is a ROW major language int arr[4][3] != arr[3][4]

> Generalization: datatype arr_name[size1][size2]..[sizeN];

Ex:
- Both are equivalent, the nested braces are recommended.
    ```C
    int arr[3][4] = {
                    {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10 , 11, 12}
                };

    int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    ```
- A multi-dim array can be visualized as a checkerboard
    ```
        0  1  2  3 [Cols]
        ----------
        0| 1  2  3  4
        1| 5  6  7  8
        2| 9 10 11 12
    [Rows]
    ```

- But, it is stored in physical memory like this
    ```
        0*4+0 0*4+1 0*4+2 0*4+3 1*4+0 1*4+1 1*4+2 1*4+3 2*4+1   etc.
        |-----|-----|-----|-----|-----|-----|-----|-----|-----|
            1     2     3     4     5     6     7     8     9    etc.
    ```

</br>
</br>

### Passing Multi-Dimentional Arrays to a Function
- In C we need to explicitly define 2nd, 3rd, 4th ... dimension of an Array
Ex:
```C
    int arr_3d[][2][7];     // 3D Array
```
- `int *ptr_to_arr;`
    - It means that we are passing a pointer `*ptr_to_arr` to the block of memory that stores arr variable.
- `ptr_to_arr[i * cols + j];`
    - We can no longer use ptr_to_arr[i][j] to access array ele.
    - We need to use the above syntax for 2D array.

        ```C
            #include<stdio.h>

            void print_2d_arr(size_t rows, size_t cols, int *ptr_to_arr)
            {
                size_t i, j;
                for(i = 0; i < rows; i++)
                {
                    for(j = 0; j < cols; j++)
                    {
                        printf("% 2d", ptr_to_arr[i * cols + j]);
                    }
                    printf("\n");
                }
            }

            int main(void)
            {
                int arr[][3] = {
                    {1,2,3},
                    {4,5,6}
                };
            /*---------------------Function to Print Array-------------------------*/
                print_2d_arr(2, 3, arr[0]);

            /*---------------------Print Array in Main-------------------------*/
                size_t i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        printf("% 2d", arr[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        ```

</br>
</br>


## Clear Array Value
```C
    #include<string.h>

    #define ARRLEN (10)
    int main (void)
    {
        int arr[ARRLEN];

    /*---------------------Shortcut_1-------------------------*/
        memset(arr, 0, sizeof arr);

    /*---------------------Basic-------------------------*/
        size_t i;
        for (i = 0; i < ARRLEN; i++)
        {
            arr[i] = 0;
        }
    }
```

</br>
</br>


## Set Array Value
```C
    int arr[10];
    /*-----Set value of 5th element = 5------*/
        arr[4] = 5;
        4[arr] = 5;
        *(arr + 4) = 5;
        *(4 + arr) = 5;
```

</br>
</br>


## Allocate and 0-Init Arr with UserDef Size
```C
    #include<stdio.h>
    #include<stdlib.h>

    int main(void)
    {
        size_t num_ele, i;

        printf("\n Enter Number of elements in an Array: ");
        fflush(stdout);

        if (1 != scanf("%zu", &num_ele))
        {
            perror("\nERROR: scanf() was not able to record the data.\n");
            exit(EXIT_FAILURE);
        }

        int *ptr_to_arr;
        ptr_to_arr = calloc(num_ele, sizeof(*ptr_to_arr));

        if (NULL == ptr_to_arr)
        {
            perror("\nERROR: calloc() failed.\n");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < num_ele; i++)
        {
            printf("\n Element - %zu = ",i);
            if (1 != scanf(ptr_to_arr[i]))
            {
                perror("\nERROR: scanf() was not able to record the data.\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("\n\n");

        printf("\nNumber Stored in the Array: \n");
        for (i = 0; i < num_ele; i++)
        {
            printf("% 2d", *(ptr_to_arr + i));
        }
    }
```