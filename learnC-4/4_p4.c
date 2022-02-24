#include <stdio.h>

int main(void)
{
    int n1, n2 , n3, n4, n5, n6, enter_number;
    int enter_number_copy;
    printf("Enter a number: between 0 and 32767:");
    scanf("%d", &enter_number);
    enter_number_copy = enter_number;
    n1 = enter_number % 8;
    enter_number = (enter_number / 8);
    n2 = enter_number % 8;
    enter_number = (enter_number / 8);
    n3 = enter_number % 8;
    enter_number = (enter_number / 8);
    n4 = enter_number % 8;
    enter_number = (enter_number / 8);
    n5 = enter_number % 8;
    enter_number = (enter_number / 8);
    n6 = enter_number % 8;

    printf("In octal, your number is: %d%d%d%d%d%d\n", n6, n5, n4, n3, n2, n1);
    printf("In octal, your number is: %d\n", enter_number_copy);
    printf("In octal, your number is: %x\n", enter_number_copy);
    return 0;
}
