/* Write and uses printf function to display float's  x 
 * Write a printf function call that displays the float type
 * variable x in the following format.
 */
#include <stdio.h>

int main(void)
{
    printf("%-8.1e\n", 10000);
    printf("%10.6e\n", 10023423400);
    printf("%-8.3f\n", 12345678.1234);
    printf("%6.0f\n", 12345678.1234);

    return 0;
}