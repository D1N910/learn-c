#include <stdio.h>

int main(void)
{
    int first_digit, second_digit, third_digit, enter_number;
    printf("Enter a three-digit number: ");
    scanf("%d", &enter_number);
    first_digit = enter_number / 100;
    second_digit = enter_number % 100 / 10;
    third_digit = enter_number % 10;
    printf("The reversal %d%d%d\n", third_digit, second_digit, first_digit);
    return 0;
}
