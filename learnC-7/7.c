#include <stdio.h>

int main(void)
{
    // int i;
    // long int y;
    // long long int y1;
    // short int c;
    // unsigned int d = 102424;
    // printf("i: %d \n", i);
    // printf("y: %ld \n", y);
    // printf("y1: %lld \n", y1);
    // printf("short int c: %hd \n", c);
    // printf("d: %d \n", d);
    // printf("d: %o \n", d);
    // printf("d: %x \n", d);
    // printf("d: %u \n", d);
    // printf("%d \n", 16);
    // printf("%d \n", 0x10);
    // printf("%d \n", 020);
    // printf("%o \n", 16);
    // printf("%x \n", 16);

    // double d;
    // long double d1 = 4234.34234324324l;
    // scanf("%lf", &d);

    // printf("%lf \n", d);
    // printf("%f \n", d1);

    // char a = 'a';

    // printf("%c \n", a);

    char ch;
    int i;
    i = 'a'; /* i is now 97 */
    ch = 'c';
    printf("%c \n", ch);
    printf("%d \n", ch);
    if ('a' <= ch && ch <= 'z') {
        ch = ch - 'a' + 'A';
    }
    printf("%d \n", 'a');
    printf("%d \n", ch);
    printf("%c \n", ch);
}