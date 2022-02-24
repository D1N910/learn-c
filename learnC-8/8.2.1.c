#include <stdio.h>
#define N 2

int main(void)
{
    double ident[N][N] = {1, 2, 4, 5};
    printf("%f\n", ident[0][1]);
    printf("%f\n", ident[1][1]);
    return 0;
}