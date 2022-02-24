/* P24 PROGRAMMING PROBLEM 5 */

/* Write a program that asks the user enter the number of x and then
 * display the value of following mulitily item formule:
 * 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 * 
 * The program asks the user to enter the value of x and then
 * displays the value of following polynomial
 */

#include <stdio.h>

int main(void)
{
    int x, x_2, x_3, x_4, x_5;
    scanf("%d", &x);
    x_2 = x * x;
    x_3 = x_2 * x;
    x_4 = x_3 * x;
    x_5 = x_4 * x;
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %d", 3 * x_5 + 2 * x_4 - 5 * x_3 - x_2 + 7 * x - 6);
    return 0;
}