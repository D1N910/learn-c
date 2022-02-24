#include <stdlib.h>
#include <stdio.h>

int fact(int n);

int main(void) {
    printf("%d \n", fact(3));

    return 0;
}

int fact(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}