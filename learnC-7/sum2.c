/* Sums a series of number (using long int variables)*/
#include <stdio.h>

int main(void)
{
    long int nums, sum;
    printf("This program sums a seriers of integers.\n");
    printf("Enter integers(0 to terminate): ");

    scanf("%ld", &nums);

    while (nums != 0)
    {
        sum += nums;
        scanf("%ld", &nums);
    }

    printf("The sum is: %ld\n", sum);
    
    return 0;
}
