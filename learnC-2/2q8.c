/* P24 PROGRAMMING PROBLEM 8 */

/* The program calculate the lease daikuan amount after first, second and third month.
 * 
 * Programming to calculate the remaining loan amoute after the first, second and third month
 * of loan repayment.
 */

#include <stdio.h>

int main(void)
{
    float amount_of_loan, interest_rate, monthly_payment;
    float balance_remaining_after_first_payment, balance_remaining_after_second_payment, balance_remaining_after_third_payment;
    float monthly_interest_rate;
    printf("Enter amount of loan: ");
    scanf("%f", &amount_of_loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    monthly_interest_rate = interest_rate / 100 / 12;

    amount_of_loan = amount_of_loan * (1 + monthly_interest_rate);

    balance_remaining_after_first_payment = amount_of_loan - monthly_payment;
    amount_of_loan = balance_remaining_after_first_payment * (1 + monthly_interest_rate);
    balance_remaining_after_second_payment = amount_of_loan - monthly_payment;
    amount_of_loan = balance_remaining_after_second_payment * (1 + monthly_interest_rate);
    balance_remaining_after_third_payment = amount_of_loan - monthly_payment;


    printf("Balance remaining after first payment: %.2f\n", balance_remaining_after_first_payment);
    printf("Balance remaining after second payment: %.2f\n", balance_remaining_after_second_payment);
    printf("Balance remaining after third payment: %.2f\n", balance_remaining_after_third_payment);

    return 0;
}