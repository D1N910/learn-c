// 2.2 07. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果序列表
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

SqlList Merger2SqlList(SqlList L1, SqlList L2) {
    SqlList newList;
    newList.length = 0;
    newList.data = (int*)malloc(sizeof(int)*(L1.length+L2.length));
    int i = 0, j = 0;
    for (; i < L1.length && j < L2.length;) {
        if (L1.data[i] < L2.data[j]) {
            newList.data[newList.length++] = L1.data[i++];
        } else {
            newList.data[newList.length++] = L2.data[j++];
        }
    }
    if (i < L1.length) {
        while (i < L1.length)
        {
            newList.data[newList.length++] = L1.data[i++];
        }
    } else {
        while (j < L2.length)
        {
            newList.data[newList.length++] = L2.data[j++];
        }
    }
    return newList;
}
// SqlList Merger2SqlList(SqlList L1, SqlList L2) {
//     int i = L1.length; int j = L2.length; int remains = 0; SqlList remainsSql;
//     // 长度分别为0时，直接返回
//     if (i == 0)
//         return L2;
//     else if(j == 0)
//         return L1;
//     SqlList L3;
//     L3.length = 0;
//     L3.data = (int*)malloc(sizeof(int)*(L1.length+L2.length));
//     for(;i> 0 && j > 0;) {
//         if (L1.data[L1.length - i] < L2.data[L2.length - j]) {
//             L3.data[L3.length] = L1.data[L1.length - i];
//             i--;
//         } else {
//             L3.data[L3.length] = L2.data[L2.length - j];
//             j--;
//         }
//         L3.length++;
//     }
//     remains = i != 0 ? i : j;
//     remainsSql = i != 0 ? L1 : L2;
//     for (; remains > 0;remains--) {
//         L3.data[L3.length] = remainsSql.data[remainsSql.length - remains];
//         L3.length++;
//     }
//     return L3;
// }


int main() {
    SqlList L1;
    SqlList L2;
    L1.data = (int*)malloc((sizeof(int))*MaxSize);
    L1.length = 3;
    L2.data = (int*)malloc((sizeof(int))*MaxSize);
    L2.length = 4;
    int data1[3] = {1, 3, 6,};
    int data2[4] = {2,4,5,7};
    L1.data = data1;
    L2.data = data2;
    SqlList L3 = Merger2SqlList(L1, L2);
    for (int j = 1;j <= L3.length; j++) {
        printf("%d ", L3.data[j-1]);
    }
    return 0;
}