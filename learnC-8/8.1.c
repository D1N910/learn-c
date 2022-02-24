#include <stdio.h>
#define A 10

int main(void)
{
    int a[10];
    char b[A];
    b[10] = 'A';
    printf("%d \n", a[1]);
    printf("%c", b[1]);
}