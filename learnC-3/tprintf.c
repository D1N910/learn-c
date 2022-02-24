/* Prints int and float values in various formats */

#include <stdio.h>

int main(void)
{
    int i = 40;
    float x = 878678667867639.21f;
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
    
    printf("\"To c or not to c, it is question.\"\n");
    printf("Item\tUnit\tPucharse\tdd\tPrice\tDate\n");
    printf("\\");
    return 0;
}