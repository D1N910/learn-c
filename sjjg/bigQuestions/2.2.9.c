// 2.2 09 我应该用折半查找法
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

void dd(int * i) {
    printf(i[0]);
}


void searchX(SqlList * L, int x) {
    if (L->length <=0) {
        L->data[0] = x;
        L->length = 1;
        return; // 防错处理
    }
    int i = 0;
    int i2 = L->length - 1;
    for (;i <= i2;i++, i2--) {
        if (L->data[i] == x) {
            // 如果相同，则和后继元素交换
            if (i+1 < L->length) {
                // i+1 合法时交换
                L->data[i] = L->data[i+1];
                L->data[i+1] = x;
            }
            return;
        } else if (L->data[i] > x) {
            // 递增数列，如果大于x，说明接下来的都比x要大了，那么就插入x
            for (int j = L->length; j > i;j--) {
                L->data[j] = L->data[j-1];
            }
            L->data[i] = x;
            L->length++;
            return;
        }
    
        if (L->data[i2] == x) {
            // 如果相同，则和后继元素交换
            if (i2+1 < L->length) {
                // i2+1 合法时交换
                L->data[i2] = L->data[i2+1];
                L->data[i2+1] = x;
            }
            return;
        } else if (L->data[i2] < x) {
            // 递增数列，如果小于x，说明接下来的都比x要小了，那么就插入x
            for (int j = L->length; j>i2;j--) {
                L->data[j] = L->data[j-1];
            }
            L->data[i2] = x;
            L->length++;
            return;
        }
    }
}


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 6;
    int data[10] = {1, 3, 5, 6, 7, 9};
    L.data = data;
    searchX(&L, 2);
    // printf("dfsdf");
    for (int j = 1;j <= L.length; j++) {
        printf("%d ", L.data[j-1]);
    }
    return 0;
}