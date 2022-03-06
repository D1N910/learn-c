/**
 * @file 2.2.3.c P18 1
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// 用指针不需要定义数组长度
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define initSize 100
#define ElementType int
#define my_printf(t) (printf(#t " %d \n", t))

typedef struct 
{
    /* data */
    ElementType *data; // 指示动态分配数组的指针
    int Maxsize, length; // 数组的最大容量和当前个数
} SeqList; // 动态分配数组顺序表的类型定义

/**
 * @brief 初始化操作
 * 
 * @param L 动态分配数组顺序表
 */
void ListInit(SeqList *L);

/**
 * @brief 添加
 * 
 * @param L 动态分配数组顺序表
 * @param e 插入的内容
 */
_Bool ListAdd(SeqList *L, ElementType e);

/**
 * @brief 插入操作
 * 
 * @param L 动态分配数组顺序表
 * @param insterIndex 在第一个元素前插入
 * @param e 插入的内容
 */
_Bool ListInsert(SeqList *L, int insterIndex, ElementType e);


/**
 * @brief 删除操作
 * 
 * @param L 操作顺序表
 * @param deleteIndex 要删除第几个元素
 * @param e 被删除的元素
 * @return _Bool 
 */
_Bool ListDelete(SeqList *L, int deleteIndex, ElementType *e);

/**
 * @brief 查找元素
 * 
 * @param L 顺序表
 * @param e 被查找的元素
 * @return _Bool 
 */
int LocateElem(SeqList *L, ElementType e);

int main(void)
{
    SeqList L;

    ListInit(&L);

    printf("%d \n", L.Maxsize);
    printf("%d \n", L.length);

    ListAdd(&L, 1);
    ListAdd(&L, 2);
    ListAdd(&L, 4);

    ListInsert(&L, 2, 3);


    my_printf(L.data[0]);
    my_printf(L.data[1]);
    my_printf(L.data[2]);
    my_printf(L.data[3]);
    my_printf(L.length);

    int delete1;
    ListDelete(&L, 1, &delete1);
    my_printf(L.data[0]);
    my_printf(delete1);
    my_printf(L.length);
    my_printf(LocateElem(&L, 3));

    return 0;
}

void ListInit(SeqList *L)
{
    L->data = (ElementType*)malloc(sizeof(ElementType)*initSize);
    L->Maxsize = initSize;
    L->length = 0;
}

_Bool ListAdd(SeqList *L, ElementType e)
{
    // 如果太大
    if (L->length >= L->Maxsize){
        printf("Error: List is full!");
        return false;
    }
    L->data[L->length] = e;
    L->length++;
    return true;
}


_Bool ListInsert(SeqList *L, int insterIndex, ElementType e)
{
    if (insterIndex < 1 || insterIndex > L->length + 1)
    {
        printf("Error: Please check the insterIndex!");
        return false;
    }

    if (L->length >= L->Maxsize)
    {
        printf("Error: List is full!");
        return false;
    }
    for (int j = L->length; j >= insterIndex; j--)
    {
        L->data[j] = L->data[j-1];
    }
    L->data[insterIndex - 1] = e;
    L->length++;
    return true;
}

_Bool ListDelete(SeqList *L, int deleteIndex, ElementType *e)
{
    if (deleteIndex < 1 || deleteIndex > L->length) {
        return false;
    }
    *e = L->data[deleteIndex - 1];
    for (int j = deleteIndex - 1;j < L->length;j++) {
        L->data[j] = L->data[j+1];
    };
    L->length--;
    return true;
}

int LocateElem(SeqList *L, ElementType e)
{
    int i = L->length;
    while (i > 0)
    {
        if (L->data[i-1] == e)
        {
            return i;
        }
        i--;
    }
    
    return i;
}