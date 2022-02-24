#include <stdio.h>

int main(void)
{
    int a[10], *p, *q, i;
    p = &a[2];
    q = p + 3;
    p += 8;
    a[5] = 5;
    a[8] = 8;
    printf("%d\n", *p);
    printf("%d", *q);
    return 0;
}