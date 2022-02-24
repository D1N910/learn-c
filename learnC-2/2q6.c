/* P24 PROGRAMMING PROBLEM 6 */

/* Write a program that asks the user enter the number of x and then
 * display the value of following mulitily item formule:
 * 
 * The program asks the user to enter the value of x and then
 * displays the value of following polynomial
 * ((((3x + 2)x - 5)x -1)x + 7)x - 6
 */

#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %d \n", ((((3 * x + 2) * x - 5) * x -1) * x + 7) * x - 6);
    return 0;
}