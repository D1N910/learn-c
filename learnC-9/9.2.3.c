#include <stdio.h>

int getFirstArray(int a[]);

int main(void) {
    int a[] = {1, 2, 3, 4};

    printf("%d \n", getFirstArray(a));

    return 0;
}

int getFirstArray(int a[])
{
    return a[0];
}