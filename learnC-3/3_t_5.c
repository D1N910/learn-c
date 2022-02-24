/* Write a program that tips the user enter all number for 1 to 16 and
 * display them by 4 x 4 juzhng and then calculate the sum of every rows, every cloumns
 * and every oppoter angle line.
 * 
 * Write a program that asks the user to enter (in any order) all the
 * integers form 1 to 16, then displays them in the form of a 4x4 materix,
 * and then calculates the sum in each row, column, and on each diagonal.
 */
#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
    printf("Enter the numbers form 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &n1, &n2,&n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);
    printf("%d\t%d\t%d\t%d\t\n%d\t%d\t%d\t%d\t\n%d\t%d\t%d\t%d\t\n%d\t%d\t%d\t%d\n\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);
    printf("Row sums: %d %d %d %d\n", n1 + n2 + n3 + n4, n5 + n6 + n7 + n8, n9 + n10 + n11 + n12, n13 + n14 + n15 + n16);
    printf("Column sums: %d %d %d %d\n", n1 + n5 + n9 + n13, n2 + n6 + n10 + n14, n3 + n7 + n11 + n15, n4 + n8 + n12 + n16);
    printf("Diagnoal sums: %d %d\n", n1 + n6 + n11 + n16, n4 + n7 + n10 + n13);
    return 0;
}