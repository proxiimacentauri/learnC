#include<stdio.h>

int main()
{
  int size = 8;
  for (int step = 0; step < size - 1; ++step)
  {
        for (int i = 0; i < size - step - 1; ++i)
        {
            printf("%d", i);
        }
        printf("\n\n");
    }
}