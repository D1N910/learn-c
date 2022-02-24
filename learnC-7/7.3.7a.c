#include <stdio.h>

int main(void)
{
    char ch;
    while ((ch = getchar()) == ' ');
    printf("I have get:");
    putchar(ch);
    printf("\n");
    return 0;
}