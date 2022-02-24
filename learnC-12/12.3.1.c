#include <stdio.h>
#define A_SIZE 10

int find_largest(int a[], int n);

int main(void)
{
    int a[A_SIZE] = {0, 100, 2, 3}, *p;

    p = a;

    int a_max = find_largest(a, A_SIZE);

    printf("%d \n", a_max);
    printf("%d \n", p[3]);

    return 0;
}

int find_largest(int a[], int n)
{
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}