#include <stdio.h>
#define A 10

int main(void)
{
    int a[] = {[10] = 2};
    printf("%d \n", a[1]);
    printf("%d \n", a[9]);
    printf("%d \n", a[10]);
    printf("%d \n", sizeof(a));
    return 0;
}