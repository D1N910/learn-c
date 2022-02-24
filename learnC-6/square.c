#include <stdio.h>

int main(void)
{
    int enter_number, i = 1;
    printf("This program prints a table of squares.");
    printf("Enter number of entries in table:");
    scanf("%d", &enter_number);
    while (i <= enter_number)
    {
        printf("\t%d\t%d\n", i, i*i);
        i++;
    }
    return 0;
}