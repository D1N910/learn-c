#include <stdio.h>
#include <stdbool.h>
#define true1 2
#define flag3 (flag2 = 3)

int main(void) {
    _Bool flag, flag1;
    int flag2;
    flag = true;
    flag1 = false;
    flag2 = true1;
    flag3;

    printf("flag: %d\n", flag);
    printf("flag1: %d\n", flag1);
    printf("flag2: %d\n", flag2);
}