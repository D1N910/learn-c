#include <stdio.h>

int main(void)
{
    int enter_number, enter_number_digits;
    printf("Enter a number: ");
    scanf("%d", &enter_number);

    if (enter_number > 999) {
        enter_number_digits = 4;
    } else if (enter_number > 99) {
        enter_number_digits = 3;
    } else if (enter_number > 9) {
        enter_number_digits = 2;
    } else {
        enter_number_digits = 1;
    }

    printf("The number %d has %d digits \n", enter_number, enter_number_digits);

    return 0;
}