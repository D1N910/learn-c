// 从有顺序表中删除其值并在给定值s与t之间（要求s<t的所有元素），若s或t不合理，或程序表为空，则显示出错信息并退出运行
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

_Bool DeleteS2T(SqlList * L, int s, int t) {
    if (s >= t || L->length <= 0)
        return false;
    int i, j;
    for (i=-1, j = 0; j < L->length; j++) {
        if (L->data[j] < s || L->data[j] > t) {
            L->data[++i] = L->data[j];
        }
    }
    L->length = i+1;
    return true;
}

// _Bool DeleteS2T(SqlList * L, int s, int t) {
//     if (s >= t || L->length <= 0) {
//         printf("Data is not valid!");
//         return false;
//     }
//     int Xindex = -1;
//     int Length = 0;
//     for (int i = 0; i < L->length; i++) {
//         if (L->data[i] < s || L->data[i] > t) {
//             if (Xindex != -1) {
//                 L->data[Xindex] = L->data[i];
//                 Xindex++;
//             }
//             Length++;
//         } else {
//             if (Xindex == -1) {
//                 Xindex = i;
//             }
//         }
//     }
//     L->length = Length;
//     return true;
// }


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 5;
    int data[5] = {1, 3, 11, 11, 2};
    L.data = data;
    DeleteS2T(&L, 3, 10);
    for (int j = 1;j <= L.length; j++) {
        printf("%d,", L.data[j-1]);
    }
    return 0;
}