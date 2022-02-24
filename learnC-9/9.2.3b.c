#include <stdio.h>

int getFirstArray(int m, int n, int a[*][*]);

int main(void) {
    int m = 10, n = 20;
    int a[10][20] = {1};

    printf("%d \n", getFirstArray(m, n, a));
    printf("%d \n", a[1][18]);

    return 0;
}

int getFirstArray(int m, int n, int a[m][n])
{
    a[1][18] = 44;
    return a[0][0];
}