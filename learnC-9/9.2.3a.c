#include <stdio.h>

// int getFirstArray(int a[]);

// int main(void) {
//     int a[] = {1, 2, 3, 4};

//     printf("%d \n", getFirstArray(a));
//     printf("%d \n", a[1]);

//     return 0;
// }

// int getFirstArray(int a[])
// {
//     a[1] = 44;
//     return a[0];
// }

int getFirstArray(int a[][20]);

int main(void) {
    int a[10][20] = {1, 2, 3, 4};

    printf("%d \n", getFirstArray(a));
    printf("%d \n", a[1][18]);

    return 0;
}

int getFirstArray(int a[][20])
{
    a[1][18] = 44;
    return a[0][0];
}