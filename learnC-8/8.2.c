#include <stdio.h>
#define N 10

int main(void)
{
    double ident[N][N];
    int row , col;

    for(row = 0; row < N; row++) 
        for (col = 0; col < N; col++)
            if (row == col)
                ident[row][col] = 1.0;
            else
                ident[row][col] = 0.0;
    printf("%f\n", ident[1][1]);
    printf("%f\n", ident[1][2]);
    return 0;
}