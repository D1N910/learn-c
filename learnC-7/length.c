#include <stdio.h>

int main(void)
{
    int stringNumber = 0; // 计算长度
    char ch; // 存储字符
    printf("Enter a message:");
    while (getchar() != '\n')
        stringNumber++;

    printf("\nYour message wat %d character(s) long\n", stringNumber);

    return 0;
}