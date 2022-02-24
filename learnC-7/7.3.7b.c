#include <stdio.h>

int main(void)
{
    int i;
    char ch;
    printf("Enter an integer: \n");
    scanf("%d", &i);
    printf("Enter an char: \n");
    ch = getchar();
    printf("integer: %d \n", i);
    printf("char: %c \n", ch);
    return 0;
}