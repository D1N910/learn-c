// 设计一个高效算法， 将顺序表L的所有元素逆置，要求算法的空间复杂度为 O(1)
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

void ReservedList(SqlList * L) {
    int start = 0;int end = L->length - 1;
    while(end > start) {
        int x = L-> data[end];
        L->data[end] =  L->data[start];
        L->data[start] = x;
        start++;
        end--;
    }
    return;
}

_Bool InsertData(SqlList * L, int i, int e) {
    printf("i %d \n", i);
    if (i < 1 || i > L->length + 1)
        return false;
    printf("i %d \n", i);
    if (L->length >= MaxSize)
        return false;
    for (int j = L->length;j>=i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}



int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 0;
    for (int j = 1;j <= MaxSize; j++)
        InsertData(&L, 1, j);

    for (int j = 1;j <= MaxSize; j++)
        printf("%d,", L.data[j-1]);

    printf("\n");
    ReservedList(&L);

    for (int j = 1;j <= MaxSize; j++) {
        printf("%d,", L.data[j-1]);
    }
    return 0;
}