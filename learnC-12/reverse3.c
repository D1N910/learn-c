#include <stdio.h>
#define A_SIZE 10

int main(void)
{
    int a[A_SIZE] = {0}, *p = a;
    printf("Please enter %d numbers:", A_SIZE);
    // 取值
    while (p < a + A_SIZE)
    {
        scanf("%d", p++);
        /* code */
    }
    p--;
    // 输出值
    while (p >= a)
    {
        printf(" %d", *p--);
    }
    printf("\n");
    
    return 0;
}