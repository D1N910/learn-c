/* Write and uses printf function to display float's  x 
 * Write a printf function call that displays the float type
 * variable x in the following format.
 */
#include <stdio.h>

int main(void)
{
    float x, y;
    printf("e:");
    scanf("%f -%f", &x, &y);

    printf("%f,%f/n", x, y);

    return 0;
}