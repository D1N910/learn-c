#include <stdio.h>

#define PRINT_IN(n) printf(#n " %d \n", n)

int main(void) {
    int j = 1, k = 2, m = 3, n = 4;
    PRINT_IN(j + k);
    PRINT_IN(m + n);
    PRINT_IN(j                    + k +-+-+m+n);
    return 0;
}