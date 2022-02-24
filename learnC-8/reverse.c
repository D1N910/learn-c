#include <stdio.h>
#define NeedNumber 10

int main(void)
{
    int getNums[NeedNumber];
    int getNumsIndex = 0;
    printf("Enter %d nunbers:", NeedNumber);
    while (getNumsIndex <= NeedNumber - 1)
    {
        /* code */
        scanf("%d", &getNums[getNumsIndex++]);
    }
    printf("In reverse order:");
    while (getNumsIndex >= 1)
    {
        printf("%d ", getNums[--getNumsIndex]);
    }
    printf("\n");
    return 0;
}