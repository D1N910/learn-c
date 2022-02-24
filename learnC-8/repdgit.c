#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {0};
    char ch;
    printf("Enter a number:");
    bool repeated_digit = false;
    while ((ch = getchar()) != '\n')
    {
        // 检查是不是有重复的
        if (digit_seen[(int)ch]) {
            repeated_digit = true;
            break;
        } else {
            digit_seen[(int)ch] = true;
        }
    }
    if (repeated_digit) {
        printf("Repeated digit\n");
    } else {
        printf("No Repeated digit\n");
    }
}