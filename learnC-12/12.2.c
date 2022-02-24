#include <stdio.h>
#define aSize 5

int main(void)
{
    int a[aSize] = {1, 2, 3, 4, 5}, sum = 0, sum2 = 0, *p, *q;
    for (p = &a[0]; p < &a[aSize]; p++)
        sum += *p;
    printf("%d\n", sum);
    q = &a[0];
    while (q < &a[aSize])
    {
        sum2 += *q++;
    }
    printf("%d\n", sum2);
    return 0;
}