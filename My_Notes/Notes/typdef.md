# Typedef

- It is a keyword in C to assign alternative names (alias) to exisisting datatypes

> Generalization: typedef <existing_name> <alias_name>

Ex:
```C
    #include<stdio.h>

    typedef unsigned long ulong;

    int main (void)
    {
        ulong var1=0;

        var1 = 8888888888888888888;

        printf("\n Value of var1 = %lu\n", var1);

        return 0;
    }
```