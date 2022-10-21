#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkNode
{
    int data; // 值
    struct LinkNode * next; // 指向下一元素
} LinkNode, *LinkList;

LinkList Creat_Header_List(LinkList L) { // 头结点创建链表
    LinkList S; // 新结点
    L = (LinkList)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int x=0;x<=9;x++) {
        S = (LinkList)malloc(sizeof(LinkNode));
        S->data = x;
        S->next = L->next;
        L->next = S;
    }

    return L;
}

// 2.3.06 设计一个算法，使其元素递增有序
LinkList Sort_List(LinkList L) {
    LinkList s, p, r; // s、p为工作指针，r为p的后继，以防断链；
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;
        for (s = L; s != NULL; s=s->next)
            if (s->next == NULL) {
                p->next = s->next;
                s->next = p;
                break;
            } else {
                // 比较p大小并添加上去
                if (p->data < s->next->data) {
                    p->next = s->next;
                    s->next = p;
                    break;
                }
            }
        p = r;
    }
    return L;
}

// 2.3.05 将带头结点的单链表就地逆置
LinkList Reverse_L(LinkList L) {
    LinkList p, r; // p为工作指针，r为p的后继，以防断链
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    
    return L;
}

// 2.3.04 删除最小值的结点 
_Bool Delete_Min(LinkList L) {
    LinkList pre; // 存储最小值的前驱结点
    LinkList min; // 存储最小值的结点
    int x; // 存储最小值
    if (L->next != NULL) {
        pre = L;
        min = L->next;
    }
    else
        return false;
    // 遍历找到最小值
    for (;L->next != NULL; L = L->next) {
        if (L->next->data < min->data) {
            pre = L;
            min = L->next;
        }
    }
    // 删除节点
    pre->next = min->next;
    free(min);
    return true; // 完成删除
}

int main() {
    LinkList L;
    L = Creat_Header_List(L);
    LinkList S; // 新结点
    for (S = L->next;S != NULL;S = S->next) {
        printf("%d ", S->data);
    }

    // Delete_Min(L);
    // printf("\n");


    // for (S = L->next;S != NULL;S = S->next) {
    //     printf("%d ", S->data);
    // }
    // printf("\n");

    // LinkList LReverse;
    // LReverse = Reverse_L(L);
    // int i = 0;
    // for (S = LReverse->next;S != NULL && i<10;S = S->next, i++) {
    //     printf("%d ", S->data);
    // }

    // 02.3.06
    LinkList LSort;
    L->next->data = 100;
    L->next->next->data = 103;
    L->next->next->next->data=102;
    LSort = Sort_List(L);
    int i = 0;
    for (S = LSort->next;S != NULL && i<10;S = S->next, i++) {
        printf("%d ", S->data);
    }
    return 0;
}