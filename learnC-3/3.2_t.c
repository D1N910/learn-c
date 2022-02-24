#include <stdio.h>

int main(void)
{
    int i, j;
    float x, y;

    scanf("%d%d%f%f", &i, &j, &x, &y);
    printf("i: %d, j: %d, x: %.2f, y: %.2f", i, j, x, y);

    scanf("%d/%d", &i, &j);
    printf("i: %d, j: %d,", i, j);
    scanf("%d /%d", &i, &j);
    printf("i: %d, j: %d,", i, j);

    return 0;
}