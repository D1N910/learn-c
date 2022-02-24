#include <stdio.h>

int main(void)
{
    printf("C89 %f\n", (double) sizeof(int));
    printf("C89 %f\n", (float) sizeof(int));
    printf("C99 only %zu \n", sizeof(int));
    return 0;
}