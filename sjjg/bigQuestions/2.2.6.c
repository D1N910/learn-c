// 2.2 06. 从有序顺序表中删除其值重复的元素，使表中所有元素均不同
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

_Bool DeleteRepition(SqlList * L) {
    if (L->length <= 0) {
        return false;
    }
    int i, j; // i 存储第一个不相同的元素，j为工作指针
    for (i = 0,j = 1; j <L->length; j++) {
        if (L->data[i] != L->data[j]) // 查找下一个与上一个元素不同的元素
            L->data[++i] = L->data[j]; // 找到后，将元素前移
    L->length = i+1;
    return;
}

// 第一次
// _Bool DeleteRepition(SqlList * L) {
//     if (L->length <= 0) {
//         return false;
//     }
//     int i ,j; // i 存储第一个不相同的元素，j为工作指针
//     for (i = 0, j = 1; j < L->length; j++)
//         if (L->data[i] != L->data[j]) // 查找到下一个与上个元素不同的元素
//             L->data[++i] = L->data[j];
//     L->length = i+1;
//     return true;
// }


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 5;
    int data[5] = {2, 2, 2, 3, 4};
    L.data = data;
    DeleteRepition(&L);
    for (int j = 1;j <= L.length; j++) {
        printf("%d,", L.data[j-1]);
    }
    return 0;
}