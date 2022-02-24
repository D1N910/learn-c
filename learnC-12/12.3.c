#include <stdio.h>
#define aSize 5

int main(void)
{
    int a[aSize] = {1, 2, 3, 4, 5}, *p, sum = 0;
    // printf("%d \n", *a);
    // *(a + 1) = 19;
    // printf("%d \n", a[1]);

    p = a;

    while (p < a + aSize)
    {
        sum += *p++;
        /* code */
    }

    printf("%d \n", sum);
    
    return 0;
}