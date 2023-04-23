/////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////

---------------------------[1.1]---------------------------
(a)
    Curly Braces
    - Start of a function or an array

(b)
    7   - int
    "7" - string ends with a null char \0
    '7' - char

(c)
    10+2/((3.0-2.0)*2)

---------------------------[1.2]---------------------------

    3*3       - 2
    (3*3)     - 2
    (3)*(3)   - 2
    ((3)*(3)) - 2

---------------------------[1.3]---------------------------

gcc -Wall t.c -o t.o
C/ $ gdb t.o
    Reading symbols from t.o...
    (No debugging symbols found in t.o)
    (gdb) run
    Starting program: /workspaces/73495213/C/t.o
    warning: Error disabling address space randomization: Operation not permitted
    [Thread debugging using libthread_db enabled]
    Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
    hello, 6.087 students
    [Inferior 1 (process 2418) exited normally]
    (gdb)


---------------------------[1.4]---------------------------
(a)
    has semicolon
    #include <stdio.h>

(b)
    void is NOT a data type

(c)
    int function(int arg1)
    {
        return arg1-1;
    }

(d)
    macro cant not do assignment

    #define MESSAGE "Happy new year!"