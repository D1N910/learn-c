#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("sizeof(int) %lu \n", (unsigned long) sizeof(int));
    printf("sizeof(short) %lu \n", (unsigned long) sizeof(short));
    printf("sizeof(long) %lu \n", (unsigned long) sizeof(long));
    printf("sizeof(float) %lu \n", (unsigned long) sizeof(float));
    printf("sizeof(double) %lu \n", (unsigned long) sizeof(double));
    printf("sizeof(long double) %lu \n", (unsigned long) sizeof(long double));
    
    return 0;
}