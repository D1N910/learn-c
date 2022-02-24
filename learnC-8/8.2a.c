#include <stdio.h>
#define N 10

int main(void)
{
    double ident[N][N] = {9};
    printf("%f\n", ident[0][0]);
    printf("%f\n", ident[1][2]);
    return 0;
}