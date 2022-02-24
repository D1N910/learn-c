#include <stdio.h>

int main(void)
{
    int j = 1000000000;
    long i;

    i = j * j;
    printf("****%ld****\n", i);

    i = (long) j * j;
    printf("****%ld****\n", i);

    return 0;
}