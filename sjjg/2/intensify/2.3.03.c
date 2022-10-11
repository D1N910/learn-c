#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;

void InsertData(LinkList L) {
    LinkList S;  // 创建一个空的元素
    LinkList p = L; // 指向下一节点

    for (int i = 0; i<= 999;i++) {
        S = (LinkList)malloc(sizeof(LNode));
        S->data = i;
        S->next = NULL;
        p->next = S;
        p = S;
    }
}

void PrintAllData(LinkList L) {
    LinkList p = L->next;
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
    
}

// 反向输出数据
void PrintResertData(LinkList L) {
    LNode * Lcopy = (LNode *)malloc(sizeof(LNode)); // 创建一个新的链表
    LNode * s; // 存储新元素
    Lcopy->next = NULL; // 链表下一个为空
    LNode * Lp = L->next; // 创建一个指向L的指针
    // 当Lp不为Null
    while (Lp != NULL)
    {
        s = (LNode *)malloc(sizeof(LNode)); // 创建一个新结点
        s->data = Lp->data;
        s->next = Lcopy->next; // s的下一个为Lcopy后继的
        Lcopy->next = s; // 头结点的next变成s
        Lp = Lp->next;
    }
    Lp = Lcopy->next;
    while (Lp != NULL)
    {
        printf("%d \n", Lp->data);
        Lp = Lp->next;
    }
}

int main() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    InsertData(L);
    PrintResertData(L);
    return 0;
}
