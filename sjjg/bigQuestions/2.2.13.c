// 2.2 13
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 11

typedef struct 
{
    int *data;
    int length;
    /* data */
} SqlList;


int searchMinPlusInt(SqlList L) {
   if (L.length == 0)
      return -1; // 返回-1说明 数据有误
   int minPlusInt = L.data[0]; // 存储L中最小的正整数
   int maxPlusInt = L.data[0]; // 存储L中最大的正整数
   for (int i = 1;i<L.length;i++) {
        if (L.data[i] > 0) {
            if (minPlusInt < 0)
                minPlusInt = L.data[i];
            if (L.data[i] < minPlusInt) {
                minPlusInt = L.data[i];
            } else if (L.data[i] > maxPlusInt) {
                maxPlusInt = L.data[i];
            }
        }
    }
    if (minPlusInt < 0) {
        return 1;
    } else if (minPlusInt > 1) {
        return minPlusInt - 1;
    } else {
        return maxPlusInt + 1;
    }
}


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 3;
    int data[10] = {-1,-2,-3};
    L.data = data;    
    printf("%d", searchMinPlusInt(L));
    return 0;
}