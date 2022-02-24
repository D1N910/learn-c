/* Computes a Universal Product Code check digit */
#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, sum_of_first, sum_of_second, total;

    printf("Please enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);

    sum_of_first = n2 + n4 + n6 + n8 + n10 + n12;
    sum_of_second = n1 + n3 + n5 + n7 + n9 + n11;

    total = 9 - (((sum_of_first * 3 + sum_of_second) - 1) % 10);

    printf("All number %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12);
    printf("Check digit: %d\n", total);

    return 0;
}