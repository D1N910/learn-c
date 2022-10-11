// p14页
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
#define InitSize 50
#define ElemType int
// typedef struct 
// {
//     ElemType data[MaxSize]; // 顺序表数据的元素
//     int length; // 顺序表当前的长度
// } SqlList; // 顺序表的定义

typedef struct 
{
    ElemType *data; // 指示动态分组的指针
    int length; // 顺序表当前的长度
} SqlList; // 顺序表的定义


void intList(SqlList *);
int GelElem(SqlList, int);
bool ListInsert(SqlList *, int, ElemType);
bool ListDelete(SqlList *, int);
int LocalElem(SqlList, int); // 按值查找位


int main() {
    SqlList L;
    L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    L.length = 0;
    ListInsert(&L, 1, 210);
    ListInsert(&L, 1, 211);
    ListInsert(&L, 1, 212);
    ListInsert(&L, 1, 214);
    ListInsert(&L, 1, 222);
    printf("Yes %d \n", GelElem(L, 2));
    ListDelete(&L, 2);
    printf("Yes %d \n", GelElem(L, 2));
    printf("LocalElem 222 %d \n", LocalElem(L, 222));
    printf("LocalElem 210 %d \n", LocalElem(L, 210));
    printf("L.length %d \n", L.length);
}

// 按位查找值
int GelElem(SqlList L, int i) {
    if (i < 1 || i > L.length) // 判断i的范围是否有效
        return -1;
    return L.data[i-1];
}

// 插入值
bool ListInsert(SqlList * L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) // 判断i的范围是否有效
        return false;
    if (L->length >= MaxSize) // 判断是否满了
        return false;
    for (int j = L->length;j>=i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

// 删除值
bool ListDelete(SqlList * L, int i) {
    if (i < 1 || i > L->length) // 判断i的范围是否有效
        return false;
    for (int j = i-1;j<=L->length-2;j++)
        L->data[j] = L->data[j+1];
    L->length--;
    return true;
}

// get local by position
int LocalElem(SqlList L, ElemType e) {
    for (int i = 0;i <= L.length; i++)
        if (L.data[i] == e)
            return i+1;
    return -1;
}