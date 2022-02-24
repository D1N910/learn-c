#include <stdlib.h>
#include <stdio.h>

void printfArrat(int a[], int n);

int main(void) {
    printfArrat((int []) {1, 3, 4, 5, 6}, 5);

    return 0;
}

void printfArrat(int a[], int n)
{
    while (n-- > 0)
    {
        if (n == 2) {
            exit(1);
        }
        printf("%d \n", a[n]);
    }
}