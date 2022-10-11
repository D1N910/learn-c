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

void DeleteX(SqlList * L, int x) {
    int i,j;
    for (i = 0, j=0;j<L->length;j++)
        if (L->data[j] != x) {
            L->data[i] = L->data[j];
            i++;
        }
    L->length = i;
}

// void DeleteX(SqlList * L, int x) {
//     int XIndex = -1;
//     int NextIndex = 0;
//     int XNumber = 0;
//     for (;NextIndex <= L->length - 1; NextIndex++) {
//         if (L->data[NextIndex] == x) {
//             if (XIndex == -1) {
//                 XIndex = NextIndex;
//             }
//             XNumber++;
//         } else if (XIndex != -1) {
//             L->data[XIndex] = L->data[NextIndex];
//             L->data[NextIndex] = x;
//             XIndex++;
//         }
//     }
//     L->length -= XNumber++;
// }

// _Bool InsertData(SqlList * L, int i, int e) {
//     printf("i %d \n", i);
//     if (i < 1 || i > L->length + 1)
//         return false;
//     printf("i %d \n", i);
//     if (L->length >= MaxSize)
//         return false;
//     for (int j = L->length;j>=i;j--)
//         L->data[j] = L->data[j-1];
//     L->data[i-1] = e;
//     L->length++;
//     return true;
// }



int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 5;
    int data[5] = {2, 1, 0, 1,0};
    L.data = data;
    DeleteX(&L, 0);
    for (int j = 1;j <= L.length; j++) {
        printf("%d,", L.data[j-1]);
    }
    return 0;
}