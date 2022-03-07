#include <stdio.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define my_gt

int main(void) {
    int j = 1, k = 2, m = 3, n = 4;
    printf("%d \n", MAX(j+k, m-n));
    return 0;
}