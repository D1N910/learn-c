#include <stdlib.h>
#include <stdio.h>

int power(int x, int n);

int main(void) {
    printf("%d \n", power(3, 2));

    return 0;
}

int power(int x, int n)
{
    return n == 0 ? 1 : x * power(x, --n);
}