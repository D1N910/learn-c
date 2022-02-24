/* Computes a Universal Product Code check digit */
#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, sum_of_first, sum_of_second, total;

    printf("Please enter first number: ");
    scanf("%1d", &n1);

    printf("Please enter the first digit group: ");
    scanf("%1d%1d%1d%1d%1d", &n2, &n3, &n4, &n5, &n6);

    printf("Please enter the second digit group: ");
    scanf("%1d%1d%1d%1d%1d", &n7, &n8, &n9, &n10, &n11);

    sum_of_first = n1 + n3 + n5 + n7 + n9 + n11;
    sum_of_second = n2 + n4 + n6 + n8 + n10;

    total = 9 - (((sum_of_first * 3 + sum_of_second) - 1) % 10);

    printf("All number %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
    printf("Check digit: %d\n", total);

    return 0;
}