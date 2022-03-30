/**
 * @file 2.3.3
 * @author D1n910 (260002330@qq.comss)
 * @brief 双链表
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
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

/**
 * @brief 双链表-尾插法
 * 
 * @param L 
 * @return LinkList 
 */
DLinkList DList_tailInsert(DLinkList L);

int main(void)
{
    DLinkList L;
    L = DList_tailInsert(L); // 尾插法插入数据
    my_printf(L->next->data);
    my_printf(L->next->next->data);
    my_printf(L->next->next->prior->data);
    return 0;
}

DLinkList DList_tailInsert(DLinkList L)
{
    ElemType x; // 获得的数据
    L = (DLinkList)malloc(sizeof(DNode));
    L->prior = NULL;
    L->next = NULL;
    DNode *s; // 获取的结点
    DNode *r; // 尾结点
    r = L; // 尾结点指向L

    printf("Enter a number to tail insert the list:");
    scanf("%d", &x);

    while (x != 9999) // 当 x == 9999 则停止执行
    {
        /* code */
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        s->prior = r;
        r->next = s;
        r = s;
        printf("Enter a number to tail insert the list:");
        scanf("%d", &x);
    }
    r->next = NULL; // 尾结点清空

    printf("\n\nDOWN\n\n");
    
    return L;
}