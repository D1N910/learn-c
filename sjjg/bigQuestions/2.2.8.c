// 2.2 08. 已知在一维数组A[m+n]中依次存放两个线性表（a1, a2, a3, ..., am）和(b1,b2,b3,...,bn)。编写一个函数，将
// 数组中的两个顺序表的位置互换，即将（b1，b2，b3，...，bn）放在(a1,a2,a3,...,am)的前面
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


void exchangeSqlListMN(SqlList * L, int m, int n) {
    if (m + n != L->length || L->length <=0)
        return; // 防错处理
    int * cacheList = (int *)malloc(sizeof(int)*(m+n));
    for (int i=0; i<L->length ;i++) {
        cacheList[i] = L->data[i];
    }
    for (int i = 0; i<L->length; i++) {
        if (i < n) {
            L->data[i] = cacheList[m+i];
        } else {
            L->data[i] = cacheList[i-n];
        }
    }
}


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 11;
    int data[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    L.data = data;
    exchangeSqlListMN(&L, 2, 9);
    for (int j = 1;j <= L.length; j++) {
        printf("%d ", L.data[j-1]);
    }
    return 0;
}