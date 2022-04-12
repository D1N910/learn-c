#include <stdlib.h>
#include <stdbool.h>
#define ElementType char

typedef struct Node
{
    ElementType data;
    struct Node * next;
}Node; // 结点

typedef struct
{
    Node *top; // 栈顶
}Strack; // 栈

void InitStrack(Strack *S)
{
    S->top = NULL;
}

// 栈判空
_Bool ifStrackEmpty(Strack S)
{
    if (S.top == NULL)
        return true;
    return false;
}

// 获得栈顶元素
_Bool getTopStrack(Strack S, ElementType *x);

// 入栈
void EnStrack(Strack *S, ElementType x)
{
    Node *data = (Node*)malloc(sizeof(Node));
    data->next = S->top;
    data->data = x;
    S->top = data;
}

// 出栈
_Bool OutStrack(Strack *S, ElementType *x)
{
    if (ifStrackEmpty(*S)) // 栈空出栈失败
        return false;
    Node *p = S->top;
    *x = p->data; // 获得出栈的值
    S->top = p->next;
    free(p); // 释放空间
    return true;
}

// 取顶
_Bool getTopStrack(Strack S, ElementType *x)
{
    if (ifStrackEmpty(S)) // 栈空出栈失败
        return false;
    *x = S.top->data; // 获得出栈的值
    return true;
}