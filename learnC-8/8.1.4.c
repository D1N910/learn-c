#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int a[10] = {0};
    printf("a[10]'s length %d\n", (int) (sizeof a / sizeof a[10]));
}