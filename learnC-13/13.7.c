#include <stdio.h>

int main(void)
{
    int a[][8] = {{1, 2, 3, 4, 5}, 9};
    printf("%d \n", a[1][0]);

    char b[][8] = {"qwer", "asds"};
    char *b1[] = {"qwer", "asds"};
    b[1][2] = 'd';
    printf("%c \n", b[1][2]);
    printf("%c \n", b1[1][0]);

    return 0;
}