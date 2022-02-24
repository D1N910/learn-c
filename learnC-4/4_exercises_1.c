#include <stdio.h>

int main(void)
{
    printf("%d %d\n", 5 / 3, 5 % 3);
    printf("%d\n", (2 + 10) % 3);
    printf("%d\n", (7 + 10) % 9 / 8);
    printf("%d\n", (1 + 5) % (2 + 2) / 3);
    return 0;
}
