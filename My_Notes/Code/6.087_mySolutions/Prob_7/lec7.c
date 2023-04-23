#include <stdio.h>

struct foo{
   union{
      int i;
      char c;
   }u;
   short s;
   unsigned int flag_s: 1;
   unsigned int flag_u: 2;
   unsigned int bar;
};


int main() {
   printf("The size of short is %zu bytes.\n", sizeof(struct foo));
   return 0;
}
