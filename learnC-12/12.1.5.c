#include <stdio.h>

int main(void)
{
    int *p = (int []) {1, 2, 3, 4, 5};
    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    return 0;
}