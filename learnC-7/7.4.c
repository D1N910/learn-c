#include <stdio.h>

int main(void)
{
    int leftNum = -10;
    unsigned int rightNum = 10;
    if (leftNum < rightNum) {
        printf("leftNum(%d) < rightNum(%d)", leftNum, rightNum);
    } else {
        printf("leftNum(%d) > rightNum(%d)", leftNum, rightNum);
    }


    return 0;
}