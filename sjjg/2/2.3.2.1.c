/**
 * @file 2.3.2.c
 * @author D1n910 (260002330@qq.comss)
 * @brief 单链表上基本操作的实现 1、采用头插法建立单链表 p29
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#define ElemType int
#define my_printf(params) (printf(#params " %d \n\n", (params)));
typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList L, ElemType e);

int main(void)
{
    LinkList L;
    LNode head_node;
    head_node.data = 0;
    L = &head_node;

    L = List_HeadInsert(L, 3);

    my_printf(L->data);
    my_printf(L->next->data);
    return 0;
}

LinkList List_HeadInsert(LinkList L, ElemType e)
{
    LNode new_point;
    new_point.data = e;
    my_printf(e);
    // 头结点的data存储目前的长度，如果长度不为0，则头结点的下一个为新结点的下一个
    if (L->data != 0) {
        new_point.next = L->next; // 获取L头结点对应的next
    }
    my_printf(new_point.data);
    L->next = &new_point; // 现在头结点的next指向新创建的点
    my_printf(L->next->data);
    L->data++;
    return L;
}