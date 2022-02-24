#include <stdio.h>
#define hhh 444

int main(void)
{
    typedef float Dollars;
    Dollars cash_in, cash_out;
    cash_in = 1000.00f;
    cash_out = 9988.03f;
    printf("%f, %f, %d \n", cash_in, cash_out, hhh);
    return 0;
}