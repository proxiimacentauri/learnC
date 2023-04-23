/////////////////////////////////////////////////////
//
//
//
//
//
//
//
/////////////////////////////////////////////////////

-------------------------------------------------------------
(a) In implementing this program, you want to access the global variable 'the_dictionary' from
main.c, as well as from dict.c.
However, due to the header files inclusion in both source documents, the variable gets declared in both places, creating an ambiguity.

How would you resolve this ambiguity?

            dict.c

#include "dict.h"

#ifndef __DATA_STRUCT__
#define __DATA_STRUCT__
/*  data struct for the dictionary  */
char *the_dict[1000];
#endif


Correction: dict.h

    extern char *the_dict[1000];

    It will caluse both files to ref the variable declared in dict.c

-------------------------------------------------------------
(b) Now, suppose you want to restrict the dictionary data structure to be accessible only from
functions in dict.c.
You remove the declaration from dict.h. Is it still possible to directly access or modify the variable from main.c, even without the declaration in dict.h?
If so, how would you ensure the data structure variable remains private?

>> After we delete the data struct from dict.h

    extern char *the_dict[1000];




-------------------------------------------------------------
(c) Congratulations! You’re done and ready to compile your code. Write the command line
that you should use to compile this code (using gcc).
Lets call the desired output program
dictionary.o

>> gcc -O0 -Wall main.c dict.c -o dictionary.o