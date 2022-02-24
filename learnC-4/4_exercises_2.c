#include <stdio.h>

int main(void)
{
    int i = 10000000;
    int j = 10000000;
    printf("%d\n", (-i) / j);
    printf("%d\n", -(i / j));
    return 0;
}
