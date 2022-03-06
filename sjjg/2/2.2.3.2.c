/**
 * @file 2.2.3.c 单链表-尾插法
 * @author D1n910 (260002330@qq.comss)
 * @brief 单链表的实现
 * @version 0.1
 * @date 2022-03-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define my_printf(s) (printf(#s " %d \n", s))
#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *ListNode;

ListNode List_initTail(ListNode L);

int main(void)
{
    ListNode my_L;
    my_L = List_initTail(my_L);
    my_printf(my_L->next->data);
    return 0;
}

ListNode List_initTail(ListNode L)
{
    int e; // 获取的数字内容
    L = (ListNode)malloc(sizeof(LNode));
    LNode *s; // 新节点的内容
    LNode *r = L; // 表尾指针

    printf("Please enter number(enter 9999 mean terminate input):");
    scanf("%d", &e); // 输入第一个节点的值

    while (e != 9999)
    {
        s = (ListNode)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;
        r = s;
        printf("Please enter number(enter 9999 mean terminate input):");
        scanf("%d", &e);
    };
    r->next = NULL; // 尾指针为空
    return L;
}