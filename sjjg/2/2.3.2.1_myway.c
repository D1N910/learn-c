/**
 * @file 2.3.2.1——myway 我自己的方式
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

LinkList List_HeadInsert(LinkList L, ElemType e);

int main(void)
{
    LinkList L;
    int x;
    LNode head_node; // 创建头结点
    head_node.data = 0; // 用这个表示length
    head_node.next = NULL;
    L = &head_node;

    printf("Please enter the number('9999' is mean end):\n");
    scanf("%d", &x);

    while (x != 9999) // 9999 表示结束
    {
        L = List_HeadInsert(L, x);
        scanf("%d", &x);
    }
    printf("You have Enter %d numbers.\n", L->data);
    return 0;
}

LinkList List_HeadInsert(LinkList L, ElemType e)
{
    LinkList new_point = (LNode*)malloc(sizeof(struct LNode));
    new_point -> data = e;
    my_printf(e);
    // 头结点的data存储目前的长度，如果长度不为0，则头结点的下一个为新结点的下一个
    if (L->data != 0) {
        new_point->next = L->next; // 获取L头结点对应的next
    }
    L->next = new_point; // 现在头结点的next指向新创建的点、
    L->data++;
    return L;
}