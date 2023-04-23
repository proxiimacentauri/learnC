#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            if (i * j > 50) {
                goto exit_loop;
            }
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }

exit_loop:
    printf("Exited the nested loop at i=%d and j=%d\n", i, j);

    return 0;
}

#include <stdio.h>

int main() {
    int i, j;
    int exit_flag = 0;

    for (i = 1; i <= 10 && !exit_flag; i++) {
        for (j = 1; j <= 10 && !exit_flag; j++) {
            if (i * j > 50) {
                exit_flag = 1;
            }
            else {
                printf("%d * %d = %d\n", i, j, i*j);
            }
        }
    }

    printf("Exited the nested loop at i=%d and j=%d\n", i-1, j-1);

    return 0;
}
