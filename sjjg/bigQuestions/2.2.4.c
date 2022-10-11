// 从有序表中删除其值并在给定值s与t之间（要求s<t的所有元素），若s或t不合理，或程序表为空，则显示出错信息并退出运行
// 09月20日 错题 - 因为没注意到是说的有序表，而且说的是“给定值”，就是s、t是值，而不是下标！
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
    int i; int j; 
    if (s >= t || L->length <= 0) {
        printf("Data is not valid!");
        return false;
    }
    for (i = 0; i < L->length&&L->data[i]<s;i++); // 寻找值大于等于 s 的第一个元素
    if (i >= L->length)
        return false;
    for (j = L->length - 1; j > i && L->data[j] < t;j--); // 寻找值小于等于 t 的第一个元素
    if (j <= i)
        return false;
    for (;j < L->length;i++, j++)
        L->data[i] = L->data[j];
    L->length = i;
    return true;
}


int main() {
    SqlList L;
    L.data = (int*)malloc((sizeof(int))*MaxSize);
    L.length = 5;
    int data[5] = {1, 2, 3, 4, 5};
    L.data = data;
    DeleteS2T(&L, 3, 4);
    for (int j = 1;j <= L.length; j++) {
        printf("%d,", L.data[j-1]);
    }
    return 0;
}