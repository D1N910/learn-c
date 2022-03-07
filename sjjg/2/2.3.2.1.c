/**
 * @file 2.3.2.1
 * @author D1n910 (260002330@qq.comss)
 * @brief 单链表上基本操作的实现 1、采用头插法建立单链表 p29
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define ElemType int
#define my_printf(params) (printf(#params " %d \n", (params)));
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/**
 * @brief 头插法
 * 
 * @param L 
 * @return LinkList 
 */
LinkList List_HeadInsert(LinkList L);

int main(void)
{
    LinkList L;
    L = List_HeadInsert(L); // 头插法获取数据
    L = List_HeadInsert(L); // 头插法获取数据
    printf("You have the last number is %d.\n", L->next->data);
    return 0;
}

LinkList List_HeadInsert(LinkList L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    L->next = NULL;

    printf("Please enter the number('9999' is mean end):\n");
    scanf("%d", &x);

    while (x != 9999) // 9999 表示结束
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        my_printf(s->data);
        s->next = L->next;
        L->next = s;
        my_printf(L->next->data);
        if (L->next->next != NULL) {
            my_printf(L->next->next->data); // 输出下一个
        }
        printf("Please enter the number('9999' is mean end):\n");
        scanf("%d", &x);
    }
    return L;
}