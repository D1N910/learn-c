#include <stdio.h>

int main(void)
{
    char ch;
    do {
        scanf("%c", &ch);
        printf("have read -> %c <- \n", ch);
    } while (ch != '\n');
    return 0;
}