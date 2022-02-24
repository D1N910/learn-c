/* P24 PROGRAMMING PROBLEM 4 */

/* Write a program that lets user enter a number of doller and than
 * display the amount after increasen 5% tax.
 * 
 * Write a program that asks the user to enter a dollar amount and
 * then display the corresponding amount after increasing the tax
 * rate by 5%.
 */

#include <stdio.h>
#define TAX_RATE 0.5f

int main(void)
{
    float amount_of_dollar;
    printf("Enter an amount: ");
    scanf("%f", &amount_of_dollar);
    printf("With tax added: $%.2f\n", amount_of_dollar + amount_of_dollar * TAX_RATE);
    return 0;
}