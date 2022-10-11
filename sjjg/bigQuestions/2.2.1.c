// 2.2 01 从顺序表中删除最小值的元素（假设唯一）并由函数返回被删除的值，空出的位置由最后一个元素补充，若顺序表为空，则显示出错误信息并退出运行
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

void DeleteMin(SqlList * L) {
    if (L->length == 0)
        return;
    int x = 0;
    for (int j = 1; j < L->length; j++) {
        if (L->data[x] > L->data[j]) {
            x = j;
        }
    }
    L->data[x] = L->data[L->length-1];
    L->length--;
    return;
}


int main() {
    SqlList L1;
    L1.data = (int*)malloc((sizeof(int))*MaxSize);
    L1.length = 3;
    int data1[3] = {1, 3, 6};
    L1.data = data1;
    DeleteMin(&L1);
    for (int j = 1;j <= L1.length; j++) {
        printf("%d ", L1.data[j-1]);
    }
    return 0;
}