/**
 * @file 2.3.3
 * @author D1n910 (260002330@qq.comss)
 * @brief 双链表 1 双链表的删除操作
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
#define my_printf(params) (printf(#params " %d \n\n", (params)));
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

/**
 * @brief 在一个目标结点之后插入一个结点
 * 
 * @param p 目标结点
 * @param e 要插入的结点
 * @return _Bool 
 */
_Bool insertANodeAfterANode(DNode *p, DNode *e);

/**
 * @brief 在一个目标结点之前插入一个结点
 * 
 * @param p 目标结点
 * @param e 要插入的结点
 * @return _Bool 
 */
_Bool insertANodeBeforeANode(DNode *p, DNode *e);


/**
 * @brief 删除一个结点
 * 
 * @param p 要被删除的结点
 * @return _Bool 
 */
_Bool deleteANode(DNode *p);


/**
 * @brief 双
 * 
 * @param p 目标结点
 * @param e 要插入的结点
 * @return _Bool 
 */
_Bool insertANodeBeforeANode(DNode *p, DNode *e);

int main(void)
{
    DLinkList L;
    L = DList_tailInsert(L); // 尾插法插入数据


    my_printf(L->next->data);
    my_printf(L->next->next->data);
    my_printf(L->next->next->prior->data);

    DNode *insert_e = (DLinkList)malloc(sizeof(DNode));
    insert_e->data = 899;

    DNode *insert_e2 = (DLinkList)malloc(sizeof(DNode));
    insert_e2->data = 455;
    
    if (insertANodeAfterANode(L->next, insert_e)) {
        my_printf(insert_e->data);
        my_printf(L->next->next->data);
        my_printf(insert_e->prior->data);
        my_printf(insert_e->next->data);
    }

    if (insertANodeBeforeANode(L->next, insert_e2)) {
        my_printf(insert_e2->data);
        my_printf(L->next->data);
        my_printf(insert_e2->next->data);
        my_printf(insert_e->prior->data);
        my_printf(insert_e->prior->prior->data);
    }

    deleteANode(insert_e2);

    my_printf(L->next->data); // 查看是否删除成功

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

_Bool insertANodeAfterANode(DNode *p, DNode *e)
{
    if (!p || !e) {
        return false;
    } // 如果 p或者e 不存在则不执行

    e->next = p->next;
    p->next->prior = e;
    e->prior = p;
    p->next = e;
    return true;
}

_Bool insertANodeBeforeANode(DNode *p, DNode *e)
{
    if (!p || !e) {
        return false;
    } // 如果 p或者e 不存在则不执行

    e->prior = p->prior;
    p->prior->next = e;
    e->next = p;
    p->prior = e;
    return true;
}

/**
 * @brief 删除一个结点
 * 
 * @param p 要被删除的结点
 * @return _Bool 
 */
_Bool deleteANode(DNode *p)
{
    DNode *priorNode = p->prior;
    DNode *nextNode = p->next;
    priorNode->next = nextNode;
    nextNode->prior = priorNode;
    free(p);
    return true;
}
