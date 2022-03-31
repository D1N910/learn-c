/**
 * @file stack08.c 带头节点的栈
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node // 箱子里的书
{
    int data;
    struct Node * pNext;
} NODE, * PNODE;

typedef struct Stack // 栈  - 箱子
{
    PNODE pTop; // 指向栈的顶部
    PNODE pBottom; // 指向栈的底部
} STACK, * PSTACK;

void init(PSTACK); // 初始化栈

void push(PSTACK, int); // 压栈，往栈中添加元素

void traverse(PSTACK); // 遍历输出栈的元素

_Bool empty(PSTACK); // 判断栈是否为空

_Bool pop(PSTACK, int *); // 出栈

void clear(PSTACK); // 清空栈内容

int main(void)
{
    STACK S; // STACK 等价于 struct Stack
    int val;

    init (&S);
    push(&S, 12);
    push(&S, 19);
    traverse(&S);
    if (pop(&S, &val)) {
        printf("出栈成功，出栈的元素是%d\n", val);
    } else {
        printf("出栈失败 \n");
    }
    clear(&S);
    traverse(&S);
    if (pop(&S, &val)) {
        printf("出栈成功，出栈的元素是%d\n", val);
    } else {
        printf("出栈失败 \n");
    }
    return 0;
}

void init (PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if (NULL == pS->pTop) {
        printf("分配内存失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }

    return;
}

void push (PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop; // pS->pTop 不能改成 pS->pBottom
    pS->pTop = pNew;

    return;
}

void traverse (PSTACK pS) {
    PNODE p = pS->pTop;
    while(p != pS->pBottom) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return;
}

_Bool empty (PSTACK pS) {
    if (pS->pTop == pS->pBottom) {
        return true;
    } else {
        return false;
    }
}

_Bool pop(PSTACK pS, int * pVal)
{
    if (empty(pS))
    {
        return false;
    }
    else
    {
        PNODE r = pS->pTop;
        pS->pTop = r->pNext;
        *pVal = r->data;
        free(r);
        r = NULL;
        return true;
    }
}

void clear(PSTACK pS)
{
    if (empty(pS)) {
        return;
    } else {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while (p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
        return;
    }
}