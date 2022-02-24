/* P24 PROGRAMMING PROBLEM 7 */

/* Write a program that asks the user enter the amount of dollar and then
 * diaplay how to use the most less number of 20 dollar,10 dollar,5 dollar and
 * 1 dollar to pay.
 * 
 * Write a program that asks the user to enter a dollar amount and then
 * shows how to pay with a minimum of $20, $10, $5 and $1.
 */

#include <stdio.h>

int main(void)
{
    int dollar_amount, minimum_20, minimum_10, minimum_5;
    printf("Please enter a dollar amount:");
    scanf("%d", &dollar_amount);
    minimum_20 = dollar_amount / 20;
    dollar_amount = dollar_amount - 20 * minimum_20;
    minimum_10 = dollar_amount / 10;
    dollar_amount = dollar_amount - 10 * minimum_10;
    minimum_5 = dollar_amount / 5;
    dollar_amount = dollar_amount - 5 * minimum_5;
    
    printf("$20 bills: %d\n", minimum_20);
    printf("$10 bills: %d\n", minimum_10);
    printf(" $5 bills: %d\n", minimum_5);
    printf(" $1 bills: %d\n", dollar_amount);
    return 0;
}