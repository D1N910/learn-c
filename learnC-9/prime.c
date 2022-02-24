#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i< n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int i;
    printf("Enter a number:");
    scanf("%d", &i);
    if (is_prime(i)) {
        printf("Prime\n");
    } else {
        printf("No Prime\n");
    }
    return 0;
}