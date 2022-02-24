#include <stdio.h>

int main(void)
{
    int i, j;
    i = j = 2;
    int k = 1;
    j += k;
    i += j;
    printf("Hello, world, %d, %d, %d \n", i, j, k);

    return 0;
}