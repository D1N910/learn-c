#include <stdio.h>

int main(void)
{
    int i;
    int *p, *q;
    p = &i;
    q = p;
    i = 100;
    printf("%d\n", *q);

    return 0;
}