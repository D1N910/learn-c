#include <stdio.h>

int main(void)
{
    // int i = 2, j = 3;
    // int k = i * j == 6;
    // printf("(a) %d \n", k);

    // int i = 5, j = 10, k = 1;
    // printf("(b) %d \n", k > i < j);

    // int i = 3, j = 2, k = 1;
    // printf("(c) %d \n", i < j == j < k);

    // int i = 3, j = 4, k = 5;
    // printf("(d) %d \n", i % j + i < k);

    int i = 5, j = 0, k = -5;
    printf("%d \n", i && j);
    printf("%d \n", i && j || k);

    return 0;
}