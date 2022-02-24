#include <stdio.h>

int main(void)
{
    int first_digit, second_digit, enter_number;
    printf("Enter a two-digit number: ");
    scanf("%d", &enter_number);
    first_digit = enter_number / 10;
    second_digit = enter_number % 10;
    printf("The reversal %d%d\n", second_digit, first_digit);
    return 0;
}
