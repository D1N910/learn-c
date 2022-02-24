#include <stdio.h>

int main(void)
{
    int a[10] = { 1 }, *p;
    p = &a[0];
    *p = 10;
    printf("%d\n", a[0]);
    printf("%d", *p);
    return 0;
}